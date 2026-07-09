# Architecture and Design

Strict Fibonacci Heaps (Brodal, Lagogiannis, Tarjan 2012) resolve the long-standing theoretical gap in priority queues, providing $O(1)$ worst-case time bounds for `find_min`, `insert`, `meld`, and `decrease_key`, alongside $O(\log n)$ bounds for `delete` and `delete_min`.

Traditional Fibonacci Heaps only achieve these bounds in the *amortized* sense, meaning occasional operations take $O(\log n)$ or even $O(n)$ time to clean up deferred structural invariants. This library implements the rigid transformations necessary for true worst-case limits.

## Constant-Time Structural Reductions

The core theoretical breakthrough of a Strict Fibonacci Heap is replacing massive, deferred consolidation cycles with continuous, incremental, constant-time "reductions".

At the end of every public heap operation (`insert`, `decrease_key`, `meld`, `delete_min`), the algorithm statically applies a fixed maximum number of structural reductions (defined internally by constants such as `SFH_INSERT_REDUCTIONS 5` or `SFH_DECREASE_KEY_REDUCTIONS 10`). These reductions greedily consume structural violations by looking at the specific `fix_lists` managed by the heap.

There are three primary reduction types:
1. **Root Reductions:** Ensures the root list degree remains bounded, consolidating active nodes of equal rank.
2. **Loss Reductions:** Restores tree density. When fixed nodes lose children, their "loss" count increases. The reduction eagerly cuts nodes with a loss $\ge 2$, cascading state changes upwards incrementally.
3. **Free Reductions:** Pairs "free" nodes of the same rank together to maintain structure.

## The Zero-Malloc Requirement

Standard priority queue implementations (like binary heaps or pairing heaps) require contiguous dynamic arrays or node-by-node dynamic allocation (`malloc`/`free`). In embedded and deterministic environments, allocations are slow, prone to fragmentation, and carry failure risk.

This library completely eradicates `malloc` through two architectural choices:

1.  **Intrusive Nodes:** The `_node_t` structure contains all sibling (`left`, `right`), child (`left_child`), and parent pointers, as well as necessary strict state metadata (`loss`, `is_free`, `prev`, `next`). The *caller* allocates this struct (on the stack, inside their own arena, or globally). The heap merely links and unlinks them.
2.  **Bounded Rank Pooling:** The algorithm uses auxiliary "Rank" objects to track groups of nodes based on their degree/loss. In a purely dynamic implementation, these rank objects would be allocated as the heap grows. However, the maximum rank of a node in a Strict Fibonacci Heap is mathematically bounded by $O(\log n)$.
    - For $2^{64}$ elements, the maximum rank is theoretically small (~86).
    - Thus, we embed a fixed array `rank_pool[100]` directly inside the `_heap_t` struct.
    - When a new rank is required, we simply reference the $i$-th element from this inline static array, completely bypassing dynamic allocation.

## State and Structural Violation Pointers

Nodes in the Strict Fibonacci heap transition between several internal states:
- **Active vs. Passive:** Nodes begin as "Passive" when melded, preventing them from interfering with the highly structured active root tree. They become "Active" gradually via reductions.
- **Free vs. Fixed:** Active nodes transition to "Fixed" when they become the child of another node. They track `loss` (number of lost fixed children) to trigger structural cuts before the tree becomes too sparse.

The heap maintains seven explicit "fix lists" using a doubly linked cyclic list embedded directly in the node struct (`prev`, `next`). These pointers isolate violating structural components in $O(1)$ time, bucketed into specific groups:
- `fix_passive`
- `fix_free_multiple` and `fix_free_single`
- `fix_loss_zero`, `fix_loss_one_multiple`, `fix_loss_one_single`, `fix_loss_two`

By keeping a direct pointer to the head of each fix list inside the heap struct, the algorithm eliminates any need to search the tree for violations, guaranteeing $O(1)$ schedules for `heap_reduce_free`, `heap_reduce_loss`, and `heap_reduce_root`.

## The Negative Infinity Flag

To implement arbitrary node deletion (`_delete(heap, node)`), the algorithm requires the target node's key to be decreased to $-\infty$, followed by an extraction.

In languages with dynamic typing (like Python) or tagged unions, this is trivial. In C, reserving a magic constant (like `INT_MIN`) strips the user of a valid data point and prevents unsigned keys from having a logical $-\infty$.

This architecture solves this by introducing `unsigned char is_min_inf : 1;` into the node struct. The comparison primitive (`node_lt`) checks this bitfield first, cleanly hijacking the sort order dynamically and allowing complete representation of the underlying data type.

## CMake Type Templates

The lack of C++ Templates or C11 `_Generic` in C89 makes type-safe polymorphic data structures difficult. `void*` is the traditional C approach, but it drops compile-time guarantees and incurs pointer-dereference overhead on basic types.

This architecture solves this by leveraging CMake's `configure_file`. The source `.h.in` and `.c.in` are written using `@KEY_TYPE@`, `@VAL_TYPE@`, and `@PREFIX@` placeholders. During configuration, CMake iterates across `SFH_KEY_TYPES` and `SFH_VAL_TYPES`, generating entirely distinct C files (e.g., `sfh_int32_t_float_...`) and linking them statically. This produces optimal, type-safe binaries with zero runtime generic overhead.
