# Architecture and Design

Strict Fibonacci Heaps (Brodal, Lagogiannis, Tarjan 2012) resolve the long-standing theoretical gap in priority queues, providing $O(1)$ worst-case time bounds for `find_min`, `insert`, `meld`, and `decrease_key`, alongside $O(\log n)$ bounds for `delete` and `delete_min`.

Traditional Fibonacci Heaps only achieve these bounds in the *amortized* sense, meaning occasional operations take $O(\log n)$ or even $O(n)$ time to clean up deferred structural invariants.

## The Zero-Malloc Requirement

Standard priority queue implementations (like binary heaps or pairing heaps) require contiguous dynamic arrays or node-by-node dynamic allocation (`malloc`/`free`). In embedded and deterministic environments, allocations are slow, prone to fragmentation, and carry failure risk.

This library completely eradicates `malloc` through two design choices:

1.  **Intrusive Nodes:** The `_node_t` structure contains all sibling (`left`, `right`), child (`left_child`), and parent pointers, as well as state metadata (`loss`, `is_free`). The *caller* allocates this struct (on the stack, inside their own arena, or globally). The heap merely organizes them.
2.  **Bounded Rank Pooling:** The algorithm uses auxiliary "Rank" objects to track groups of nodes based on their degree/loss. In a purely dynamic implementation, these rank objects would be allocated dynamically as the heap grows. However, the maximum rank of a node in a Strict Fibonacci Heap is mathematically bounded by $O(\log n)$.
    - For $2^{64}$ elements, the maximum rank is roughly 86.
    - Thus, we embed a fixed array `rank_pool[100]` directly inside the `_heap_t` struct.
    - When a new rank is required, we select the $i$-th element from this static array, bypassing the allocator completely.

## State and Structural Pointers

Nodes transition between `free` and `fixed` states, and track `loss` (number of lost fixed children) to trigger structural reductions.

The heap maintains seven "fix lists" using a doubly linked cyclic list embedded in the node (`prev`, `next`). These pointers isolate violating structural components (e.g. `fix_loss_two` or `fix_free_multiple`), allowing the `decrease_key` and `delete_min` algorithms to perform $O(1)$ scheduled reductions.

## The Negative Infinity Flag

To implement arbitrary node deletion (`_delete(heap, node)`), the node's key must be decreased to $-\infty$, followed by an extraction.

In languages with dynamic typing (Python) or tagged unions, this is trivial. In C, reserving a magic constant (like `INT_MIN`) strips the user of a valid data point and prevents unsigned keys from having a logical $-\infty$.

This library introduces `unsigned char is_min_inf : 1;` into the node struct. The comparison primitive checks this flag first, cleanly hijacking the sort order dynamically and allowing complete representation of the underlying data type.

## CMake Type Templates

The lack of C++ Templates or C11 `_Generic` in C89 makes type-safe polymorphic data structures difficult. `void*` is the traditional C approach, but it drops compile-time guarantees and incurs pointer-dereference overhead on basic integer types.

This architecture solves this by leveraging CMake's `configure_file`. The source `.h.in` and `.c.in` are written using `@KEY_TYPE@`, `@VAL_TYPE@`, and `@PREFIX@` placeholders. During configuration, CMake iterates across `SFH_KEY_TYPES` and `SFH_VAL_TYPES`, generating entirely distinct C files (e.g., `sfh_int32_t_float_...`) and linking them statically. This produces perfectly optimal, type-safe binaries with zero generic overhead.
