# c-strict-fibonacci-heaps

[![License](https://img.shields.io/badge/license-Apache--2.0%20OR%20MIT-blue.svg)](https://opensource.org/licenses/Apache-2.0)
[![Doc Coverage](https://img.shields.io/badge/docs-0%25-red.svg)](#)
[![Test Coverage](https://img.shields.io/badge/coverage-98%25-brightgreen.svg)](#)
[![CI](https://github.com/SamuelMarks/cdd-go/actions/workflows/ci.yml/badge.svg)](https://github.com/SamuelMarks/cdd-go/actions/workflows/ci.yml)
![Test Coverage](https://img.shields.io/badge/Test%20Coverage-100.0%25-brightgreen.svg)
![Doc Coverage](https://img.shields.io/badge/Doc%20Coverage-100.0%25-brightgreen.svg)

A strictly C89 compliant, zero-allocation (0 malloc), template-generated Strict Fibonacci Heap library.

Based on the breakthrough algorithm described by Gerth Stølting Brodal, George Lagogiannis, and Robert E. Tarjan, this implementation achieves true **worst-case** $O(1)$ time for `find_min`, `insert`, `meld`, and `decrease_key`, and $O(\log n)$ **worst-case** time for `delete` and `delete_min`.

Reference: Gerth Stølting Brodal, George Lagogiannis, and Robert E. Tarjan. 2025. Strict Fibonacci Heaps. ACM Trans. Algorithms 21, 2, Article 15 (April 2025), 18 pages. https://doi.org/10.1145/3707692

## Theoretical Background

Standard Fibonacci Heaps (Fredman and Tarjan, 1987) are theoretically elegant but rely on **amortized** time bounds. They delay structural maintenance—such as tree consolidation—until a `delete_min` occurs. While this yields $O(1)$ *amortized* time for `insert` and `decrease_key`, individual operations can degrade to $O(n)$ worst-case time when large cascades of structural violations must be fixed simultaneously. This makes standard Fibonacci Heaps unsuitable for real-time systems where consistent latency is required.

**Strict Fibonacci Heaps** solve this by strictly bounding the number of structural violations. Instead of deferring maintenance, a Strict Fibonacci Heap performs a constant, bounded number of structural "reductions" (tree linking, cutting, and rank adjustments) during every `insert`, `decrease_key`, and `delete_min` operation. By spreading the cleanup cost continuously, the data structure mathematically guarantees its theoretical time bounds in the **worst-case**, providing entirely predictable performance without sacrificing asymptotic efficiency.

## Key Features

- **Zero Allocation (Malloc-Free):** Operates on an *intrusive* node design. The caller manages all memory for `node` structures. Internal heap bookkeeping (such as rank tracking) leverages mathematically bounded arrays (max depth 100) embedded directly inside the `heap` struct.
- **Type-Safe Permutation via CMake:** C lacks generic typing, and `void*` incurs runtime overhead and type-safety loss. This library uses CMake `configure_file` templates to generate concrete, highly optimized permutations for any combination of key and value types (e.g., `sfh_int32_t_uint64_t_...`).
- **Strict C89 & Doxygen:** 100% compliant with ISO C90 (C89). Compiles seamlessly on MSVC (2005+), GCC, Clang, and MinGW with aggressive flags (`-Wall -Wextra -pedantic` / `/RTC1`). Complete Doxygen coverage on all functions.
- **Robust Error Percolation:** Every non-void, non-math function strictly returns an error enumeration (`_error_t`). Outputs are always passed via pointer arguments.
- **Negative Infinity Avoidance:** Implements logical negative infinity via an out-of-band bitfield (`unsigned char is_min_inf : 1;`), enabling the use of unsigned integers or pointers as keys without sacrificing a valid value space.

## Integration

You can cleanly integrate this project as a CMake submodule. Thanks to the `BUILD_TESTING` guard, testing dependencies are completely isolated when included in a parent project.

```cmake
# Prune the build matrix to exactly what you need to save compile time
set(SFH_KEY_TYPES "int32_t;int64_t" CACHE STRING "" FORCE)
set(SFH_VAL_TYPES "void*;int32_t" CACHE STRING "" FORCE)

add_subdirectory(strict-fibonacci-heaps)
target_link_libraries(my_target PRIVATE strict_fibonacci_heaps)
```

## Supported Compilers

Tested extensively across Windows, Linux, and macOS using:
- Microsoft Visual C++ (MSVC 2005, 2022, 2026) via `MT`/`MD` threading models.
- GCC
- Clang

## Further Reading

- [USAGE.md](USAGE.md) - For API examples, proper memory management, and CMake integration.
- [ARCHITECTURE.md](ARCHITECTURE.md) - For deep-dives into the $O(1)$ mechanics, Active/Passive nodes, and zero-malloc strategy.

## FetchContent Example

To easily embed this library inside your project using CMake's `FetchContent`:

```cmake
include(FetchContent)

# Optional: Prune type matrix to avoid compiling unused types
set(SFH_KEY_TYPES "int32_t;int64_t" CACHE STRING "" FORCE)
set(SFH_VAL_TYPES "void*;int32_t" CACHE STRING "" FORCE)

FetchContent_Declare(
  c-strict-fibonacci-heaps
  GIT_REPOSITORY https://github.com/SamuelMarks/c-strict-fibonacci-heaps.git
  GIT_TAG        master
)

FetchContent_MakeAvailable(c-strict-fibonacci-heaps)

# Link against the imported target
target_link_libraries(my_target PRIVATE c-strict-fibonacci-heaps)
```

---

## License

Licensed under either of

- Apache License, Version 2.0 ([LICENSE-APACHE](LICENSE-APACHE) or <https://www.apache.org/licenses/LICENSE-2.0>)
- MIT license ([LICENSE-MIT](LICENSE-MIT) or <https://opensource.org/licenses/MIT>)

at your option.

### Contribution

Unless you explicitly state otherwise, any contribution intentionally submitted
for inclusion in the work by you, as defined in the Apache-2.0 license, shall be
dual licensed as above, without any additional terms or conditions.
