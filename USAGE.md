# Usage Guide

This document details how to configure the build matrix, interact with the generated C89 API, and correctly handle the intrusive zero-malloc constraints.

## CMake Type Generation

By default, the library generates permutations for all standard `stdint.h` types. You will almost certainly want to restrict this in your parent `CMakeLists.txt` to minimize compilation time.

```cmake
# Before calling add_subdirectory!
set(SFH_KEY_TYPES "int32_t;float" CACHE STRING "" FORCE)
set(SFH_VAL_TYPES "int32_t;char*" CACHE STRING "" FORCE)

add_subdirectory(strict-fibonacci-heaps)
```

This will generate prefixed headers and sources, outputting a composite header to `build/c-strict-fibonacci-heaps.h`. The prefixes are dynamically derived (e.g., `*` is replaced with `ptr`). For an `int32_t` key and `char*` value, the prefix is `sfh_int32_t_charptr_`.

## API Conventions

1.  **Prefix:** All structs, functions, and enums use the specific `{PREFIX}_` signature.
2.  **Output Parameters:** Any output value is returned through a passed pointer.
3.  **Error Percolation:** ALL functions return `{PREFIX}_error_t`. `0` (`_SUCCESS`) indicates success.

## Node Management and Lifetime

Nodes **must** outlive their residency in the heap. Because this is an *intrusive* data structure, the heap internally stores pointers directly to your variables.

If you allocate a node on the stack, it **must** be extracted or explicitly deleted from the heap before that stack frame returns. Otherwise, the heap will point to garbage memory, leading to undefined behavior.

## Basic Example

```c
#include <stdio.h>
#include <stdlib.h>
#include "c-strict-fibonacci-heaps.h"

/* Type aliases for readability */
typedef sfh_int32_t_int32_t_heap_t heap_t;
typedef sfh_int32_t_int32_t_node_t node_t;
typedef sfh_int32_t_int32_t_error_t error_t;

int main(void) {
    heap_t heap;
    node_t n1, n2, n3; /* Caller allocated on the stack! */
    node_t *min_node;
    error_t rc;
    int is_empty;

    /* 1. Initialization */
    rc = sfh_int32_t_int32_t_init(&heap);
    if (rc != sfh_int32_t_int32_t_SUCCESS) return 1;

    /* 2. Insertion */
    rc = sfh_int32_t_int32_t_insert(&heap, &n1, 10, 100);
    if (rc != sfh_int32_t_int32_t_SUCCESS) return 1;

    rc = sfh_int32_t_int32_t_insert(&heap, &n2, 5, 200);
    if (rc != sfh_int32_t_int32_t_SUCCESS) return 1;

    rc = sfh_int32_t_int32_t_insert(&heap, &n3, 15, 300);
    if (rc != sfh_int32_t_int32_t_SUCCESS) return 1;

    /* 3. Decrease Key (Change n1's key from 10 to 1) */
    rc = sfh_int32_t_int32_t_decrease_key(&heap, &n1, 1);
    if (rc != sfh_int32_t_int32_t_SUCCESS) return 1;

    /* 4. Explicit Node Deletion */
    /* Let's say we no longer want n3 in the priority queue */
    rc = sfh_int32_t_int32_t_delete(&heap, &n3);
    if (rc != sfh_int32_t_int32_t_SUCCESS) return 1;

    /* 5. Find and Extract Minimum */
    while (1) {
        rc = sfh_int32_t_int32_t_empty(&heap, &is_empty);
        if (rc != sfh_int32_t_int32_t_SUCCESS) return 1;
        if (is_empty) break;

        /* Observe the minimum element */
        rc = sfh_int32_t_int32_t_find_min(&heap, &min_node);
        if (rc != sfh_int32_t_int32_t_SUCCESS) return 1;

        printf("Extracted Key: %d, Value: %d\n", min_node->key, min_node->value);

        /* Remove it from the heap */
        rc = sfh_int32_t_int32_t_delete_min(&heap);
        if (rc != sfh_int32_t_int32_t_SUCCESS) return 1;
    }

    /* All stack-allocated nodes have now been removed from the heap.
       It is safe to let n1, n2, and n3 go out of scope. */
    return 0;
}
```

## Melding

To achieve $O(1)$ worst-case melding between two heaps, use the `_meld` function.

```c
heap_t h1, h2;
heap_t *resulting_heap;

/* Assuming h1 and h2 are valid initialized heaps populated with nodes */
error_t rc = sfh_int32_t_int32_t_meld(&h1, &h2, &resulting_heap);
if (rc != sfh_int32_t_int32_t_SUCCESS) {
    /* Handle error */
}
```

**CRITICAL NOTE ON MELDING:** Strict Fibonacci Heaps structurally destroy the smaller heap during a meld by setting its nodes to a "Passive" state and merging it. The output pointer `resulting_heap` will point to the larger of `&h1` or `&h2`. The smaller heap struct is marked inactive and retired.

**Do not reuse the smaller heap struct without calling `_init` on it again.**
