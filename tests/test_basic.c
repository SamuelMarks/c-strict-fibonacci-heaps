/* clang-format off */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "greatest.h"
#include "c-strict-fibonacci-heaps.h"
/* clang-format on */

TEST test_all_sfh_int8_t_int8_t(void) {
  sfh_int8_t_int8_t_heap_t heap;
  sfh_int8_t_int8_t_node_t node, node2;
  sfh_int8_t_int8_t_node_t *out_node;
  sfh_int8_t_int8_t_heap_t *out_heap;
  int is_empty;
  sfh_int8_t_int8_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int8_t_int8_t_init(NULL);
  rc = sfh_int8_t_int8_t_empty(NULL, &is_empty);
  rc = sfh_int8_t_int8_t_find_min(NULL, &out_node);
  rc = sfh_int8_t_int8_t_insert(NULL, &node, 1, 0);
  rc = sfh_int8_t_int8_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int8_t_int8_t_delete_min(NULL);
  rc = sfh_int8_t_int8_t_delete(NULL, &node);
  rc = sfh_int8_t_int8_t_delete(&heap, NULL);
  rc = sfh_int8_t_int8_t_decrease_key(NULL, &node, 1);
  rc = sfh_int8_t_int8_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int8_t_int8_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int8_t_int8_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int8_t_int8_t_meld(&heap, &heap, NULL);

  sfh_int8_t_int8_t_init(&heap);
  rc = sfh_int8_t_int8_t_empty(&heap, &is_empty);
  rc = sfh_int8_t_int8_t_find_min(&heap, &out_node);
  rc = sfh_int8_t_int8_t_delete_min(&heap);

  rc = sfh_int8_t_int8_t_insert(&heap, &node, 10, 0);
  rc = sfh_int8_t_int8_t_empty(&heap, &is_empty);
  rc = sfh_int8_t_int8_t_find_min(&heap, &out_node);

  rc = sfh_int8_t_int8_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int8_t_int8_t_delete(&heap, &node);
  rc = sfh_int8_t_int8_t_delete_min(&heap);

  {
    sfh_int8_t_int8_t_heap_t h1, h2, h3, *merged;
    sfh_int8_t_int8_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int8_t_int8_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int8_t_int8_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int8_t_int8_t_init(&h3);
    sfh_int8_t_int8_t_insert(&h1, &n1, 1, 0);
    sfh_int8_t_int8_t_insert(&h1, &n2, 2, 0);
    sfh_int8_t_int8_t_insert(&h1, &n3, 3, 0);
    sfh_int8_t_int8_t_insert(&h1, &n4, 4, 0);
    sfh_int8_t_int8_t_insert(&h2, &n5, 5, 0);

    sfh_int8_t_int8_t_meld(&h1, &h2, &merged);
    sfh_int8_t_int8_t_delete_min(merged);
    sfh_int8_t_int8_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int8_t_int8_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int8_t_int8_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int8_t_int8_t_insert(&heap, &fnodes[idx],
                                        (int8_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int8_t_int8_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int8_t_int8_t_decrease_key(&heap, &fnodes[idx], (int8_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int8_t_int8_t_node_t *min;
          sfh_int8_t_int8_t_find_min(&heap, &min);
          rc = sfh_int8_t_int8_t_delete_min(&heap);
          if (rc == sfh_int8_t_int8_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int8_t_int8_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int8_t_int8_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int8_t_int16_t(void) {
  sfh_int8_t_int16_t_heap_t heap;
  sfh_int8_t_int16_t_node_t node, node2;
  sfh_int8_t_int16_t_node_t *out_node;
  sfh_int8_t_int16_t_heap_t *out_heap;
  int is_empty;
  sfh_int8_t_int16_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int8_t_int16_t_init(NULL);
  rc = sfh_int8_t_int16_t_empty(NULL, &is_empty);
  rc = sfh_int8_t_int16_t_find_min(NULL, &out_node);
  rc = sfh_int8_t_int16_t_insert(NULL, &node, 1, 0);
  rc = sfh_int8_t_int16_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int8_t_int16_t_delete_min(NULL);
  rc = sfh_int8_t_int16_t_delete(NULL, &node);
  rc = sfh_int8_t_int16_t_delete(&heap, NULL);
  rc = sfh_int8_t_int16_t_decrease_key(NULL, &node, 1);
  rc = sfh_int8_t_int16_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int8_t_int16_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int8_t_int16_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int8_t_int16_t_meld(&heap, &heap, NULL);

  sfh_int8_t_int16_t_init(&heap);
  rc = sfh_int8_t_int16_t_empty(&heap, &is_empty);
  rc = sfh_int8_t_int16_t_find_min(&heap, &out_node);
  rc = sfh_int8_t_int16_t_delete_min(&heap);

  rc = sfh_int8_t_int16_t_insert(&heap, &node, 10, 0);
  rc = sfh_int8_t_int16_t_empty(&heap, &is_empty);
  rc = sfh_int8_t_int16_t_find_min(&heap, &out_node);

  rc = sfh_int8_t_int16_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int8_t_int16_t_delete(&heap, &node);
  rc = sfh_int8_t_int16_t_delete_min(&heap);

  {
    sfh_int8_t_int16_t_heap_t h1, h2, h3, *merged;
    sfh_int8_t_int16_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int8_t_int16_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int8_t_int16_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int8_t_int16_t_init(&h3);
    sfh_int8_t_int16_t_insert(&h1, &n1, 1, 0);
    sfh_int8_t_int16_t_insert(&h1, &n2, 2, 0);
    sfh_int8_t_int16_t_insert(&h1, &n3, 3, 0);
    sfh_int8_t_int16_t_insert(&h1, &n4, 4, 0);
    sfh_int8_t_int16_t_insert(&h2, &n5, 5, 0);

    sfh_int8_t_int16_t_meld(&h1, &h2, &merged);
    sfh_int8_t_int16_t_delete_min(merged);
    sfh_int8_t_int16_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int8_t_int16_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int8_t_int16_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int8_t_int16_t_insert(&heap, &fnodes[idx],
                                         (int8_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int8_t_int16_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int8_t_int16_t_decrease_key(&heap, &fnodes[idx], (int8_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int8_t_int16_t_node_t *min;
          sfh_int8_t_int16_t_find_min(&heap, &min);
          rc = sfh_int8_t_int16_t_delete_min(&heap);
          if (rc == sfh_int8_t_int16_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int8_t_int16_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int8_t_int16_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int8_t_int32_t(void) {
  sfh_int8_t_int32_t_heap_t heap;
  sfh_int8_t_int32_t_node_t node, node2;
  sfh_int8_t_int32_t_node_t *out_node;
  sfh_int8_t_int32_t_heap_t *out_heap;
  int is_empty;
  sfh_int8_t_int32_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int8_t_int32_t_init(NULL);
  rc = sfh_int8_t_int32_t_empty(NULL, &is_empty);
  rc = sfh_int8_t_int32_t_find_min(NULL, &out_node);
  rc = sfh_int8_t_int32_t_insert(NULL, &node, 1, 0);
  rc = sfh_int8_t_int32_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int8_t_int32_t_delete_min(NULL);
  rc = sfh_int8_t_int32_t_delete(NULL, &node);
  rc = sfh_int8_t_int32_t_delete(&heap, NULL);
  rc = sfh_int8_t_int32_t_decrease_key(NULL, &node, 1);
  rc = sfh_int8_t_int32_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int8_t_int32_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int8_t_int32_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int8_t_int32_t_meld(&heap, &heap, NULL);

  sfh_int8_t_int32_t_init(&heap);
  rc = sfh_int8_t_int32_t_empty(&heap, &is_empty);
  rc = sfh_int8_t_int32_t_find_min(&heap, &out_node);
  rc = sfh_int8_t_int32_t_delete_min(&heap);

  rc = sfh_int8_t_int32_t_insert(&heap, &node, 10, 0);
  rc = sfh_int8_t_int32_t_empty(&heap, &is_empty);
  rc = sfh_int8_t_int32_t_find_min(&heap, &out_node);

  rc = sfh_int8_t_int32_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int8_t_int32_t_delete(&heap, &node);
  rc = sfh_int8_t_int32_t_delete_min(&heap);

  {
    sfh_int8_t_int32_t_heap_t h1, h2, h3, *merged;
    sfh_int8_t_int32_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int8_t_int32_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int8_t_int32_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int8_t_int32_t_init(&h3);
    sfh_int8_t_int32_t_insert(&h1, &n1, 1, 0);
    sfh_int8_t_int32_t_insert(&h1, &n2, 2, 0);
    sfh_int8_t_int32_t_insert(&h1, &n3, 3, 0);
    sfh_int8_t_int32_t_insert(&h1, &n4, 4, 0);
    sfh_int8_t_int32_t_insert(&h2, &n5, 5, 0);

    sfh_int8_t_int32_t_meld(&h1, &h2, &merged);
    sfh_int8_t_int32_t_delete_min(merged);
    sfh_int8_t_int32_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int8_t_int32_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int8_t_int32_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int8_t_int32_t_insert(&heap, &fnodes[idx],
                                         (int8_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int8_t_int32_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int8_t_int32_t_decrease_key(&heap, &fnodes[idx], (int8_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int8_t_int32_t_node_t *min;
          sfh_int8_t_int32_t_find_min(&heap, &min);
          rc = sfh_int8_t_int32_t_delete_min(&heap);
          if (rc == sfh_int8_t_int32_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int8_t_int32_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int8_t_int32_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int8_t_int64_t(void) {
  sfh_int8_t_int64_t_heap_t heap;
  sfh_int8_t_int64_t_node_t node, node2;
  sfh_int8_t_int64_t_node_t *out_node;
  sfh_int8_t_int64_t_heap_t *out_heap;
  int is_empty;
  sfh_int8_t_int64_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int8_t_int64_t_init(NULL);
  rc = sfh_int8_t_int64_t_empty(NULL, &is_empty);
  rc = sfh_int8_t_int64_t_find_min(NULL, &out_node);
  rc = sfh_int8_t_int64_t_insert(NULL, &node, 1, 0);
  rc = sfh_int8_t_int64_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int8_t_int64_t_delete_min(NULL);
  rc = sfh_int8_t_int64_t_delete(NULL, &node);
  rc = sfh_int8_t_int64_t_delete(&heap, NULL);
  rc = sfh_int8_t_int64_t_decrease_key(NULL, &node, 1);
  rc = sfh_int8_t_int64_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int8_t_int64_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int8_t_int64_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int8_t_int64_t_meld(&heap, &heap, NULL);

  sfh_int8_t_int64_t_init(&heap);
  rc = sfh_int8_t_int64_t_empty(&heap, &is_empty);
  rc = sfh_int8_t_int64_t_find_min(&heap, &out_node);
  rc = sfh_int8_t_int64_t_delete_min(&heap);

  rc = sfh_int8_t_int64_t_insert(&heap, &node, 10, 0);
  rc = sfh_int8_t_int64_t_empty(&heap, &is_empty);
  rc = sfh_int8_t_int64_t_find_min(&heap, &out_node);

  rc = sfh_int8_t_int64_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int8_t_int64_t_delete(&heap, &node);
  rc = sfh_int8_t_int64_t_delete_min(&heap);

  {
    sfh_int8_t_int64_t_heap_t h1, h2, h3, *merged;
    sfh_int8_t_int64_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int8_t_int64_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int8_t_int64_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int8_t_int64_t_init(&h3);
    sfh_int8_t_int64_t_insert(&h1, &n1, 1, 0);
    sfh_int8_t_int64_t_insert(&h1, &n2, 2, 0);
    sfh_int8_t_int64_t_insert(&h1, &n3, 3, 0);
    sfh_int8_t_int64_t_insert(&h1, &n4, 4, 0);
    sfh_int8_t_int64_t_insert(&h2, &n5, 5, 0);

    sfh_int8_t_int64_t_meld(&h1, &h2, &merged);
    sfh_int8_t_int64_t_delete_min(merged);
    sfh_int8_t_int64_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int8_t_int64_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int8_t_int64_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int8_t_int64_t_insert(&heap, &fnodes[idx],
                                         (int8_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int8_t_int64_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int8_t_int64_t_decrease_key(&heap, &fnodes[idx], (int8_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int8_t_int64_t_node_t *min;
          sfh_int8_t_int64_t_find_min(&heap, &min);
          rc = sfh_int8_t_int64_t_delete_min(&heap);
          if (rc == sfh_int8_t_int64_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int8_t_int64_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int8_t_int64_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int8_t_uint8_t(void) {
  sfh_int8_t_uint8_t_heap_t heap;
  sfh_int8_t_uint8_t_node_t node, node2;
  sfh_int8_t_uint8_t_node_t *out_node;
  sfh_int8_t_uint8_t_heap_t *out_heap;
  int is_empty;
  sfh_int8_t_uint8_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int8_t_uint8_t_init(NULL);
  rc = sfh_int8_t_uint8_t_empty(NULL, &is_empty);
  rc = sfh_int8_t_uint8_t_find_min(NULL, &out_node);
  rc = sfh_int8_t_uint8_t_insert(NULL, &node, 1, 0);
  rc = sfh_int8_t_uint8_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int8_t_uint8_t_delete_min(NULL);
  rc = sfh_int8_t_uint8_t_delete(NULL, &node);
  rc = sfh_int8_t_uint8_t_delete(&heap, NULL);
  rc = sfh_int8_t_uint8_t_decrease_key(NULL, &node, 1);
  rc = sfh_int8_t_uint8_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int8_t_uint8_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int8_t_uint8_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int8_t_uint8_t_meld(&heap, &heap, NULL);

  sfh_int8_t_uint8_t_init(&heap);
  rc = sfh_int8_t_uint8_t_empty(&heap, &is_empty);
  rc = sfh_int8_t_uint8_t_find_min(&heap, &out_node);
  rc = sfh_int8_t_uint8_t_delete_min(&heap);

  rc = sfh_int8_t_uint8_t_insert(&heap, &node, 10, 0);
  rc = sfh_int8_t_uint8_t_empty(&heap, &is_empty);
  rc = sfh_int8_t_uint8_t_find_min(&heap, &out_node);

  rc = sfh_int8_t_uint8_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int8_t_uint8_t_delete(&heap, &node);
  rc = sfh_int8_t_uint8_t_delete_min(&heap);

  {
    sfh_int8_t_uint8_t_heap_t h1, h2, h3, *merged;
    sfh_int8_t_uint8_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int8_t_uint8_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int8_t_uint8_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int8_t_uint8_t_init(&h3);
    sfh_int8_t_uint8_t_insert(&h1, &n1, 1, 0);
    sfh_int8_t_uint8_t_insert(&h1, &n2, 2, 0);
    sfh_int8_t_uint8_t_insert(&h1, &n3, 3, 0);
    sfh_int8_t_uint8_t_insert(&h1, &n4, 4, 0);
    sfh_int8_t_uint8_t_insert(&h2, &n5, 5, 0);

    sfh_int8_t_uint8_t_meld(&h1, &h2, &merged);
    sfh_int8_t_uint8_t_delete_min(merged);
    sfh_int8_t_uint8_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int8_t_uint8_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int8_t_uint8_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int8_t_uint8_t_insert(&heap, &fnodes[idx],
                                         (int8_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int8_t_uint8_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int8_t_uint8_t_decrease_key(&heap, &fnodes[idx], (int8_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int8_t_uint8_t_node_t *min;
          sfh_int8_t_uint8_t_find_min(&heap, &min);
          rc = sfh_int8_t_uint8_t_delete_min(&heap);
          if (rc == sfh_int8_t_uint8_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int8_t_uint8_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int8_t_uint8_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int8_t_uint16_t(void) {
  sfh_int8_t_uint16_t_heap_t heap;
  sfh_int8_t_uint16_t_node_t node, node2;
  sfh_int8_t_uint16_t_node_t *out_node;
  sfh_int8_t_uint16_t_heap_t *out_heap;
  int is_empty;
  sfh_int8_t_uint16_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int8_t_uint16_t_init(NULL);
  rc = sfh_int8_t_uint16_t_empty(NULL, &is_empty);
  rc = sfh_int8_t_uint16_t_find_min(NULL, &out_node);
  rc = sfh_int8_t_uint16_t_insert(NULL, &node, 1, 0);
  rc = sfh_int8_t_uint16_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int8_t_uint16_t_delete_min(NULL);
  rc = sfh_int8_t_uint16_t_delete(NULL, &node);
  rc = sfh_int8_t_uint16_t_delete(&heap, NULL);
  rc = sfh_int8_t_uint16_t_decrease_key(NULL, &node, 1);
  rc = sfh_int8_t_uint16_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int8_t_uint16_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int8_t_uint16_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int8_t_uint16_t_meld(&heap, &heap, NULL);

  sfh_int8_t_uint16_t_init(&heap);
  rc = sfh_int8_t_uint16_t_empty(&heap, &is_empty);
  rc = sfh_int8_t_uint16_t_find_min(&heap, &out_node);
  rc = sfh_int8_t_uint16_t_delete_min(&heap);

  rc = sfh_int8_t_uint16_t_insert(&heap, &node, 10, 0);
  rc = sfh_int8_t_uint16_t_empty(&heap, &is_empty);
  rc = sfh_int8_t_uint16_t_find_min(&heap, &out_node);

  rc = sfh_int8_t_uint16_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int8_t_uint16_t_delete(&heap, &node);
  rc = sfh_int8_t_uint16_t_delete_min(&heap);

  {
    sfh_int8_t_uint16_t_heap_t h1, h2, h3, *merged;
    sfh_int8_t_uint16_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int8_t_uint16_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int8_t_uint16_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int8_t_uint16_t_init(&h3);
    sfh_int8_t_uint16_t_insert(&h1, &n1, 1, 0);
    sfh_int8_t_uint16_t_insert(&h1, &n2, 2, 0);
    sfh_int8_t_uint16_t_insert(&h1, &n3, 3, 0);
    sfh_int8_t_uint16_t_insert(&h1, &n4, 4, 0);
    sfh_int8_t_uint16_t_insert(&h2, &n5, 5, 0);

    sfh_int8_t_uint16_t_meld(&h1, &h2, &merged);
    sfh_int8_t_uint16_t_delete_min(merged);
    sfh_int8_t_uint16_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int8_t_uint16_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int8_t_uint16_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int8_t_uint16_t_insert(&heap, &fnodes[idx],
                                          (int8_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int8_t_uint16_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int8_t_uint16_t_decrease_key(&heap, &fnodes[idx], (int8_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int8_t_uint16_t_node_t *min;
          sfh_int8_t_uint16_t_find_min(&heap, &min);
          rc = sfh_int8_t_uint16_t_delete_min(&heap);
          if (rc == sfh_int8_t_uint16_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int8_t_uint16_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int8_t_uint16_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int8_t_uint32_t(void) {
  sfh_int8_t_uint32_t_heap_t heap;
  sfh_int8_t_uint32_t_node_t node, node2;
  sfh_int8_t_uint32_t_node_t *out_node;
  sfh_int8_t_uint32_t_heap_t *out_heap;
  int is_empty;
  sfh_int8_t_uint32_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int8_t_uint32_t_init(NULL);
  rc = sfh_int8_t_uint32_t_empty(NULL, &is_empty);
  rc = sfh_int8_t_uint32_t_find_min(NULL, &out_node);
  rc = sfh_int8_t_uint32_t_insert(NULL, &node, 1, 0);
  rc = sfh_int8_t_uint32_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int8_t_uint32_t_delete_min(NULL);
  rc = sfh_int8_t_uint32_t_delete(NULL, &node);
  rc = sfh_int8_t_uint32_t_delete(&heap, NULL);
  rc = sfh_int8_t_uint32_t_decrease_key(NULL, &node, 1);
  rc = sfh_int8_t_uint32_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int8_t_uint32_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int8_t_uint32_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int8_t_uint32_t_meld(&heap, &heap, NULL);

  sfh_int8_t_uint32_t_init(&heap);
  rc = sfh_int8_t_uint32_t_empty(&heap, &is_empty);
  rc = sfh_int8_t_uint32_t_find_min(&heap, &out_node);
  rc = sfh_int8_t_uint32_t_delete_min(&heap);

  rc = sfh_int8_t_uint32_t_insert(&heap, &node, 10, 0);
  rc = sfh_int8_t_uint32_t_empty(&heap, &is_empty);
  rc = sfh_int8_t_uint32_t_find_min(&heap, &out_node);

  rc = sfh_int8_t_uint32_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int8_t_uint32_t_delete(&heap, &node);
  rc = sfh_int8_t_uint32_t_delete_min(&heap);

  {
    sfh_int8_t_uint32_t_heap_t h1, h2, h3, *merged;
    sfh_int8_t_uint32_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int8_t_uint32_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int8_t_uint32_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int8_t_uint32_t_init(&h3);
    sfh_int8_t_uint32_t_insert(&h1, &n1, 1, 0);
    sfh_int8_t_uint32_t_insert(&h1, &n2, 2, 0);
    sfh_int8_t_uint32_t_insert(&h1, &n3, 3, 0);
    sfh_int8_t_uint32_t_insert(&h1, &n4, 4, 0);
    sfh_int8_t_uint32_t_insert(&h2, &n5, 5, 0);

    sfh_int8_t_uint32_t_meld(&h1, &h2, &merged);
    sfh_int8_t_uint32_t_delete_min(merged);
    sfh_int8_t_uint32_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int8_t_uint32_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int8_t_uint32_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int8_t_uint32_t_insert(&heap, &fnodes[idx],
                                          (int8_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int8_t_uint32_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int8_t_uint32_t_decrease_key(&heap, &fnodes[idx], (int8_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int8_t_uint32_t_node_t *min;
          sfh_int8_t_uint32_t_find_min(&heap, &min);
          rc = sfh_int8_t_uint32_t_delete_min(&heap);
          if (rc == sfh_int8_t_uint32_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int8_t_uint32_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int8_t_uint32_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int8_t_uint64_t(void) {
  sfh_int8_t_uint64_t_heap_t heap;
  sfh_int8_t_uint64_t_node_t node, node2;
  sfh_int8_t_uint64_t_node_t *out_node;
  sfh_int8_t_uint64_t_heap_t *out_heap;
  int is_empty;
  sfh_int8_t_uint64_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int8_t_uint64_t_init(NULL);
  rc = sfh_int8_t_uint64_t_empty(NULL, &is_empty);
  rc = sfh_int8_t_uint64_t_find_min(NULL, &out_node);
  rc = sfh_int8_t_uint64_t_insert(NULL, &node, 1, 0);
  rc = sfh_int8_t_uint64_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int8_t_uint64_t_delete_min(NULL);
  rc = sfh_int8_t_uint64_t_delete(NULL, &node);
  rc = sfh_int8_t_uint64_t_delete(&heap, NULL);
  rc = sfh_int8_t_uint64_t_decrease_key(NULL, &node, 1);
  rc = sfh_int8_t_uint64_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int8_t_uint64_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int8_t_uint64_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int8_t_uint64_t_meld(&heap, &heap, NULL);

  sfh_int8_t_uint64_t_init(&heap);
  rc = sfh_int8_t_uint64_t_empty(&heap, &is_empty);
  rc = sfh_int8_t_uint64_t_find_min(&heap, &out_node);
  rc = sfh_int8_t_uint64_t_delete_min(&heap);

  rc = sfh_int8_t_uint64_t_insert(&heap, &node, 10, 0);
  rc = sfh_int8_t_uint64_t_empty(&heap, &is_empty);
  rc = sfh_int8_t_uint64_t_find_min(&heap, &out_node);

  rc = sfh_int8_t_uint64_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int8_t_uint64_t_delete(&heap, &node);
  rc = sfh_int8_t_uint64_t_delete_min(&heap);

  {
    sfh_int8_t_uint64_t_heap_t h1, h2, h3, *merged;
    sfh_int8_t_uint64_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int8_t_uint64_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int8_t_uint64_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int8_t_uint64_t_init(&h3);
    sfh_int8_t_uint64_t_insert(&h1, &n1, 1, 0);
    sfh_int8_t_uint64_t_insert(&h1, &n2, 2, 0);
    sfh_int8_t_uint64_t_insert(&h1, &n3, 3, 0);
    sfh_int8_t_uint64_t_insert(&h1, &n4, 4, 0);
    sfh_int8_t_uint64_t_insert(&h2, &n5, 5, 0);

    sfh_int8_t_uint64_t_meld(&h1, &h2, &merged);
    sfh_int8_t_uint64_t_delete_min(merged);
    sfh_int8_t_uint64_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int8_t_uint64_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int8_t_uint64_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int8_t_uint64_t_insert(&heap, &fnodes[idx],
                                          (int8_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int8_t_uint64_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int8_t_uint64_t_decrease_key(&heap, &fnodes[idx], (int8_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int8_t_uint64_t_node_t *min;
          sfh_int8_t_uint64_t_find_min(&heap, &min);
          rc = sfh_int8_t_uint64_t_delete_min(&heap);
          if (rc == sfh_int8_t_uint64_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int8_t_uint64_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int8_t_uint64_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int8_t_float(void) {
  sfh_int8_t_float_heap_t heap;
  sfh_int8_t_float_node_t node, node2;
  sfh_int8_t_float_node_t *out_node;
  sfh_int8_t_float_heap_t *out_heap;
  int is_empty;
  sfh_int8_t_float_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int8_t_float_init(NULL);
  rc = sfh_int8_t_float_empty(NULL, &is_empty);
  rc = sfh_int8_t_float_find_min(NULL, &out_node);
  rc = sfh_int8_t_float_insert(NULL, &node, 1, 0);
  rc = sfh_int8_t_float_insert(&heap, NULL, 1, 0);
  rc = sfh_int8_t_float_delete_min(NULL);
  rc = sfh_int8_t_float_delete(NULL, &node);
  rc = sfh_int8_t_float_delete(&heap, NULL);
  rc = sfh_int8_t_float_decrease_key(NULL, &node, 1);
  rc = sfh_int8_t_float_decrease_key(&heap, NULL, 1);
  rc = sfh_int8_t_float_meld(NULL, &heap, &out_heap);
  rc = sfh_int8_t_float_meld(&heap, NULL, &out_heap);
  rc = sfh_int8_t_float_meld(&heap, &heap, NULL);

  sfh_int8_t_float_init(&heap);
  rc = sfh_int8_t_float_empty(&heap, &is_empty);
  rc = sfh_int8_t_float_find_min(&heap, &out_node);
  rc = sfh_int8_t_float_delete_min(&heap);

  rc = sfh_int8_t_float_insert(&heap, &node, 10, 0);
  rc = sfh_int8_t_float_empty(&heap, &is_empty);
  rc = sfh_int8_t_float_find_min(&heap, &out_node);

  rc = sfh_int8_t_float_insert(&heap, &node2, 10, 0);
  rc = sfh_int8_t_float_delete(&heap, &node);
  rc = sfh_int8_t_float_delete_min(&heap);

  {
    sfh_int8_t_float_heap_t h1, h2, h3, *merged;
    sfh_int8_t_float_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int8_t_float_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int8_t_float_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int8_t_float_init(&h3);
    sfh_int8_t_float_insert(&h1, &n1, 1, 0);
    sfh_int8_t_float_insert(&h1, &n2, 2, 0);
    sfh_int8_t_float_insert(&h1, &n3, 3, 0);
    sfh_int8_t_float_insert(&h1, &n4, 4, 0);
    sfh_int8_t_float_insert(&h2, &n5, 5, 0);

    sfh_int8_t_float_meld(&h1, &h2, &merged);
    sfh_int8_t_float_delete_min(merged);
    sfh_int8_t_float_meld(&h3, merged, &merged);
  }

  {
    static sfh_int8_t_float_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int8_t_float_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int8_t_float_insert(&heap, &fnodes[idx],
                                       (int8_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int8_t_float_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int8_t_float_decrease_key(&heap, &fnodes[idx], (int8_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int8_t_float_node_t *min;
          sfh_int8_t_float_find_min(&heap, &min);
          rc = sfh_int8_t_float_delete_min(&heap);
          if (rc == sfh_int8_t_float_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int8_t_float_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int8_t_float_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int8_t_double(void) {
  sfh_int8_t_double_heap_t heap;
  sfh_int8_t_double_node_t node, node2;
  sfh_int8_t_double_node_t *out_node;
  sfh_int8_t_double_heap_t *out_heap;
  int is_empty;
  sfh_int8_t_double_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int8_t_double_init(NULL);
  rc = sfh_int8_t_double_empty(NULL, &is_empty);
  rc = sfh_int8_t_double_find_min(NULL, &out_node);
  rc = sfh_int8_t_double_insert(NULL, &node, 1, 0);
  rc = sfh_int8_t_double_insert(&heap, NULL, 1, 0);
  rc = sfh_int8_t_double_delete_min(NULL);
  rc = sfh_int8_t_double_delete(NULL, &node);
  rc = sfh_int8_t_double_delete(&heap, NULL);
  rc = sfh_int8_t_double_decrease_key(NULL, &node, 1);
  rc = sfh_int8_t_double_decrease_key(&heap, NULL, 1);
  rc = sfh_int8_t_double_meld(NULL, &heap, &out_heap);
  rc = sfh_int8_t_double_meld(&heap, NULL, &out_heap);
  rc = sfh_int8_t_double_meld(&heap, &heap, NULL);

  sfh_int8_t_double_init(&heap);
  rc = sfh_int8_t_double_empty(&heap, &is_empty);
  rc = sfh_int8_t_double_find_min(&heap, &out_node);
  rc = sfh_int8_t_double_delete_min(&heap);

  rc = sfh_int8_t_double_insert(&heap, &node, 10, 0);
  rc = sfh_int8_t_double_empty(&heap, &is_empty);
  rc = sfh_int8_t_double_find_min(&heap, &out_node);

  rc = sfh_int8_t_double_insert(&heap, &node2, 10, 0);
  rc = sfh_int8_t_double_delete(&heap, &node);
  rc = sfh_int8_t_double_delete_min(&heap);

  {
    sfh_int8_t_double_heap_t h1, h2, h3, *merged;
    sfh_int8_t_double_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int8_t_double_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int8_t_double_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int8_t_double_init(&h3);
    sfh_int8_t_double_insert(&h1, &n1, 1, 0);
    sfh_int8_t_double_insert(&h1, &n2, 2, 0);
    sfh_int8_t_double_insert(&h1, &n3, 3, 0);
    sfh_int8_t_double_insert(&h1, &n4, 4, 0);
    sfh_int8_t_double_insert(&h2, &n5, 5, 0);

    sfh_int8_t_double_meld(&h1, &h2, &merged);
    sfh_int8_t_double_delete_min(merged);
    sfh_int8_t_double_meld(&h3, merged, &merged);
  }

  {
    static sfh_int8_t_double_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int8_t_double_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int8_t_double_insert(&heap, &fnodes[idx],
                                        (int8_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int8_t_double_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int8_t_double_decrease_key(&heap, &fnodes[idx], (int8_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int8_t_double_node_t *min;
          sfh_int8_t_double_find_min(&heap, &min);
          rc = sfh_int8_t_double_delete_min(&heap);
          if (rc == sfh_int8_t_double_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int8_t_double_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int8_t_double_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int8_t_charptr(void) {
  sfh_int8_t_charptr_heap_t heap;
  sfh_int8_t_charptr_node_t node, node2;
  sfh_int8_t_charptr_node_t *out_node;
  sfh_int8_t_charptr_heap_t *out_heap;
  int is_empty;
  sfh_int8_t_charptr_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int8_t_charptr_init(NULL);
  rc = sfh_int8_t_charptr_empty(NULL, &is_empty);
  rc = sfh_int8_t_charptr_find_min(NULL, &out_node);
  rc = sfh_int8_t_charptr_insert(NULL, &node, 1, 0);
  rc = sfh_int8_t_charptr_insert(&heap, NULL, 1, 0);
  rc = sfh_int8_t_charptr_delete_min(NULL);
  rc = sfh_int8_t_charptr_delete(NULL, &node);
  rc = sfh_int8_t_charptr_delete(&heap, NULL);
  rc = sfh_int8_t_charptr_decrease_key(NULL, &node, 1);
  rc = sfh_int8_t_charptr_decrease_key(&heap, NULL, 1);
  rc = sfh_int8_t_charptr_meld(NULL, &heap, &out_heap);
  rc = sfh_int8_t_charptr_meld(&heap, NULL, &out_heap);
  rc = sfh_int8_t_charptr_meld(&heap, &heap, NULL);

  sfh_int8_t_charptr_init(&heap);
  rc = sfh_int8_t_charptr_empty(&heap, &is_empty);
  rc = sfh_int8_t_charptr_find_min(&heap, &out_node);
  rc = sfh_int8_t_charptr_delete_min(&heap);

  rc = sfh_int8_t_charptr_insert(&heap, &node, 10, 0);
  rc = sfh_int8_t_charptr_empty(&heap, &is_empty);
  rc = sfh_int8_t_charptr_find_min(&heap, &out_node);

  rc = sfh_int8_t_charptr_insert(&heap, &node2, 10, 0);
  rc = sfh_int8_t_charptr_delete(&heap, &node);
  rc = sfh_int8_t_charptr_delete_min(&heap);

  {
    sfh_int8_t_charptr_heap_t h1, h2, h3, *merged;
    sfh_int8_t_charptr_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int8_t_charptr_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int8_t_charptr_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int8_t_charptr_init(&h3);
    sfh_int8_t_charptr_insert(&h1, &n1, 1, 0);
    sfh_int8_t_charptr_insert(&h1, &n2, 2, 0);
    sfh_int8_t_charptr_insert(&h1, &n3, 3, 0);
    sfh_int8_t_charptr_insert(&h1, &n4, 4, 0);
    sfh_int8_t_charptr_insert(&h2, &n5, 5, 0);

    sfh_int8_t_charptr_meld(&h1, &h2, &merged);
    sfh_int8_t_charptr_delete_min(merged);
    sfh_int8_t_charptr_meld(&h3, merged, &merged);
  }

  {
    static sfh_int8_t_charptr_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int8_t_charptr_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int8_t_charptr_insert(&heap, &fnodes[idx],
                                         (int8_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int8_t_charptr_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int8_t_charptr_decrease_key(&heap, &fnodes[idx], (int8_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int8_t_charptr_node_t *min;
          sfh_int8_t_charptr_find_min(&heap, &min);
          rc = sfh_int8_t_charptr_delete_min(&heap);
          if (rc == sfh_int8_t_charptr_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int8_t_charptr_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int8_t_charptr_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int8_t_voidptr(void) {
  sfh_int8_t_voidptr_heap_t heap;
  sfh_int8_t_voidptr_node_t node, node2;
  sfh_int8_t_voidptr_node_t *out_node;
  sfh_int8_t_voidptr_heap_t *out_heap;
  int is_empty;
  sfh_int8_t_voidptr_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int8_t_voidptr_init(NULL);
  rc = sfh_int8_t_voidptr_empty(NULL, &is_empty);
  rc = sfh_int8_t_voidptr_find_min(NULL, &out_node);
  rc = sfh_int8_t_voidptr_insert(NULL, &node, 1, 0);
  rc = sfh_int8_t_voidptr_insert(&heap, NULL, 1, 0);
  rc = sfh_int8_t_voidptr_delete_min(NULL);
  rc = sfh_int8_t_voidptr_delete(NULL, &node);
  rc = sfh_int8_t_voidptr_delete(&heap, NULL);
  rc = sfh_int8_t_voidptr_decrease_key(NULL, &node, 1);
  rc = sfh_int8_t_voidptr_decrease_key(&heap, NULL, 1);
  rc = sfh_int8_t_voidptr_meld(NULL, &heap, &out_heap);
  rc = sfh_int8_t_voidptr_meld(&heap, NULL, &out_heap);
  rc = sfh_int8_t_voidptr_meld(&heap, &heap, NULL);

  sfh_int8_t_voidptr_init(&heap);
  rc = sfh_int8_t_voidptr_empty(&heap, &is_empty);
  rc = sfh_int8_t_voidptr_find_min(&heap, &out_node);
  rc = sfh_int8_t_voidptr_delete_min(&heap);

  rc = sfh_int8_t_voidptr_insert(&heap, &node, 10, 0);
  rc = sfh_int8_t_voidptr_empty(&heap, &is_empty);
  rc = sfh_int8_t_voidptr_find_min(&heap, &out_node);

  rc = sfh_int8_t_voidptr_insert(&heap, &node2, 10, 0);
  rc = sfh_int8_t_voidptr_delete(&heap, &node);
  rc = sfh_int8_t_voidptr_delete_min(&heap);

  {
    sfh_int8_t_voidptr_heap_t h1, h2, h3, *merged;
    sfh_int8_t_voidptr_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int8_t_voidptr_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int8_t_voidptr_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int8_t_voidptr_init(&h3);
    sfh_int8_t_voidptr_insert(&h1, &n1, 1, 0);
    sfh_int8_t_voidptr_insert(&h1, &n2, 2, 0);
    sfh_int8_t_voidptr_insert(&h1, &n3, 3, 0);
    sfh_int8_t_voidptr_insert(&h1, &n4, 4, 0);
    sfh_int8_t_voidptr_insert(&h2, &n5, 5, 0);

    sfh_int8_t_voidptr_meld(&h1, &h2, &merged);
    sfh_int8_t_voidptr_delete_min(merged);
    sfh_int8_t_voidptr_meld(&h3, merged, &merged);
  }

  {
    static sfh_int8_t_voidptr_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int8_t_voidptr_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int8_t_voidptr_insert(&heap, &fnodes[idx],
                                         (int8_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int8_t_voidptr_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int8_t_voidptr_decrease_key(&heap, &fnodes[idx], (int8_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int8_t_voidptr_node_t *min;
          sfh_int8_t_voidptr_find_min(&heap, &min);
          rc = sfh_int8_t_voidptr_delete_min(&heap);
          if (rc == sfh_int8_t_voidptr_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int8_t_voidptr_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int8_t_voidptr_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int16_t_int8_t(void) {
  sfh_int16_t_int8_t_heap_t heap;
  sfh_int16_t_int8_t_node_t node, node2;
  sfh_int16_t_int8_t_node_t *out_node;
  sfh_int16_t_int8_t_heap_t *out_heap;
  int is_empty;
  sfh_int16_t_int8_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int16_t_int8_t_init(NULL);
  rc = sfh_int16_t_int8_t_empty(NULL, &is_empty);
  rc = sfh_int16_t_int8_t_find_min(NULL, &out_node);
  rc = sfh_int16_t_int8_t_insert(NULL, &node, 1, 0);
  rc = sfh_int16_t_int8_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int16_t_int8_t_delete_min(NULL);
  rc = sfh_int16_t_int8_t_delete(NULL, &node);
  rc = sfh_int16_t_int8_t_delete(&heap, NULL);
  rc = sfh_int16_t_int8_t_decrease_key(NULL, &node, 1);
  rc = sfh_int16_t_int8_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int16_t_int8_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int16_t_int8_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int16_t_int8_t_meld(&heap, &heap, NULL);

  sfh_int16_t_int8_t_init(&heap);
  rc = sfh_int16_t_int8_t_empty(&heap, &is_empty);
  rc = sfh_int16_t_int8_t_find_min(&heap, &out_node);
  rc = sfh_int16_t_int8_t_delete_min(&heap);

  rc = sfh_int16_t_int8_t_insert(&heap, &node, 10, 0);
  rc = sfh_int16_t_int8_t_empty(&heap, &is_empty);
  rc = sfh_int16_t_int8_t_find_min(&heap, &out_node);

  rc = sfh_int16_t_int8_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int16_t_int8_t_delete(&heap, &node);
  rc = sfh_int16_t_int8_t_delete_min(&heap);

  {
    sfh_int16_t_int8_t_heap_t h1, h2, h3, *merged;
    sfh_int16_t_int8_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int16_t_int8_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int16_t_int8_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int16_t_int8_t_init(&h3);
    sfh_int16_t_int8_t_insert(&h1, &n1, 1, 0);
    sfh_int16_t_int8_t_insert(&h1, &n2, 2, 0);
    sfh_int16_t_int8_t_insert(&h1, &n3, 3, 0);
    sfh_int16_t_int8_t_insert(&h1, &n4, 4, 0);
    sfh_int16_t_int8_t_insert(&h2, &n5, 5, 0);

    sfh_int16_t_int8_t_meld(&h1, &h2, &merged);
    sfh_int16_t_int8_t_delete_min(merged);
    sfh_int16_t_int8_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int16_t_int8_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int16_t_int8_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int16_t_int8_t_insert(&heap, &fnodes[idx],
                                         (int16_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int16_t_int8_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int16_t_int8_t_decrease_key(&heap, &fnodes[idx], (int16_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int16_t_int8_t_node_t *min;
          sfh_int16_t_int8_t_find_min(&heap, &min);
          rc = sfh_int16_t_int8_t_delete_min(&heap);
          if (rc == sfh_int16_t_int8_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int16_t_int8_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int16_t_int8_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int16_t_int16_t(void) {
  sfh_int16_t_int16_t_heap_t heap;
  sfh_int16_t_int16_t_node_t node, node2;
  sfh_int16_t_int16_t_node_t *out_node;
  sfh_int16_t_int16_t_heap_t *out_heap;
  int is_empty;
  sfh_int16_t_int16_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int16_t_int16_t_init(NULL);
  rc = sfh_int16_t_int16_t_empty(NULL, &is_empty);
  rc = sfh_int16_t_int16_t_find_min(NULL, &out_node);
  rc = sfh_int16_t_int16_t_insert(NULL, &node, 1, 0);
  rc = sfh_int16_t_int16_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int16_t_int16_t_delete_min(NULL);
  rc = sfh_int16_t_int16_t_delete(NULL, &node);
  rc = sfh_int16_t_int16_t_delete(&heap, NULL);
  rc = sfh_int16_t_int16_t_decrease_key(NULL, &node, 1);
  rc = sfh_int16_t_int16_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int16_t_int16_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int16_t_int16_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int16_t_int16_t_meld(&heap, &heap, NULL);

  sfh_int16_t_int16_t_init(&heap);
  rc = sfh_int16_t_int16_t_empty(&heap, &is_empty);
  rc = sfh_int16_t_int16_t_find_min(&heap, &out_node);
  rc = sfh_int16_t_int16_t_delete_min(&heap);

  rc = sfh_int16_t_int16_t_insert(&heap, &node, 10, 0);
  rc = sfh_int16_t_int16_t_empty(&heap, &is_empty);
  rc = sfh_int16_t_int16_t_find_min(&heap, &out_node);

  rc = sfh_int16_t_int16_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int16_t_int16_t_delete(&heap, &node);
  rc = sfh_int16_t_int16_t_delete_min(&heap);

  {
    sfh_int16_t_int16_t_heap_t h1, h2, h3, *merged;
    sfh_int16_t_int16_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int16_t_int16_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int16_t_int16_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int16_t_int16_t_init(&h3);
    sfh_int16_t_int16_t_insert(&h1, &n1, 1, 0);
    sfh_int16_t_int16_t_insert(&h1, &n2, 2, 0);
    sfh_int16_t_int16_t_insert(&h1, &n3, 3, 0);
    sfh_int16_t_int16_t_insert(&h1, &n4, 4, 0);
    sfh_int16_t_int16_t_insert(&h2, &n5, 5, 0);

    sfh_int16_t_int16_t_meld(&h1, &h2, &merged);
    sfh_int16_t_int16_t_delete_min(merged);
    sfh_int16_t_int16_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int16_t_int16_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int16_t_int16_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int16_t_int16_t_insert(&heap, &fnodes[idx],
                                          (int16_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int16_t_int16_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc =
              sfh_int16_t_int16_t_decrease_key(&heap, &fnodes[idx], (int16_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int16_t_int16_t_node_t *min;
          sfh_int16_t_int16_t_find_min(&heap, &min);
          rc = sfh_int16_t_int16_t_delete_min(&heap);
          if (rc == sfh_int16_t_int16_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int16_t_int16_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int16_t_int16_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int16_t_int32_t(void) {
  sfh_int16_t_int32_t_heap_t heap;
  sfh_int16_t_int32_t_node_t node, node2;
  sfh_int16_t_int32_t_node_t *out_node;
  sfh_int16_t_int32_t_heap_t *out_heap;
  int is_empty;
  sfh_int16_t_int32_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int16_t_int32_t_init(NULL);
  rc = sfh_int16_t_int32_t_empty(NULL, &is_empty);
  rc = sfh_int16_t_int32_t_find_min(NULL, &out_node);
  rc = sfh_int16_t_int32_t_insert(NULL, &node, 1, 0);
  rc = sfh_int16_t_int32_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int16_t_int32_t_delete_min(NULL);
  rc = sfh_int16_t_int32_t_delete(NULL, &node);
  rc = sfh_int16_t_int32_t_delete(&heap, NULL);
  rc = sfh_int16_t_int32_t_decrease_key(NULL, &node, 1);
  rc = sfh_int16_t_int32_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int16_t_int32_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int16_t_int32_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int16_t_int32_t_meld(&heap, &heap, NULL);

  sfh_int16_t_int32_t_init(&heap);
  rc = sfh_int16_t_int32_t_empty(&heap, &is_empty);
  rc = sfh_int16_t_int32_t_find_min(&heap, &out_node);
  rc = sfh_int16_t_int32_t_delete_min(&heap);

  rc = sfh_int16_t_int32_t_insert(&heap, &node, 10, 0);
  rc = sfh_int16_t_int32_t_empty(&heap, &is_empty);
  rc = sfh_int16_t_int32_t_find_min(&heap, &out_node);

  rc = sfh_int16_t_int32_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int16_t_int32_t_delete(&heap, &node);
  rc = sfh_int16_t_int32_t_delete_min(&heap);

  {
    sfh_int16_t_int32_t_heap_t h1, h2, h3, *merged;
    sfh_int16_t_int32_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int16_t_int32_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int16_t_int32_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int16_t_int32_t_init(&h3);
    sfh_int16_t_int32_t_insert(&h1, &n1, 1, 0);
    sfh_int16_t_int32_t_insert(&h1, &n2, 2, 0);
    sfh_int16_t_int32_t_insert(&h1, &n3, 3, 0);
    sfh_int16_t_int32_t_insert(&h1, &n4, 4, 0);
    sfh_int16_t_int32_t_insert(&h2, &n5, 5, 0);

    sfh_int16_t_int32_t_meld(&h1, &h2, &merged);
    sfh_int16_t_int32_t_delete_min(merged);
    sfh_int16_t_int32_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int16_t_int32_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int16_t_int32_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int16_t_int32_t_insert(&heap, &fnodes[idx],
                                          (int16_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int16_t_int32_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc =
              sfh_int16_t_int32_t_decrease_key(&heap, &fnodes[idx], (int16_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int16_t_int32_t_node_t *min;
          sfh_int16_t_int32_t_find_min(&heap, &min);
          rc = sfh_int16_t_int32_t_delete_min(&heap);
          if (rc == sfh_int16_t_int32_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int16_t_int32_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int16_t_int32_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int16_t_int64_t(void) {
  sfh_int16_t_int64_t_heap_t heap;
  sfh_int16_t_int64_t_node_t node, node2;
  sfh_int16_t_int64_t_node_t *out_node;
  sfh_int16_t_int64_t_heap_t *out_heap;
  int is_empty;
  sfh_int16_t_int64_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int16_t_int64_t_init(NULL);
  rc = sfh_int16_t_int64_t_empty(NULL, &is_empty);
  rc = sfh_int16_t_int64_t_find_min(NULL, &out_node);
  rc = sfh_int16_t_int64_t_insert(NULL, &node, 1, 0);
  rc = sfh_int16_t_int64_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int16_t_int64_t_delete_min(NULL);
  rc = sfh_int16_t_int64_t_delete(NULL, &node);
  rc = sfh_int16_t_int64_t_delete(&heap, NULL);
  rc = sfh_int16_t_int64_t_decrease_key(NULL, &node, 1);
  rc = sfh_int16_t_int64_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int16_t_int64_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int16_t_int64_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int16_t_int64_t_meld(&heap, &heap, NULL);

  sfh_int16_t_int64_t_init(&heap);
  rc = sfh_int16_t_int64_t_empty(&heap, &is_empty);
  rc = sfh_int16_t_int64_t_find_min(&heap, &out_node);
  rc = sfh_int16_t_int64_t_delete_min(&heap);

  rc = sfh_int16_t_int64_t_insert(&heap, &node, 10, 0);
  rc = sfh_int16_t_int64_t_empty(&heap, &is_empty);
  rc = sfh_int16_t_int64_t_find_min(&heap, &out_node);

  rc = sfh_int16_t_int64_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int16_t_int64_t_delete(&heap, &node);
  rc = sfh_int16_t_int64_t_delete_min(&heap);

  {
    sfh_int16_t_int64_t_heap_t h1, h2, h3, *merged;
    sfh_int16_t_int64_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int16_t_int64_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int16_t_int64_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int16_t_int64_t_init(&h3);
    sfh_int16_t_int64_t_insert(&h1, &n1, 1, 0);
    sfh_int16_t_int64_t_insert(&h1, &n2, 2, 0);
    sfh_int16_t_int64_t_insert(&h1, &n3, 3, 0);
    sfh_int16_t_int64_t_insert(&h1, &n4, 4, 0);
    sfh_int16_t_int64_t_insert(&h2, &n5, 5, 0);

    sfh_int16_t_int64_t_meld(&h1, &h2, &merged);
    sfh_int16_t_int64_t_delete_min(merged);
    sfh_int16_t_int64_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int16_t_int64_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int16_t_int64_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int16_t_int64_t_insert(&heap, &fnodes[idx],
                                          (int16_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int16_t_int64_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc =
              sfh_int16_t_int64_t_decrease_key(&heap, &fnodes[idx], (int16_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int16_t_int64_t_node_t *min;
          sfh_int16_t_int64_t_find_min(&heap, &min);
          rc = sfh_int16_t_int64_t_delete_min(&heap);
          if (rc == sfh_int16_t_int64_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int16_t_int64_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int16_t_int64_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int16_t_uint8_t(void) {
  sfh_int16_t_uint8_t_heap_t heap;
  sfh_int16_t_uint8_t_node_t node, node2;
  sfh_int16_t_uint8_t_node_t *out_node;
  sfh_int16_t_uint8_t_heap_t *out_heap;
  int is_empty;
  sfh_int16_t_uint8_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int16_t_uint8_t_init(NULL);
  rc = sfh_int16_t_uint8_t_empty(NULL, &is_empty);
  rc = sfh_int16_t_uint8_t_find_min(NULL, &out_node);
  rc = sfh_int16_t_uint8_t_insert(NULL, &node, 1, 0);
  rc = sfh_int16_t_uint8_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int16_t_uint8_t_delete_min(NULL);
  rc = sfh_int16_t_uint8_t_delete(NULL, &node);
  rc = sfh_int16_t_uint8_t_delete(&heap, NULL);
  rc = sfh_int16_t_uint8_t_decrease_key(NULL, &node, 1);
  rc = sfh_int16_t_uint8_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int16_t_uint8_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int16_t_uint8_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int16_t_uint8_t_meld(&heap, &heap, NULL);

  sfh_int16_t_uint8_t_init(&heap);
  rc = sfh_int16_t_uint8_t_empty(&heap, &is_empty);
  rc = sfh_int16_t_uint8_t_find_min(&heap, &out_node);
  rc = sfh_int16_t_uint8_t_delete_min(&heap);

  rc = sfh_int16_t_uint8_t_insert(&heap, &node, 10, 0);
  rc = sfh_int16_t_uint8_t_empty(&heap, &is_empty);
  rc = sfh_int16_t_uint8_t_find_min(&heap, &out_node);

  rc = sfh_int16_t_uint8_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int16_t_uint8_t_delete(&heap, &node);
  rc = sfh_int16_t_uint8_t_delete_min(&heap);

  {
    sfh_int16_t_uint8_t_heap_t h1, h2, h3, *merged;
    sfh_int16_t_uint8_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int16_t_uint8_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int16_t_uint8_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int16_t_uint8_t_init(&h3);
    sfh_int16_t_uint8_t_insert(&h1, &n1, 1, 0);
    sfh_int16_t_uint8_t_insert(&h1, &n2, 2, 0);
    sfh_int16_t_uint8_t_insert(&h1, &n3, 3, 0);
    sfh_int16_t_uint8_t_insert(&h1, &n4, 4, 0);
    sfh_int16_t_uint8_t_insert(&h2, &n5, 5, 0);

    sfh_int16_t_uint8_t_meld(&h1, &h2, &merged);
    sfh_int16_t_uint8_t_delete_min(merged);
    sfh_int16_t_uint8_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int16_t_uint8_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int16_t_uint8_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int16_t_uint8_t_insert(&heap, &fnodes[idx],
                                          (int16_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int16_t_uint8_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc =
              sfh_int16_t_uint8_t_decrease_key(&heap, &fnodes[idx], (int16_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int16_t_uint8_t_node_t *min;
          sfh_int16_t_uint8_t_find_min(&heap, &min);
          rc = sfh_int16_t_uint8_t_delete_min(&heap);
          if (rc == sfh_int16_t_uint8_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int16_t_uint8_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int16_t_uint8_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int16_t_uint16_t(void) {
  sfh_int16_t_uint16_t_heap_t heap;
  sfh_int16_t_uint16_t_node_t node, node2;
  sfh_int16_t_uint16_t_node_t *out_node;
  sfh_int16_t_uint16_t_heap_t *out_heap;
  int is_empty;
  sfh_int16_t_uint16_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int16_t_uint16_t_init(NULL);
  rc = sfh_int16_t_uint16_t_empty(NULL, &is_empty);
  rc = sfh_int16_t_uint16_t_find_min(NULL, &out_node);
  rc = sfh_int16_t_uint16_t_insert(NULL, &node, 1, 0);
  rc = sfh_int16_t_uint16_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int16_t_uint16_t_delete_min(NULL);
  rc = sfh_int16_t_uint16_t_delete(NULL, &node);
  rc = sfh_int16_t_uint16_t_delete(&heap, NULL);
  rc = sfh_int16_t_uint16_t_decrease_key(NULL, &node, 1);
  rc = sfh_int16_t_uint16_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int16_t_uint16_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int16_t_uint16_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int16_t_uint16_t_meld(&heap, &heap, NULL);

  sfh_int16_t_uint16_t_init(&heap);
  rc = sfh_int16_t_uint16_t_empty(&heap, &is_empty);
  rc = sfh_int16_t_uint16_t_find_min(&heap, &out_node);
  rc = sfh_int16_t_uint16_t_delete_min(&heap);

  rc = sfh_int16_t_uint16_t_insert(&heap, &node, 10, 0);
  rc = sfh_int16_t_uint16_t_empty(&heap, &is_empty);
  rc = sfh_int16_t_uint16_t_find_min(&heap, &out_node);

  rc = sfh_int16_t_uint16_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int16_t_uint16_t_delete(&heap, &node);
  rc = sfh_int16_t_uint16_t_delete_min(&heap);

  {
    sfh_int16_t_uint16_t_heap_t h1, h2, h3, *merged;
    sfh_int16_t_uint16_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int16_t_uint16_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int16_t_uint16_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int16_t_uint16_t_init(&h3);
    sfh_int16_t_uint16_t_insert(&h1, &n1, 1, 0);
    sfh_int16_t_uint16_t_insert(&h1, &n2, 2, 0);
    sfh_int16_t_uint16_t_insert(&h1, &n3, 3, 0);
    sfh_int16_t_uint16_t_insert(&h1, &n4, 4, 0);
    sfh_int16_t_uint16_t_insert(&h2, &n5, 5, 0);

    sfh_int16_t_uint16_t_meld(&h1, &h2, &merged);
    sfh_int16_t_uint16_t_delete_min(merged);
    sfh_int16_t_uint16_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int16_t_uint16_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int16_t_uint16_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int16_t_uint16_t_insert(&heap, &fnodes[idx],
                                           (int16_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int16_t_uint16_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int16_t_uint16_t_decrease_key(&heap, &fnodes[idx],
                                                 (int16_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int16_t_uint16_t_node_t *min;
          sfh_int16_t_uint16_t_find_min(&heap, &min);
          rc = sfh_int16_t_uint16_t_delete_min(&heap);
          if (rc == sfh_int16_t_uint16_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int16_t_uint16_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int16_t_uint16_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int16_t_uint32_t(void) {
  sfh_int16_t_uint32_t_heap_t heap;
  sfh_int16_t_uint32_t_node_t node, node2;
  sfh_int16_t_uint32_t_node_t *out_node;
  sfh_int16_t_uint32_t_heap_t *out_heap;
  int is_empty;
  sfh_int16_t_uint32_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int16_t_uint32_t_init(NULL);
  rc = sfh_int16_t_uint32_t_empty(NULL, &is_empty);
  rc = sfh_int16_t_uint32_t_find_min(NULL, &out_node);
  rc = sfh_int16_t_uint32_t_insert(NULL, &node, 1, 0);
  rc = sfh_int16_t_uint32_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int16_t_uint32_t_delete_min(NULL);
  rc = sfh_int16_t_uint32_t_delete(NULL, &node);
  rc = sfh_int16_t_uint32_t_delete(&heap, NULL);
  rc = sfh_int16_t_uint32_t_decrease_key(NULL, &node, 1);
  rc = sfh_int16_t_uint32_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int16_t_uint32_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int16_t_uint32_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int16_t_uint32_t_meld(&heap, &heap, NULL);

  sfh_int16_t_uint32_t_init(&heap);
  rc = sfh_int16_t_uint32_t_empty(&heap, &is_empty);
  rc = sfh_int16_t_uint32_t_find_min(&heap, &out_node);
  rc = sfh_int16_t_uint32_t_delete_min(&heap);

  rc = sfh_int16_t_uint32_t_insert(&heap, &node, 10, 0);
  rc = sfh_int16_t_uint32_t_empty(&heap, &is_empty);
  rc = sfh_int16_t_uint32_t_find_min(&heap, &out_node);

  rc = sfh_int16_t_uint32_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int16_t_uint32_t_delete(&heap, &node);
  rc = sfh_int16_t_uint32_t_delete_min(&heap);

  {
    sfh_int16_t_uint32_t_heap_t h1, h2, h3, *merged;
    sfh_int16_t_uint32_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int16_t_uint32_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int16_t_uint32_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int16_t_uint32_t_init(&h3);
    sfh_int16_t_uint32_t_insert(&h1, &n1, 1, 0);
    sfh_int16_t_uint32_t_insert(&h1, &n2, 2, 0);
    sfh_int16_t_uint32_t_insert(&h1, &n3, 3, 0);
    sfh_int16_t_uint32_t_insert(&h1, &n4, 4, 0);
    sfh_int16_t_uint32_t_insert(&h2, &n5, 5, 0);

    sfh_int16_t_uint32_t_meld(&h1, &h2, &merged);
    sfh_int16_t_uint32_t_delete_min(merged);
    sfh_int16_t_uint32_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int16_t_uint32_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int16_t_uint32_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int16_t_uint32_t_insert(&heap, &fnodes[idx],
                                           (int16_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int16_t_uint32_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int16_t_uint32_t_decrease_key(&heap, &fnodes[idx],
                                                 (int16_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int16_t_uint32_t_node_t *min;
          sfh_int16_t_uint32_t_find_min(&heap, &min);
          rc = sfh_int16_t_uint32_t_delete_min(&heap);
          if (rc == sfh_int16_t_uint32_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int16_t_uint32_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int16_t_uint32_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int16_t_uint64_t(void) {
  sfh_int16_t_uint64_t_heap_t heap;
  sfh_int16_t_uint64_t_node_t node, node2;
  sfh_int16_t_uint64_t_node_t *out_node;
  sfh_int16_t_uint64_t_heap_t *out_heap;
  int is_empty;
  sfh_int16_t_uint64_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int16_t_uint64_t_init(NULL);
  rc = sfh_int16_t_uint64_t_empty(NULL, &is_empty);
  rc = sfh_int16_t_uint64_t_find_min(NULL, &out_node);
  rc = sfh_int16_t_uint64_t_insert(NULL, &node, 1, 0);
  rc = sfh_int16_t_uint64_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int16_t_uint64_t_delete_min(NULL);
  rc = sfh_int16_t_uint64_t_delete(NULL, &node);
  rc = sfh_int16_t_uint64_t_delete(&heap, NULL);
  rc = sfh_int16_t_uint64_t_decrease_key(NULL, &node, 1);
  rc = sfh_int16_t_uint64_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int16_t_uint64_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int16_t_uint64_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int16_t_uint64_t_meld(&heap, &heap, NULL);

  sfh_int16_t_uint64_t_init(&heap);
  rc = sfh_int16_t_uint64_t_empty(&heap, &is_empty);
  rc = sfh_int16_t_uint64_t_find_min(&heap, &out_node);
  rc = sfh_int16_t_uint64_t_delete_min(&heap);

  rc = sfh_int16_t_uint64_t_insert(&heap, &node, 10, 0);
  rc = sfh_int16_t_uint64_t_empty(&heap, &is_empty);
  rc = sfh_int16_t_uint64_t_find_min(&heap, &out_node);

  rc = sfh_int16_t_uint64_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int16_t_uint64_t_delete(&heap, &node);
  rc = sfh_int16_t_uint64_t_delete_min(&heap);

  {
    sfh_int16_t_uint64_t_heap_t h1, h2, h3, *merged;
    sfh_int16_t_uint64_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int16_t_uint64_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int16_t_uint64_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int16_t_uint64_t_init(&h3);
    sfh_int16_t_uint64_t_insert(&h1, &n1, 1, 0);
    sfh_int16_t_uint64_t_insert(&h1, &n2, 2, 0);
    sfh_int16_t_uint64_t_insert(&h1, &n3, 3, 0);
    sfh_int16_t_uint64_t_insert(&h1, &n4, 4, 0);
    sfh_int16_t_uint64_t_insert(&h2, &n5, 5, 0);

    sfh_int16_t_uint64_t_meld(&h1, &h2, &merged);
    sfh_int16_t_uint64_t_delete_min(merged);
    sfh_int16_t_uint64_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int16_t_uint64_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int16_t_uint64_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int16_t_uint64_t_insert(&heap, &fnodes[idx],
                                           (int16_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int16_t_uint64_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int16_t_uint64_t_decrease_key(&heap, &fnodes[idx],
                                                 (int16_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int16_t_uint64_t_node_t *min;
          sfh_int16_t_uint64_t_find_min(&heap, &min);
          rc = sfh_int16_t_uint64_t_delete_min(&heap);
          if (rc == sfh_int16_t_uint64_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int16_t_uint64_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int16_t_uint64_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int16_t_float(void) {
  sfh_int16_t_float_heap_t heap;
  sfh_int16_t_float_node_t node, node2;
  sfh_int16_t_float_node_t *out_node;
  sfh_int16_t_float_heap_t *out_heap;
  int is_empty;
  sfh_int16_t_float_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int16_t_float_init(NULL);
  rc = sfh_int16_t_float_empty(NULL, &is_empty);
  rc = sfh_int16_t_float_find_min(NULL, &out_node);
  rc = sfh_int16_t_float_insert(NULL, &node, 1, 0);
  rc = sfh_int16_t_float_insert(&heap, NULL, 1, 0);
  rc = sfh_int16_t_float_delete_min(NULL);
  rc = sfh_int16_t_float_delete(NULL, &node);
  rc = sfh_int16_t_float_delete(&heap, NULL);
  rc = sfh_int16_t_float_decrease_key(NULL, &node, 1);
  rc = sfh_int16_t_float_decrease_key(&heap, NULL, 1);
  rc = sfh_int16_t_float_meld(NULL, &heap, &out_heap);
  rc = sfh_int16_t_float_meld(&heap, NULL, &out_heap);
  rc = sfh_int16_t_float_meld(&heap, &heap, NULL);

  sfh_int16_t_float_init(&heap);
  rc = sfh_int16_t_float_empty(&heap, &is_empty);
  rc = sfh_int16_t_float_find_min(&heap, &out_node);
  rc = sfh_int16_t_float_delete_min(&heap);

  rc = sfh_int16_t_float_insert(&heap, &node, 10, 0);
  rc = sfh_int16_t_float_empty(&heap, &is_empty);
  rc = sfh_int16_t_float_find_min(&heap, &out_node);

  rc = sfh_int16_t_float_insert(&heap, &node2, 10, 0);
  rc = sfh_int16_t_float_delete(&heap, &node);
  rc = sfh_int16_t_float_delete_min(&heap);

  {
    sfh_int16_t_float_heap_t h1, h2, h3, *merged;
    sfh_int16_t_float_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int16_t_float_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int16_t_float_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int16_t_float_init(&h3);
    sfh_int16_t_float_insert(&h1, &n1, 1, 0);
    sfh_int16_t_float_insert(&h1, &n2, 2, 0);
    sfh_int16_t_float_insert(&h1, &n3, 3, 0);
    sfh_int16_t_float_insert(&h1, &n4, 4, 0);
    sfh_int16_t_float_insert(&h2, &n5, 5, 0);

    sfh_int16_t_float_meld(&h1, &h2, &merged);
    sfh_int16_t_float_delete_min(merged);
    sfh_int16_t_float_meld(&h3, merged, &merged);
  }

  {
    static sfh_int16_t_float_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int16_t_float_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int16_t_float_insert(&heap, &fnodes[idx],
                                        (int16_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int16_t_float_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int16_t_float_decrease_key(&heap, &fnodes[idx], (int16_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int16_t_float_node_t *min;
          sfh_int16_t_float_find_min(&heap, &min);
          rc = sfh_int16_t_float_delete_min(&heap);
          if (rc == sfh_int16_t_float_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int16_t_float_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int16_t_float_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int16_t_double(void) {
  sfh_int16_t_double_heap_t heap;
  sfh_int16_t_double_node_t node, node2;
  sfh_int16_t_double_node_t *out_node;
  sfh_int16_t_double_heap_t *out_heap;
  int is_empty;
  sfh_int16_t_double_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int16_t_double_init(NULL);
  rc = sfh_int16_t_double_empty(NULL, &is_empty);
  rc = sfh_int16_t_double_find_min(NULL, &out_node);
  rc = sfh_int16_t_double_insert(NULL, &node, 1, 0);
  rc = sfh_int16_t_double_insert(&heap, NULL, 1, 0);
  rc = sfh_int16_t_double_delete_min(NULL);
  rc = sfh_int16_t_double_delete(NULL, &node);
  rc = sfh_int16_t_double_delete(&heap, NULL);
  rc = sfh_int16_t_double_decrease_key(NULL, &node, 1);
  rc = sfh_int16_t_double_decrease_key(&heap, NULL, 1);
  rc = sfh_int16_t_double_meld(NULL, &heap, &out_heap);
  rc = sfh_int16_t_double_meld(&heap, NULL, &out_heap);
  rc = sfh_int16_t_double_meld(&heap, &heap, NULL);

  sfh_int16_t_double_init(&heap);
  rc = sfh_int16_t_double_empty(&heap, &is_empty);
  rc = sfh_int16_t_double_find_min(&heap, &out_node);
  rc = sfh_int16_t_double_delete_min(&heap);

  rc = sfh_int16_t_double_insert(&heap, &node, 10, 0);
  rc = sfh_int16_t_double_empty(&heap, &is_empty);
  rc = sfh_int16_t_double_find_min(&heap, &out_node);

  rc = sfh_int16_t_double_insert(&heap, &node2, 10, 0);
  rc = sfh_int16_t_double_delete(&heap, &node);
  rc = sfh_int16_t_double_delete_min(&heap);

  {
    sfh_int16_t_double_heap_t h1, h2, h3, *merged;
    sfh_int16_t_double_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int16_t_double_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int16_t_double_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int16_t_double_init(&h3);
    sfh_int16_t_double_insert(&h1, &n1, 1, 0);
    sfh_int16_t_double_insert(&h1, &n2, 2, 0);
    sfh_int16_t_double_insert(&h1, &n3, 3, 0);
    sfh_int16_t_double_insert(&h1, &n4, 4, 0);
    sfh_int16_t_double_insert(&h2, &n5, 5, 0);

    sfh_int16_t_double_meld(&h1, &h2, &merged);
    sfh_int16_t_double_delete_min(merged);
    sfh_int16_t_double_meld(&h3, merged, &merged);
  }

  {
    static sfh_int16_t_double_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int16_t_double_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int16_t_double_insert(&heap, &fnodes[idx],
                                         (int16_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int16_t_double_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int16_t_double_decrease_key(&heap, &fnodes[idx], (int16_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int16_t_double_node_t *min;
          sfh_int16_t_double_find_min(&heap, &min);
          rc = sfh_int16_t_double_delete_min(&heap);
          if (rc == sfh_int16_t_double_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int16_t_double_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int16_t_double_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int16_t_charptr(void) {
  sfh_int16_t_charptr_heap_t heap;
  sfh_int16_t_charptr_node_t node, node2;
  sfh_int16_t_charptr_node_t *out_node;
  sfh_int16_t_charptr_heap_t *out_heap;
  int is_empty;
  sfh_int16_t_charptr_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int16_t_charptr_init(NULL);
  rc = sfh_int16_t_charptr_empty(NULL, &is_empty);
  rc = sfh_int16_t_charptr_find_min(NULL, &out_node);
  rc = sfh_int16_t_charptr_insert(NULL, &node, 1, 0);
  rc = sfh_int16_t_charptr_insert(&heap, NULL, 1, 0);
  rc = sfh_int16_t_charptr_delete_min(NULL);
  rc = sfh_int16_t_charptr_delete(NULL, &node);
  rc = sfh_int16_t_charptr_delete(&heap, NULL);
  rc = sfh_int16_t_charptr_decrease_key(NULL, &node, 1);
  rc = sfh_int16_t_charptr_decrease_key(&heap, NULL, 1);
  rc = sfh_int16_t_charptr_meld(NULL, &heap, &out_heap);
  rc = sfh_int16_t_charptr_meld(&heap, NULL, &out_heap);
  rc = sfh_int16_t_charptr_meld(&heap, &heap, NULL);

  sfh_int16_t_charptr_init(&heap);
  rc = sfh_int16_t_charptr_empty(&heap, &is_empty);
  rc = sfh_int16_t_charptr_find_min(&heap, &out_node);
  rc = sfh_int16_t_charptr_delete_min(&heap);

  rc = sfh_int16_t_charptr_insert(&heap, &node, 10, 0);
  rc = sfh_int16_t_charptr_empty(&heap, &is_empty);
  rc = sfh_int16_t_charptr_find_min(&heap, &out_node);

  rc = sfh_int16_t_charptr_insert(&heap, &node2, 10, 0);
  rc = sfh_int16_t_charptr_delete(&heap, &node);
  rc = sfh_int16_t_charptr_delete_min(&heap);

  {
    sfh_int16_t_charptr_heap_t h1, h2, h3, *merged;
    sfh_int16_t_charptr_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int16_t_charptr_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int16_t_charptr_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int16_t_charptr_init(&h3);
    sfh_int16_t_charptr_insert(&h1, &n1, 1, 0);
    sfh_int16_t_charptr_insert(&h1, &n2, 2, 0);
    sfh_int16_t_charptr_insert(&h1, &n3, 3, 0);
    sfh_int16_t_charptr_insert(&h1, &n4, 4, 0);
    sfh_int16_t_charptr_insert(&h2, &n5, 5, 0);

    sfh_int16_t_charptr_meld(&h1, &h2, &merged);
    sfh_int16_t_charptr_delete_min(merged);
    sfh_int16_t_charptr_meld(&h3, merged, &merged);
  }

  {
    static sfh_int16_t_charptr_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int16_t_charptr_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int16_t_charptr_insert(&heap, &fnodes[idx],
                                          (int16_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int16_t_charptr_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc =
              sfh_int16_t_charptr_decrease_key(&heap, &fnodes[idx], (int16_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int16_t_charptr_node_t *min;
          sfh_int16_t_charptr_find_min(&heap, &min);
          rc = sfh_int16_t_charptr_delete_min(&heap);
          if (rc == sfh_int16_t_charptr_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int16_t_charptr_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int16_t_charptr_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int16_t_voidptr(void) {
  sfh_int16_t_voidptr_heap_t heap;
  sfh_int16_t_voidptr_node_t node, node2;
  sfh_int16_t_voidptr_node_t *out_node;
  sfh_int16_t_voidptr_heap_t *out_heap;
  int is_empty;
  sfh_int16_t_voidptr_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int16_t_voidptr_init(NULL);
  rc = sfh_int16_t_voidptr_empty(NULL, &is_empty);
  rc = sfh_int16_t_voidptr_find_min(NULL, &out_node);
  rc = sfh_int16_t_voidptr_insert(NULL, &node, 1, 0);
  rc = sfh_int16_t_voidptr_insert(&heap, NULL, 1, 0);
  rc = sfh_int16_t_voidptr_delete_min(NULL);
  rc = sfh_int16_t_voidptr_delete(NULL, &node);
  rc = sfh_int16_t_voidptr_delete(&heap, NULL);
  rc = sfh_int16_t_voidptr_decrease_key(NULL, &node, 1);
  rc = sfh_int16_t_voidptr_decrease_key(&heap, NULL, 1);
  rc = sfh_int16_t_voidptr_meld(NULL, &heap, &out_heap);
  rc = sfh_int16_t_voidptr_meld(&heap, NULL, &out_heap);
  rc = sfh_int16_t_voidptr_meld(&heap, &heap, NULL);

  sfh_int16_t_voidptr_init(&heap);
  rc = sfh_int16_t_voidptr_empty(&heap, &is_empty);
  rc = sfh_int16_t_voidptr_find_min(&heap, &out_node);
  rc = sfh_int16_t_voidptr_delete_min(&heap);

  rc = sfh_int16_t_voidptr_insert(&heap, &node, 10, 0);
  rc = sfh_int16_t_voidptr_empty(&heap, &is_empty);
  rc = sfh_int16_t_voidptr_find_min(&heap, &out_node);

  rc = sfh_int16_t_voidptr_insert(&heap, &node2, 10, 0);
  rc = sfh_int16_t_voidptr_delete(&heap, &node);
  rc = sfh_int16_t_voidptr_delete_min(&heap);

  {
    sfh_int16_t_voidptr_heap_t h1, h2, h3, *merged;
    sfh_int16_t_voidptr_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int16_t_voidptr_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int16_t_voidptr_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int16_t_voidptr_init(&h3);
    sfh_int16_t_voidptr_insert(&h1, &n1, 1, 0);
    sfh_int16_t_voidptr_insert(&h1, &n2, 2, 0);
    sfh_int16_t_voidptr_insert(&h1, &n3, 3, 0);
    sfh_int16_t_voidptr_insert(&h1, &n4, 4, 0);
    sfh_int16_t_voidptr_insert(&h2, &n5, 5, 0);

    sfh_int16_t_voidptr_meld(&h1, &h2, &merged);
    sfh_int16_t_voidptr_delete_min(merged);
    sfh_int16_t_voidptr_meld(&h3, merged, &merged);
  }

  {
    static sfh_int16_t_voidptr_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int16_t_voidptr_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int16_t_voidptr_insert(&heap, &fnodes[idx],
                                          (int16_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int16_t_voidptr_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc =
              sfh_int16_t_voidptr_decrease_key(&heap, &fnodes[idx], (int16_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int16_t_voidptr_node_t *min;
          sfh_int16_t_voidptr_find_min(&heap, &min);
          rc = sfh_int16_t_voidptr_delete_min(&heap);
          if (rc == sfh_int16_t_voidptr_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int16_t_voidptr_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int16_t_voidptr_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int32_t_int8_t(void) {
  sfh_int32_t_int8_t_heap_t heap;
  sfh_int32_t_int8_t_node_t node, node2;
  sfh_int32_t_int8_t_node_t *out_node;
  sfh_int32_t_int8_t_heap_t *out_heap;
  int is_empty;
  sfh_int32_t_int8_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int32_t_int8_t_init(NULL);
  rc = sfh_int32_t_int8_t_empty(NULL, &is_empty);
  rc = sfh_int32_t_int8_t_find_min(NULL, &out_node);
  rc = sfh_int32_t_int8_t_insert(NULL, &node, 1, 0);
  rc = sfh_int32_t_int8_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int32_t_int8_t_delete_min(NULL);
  rc = sfh_int32_t_int8_t_delete(NULL, &node);
  rc = sfh_int32_t_int8_t_delete(&heap, NULL);
  rc = sfh_int32_t_int8_t_decrease_key(NULL, &node, 1);
  rc = sfh_int32_t_int8_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int32_t_int8_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int32_t_int8_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int32_t_int8_t_meld(&heap, &heap, NULL);

  sfh_int32_t_int8_t_init(&heap);
  rc = sfh_int32_t_int8_t_empty(&heap, &is_empty);
  rc = sfh_int32_t_int8_t_find_min(&heap, &out_node);
  rc = sfh_int32_t_int8_t_delete_min(&heap);

  rc = sfh_int32_t_int8_t_insert(&heap, &node, 10, 0);
  rc = sfh_int32_t_int8_t_empty(&heap, &is_empty);
  rc = sfh_int32_t_int8_t_find_min(&heap, &out_node);

  rc = sfh_int32_t_int8_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int32_t_int8_t_delete(&heap, &node);
  rc = sfh_int32_t_int8_t_delete_min(&heap);

  {
    sfh_int32_t_int8_t_heap_t h1, h2, h3, *merged;
    sfh_int32_t_int8_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int32_t_int8_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int32_t_int8_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int32_t_int8_t_init(&h3);
    sfh_int32_t_int8_t_insert(&h1, &n1, 1, 0);
    sfh_int32_t_int8_t_insert(&h1, &n2, 2, 0);
    sfh_int32_t_int8_t_insert(&h1, &n3, 3, 0);
    sfh_int32_t_int8_t_insert(&h1, &n4, 4, 0);
    sfh_int32_t_int8_t_insert(&h2, &n5, 5, 0);

    sfh_int32_t_int8_t_meld(&h1, &h2, &merged);
    sfh_int32_t_int8_t_delete_min(merged);
    sfh_int32_t_int8_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int32_t_int8_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int32_t_int8_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int32_t_int8_t_insert(&heap, &fnodes[idx],
                                         (int32_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int32_t_int8_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int32_t_int8_t_decrease_key(&heap, &fnodes[idx], (int32_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int32_t_int8_t_node_t *min;
          sfh_int32_t_int8_t_find_min(&heap, &min);
          rc = sfh_int32_t_int8_t_delete_min(&heap);
          if (rc == sfh_int32_t_int8_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int32_t_int8_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int32_t_int8_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int32_t_int16_t(void) {
  sfh_int32_t_int16_t_heap_t heap;
  sfh_int32_t_int16_t_node_t node, node2;
  sfh_int32_t_int16_t_node_t *out_node;
  sfh_int32_t_int16_t_heap_t *out_heap;
  int is_empty;
  sfh_int32_t_int16_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int32_t_int16_t_init(NULL);
  rc = sfh_int32_t_int16_t_empty(NULL, &is_empty);
  rc = sfh_int32_t_int16_t_find_min(NULL, &out_node);
  rc = sfh_int32_t_int16_t_insert(NULL, &node, 1, 0);
  rc = sfh_int32_t_int16_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int32_t_int16_t_delete_min(NULL);
  rc = sfh_int32_t_int16_t_delete(NULL, &node);
  rc = sfh_int32_t_int16_t_delete(&heap, NULL);
  rc = sfh_int32_t_int16_t_decrease_key(NULL, &node, 1);
  rc = sfh_int32_t_int16_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int32_t_int16_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int32_t_int16_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int32_t_int16_t_meld(&heap, &heap, NULL);

  sfh_int32_t_int16_t_init(&heap);
  rc = sfh_int32_t_int16_t_empty(&heap, &is_empty);
  rc = sfh_int32_t_int16_t_find_min(&heap, &out_node);
  rc = sfh_int32_t_int16_t_delete_min(&heap);

  rc = sfh_int32_t_int16_t_insert(&heap, &node, 10, 0);
  rc = sfh_int32_t_int16_t_empty(&heap, &is_empty);
  rc = sfh_int32_t_int16_t_find_min(&heap, &out_node);

  rc = sfh_int32_t_int16_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int32_t_int16_t_delete(&heap, &node);
  rc = sfh_int32_t_int16_t_delete_min(&heap);

  {
    sfh_int32_t_int16_t_heap_t h1, h2, h3, *merged;
    sfh_int32_t_int16_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int32_t_int16_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int32_t_int16_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int32_t_int16_t_init(&h3);
    sfh_int32_t_int16_t_insert(&h1, &n1, 1, 0);
    sfh_int32_t_int16_t_insert(&h1, &n2, 2, 0);
    sfh_int32_t_int16_t_insert(&h1, &n3, 3, 0);
    sfh_int32_t_int16_t_insert(&h1, &n4, 4, 0);
    sfh_int32_t_int16_t_insert(&h2, &n5, 5, 0);

    sfh_int32_t_int16_t_meld(&h1, &h2, &merged);
    sfh_int32_t_int16_t_delete_min(merged);
    sfh_int32_t_int16_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int32_t_int16_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int32_t_int16_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int32_t_int16_t_insert(&heap, &fnodes[idx],
                                          (int32_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int32_t_int16_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc =
              sfh_int32_t_int16_t_decrease_key(&heap, &fnodes[idx], (int32_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int32_t_int16_t_node_t *min;
          sfh_int32_t_int16_t_find_min(&heap, &min);
          rc = sfh_int32_t_int16_t_delete_min(&heap);
          if (rc == sfh_int32_t_int16_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int32_t_int16_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int32_t_int16_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int32_t_int32_t(void) {
  sfh_int32_t_int32_t_heap_t heap;
  sfh_int32_t_int32_t_node_t node, node2;
  sfh_int32_t_int32_t_node_t *out_node;
  sfh_int32_t_int32_t_heap_t *out_heap;
  int is_empty;
  sfh_int32_t_int32_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int32_t_int32_t_init(NULL);
  rc = sfh_int32_t_int32_t_empty(NULL, &is_empty);
  rc = sfh_int32_t_int32_t_find_min(NULL, &out_node);
  rc = sfh_int32_t_int32_t_insert(NULL, &node, 1, 0);
  rc = sfh_int32_t_int32_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int32_t_int32_t_delete_min(NULL);
  rc = sfh_int32_t_int32_t_delete(NULL, &node);
  rc = sfh_int32_t_int32_t_delete(&heap, NULL);
  rc = sfh_int32_t_int32_t_decrease_key(NULL, &node, 1);
  rc = sfh_int32_t_int32_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int32_t_int32_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int32_t_int32_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int32_t_int32_t_meld(&heap, &heap, NULL);

  sfh_int32_t_int32_t_init(&heap);
  rc = sfh_int32_t_int32_t_empty(&heap, &is_empty);
  rc = sfh_int32_t_int32_t_find_min(&heap, &out_node);
  rc = sfh_int32_t_int32_t_delete_min(&heap);

  rc = sfh_int32_t_int32_t_insert(&heap, &node, 10, 0);
  rc = sfh_int32_t_int32_t_empty(&heap, &is_empty);
  rc = sfh_int32_t_int32_t_find_min(&heap, &out_node);

  rc = sfh_int32_t_int32_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int32_t_int32_t_delete(&heap, &node);
  rc = sfh_int32_t_int32_t_delete_min(&heap);

  {
    sfh_int32_t_int32_t_heap_t h1, h2, h3, *merged;
    sfh_int32_t_int32_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int32_t_int32_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int32_t_int32_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int32_t_int32_t_init(&h3);
    sfh_int32_t_int32_t_insert(&h1, &n1, 1, 0);
    sfh_int32_t_int32_t_insert(&h1, &n2, 2, 0);
    sfh_int32_t_int32_t_insert(&h1, &n3, 3, 0);
    sfh_int32_t_int32_t_insert(&h1, &n4, 4, 0);
    sfh_int32_t_int32_t_insert(&h2, &n5, 5, 0);

    sfh_int32_t_int32_t_meld(&h1, &h2, &merged);
    sfh_int32_t_int32_t_delete_min(merged);
    sfh_int32_t_int32_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int32_t_int32_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int32_t_int32_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int32_t_int32_t_insert(&heap, &fnodes[idx],
                                          (int32_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int32_t_int32_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc =
              sfh_int32_t_int32_t_decrease_key(&heap, &fnodes[idx], (int32_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int32_t_int32_t_node_t *min;
          sfh_int32_t_int32_t_find_min(&heap, &min);
          rc = sfh_int32_t_int32_t_delete_min(&heap);
          if (rc == sfh_int32_t_int32_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int32_t_int32_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int32_t_int32_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int32_t_int64_t(void) {
  sfh_int32_t_int64_t_heap_t heap;
  sfh_int32_t_int64_t_node_t node, node2;
  sfh_int32_t_int64_t_node_t *out_node;
  sfh_int32_t_int64_t_heap_t *out_heap;
  int is_empty;
  sfh_int32_t_int64_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int32_t_int64_t_init(NULL);
  rc = sfh_int32_t_int64_t_empty(NULL, &is_empty);
  rc = sfh_int32_t_int64_t_find_min(NULL, &out_node);
  rc = sfh_int32_t_int64_t_insert(NULL, &node, 1, 0);
  rc = sfh_int32_t_int64_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int32_t_int64_t_delete_min(NULL);
  rc = sfh_int32_t_int64_t_delete(NULL, &node);
  rc = sfh_int32_t_int64_t_delete(&heap, NULL);
  rc = sfh_int32_t_int64_t_decrease_key(NULL, &node, 1);
  rc = sfh_int32_t_int64_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int32_t_int64_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int32_t_int64_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int32_t_int64_t_meld(&heap, &heap, NULL);

  sfh_int32_t_int64_t_init(&heap);
  rc = sfh_int32_t_int64_t_empty(&heap, &is_empty);
  rc = sfh_int32_t_int64_t_find_min(&heap, &out_node);
  rc = sfh_int32_t_int64_t_delete_min(&heap);

  rc = sfh_int32_t_int64_t_insert(&heap, &node, 10, 0);
  rc = sfh_int32_t_int64_t_empty(&heap, &is_empty);
  rc = sfh_int32_t_int64_t_find_min(&heap, &out_node);

  rc = sfh_int32_t_int64_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int32_t_int64_t_delete(&heap, &node);
  rc = sfh_int32_t_int64_t_delete_min(&heap);

  {
    sfh_int32_t_int64_t_heap_t h1, h2, h3, *merged;
    sfh_int32_t_int64_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int32_t_int64_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int32_t_int64_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int32_t_int64_t_init(&h3);
    sfh_int32_t_int64_t_insert(&h1, &n1, 1, 0);
    sfh_int32_t_int64_t_insert(&h1, &n2, 2, 0);
    sfh_int32_t_int64_t_insert(&h1, &n3, 3, 0);
    sfh_int32_t_int64_t_insert(&h1, &n4, 4, 0);
    sfh_int32_t_int64_t_insert(&h2, &n5, 5, 0);

    sfh_int32_t_int64_t_meld(&h1, &h2, &merged);
    sfh_int32_t_int64_t_delete_min(merged);
    sfh_int32_t_int64_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int32_t_int64_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int32_t_int64_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int32_t_int64_t_insert(&heap, &fnodes[idx],
                                          (int32_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int32_t_int64_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc =
              sfh_int32_t_int64_t_decrease_key(&heap, &fnodes[idx], (int32_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int32_t_int64_t_node_t *min;
          sfh_int32_t_int64_t_find_min(&heap, &min);
          rc = sfh_int32_t_int64_t_delete_min(&heap);
          if (rc == sfh_int32_t_int64_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int32_t_int64_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int32_t_int64_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int32_t_uint8_t(void) {
  sfh_int32_t_uint8_t_heap_t heap;
  sfh_int32_t_uint8_t_node_t node, node2;
  sfh_int32_t_uint8_t_node_t *out_node;
  sfh_int32_t_uint8_t_heap_t *out_heap;
  int is_empty;
  sfh_int32_t_uint8_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int32_t_uint8_t_init(NULL);
  rc = sfh_int32_t_uint8_t_empty(NULL, &is_empty);
  rc = sfh_int32_t_uint8_t_find_min(NULL, &out_node);
  rc = sfh_int32_t_uint8_t_insert(NULL, &node, 1, 0);
  rc = sfh_int32_t_uint8_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int32_t_uint8_t_delete_min(NULL);
  rc = sfh_int32_t_uint8_t_delete(NULL, &node);
  rc = sfh_int32_t_uint8_t_delete(&heap, NULL);
  rc = sfh_int32_t_uint8_t_decrease_key(NULL, &node, 1);
  rc = sfh_int32_t_uint8_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int32_t_uint8_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int32_t_uint8_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int32_t_uint8_t_meld(&heap, &heap, NULL);

  sfh_int32_t_uint8_t_init(&heap);
  rc = sfh_int32_t_uint8_t_empty(&heap, &is_empty);
  rc = sfh_int32_t_uint8_t_find_min(&heap, &out_node);
  rc = sfh_int32_t_uint8_t_delete_min(&heap);

  rc = sfh_int32_t_uint8_t_insert(&heap, &node, 10, 0);
  rc = sfh_int32_t_uint8_t_empty(&heap, &is_empty);
  rc = sfh_int32_t_uint8_t_find_min(&heap, &out_node);

  rc = sfh_int32_t_uint8_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int32_t_uint8_t_delete(&heap, &node);
  rc = sfh_int32_t_uint8_t_delete_min(&heap);

  {
    sfh_int32_t_uint8_t_heap_t h1, h2, h3, *merged;
    sfh_int32_t_uint8_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int32_t_uint8_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int32_t_uint8_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int32_t_uint8_t_init(&h3);
    sfh_int32_t_uint8_t_insert(&h1, &n1, 1, 0);
    sfh_int32_t_uint8_t_insert(&h1, &n2, 2, 0);
    sfh_int32_t_uint8_t_insert(&h1, &n3, 3, 0);
    sfh_int32_t_uint8_t_insert(&h1, &n4, 4, 0);
    sfh_int32_t_uint8_t_insert(&h2, &n5, 5, 0);

    sfh_int32_t_uint8_t_meld(&h1, &h2, &merged);
    sfh_int32_t_uint8_t_delete_min(merged);
    sfh_int32_t_uint8_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int32_t_uint8_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int32_t_uint8_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int32_t_uint8_t_insert(&heap, &fnodes[idx],
                                          (int32_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int32_t_uint8_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc =
              sfh_int32_t_uint8_t_decrease_key(&heap, &fnodes[idx], (int32_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int32_t_uint8_t_node_t *min;
          sfh_int32_t_uint8_t_find_min(&heap, &min);
          rc = sfh_int32_t_uint8_t_delete_min(&heap);
          if (rc == sfh_int32_t_uint8_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int32_t_uint8_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int32_t_uint8_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int32_t_uint16_t(void) {
  sfh_int32_t_uint16_t_heap_t heap;
  sfh_int32_t_uint16_t_node_t node, node2;
  sfh_int32_t_uint16_t_node_t *out_node;
  sfh_int32_t_uint16_t_heap_t *out_heap;
  int is_empty;
  sfh_int32_t_uint16_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int32_t_uint16_t_init(NULL);
  rc = sfh_int32_t_uint16_t_empty(NULL, &is_empty);
  rc = sfh_int32_t_uint16_t_find_min(NULL, &out_node);
  rc = sfh_int32_t_uint16_t_insert(NULL, &node, 1, 0);
  rc = sfh_int32_t_uint16_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int32_t_uint16_t_delete_min(NULL);
  rc = sfh_int32_t_uint16_t_delete(NULL, &node);
  rc = sfh_int32_t_uint16_t_delete(&heap, NULL);
  rc = sfh_int32_t_uint16_t_decrease_key(NULL, &node, 1);
  rc = sfh_int32_t_uint16_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int32_t_uint16_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int32_t_uint16_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int32_t_uint16_t_meld(&heap, &heap, NULL);

  sfh_int32_t_uint16_t_init(&heap);
  rc = sfh_int32_t_uint16_t_empty(&heap, &is_empty);
  rc = sfh_int32_t_uint16_t_find_min(&heap, &out_node);
  rc = sfh_int32_t_uint16_t_delete_min(&heap);

  rc = sfh_int32_t_uint16_t_insert(&heap, &node, 10, 0);
  rc = sfh_int32_t_uint16_t_empty(&heap, &is_empty);
  rc = sfh_int32_t_uint16_t_find_min(&heap, &out_node);

  rc = sfh_int32_t_uint16_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int32_t_uint16_t_delete(&heap, &node);
  rc = sfh_int32_t_uint16_t_delete_min(&heap);

  {
    sfh_int32_t_uint16_t_heap_t h1, h2, h3, *merged;
    sfh_int32_t_uint16_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int32_t_uint16_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int32_t_uint16_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int32_t_uint16_t_init(&h3);
    sfh_int32_t_uint16_t_insert(&h1, &n1, 1, 0);
    sfh_int32_t_uint16_t_insert(&h1, &n2, 2, 0);
    sfh_int32_t_uint16_t_insert(&h1, &n3, 3, 0);
    sfh_int32_t_uint16_t_insert(&h1, &n4, 4, 0);
    sfh_int32_t_uint16_t_insert(&h2, &n5, 5, 0);

    sfh_int32_t_uint16_t_meld(&h1, &h2, &merged);
    sfh_int32_t_uint16_t_delete_min(merged);
    sfh_int32_t_uint16_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int32_t_uint16_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int32_t_uint16_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int32_t_uint16_t_insert(&heap, &fnodes[idx],
                                           (int32_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int32_t_uint16_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int32_t_uint16_t_decrease_key(&heap, &fnodes[idx],
                                                 (int32_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int32_t_uint16_t_node_t *min;
          sfh_int32_t_uint16_t_find_min(&heap, &min);
          rc = sfh_int32_t_uint16_t_delete_min(&heap);
          if (rc == sfh_int32_t_uint16_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int32_t_uint16_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int32_t_uint16_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int32_t_uint32_t(void) {
  sfh_int32_t_uint32_t_heap_t heap;
  sfh_int32_t_uint32_t_node_t node, node2;
  sfh_int32_t_uint32_t_node_t *out_node;
  sfh_int32_t_uint32_t_heap_t *out_heap;
  int is_empty;
  sfh_int32_t_uint32_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int32_t_uint32_t_init(NULL);
  rc = sfh_int32_t_uint32_t_empty(NULL, &is_empty);
  rc = sfh_int32_t_uint32_t_find_min(NULL, &out_node);
  rc = sfh_int32_t_uint32_t_insert(NULL, &node, 1, 0);
  rc = sfh_int32_t_uint32_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int32_t_uint32_t_delete_min(NULL);
  rc = sfh_int32_t_uint32_t_delete(NULL, &node);
  rc = sfh_int32_t_uint32_t_delete(&heap, NULL);
  rc = sfh_int32_t_uint32_t_decrease_key(NULL, &node, 1);
  rc = sfh_int32_t_uint32_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int32_t_uint32_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int32_t_uint32_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int32_t_uint32_t_meld(&heap, &heap, NULL);

  sfh_int32_t_uint32_t_init(&heap);
  rc = sfh_int32_t_uint32_t_empty(&heap, &is_empty);
  rc = sfh_int32_t_uint32_t_find_min(&heap, &out_node);
  rc = sfh_int32_t_uint32_t_delete_min(&heap);

  rc = sfh_int32_t_uint32_t_insert(&heap, &node, 10, 0);
  rc = sfh_int32_t_uint32_t_empty(&heap, &is_empty);
  rc = sfh_int32_t_uint32_t_find_min(&heap, &out_node);

  rc = sfh_int32_t_uint32_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int32_t_uint32_t_delete(&heap, &node);
  rc = sfh_int32_t_uint32_t_delete_min(&heap);

  {
    sfh_int32_t_uint32_t_heap_t h1, h2, h3, *merged;
    sfh_int32_t_uint32_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int32_t_uint32_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int32_t_uint32_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int32_t_uint32_t_init(&h3);
    sfh_int32_t_uint32_t_insert(&h1, &n1, 1, 0);
    sfh_int32_t_uint32_t_insert(&h1, &n2, 2, 0);
    sfh_int32_t_uint32_t_insert(&h1, &n3, 3, 0);
    sfh_int32_t_uint32_t_insert(&h1, &n4, 4, 0);
    sfh_int32_t_uint32_t_insert(&h2, &n5, 5, 0);

    sfh_int32_t_uint32_t_meld(&h1, &h2, &merged);
    sfh_int32_t_uint32_t_delete_min(merged);
    sfh_int32_t_uint32_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int32_t_uint32_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int32_t_uint32_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int32_t_uint32_t_insert(&heap, &fnodes[idx],
                                           (int32_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int32_t_uint32_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int32_t_uint32_t_decrease_key(&heap, &fnodes[idx],
                                                 (int32_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int32_t_uint32_t_node_t *min;
          sfh_int32_t_uint32_t_find_min(&heap, &min);
          rc = sfh_int32_t_uint32_t_delete_min(&heap);
          if (rc == sfh_int32_t_uint32_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int32_t_uint32_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int32_t_uint32_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int32_t_uint64_t(void) {
  sfh_int32_t_uint64_t_heap_t heap;
  sfh_int32_t_uint64_t_node_t node, node2;
  sfh_int32_t_uint64_t_node_t *out_node;
  sfh_int32_t_uint64_t_heap_t *out_heap;
  int is_empty;
  sfh_int32_t_uint64_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int32_t_uint64_t_init(NULL);
  rc = sfh_int32_t_uint64_t_empty(NULL, &is_empty);
  rc = sfh_int32_t_uint64_t_find_min(NULL, &out_node);
  rc = sfh_int32_t_uint64_t_insert(NULL, &node, 1, 0);
  rc = sfh_int32_t_uint64_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int32_t_uint64_t_delete_min(NULL);
  rc = sfh_int32_t_uint64_t_delete(NULL, &node);
  rc = sfh_int32_t_uint64_t_delete(&heap, NULL);
  rc = sfh_int32_t_uint64_t_decrease_key(NULL, &node, 1);
  rc = sfh_int32_t_uint64_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int32_t_uint64_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int32_t_uint64_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int32_t_uint64_t_meld(&heap, &heap, NULL);

  sfh_int32_t_uint64_t_init(&heap);
  rc = sfh_int32_t_uint64_t_empty(&heap, &is_empty);
  rc = sfh_int32_t_uint64_t_find_min(&heap, &out_node);
  rc = sfh_int32_t_uint64_t_delete_min(&heap);

  rc = sfh_int32_t_uint64_t_insert(&heap, &node, 10, 0);
  rc = sfh_int32_t_uint64_t_empty(&heap, &is_empty);
  rc = sfh_int32_t_uint64_t_find_min(&heap, &out_node);

  rc = sfh_int32_t_uint64_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int32_t_uint64_t_delete(&heap, &node);
  rc = sfh_int32_t_uint64_t_delete_min(&heap);

  {
    sfh_int32_t_uint64_t_heap_t h1, h2, h3, *merged;
    sfh_int32_t_uint64_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int32_t_uint64_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int32_t_uint64_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int32_t_uint64_t_init(&h3);
    sfh_int32_t_uint64_t_insert(&h1, &n1, 1, 0);
    sfh_int32_t_uint64_t_insert(&h1, &n2, 2, 0);
    sfh_int32_t_uint64_t_insert(&h1, &n3, 3, 0);
    sfh_int32_t_uint64_t_insert(&h1, &n4, 4, 0);
    sfh_int32_t_uint64_t_insert(&h2, &n5, 5, 0);

    sfh_int32_t_uint64_t_meld(&h1, &h2, &merged);
    sfh_int32_t_uint64_t_delete_min(merged);
    sfh_int32_t_uint64_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int32_t_uint64_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int32_t_uint64_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int32_t_uint64_t_insert(&heap, &fnodes[idx],
                                           (int32_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int32_t_uint64_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int32_t_uint64_t_decrease_key(&heap, &fnodes[idx],
                                                 (int32_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int32_t_uint64_t_node_t *min;
          sfh_int32_t_uint64_t_find_min(&heap, &min);
          rc = sfh_int32_t_uint64_t_delete_min(&heap);
          if (rc == sfh_int32_t_uint64_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int32_t_uint64_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int32_t_uint64_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int32_t_float(void) {
  sfh_int32_t_float_heap_t heap;
  sfh_int32_t_float_node_t node, node2;
  sfh_int32_t_float_node_t *out_node;
  sfh_int32_t_float_heap_t *out_heap;
  int is_empty;
  sfh_int32_t_float_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int32_t_float_init(NULL);
  rc = sfh_int32_t_float_empty(NULL, &is_empty);
  rc = sfh_int32_t_float_find_min(NULL, &out_node);
  rc = sfh_int32_t_float_insert(NULL, &node, 1, 0);
  rc = sfh_int32_t_float_insert(&heap, NULL, 1, 0);
  rc = sfh_int32_t_float_delete_min(NULL);
  rc = sfh_int32_t_float_delete(NULL, &node);
  rc = sfh_int32_t_float_delete(&heap, NULL);
  rc = sfh_int32_t_float_decrease_key(NULL, &node, 1);
  rc = sfh_int32_t_float_decrease_key(&heap, NULL, 1);
  rc = sfh_int32_t_float_meld(NULL, &heap, &out_heap);
  rc = sfh_int32_t_float_meld(&heap, NULL, &out_heap);
  rc = sfh_int32_t_float_meld(&heap, &heap, NULL);

  sfh_int32_t_float_init(&heap);
  rc = sfh_int32_t_float_empty(&heap, &is_empty);
  rc = sfh_int32_t_float_find_min(&heap, &out_node);
  rc = sfh_int32_t_float_delete_min(&heap);

  rc = sfh_int32_t_float_insert(&heap, &node, 10, 0);
  rc = sfh_int32_t_float_empty(&heap, &is_empty);
  rc = sfh_int32_t_float_find_min(&heap, &out_node);

  rc = sfh_int32_t_float_insert(&heap, &node2, 10, 0);
  rc = sfh_int32_t_float_delete(&heap, &node);
  rc = sfh_int32_t_float_delete_min(&heap);

  {
    sfh_int32_t_float_heap_t h1, h2, h3, *merged;
    sfh_int32_t_float_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int32_t_float_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int32_t_float_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int32_t_float_init(&h3);
    sfh_int32_t_float_insert(&h1, &n1, 1, 0);
    sfh_int32_t_float_insert(&h1, &n2, 2, 0);
    sfh_int32_t_float_insert(&h1, &n3, 3, 0);
    sfh_int32_t_float_insert(&h1, &n4, 4, 0);
    sfh_int32_t_float_insert(&h2, &n5, 5, 0);

    sfh_int32_t_float_meld(&h1, &h2, &merged);
    sfh_int32_t_float_delete_min(merged);
    sfh_int32_t_float_meld(&h3, merged, &merged);
  }

  {
    static sfh_int32_t_float_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int32_t_float_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int32_t_float_insert(&heap, &fnodes[idx],
                                        (int32_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int32_t_float_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int32_t_float_decrease_key(&heap, &fnodes[idx], (int32_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int32_t_float_node_t *min;
          sfh_int32_t_float_find_min(&heap, &min);
          rc = sfh_int32_t_float_delete_min(&heap);
          if (rc == sfh_int32_t_float_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int32_t_float_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int32_t_float_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int32_t_double(void) {
  sfh_int32_t_double_heap_t heap;
  sfh_int32_t_double_node_t node, node2;
  sfh_int32_t_double_node_t *out_node;
  sfh_int32_t_double_heap_t *out_heap;
  int is_empty;
  sfh_int32_t_double_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int32_t_double_init(NULL);
  rc = sfh_int32_t_double_empty(NULL, &is_empty);
  rc = sfh_int32_t_double_find_min(NULL, &out_node);
  rc = sfh_int32_t_double_insert(NULL, &node, 1, 0);
  rc = sfh_int32_t_double_insert(&heap, NULL, 1, 0);
  rc = sfh_int32_t_double_delete_min(NULL);
  rc = sfh_int32_t_double_delete(NULL, &node);
  rc = sfh_int32_t_double_delete(&heap, NULL);
  rc = sfh_int32_t_double_decrease_key(NULL, &node, 1);
  rc = sfh_int32_t_double_decrease_key(&heap, NULL, 1);
  rc = sfh_int32_t_double_meld(NULL, &heap, &out_heap);
  rc = sfh_int32_t_double_meld(&heap, NULL, &out_heap);
  rc = sfh_int32_t_double_meld(&heap, &heap, NULL);

  sfh_int32_t_double_init(&heap);
  rc = sfh_int32_t_double_empty(&heap, &is_empty);
  rc = sfh_int32_t_double_find_min(&heap, &out_node);
  rc = sfh_int32_t_double_delete_min(&heap);

  rc = sfh_int32_t_double_insert(&heap, &node, 10, 0);
  rc = sfh_int32_t_double_empty(&heap, &is_empty);
  rc = sfh_int32_t_double_find_min(&heap, &out_node);

  rc = sfh_int32_t_double_insert(&heap, &node2, 10, 0);
  rc = sfh_int32_t_double_delete(&heap, &node);
  rc = sfh_int32_t_double_delete_min(&heap);

  {
    sfh_int32_t_double_heap_t h1, h2, h3, *merged;
    sfh_int32_t_double_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int32_t_double_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int32_t_double_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int32_t_double_init(&h3);
    sfh_int32_t_double_insert(&h1, &n1, 1, 0);
    sfh_int32_t_double_insert(&h1, &n2, 2, 0);
    sfh_int32_t_double_insert(&h1, &n3, 3, 0);
    sfh_int32_t_double_insert(&h1, &n4, 4, 0);
    sfh_int32_t_double_insert(&h2, &n5, 5, 0);

    sfh_int32_t_double_meld(&h1, &h2, &merged);
    sfh_int32_t_double_delete_min(merged);
    sfh_int32_t_double_meld(&h3, merged, &merged);
  }

  {
    static sfh_int32_t_double_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int32_t_double_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int32_t_double_insert(&heap, &fnodes[idx],
                                         (int32_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int32_t_double_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int32_t_double_decrease_key(&heap, &fnodes[idx], (int32_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int32_t_double_node_t *min;
          sfh_int32_t_double_find_min(&heap, &min);
          rc = sfh_int32_t_double_delete_min(&heap);
          if (rc == sfh_int32_t_double_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int32_t_double_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int32_t_double_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int32_t_charptr(void) {
  sfh_int32_t_charptr_heap_t heap;
  sfh_int32_t_charptr_node_t node, node2;
  sfh_int32_t_charptr_node_t *out_node;
  sfh_int32_t_charptr_heap_t *out_heap;
  int is_empty;
  sfh_int32_t_charptr_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int32_t_charptr_init(NULL);
  rc = sfh_int32_t_charptr_empty(NULL, &is_empty);
  rc = sfh_int32_t_charptr_find_min(NULL, &out_node);
  rc = sfh_int32_t_charptr_insert(NULL, &node, 1, 0);
  rc = sfh_int32_t_charptr_insert(&heap, NULL, 1, 0);
  rc = sfh_int32_t_charptr_delete_min(NULL);
  rc = sfh_int32_t_charptr_delete(NULL, &node);
  rc = sfh_int32_t_charptr_delete(&heap, NULL);
  rc = sfh_int32_t_charptr_decrease_key(NULL, &node, 1);
  rc = sfh_int32_t_charptr_decrease_key(&heap, NULL, 1);
  rc = sfh_int32_t_charptr_meld(NULL, &heap, &out_heap);
  rc = sfh_int32_t_charptr_meld(&heap, NULL, &out_heap);
  rc = sfh_int32_t_charptr_meld(&heap, &heap, NULL);

  sfh_int32_t_charptr_init(&heap);
  rc = sfh_int32_t_charptr_empty(&heap, &is_empty);
  rc = sfh_int32_t_charptr_find_min(&heap, &out_node);
  rc = sfh_int32_t_charptr_delete_min(&heap);

  rc = sfh_int32_t_charptr_insert(&heap, &node, 10, 0);
  rc = sfh_int32_t_charptr_empty(&heap, &is_empty);
  rc = sfh_int32_t_charptr_find_min(&heap, &out_node);

  rc = sfh_int32_t_charptr_insert(&heap, &node2, 10, 0);
  rc = sfh_int32_t_charptr_delete(&heap, &node);
  rc = sfh_int32_t_charptr_delete_min(&heap);

  {
    sfh_int32_t_charptr_heap_t h1, h2, h3, *merged;
    sfh_int32_t_charptr_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int32_t_charptr_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int32_t_charptr_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int32_t_charptr_init(&h3);
    sfh_int32_t_charptr_insert(&h1, &n1, 1, 0);
    sfh_int32_t_charptr_insert(&h1, &n2, 2, 0);
    sfh_int32_t_charptr_insert(&h1, &n3, 3, 0);
    sfh_int32_t_charptr_insert(&h1, &n4, 4, 0);
    sfh_int32_t_charptr_insert(&h2, &n5, 5, 0);

    sfh_int32_t_charptr_meld(&h1, &h2, &merged);
    sfh_int32_t_charptr_delete_min(merged);
    sfh_int32_t_charptr_meld(&h3, merged, &merged);
  }

  {
    static sfh_int32_t_charptr_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int32_t_charptr_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int32_t_charptr_insert(&heap, &fnodes[idx],
                                          (int32_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int32_t_charptr_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc =
              sfh_int32_t_charptr_decrease_key(&heap, &fnodes[idx], (int32_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int32_t_charptr_node_t *min;
          sfh_int32_t_charptr_find_min(&heap, &min);
          rc = sfh_int32_t_charptr_delete_min(&heap);
          if (rc == sfh_int32_t_charptr_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int32_t_charptr_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int32_t_charptr_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int32_t_voidptr(void) {
  sfh_int32_t_voidptr_heap_t heap;
  sfh_int32_t_voidptr_node_t node, node2;
  sfh_int32_t_voidptr_node_t *out_node;
  sfh_int32_t_voidptr_heap_t *out_heap;
  int is_empty;
  sfh_int32_t_voidptr_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int32_t_voidptr_init(NULL);
  rc = sfh_int32_t_voidptr_empty(NULL, &is_empty);
  rc = sfh_int32_t_voidptr_find_min(NULL, &out_node);
  rc = sfh_int32_t_voidptr_insert(NULL, &node, 1, 0);
  rc = sfh_int32_t_voidptr_insert(&heap, NULL, 1, 0);
  rc = sfh_int32_t_voidptr_delete_min(NULL);
  rc = sfh_int32_t_voidptr_delete(NULL, &node);
  rc = sfh_int32_t_voidptr_delete(&heap, NULL);
  rc = sfh_int32_t_voidptr_decrease_key(NULL, &node, 1);
  rc = sfh_int32_t_voidptr_decrease_key(&heap, NULL, 1);
  rc = sfh_int32_t_voidptr_meld(NULL, &heap, &out_heap);
  rc = sfh_int32_t_voidptr_meld(&heap, NULL, &out_heap);
  rc = sfh_int32_t_voidptr_meld(&heap, &heap, NULL);

  sfh_int32_t_voidptr_init(&heap);
  rc = sfh_int32_t_voidptr_empty(&heap, &is_empty);
  rc = sfh_int32_t_voidptr_find_min(&heap, &out_node);
  rc = sfh_int32_t_voidptr_delete_min(&heap);

  rc = sfh_int32_t_voidptr_insert(&heap, &node, 10, 0);
  rc = sfh_int32_t_voidptr_empty(&heap, &is_empty);
  rc = sfh_int32_t_voidptr_find_min(&heap, &out_node);

  rc = sfh_int32_t_voidptr_insert(&heap, &node2, 10, 0);
  rc = sfh_int32_t_voidptr_delete(&heap, &node);
  rc = sfh_int32_t_voidptr_delete_min(&heap);

  {
    sfh_int32_t_voidptr_heap_t h1, h2, h3, *merged;
    sfh_int32_t_voidptr_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int32_t_voidptr_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int32_t_voidptr_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int32_t_voidptr_init(&h3);
    sfh_int32_t_voidptr_insert(&h1, &n1, 1, 0);
    sfh_int32_t_voidptr_insert(&h1, &n2, 2, 0);
    sfh_int32_t_voidptr_insert(&h1, &n3, 3, 0);
    sfh_int32_t_voidptr_insert(&h1, &n4, 4, 0);
    sfh_int32_t_voidptr_insert(&h2, &n5, 5, 0);

    sfh_int32_t_voidptr_meld(&h1, &h2, &merged);
    sfh_int32_t_voidptr_delete_min(merged);
    sfh_int32_t_voidptr_meld(&h3, merged, &merged);
  }

  {
    static sfh_int32_t_voidptr_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int32_t_voidptr_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int32_t_voidptr_insert(&heap, &fnodes[idx],
                                          (int32_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int32_t_voidptr_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc =
              sfh_int32_t_voidptr_decrease_key(&heap, &fnodes[idx], (int32_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int32_t_voidptr_node_t *min;
          sfh_int32_t_voidptr_find_min(&heap, &min);
          rc = sfh_int32_t_voidptr_delete_min(&heap);
          if (rc == sfh_int32_t_voidptr_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int32_t_voidptr_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int32_t_voidptr_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int64_t_int8_t(void) {
  sfh_int64_t_int8_t_heap_t heap;
  sfh_int64_t_int8_t_node_t node, node2;
  sfh_int64_t_int8_t_node_t *out_node;
  sfh_int64_t_int8_t_heap_t *out_heap;
  int is_empty;
  sfh_int64_t_int8_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int64_t_int8_t_init(NULL);
  rc = sfh_int64_t_int8_t_empty(NULL, &is_empty);
  rc = sfh_int64_t_int8_t_find_min(NULL, &out_node);
  rc = sfh_int64_t_int8_t_insert(NULL, &node, 1, 0);
  rc = sfh_int64_t_int8_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int64_t_int8_t_delete_min(NULL);
  rc = sfh_int64_t_int8_t_delete(NULL, &node);
  rc = sfh_int64_t_int8_t_delete(&heap, NULL);
  rc = sfh_int64_t_int8_t_decrease_key(NULL, &node, 1);
  rc = sfh_int64_t_int8_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int64_t_int8_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int64_t_int8_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int64_t_int8_t_meld(&heap, &heap, NULL);

  sfh_int64_t_int8_t_init(&heap);
  rc = sfh_int64_t_int8_t_empty(&heap, &is_empty);
  rc = sfh_int64_t_int8_t_find_min(&heap, &out_node);
  rc = sfh_int64_t_int8_t_delete_min(&heap);

  rc = sfh_int64_t_int8_t_insert(&heap, &node, 10, 0);
  rc = sfh_int64_t_int8_t_empty(&heap, &is_empty);
  rc = sfh_int64_t_int8_t_find_min(&heap, &out_node);

  rc = sfh_int64_t_int8_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int64_t_int8_t_delete(&heap, &node);
  rc = sfh_int64_t_int8_t_delete_min(&heap);

  {
    sfh_int64_t_int8_t_heap_t h1, h2, h3, *merged;
    sfh_int64_t_int8_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int64_t_int8_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int64_t_int8_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int64_t_int8_t_init(&h3);
    sfh_int64_t_int8_t_insert(&h1, &n1, 1, 0);
    sfh_int64_t_int8_t_insert(&h1, &n2, 2, 0);
    sfh_int64_t_int8_t_insert(&h1, &n3, 3, 0);
    sfh_int64_t_int8_t_insert(&h1, &n4, 4, 0);
    sfh_int64_t_int8_t_insert(&h2, &n5, 5, 0);

    sfh_int64_t_int8_t_meld(&h1, &h2, &merged);
    sfh_int64_t_int8_t_delete_min(merged);
    sfh_int64_t_int8_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int64_t_int8_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int64_t_int8_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int64_t_int8_t_insert(&heap, &fnodes[idx],
                                         (int64_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int64_t_int8_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int64_t_int8_t_decrease_key(&heap, &fnodes[idx], (int64_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int64_t_int8_t_node_t *min;
          sfh_int64_t_int8_t_find_min(&heap, &min);
          rc = sfh_int64_t_int8_t_delete_min(&heap);
          if (rc == sfh_int64_t_int8_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int64_t_int8_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int64_t_int8_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int64_t_int16_t(void) {
  sfh_int64_t_int16_t_heap_t heap;
  sfh_int64_t_int16_t_node_t node, node2;
  sfh_int64_t_int16_t_node_t *out_node;
  sfh_int64_t_int16_t_heap_t *out_heap;
  int is_empty;
  sfh_int64_t_int16_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int64_t_int16_t_init(NULL);
  rc = sfh_int64_t_int16_t_empty(NULL, &is_empty);
  rc = sfh_int64_t_int16_t_find_min(NULL, &out_node);
  rc = sfh_int64_t_int16_t_insert(NULL, &node, 1, 0);
  rc = sfh_int64_t_int16_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int64_t_int16_t_delete_min(NULL);
  rc = sfh_int64_t_int16_t_delete(NULL, &node);
  rc = sfh_int64_t_int16_t_delete(&heap, NULL);
  rc = sfh_int64_t_int16_t_decrease_key(NULL, &node, 1);
  rc = sfh_int64_t_int16_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int64_t_int16_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int64_t_int16_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int64_t_int16_t_meld(&heap, &heap, NULL);

  sfh_int64_t_int16_t_init(&heap);
  rc = sfh_int64_t_int16_t_empty(&heap, &is_empty);
  rc = sfh_int64_t_int16_t_find_min(&heap, &out_node);
  rc = sfh_int64_t_int16_t_delete_min(&heap);

  rc = sfh_int64_t_int16_t_insert(&heap, &node, 10, 0);
  rc = sfh_int64_t_int16_t_empty(&heap, &is_empty);
  rc = sfh_int64_t_int16_t_find_min(&heap, &out_node);

  rc = sfh_int64_t_int16_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int64_t_int16_t_delete(&heap, &node);
  rc = sfh_int64_t_int16_t_delete_min(&heap);

  {
    sfh_int64_t_int16_t_heap_t h1, h2, h3, *merged;
    sfh_int64_t_int16_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int64_t_int16_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int64_t_int16_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int64_t_int16_t_init(&h3);
    sfh_int64_t_int16_t_insert(&h1, &n1, 1, 0);
    sfh_int64_t_int16_t_insert(&h1, &n2, 2, 0);
    sfh_int64_t_int16_t_insert(&h1, &n3, 3, 0);
    sfh_int64_t_int16_t_insert(&h1, &n4, 4, 0);
    sfh_int64_t_int16_t_insert(&h2, &n5, 5, 0);

    sfh_int64_t_int16_t_meld(&h1, &h2, &merged);
    sfh_int64_t_int16_t_delete_min(merged);
    sfh_int64_t_int16_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int64_t_int16_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int64_t_int16_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int64_t_int16_t_insert(&heap, &fnodes[idx],
                                          (int64_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int64_t_int16_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc =
              sfh_int64_t_int16_t_decrease_key(&heap, &fnodes[idx], (int64_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int64_t_int16_t_node_t *min;
          sfh_int64_t_int16_t_find_min(&heap, &min);
          rc = sfh_int64_t_int16_t_delete_min(&heap);
          if (rc == sfh_int64_t_int16_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int64_t_int16_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int64_t_int16_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int64_t_int32_t(void) {
  sfh_int64_t_int32_t_heap_t heap;
  sfh_int64_t_int32_t_node_t node, node2;
  sfh_int64_t_int32_t_node_t *out_node;
  sfh_int64_t_int32_t_heap_t *out_heap;
  int is_empty;
  sfh_int64_t_int32_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int64_t_int32_t_init(NULL);
  rc = sfh_int64_t_int32_t_empty(NULL, &is_empty);
  rc = sfh_int64_t_int32_t_find_min(NULL, &out_node);
  rc = sfh_int64_t_int32_t_insert(NULL, &node, 1, 0);
  rc = sfh_int64_t_int32_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int64_t_int32_t_delete_min(NULL);
  rc = sfh_int64_t_int32_t_delete(NULL, &node);
  rc = sfh_int64_t_int32_t_delete(&heap, NULL);
  rc = sfh_int64_t_int32_t_decrease_key(NULL, &node, 1);
  rc = sfh_int64_t_int32_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int64_t_int32_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int64_t_int32_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int64_t_int32_t_meld(&heap, &heap, NULL);

  sfh_int64_t_int32_t_init(&heap);
  rc = sfh_int64_t_int32_t_empty(&heap, &is_empty);
  rc = sfh_int64_t_int32_t_find_min(&heap, &out_node);
  rc = sfh_int64_t_int32_t_delete_min(&heap);

  rc = sfh_int64_t_int32_t_insert(&heap, &node, 10, 0);
  rc = sfh_int64_t_int32_t_empty(&heap, &is_empty);
  rc = sfh_int64_t_int32_t_find_min(&heap, &out_node);

  rc = sfh_int64_t_int32_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int64_t_int32_t_delete(&heap, &node);
  rc = sfh_int64_t_int32_t_delete_min(&heap);

  {
    sfh_int64_t_int32_t_heap_t h1, h2, h3, *merged;
    sfh_int64_t_int32_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int64_t_int32_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int64_t_int32_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int64_t_int32_t_init(&h3);
    sfh_int64_t_int32_t_insert(&h1, &n1, 1, 0);
    sfh_int64_t_int32_t_insert(&h1, &n2, 2, 0);
    sfh_int64_t_int32_t_insert(&h1, &n3, 3, 0);
    sfh_int64_t_int32_t_insert(&h1, &n4, 4, 0);
    sfh_int64_t_int32_t_insert(&h2, &n5, 5, 0);

    sfh_int64_t_int32_t_meld(&h1, &h2, &merged);
    sfh_int64_t_int32_t_delete_min(merged);
    sfh_int64_t_int32_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int64_t_int32_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int64_t_int32_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int64_t_int32_t_insert(&heap, &fnodes[idx],
                                          (int64_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int64_t_int32_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc =
              sfh_int64_t_int32_t_decrease_key(&heap, &fnodes[idx], (int64_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int64_t_int32_t_node_t *min;
          sfh_int64_t_int32_t_find_min(&heap, &min);
          rc = sfh_int64_t_int32_t_delete_min(&heap);
          if (rc == sfh_int64_t_int32_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int64_t_int32_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int64_t_int32_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int64_t_int64_t(void) {
  sfh_int64_t_int64_t_heap_t heap;
  sfh_int64_t_int64_t_node_t node, node2;
  sfh_int64_t_int64_t_node_t *out_node;
  sfh_int64_t_int64_t_heap_t *out_heap;
  int is_empty;
  sfh_int64_t_int64_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int64_t_int64_t_init(NULL);
  rc = sfh_int64_t_int64_t_empty(NULL, &is_empty);
  rc = sfh_int64_t_int64_t_find_min(NULL, &out_node);
  rc = sfh_int64_t_int64_t_insert(NULL, &node, 1, 0);
  rc = sfh_int64_t_int64_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int64_t_int64_t_delete_min(NULL);
  rc = sfh_int64_t_int64_t_delete(NULL, &node);
  rc = sfh_int64_t_int64_t_delete(&heap, NULL);
  rc = sfh_int64_t_int64_t_decrease_key(NULL, &node, 1);
  rc = sfh_int64_t_int64_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int64_t_int64_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int64_t_int64_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int64_t_int64_t_meld(&heap, &heap, NULL);

  sfh_int64_t_int64_t_init(&heap);
  rc = sfh_int64_t_int64_t_empty(&heap, &is_empty);
  rc = sfh_int64_t_int64_t_find_min(&heap, &out_node);
  rc = sfh_int64_t_int64_t_delete_min(&heap);

  rc = sfh_int64_t_int64_t_insert(&heap, &node, 10, 0);
  rc = sfh_int64_t_int64_t_empty(&heap, &is_empty);
  rc = sfh_int64_t_int64_t_find_min(&heap, &out_node);

  rc = sfh_int64_t_int64_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int64_t_int64_t_delete(&heap, &node);
  rc = sfh_int64_t_int64_t_delete_min(&heap);

  {
    sfh_int64_t_int64_t_heap_t h1, h2, h3, *merged;
    sfh_int64_t_int64_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int64_t_int64_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int64_t_int64_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int64_t_int64_t_init(&h3);
    sfh_int64_t_int64_t_insert(&h1, &n1, 1, 0);
    sfh_int64_t_int64_t_insert(&h1, &n2, 2, 0);
    sfh_int64_t_int64_t_insert(&h1, &n3, 3, 0);
    sfh_int64_t_int64_t_insert(&h1, &n4, 4, 0);
    sfh_int64_t_int64_t_insert(&h2, &n5, 5, 0);

    sfh_int64_t_int64_t_meld(&h1, &h2, &merged);
    sfh_int64_t_int64_t_delete_min(merged);
    sfh_int64_t_int64_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int64_t_int64_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int64_t_int64_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int64_t_int64_t_insert(&heap, &fnodes[idx],
                                          (int64_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int64_t_int64_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc =
              sfh_int64_t_int64_t_decrease_key(&heap, &fnodes[idx], (int64_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int64_t_int64_t_node_t *min;
          sfh_int64_t_int64_t_find_min(&heap, &min);
          rc = sfh_int64_t_int64_t_delete_min(&heap);
          if (rc == sfh_int64_t_int64_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int64_t_int64_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int64_t_int64_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int64_t_uint8_t(void) {
  sfh_int64_t_uint8_t_heap_t heap;
  sfh_int64_t_uint8_t_node_t node, node2;
  sfh_int64_t_uint8_t_node_t *out_node;
  sfh_int64_t_uint8_t_heap_t *out_heap;
  int is_empty;
  sfh_int64_t_uint8_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int64_t_uint8_t_init(NULL);
  rc = sfh_int64_t_uint8_t_empty(NULL, &is_empty);
  rc = sfh_int64_t_uint8_t_find_min(NULL, &out_node);
  rc = sfh_int64_t_uint8_t_insert(NULL, &node, 1, 0);
  rc = sfh_int64_t_uint8_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int64_t_uint8_t_delete_min(NULL);
  rc = sfh_int64_t_uint8_t_delete(NULL, &node);
  rc = sfh_int64_t_uint8_t_delete(&heap, NULL);
  rc = sfh_int64_t_uint8_t_decrease_key(NULL, &node, 1);
  rc = sfh_int64_t_uint8_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int64_t_uint8_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int64_t_uint8_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int64_t_uint8_t_meld(&heap, &heap, NULL);

  sfh_int64_t_uint8_t_init(&heap);
  rc = sfh_int64_t_uint8_t_empty(&heap, &is_empty);
  rc = sfh_int64_t_uint8_t_find_min(&heap, &out_node);
  rc = sfh_int64_t_uint8_t_delete_min(&heap);

  rc = sfh_int64_t_uint8_t_insert(&heap, &node, 10, 0);
  rc = sfh_int64_t_uint8_t_empty(&heap, &is_empty);
  rc = sfh_int64_t_uint8_t_find_min(&heap, &out_node);

  rc = sfh_int64_t_uint8_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int64_t_uint8_t_delete(&heap, &node);
  rc = sfh_int64_t_uint8_t_delete_min(&heap);

  {
    sfh_int64_t_uint8_t_heap_t h1, h2, h3, *merged;
    sfh_int64_t_uint8_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int64_t_uint8_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int64_t_uint8_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int64_t_uint8_t_init(&h3);
    sfh_int64_t_uint8_t_insert(&h1, &n1, 1, 0);
    sfh_int64_t_uint8_t_insert(&h1, &n2, 2, 0);
    sfh_int64_t_uint8_t_insert(&h1, &n3, 3, 0);
    sfh_int64_t_uint8_t_insert(&h1, &n4, 4, 0);
    sfh_int64_t_uint8_t_insert(&h2, &n5, 5, 0);

    sfh_int64_t_uint8_t_meld(&h1, &h2, &merged);
    sfh_int64_t_uint8_t_delete_min(merged);
    sfh_int64_t_uint8_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int64_t_uint8_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int64_t_uint8_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int64_t_uint8_t_insert(&heap, &fnodes[idx],
                                          (int64_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int64_t_uint8_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc =
              sfh_int64_t_uint8_t_decrease_key(&heap, &fnodes[idx], (int64_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int64_t_uint8_t_node_t *min;
          sfh_int64_t_uint8_t_find_min(&heap, &min);
          rc = sfh_int64_t_uint8_t_delete_min(&heap);
          if (rc == sfh_int64_t_uint8_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int64_t_uint8_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int64_t_uint8_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int64_t_uint16_t(void) {
  sfh_int64_t_uint16_t_heap_t heap;
  sfh_int64_t_uint16_t_node_t node, node2;
  sfh_int64_t_uint16_t_node_t *out_node;
  sfh_int64_t_uint16_t_heap_t *out_heap;
  int is_empty;
  sfh_int64_t_uint16_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int64_t_uint16_t_init(NULL);
  rc = sfh_int64_t_uint16_t_empty(NULL, &is_empty);
  rc = sfh_int64_t_uint16_t_find_min(NULL, &out_node);
  rc = sfh_int64_t_uint16_t_insert(NULL, &node, 1, 0);
  rc = sfh_int64_t_uint16_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int64_t_uint16_t_delete_min(NULL);
  rc = sfh_int64_t_uint16_t_delete(NULL, &node);
  rc = sfh_int64_t_uint16_t_delete(&heap, NULL);
  rc = sfh_int64_t_uint16_t_decrease_key(NULL, &node, 1);
  rc = sfh_int64_t_uint16_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int64_t_uint16_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int64_t_uint16_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int64_t_uint16_t_meld(&heap, &heap, NULL);

  sfh_int64_t_uint16_t_init(&heap);
  rc = sfh_int64_t_uint16_t_empty(&heap, &is_empty);
  rc = sfh_int64_t_uint16_t_find_min(&heap, &out_node);
  rc = sfh_int64_t_uint16_t_delete_min(&heap);

  rc = sfh_int64_t_uint16_t_insert(&heap, &node, 10, 0);
  rc = sfh_int64_t_uint16_t_empty(&heap, &is_empty);
  rc = sfh_int64_t_uint16_t_find_min(&heap, &out_node);

  rc = sfh_int64_t_uint16_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int64_t_uint16_t_delete(&heap, &node);
  rc = sfh_int64_t_uint16_t_delete_min(&heap);

  {
    sfh_int64_t_uint16_t_heap_t h1, h2, h3, *merged;
    sfh_int64_t_uint16_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int64_t_uint16_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int64_t_uint16_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int64_t_uint16_t_init(&h3);
    sfh_int64_t_uint16_t_insert(&h1, &n1, 1, 0);
    sfh_int64_t_uint16_t_insert(&h1, &n2, 2, 0);
    sfh_int64_t_uint16_t_insert(&h1, &n3, 3, 0);
    sfh_int64_t_uint16_t_insert(&h1, &n4, 4, 0);
    sfh_int64_t_uint16_t_insert(&h2, &n5, 5, 0);

    sfh_int64_t_uint16_t_meld(&h1, &h2, &merged);
    sfh_int64_t_uint16_t_delete_min(merged);
    sfh_int64_t_uint16_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int64_t_uint16_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int64_t_uint16_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int64_t_uint16_t_insert(&heap, &fnodes[idx],
                                           (int64_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int64_t_uint16_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int64_t_uint16_t_decrease_key(&heap, &fnodes[idx],
                                                 (int64_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int64_t_uint16_t_node_t *min;
          sfh_int64_t_uint16_t_find_min(&heap, &min);
          rc = sfh_int64_t_uint16_t_delete_min(&heap);
          if (rc == sfh_int64_t_uint16_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int64_t_uint16_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int64_t_uint16_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int64_t_uint32_t(void) {
  sfh_int64_t_uint32_t_heap_t heap;
  sfh_int64_t_uint32_t_node_t node, node2;
  sfh_int64_t_uint32_t_node_t *out_node;
  sfh_int64_t_uint32_t_heap_t *out_heap;
  int is_empty;
  sfh_int64_t_uint32_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int64_t_uint32_t_init(NULL);
  rc = sfh_int64_t_uint32_t_empty(NULL, &is_empty);
  rc = sfh_int64_t_uint32_t_find_min(NULL, &out_node);
  rc = sfh_int64_t_uint32_t_insert(NULL, &node, 1, 0);
  rc = sfh_int64_t_uint32_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int64_t_uint32_t_delete_min(NULL);
  rc = sfh_int64_t_uint32_t_delete(NULL, &node);
  rc = sfh_int64_t_uint32_t_delete(&heap, NULL);
  rc = sfh_int64_t_uint32_t_decrease_key(NULL, &node, 1);
  rc = sfh_int64_t_uint32_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int64_t_uint32_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int64_t_uint32_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int64_t_uint32_t_meld(&heap, &heap, NULL);

  sfh_int64_t_uint32_t_init(&heap);
  rc = sfh_int64_t_uint32_t_empty(&heap, &is_empty);
  rc = sfh_int64_t_uint32_t_find_min(&heap, &out_node);
  rc = sfh_int64_t_uint32_t_delete_min(&heap);

  rc = sfh_int64_t_uint32_t_insert(&heap, &node, 10, 0);
  rc = sfh_int64_t_uint32_t_empty(&heap, &is_empty);
  rc = sfh_int64_t_uint32_t_find_min(&heap, &out_node);

  rc = sfh_int64_t_uint32_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int64_t_uint32_t_delete(&heap, &node);
  rc = sfh_int64_t_uint32_t_delete_min(&heap);

  {
    sfh_int64_t_uint32_t_heap_t h1, h2, h3, *merged;
    sfh_int64_t_uint32_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int64_t_uint32_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int64_t_uint32_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int64_t_uint32_t_init(&h3);
    sfh_int64_t_uint32_t_insert(&h1, &n1, 1, 0);
    sfh_int64_t_uint32_t_insert(&h1, &n2, 2, 0);
    sfh_int64_t_uint32_t_insert(&h1, &n3, 3, 0);
    sfh_int64_t_uint32_t_insert(&h1, &n4, 4, 0);
    sfh_int64_t_uint32_t_insert(&h2, &n5, 5, 0);

    sfh_int64_t_uint32_t_meld(&h1, &h2, &merged);
    sfh_int64_t_uint32_t_delete_min(merged);
    sfh_int64_t_uint32_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int64_t_uint32_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int64_t_uint32_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int64_t_uint32_t_insert(&heap, &fnodes[idx],
                                           (int64_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int64_t_uint32_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int64_t_uint32_t_decrease_key(&heap, &fnodes[idx],
                                                 (int64_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int64_t_uint32_t_node_t *min;
          sfh_int64_t_uint32_t_find_min(&heap, &min);
          rc = sfh_int64_t_uint32_t_delete_min(&heap);
          if (rc == sfh_int64_t_uint32_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int64_t_uint32_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int64_t_uint32_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int64_t_uint64_t(void) {
  sfh_int64_t_uint64_t_heap_t heap;
  sfh_int64_t_uint64_t_node_t node, node2;
  sfh_int64_t_uint64_t_node_t *out_node;
  sfh_int64_t_uint64_t_heap_t *out_heap;
  int is_empty;
  sfh_int64_t_uint64_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int64_t_uint64_t_init(NULL);
  rc = sfh_int64_t_uint64_t_empty(NULL, &is_empty);
  rc = sfh_int64_t_uint64_t_find_min(NULL, &out_node);
  rc = sfh_int64_t_uint64_t_insert(NULL, &node, 1, 0);
  rc = sfh_int64_t_uint64_t_insert(&heap, NULL, 1, 0);
  rc = sfh_int64_t_uint64_t_delete_min(NULL);
  rc = sfh_int64_t_uint64_t_delete(NULL, &node);
  rc = sfh_int64_t_uint64_t_delete(&heap, NULL);
  rc = sfh_int64_t_uint64_t_decrease_key(NULL, &node, 1);
  rc = sfh_int64_t_uint64_t_decrease_key(&heap, NULL, 1);
  rc = sfh_int64_t_uint64_t_meld(NULL, &heap, &out_heap);
  rc = sfh_int64_t_uint64_t_meld(&heap, NULL, &out_heap);
  rc = sfh_int64_t_uint64_t_meld(&heap, &heap, NULL);

  sfh_int64_t_uint64_t_init(&heap);
  rc = sfh_int64_t_uint64_t_empty(&heap, &is_empty);
  rc = sfh_int64_t_uint64_t_find_min(&heap, &out_node);
  rc = sfh_int64_t_uint64_t_delete_min(&heap);

  rc = sfh_int64_t_uint64_t_insert(&heap, &node, 10, 0);
  rc = sfh_int64_t_uint64_t_empty(&heap, &is_empty);
  rc = sfh_int64_t_uint64_t_find_min(&heap, &out_node);

  rc = sfh_int64_t_uint64_t_insert(&heap, &node2, 10, 0);
  rc = sfh_int64_t_uint64_t_delete(&heap, &node);
  rc = sfh_int64_t_uint64_t_delete_min(&heap);

  {
    sfh_int64_t_uint64_t_heap_t h1, h2, h3, *merged;
    sfh_int64_t_uint64_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int64_t_uint64_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int64_t_uint64_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int64_t_uint64_t_init(&h3);
    sfh_int64_t_uint64_t_insert(&h1, &n1, 1, 0);
    sfh_int64_t_uint64_t_insert(&h1, &n2, 2, 0);
    sfh_int64_t_uint64_t_insert(&h1, &n3, 3, 0);
    sfh_int64_t_uint64_t_insert(&h1, &n4, 4, 0);
    sfh_int64_t_uint64_t_insert(&h2, &n5, 5, 0);

    sfh_int64_t_uint64_t_meld(&h1, &h2, &merged);
    sfh_int64_t_uint64_t_delete_min(merged);
    sfh_int64_t_uint64_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_int64_t_uint64_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int64_t_uint64_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int64_t_uint64_t_insert(&heap, &fnodes[idx],
                                           (int64_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int64_t_uint64_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int64_t_uint64_t_decrease_key(&heap, &fnodes[idx],
                                                 (int64_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int64_t_uint64_t_node_t *min;
          sfh_int64_t_uint64_t_find_min(&heap, &min);
          rc = sfh_int64_t_uint64_t_delete_min(&heap);
          if (rc == sfh_int64_t_uint64_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int64_t_uint64_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int64_t_uint64_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int64_t_float(void) {
  sfh_int64_t_float_heap_t heap;
  sfh_int64_t_float_node_t node, node2;
  sfh_int64_t_float_node_t *out_node;
  sfh_int64_t_float_heap_t *out_heap;
  int is_empty;
  sfh_int64_t_float_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int64_t_float_init(NULL);
  rc = sfh_int64_t_float_empty(NULL, &is_empty);
  rc = sfh_int64_t_float_find_min(NULL, &out_node);
  rc = sfh_int64_t_float_insert(NULL, &node, 1, 0);
  rc = sfh_int64_t_float_insert(&heap, NULL, 1, 0);
  rc = sfh_int64_t_float_delete_min(NULL);
  rc = sfh_int64_t_float_delete(NULL, &node);
  rc = sfh_int64_t_float_delete(&heap, NULL);
  rc = sfh_int64_t_float_decrease_key(NULL, &node, 1);
  rc = sfh_int64_t_float_decrease_key(&heap, NULL, 1);
  rc = sfh_int64_t_float_meld(NULL, &heap, &out_heap);
  rc = sfh_int64_t_float_meld(&heap, NULL, &out_heap);
  rc = sfh_int64_t_float_meld(&heap, &heap, NULL);

  sfh_int64_t_float_init(&heap);
  rc = sfh_int64_t_float_empty(&heap, &is_empty);
  rc = sfh_int64_t_float_find_min(&heap, &out_node);
  rc = sfh_int64_t_float_delete_min(&heap);

  rc = sfh_int64_t_float_insert(&heap, &node, 10, 0);
  rc = sfh_int64_t_float_empty(&heap, &is_empty);
  rc = sfh_int64_t_float_find_min(&heap, &out_node);

  rc = sfh_int64_t_float_insert(&heap, &node2, 10, 0);
  rc = sfh_int64_t_float_delete(&heap, &node);
  rc = sfh_int64_t_float_delete_min(&heap);

  {
    sfh_int64_t_float_heap_t h1, h2, h3, *merged;
    sfh_int64_t_float_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int64_t_float_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int64_t_float_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int64_t_float_init(&h3);
    sfh_int64_t_float_insert(&h1, &n1, 1, 0);
    sfh_int64_t_float_insert(&h1, &n2, 2, 0);
    sfh_int64_t_float_insert(&h1, &n3, 3, 0);
    sfh_int64_t_float_insert(&h1, &n4, 4, 0);
    sfh_int64_t_float_insert(&h2, &n5, 5, 0);

    sfh_int64_t_float_meld(&h1, &h2, &merged);
    sfh_int64_t_float_delete_min(merged);
    sfh_int64_t_float_meld(&h3, merged, &merged);
  }

  {
    static sfh_int64_t_float_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int64_t_float_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int64_t_float_insert(&heap, &fnodes[idx],
                                        (int64_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int64_t_float_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int64_t_float_decrease_key(&heap, &fnodes[idx], (int64_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int64_t_float_node_t *min;
          sfh_int64_t_float_find_min(&heap, &min);
          rc = sfh_int64_t_float_delete_min(&heap);
          if (rc == sfh_int64_t_float_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int64_t_float_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int64_t_float_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int64_t_double(void) {
  sfh_int64_t_double_heap_t heap;
  sfh_int64_t_double_node_t node, node2;
  sfh_int64_t_double_node_t *out_node;
  sfh_int64_t_double_heap_t *out_heap;
  int is_empty;
  sfh_int64_t_double_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int64_t_double_init(NULL);
  rc = sfh_int64_t_double_empty(NULL, &is_empty);
  rc = sfh_int64_t_double_find_min(NULL, &out_node);
  rc = sfh_int64_t_double_insert(NULL, &node, 1, 0);
  rc = sfh_int64_t_double_insert(&heap, NULL, 1, 0);
  rc = sfh_int64_t_double_delete_min(NULL);
  rc = sfh_int64_t_double_delete(NULL, &node);
  rc = sfh_int64_t_double_delete(&heap, NULL);
  rc = sfh_int64_t_double_decrease_key(NULL, &node, 1);
  rc = sfh_int64_t_double_decrease_key(&heap, NULL, 1);
  rc = sfh_int64_t_double_meld(NULL, &heap, &out_heap);
  rc = sfh_int64_t_double_meld(&heap, NULL, &out_heap);
  rc = sfh_int64_t_double_meld(&heap, &heap, NULL);

  sfh_int64_t_double_init(&heap);
  rc = sfh_int64_t_double_empty(&heap, &is_empty);
  rc = sfh_int64_t_double_find_min(&heap, &out_node);
  rc = sfh_int64_t_double_delete_min(&heap);

  rc = sfh_int64_t_double_insert(&heap, &node, 10, 0);
  rc = sfh_int64_t_double_empty(&heap, &is_empty);
  rc = sfh_int64_t_double_find_min(&heap, &out_node);

  rc = sfh_int64_t_double_insert(&heap, &node2, 10, 0);
  rc = sfh_int64_t_double_delete(&heap, &node);
  rc = sfh_int64_t_double_delete_min(&heap);

  {
    sfh_int64_t_double_heap_t h1, h2, h3, *merged;
    sfh_int64_t_double_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int64_t_double_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int64_t_double_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int64_t_double_init(&h3);
    sfh_int64_t_double_insert(&h1, &n1, 1, 0);
    sfh_int64_t_double_insert(&h1, &n2, 2, 0);
    sfh_int64_t_double_insert(&h1, &n3, 3, 0);
    sfh_int64_t_double_insert(&h1, &n4, 4, 0);
    sfh_int64_t_double_insert(&h2, &n5, 5, 0);

    sfh_int64_t_double_meld(&h1, &h2, &merged);
    sfh_int64_t_double_delete_min(merged);
    sfh_int64_t_double_meld(&h3, merged, &merged);
  }

  {
    static sfh_int64_t_double_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int64_t_double_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int64_t_double_insert(&heap, &fnodes[idx],
                                         (int64_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int64_t_double_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_int64_t_double_decrease_key(&heap, &fnodes[idx], (int64_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int64_t_double_node_t *min;
          sfh_int64_t_double_find_min(&heap, &min);
          rc = sfh_int64_t_double_delete_min(&heap);
          if (rc == sfh_int64_t_double_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int64_t_double_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int64_t_double_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int64_t_charptr(void) {
  sfh_int64_t_charptr_heap_t heap;
  sfh_int64_t_charptr_node_t node, node2;
  sfh_int64_t_charptr_node_t *out_node;
  sfh_int64_t_charptr_heap_t *out_heap;
  int is_empty;
  sfh_int64_t_charptr_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int64_t_charptr_init(NULL);
  rc = sfh_int64_t_charptr_empty(NULL, &is_empty);
  rc = sfh_int64_t_charptr_find_min(NULL, &out_node);
  rc = sfh_int64_t_charptr_insert(NULL, &node, 1, 0);
  rc = sfh_int64_t_charptr_insert(&heap, NULL, 1, 0);
  rc = sfh_int64_t_charptr_delete_min(NULL);
  rc = sfh_int64_t_charptr_delete(NULL, &node);
  rc = sfh_int64_t_charptr_delete(&heap, NULL);
  rc = sfh_int64_t_charptr_decrease_key(NULL, &node, 1);
  rc = sfh_int64_t_charptr_decrease_key(&heap, NULL, 1);
  rc = sfh_int64_t_charptr_meld(NULL, &heap, &out_heap);
  rc = sfh_int64_t_charptr_meld(&heap, NULL, &out_heap);
  rc = sfh_int64_t_charptr_meld(&heap, &heap, NULL);

  sfh_int64_t_charptr_init(&heap);
  rc = sfh_int64_t_charptr_empty(&heap, &is_empty);
  rc = sfh_int64_t_charptr_find_min(&heap, &out_node);
  rc = sfh_int64_t_charptr_delete_min(&heap);

  rc = sfh_int64_t_charptr_insert(&heap, &node, 10, 0);
  rc = sfh_int64_t_charptr_empty(&heap, &is_empty);
  rc = sfh_int64_t_charptr_find_min(&heap, &out_node);

  rc = sfh_int64_t_charptr_insert(&heap, &node2, 10, 0);
  rc = sfh_int64_t_charptr_delete(&heap, &node);
  rc = sfh_int64_t_charptr_delete_min(&heap);

  {
    sfh_int64_t_charptr_heap_t h1, h2, h3, *merged;
    sfh_int64_t_charptr_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int64_t_charptr_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int64_t_charptr_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int64_t_charptr_init(&h3);
    sfh_int64_t_charptr_insert(&h1, &n1, 1, 0);
    sfh_int64_t_charptr_insert(&h1, &n2, 2, 0);
    sfh_int64_t_charptr_insert(&h1, &n3, 3, 0);
    sfh_int64_t_charptr_insert(&h1, &n4, 4, 0);
    sfh_int64_t_charptr_insert(&h2, &n5, 5, 0);

    sfh_int64_t_charptr_meld(&h1, &h2, &merged);
    sfh_int64_t_charptr_delete_min(merged);
    sfh_int64_t_charptr_meld(&h3, merged, &merged);
  }

  {
    static sfh_int64_t_charptr_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int64_t_charptr_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int64_t_charptr_insert(&heap, &fnodes[idx],
                                          (int64_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int64_t_charptr_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc =
              sfh_int64_t_charptr_decrease_key(&heap, &fnodes[idx], (int64_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int64_t_charptr_node_t *min;
          sfh_int64_t_charptr_find_min(&heap, &min);
          rc = sfh_int64_t_charptr_delete_min(&heap);
          if (rc == sfh_int64_t_charptr_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int64_t_charptr_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int64_t_charptr_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_int64_t_voidptr(void) {
  sfh_int64_t_voidptr_heap_t heap;
  sfh_int64_t_voidptr_node_t node, node2;
  sfh_int64_t_voidptr_node_t *out_node;
  sfh_int64_t_voidptr_heap_t *out_heap;
  int is_empty;
  sfh_int64_t_voidptr_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_int64_t_voidptr_init(NULL);
  rc = sfh_int64_t_voidptr_empty(NULL, &is_empty);
  rc = sfh_int64_t_voidptr_find_min(NULL, &out_node);
  rc = sfh_int64_t_voidptr_insert(NULL, &node, 1, 0);
  rc = sfh_int64_t_voidptr_insert(&heap, NULL, 1, 0);
  rc = sfh_int64_t_voidptr_delete_min(NULL);
  rc = sfh_int64_t_voidptr_delete(NULL, &node);
  rc = sfh_int64_t_voidptr_delete(&heap, NULL);
  rc = sfh_int64_t_voidptr_decrease_key(NULL, &node, 1);
  rc = sfh_int64_t_voidptr_decrease_key(&heap, NULL, 1);
  rc = sfh_int64_t_voidptr_meld(NULL, &heap, &out_heap);
  rc = sfh_int64_t_voidptr_meld(&heap, NULL, &out_heap);
  rc = sfh_int64_t_voidptr_meld(&heap, &heap, NULL);

  sfh_int64_t_voidptr_init(&heap);
  rc = sfh_int64_t_voidptr_empty(&heap, &is_empty);
  rc = sfh_int64_t_voidptr_find_min(&heap, &out_node);
  rc = sfh_int64_t_voidptr_delete_min(&heap);

  rc = sfh_int64_t_voidptr_insert(&heap, &node, 10, 0);
  rc = sfh_int64_t_voidptr_empty(&heap, &is_empty);
  rc = sfh_int64_t_voidptr_find_min(&heap, &out_node);

  rc = sfh_int64_t_voidptr_insert(&heap, &node2, 10, 0);
  rc = sfh_int64_t_voidptr_delete(&heap, &node);
  rc = sfh_int64_t_voidptr_delete_min(&heap);

  {
    sfh_int64_t_voidptr_heap_t h1, h2, h3, *merged;
    sfh_int64_t_voidptr_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_int64_t_voidptr_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_int64_t_voidptr_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_int64_t_voidptr_init(&h3);
    sfh_int64_t_voidptr_insert(&h1, &n1, 1, 0);
    sfh_int64_t_voidptr_insert(&h1, &n2, 2, 0);
    sfh_int64_t_voidptr_insert(&h1, &n3, 3, 0);
    sfh_int64_t_voidptr_insert(&h1, &n4, 4, 0);
    sfh_int64_t_voidptr_insert(&h2, &n5, 5, 0);

    sfh_int64_t_voidptr_meld(&h1, &h2, &merged);
    sfh_int64_t_voidptr_delete_min(merged);
    sfh_int64_t_voidptr_meld(&h3, merged, &merged);
  }

  {
    static sfh_int64_t_voidptr_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_int64_t_voidptr_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_int64_t_voidptr_insert(&heap, &fnodes[idx],
                                          (int64_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_int64_t_voidptr_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc =
              sfh_int64_t_voidptr_decrease_key(&heap, &fnodes[idx], (int64_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_int64_t_voidptr_node_t *min;
          sfh_int64_t_voidptr_find_min(&heap, &min);
          rc = sfh_int64_t_voidptr_delete_min(&heap);
          if (rc == sfh_int64_t_voidptr_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_int64_t_voidptr_delete(&heap, &fnodes[idx]);
          if (rc == sfh_int64_t_voidptr_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint8_t_int8_t(void) {
  sfh_uint8_t_int8_t_heap_t heap;
  sfh_uint8_t_int8_t_node_t node, node2;
  sfh_uint8_t_int8_t_node_t *out_node;
  sfh_uint8_t_int8_t_heap_t *out_heap;
  int is_empty;
  sfh_uint8_t_int8_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint8_t_int8_t_init(NULL);
  rc = sfh_uint8_t_int8_t_empty(NULL, &is_empty);
  rc = sfh_uint8_t_int8_t_find_min(NULL, &out_node);
  rc = sfh_uint8_t_int8_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint8_t_int8_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint8_t_int8_t_delete_min(NULL);
  rc = sfh_uint8_t_int8_t_delete(NULL, &node);
  rc = sfh_uint8_t_int8_t_delete(&heap, NULL);
  rc = sfh_uint8_t_int8_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint8_t_int8_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint8_t_int8_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint8_t_int8_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint8_t_int8_t_meld(&heap, &heap, NULL);

  sfh_uint8_t_int8_t_init(&heap);
  rc = sfh_uint8_t_int8_t_empty(&heap, &is_empty);
  rc = sfh_uint8_t_int8_t_find_min(&heap, &out_node);
  rc = sfh_uint8_t_int8_t_delete_min(&heap);

  rc = sfh_uint8_t_int8_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint8_t_int8_t_empty(&heap, &is_empty);
  rc = sfh_uint8_t_int8_t_find_min(&heap, &out_node);

  rc = sfh_uint8_t_int8_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint8_t_int8_t_delete(&heap, &node);
  rc = sfh_uint8_t_int8_t_delete_min(&heap);

  {
    sfh_uint8_t_int8_t_heap_t h1, h2, h3, *merged;
    sfh_uint8_t_int8_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint8_t_int8_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint8_t_int8_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint8_t_int8_t_init(&h3);
    sfh_uint8_t_int8_t_insert(&h1, &n1, 1, 0);
    sfh_uint8_t_int8_t_insert(&h1, &n2, 2, 0);
    sfh_uint8_t_int8_t_insert(&h1, &n3, 3, 0);
    sfh_uint8_t_int8_t_insert(&h1, &n4, 4, 0);
    sfh_uint8_t_int8_t_insert(&h2, &n5, 5, 0);

    sfh_uint8_t_int8_t_meld(&h1, &h2, &merged);
    sfh_uint8_t_int8_t_delete_min(merged);
    sfh_uint8_t_int8_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint8_t_int8_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint8_t_int8_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint8_t_int8_t_insert(&heap, &fnodes[idx],
                                         (uint8_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint8_t_int8_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint8_t_int8_t_decrease_key(&heap, &fnodes[idx], (uint8_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint8_t_int8_t_node_t *min;
          sfh_uint8_t_int8_t_find_min(&heap, &min);
          rc = sfh_uint8_t_int8_t_delete_min(&heap);
          if (rc == sfh_uint8_t_int8_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint8_t_int8_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint8_t_int8_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint8_t_int16_t(void) {
  sfh_uint8_t_int16_t_heap_t heap;
  sfh_uint8_t_int16_t_node_t node, node2;
  sfh_uint8_t_int16_t_node_t *out_node;
  sfh_uint8_t_int16_t_heap_t *out_heap;
  int is_empty;
  sfh_uint8_t_int16_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint8_t_int16_t_init(NULL);
  rc = sfh_uint8_t_int16_t_empty(NULL, &is_empty);
  rc = sfh_uint8_t_int16_t_find_min(NULL, &out_node);
  rc = sfh_uint8_t_int16_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint8_t_int16_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint8_t_int16_t_delete_min(NULL);
  rc = sfh_uint8_t_int16_t_delete(NULL, &node);
  rc = sfh_uint8_t_int16_t_delete(&heap, NULL);
  rc = sfh_uint8_t_int16_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint8_t_int16_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint8_t_int16_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint8_t_int16_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint8_t_int16_t_meld(&heap, &heap, NULL);

  sfh_uint8_t_int16_t_init(&heap);
  rc = sfh_uint8_t_int16_t_empty(&heap, &is_empty);
  rc = sfh_uint8_t_int16_t_find_min(&heap, &out_node);
  rc = sfh_uint8_t_int16_t_delete_min(&heap);

  rc = sfh_uint8_t_int16_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint8_t_int16_t_empty(&heap, &is_empty);
  rc = sfh_uint8_t_int16_t_find_min(&heap, &out_node);

  rc = sfh_uint8_t_int16_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint8_t_int16_t_delete(&heap, &node);
  rc = sfh_uint8_t_int16_t_delete_min(&heap);

  {
    sfh_uint8_t_int16_t_heap_t h1, h2, h3, *merged;
    sfh_uint8_t_int16_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint8_t_int16_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint8_t_int16_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint8_t_int16_t_init(&h3);
    sfh_uint8_t_int16_t_insert(&h1, &n1, 1, 0);
    sfh_uint8_t_int16_t_insert(&h1, &n2, 2, 0);
    sfh_uint8_t_int16_t_insert(&h1, &n3, 3, 0);
    sfh_uint8_t_int16_t_insert(&h1, &n4, 4, 0);
    sfh_uint8_t_int16_t_insert(&h2, &n5, 5, 0);

    sfh_uint8_t_int16_t_meld(&h1, &h2, &merged);
    sfh_uint8_t_int16_t_delete_min(merged);
    sfh_uint8_t_int16_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint8_t_int16_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint8_t_int16_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint8_t_int16_t_insert(&heap, &fnodes[idx],
                                          (uint8_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint8_t_int16_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc =
              sfh_uint8_t_int16_t_decrease_key(&heap, &fnodes[idx], (uint8_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint8_t_int16_t_node_t *min;
          sfh_uint8_t_int16_t_find_min(&heap, &min);
          rc = sfh_uint8_t_int16_t_delete_min(&heap);
          if (rc == sfh_uint8_t_int16_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint8_t_int16_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint8_t_int16_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint8_t_int32_t(void) {
  sfh_uint8_t_int32_t_heap_t heap;
  sfh_uint8_t_int32_t_node_t node, node2;
  sfh_uint8_t_int32_t_node_t *out_node;
  sfh_uint8_t_int32_t_heap_t *out_heap;
  int is_empty;
  sfh_uint8_t_int32_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint8_t_int32_t_init(NULL);
  rc = sfh_uint8_t_int32_t_empty(NULL, &is_empty);
  rc = sfh_uint8_t_int32_t_find_min(NULL, &out_node);
  rc = sfh_uint8_t_int32_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint8_t_int32_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint8_t_int32_t_delete_min(NULL);
  rc = sfh_uint8_t_int32_t_delete(NULL, &node);
  rc = sfh_uint8_t_int32_t_delete(&heap, NULL);
  rc = sfh_uint8_t_int32_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint8_t_int32_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint8_t_int32_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint8_t_int32_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint8_t_int32_t_meld(&heap, &heap, NULL);

  sfh_uint8_t_int32_t_init(&heap);
  rc = sfh_uint8_t_int32_t_empty(&heap, &is_empty);
  rc = sfh_uint8_t_int32_t_find_min(&heap, &out_node);
  rc = sfh_uint8_t_int32_t_delete_min(&heap);

  rc = sfh_uint8_t_int32_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint8_t_int32_t_empty(&heap, &is_empty);
  rc = sfh_uint8_t_int32_t_find_min(&heap, &out_node);

  rc = sfh_uint8_t_int32_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint8_t_int32_t_delete(&heap, &node);
  rc = sfh_uint8_t_int32_t_delete_min(&heap);

  {
    sfh_uint8_t_int32_t_heap_t h1, h2, h3, *merged;
    sfh_uint8_t_int32_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint8_t_int32_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint8_t_int32_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint8_t_int32_t_init(&h3);
    sfh_uint8_t_int32_t_insert(&h1, &n1, 1, 0);
    sfh_uint8_t_int32_t_insert(&h1, &n2, 2, 0);
    sfh_uint8_t_int32_t_insert(&h1, &n3, 3, 0);
    sfh_uint8_t_int32_t_insert(&h1, &n4, 4, 0);
    sfh_uint8_t_int32_t_insert(&h2, &n5, 5, 0);

    sfh_uint8_t_int32_t_meld(&h1, &h2, &merged);
    sfh_uint8_t_int32_t_delete_min(merged);
    sfh_uint8_t_int32_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint8_t_int32_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint8_t_int32_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint8_t_int32_t_insert(&heap, &fnodes[idx],
                                          (uint8_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint8_t_int32_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc =
              sfh_uint8_t_int32_t_decrease_key(&heap, &fnodes[idx], (uint8_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint8_t_int32_t_node_t *min;
          sfh_uint8_t_int32_t_find_min(&heap, &min);
          rc = sfh_uint8_t_int32_t_delete_min(&heap);
          if (rc == sfh_uint8_t_int32_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint8_t_int32_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint8_t_int32_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint8_t_int64_t(void) {
  sfh_uint8_t_int64_t_heap_t heap;
  sfh_uint8_t_int64_t_node_t node, node2;
  sfh_uint8_t_int64_t_node_t *out_node;
  sfh_uint8_t_int64_t_heap_t *out_heap;
  int is_empty;
  sfh_uint8_t_int64_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint8_t_int64_t_init(NULL);
  rc = sfh_uint8_t_int64_t_empty(NULL, &is_empty);
  rc = sfh_uint8_t_int64_t_find_min(NULL, &out_node);
  rc = sfh_uint8_t_int64_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint8_t_int64_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint8_t_int64_t_delete_min(NULL);
  rc = sfh_uint8_t_int64_t_delete(NULL, &node);
  rc = sfh_uint8_t_int64_t_delete(&heap, NULL);
  rc = sfh_uint8_t_int64_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint8_t_int64_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint8_t_int64_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint8_t_int64_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint8_t_int64_t_meld(&heap, &heap, NULL);

  sfh_uint8_t_int64_t_init(&heap);
  rc = sfh_uint8_t_int64_t_empty(&heap, &is_empty);
  rc = sfh_uint8_t_int64_t_find_min(&heap, &out_node);
  rc = sfh_uint8_t_int64_t_delete_min(&heap);

  rc = sfh_uint8_t_int64_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint8_t_int64_t_empty(&heap, &is_empty);
  rc = sfh_uint8_t_int64_t_find_min(&heap, &out_node);

  rc = sfh_uint8_t_int64_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint8_t_int64_t_delete(&heap, &node);
  rc = sfh_uint8_t_int64_t_delete_min(&heap);

  {
    sfh_uint8_t_int64_t_heap_t h1, h2, h3, *merged;
    sfh_uint8_t_int64_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint8_t_int64_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint8_t_int64_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint8_t_int64_t_init(&h3);
    sfh_uint8_t_int64_t_insert(&h1, &n1, 1, 0);
    sfh_uint8_t_int64_t_insert(&h1, &n2, 2, 0);
    sfh_uint8_t_int64_t_insert(&h1, &n3, 3, 0);
    sfh_uint8_t_int64_t_insert(&h1, &n4, 4, 0);
    sfh_uint8_t_int64_t_insert(&h2, &n5, 5, 0);

    sfh_uint8_t_int64_t_meld(&h1, &h2, &merged);
    sfh_uint8_t_int64_t_delete_min(merged);
    sfh_uint8_t_int64_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint8_t_int64_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint8_t_int64_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint8_t_int64_t_insert(&heap, &fnodes[idx],
                                          (uint8_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint8_t_int64_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc =
              sfh_uint8_t_int64_t_decrease_key(&heap, &fnodes[idx], (uint8_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint8_t_int64_t_node_t *min;
          sfh_uint8_t_int64_t_find_min(&heap, &min);
          rc = sfh_uint8_t_int64_t_delete_min(&heap);
          if (rc == sfh_uint8_t_int64_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint8_t_int64_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint8_t_int64_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint8_t_uint8_t(void) {
  sfh_uint8_t_uint8_t_heap_t heap;
  sfh_uint8_t_uint8_t_node_t node, node2;
  sfh_uint8_t_uint8_t_node_t *out_node;
  sfh_uint8_t_uint8_t_heap_t *out_heap;
  int is_empty;
  sfh_uint8_t_uint8_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint8_t_uint8_t_init(NULL);
  rc = sfh_uint8_t_uint8_t_empty(NULL, &is_empty);
  rc = sfh_uint8_t_uint8_t_find_min(NULL, &out_node);
  rc = sfh_uint8_t_uint8_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint8_t_uint8_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint8_t_uint8_t_delete_min(NULL);
  rc = sfh_uint8_t_uint8_t_delete(NULL, &node);
  rc = sfh_uint8_t_uint8_t_delete(&heap, NULL);
  rc = sfh_uint8_t_uint8_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint8_t_uint8_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint8_t_uint8_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint8_t_uint8_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint8_t_uint8_t_meld(&heap, &heap, NULL);

  sfh_uint8_t_uint8_t_init(&heap);
  rc = sfh_uint8_t_uint8_t_empty(&heap, &is_empty);
  rc = sfh_uint8_t_uint8_t_find_min(&heap, &out_node);
  rc = sfh_uint8_t_uint8_t_delete_min(&heap);

  rc = sfh_uint8_t_uint8_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint8_t_uint8_t_empty(&heap, &is_empty);
  rc = sfh_uint8_t_uint8_t_find_min(&heap, &out_node);

  rc = sfh_uint8_t_uint8_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint8_t_uint8_t_delete(&heap, &node);
  rc = sfh_uint8_t_uint8_t_delete_min(&heap);

  {
    sfh_uint8_t_uint8_t_heap_t h1, h2, h3, *merged;
    sfh_uint8_t_uint8_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint8_t_uint8_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint8_t_uint8_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint8_t_uint8_t_init(&h3);
    sfh_uint8_t_uint8_t_insert(&h1, &n1, 1, 0);
    sfh_uint8_t_uint8_t_insert(&h1, &n2, 2, 0);
    sfh_uint8_t_uint8_t_insert(&h1, &n3, 3, 0);
    sfh_uint8_t_uint8_t_insert(&h1, &n4, 4, 0);
    sfh_uint8_t_uint8_t_insert(&h2, &n5, 5, 0);

    sfh_uint8_t_uint8_t_meld(&h1, &h2, &merged);
    sfh_uint8_t_uint8_t_delete_min(merged);
    sfh_uint8_t_uint8_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint8_t_uint8_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint8_t_uint8_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint8_t_uint8_t_insert(&heap, &fnodes[idx],
                                          (uint8_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint8_t_uint8_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc =
              sfh_uint8_t_uint8_t_decrease_key(&heap, &fnodes[idx], (uint8_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint8_t_uint8_t_node_t *min;
          sfh_uint8_t_uint8_t_find_min(&heap, &min);
          rc = sfh_uint8_t_uint8_t_delete_min(&heap);
          if (rc == sfh_uint8_t_uint8_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint8_t_uint8_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint8_t_uint8_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint8_t_uint16_t(void) {
  sfh_uint8_t_uint16_t_heap_t heap;
  sfh_uint8_t_uint16_t_node_t node, node2;
  sfh_uint8_t_uint16_t_node_t *out_node;
  sfh_uint8_t_uint16_t_heap_t *out_heap;
  int is_empty;
  sfh_uint8_t_uint16_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint8_t_uint16_t_init(NULL);
  rc = sfh_uint8_t_uint16_t_empty(NULL, &is_empty);
  rc = sfh_uint8_t_uint16_t_find_min(NULL, &out_node);
  rc = sfh_uint8_t_uint16_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint8_t_uint16_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint8_t_uint16_t_delete_min(NULL);
  rc = sfh_uint8_t_uint16_t_delete(NULL, &node);
  rc = sfh_uint8_t_uint16_t_delete(&heap, NULL);
  rc = sfh_uint8_t_uint16_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint8_t_uint16_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint8_t_uint16_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint8_t_uint16_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint8_t_uint16_t_meld(&heap, &heap, NULL);

  sfh_uint8_t_uint16_t_init(&heap);
  rc = sfh_uint8_t_uint16_t_empty(&heap, &is_empty);
  rc = sfh_uint8_t_uint16_t_find_min(&heap, &out_node);
  rc = sfh_uint8_t_uint16_t_delete_min(&heap);

  rc = sfh_uint8_t_uint16_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint8_t_uint16_t_empty(&heap, &is_empty);
  rc = sfh_uint8_t_uint16_t_find_min(&heap, &out_node);

  rc = sfh_uint8_t_uint16_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint8_t_uint16_t_delete(&heap, &node);
  rc = sfh_uint8_t_uint16_t_delete_min(&heap);

  {
    sfh_uint8_t_uint16_t_heap_t h1, h2, h3, *merged;
    sfh_uint8_t_uint16_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint8_t_uint16_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint8_t_uint16_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint8_t_uint16_t_init(&h3);
    sfh_uint8_t_uint16_t_insert(&h1, &n1, 1, 0);
    sfh_uint8_t_uint16_t_insert(&h1, &n2, 2, 0);
    sfh_uint8_t_uint16_t_insert(&h1, &n3, 3, 0);
    sfh_uint8_t_uint16_t_insert(&h1, &n4, 4, 0);
    sfh_uint8_t_uint16_t_insert(&h2, &n5, 5, 0);

    sfh_uint8_t_uint16_t_meld(&h1, &h2, &merged);
    sfh_uint8_t_uint16_t_delete_min(merged);
    sfh_uint8_t_uint16_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint8_t_uint16_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint8_t_uint16_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint8_t_uint16_t_insert(&heap, &fnodes[idx],
                                           (uint8_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint8_t_uint16_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint8_t_uint16_t_decrease_key(&heap, &fnodes[idx],
                                                 (uint8_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint8_t_uint16_t_node_t *min;
          sfh_uint8_t_uint16_t_find_min(&heap, &min);
          rc = sfh_uint8_t_uint16_t_delete_min(&heap);
          if (rc == sfh_uint8_t_uint16_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint8_t_uint16_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint8_t_uint16_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint8_t_uint32_t(void) {
  sfh_uint8_t_uint32_t_heap_t heap;
  sfh_uint8_t_uint32_t_node_t node, node2;
  sfh_uint8_t_uint32_t_node_t *out_node;
  sfh_uint8_t_uint32_t_heap_t *out_heap;
  int is_empty;
  sfh_uint8_t_uint32_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint8_t_uint32_t_init(NULL);
  rc = sfh_uint8_t_uint32_t_empty(NULL, &is_empty);
  rc = sfh_uint8_t_uint32_t_find_min(NULL, &out_node);
  rc = sfh_uint8_t_uint32_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint8_t_uint32_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint8_t_uint32_t_delete_min(NULL);
  rc = sfh_uint8_t_uint32_t_delete(NULL, &node);
  rc = sfh_uint8_t_uint32_t_delete(&heap, NULL);
  rc = sfh_uint8_t_uint32_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint8_t_uint32_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint8_t_uint32_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint8_t_uint32_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint8_t_uint32_t_meld(&heap, &heap, NULL);

  sfh_uint8_t_uint32_t_init(&heap);
  rc = sfh_uint8_t_uint32_t_empty(&heap, &is_empty);
  rc = sfh_uint8_t_uint32_t_find_min(&heap, &out_node);
  rc = sfh_uint8_t_uint32_t_delete_min(&heap);

  rc = sfh_uint8_t_uint32_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint8_t_uint32_t_empty(&heap, &is_empty);
  rc = sfh_uint8_t_uint32_t_find_min(&heap, &out_node);

  rc = sfh_uint8_t_uint32_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint8_t_uint32_t_delete(&heap, &node);
  rc = sfh_uint8_t_uint32_t_delete_min(&heap);

  {
    sfh_uint8_t_uint32_t_heap_t h1, h2, h3, *merged;
    sfh_uint8_t_uint32_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint8_t_uint32_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint8_t_uint32_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint8_t_uint32_t_init(&h3);
    sfh_uint8_t_uint32_t_insert(&h1, &n1, 1, 0);
    sfh_uint8_t_uint32_t_insert(&h1, &n2, 2, 0);
    sfh_uint8_t_uint32_t_insert(&h1, &n3, 3, 0);
    sfh_uint8_t_uint32_t_insert(&h1, &n4, 4, 0);
    sfh_uint8_t_uint32_t_insert(&h2, &n5, 5, 0);

    sfh_uint8_t_uint32_t_meld(&h1, &h2, &merged);
    sfh_uint8_t_uint32_t_delete_min(merged);
    sfh_uint8_t_uint32_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint8_t_uint32_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint8_t_uint32_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint8_t_uint32_t_insert(&heap, &fnodes[idx],
                                           (uint8_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint8_t_uint32_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint8_t_uint32_t_decrease_key(&heap, &fnodes[idx],
                                                 (uint8_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint8_t_uint32_t_node_t *min;
          sfh_uint8_t_uint32_t_find_min(&heap, &min);
          rc = sfh_uint8_t_uint32_t_delete_min(&heap);
          if (rc == sfh_uint8_t_uint32_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint8_t_uint32_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint8_t_uint32_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint8_t_uint64_t(void) {
  sfh_uint8_t_uint64_t_heap_t heap;
  sfh_uint8_t_uint64_t_node_t node, node2;
  sfh_uint8_t_uint64_t_node_t *out_node;
  sfh_uint8_t_uint64_t_heap_t *out_heap;
  int is_empty;
  sfh_uint8_t_uint64_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint8_t_uint64_t_init(NULL);
  rc = sfh_uint8_t_uint64_t_empty(NULL, &is_empty);
  rc = sfh_uint8_t_uint64_t_find_min(NULL, &out_node);
  rc = sfh_uint8_t_uint64_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint8_t_uint64_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint8_t_uint64_t_delete_min(NULL);
  rc = sfh_uint8_t_uint64_t_delete(NULL, &node);
  rc = sfh_uint8_t_uint64_t_delete(&heap, NULL);
  rc = sfh_uint8_t_uint64_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint8_t_uint64_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint8_t_uint64_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint8_t_uint64_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint8_t_uint64_t_meld(&heap, &heap, NULL);

  sfh_uint8_t_uint64_t_init(&heap);
  rc = sfh_uint8_t_uint64_t_empty(&heap, &is_empty);
  rc = sfh_uint8_t_uint64_t_find_min(&heap, &out_node);
  rc = sfh_uint8_t_uint64_t_delete_min(&heap);

  rc = sfh_uint8_t_uint64_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint8_t_uint64_t_empty(&heap, &is_empty);
  rc = sfh_uint8_t_uint64_t_find_min(&heap, &out_node);

  rc = sfh_uint8_t_uint64_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint8_t_uint64_t_delete(&heap, &node);
  rc = sfh_uint8_t_uint64_t_delete_min(&heap);

  {
    sfh_uint8_t_uint64_t_heap_t h1, h2, h3, *merged;
    sfh_uint8_t_uint64_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint8_t_uint64_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint8_t_uint64_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint8_t_uint64_t_init(&h3);
    sfh_uint8_t_uint64_t_insert(&h1, &n1, 1, 0);
    sfh_uint8_t_uint64_t_insert(&h1, &n2, 2, 0);
    sfh_uint8_t_uint64_t_insert(&h1, &n3, 3, 0);
    sfh_uint8_t_uint64_t_insert(&h1, &n4, 4, 0);
    sfh_uint8_t_uint64_t_insert(&h2, &n5, 5, 0);

    sfh_uint8_t_uint64_t_meld(&h1, &h2, &merged);
    sfh_uint8_t_uint64_t_delete_min(merged);
    sfh_uint8_t_uint64_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint8_t_uint64_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint8_t_uint64_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint8_t_uint64_t_insert(&heap, &fnodes[idx],
                                           (uint8_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint8_t_uint64_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint8_t_uint64_t_decrease_key(&heap, &fnodes[idx],
                                                 (uint8_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint8_t_uint64_t_node_t *min;
          sfh_uint8_t_uint64_t_find_min(&heap, &min);
          rc = sfh_uint8_t_uint64_t_delete_min(&heap);
          if (rc == sfh_uint8_t_uint64_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint8_t_uint64_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint8_t_uint64_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint8_t_float(void) {
  sfh_uint8_t_float_heap_t heap;
  sfh_uint8_t_float_node_t node, node2;
  sfh_uint8_t_float_node_t *out_node;
  sfh_uint8_t_float_heap_t *out_heap;
  int is_empty;
  sfh_uint8_t_float_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint8_t_float_init(NULL);
  rc = sfh_uint8_t_float_empty(NULL, &is_empty);
  rc = sfh_uint8_t_float_find_min(NULL, &out_node);
  rc = sfh_uint8_t_float_insert(NULL, &node, 1, 0);
  rc = sfh_uint8_t_float_insert(&heap, NULL, 1, 0);
  rc = sfh_uint8_t_float_delete_min(NULL);
  rc = sfh_uint8_t_float_delete(NULL, &node);
  rc = sfh_uint8_t_float_delete(&heap, NULL);
  rc = sfh_uint8_t_float_decrease_key(NULL, &node, 1);
  rc = sfh_uint8_t_float_decrease_key(&heap, NULL, 1);
  rc = sfh_uint8_t_float_meld(NULL, &heap, &out_heap);
  rc = sfh_uint8_t_float_meld(&heap, NULL, &out_heap);
  rc = sfh_uint8_t_float_meld(&heap, &heap, NULL);

  sfh_uint8_t_float_init(&heap);
  rc = sfh_uint8_t_float_empty(&heap, &is_empty);
  rc = sfh_uint8_t_float_find_min(&heap, &out_node);
  rc = sfh_uint8_t_float_delete_min(&heap);

  rc = sfh_uint8_t_float_insert(&heap, &node, 10, 0);
  rc = sfh_uint8_t_float_empty(&heap, &is_empty);
  rc = sfh_uint8_t_float_find_min(&heap, &out_node);

  rc = sfh_uint8_t_float_insert(&heap, &node2, 10, 0);
  rc = sfh_uint8_t_float_delete(&heap, &node);
  rc = sfh_uint8_t_float_delete_min(&heap);

  {
    sfh_uint8_t_float_heap_t h1, h2, h3, *merged;
    sfh_uint8_t_float_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint8_t_float_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint8_t_float_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint8_t_float_init(&h3);
    sfh_uint8_t_float_insert(&h1, &n1, 1, 0);
    sfh_uint8_t_float_insert(&h1, &n2, 2, 0);
    sfh_uint8_t_float_insert(&h1, &n3, 3, 0);
    sfh_uint8_t_float_insert(&h1, &n4, 4, 0);
    sfh_uint8_t_float_insert(&h2, &n5, 5, 0);

    sfh_uint8_t_float_meld(&h1, &h2, &merged);
    sfh_uint8_t_float_delete_min(merged);
    sfh_uint8_t_float_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint8_t_float_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint8_t_float_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint8_t_float_insert(&heap, &fnodes[idx],
                                        (uint8_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint8_t_float_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint8_t_float_decrease_key(&heap, &fnodes[idx], (uint8_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint8_t_float_node_t *min;
          sfh_uint8_t_float_find_min(&heap, &min);
          rc = sfh_uint8_t_float_delete_min(&heap);
          if (rc == sfh_uint8_t_float_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint8_t_float_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint8_t_float_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint8_t_double(void) {
  sfh_uint8_t_double_heap_t heap;
  sfh_uint8_t_double_node_t node, node2;
  sfh_uint8_t_double_node_t *out_node;
  sfh_uint8_t_double_heap_t *out_heap;
  int is_empty;
  sfh_uint8_t_double_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint8_t_double_init(NULL);
  rc = sfh_uint8_t_double_empty(NULL, &is_empty);
  rc = sfh_uint8_t_double_find_min(NULL, &out_node);
  rc = sfh_uint8_t_double_insert(NULL, &node, 1, 0);
  rc = sfh_uint8_t_double_insert(&heap, NULL, 1, 0);
  rc = sfh_uint8_t_double_delete_min(NULL);
  rc = sfh_uint8_t_double_delete(NULL, &node);
  rc = sfh_uint8_t_double_delete(&heap, NULL);
  rc = sfh_uint8_t_double_decrease_key(NULL, &node, 1);
  rc = sfh_uint8_t_double_decrease_key(&heap, NULL, 1);
  rc = sfh_uint8_t_double_meld(NULL, &heap, &out_heap);
  rc = sfh_uint8_t_double_meld(&heap, NULL, &out_heap);
  rc = sfh_uint8_t_double_meld(&heap, &heap, NULL);

  sfh_uint8_t_double_init(&heap);
  rc = sfh_uint8_t_double_empty(&heap, &is_empty);
  rc = sfh_uint8_t_double_find_min(&heap, &out_node);
  rc = sfh_uint8_t_double_delete_min(&heap);

  rc = sfh_uint8_t_double_insert(&heap, &node, 10, 0);
  rc = sfh_uint8_t_double_empty(&heap, &is_empty);
  rc = sfh_uint8_t_double_find_min(&heap, &out_node);

  rc = sfh_uint8_t_double_insert(&heap, &node2, 10, 0);
  rc = sfh_uint8_t_double_delete(&heap, &node);
  rc = sfh_uint8_t_double_delete_min(&heap);

  {
    sfh_uint8_t_double_heap_t h1, h2, h3, *merged;
    sfh_uint8_t_double_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint8_t_double_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint8_t_double_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint8_t_double_init(&h3);
    sfh_uint8_t_double_insert(&h1, &n1, 1, 0);
    sfh_uint8_t_double_insert(&h1, &n2, 2, 0);
    sfh_uint8_t_double_insert(&h1, &n3, 3, 0);
    sfh_uint8_t_double_insert(&h1, &n4, 4, 0);
    sfh_uint8_t_double_insert(&h2, &n5, 5, 0);

    sfh_uint8_t_double_meld(&h1, &h2, &merged);
    sfh_uint8_t_double_delete_min(merged);
    sfh_uint8_t_double_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint8_t_double_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint8_t_double_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint8_t_double_insert(&heap, &fnodes[idx],
                                         (uint8_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint8_t_double_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint8_t_double_decrease_key(&heap, &fnodes[idx], (uint8_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint8_t_double_node_t *min;
          sfh_uint8_t_double_find_min(&heap, &min);
          rc = sfh_uint8_t_double_delete_min(&heap);
          if (rc == sfh_uint8_t_double_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint8_t_double_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint8_t_double_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint8_t_charptr(void) {
  sfh_uint8_t_charptr_heap_t heap;
  sfh_uint8_t_charptr_node_t node, node2;
  sfh_uint8_t_charptr_node_t *out_node;
  sfh_uint8_t_charptr_heap_t *out_heap;
  int is_empty;
  sfh_uint8_t_charptr_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint8_t_charptr_init(NULL);
  rc = sfh_uint8_t_charptr_empty(NULL, &is_empty);
  rc = sfh_uint8_t_charptr_find_min(NULL, &out_node);
  rc = sfh_uint8_t_charptr_insert(NULL, &node, 1, 0);
  rc = sfh_uint8_t_charptr_insert(&heap, NULL, 1, 0);
  rc = sfh_uint8_t_charptr_delete_min(NULL);
  rc = sfh_uint8_t_charptr_delete(NULL, &node);
  rc = sfh_uint8_t_charptr_delete(&heap, NULL);
  rc = sfh_uint8_t_charptr_decrease_key(NULL, &node, 1);
  rc = sfh_uint8_t_charptr_decrease_key(&heap, NULL, 1);
  rc = sfh_uint8_t_charptr_meld(NULL, &heap, &out_heap);
  rc = sfh_uint8_t_charptr_meld(&heap, NULL, &out_heap);
  rc = sfh_uint8_t_charptr_meld(&heap, &heap, NULL);

  sfh_uint8_t_charptr_init(&heap);
  rc = sfh_uint8_t_charptr_empty(&heap, &is_empty);
  rc = sfh_uint8_t_charptr_find_min(&heap, &out_node);
  rc = sfh_uint8_t_charptr_delete_min(&heap);

  rc = sfh_uint8_t_charptr_insert(&heap, &node, 10, 0);
  rc = sfh_uint8_t_charptr_empty(&heap, &is_empty);
  rc = sfh_uint8_t_charptr_find_min(&heap, &out_node);

  rc = sfh_uint8_t_charptr_insert(&heap, &node2, 10, 0);
  rc = sfh_uint8_t_charptr_delete(&heap, &node);
  rc = sfh_uint8_t_charptr_delete_min(&heap);

  {
    sfh_uint8_t_charptr_heap_t h1, h2, h3, *merged;
    sfh_uint8_t_charptr_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint8_t_charptr_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint8_t_charptr_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint8_t_charptr_init(&h3);
    sfh_uint8_t_charptr_insert(&h1, &n1, 1, 0);
    sfh_uint8_t_charptr_insert(&h1, &n2, 2, 0);
    sfh_uint8_t_charptr_insert(&h1, &n3, 3, 0);
    sfh_uint8_t_charptr_insert(&h1, &n4, 4, 0);
    sfh_uint8_t_charptr_insert(&h2, &n5, 5, 0);

    sfh_uint8_t_charptr_meld(&h1, &h2, &merged);
    sfh_uint8_t_charptr_delete_min(merged);
    sfh_uint8_t_charptr_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint8_t_charptr_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint8_t_charptr_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint8_t_charptr_insert(&heap, &fnodes[idx],
                                          (uint8_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint8_t_charptr_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc =
              sfh_uint8_t_charptr_decrease_key(&heap, &fnodes[idx], (uint8_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint8_t_charptr_node_t *min;
          sfh_uint8_t_charptr_find_min(&heap, &min);
          rc = sfh_uint8_t_charptr_delete_min(&heap);
          if (rc == sfh_uint8_t_charptr_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint8_t_charptr_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint8_t_charptr_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint8_t_voidptr(void) {
  sfh_uint8_t_voidptr_heap_t heap;
  sfh_uint8_t_voidptr_node_t node, node2;
  sfh_uint8_t_voidptr_node_t *out_node;
  sfh_uint8_t_voidptr_heap_t *out_heap;
  int is_empty;
  sfh_uint8_t_voidptr_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint8_t_voidptr_init(NULL);
  rc = sfh_uint8_t_voidptr_empty(NULL, &is_empty);
  rc = sfh_uint8_t_voidptr_find_min(NULL, &out_node);
  rc = sfh_uint8_t_voidptr_insert(NULL, &node, 1, 0);
  rc = sfh_uint8_t_voidptr_insert(&heap, NULL, 1, 0);
  rc = sfh_uint8_t_voidptr_delete_min(NULL);
  rc = sfh_uint8_t_voidptr_delete(NULL, &node);
  rc = sfh_uint8_t_voidptr_delete(&heap, NULL);
  rc = sfh_uint8_t_voidptr_decrease_key(NULL, &node, 1);
  rc = sfh_uint8_t_voidptr_decrease_key(&heap, NULL, 1);
  rc = sfh_uint8_t_voidptr_meld(NULL, &heap, &out_heap);
  rc = sfh_uint8_t_voidptr_meld(&heap, NULL, &out_heap);
  rc = sfh_uint8_t_voidptr_meld(&heap, &heap, NULL);

  sfh_uint8_t_voidptr_init(&heap);
  rc = sfh_uint8_t_voidptr_empty(&heap, &is_empty);
  rc = sfh_uint8_t_voidptr_find_min(&heap, &out_node);
  rc = sfh_uint8_t_voidptr_delete_min(&heap);

  rc = sfh_uint8_t_voidptr_insert(&heap, &node, 10, 0);
  rc = sfh_uint8_t_voidptr_empty(&heap, &is_empty);
  rc = sfh_uint8_t_voidptr_find_min(&heap, &out_node);

  rc = sfh_uint8_t_voidptr_insert(&heap, &node2, 10, 0);
  rc = sfh_uint8_t_voidptr_delete(&heap, &node);
  rc = sfh_uint8_t_voidptr_delete_min(&heap);

  {
    sfh_uint8_t_voidptr_heap_t h1, h2, h3, *merged;
    sfh_uint8_t_voidptr_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint8_t_voidptr_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint8_t_voidptr_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint8_t_voidptr_init(&h3);
    sfh_uint8_t_voidptr_insert(&h1, &n1, 1, 0);
    sfh_uint8_t_voidptr_insert(&h1, &n2, 2, 0);
    sfh_uint8_t_voidptr_insert(&h1, &n3, 3, 0);
    sfh_uint8_t_voidptr_insert(&h1, &n4, 4, 0);
    sfh_uint8_t_voidptr_insert(&h2, &n5, 5, 0);

    sfh_uint8_t_voidptr_meld(&h1, &h2, &merged);
    sfh_uint8_t_voidptr_delete_min(merged);
    sfh_uint8_t_voidptr_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint8_t_voidptr_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint8_t_voidptr_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint8_t_voidptr_insert(&heap, &fnodes[idx],
                                          (uint8_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint8_t_voidptr_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc =
              sfh_uint8_t_voidptr_decrease_key(&heap, &fnodes[idx], (uint8_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint8_t_voidptr_node_t *min;
          sfh_uint8_t_voidptr_find_min(&heap, &min);
          rc = sfh_uint8_t_voidptr_delete_min(&heap);
          if (rc == sfh_uint8_t_voidptr_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint8_t_voidptr_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint8_t_voidptr_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint16_t_int8_t(void) {
  sfh_uint16_t_int8_t_heap_t heap;
  sfh_uint16_t_int8_t_node_t node, node2;
  sfh_uint16_t_int8_t_node_t *out_node;
  sfh_uint16_t_int8_t_heap_t *out_heap;
  int is_empty;
  sfh_uint16_t_int8_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint16_t_int8_t_init(NULL);
  rc = sfh_uint16_t_int8_t_empty(NULL, &is_empty);
  rc = sfh_uint16_t_int8_t_find_min(NULL, &out_node);
  rc = sfh_uint16_t_int8_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint16_t_int8_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint16_t_int8_t_delete_min(NULL);
  rc = sfh_uint16_t_int8_t_delete(NULL, &node);
  rc = sfh_uint16_t_int8_t_delete(&heap, NULL);
  rc = sfh_uint16_t_int8_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint16_t_int8_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint16_t_int8_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint16_t_int8_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint16_t_int8_t_meld(&heap, &heap, NULL);

  sfh_uint16_t_int8_t_init(&heap);
  rc = sfh_uint16_t_int8_t_empty(&heap, &is_empty);
  rc = sfh_uint16_t_int8_t_find_min(&heap, &out_node);
  rc = sfh_uint16_t_int8_t_delete_min(&heap);

  rc = sfh_uint16_t_int8_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint16_t_int8_t_empty(&heap, &is_empty);
  rc = sfh_uint16_t_int8_t_find_min(&heap, &out_node);

  rc = sfh_uint16_t_int8_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint16_t_int8_t_delete(&heap, &node);
  rc = sfh_uint16_t_int8_t_delete_min(&heap);

  {
    sfh_uint16_t_int8_t_heap_t h1, h2, h3, *merged;
    sfh_uint16_t_int8_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint16_t_int8_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint16_t_int8_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint16_t_int8_t_init(&h3);
    sfh_uint16_t_int8_t_insert(&h1, &n1, 1, 0);
    sfh_uint16_t_int8_t_insert(&h1, &n2, 2, 0);
    sfh_uint16_t_int8_t_insert(&h1, &n3, 3, 0);
    sfh_uint16_t_int8_t_insert(&h1, &n4, 4, 0);
    sfh_uint16_t_int8_t_insert(&h2, &n5, 5, 0);

    sfh_uint16_t_int8_t_meld(&h1, &h2, &merged);
    sfh_uint16_t_int8_t_delete_min(merged);
    sfh_uint16_t_int8_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint16_t_int8_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint16_t_int8_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint16_t_int8_t_insert(&heap, &fnodes[idx],
                                          (uint16_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint16_t_int8_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint16_t_int8_t_decrease_key(&heap, &fnodes[idx],
                                                (uint16_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint16_t_int8_t_node_t *min;
          sfh_uint16_t_int8_t_find_min(&heap, &min);
          rc = sfh_uint16_t_int8_t_delete_min(&heap);
          if (rc == sfh_uint16_t_int8_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint16_t_int8_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint16_t_int8_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint16_t_int16_t(void) {
  sfh_uint16_t_int16_t_heap_t heap;
  sfh_uint16_t_int16_t_node_t node, node2;
  sfh_uint16_t_int16_t_node_t *out_node;
  sfh_uint16_t_int16_t_heap_t *out_heap;
  int is_empty;
  sfh_uint16_t_int16_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint16_t_int16_t_init(NULL);
  rc = sfh_uint16_t_int16_t_empty(NULL, &is_empty);
  rc = sfh_uint16_t_int16_t_find_min(NULL, &out_node);
  rc = sfh_uint16_t_int16_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint16_t_int16_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint16_t_int16_t_delete_min(NULL);
  rc = sfh_uint16_t_int16_t_delete(NULL, &node);
  rc = sfh_uint16_t_int16_t_delete(&heap, NULL);
  rc = sfh_uint16_t_int16_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint16_t_int16_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint16_t_int16_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint16_t_int16_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint16_t_int16_t_meld(&heap, &heap, NULL);

  sfh_uint16_t_int16_t_init(&heap);
  rc = sfh_uint16_t_int16_t_empty(&heap, &is_empty);
  rc = sfh_uint16_t_int16_t_find_min(&heap, &out_node);
  rc = sfh_uint16_t_int16_t_delete_min(&heap);

  rc = sfh_uint16_t_int16_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint16_t_int16_t_empty(&heap, &is_empty);
  rc = sfh_uint16_t_int16_t_find_min(&heap, &out_node);

  rc = sfh_uint16_t_int16_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint16_t_int16_t_delete(&heap, &node);
  rc = sfh_uint16_t_int16_t_delete_min(&heap);

  {
    sfh_uint16_t_int16_t_heap_t h1, h2, h3, *merged;
    sfh_uint16_t_int16_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint16_t_int16_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint16_t_int16_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint16_t_int16_t_init(&h3);
    sfh_uint16_t_int16_t_insert(&h1, &n1, 1, 0);
    sfh_uint16_t_int16_t_insert(&h1, &n2, 2, 0);
    sfh_uint16_t_int16_t_insert(&h1, &n3, 3, 0);
    sfh_uint16_t_int16_t_insert(&h1, &n4, 4, 0);
    sfh_uint16_t_int16_t_insert(&h2, &n5, 5, 0);

    sfh_uint16_t_int16_t_meld(&h1, &h2, &merged);
    sfh_uint16_t_int16_t_delete_min(merged);
    sfh_uint16_t_int16_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint16_t_int16_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint16_t_int16_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint16_t_int16_t_insert(&heap, &fnodes[idx],
                                           (uint16_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint16_t_int16_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint16_t_int16_t_decrease_key(&heap, &fnodes[idx],
                                                 (uint16_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint16_t_int16_t_node_t *min;
          sfh_uint16_t_int16_t_find_min(&heap, &min);
          rc = sfh_uint16_t_int16_t_delete_min(&heap);
          if (rc == sfh_uint16_t_int16_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint16_t_int16_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint16_t_int16_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint16_t_int32_t(void) {
  sfh_uint16_t_int32_t_heap_t heap;
  sfh_uint16_t_int32_t_node_t node, node2;
  sfh_uint16_t_int32_t_node_t *out_node;
  sfh_uint16_t_int32_t_heap_t *out_heap;
  int is_empty;
  sfh_uint16_t_int32_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint16_t_int32_t_init(NULL);
  rc = sfh_uint16_t_int32_t_empty(NULL, &is_empty);
  rc = sfh_uint16_t_int32_t_find_min(NULL, &out_node);
  rc = sfh_uint16_t_int32_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint16_t_int32_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint16_t_int32_t_delete_min(NULL);
  rc = sfh_uint16_t_int32_t_delete(NULL, &node);
  rc = sfh_uint16_t_int32_t_delete(&heap, NULL);
  rc = sfh_uint16_t_int32_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint16_t_int32_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint16_t_int32_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint16_t_int32_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint16_t_int32_t_meld(&heap, &heap, NULL);

  sfh_uint16_t_int32_t_init(&heap);
  rc = sfh_uint16_t_int32_t_empty(&heap, &is_empty);
  rc = sfh_uint16_t_int32_t_find_min(&heap, &out_node);
  rc = sfh_uint16_t_int32_t_delete_min(&heap);

  rc = sfh_uint16_t_int32_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint16_t_int32_t_empty(&heap, &is_empty);
  rc = sfh_uint16_t_int32_t_find_min(&heap, &out_node);

  rc = sfh_uint16_t_int32_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint16_t_int32_t_delete(&heap, &node);
  rc = sfh_uint16_t_int32_t_delete_min(&heap);

  {
    sfh_uint16_t_int32_t_heap_t h1, h2, h3, *merged;
    sfh_uint16_t_int32_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint16_t_int32_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint16_t_int32_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint16_t_int32_t_init(&h3);
    sfh_uint16_t_int32_t_insert(&h1, &n1, 1, 0);
    sfh_uint16_t_int32_t_insert(&h1, &n2, 2, 0);
    sfh_uint16_t_int32_t_insert(&h1, &n3, 3, 0);
    sfh_uint16_t_int32_t_insert(&h1, &n4, 4, 0);
    sfh_uint16_t_int32_t_insert(&h2, &n5, 5, 0);

    sfh_uint16_t_int32_t_meld(&h1, &h2, &merged);
    sfh_uint16_t_int32_t_delete_min(merged);
    sfh_uint16_t_int32_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint16_t_int32_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint16_t_int32_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint16_t_int32_t_insert(&heap, &fnodes[idx],
                                           (uint16_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint16_t_int32_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint16_t_int32_t_decrease_key(&heap, &fnodes[idx],
                                                 (uint16_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint16_t_int32_t_node_t *min;
          sfh_uint16_t_int32_t_find_min(&heap, &min);
          rc = sfh_uint16_t_int32_t_delete_min(&heap);
          if (rc == sfh_uint16_t_int32_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint16_t_int32_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint16_t_int32_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint16_t_int64_t(void) {
  sfh_uint16_t_int64_t_heap_t heap;
  sfh_uint16_t_int64_t_node_t node, node2;
  sfh_uint16_t_int64_t_node_t *out_node;
  sfh_uint16_t_int64_t_heap_t *out_heap;
  int is_empty;
  sfh_uint16_t_int64_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint16_t_int64_t_init(NULL);
  rc = sfh_uint16_t_int64_t_empty(NULL, &is_empty);
  rc = sfh_uint16_t_int64_t_find_min(NULL, &out_node);
  rc = sfh_uint16_t_int64_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint16_t_int64_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint16_t_int64_t_delete_min(NULL);
  rc = sfh_uint16_t_int64_t_delete(NULL, &node);
  rc = sfh_uint16_t_int64_t_delete(&heap, NULL);
  rc = sfh_uint16_t_int64_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint16_t_int64_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint16_t_int64_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint16_t_int64_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint16_t_int64_t_meld(&heap, &heap, NULL);

  sfh_uint16_t_int64_t_init(&heap);
  rc = sfh_uint16_t_int64_t_empty(&heap, &is_empty);
  rc = sfh_uint16_t_int64_t_find_min(&heap, &out_node);
  rc = sfh_uint16_t_int64_t_delete_min(&heap);

  rc = sfh_uint16_t_int64_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint16_t_int64_t_empty(&heap, &is_empty);
  rc = sfh_uint16_t_int64_t_find_min(&heap, &out_node);

  rc = sfh_uint16_t_int64_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint16_t_int64_t_delete(&heap, &node);
  rc = sfh_uint16_t_int64_t_delete_min(&heap);

  {
    sfh_uint16_t_int64_t_heap_t h1, h2, h3, *merged;
    sfh_uint16_t_int64_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint16_t_int64_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint16_t_int64_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint16_t_int64_t_init(&h3);
    sfh_uint16_t_int64_t_insert(&h1, &n1, 1, 0);
    sfh_uint16_t_int64_t_insert(&h1, &n2, 2, 0);
    sfh_uint16_t_int64_t_insert(&h1, &n3, 3, 0);
    sfh_uint16_t_int64_t_insert(&h1, &n4, 4, 0);
    sfh_uint16_t_int64_t_insert(&h2, &n5, 5, 0);

    sfh_uint16_t_int64_t_meld(&h1, &h2, &merged);
    sfh_uint16_t_int64_t_delete_min(merged);
    sfh_uint16_t_int64_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint16_t_int64_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint16_t_int64_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint16_t_int64_t_insert(&heap, &fnodes[idx],
                                           (uint16_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint16_t_int64_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint16_t_int64_t_decrease_key(&heap, &fnodes[idx],
                                                 (uint16_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint16_t_int64_t_node_t *min;
          sfh_uint16_t_int64_t_find_min(&heap, &min);
          rc = sfh_uint16_t_int64_t_delete_min(&heap);
          if (rc == sfh_uint16_t_int64_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint16_t_int64_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint16_t_int64_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint16_t_uint8_t(void) {
  sfh_uint16_t_uint8_t_heap_t heap;
  sfh_uint16_t_uint8_t_node_t node, node2;
  sfh_uint16_t_uint8_t_node_t *out_node;
  sfh_uint16_t_uint8_t_heap_t *out_heap;
  int is_empty;
  sfh_uint16_t_uint8_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint16_t_uint8_t_init(NULL);
  rc = sfh_uint16_t_uint8_t_empty(NULL, &is_empty);
  rc = sfh_uint16_t_uint8_t_find_min(NULL, &out_node);
  rc = sfh_uint16_t_uint8_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint16_t_uint8_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint16_t_uint8_t_delete_min(NULL);
  rc = sfh_uint16_t_uint8_t_delete(NULL, &node);
  rc = sfh_uint16_t_uint8_t_delete(&heap, NULL);
  rc = sfh_uint16_t_uint8_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint16_t_uint8_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint16_t_uint8_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint16_t_uint8_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint16_t_uint8_t_meld(&heap, &heap, NULL);

  sfh_uint16_t_uint8_t_init(&heap);
  rc = sfh_uint16_t_uint8_t_empty(&heap, &is_empty);
  rc = sfh_uint16_t_uint8_t_find_min(&heap, &out_node);
  rc = sfh_uint16_t_uint8_t_delete_min(&heap);

  rc = sfh_uint16_t_uint8_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint16_t_uint8_t_empty(&heap, &is_empty);
  rc = sfh_uint16_t_uint8_t_find_min(&heap, &out_node);

  rc = sfh_uint16_t_uint8_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint16_t_uint8_t_delete(&heap, &node);
  rc = sfh_uint16_t_uint8_t_delete_min(&heap);

  {
    sfh_uint16_t_uint8_t_heap_t h1, h2, h3, *merged;
    sfh_uint16_t_uint8_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint16_t_uint8_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint16_t_uint8_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint16_t_uint8_t_init(&h3);
    sfh_uint16_t_uint8_t_insert(&h1, &n1, 1, 0);
    sfh_uint16_t_uint8_t_insert(&h1, &n2, 2, 0);
    sfh_uint16_t_uint8_t_insert(&h1, &n3, 3, 0);
    sfh_uint16_t_uint8_t_insert(&h1, &n4, 4, 0);
    sfh_uint16_t_uint8_t_insert(&h2, &n5, 5, 0);

    sfh_uint16_t_uint8_t_meld(&h1, &h2, &merged);
    sfh_uint16_t_uint8_t_delete_min(merged);
    sfh_uint16_t_uint8_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint16_t_uint8_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint16_t_uint8_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint16_t_uint8_t_insert(&heap, &fnodes[idx],
                                           (uint16_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint16_t_uint8_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint16_t_uint8_t_decrease_key(&heap, &fnodes[idx],
                                                 (uint16_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint16_t_uint8_t_node_t *min;
          sfh_uint16_t_uint8_t_find_min(&heap, &min);
          rc = sfh_uint16_t_uint8_t_delete_min(&heap);
          if (rc == sfh_uint16_t_uint8_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint16_t_uint8_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint16_t_uint8_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint16_t_uint16_t(void) {
  sfh_uint16_t_uint16_t_heap_t heap;
  sfh_uint16_t_uint16_t_node_t node, node2;
  sfh_uint16_t_uint16_t_node_t *out_node;
  sfh_uint16_t_uint16_t_heap_t *out_heap;
  int is_empty;
  sfh_uint16_t_uint16_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint16_t_uint16_t_init(NULL);
  rc = sfh_uint16_t_uint16_t_empty(NULL, &is_empty);
  rc = sfh_uint16_t_uint16_t_find_min(NULL, &out_node);
  rc = sfh_uint16_t_uint16_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint16_t_uint16_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint16_t_uint16_t_delete_min(NULL);
  rc = sfh_uint16_t_uint16_t_delete(NULL, &node);
  rc = sfh_uint16_t_uint16_t_delete(&heap, NULL);
  rc = sfh_uint16_t_uint16_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint16_t_uint16_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint16_t_uint16_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint16_t_uint16_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint16_t_uint16_t_meld(&heap, &heap, NULL);

  sfh_uint16_t_uint16_t_init(&heap);
  rc = sfh_uint16_t_uint16_t_empty(&heap, &is_empty);
  rc = sfh_uint16_t_uint16_t_find_min(&heap, &out_node);
  rc = sfh_uint16_t_uint16_t_delete_min(&heap);

  rc = sfh_uint16_t_uint16_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint16_t_uint16_t_empty(&heap, &is_empty);
  rc = sfh_uint16_t_uint16_t_find_min(&heap, &out_node);

  rc = sfh_uint16_t_uint16_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint16_t_uint16_t_delete(&heap, &node);
  rc = sfh_uint16_t_uint16_t_delete_min(&heap);

  {
    sfh_uint16_t_uint16_t_heap_t h1, h2, h3, *merged;
    sfh_uint16_t_uint16_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint16_t_uint16_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint16_t_uint16_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint16_t_uint16_t_init(&h3);
    sfh_uint16_t_uint16_t_insert(&h1, &n1, 1, 0);
    sfh_uint16_t_uint16_t_insert(&h1, &n2, 2, 0);
    sfh_uint16_t_uint16_t_insert(&h1, &n3, 3, 0);
    sfh_uint16_t_uint16_t_insert(&h1, &n4, 4, 0);
    sfh_uint16_t_uint16_t_insert(&h2, &n5, 5, 0);

    sfh_uint16_t_uint16_t_meld(&h1, &h2, &merged);
    sfh_uint16_t_uint16_t_delete_min(merged);
    sfh_uint16_t_uint16_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint16_t_uint16_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint16_t_uint16_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint16_t_uint16_t_insert(&heap, &fnodes[idx],
                                            (uint16_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint16_t_uint16_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint16_t_uint16_t_decrease_key(&heap, &fnodes[idx],
                                                  (uint16_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint16_t_uint16_t_node_t *min;
          sfh_uint16_t_uint16_t_find_min(&heap, &min);
          rc = sfh_uint16_t_uint16_t_delete_min(&heap);
          if (rc == sfh_uint16_t_uint16_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint16_t_uint16_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint16_t_uint16_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint16_t_uint32_t(void) {
  sfh_uint16_t_uint32_t_heap_t heap;
  sfh_uint16_t_uint32_t_node_t node, node2;
  sfh_uint16_t_uint32_t_node_t *out_node;
  sfh_uint16_t_uint32_t_heap_t *out_heap;
  int is_empty;
  sfh_uint16_t_uint32_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint16_t_uint32_t_init(NULL);
  rc = sfh_uint16_t_uint32_t_empty(NULL, &is_empty);
  rc = sfh_uint16_t_uint32_t_find_min(NULL, &out_node);
  rc = sfh_uint16_t_uint32_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint16_t_uint32_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint16_t_uint32_t_delete_min(NULL);
  rc = sfh_uint16_t_uint32_t_delete(NULL, &node);
  rc = sfh_uint16_t_uint32_t_delete(&heap, NULL);
  rc = sfh_uint16_t_uint32_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint16_t_uint32_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint16_t_uint32_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint16_t_uint32_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint16_t_uint32_t_meld(&heap, &heap, NULL);

  sfh_uint16_t_uint32_t_init(&heap);
  rc = sfh_uint16_t_uint32_t_empty(&heap, &is_empty);
  rc = sfh_uint16_t_uint32_t_find_min(&heap, &out_node);
  rc = sfh_uint16_t_uint32_t_delete_min(&heap);

  rc = sfh_uint16_t_uint32_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint16_t_uint32_t_empty(&heap, &is_empty);
  rc = sfh_uint16_t_uint32_t_find_min(&heap, &out_node);

  rc = sfh_uint16_t_uint32_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint16_t_uint32_t_delete(&heap, &node);
  rc = sfh_uint16_t_uint32_t_delete_min(&heap);

  {
    sfh_uint16_t_uint32_t_heap_t h1, h2, h3, *merged;
    sfh_uint16_t_uint32_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint16_t_uint32_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint16_t_uint32_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint16_t_uint32_t_init(&h3);
    sfh_uint16_t_uint32_t_insert(&h1, &n1, 1, 0);
    sfh_uint16_t_uint32_t_insert(&h1, &n2, 2, 0);
    sfh_uint16_t_uint32_t_insert(&h1, &n3, 3, 0);
    sfh_uint16_t_uint32_t_insert(&h1, &n4, 4, 0);
    sfh_uint16_t_uint32_t_insert(&h2, &n5, 5, 0);

    sfh_uint16_t_uint32_t_meld(&h1, &h2, &merged);
    sfh_uint16_t_uint32_t_delete_min(merged);
    sfh_uint16_t_uint32_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint16_t_uint32_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint16_t_uint32_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint16_t_uint32_t_insert(&heap, &fnodes[idx],
                                            (uint16_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint16_t_uint32_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint16_t_uint32_t_decrease_key(&heap, &fnodes[idx],
                                                  (uint16_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint16_t_uint32_t_node_t *min;
          sfh_uint16_t_uint32_t_find_min(&heap, &min);
          rc = sfh_uint16_t_uint32_t_delete_min(&heap);
          if (rc == sfh_uint16_t_uint32_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint16_t_uint32_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint16_t_uint32_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint16_t_uint64_t(void) {
  sfh_uint16_t_uint64_t_heap_t heap;
  sfh_uint16_t_uint64_t_node_t node, node2;
  sfh_uint16_t_uint64_t_node_t *out_node;
  sfh_uint16_t_uint64_t_heap_t *out_heap;
  int is_empty;
  sfh_uint16_t_uint64_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint16_t_uint64_t_init(NULL);
  rc = sfh_uint16_t_uint64_t_empty(NULL, &is_empty);
  rc = sfh_uint16_t_uint64_t_find_min(NULL, &out_node);
  rc = sfh_uint16_t_uint64_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint16_t_uint64_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint16_t_uint64_t_delete_min(NULL);
  rc = sfh_uint16_t_uint64_t_delete(NULL, &node);
  rc = sfh_uint16_t_uint64_t_delete(&heap, NULL);
  rc = sfh_uint16_t_uint64_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint16_t_uint64_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint16_t_uint64_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint16_t_uint64_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint16_t_uint64_t_meld(&heap, &heap, NULL);

  sfh_uint16_t_uint64_t_init(&heap);
  rc = sfh_uint16_t_uint64_t_empty(&heap, &is_empty);
  rc = sfh_uint16_t_uint64_t_find_min(&heap, &out_node);
  rc = sfh_uint16_t_uint64_t_delete_min(&heap);

  rc = sfh_uint16_t_uint64_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint16_t_uint64_t_empty(&heap, &is_empty);
  rc = sfh_uint16_t_uint64_t_find_min(&heap, &out_node);

  rc = sfh_uint16_t_uint64_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint16_t_uint64_t_delete(&heap, &node);
  rc = sfh_uint16_t_uint64_t_delete_min(&heap);

  {
    sfh_uint16_t_uint64_t_heap_t h1, h2, h3, *merged;
    sfh_uint16_t_uint64_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint16_t_uint64_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint16_t_uint64_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint16_t_uint64_t_init(&h3);
    sfh_uint16_t_uint64_t_insert(&h1, &n1, 1, 0);
    sfh_uint16_t_uint64_t_insert(&h1, &n2, 2, 0);
    sfh_uint16_t_uint64_t_insert(&h1, &n3, 3, 0);
    sfh_uint16_t_uint64_t_insert(&h1, &n4, 4, 0);
    sfh_uint16_t_uint64_t_insert(&h2, &n5, 5, 0);

    sfh_uint16_t_uint64_t_meld(&h1, &h2, &merged);
    sfh_uint16_t_uint64_t_delete_min(merged);
    sfh_uint16_t_uint64_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint16_t_uint64_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint16_t_uint64_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint16_t_uint64_t_insert(&heap, &fnodes[idx],
                                            (uint16_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint16_t_uint64_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint16_t_uint64_t_decrease_key(&heap, &fnodes[idx],
                                                  (uint16_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint16_t_uint64_t_node_t *min;
          sfh_uint16_t_uint64_t_find_min(&heap, &min);
          rc = sfh_uint16_t_uint64_t_delete_min(&heap);
          if (rc == sfh_uint16_t_uint64_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint16_t_uint64_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint16_t_uint64_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint16_t_float(void) {
  sfh_uint16_t_float_heap_t heap;
  sfh_uint16_t_float_node_t node, node2;
  sfh_uint16_t_float_node_t *out_node;
  sfh_uint16_t_float_heap_t *out_heap;
  int is_empty;
  sfh_uint16_t_float_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint16_t_float_init(NULL);
  rc = sfh_uint16_t_float_empty(NULL, &is_empty);
  rc = sfh_uint16_t_float_find_min(NULL, &out_node);
  rc = sfh_uint16_t_float_insert(NULL, &node, 1, 0);
  rc = sfh_uint16_t_float_insert(&heap, NULL, 1, 0);
  rc = sfh_uint16_t_float_delete_min(NULL);
  rc = sfh_uint16_t_float_delete(NULL, &node);
  rc = sfh_uint16_t_float_delete(&heap, NULL);
  rc = sfh_uint16_t_float_decrease_key(NULL, &node, 1);
  rc = sfh_uint16_t_float_decrease_key(&heap, NULL, 1);
  rc = sfh_uint16_t_float_meld(NULL, &heap, &out_heap);
  rc = sfh_uint16_t_float_meld(&heap, NULL, &out_heap);
  rc = sfh_uint16_t_float_meld(&heap, &heap, NULL);

  sfh_uint16_t_float_init(&heap);
  rc = sfh_uint16_t_float_empty(&heap, &is_empty);
  rc = sfh_uint16_t_float_find_min(&heap, &out_node);
  rc = sfh_uint16_t_float_delete_min(&heap);

  rc = sfh_uint16_t_float_insert(&heap, &node, 10, 0);
  rc = sfh_uint16_t_float_empty(&heap, &is_empty);
  rc = sfh_uint16_t_float_find_min(&heap, &out_node);

  rc = sfh_uint16_t_float_insert(&heap, &node2, 10, 0);
  rc = sfh_uint16_t_float_delete(&heap, &node);
  rc = sfh_uint16_t_float_delete_min(&heap);

  {
    sfh_uint16_t_float_heap_t h1, h2, h3, *merged;
    sfh_uint16_t_float_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint16_t_float_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint16_t_float_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint16_t_float_init(&h3);
    sfh_uint16_t_float_insert(&h1, &n1, 1, 0);
    sfh_uint16_t_float_insert(&h1, &n2, 2, 0);
    sfh_uint16_t_float_insert(&h1, &n3, 3, 0);
    sfh_uint16_t_float_insert(&h1, &n4, 4, 0);
    sfh_uint16_t_float_insert(&h2, &n5, 5, 0);

    sfh_uint16_t_float_meld(&h1, &h2, &merged);
    sfh_uint16_t_float_delete_min(merged);
    sfh_uint16_t_float_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint16_t_float_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint16_t_float_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint16_t_float_insert(&heap, &fnodes[idx],
                                         (uint16_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint16_t_float_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc =
              sfh_uint16_t_float_decrease_key(&heap, &fnodes[idx], (uint16_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint16_t_float_node_t *min;
          sfh_uint16_t_float_find_min(&heap, &min);
          rc = sfh_uint16_t_float_delete_min(&heap);
          if (rc == sfh_uint16_t_float_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint16_t_float_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint16_t_float_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint16_t_double(void) {
  sfh_uint16_t_double_heap_t heap;
  sfh_uint16_t_double_node_t node, node2;
  sfh_uint16_t_double_node_t *out_node;
  sfh_uint16_t_double_heap_t *out_heap;
  int is_empty;
  sfh_uint16_t_double_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint16_t_double_init(NULL);
  rc = sfh_uint16_t_double_empty(NULL, &is_empty);
  rc = sfh_uint16_t_double_find_min(NULL, &out_node);
  rc = sfh_uint16_t_double_insert(NULL, &node, 1, 0);
  rc = sfh_uint16_t_double_insert(&heap, NULL, 1, 0);
  rc = sfh_uint16_t_double_delete_min(NULL);
  rc = sfh_uint16_t_double_delete(NULL, &node);
  rc = sfh_uint16_t_double_delete(&heap, NULL);
  rc = sfh_uint16_t_double_decrease_key(NULL, &node, 1);
  rc = sfh_uint16_t_double_decrease_key(&heap, NULL, 1);
  rc = sfh_uint16_t_double_meld(NULL, &heap, &out_heap);
  rc = sfh_uint16_t_double_meld(&heap, NULL, &out_heap);
  rc = sfh_uint16_t_double_meld(&heap, &heap, NULL);

  sfh_uint16_t_double_init(&heap);
  rc = sfh_uint16_t_double_empty(&heap, &is_empty);
  rc = sfh_uint16_t_double_find_min(&heap, &out_node);
  rc = sfh_uint16_t_double_delete_min(&heap);

  rc = sfh_uint16_t_double_insert(&heap, &node, 10, 0);
  rc = sfh_uint16_t_double_empty(&heap, &is_empty);
  rc = sfh_uint16_t_double_find_min(&heap, &out_node);

  rc = sfh_uint16_t_double_insert(&heap, &node2, 10, 0);
  rc = sfh_uint16_t_double_delete(&heap, &node);
  rc = sfh_uint16_t_double_delete_min(&heap);

  {
    sfh_uint16_t_double_heap_t h1, h2, h3, *merged;
    sfh_uint16_t_double_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint16_t_double_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint16_t_double_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint16_t_double_init(&h3);
    sfh_uint16_t_double_insert(&h1, &n1, 1, 0);
    sfh_uint16_t_double_insert(&h1, &n2, 2, 0);
    sfh_uint16_t_double_insert(&h1, &n3, 3, 0);
    sfh_uint16_t_double_insert(&h1, &n4, 4, 0);
    sfh_uint16_t_double_insert(&h2, &n5, 5, 0);

    sfh_uint16_t_double_meld(&h1, &h2, &merged);
    sfh_uint16_t_double_delete_min(merged);
    sfh_uint16_t_double_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint16_t_double_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint16_t_double_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint16_t_double_insert(&heap, &fnodes[idx],
                                          (uint16_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint16_t_double_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint16_t_double_decrease_key(&heap, &fnodes[idx],
                                                (uint16_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint16_t_double_node_t *min;
          sfh_uint16_t_double_find_min(&heap, &min);
          rc = sfh_uint16_t_double_delete_min(&heap);
          if (rc == sfh_uint16_t_double_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint16_t_double_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint16_t_double_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint16_t_charptr(void) {
  sfh_uint16_t_charptr_heap_t heap;
  sfh_uint16_t_charptr_node_t node, node2;
  sfh_uint16_t_charptr_node_t *out_node;
  sfh_uint16_t_charptr_heap_t *out_heap;
  int is_empty;
  sfh_uint16_t_charptr_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint16_t_charptr_init(NULL);
  rc = sfh_uint16_t_charptr_empty(NULL, &is_empty);
  rc = sfh_uint16_t_charptr_find_min(NULL, &out_node);
  rc = sfh_uint16_t_charptr_insert(NULL, &node, 1, 0);
  rc = sfh_uint16_t_charptr_insert(&heap, NULL, 1, 0);
  rc = sfh_uint16_t_charptr_delete_min(NULL);
  rc = sfh_uint16_t_charptr_delete(NULL, &node);
  rc = sfh_uint16_t_charptr_delete(&heap, NULL);
  rc = sfh_uint16_t_charptr_decrease_key(NULL, &node, 1);
  rc = sfh_uint16_t_charptr_decrease_key(&heap, NULL, 1);
  rc = sfh_uint16_t_charptr_meld(NULL, &heap, &out_heap);
  rc = sfh_uint16_t_charptr_meld(&heap, NULL, &out_heap);
  rc = sfh_uint16_t_charptr_meld(&heap, &heap, NULL);

  sfh_uint16_t_charptr_init(&heap);
  rc = sfh_uint16_t_charptr_empty(&heap, &is_empty);
  rc = sfh_uint16_t_charptr_find_min(&heap, &out_node);
  rc = sfh_uint16_t_charptr_delete_min(&heap);

  rc = sfh_uint16_t_charptr_insert(&heap, &node, 10, 0);
  rc = sfh_uint16_t_charptr_empty(&heap, &is_empty);
  rc = sfh_uint16_t_charptr_find_min(&heap, &out_node);

  rc = sfh_uint16_t_charptr_insert(&heap, &node2, 10, 0);
  rc = sfh_uint16_t_charptr_delete(&heap, &node);
  rc = sfh_uint16_t_charptr_delete_min(&heap);

  {
    sfh_uint16_t_charptr_heap_t h1, h2, h3, *merged;
    sfh_uint16_t_charptr_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint16_t_charptr_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint16_t_charptr_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint16_t_charptr_init(&h3);
    sfh_uint16_t_charptr_insert(&h1, &n1, 1, 0);
    sfh_uint16_t_charptr_insert(&h1, &n2, 2, 0);
    sfh_uint16_t_charptr_insert(&h1, &n3, 3, 0);
    sfh_uint16_t_charptr_insert(&h1, &n4, 4, 0);
    sfh_uint16_t_charptr_insert(&h2, &n5, 5, 0);

    sfh_uint16_t_charptr_meld(&h1, &h2, &merged);
    sfh_uint16_t_charptr_delete_min(merged);
    sfh_uint16_t_charptr_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint16_t_charptr_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint16_t_charptr_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint16_t_charptr_insert(&heap, &fnodes[idx],
                                           (uint16_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint16_t_charptr_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint16_t_charptr_decrease_key(&heap, &fnodes[idx],
                                                 (uint16_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint16_t_charptr_node_t *min;
          sfh_uint16_t_charptr_find_min(&heap, &min);
          rc = sfh_uint16_t_charptr_delete_min(&heap);
          if (rc == sfh_uint16_t_charptr_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint16_t_charptr_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint16_t_charptr_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint16_t_voidptr(void) {
  sfh_uint16_t_voidptr_heap_t heap;
  sfh_uint16_t_voidptr_node_t node, node2;
  sfh_uint16_t_voidptr_node_t *out_node;
  sfh_uint16_t_voidptr_heap_t *out_heap;
  int is_empty;
  sfh_uint16_t_voidptr_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint16_t_voidptr_init(NULL);
  rc = sfh_uint16_t_voidptr_empty(NULL, &is_empty);
  rc = sfh_uint16_t_voidptr_find_min(NULL, &out_node);
  rc = sfh_uint16_t_voidptr_insert(NULL, &node, 1, 0);
  rc = sfh_uint16_t_voidptr_insert(&heap, NULL, 1, 0);
  rc = sfh_uint16_t_voidptr_delete_min(NULL);
  rc = sfh_uint16_t_voidptr_delete(NULL, &node);
  rc = sfh_uint16_t_voidptr_delete(&heap, NULL);
  rc = sfh_uint16_t_voidptr_decrease_key(NULL, &node, 1);
  rc = sfh_uint16_t_voidptr_decrease_key(&heap, NULL, 1);
  rc = sfh_uint16_t_voidptr_meld(NULL, &heap, &out_heap);
  rc = sfh_uint16_t_voidptr_meld(&heap, NULL, &out_heap);
  rc = sfh_uint16_t_voidptr_meld(&heap, &heap, NULL);

  sfh_uint16_t_voidptr_init(&heap);
  rc = sfh_uint16_t_voidptr_empty(&heap, &is_empty);
  rc = sfh_uint16_t_voidptr_find_min(&heap, &out_node);
  rc = sfh_uint16_t_voidptr_delete_min(&heap);

  rc = sfh_uint16_t_voidptr_insert(&heap, &node, 10, 0);
  rc = sfh_uint16_t_voidptr_empty(&heap, &is_empty);
  rc = sfh_uint16_t_voidptr_find_min(&heap, &out_node);

  rc = sfh_uint16_t_voidptr_insert(&heap, &node2, 10, 0);
  rc = sfh_uint16_t_voidptr_delete(&heap, &node);
  rc = sfh_uint16_t_voidptr_delete_min(&heap);

  {
    sfh_uint16_t_voidptr_heap_t h1, h2, h3, *merged;
    sfh_uint16_t_voidptr_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint16_t_voidptr_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint16_t_voidptr_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint16_t_voidptr_init(&h3);
    sfh_uint16_t_voidptr_insert(&h1, &n1, 1, 0);
    sfh_uint16_t_voidptr_insert(&h1, &n2, 2, 0);
    sfh_uint16_t_voidptr_insert(&h1, &n3, 3, 0);
    sfh_uint16_t_voidptr_insert(&h1, &n4, 4, 0);
    sfh_uint16_t_voidptr_insert(&h2, &n5, 5, 0);

    sfh_uint16_t_voidptr_meld(&h1, &h2, &merged);
    sfh_uint16_t_voidptr_delete_min(merged);
    sfh_uint16_t_voidptr_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint16_t_voidptr_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint16_t_voidptr_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint16_t_voidptr_insert(&heap, &fnodes[idx],
                                           (uint16_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint16_t_voidptr_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint16_t_voidptr_decrease_key(&heap, &fnodes[idx],
                                                 (uint16_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint16_t_voidptr_node_t *min;
          sfh_uint16_t_voidptr_find_min(&heap, &min);
          rc = sfh_uint16_t_voidptr_delete_min(&heap);
          if (rc == sfh_uint16_t_voidptr_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint16_t_voidptr_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint16_t_voidptr_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint32_t_int8_t(void) {
  sfh_uint32_t_int8_t_heap_t heap;
  sfh_uint32_t_int8_t_node_t node, node2;
  sfh_uint32_t_int8_t_node_t *out_node;
  sfh_uint32_t_int8_t_heap_t *out_heap;
  int is_empty;
  sfh_uint32_t_int8_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint32_t_int8_t_init(NULL);
  rc = sfh_uint32_t_int8_t_empty(NULL, &is_empty);
  rc = sfh_uint32_t_int8_t_find_min(NULL, &out_node);
  rc = sfh_uint32_t_int8_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint32_t_int8_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint32_t_int8_t_delete_min(NULL);
  rc = sfh_uint32_t_int8_t_delete(NULL, &node);
  rc = sfh_uint32_t_int8_t_delete(&heap, NULL);
  rc = sfh_uint32_t_int8_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint32_t_int8_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint32_t_int8_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint32_t_int8_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint32_t_int8_t_meld(&heap, &heap, NULL);

  sfh_uint32_t_int8_t_init(&heap);
  rc = sfh_uint32_t_int8_t_empty(&heap, &is_empty);
  rc = sfh_uint32_t_int8_t_find_min(&heap, &out_node);
  rc = sfh_uint32_t_int8_t_delete_min(&heap);

  rc = sfh_uint32_t_int8_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint32_t_int8_t_empty(&heap, &is_empty);
  rc = sfh_uint32_t_int8_t_find_min(&heap, &out_node);

  rc = sfh_uint32_t_int8_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint32_t_int8_t_delete(&heap, &node);
  rc = sfh_uint32_t_int8_t_delete_min(&heap);

  {
    sfh_uint32_t_int8_t_heap_t h1, h2, h3, *merged;
    sfh_uint32_t_int8_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint32_t_int8_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint32_t_int8_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint32_t_int8_t_init(&h3);
    sfh_uint32_t_int8_t_insert(&h1, &n1, 1, 0);
    sfh_uint32_t_int8_t_insert(&h1, &n2, 2, 0);
    sfh_uint32_t_int8_t_insert(&h1, &n3, 3, 0);
    sfh_uint32_t_int8_t_insert(&h1, &n4, 4, 0);
    sfh_uint32_t_int8_t_insert(&h2, &n5, 5, 0);

    sfh_uint32_t_int8_t_meld(&h1, &h2, &merged);
    sfh_uint32_t_int8_t_delete_min(merged);
    sfh_uint32_t_int8_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint32_t_int8_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint32_t_int8_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint32_t_int8_t_insert(&heap, &fnodes[idx],
                                          (uint32_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint32_t_int8_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint32_t_int8_t_decrease_key(&heap, &fnodes[idx],
                                                (uint32_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint32_t_int8_t_node_t *min;
          sfh_uint32_t_int8_t_find_min(&heap, &min);
          rc = sfh_uint32_t_int8_t_delete_min(&heap);
          if (rc == sfh_uint32_t_int8_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint32_t_int8_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint32_t_int8_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint32_t_int16_t(void) {
  sfh_uint32_t_int16_t_heap_t heap;
  sfh_uint32_t_int16_t_node_t node, node2;
  sfh_uint32_t_int16_t_node_t *out_node;
  sfh_uint32_t_int16_t_heap_t *out_heap;
  int is_empty;
  sfh_uint32_t_int16_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint32_t_int16_t_init(NULL);
  rc = sfh_uint32_t_int16_t_empty(NULL, &is_empty);
  rc = sfh_uint32_t_int16_t_find_min(NULL, &out_node);
  rc = sfh_uint32_t_int16_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint32_t_int16_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint32_t_int16_t_delete_min(NULL);
  rc = sfh_uint32_t_int16_t_delete(NULL, &node);
  rc = sfh_uint32_t_int16_t_delete(&heap, NULL);
  rc = sfh_uint32_t_int16_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint32_t_int16_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint32_t_int16_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint32_t_int16_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint32_t_int16_t_meld(&heap, &heap, NULL);

  sfh_uint32_t_int16_t_init(&heap);
  rc = sfh_uint32_t_int16_t_empty(&heap, &is_empty);
  rc = sfh_uint32_t_int16_t_find_min(&heap, &out_node);
  rc = sfh_uint32_t_int16_t_delete_min(&heap);

  rc = sfh_uint32_t_int16_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint32_t_int16_t_empty(&heap, &is_empty);
  rc = sfh_uint32_t_int16_t_find_min(&heap, &out_node);

  rc = sfh_uint32_t_int16_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint32_t_int16_t_delete(&heap, &node);
  rc = sfh_uint32_t_int16_t_delete_min(&heap);

  {
    sfh_uint32_t_int16_t_heap_t h1, h2, h3, *merged;
    sfh_uint32_t_int16_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint32_t_int16_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint32_t_int16_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint32_t_int16_t_init(&h3);
    sfh_uint32_t_int16_t_insert(&h1, &n1, 1, 0);
    sfh_uint32_t_int16_t_insert(&h1, &n2, 2, 0);
    sfh_uint32_t_int16_t_insert(&h1, &n3, 3, 0);
    sfh_uint32_t_int16_t_insert(&h1, &n4, 4, 0);
    sfh_uint32_t_int16_t_insert(&h2, &n5, 5, 0);

    sfh_uint32_t_int16_t_meld(&h1, &h2, &merged);
    sfh_uint32_t_int16_t_delete_min(merged);
    sfh_uint32_t_int16_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint32_t_int16_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint32_t_int16_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint32_t_int16_t_insert(&heap, &fnodes[idx],
                                           (uint32_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint32_t_int16_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint32_t_int16_t_decrease_key(&heap, &fnodes[idx],
                                                 (uint32_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint32_t_int16_t_node_t *min;
          sfh_uint32_t_int16_t_find_min(&heap, &min);
          rc = sfh_uint32_t_int16_t_delete_min(&heap);
          if (rc == sfh_uint32_t_int16_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint32_t_int16_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint32_t_int16_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint32_t_int32_t(void) {
  sfh_uint32_t_int32_t_heap_t heap;
  sfh_uint32_t_int32_t_node_t node, node2;
  sfh_uint32_t_int32_t_node_t *out_node;
  sfh_uint32_t_int32_t_heap_t *out_heap;
  int is_empty;
  sfh_uint32_t_int32_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint32_t_int32_t_init(NULL);
  rc = sfh_uint32_t_int32_t_empty(NULL, &is_empty);
  rc = sfh_uint32_t_int32_t_find_min(NULL, &out_node);
  rc = sfh_uint32_t_int32_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint32_t_int32_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint32_t_int32_t_delete_min(NULL);
  rc = sfh_uint32_t_int32_t_delete(NULL, &node);
  rc = sfh_uint32_t_int32_t_delete(&heap, NULL);
  rc = sfh_uint32_t_int32_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint32_t_int32_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint32_t_int32_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint32_t_int32_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint32_t_int32_t_meld(&heap, &heap, NULL);

  sfh_uint32_t_int32_t_init(&heap);
  rc = sfh_uint32_t_int32_t_empty(&heap, &is_empty);
  rc = sfh_uint32_t_int32_t_find_min(&heap, &out_node);
  rc = sfh_uint32_t_int32_t_delete_min(&heap);

  rc = sfh_uint32_t_int32_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint32_t_int32_t_empty(&heap, &is_empty);
  rc = sfh_uint32_t_int32_t_find_min(&heap, &out_node);

  rc = sfh_uint32_t_int32_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint32_t_int32_t_delete(&heap, &node);
  rc = sfh_uint32_t_int32_t_delete_min(&heap);

  {
    sfh_uint32_t_int32_t_heap_t h1, h2, h3, *merged;
    sfh_uint32_t_int32_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint32_t_int32_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint32_t_int32_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint32_t_int32_t_init(&h3);
    sfh_uint32_t_int32_t_insert(&h1, &n1, 1, 0);
    sfh_uint32_t_int32_t_insert(&h1, &n2, 2, 0);
    sfh_uint32_t_int32_t_insert(&h1, &n3, 3, 0);
    sfh_uint32_t_int32_t_insert(&h1, &n4, 4, 0);
    sfh_uint32_t_int32_t_insert(&h2, &n5, 5, 0);

    sfh_uint32_t_int32_t_meld(&h1, &h2, &merged);
    sfh_uint32_t_int32_t_delete_min(merged);
    sfh_uint32_t_int32_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint32_t_int32_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint32_t_int32_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint32_t_int32_t_insert(&heap, &fnodes[idx],
                                           (uint32_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint32_t_int32_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint32_t_int32_t_decrease_key(&heap, &fnodes[idx],
                                                 (uint32_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint32_t_int32_t_node_t *min;
          sfh_uint32_t_int32_t_find_min(&heap, &min);
          rc = sfh_uint32_t_int32_t_delete_min(&heap);
          if (rc == sfh_uint32_t_int32_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint32_t_int32_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint32_t_int32_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint32_t_int64_t(void) {
  sfh_uint32_t_int64_t_heap_t heap;
  sfh_uint32_t_int64_t_node_t node, node2;
  sfh_uint32_t_int64_t_node_t *out_node;
  sfh_uint32_t_int64_t_heap_t *out_heap;
  int is_empty;
  sfh_uint32_t_int64_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint32_t_int64_t_init(NULL);
  rc = sfh_uint32_t_int64_t_empty(NULL, &is_empty);
  rc = sfh_uint32_t_int64_t_find_min(NULL, &out_node);
  rc = sfh_uint32_t_int64_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint32_t_int64_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint32_t_int64_t_delete_min(NULL);
  rc = sfh_uint32_t_int64_t_delete(NULL, &node);
  rc = sfh_uint32_t_int64_t_delete(&heap, NULL);
  rc = sfh_uint32_t_int64_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint32_t_int64_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint32_t_int64_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint32_t_int64_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint32_t_int64_t_meld(&heap, &heap, NULL);

  sfh_uint32_t_int64_t_init(&heap);
  rc = sfh_uint32_t_int64_t_empty(&heap, &is_empty);
  rc = sfh_uint32_t_int64_t_find_min(&heap, &out_node);
  rc = sfh_uint32_t_int64_t_delete_min(&heap);

  rc = sfh_uint32_t_int64_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint32_t_int64_t_empty(&heap, &is_empty);
  rc = sfh_uint32_t_int64_t_find_min(&heap, &out_node);

  rc = sfh_uint32_t_int64_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint32_t_int64_t_delete(&heap, &node);
  rc = sfh_uint32_t_int64_t_delete_min(&heap);

  {
    sfh_uint32_t_int64_t_heap_t h1, h2, h3, *merged;
    sfh_uint32_t_int64_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint32_t_int64_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint32_t_int64_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint32_t_int64_t_init(&h3);
    sfh_uint32_t_int64_t_insert(&h1, &n1, 1, 0);
    sfh_uint32_t_int64_t_insert(&h1, &n2, 2, 0);
    sfh_uint32_t_int64_t_insert(&h1, &n3, 3, 0);
    sfh_uint32_t_int64_t_insert(&h1, &n4, 4, 0);
    sfh_uint32_t_int64_t_insert(&h2, &n5, 5, 0);

    sfh_uint32_t_int64_t_meld(&h1, &h2, &merged);
    sfh_uint32_t_int64_t_delete_min(merged);
    sfh_uint32_t_int64_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint32_t_int64_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint32_t_int64_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint32_t_int64_t_insert(&heap, &fnodes[idx],
                                           (uint32_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint32_t_int64_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint32_t_int64_t_decrease_key(&heap, &fnodes[idx],
                                                 (uint32_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint32_t_int64_t_node_t *min;
          sfh_uint32_t_int64_t_find_min(&heap, &min);
          rc = sfh_uint32_t_int64_t_delete_min(&heap);
          if (rc == sfh_uint32_t_int64_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint32_t_int64_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint32_t_int64_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint32_t_uint8_t(void) {
  sfh_uint32_t_uint8_t_heap_t heap;
  sfh_uint32_t_uint8_t_node_t node, node2;
  sfh_uint32_t_uint8_t_node_t *out_node;
  sfh_uint32_t_uint8_t_heap_t *out_heap;
  int is_empty;
  sfh_uint32_t_uint8_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint32_t_uint8_t_init(NULL);
  rc = sfh_uint32_t_uint8_t_empty(NULL, &is_empty);
  rc = sfh_uint32_t_uint8_t_find_min(NULL, &out_node);
  rc = sfh_uint32_t_uint8_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint32_t_uint8_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint32_t_uint8_t_delete_min(NULL);
  rc = sfh_uint32_t_uint8_t_delete(NULL, &node);
  rc = sfh_uint32_t_uint8_t_delete(&heap, NULL);
  rc = sfh_uint32_t_uint8_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint32_t_uint8_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint32_t_uint8_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint32_t_uint8_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint32_t_uint8_t_meld(&heap, &heap, NULL);

  sfh_uint32_t_uint8_t_init(&heap);
  rc = sfh_uint32_t_uint8_t_empty(&heap, &is_empty);
  rc = sfh_uint32_t_uint8_t_find_min(&heap, &out_node);
  rc = sfh_uint32_t_uint8_t_delete_min(&heap);

  rc = sfh_uint32_t_uint8_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint32_t_uint8_t_empty(&heap, &is_empty);
  rc = sfh_uint32_t_uint8_t_find_min(&heap, &out_node);

  rc = sfh_uint32_t_uint8_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint32_t_uint8_t_delete(&heap, &node);
  rc = sfh_uint32_t_uint8_t_delete_min(&heap);

  {
    sfh_uint32_t_uint8_t_heap_t h1, h2, h3, *merged;
    sfh_uint32_t_uint8_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint32_t_uint8_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint32_t_uint8_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint32_t_uint8_t_init(&h3);
    sfh_uint32_t_uint8_t_insert(&h1, &n1, 1, 0);
    sfh_uint32_t_uint8_t_insert(&h1, &n2, 2, 0);
    sfh_uint32_t_uint8_t_insert(&h1, &n3, 3, 0);
    sfh_uint32_t_uint8_t_insert(&h1, &n4, 4, 0);
    sfh_uint32_t_uint8_t_insert(&h2, &n5, 5, 0);

    sfh_uint32_t_uint8_t_meld(&h1, &h2, &merged);
    sfh_uint32_t_uint8_t_delete_min(merged);
    sfh_uint32_t_uint8_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint32_t_uint8_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint32_t_uint8_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint32_t_uint8_t_insert(&heap, &fnodes[idx],
                                           (uint32_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint32_t_uint8_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint32_t_uint8_t_decrease_key(&heap, &fnodes[idx],
                                                 (uint32_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint32_t_uint8_t_node_t *min;
          sfh_uint32_t_uint8_t_find_min(&heap, &min);
          rc = sfh_uint32_t_uint8_t_delete_min(&heap);
          if (rc == sfh_uint32_t_uint8_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint32_t_uint8_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint32_t_uint8_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint32_t_uint16_t(void) {
  sfh_uint32_t_uint16_t_heap_t heap;
  sfh_uint32_t_uint16_t_node_t node, node2;
  sfh_uint32_t_uint16_t_node_t *out_node;
  sfh_uint32_t_uint16_t_heap_t *out_heap;
  int is_empty;
  sfh_uint32_t_uint16_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint32_t_uint16_t_init(NULL);
  rc = sfh_uint32_t_uint16_t_empty(NULL, &is_empty);
  rc = sfh_uint32_t_uint16_t_find_min(NULL, &out_node);
  rc = sfh_uint32_t_uint16_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint32_t_uint16_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint32_t_uint16_t_delete_min(NULL);
  rc = sfh_uint32_t_uint16_t_delete(NULL, &node);
  rc = sfh_uint32_t_uint16_t_delete(&heap, NULL);
  rc = sfh_uint32_t_uint16_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint32_t_uint16_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint32_t_uint16_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint32_t_uint16_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint32_t_uint16_t_meld(&heap, &heap, NULL);

  sfh_uint32_t_uint16_t_init(&heap);
  rc = sfh_uint32_t_uint16_t_empty(&heap, &is_empty);
  rc = sfh_uint32_t_uint16_t_find_min(&heap, &out_node);
  rc = sfh_uint32_t_uint16_t_delete_min(&heap);

  rc = sfh_uint32_t_uint16_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint32_t_uint16_t_empty(&heap, &is_empty);
  rc = sfh_uint32_t_uint16_t_find_min(&heap, &out_node);

  rc = sfh_uint32_t_uint16_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint32_t_uint16_t_delete(&heap, &node);
  rc = sfh_uint32_t_uint16_t_delete_min(&heap);

  {
    sfh_uint32_t_uint16_t_heap_t h1, h2, h3, *merged;
    sfh_uint32_t_uint16_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint32_t_uint16_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint32_t_uint16_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint32_t_uint16_t_init(&h3);
    sfh_uint32_t_uint16_t_insert(&h1, &n1, 1, 0);
    sfh_uint32_t_uint16_t_insert(&h1, &n2, 2, 0);
    sfh_uint32_t_uint16_t_insert(&h1, &n3, 3, 0);
    sfh_uint32_t_uint16_t_insert(&h1, &n4, 4, 0);
    sfh_uint32_t_uint16_t_insert(&h2, &n5, 5, 0);

    sfh_uint32_t_uint16_t_meld(&h1, &h2, &merged);
    sfh_uint32_t_uint16_t_delete_min(merged);
    sfh_uint32_t_uint16_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint32_t_uint16_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint32_t_uint16_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint32_t_uint16_t_insert(&heap, &fnodes[idx],
                                            (uint32_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint32_t_uint16_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint32_t_uint16_t_decrease_key(&heap, &fnodes[idx],
                                                  (uint32_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint32_t_uint16_t_node_t *min;
          sfh_uint32_t_uint16_t_find_min(&heap, &min);
          rc = sfh_uint32_t_uint16_t_delete_min(&heap);
          if (rc == sfh_uint32_t_uint16_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint32_t_uint16_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint32_t_uint16_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint32_t_uint32_t(void) {
  sfh_uint32_t_uint32_t_heap_t heap;
  sfh_uint32_t_uint32_t_node_t node, node2;
  sfh_uint32_t_uint32_t_node_t *out_node;
  sfh_uint32_t_uint32_t_heap_t *out_heap;
  int is_empty;
  sfh_uint32_t_uint32_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint32_t_uint32_t_init(NULL);
  rc = sfh_uint32_t_uint32_t_empty(NULL, &is_empty);
  rc = sfh_uint32_t_uint32_t_find_min(NULL, &out_node);
  rc = sfh_uint32_t_uint32_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint32_t_uint32_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint32_t_uint32_t_delete_min(NULL);
  rc = sfh_uint32_t_uint32_t_delete(NULL, &node);
  rc = sfh_uint32_t_uint32_t_delete(&heap, NULL);
  rc = sfh_uint32_t_uint32_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint32_t_uint32_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint32_t_uint32_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint32_t_uint32_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint32_t_uint32_t_meld(&heap, &heap, NULL);

  sfh_uint32_t_uint32_t_init(&heap);
  rc = sfh_uint32_t_uint32_t_empty(&heap, &is_empty);
  rc = sfh_uint32_t_uint32_t_find_min(&heap, &out_node);
  rc = sfh_uint32_t_uint32_t_delete_min(&heap);

  rc = sfh_uint32_t_uint32_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint32_t_uint32_t_empty(&heap, &is_empty);
  rc = sfh_uint32_t_uint32_t_find_min(&heap, &out_node);

  rc = sfh_uint32_t_uint32_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint32_t_uint32_t_delete(&heap, &node);
  rc = sfh_uint32_t_uint32_t_delete_min(&heap);

  {
    sfh_uint32_t_uint32_t_heap_t h1, h2, h3, *merged;
    sfh_uint32_t_uint32_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint32_t_uint32_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint32_t_uint32_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint32_t_uint32_t_init(&h3);
    sfh_uint32_t_uint32_t_insert(&h1, &n1, 1, 0);
    sfh_uint32_t_uint32_t_insert(&h1, &n2, 2, 0);
    sfh_uint32_t_uint32_t_insert(&h1, &n3, 3, 0);
    sfh_uint32_t_uint32_t_insert(&h1, &n4, 4, 0);
    sfh_uint32_t_uint32_t_insert(&h2, &n5, 5, 0);

    sfh_uint32_t_uint32_t_meld(&h1, &h2, &merged);
    sfh_uint32_t_uint32_t_delete_min(merged);
    sfh_uint32_t_uint32_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint32_t_uint32_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint32_t_uint32_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint32_t_uint32_t_insert(&heap, &fnodes[idx],
                                            (uint32_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint32_t_uint32_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint32_t_uint32_t_decrease_key(&heap, &fnodes[idx],
                                                  (uint32_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint32_t_uint32_t_node_t *min;
          sfh_uint32_t_uint32_t_find_min(&heap, &min);
          rc = sfh_uint32_t_uint32_t_delete_min(&heap);
          if (rc == sfh_uint32_t_uint32_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint32_t_uint32_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint32_t_uint32_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint32_t_uint64_t(void) {
  sfh_uint32_t_uint64_t_heap_t heap;
  sfh_uint32_t_uint64_t_node_t node, node2;
  sfh_uint32_t_uint64_t_node_t *out_node;
  sfh_uint32_t_uint64_t_heap_t *out_heap;
  int is_empty;
  sfh_uint32_t_uint64_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint32_t_uint64_t_init(NULL);
  rc = sfh_uint32_t_uint64_t_empty(NULL, &is_empty);
  rc = sfh_uint32_t_uint64_t_find_min(NULL, &out_node);
  rc = sfh_uint32_t_uint64_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint32_t_uint64_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint32_t_uint64_t_delete_min(NULL);
  rc = sfh_uint32_t_uint64_t_delete(NULL, &node);
  rc = sfh_uint32_t_uint64_t_delete(&heap, NULL);
  rc = sfh_uint32_t_uint64_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint32_t_uint64_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint32_t_uint64_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint32_t_uint64_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint32_t_uint64_t_meld(&heap, &heap, NULL);

  sfh_uint32_t_uint64_t_init(&heap);
  rc = sfh_uint32_t_uint64_t_empty(&heap, &is_empty);
  rc = sfh_uint32_t_uint64_t_find_min(&heap, &out_node);
  rc = sfh_uint32_t_uint64_t_delete_min(&heap);

  rc = sfh_uint32_t_uint64_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint32_t_uint64_t_empty(&heap, &is_empty);
  rc = sfh_uint32_t_uint64_t_find_min(&heap, &out_node);

  rc = sfh_uint32_t_uint64_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint32_t_uint64_t_delete(&heap, &node);
  rc = sfh_uint32_t_uint64_t_delete_min(&heap);

  {
    sfh_uint32_t_uint64_t_heap_t h1, h2, h3, *merged;
    sfh_uint32_t_uint64_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint32_t_uint64_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint32_t_uint64_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint32_t_uint64_t_init(&h3);
    sfh_uint32_t_uint64_t_insert(&h1, &n1, 1, 0);
    sfh_uint32_t_uint64_t_insert(&h1, &n2, 2, 0);
    sfh_uint32_t_uint64_t_insert(&h1, &n3, 3, 0);
    sfh_uint32_t_uint64_t_insert(&h1, &n4, 4, 0);
    sfh_uint32_t_uint64_t_insert(&h2, &n5, 5, 0);

    sfh_uint32_t_uint64_t_meld(&h1, &h2, &merged);
    sfh_uint32_t_uint64_t_delete_min(merged);
    sfh_uint32_t_uint64_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint32_t_uint64_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint32_t_uint64_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint32_t_uint64_t_insert(&heap, &fnodes[idx],
                                            (uint32_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint32_t_uint64_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint32_t_uint64_t_decrease_key(&heap, &fnodes[idx],
                                                  (uint32_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint32_t_uint64_t_node_t *min;
          sfh_uint32_t_uint64_t_find_min(&heap, &min);
          rc = sfh_uint32_t_uint64_t_delete_min(&heap);
          if (rc == sfh_uint32_t_uint64_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint32_t_uint64_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint32_t_uint64_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint32_t_float(void) {
  sfh_uint32_t_float_heap_t heap;
  sfh_uint32_t_float_node_t node, node2;
  sfh_uint32_t_float_node_t *out_node;
  sfh_uint32_t_float_heap_t *out_heap;
  int is_empty;
  sfh_uint32_t_float_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint32_t_float_init(NULL);
  rc = sfh_uint32_t_float_empty(NULL, &is_empty);
  rc = sfh_uint32_t_float_find_min(NULL, &out_node);
  rc = sfh_uint32_t_float_insert(NULL, &node, 1, 0);
  rc = sfh_uint32_t_float_insert(&heap, NULL, 1, 0);
  rc = sfh_uint32_t_float_delete_min(NULL);
  rc = sfh_uint32_t_float_delete(NULL, &node);
  rc = sfh_uint32_t_float_delete(&heap, NULL);
  rc = sfh_uint32_t_float_decrease_key(NULL, &node, 1);
  rc = sfh_uint32_t_float_decrease_key(&heap, NULL, 1);
  rc = sfh_uint32_t_float_meld(NULL, &heap, &out_heap);
  rc = sfh_uint32_t_float_meld(&heap, NULL, &out_heap);
  rc = sfh_uint32_t_float_meld(&heap, &heap, NULL);

  sfh_uint32_t_float_init(&heap);
  rc = sfh_uint32_t_float_empty(&heap, &is_empty);
  rc = sfh_uint32_t_float_find_min(&heap, &out_node);
  rc = sfh_uint32_t_float_delete_min(&heap);

  rc = sfh_uint32_t_float_insert(&heap, &node, 10, 0);
  rc = sfh_uint32_t_float_empty(&heap, &is_empty);
  rc = sfh_uint32_t_float_find_min(&heap, &out_node);

  rc = sfh_uint32_t_float_insert(&heap, &node2, 10, 0);
  rc = sfh_uint32_t_float_delete(&heap, &node);
  rc = sfh_uint32_t_float_delete_min(&heap);

  {
    sfh_uint32_t_float_heap_t h1, h2, h3, *merged;
    sfh_uint32_t_float_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint32_t_float_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint32_t_float_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint32_t_float_init(&h3);
    sfh_uint32_t_float_insert(&h1, &n1, 1, 0);
    sfh_uint32_t_float_insert(&h1, &n2, 2, 0);
    sfh_uint32_t_float_insert(&h1, &n3, 3, 0);
    sfh_uint32_t_float_insert(&h1, &n4, 4, 0);
    sfh_uint32_t_float_insert(&h2, &n5, 5, 0);

    sfh_uint32_t_float_meld(&h1, &h2, &merged);
    sfh_uint32_t_float_delete_min(merged);
    sfh_uint32_t_float_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint32_t_float_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint32_t_float_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint32_t_float_insert(&heap, &fnodes[idx],
                                         (uint32_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint32_t_float_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc =
              sfh_uint32_t_float_decrease_key(&heap, &fnodes[idx], (uint32_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint32_t_float_node_t *min;
          sfh_uint32_t_float_find_min(&heap, &min);
          rc = sfh_uint32_t_float_delete_min(&heap);
          if (rc == sfh_uint32_t_float_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint32_t_float_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint32_t_float_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint32_t_double(void) {
  sfh_uint32_t_double_heap_t heap;
  sfh_uint32_t_double_node_t node, node2;
  sfh_uint32_t_double_node_t *out_node;
  sfh_uint32_t_double_heap_t *out_heap;
  int is_empty;
  sfh_uint32_t_double_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint32_t_double_init(NULL);
  rc = sfh_uint32_t_double_empty(NULL, &is_empty);
  rc = sfh_uint32_t_double_find_min(NULL, &out_node);
  rc = sfh_uint32_t_double_insert(NULL, &node, 1, 0);
  rc = sfh_uint32_t_double_insert(&heap, NULL, 1, 0);
  rc = sfh_uint32_t_double_delete_min(NULL);
  rc = sfh_uint32_t_double_delete(NULL, &node);
  rc = sfh_uint32_t_double_delete(&heap, NULL);
  rc = sfh_uint32_t_double_decrease_key(NULL, &node, 1);
  rc = sfh_uint32_t_double_decrease_key(&heap, NULL, 1);
  rc = sfh_uint32_t_double_meld(NULL, &heap, &out_heap);
  rc = sfh_uint32_t_double_meld(&heap, NULL, &out_heap);
  rc = sfh_uint32_t_double_meld(&heap, &heap, NULL);

  sfh_uint32_t_double_init(&heap);
  rc = sfh_uint32_t_double_empty(&heap, &is_empty);
  rc = sfh_uint32_t_double_find_min(&heap, &out_node);
  rc = sfh_uint32_t_double_delete_min(&heap);

  rc = sfh_uint32_t_double_insert(&heap, &node, 10, 0);
  rc = sfh_uint32_t_double_empty(&heap, &is_empty);
  rc = sfh_uint32_t_double_find_min(&heap, &out_node);

  rc = sfh_uint32_t_double_insert(&heap, &node2, 10, 0);
  rc = sfh_uint32_t_double_delete(&heap, &node);
  rc = sfh_uint32_t_double_delete_min(&heap);

  {
    sfh_uint32_t_double_heap_t h1, h2, h3, *merged;
    sfh_uint32_t_double_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint32_t_double_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint32_t_double_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint32_t_double_init(&h3);
    sfh_uint32_t_double_insert(&h1, &n1, 1, 0);
    sfh_uint32_t_double_insert(&h1, &n2, 2, 0);
    sfh_uint32_t_double_insert(&h1, &n3, 3, 0);
    sfh_uint32_t_double_insert(&h1, &n4, 4, 0);
    sfh_uint32_t_double_insert(&h2, &n5, 5, 0);

    sfh_uint32_t_double_meld(&h1, &h2, &merged);
    sfh_uint32_t_double_delete_min(merged);
    sfh_uint32_t_double_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint32_t_double_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint32_t_double_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint32_t_double_insert(&heap, &fnodes[idx],
                                          (uint32_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint32_t_double_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint32_t_double_decrease_key(&heap, &fnodes[idx],
                                                (uint32_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint32_t_double_node_t *min;
          sfh_uint32_t_double_find_min(&heap, &min);
          rc = sfh_uint32_t_double_delete_min(&heap);
          if (rc == sfh_uint32_t_double_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint32_t_double_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint32_t_double_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint32_t_charptr(void) {
  sfh_uint32_t_charptr_heap_t heap;
  sfh_uint32_t_charptr_node_t node, node2;
  sfh_uint32_t_charptr_node_t *out_node;
  sfh_uint32_t_charptr_heap_t *out_heap;
  int is_empty;
  sfh_uint32_t_charptr_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint32_t_charptr_init(NULL);
  rc = sfh_uint32_t_charptr_empty(NULL, &is_empty);
  rc = sfh_uint32_t_charptr_find_min(NULL, &out_node);
  rc = sfh_uint32_t_charptr_insert(NULL, &node, 1, 0);
  rc = sfh_uint32_t_charptr_insert(&heap, NULL, 1, 0);
  rc = sfh_uint32_t_charptr_delete_min(NULL);
  rc = sfh_uint32_t_charptr_delete(NULL, &node);
  rc = sfh_uint32_t_charptr_delete(&heap, NULL);
  rc = sfh_uint32_t_charptr_decrease_key(NULL, &node, 1);
  rc = sfh_uint32_t_charptr_decrease_key(&heap, NULL, 1);
  rc = sfh_uint32_t_charptr_meld(NULL, &heap, &out_heap);
  rc = sfh_uint32_t_charptr_meld(&heap, NULL, &out_heap);
  rc = sfh_uint32_t_charptr_meld(&heap, &heap, NULL);

  sfh_uint32_t_charptr_init(&heap);
  rc = sfh_uint32_t_charptr_empty(&heap, &is_empty);
  rc = sfh_uint32_t_charptr_find_min(&heap, &out_node);
  rc = sfh_uint32_t_charptr_delete_min(&heap);

  rc = sfh_uint32_t_charptr_insert(&heap, &node, 10, 0);
  rc = sfh_uint32_t_charptr_empty(&heap, &is_empty);
  rc = sfh_uint32_t_charptr_find_min(&heap, &out_node);

  rc = sfh_uint32_t_charptr_insert(&heap, &node2, 10, 0);
  rc = sfh_uint32_t_charptr_delete(&heap, &node);
  rc = sfh_uint32_t_charptr_delete_min(&heap);

  {
    sfh_uint32_t_charptr_heap_t h1, h2, h3, *merged;
    sfh_uint32_t_charptr_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint32_t_charptr_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint32_t_charptr_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint32_t_charptr_init(&h3);
    sfh_uint32_t_charptr_insert(&h1, &n1, 1, 0);
    sfh_uint32_t_charptr_insert(&h1, &n2, 2, 0);
    sfh_uint32_t_charptr_insert(&h1, &n3, 3, 0);
    sfh_uint32_t_charptr_insert(&h1, &n4, 4, 0);
    sfh_uint32_t_charptr_insert(&h2, &n5, 5, 0);

    sfh_uint32_t_charptr_meld(&h1, &h2, &merged);
    sfh_uint32_t_charptr_delete_min(merged);
    sfh_uint32_t_charptr_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint32_t_charptr_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint32_t_charptr_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint32_t_charptr_insert(&heap, &fnodes[idx],
                                           (uint32_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint32_t_charptr_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint32_t_charptr_decrease_key(&heap, &fnodes[idx],
                                                 (uint32_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint32_t_charptr_node_t *min;
          sfh_uint32_t_charptr_find_min(&heap, &min);
          rc = sfh_uint32_t_charptr_delete_min(&heap);
          if (rc == sfh_uint32_t_charptr_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint32_t_charptr_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint32_t_charptr_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint32_t_voidptr(void) {
  sfh_uint32_t_voidptr_heap_t heap;
  sfh_uint32_t_voidptr_node_t node, node2;
  sfh_uint32_t_voidptr_node_t *out_node;
  sfh_uint32_t_voidptr_heap_t *out_heap;
  int is_empty;
  sfh_uint32_t_voidptr_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint32_t_voidptr_init(NULL);
  rc = sfh_uint32_t_voidptr_empty(NULL, &is_empty);
  rc = sfh_uint32_t_voidptr_find_min(NULL, &out_node);
  rc = sfh_uint32_t_voidptr_insert(NULL, &node, 1, 0);
  rc = sfh_uint32_t_voidptr_insert(&heap, NULL, 1, 0);
  rc = sfh_uint32_t_voidptr_delete_min(NULL);
  rc = sfh_uint32_t_voidptr_delete(NULL, &node);
  rc = sfh_uint32_t_voidptr_delete(&heap, NULL);
  rc = sfh_uint32_t_voidptr_decrease_key(NULL, &node, 1);
  rc = sfh_uint32_t_voidptr_decrease_key(&heap, NULL, 1);
  rc = sfh_uint32_t_voidptr_meld(NULL, &heap, &out_heap);
  rc = sfh_uint32_t_voidptr_meld(&heap, NULL, &out_heap);
  rc = sfh_uint32_t_voidptr_meld(&heap, &heap, NULL);

  sfh_uint32_t_voidptr_init(&heap);
  rc = sfh_uint32_t_voidptr_empty(&heap, &is_empty);
  rc = sfh_uint32_t_voidptr_find_min(&heap, &out_node);
  rc = sfh_uint32_t_voidptr_delete_min(&heap);

  rc = sfh_uint32_t_voidptr_insert(&heap, &node, 10, 0);
  rc = sfh_uint32_t_voidptr_empty(&heap, &is_empty);
  rc = sfh_uint32_t_voidptr_find_min(&heap, &out_node);

  rc = sfh_uint32_t_voidptr_insert(&heap, &node2, 10, 0);
  rc = sfh_uint32_t_voidptr_delete(&heap, &node);
  rc = sfh_uint32_t_voidptr_delete_min(&heap);

  {
    sfh_uint32_t_voidptr_heap_t h1, h2, h3, *merged;
    sfh_uint32_t_voidptr_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint32_t_voidptr_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint32_t_voidptr_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint32_t_voidptr_init(&h3);
    sfh_uint32_t_voidptr_insert(&h1, &n1, 1, 0);
    sfh_uint32_t_voidptr_insert(&h1, &n2, 2, 0);
    sfh_uint32_t_voidptr_insert(&h1, &n3, 3, 0);
    sfh_uint32_t_voidptr_insert(&h1, &n4, 4, 0);
    sfh_uint32_t_voidptr_insert(&h2, &n5, 5, 0);

    sfh_uint32_t_voidptr_meld(&h1, &h2, &merged);
    sfh_uint32_t_voidptr_delete_min(merged);
    sfh_uint32_t_voidptr_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint32_t_voidptr_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint32_t_voidptr_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint32_t_voidptr_insert(&heap, &fnodes[idx],
                                           (uint32_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint32_t_voidptr_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint32_t_voidptr_decrease_key(&heap, &fnodes[idx],
                                                 (uint32_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint32_t_voidptr_node_t *min;
          sfh_uint32_t_voidptr_find_min(&heap, &min);
          rc = sfh_uint32_t_voidptr_delete_min(&heap);
          if (rc == sfh_uint32_t_voidptr_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint32_t_voidptr_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint32_t_voidptr_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint64_t_int8_t(void) {
  sfh_uint64_t_int8_t_heap_t heap;
  sfh_uint64_t_int8_t_node_t node, node2;
  sfh_uint64_t_int8_t_node_t *out_node;
  sfh_uint64_t_int8_t_heap_t *out_heap;
  int is_empty;
  sfh_uint64_t_int8_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint64_t_int8_t_init(NULL);
  rc = sfh_uint64_t_int8_t_empty(NULL, &is_empty);
  rc = sfh_uint64_t_int8_t_find_min(NULL, &out_node);
  rc = sfh_uint64_t_int8_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint64_t_int8_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint64_t_int8_t_delete_min(NULL);
  rc = sfh_uint64_t_int8_t_delete(NULL, &node);
  rc = sfh_uint64_t_int8_t_delete(&heap, NULL);
  rc = sfh_uint64_t_int8_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint64_t_int8_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint64_t_int8_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint64_t_int8_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint64_t_int8_t_meld(&heap, &heap, NULL);

  sfh_uint64_t_int8_t_init(&heap);
  rc = sfh_uint64_t_int8_t_empty(&heap, &is_empty);
  rc = sfh_uint64_t_int8_t_find_min(&heap, &out_node);
  rc = sfh_uint64_t_int8_t_delete_min(&heap);

  rc = sfh_uint64_t_int8_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint64_t_int8_t_empty(&heap, &is_empty);
  rc = sfh_uint64_t_int8_t_find_min(&heap, &out_node);

  rc = sfh_uint64_t_int8_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint64_t_int8_t_delete(&heap, &node);
  rc = sfh_uint64_t_int8_t_delete_min(&heap);

  {
    sfh_uint64_t_int8_t_heap_t h1, h2, h3, *merged;
    sfh_uint64_t_int8_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint64_t_int8_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint64_t_int8_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint64_t_int8_t_init(&h3);
    sfh_uint64_t_int8_t_insert(&h1, &n1, 1, 0);
    sfh_uint64_t_int8_t_insert(&h1, &n2, 2, 0);
    sfh_uint64_t_int8_t_insert(&h1, &n3, 3, 0);
    sfh_uint64_t_int8_t_insert(&h1, &n4, 4, 0);
    sfh_uint64_t_int8_t_insert(&h2, &n5, 5, 0);

    sfh_uint64_t_int8_t_meld(&h1, &h2, &merged);
    sfh_uint64_t_int8_t_delete_min(merged);
    sfh_uint64_t_int8_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint64_t_int8_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint64_t_int8_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint64_t_int8_t_insert(&heap, &fnodes[idx],
                                          (uint64_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint64_t_int8_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint64_t_int8_t_decrease_key(&heap, &fnodes[idx],
                                                (uint64_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint64_t_int8_t_node_t *min;
          sfh_uint64_t_int8_t_find_min(&heap, &min);
          rc = sfh_uint64_t_int8_t_delete_min(&heap);
          if (rc == sfh_uint64_t_int8_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint64_t_int8_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint64_t_int8_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint64_t_int16_t(void) {
  sfh_uint64_t_int16_t_heap_t heap;
  sfh_uint64_t_int16_t_node_t node, node2;
  sfh_uint64_t_int16_t_node_t *out_node;
  sfh_uint64_t_int16_t_heap_t *out_heap;
  int is_empty;
  sfh_uint64_t_int16_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint64_t_int16_t_init(NULL);
  rc = sfh_uint64_t_int16_t_empty(NULL, &is_empty);
  rc = sfh_uint64_t_int16_t_find_min(NULL, &out_node);
  rc = sfh_uint64_t_int16_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint64_t_int16_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint64_t_int16_t_delete_min(NULL);
  rc = sfh_uint64_t_int16_t_delete(NULL, &node);
  rc = sfh_uint64_t_int16_t_delete(&heap, NULL);
  rc = sfh_uint64_t_int16_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint64_t_int16_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint64_t_int16_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint64_t_int16_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint64_t_int16_t_meld(&heap, &heap, NULL);

  sfh_uint64_t_int16_t_init(&heap);
  rc = sfh_uint64_t_int16_t_empty(&heap, &is_empty);
  rc = sfh_uint64_t_int16_t_find_min(&heap, &out_node);
  rc = sfh_uint64_t_int16_t_delete_min(&heap);

  rc = sfh_uint64_t_int16_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint64_t_int16_t_empty(&heap, &is_empty);
  rc = sfh_uint64_t_int16_t_find_min(&heap, &out_node);

  rc = sfh_uint64_t_int16_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint64_t_int16_t_delete(&heap, &node);
  rc = sfh_uint64_t_int16_t_delete_min(&heap);

  {
    sfh_uint64_t_int16_t_heap_t h1, h2, h3, *merged;
    sfh_uint64_t_int16_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint64_t_int16_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint64_t_int16_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint64_t_int16_t_init(&h3);
    sfh_uint64_t_int16_t_insert(&h1, &n1, 1, 0);
    sfh_uint64_t_int16_t_insert(&h1, &n2, 2, 0);
    sfh_uint64_t_int16_t_insert(&h1, &n3, 3, 0);
    sfh_uint64_t_int16_t_insert(&h1, &n4, 4, 0);
    sfh_uint64_t_int16_t_insert(&h2, &n5, 5, 0);

    sfh_uint64_t_int16_t_meld(&h1, &h2, &merged);
    sfh_uint64_t_int16_t_delete_min(merged);
    sfh_uint64_t_int16_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint64_t_int16_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint64_t_int16_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint64_t_int16_t_insert(&heap, &fnodes[idx],
                                           (uint64_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint64_t_int16_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint64_t_int16_t_decrease_key(&heap, &fnodes[idx],
                                                 (uint64_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint64_t_int16_t_node_t *min;
          sfh_uint64_t_int16_t_find_min(&heap, &min);
          rc = sfh_uint64_t_int16_t_delete_min(&heap);
          if (rc == sfh_uint64_t_int16_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint64_t_int16_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint64_t_int16_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint64_t_int32_t(void) {
  sfh_uint64_t_int32_t_heap_t heap;
  sfh_uint64_t_int32_t_node_t node, node2;
  sfh_uint64_t_int32_t_node_t *out_node;
  sfh_uint64_t_int32_t_heap_t *out_heap;
  int is_empty;
  sfh_uint64_t_int32_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint64_t_int32_t_init(NULL);
  rc = sfh_uint64_t_int32_t_empty(NULL, &is_empty);
  rc = sfh_uint64_t_int32_t_find_min(NULL, &out_node);
  rc = sfh_uint64_t_int32_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint64_t_int32_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint64_t_int32_t_delete_min(NULL);
  rc = sfh_uint64_t_int32_t_delete(NULL, &node);
  rc = sfh_uint64_t_int32_t_delete(&heap, NULL);
  rc = sfh_uint64_t_int32_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint64_t_int32_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint64_t_int32_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint64_t_int32_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint64_t_int32_t_meld(&heap, &heap, NULL);

  sfh_uint64_t_int32_t_init(&heap);
  rc = sfh_uint64_t_int32_t_empty(&heap, &is_empty);
  rc = sfh_uint64_t_int32_t_find_min(&heap, &out_node);
  rc = sfh_uint64_t_int32_t_delete_min(&heap);

  rc = sfh_uint64_t_int32_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint64_t_int32_t_empty(&heap, &is_empty);
  rc = sfh_uint64_t_int32_t_find_min(&heap, &out_node);

  rc = sfh_uint64_t_int32_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint64_t_int32_t_delete(&heap, &node);
  rc = sfh_uint64_t_int32_t_delete_min(&heap);

  {
    sfh_uint64_t_int32_t_heap_t h1, h2, h3, *merged;
    sfh_uint64_t_int32_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint64_t_int32_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint64_t_int32_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint64_t_int32_t_init(&h3);
    sfh_uint64_t_int32_t_insert(&h1, &n1, 1, 0);
    sfh_uint64_t_int32_t_insert(&h1, &n2, 2, 0);
    sfh_uint64_t_int32_t_insert(&h1, &n3, 3, 0);
    sfh_uint64_t_int32_t_insert(&h1, &n4, 4, 0);
    sfh_uint64_t_int32_t_insert(&h2, &n5, 5, 0);

    sfh_uint64_t_int32_t_meld(&h1, &h2, &merged);
    sfh_uint64_t_int32_t_delete_min(merged);
    sfh_uint64_t_int32_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint64_t_int32_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint64_t_int32_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint64_t_int32_t_insert(&heap, &fnodes[idx],
                                           (uint64_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint64_t_int32_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint64_t_int32_t_decrease_key(&heap, &fnodes[idx],
                                                 (uint64_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint64_t_int32_t_node_t *min;
          sfh_uint64_t_int32_t_find_min(&heap, &min);
          rc = sfh_uint64_t_int32_t_delete_min(&heap);
          if (rc == sfh_uint64_t_int32_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint64_t_int32_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint64_t_int32_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint64_t_int64_t(void) {
  sfh_uint64_t_int64_t_heap_t heap;
  sfh_uint64_t_int64_t_node_t node, node2;
  sfh_uint64_t_int64_t_node_t *out_node;
  sfh_uint64_t_int64_t_heap_t *out_heap;
  int is_empty;
  sfh_uint64_t_int64_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint64_t_int64_t_init(NULL);
  rc = sfh_uint64_t_int64_t_empty(NULL, &is_empty);
  rc = sfh_uint64_t_int64_t_find_min(NULL, &out_node);
  rc = sfh_uint64_t_int64_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint64_t_int64_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint64_t_int64_t_delete_min(NULL);
  rc = sfh_uint64_t_int64_t_delete(NULL, &node);
  rc = sfh_uint64_t_int64_t_delete(&heap, NULL);
  rc = sfh_uint64_t_int64_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint64_t_int64_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint64_t_int64_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint64_t_int64_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint64_t_int64_t_meld(&heap, &heap, NULL);

  sfh_uint64_t_int64_t_init(&heap);
  rc = sfh_uint64_t_int64_t_empty(&heap, &is_empty);
  rc = sfh_uint64_t_int64_t_find_min(&heap, &out_node);
  rc = sfh_uint64_t_int64_t_delete_min(&heap);

  rc = sfh_uint64_t_int64_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint64_t_int64_t_empty(&heap, &is_empty);
  rc = sfh_uint64_t_int64_t_find_min(&heap, &out_node);

  rc = sfh_uint64_t_int64_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint64_t_int64_t_delete(&heap, &node);
  rc = sfh_uint64_t_int64_t_delete_min(&heap);

  {
    sfh_uint64_t_int64_t_heap_t h1, h2, h3, *merged;
    sfh_uint64_t_int64_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint64_t_int64_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint64_t_int64_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint64_t_int64_t_init(&h3);
    sfh_uint64_t_int64_t_insert(&h1, &n1, 1, 0);
    sfh_uint64_t_int64_t_insert(&h1, &n2, 2, 0);
    sfh_uint64_t_int64_t_insert(&h1, &n3, 3, 0);
    sfh_uint64_t_int64_t_insert(&h1, &n4, 4, 0);
    sfh_uint64_t_int64_t_insert(&h2, &n5, 5, 0);

    sfh_uint64_t_int64_t_meld(&h1, &h2, &merged);
    sfh_uint64_t_int64_t_delete_min(merged);
    sfh_uint64_t_int64_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint64_t_int64_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint64_t_int64_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint64_t_int64_t_insert(&heap, &fnodes[idx],
                                           (uint64_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint64_t_int64_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint64_t_int64_t_decrease_key(&heap, &fnodes[idx],
                                                 (uint64_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint64_t_int64_t_node_t *min;
          sfh_uint64_t_int64_t_find_min(&heap, &min);
          rc = sfh_uint64_t_int64_t_delete_min(&heap);
          if (rc == sfh_uint64_t_int64_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint64_t_int64_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint64_t_int64_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint64_t_uint8_t(void) {
  sfh_uint64_t_uint8_t_heap_t heap;
  sfh_uint64_t_uint8_t_node_t node, node2;
  sfh_uint64_t_uint8_t_node_t *out_node;
  sfh_uint64_t_uint8_t_heap_t *out_heap;
  int is_empty;
  sfh_uint64_t_uint8_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint64_t_uint8_t_init(NULL);
  rc = sfh_uint64_t_uint8_t_empty(NULL, &is_empty);
  rc = sfh_uint64_t_uint8_t_find_min(NULL, &out_node);
  rc = sfh_uint64_t_uint8_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint64_t_uint8_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint64_t_uint8_t_delete_min(NULL);
  rc = sfh_uint64_t_uint8_t_delete(NULL, &node);
  rc = sfh_uint64_t_uint8_t_delete(&heap, NULL);
  rc = sfh_uint64_t_uint8_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint64_t_uint8_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint64_t_uint8_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint64_t_uint8_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint64_t_uint8_t_meld(&heap, &heap, NULL);

  sfh_uint64_t_uint8_t_init(&heap);
  rc = sfh_uint64_t_uint8_t_empty(&heap, &is_empty);
  rc = sfh_uint64_t_uint8_t_find_min(&heap, &out_node);
  rc = sfh_uint64_t_uint8_t_delete_min(&heap);

  rc = sfh_uint64_t_uint8_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint64_t_uint8_t_empty(&heap, &is_empty);
  rc = sfh_uint64_t_uint8_t_find_min(&heap, &out_node);

  rc = sfh_uint64_t_uint8_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint64_t_uint8_t_delete(&heap, &node);
  rc = sfh_uint64_t_uint8_t_delete_min(&heap);

  {
    sfh_uint64_t_uint8_t_heap_t h1, h2, h3, *merged;
    sfh_uint64_t_uint8_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint64_t_uint8_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint64_t_uint8_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint64_t_uint8_t_init(&h3);
    sfh_uint64_t_uint8_t_insert(&h1, &n1, 1, 0);
    sfh_uint64_t_uint8_t_insert(&h1, &n2, 2, 0);
    sfh_uint64_t_uint8_t_insert(&h1, &n3, 3, 0);
    sfh_uint64_t_uint8_t_insert(&h1, &n4, 4, 0);
    sfh_uint64_t_uint8_t_insert(&h2, &n5, 5, 0);

    sfh_uint64_t_uint8_t_meld(&h1, &h2, &merged);
    sfh_uint64_t_uint8_t_delete_min(merged);
    sfh_uint64_t_uint8_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint64_t_uint8_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint64_t_uint8_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint64_t_uint8_t_insert(&heap, &fnodes[idx],
                                           (uint64_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint64_t_uint8_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint64_t_uint8_t_decrease_key(&heap, &fnodes[idx],
                                                 (uint64_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint64_t_uint8_t_node_t *min;
          sfh_uint64_t_uint8_t_find_min(&heap, &min);
          rc = sfh_uint64_t_uint8_t_delete_min(&heap);
          if (rc == sfh_uint64_t_uint8_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint64_t_uint8_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint64_t_uint8_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint64_t_uint16_t(void) {
  sfh_uint64_t_uint16_t_heap_t heap;
  sfh_uint64_t_uint16_t_node_t node, node2;
  sfh_uint64_t_uint16_t_node_t *out_node;
  sfh_uint64_t_uint16_t_heap_t *out_heap;
  int is_empty;
  sfh_uint64_t_uint16_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint64_t_uint16_t_init(NULL);
  rc = sfh_uint64_t_uint16_t_empty(NULL, &is_empty);
  rc = sfh_uint64_t_uint16_t_find_min(NULL, &out_node);
  rc = sfh_uint64_t_uint16_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint64_t_uint16_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint64_t_uint16_t_delete_min(NULL);
  rc = sfh_uint64_t_uint16_t_delete(NULL, &node);
  rc = sfh_uint64_t_uint16_t_delete(&heap, NULL);
  rc = sfh_uint64_t_uint16_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint64_t_uint16_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint64_t_uint16_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint64_t_uint16_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint64_t_uint16_t_meld(&heap, &heap, NULL);

  sfh_uint64_t_uint16_t_init(&heap);
  rc = sfh_uint64_t_uint16_t_empty(&heap, &is_empty);
  rc = sfh_uint64_t_uint16_t_find_min(&heap, &out_node);
  rc = sfh_uint64_t_uint16_t_delete_min(&heap);

  rc = sfh_uint64_t_uint16_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint64_t_uint16_t_empty(&heap, &is_empty);
  rc = sfh_uint64_t_uint16_t_find_min(&heap, &out_node);

  rc = sfh_uint64_t_uint16_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint64_t_uint16_t_delete(&heap, &node);
  rc = sfh_uint64_t_uint16_t_delete_min(&heap);

  {
    sfh_uint64_t_uint16_t_heap_t h1, h2, h3, *merged;
    sfh_uint64_t_uint16_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint64_t_uint16_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint64_t_uint16_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint64_t_uint16_t_init(&h3);
    sfh_uint64_t_uint16_t_insert(&h1, &n1, 1, 0);
    sfh_uint64_t_uint16_t_insert(&h1, &n2, 2, 0);
    sfh_uint64_t_uint16_t_insert(&h1, &n3, 3, 0);
    sfh_uint64_t_uint16_t_insert(&h1, &n4, 4, 0);
    sfh_uint64_t_uint16_t_insert(&h2, &n5, 5, 0);

    sfh_uint64_t_uint16_t_meld(&h1, &h2, &merged);
    sfh_uint64_t_uint16_t_delete_min(merged);
    sfh_uint64_t_uint16_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint64_t_uint16_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint64_t_uint16_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint64_t_uint16_t_insert(&heap, &fnodes[idx],
                                            (uint64_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint64_t_uint16_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint64_t_uint16_t_decrease_key(&heap, &fnodes[idx],
                                                  (uint64_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint64_t_uint16_t_node_t *min;
          sfh_uint64_t_uint16_t_find_min(&heap, &min);
          rc = sfh_uint64_t_uint16_t_delete_min(&heap);
          if (rc == sfh_uint64_t_uint16_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint64_t_uint16_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint64_t_uint16_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint64_t_uint32_t(void) {
  sfh_uint64_t_uint32_t_heap_t heap;
  sfh_uint64_t_uint32_t_node_t node, node2;
  sfh_uint64_t_uint32_t_node_t *out_node;
  sfh_uint64_t_uint32_t_heap_t *out_heap;
  int is_empty;
  sfh_uint64_t_uint32_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint64_t_uint32_t_init(NULL);
  rc = sfh_uint64_t_uint32_t_empty(NULL, &is_empty);
  rc = sfh_uint64_t_uint32_t_find_min(NULL, &out_node);
  rc = sfh_uint64_t_uint32_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint64_t_uint32_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint64_t_uint32_t_delete_min(NULL);
  rc = sfh_uint64_t_uint32_t_delete(NULL, &node);
  rc = sfh_uint64_t_uint32_t_delete(&heap, NULL);
  rc = sfh_uint64_t_uint32_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint64_t_uint32_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint64_t_uint32_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint64_t_uint32_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint64_t_uint32_t_meld(&heap, &heap, NULL);

  sfh_uint64_t_uint32_t_init(&heap);
  rc = sfh_uint64_t_uint32_t_empty(&heap, &is_empty);
  rc = sfh_uint64_t_uint32_t_find_min(&heap, &out_node);
  rc = sfh_uint64_t_uint32_t_delete_min(&heap);

  rc = sfh_uint64_t_uint32_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint64_t_uint32_t_empty(&heap, &is_empty);
  rc = sfh_uint64_t_uint32_t_find_min(&heap, &out_node);

  rc = sfh_uint64_t_uint32_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint64_t_uint32_t_delete(&heap, &node);
  rc = sfh_uint64_t_uint32_t_delete_min(&heap);

  {
    sfh_uint64_t_uint32_t_heap_t h1, h2, h3, *merged;
    sfh_uint64_t_uint32_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint64_t_uint32_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint64_t_uint32_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint64_t_uint32_t_init(&h3);
    sfh_uint64_t_uint32_t_insert(&h1, &n1, 1, 0);
    sfh_uint64_t_uint32_t_insert(&h1, &n2, 2, 0);
    sfh_uint64_t_uint32_t_insert(&h1, &n3, 3, 0);
    sfh_uint64_t_uint32_t_insert(&h1, &n4, 4, 0);
    sfh_uint64_t_uint32_t_insert(&h2, &n5, 5, 0);

    sfh_uint64_t_uint32_t_meld(&h1, &h2, &merged);
    sfh_uint64_t_uint32_t_delete_min(merged);
    sfh_uint64_t_uint32_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint64_t_uint32_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint64_t_uint32_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint64_t_uint32_t_insert(&heap, &fnodes[idx],
                                            (uint64_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint64_t_uint32_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint64_t_uint32_t_decrease_key(&heap, &fnodes[idx],
                                                  (uint64_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint64_t_uint32_t_node_t *min;
          sfh_uint64_t_uint32_t_find_min(&heap, &min);
          rc = sfh_uint64_t_uint32_t_delete_min(&heap);
          if (rc == sfh_uint64_t_uint32_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint64_t_uint32_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint64_t_uint32_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint64_t_uint64_t(void) {
  sfh_uint64_t_uint64_t_heap_t heap;
  sfh_uint64_t_uint64_t_node_t node, node2;
  sfh_uint64_t_uint64_t_node_t *out_node;
  sfh_uint64_t_uint64_t_heap_t *out_heap;
  int is_empty;
  sfh_uint64_t_uint64_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint64_t_uint64_t_init(NULL);
  rc = sfh_uint64_t_uint64_t_empty(NULL, &is_empty);
  rc = sfh_uint64_t_uint64_t_find_min(NULL, &out_node);
  rc = sfh_uint64_t_uint64_t_insert(NULL, &node, 1, 0);
  rc = sfh_uint64_t_uint64_t_insert(&heap, NULL, 1, 0);
  rc = sfh_uint64_t_uint64_t_delete_min(NULL);
  rc = sfh_uint64_t_uint64_t_delete(NULL, &node);
  rc = sfh_uint64_t_uint64_t_delete(&heap, NULL);
  rc = sfh_uint64_t_uint64_t_decrease_key(NULL, &node, 1);
  rc = sfh_uint64_t_uint64_t_decrease_key(&heap, NULL, 1);
  rc = sfh_uint64_t_uint64_t_meld(NULL, &heap, &out_heap);
  rc = sfh_uint64_t_uint64_t_meld(&heap, NULL, &out_heap);
  rc = sfh_uint64_t_uint64_t_meld(&heap, &heap, NULL);

  sfh_uint64_t_uint64_t_init(&heap);
  rc = sfh_uint64_t_uint64_t_empty(&heap, &is_empty);
  rc = sfh_uint64_t_uint64_t_find_min(&heap, &out_node);
  rc = sfh_uint64_t_uint64_t_delete_min(&heap);

  rc = sfh_uint64_t_uint64_t_insert(&heap, &node, 10, 0);
  rc = sfh_uint64_t_uint64_t_empty(&heap, &is_empty);
  rc = sfh_uint64_t_uint64_t_find_min(&heap, &out_node);

  rc = sfh_uint64_t_uint64_t_insert(&heap, &node2, 10, 0);
  rc = sfh_uint64_t_uint64_t_delete(&heap, &node);
  rc = sfh_uint64_t_uint64_t_delete_min(&heap);

  {
    sfh_uint64_t_uint64_t_heap_t h1, h2, h3, *merged;
    sfh_uint64_t_uint64_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint64_t_uint64_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint64_t_uint64_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint64_t_uint64_t_init(&h3);
    sfh_uint64_t_uint64_t_insert(&h1, &n1, 1, 0);
    sfh_uint64_t_uint64_t_insert(&h1, &n2, 2, 0);
    sfh_uint64_t_uint64_t_insert(&h1, &n3, 3, 0);
    sfh_uint64_t_uint64_t_insert(&h1, &n4, 4, 0);
    sfh_uint64_t_uint64_t_insert(&h2, &n5, 5, 0);

    sfh_uint64_t_uint64_t_meld(&h1, &h2, &merged);
    sfh_uint64_t_uint64_t_delete_min(merged);
    sfh_uint64_t_uint64_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint64_t_uint64_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint64_t_uint64_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint64_t_uint64_t_insert(&heap, &fnodes[idx],
                                            (uint64_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint64_t_uint64_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint64_t_uint64_t_decrease_key(&heap, &fnodes[idx],
                                                  (uint64_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint64_t_uint64_t_node_t *min;
          sfh_uint64_t_uint64_t_find_min(&heap, &min);
          rc = sfh_uint64_t_uint64_t_delete_min(&heap);
          if (rc == sfh_uint64_t_uint64_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint64_t_uint64_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint64_t_uint64_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint64_t_float(void) {
  sfh_uint64_t_float_heap_t heap;
  sfh_uint64_t_float_node_t node, node2;
  sfh_uint64_t_float_node_t *out_node;
  sfh_uint64_t_float_heap_t *out_heap;
  int is_empty;
  sfh_uint64_t_float_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint64_t_float_init(NULL);
  rc = sfh_uint64_t_float_empty(NULL, &is_empty);
  rc = sfh_uint64_t_float_find_min(NULL, &out_node);
  rc = sfh_uint64_t_float_insert(NULL, &node, 1, 0);
  rc = sfh_uint64_t_float_insert(&heap, NULL, 1, 0);
  rc = sfh_uint64_t_float_delete_min(NULL);
  rc = sfh_uint64_t_float_delete(NULL, &node);
  rc = sfh_uint64_t_float_delete(&heap, NULL);
  rc = sfh_uint64_t_float_decrease_key(NULL, &node, 1);
  rc = sfh_uint64_t_float_decrease_key(&heap, NULL, 1);
  rc = sfh_uint64_t_float_meld(NULL, &heap, &out_heap);
  rc = sfh_uint64_t_float_meld(&heap, NULL, &out_heap);
  rc = sfh_uint64_t_float_meld(&heap, &heap, NULL);

  sfh_uint64_t_float_init(&heap);
  rc = sfh_uint64_t_float_empty(&heap, &is_empty);
  rc = sfh_uint64_t_float_find_min(&heap, &out_node);
  rc = sfh_uint64_t_float_delete_min(&heap);

  rc = sfh_uint64_t_float_insert(&heap, &node, 10, 0);
  rc = sfh_uint64_t_float_empty(&heap, &is_empty);
  rc = sfh_uint64_t_float_find_min(&heap, &out_node);

  rc = sfh_uint64_t_float_insert(&heap, &node2, 10, 0);
  rc = sfh_uint64_t_float_delete(&heap, &node);
  rc = sfh_uint64_t_float_delete_min(&heap);

  {
    sfh_uint64_t_float_heap_t h1, h2, h3, *merged;
    sfh_uint64_t_float_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint64_t_float_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint64_t_float_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint64_t_float_init(&h3);
    sfh_uint64_t_float_insert(&h1, &n1, 1, 0);
    sfh_uint64_t_float_insert(&h1, &n2, 2, 0);
    sfh_uint64_t_float_insert(&h1, &n3, 3, 0);
    sfh_uint64_t_float_insert(&h1, &n4, 4, 0);
    sfh_uint64_t_float_insert(&h2, &n5, 5, 0);

    sfh_uint64_t_float_meld(&h1, &h2, &merged);
    sfh_uint64_t_float_delete_min(merged);
    sfh_uint64_t_float_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint64_t_float_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint64_t_float_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint64_t_float_insert(&heap, &fnodes[idx],
                                         (uint64_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint64_t_float_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc =
              sfh_uint64_t_float_decrease_key(&heap, &fnodes[idx], (uint64_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint64_t_float_node_t *min;
          sfh_uint64_t_float_find_min(&heap, &min);
          rc = sfh_uint64_t_float_delete_min(&heap);
          if (rc == sfh_uint64_t_float_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint64_t_float_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint64_t_float_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint64_t_double(void) {
  sfh_uint64_t_double_heap_t heap;
  sfh_uint64_t_double_node_t node, node2;
  sfh_uint64_t_double_node_t *out_node;
  sfh_uint64_t_double_heap_t *out_heap;
  int is_empty;
  sfh_uint64_t_double_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint64_t_double_init(NULL);
  rc = sfh_uint64_t_double_empty(NULL, &is_empty);
  rc = sfh_uint64_t_double_find_min(NULL, &out_node);
  rc = sfh_uint64_t_double_insert(NULL, &node, 1, 0);
  rc = sfh_uint64_t_double_insert(&heap, NULL, 1, 0);
  rc = sfh_uint64_t_double_delete_min(NULL);
  rc = sfh_uint64_t_double_delete(NULL, &node);
  rc = sfh_uint64_t_double_delete(&heap, NULL);
  rc = sfh_uint64_t_double_decrease_key(NULL, &node, 1);
  rc = sfh_uint64_t_double_decrease_key(&heap, NULL, 1);
  rc = sfh_uint64_t_double_meld(NULL, &heap, &out_heap);
  rc = sfh_uint64_t_double_meld(&heap, NULL, &out_heap);
  rc = sfh_uint64_t_double_meld(&heap, &heap, NULL);

  sfh_uint64_t_double_init(&heap);
  rc = sfh_uint64_t_double_empty(&heap, &is_empty);
  rc = sfh_uint64_t_double_find_min(&heap, &out_node);
  rc = sfh_uint64_t_double_delete_min(&heap);

  rc = sfh_uint64_t_double_insert(&heap, &node, 10, 0);
  rc = sfh_uint64_t_double_empty(&heap, &is_empty);
  rc = sfh_uint64_t_double_find_min(&heap, &out_node);

  rc = sfh_uint64_t_double_insert(&heap, &node2, 10, 0);
  rc = sfh_uint64_t_double_delete(&heap, &node);
  rc = sfh_uint64_t_double_delete_min(&heap);

  {
    sfh_uint64_t_double_heap_t h1, h2, h3, *merged;
    sfh_uint64_t_double_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint64_t_double_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint64_t_double_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint64_t_double_init(&h3);
    sfh_uint64_t_double_insert(&h1, &n1, 1, 0);
    sfh_uint64_t_double_insert(&h1, &n2, 2, 0);
    sfh_uint64_t_double_insert(&h1, &n3, 3, 0);
    sfh_uint64_t_double_insert(&h1, &n4, 4, 0);
    sfh_uint64_t_double_insert(&h2, &n5, 5, 0);

    sfh_uint64_t_double_meld(&h1, &h2, &merged);
    sfh_uint64_t_double_delete_min(merged);
    sfh_uint64_t_double_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint64_t_double_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint64_t_double_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint64_t_double_insert(&heap, &fnodes[idx],
                                          (uint64_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint64_t_double_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint64_t_double_decrease_key(&heap, &fnodes[idx],
                                                (uint64_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint64_t_double_node_t *min;
          sfh_uint64_t_double_find_min(&heap, &min);
          rc = sfh_uint64_t_double_delete_min(&heap);
          if (rc == sfh_uint64_t_double_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint64_t_double_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint64_t_double_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint64_t_charptr(void) {
  sfh_uint64_t_charptr_heap_t heap;
  sfh_uint64_t_charptr_node_t node, node2;
  sfh_uint64_t_charptr_node_t *out_node;
  sfh_uint64_t_charptr_heap_t *out_heap;
  int is_empty;
  sfh_uint64_t_charptr_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint64_t_charptr_init(NULL);
  rc = sfh_uint64_t_charptr_empty(NULL, &is_empty);
  rc = sfh_uint64_t_charptr_find_min(NULL, &out_node);
  rc = sfh_uint64_t_charptr_insert(NULL, &node, 1, 0);
  rc = sfh_uint64_t_charptr_insert(&heap, NULL, 1, 0);
  rc = sfh_uint64_t_charptr_delete_min(NULL);
  rc = sfh_uint64_t_charptr_delete(NULL, &node);
  rc = sfh_uint64_t_charptr_delete(&heap, NULL);
  rc = sfh_uint64_t_charptr_decrease_key(NULL, &node, 1);
  rc = sfh_uint64_t_charptr_decrease_key(&heap, NULL, 1);
  rc = sfh_uint64_t_charptr_meld(NULL, &heap, &out_heap);
  rc = sfh_uint64_t_charptr_meld(&heap, NULL, &out_heap);
  rc = sfh_uint64_t_charptr_meld(&heap, &heap, NULL);

  sfh_uint64_t_charptr_init(&heap);
  rc = sfh_uint64_t_charptr_empty(&heap, &is_empty);
  rc = sfh_uint64_t_charptr_find_min(&heap, &out_node);
  rc = sfh_uint64_t_charptr_delete_min(&heap);

  rc = sfh_uint64_t_charptr_insert(&heap, &node, 10, 0);
  rc = sfh_uint64_t_charptr_empty(&heap, &is_empty);
  rc = sfh_uint64_t_charptr_find_min(&heap, &out_node);

  rc = sfh_uint64_t_charptr_insert(&heap, &node2, 10, 0);
  rc = sfh_uint64_t_charptr_delete(&heap, &node);
  rc = sfh_uint64_t_charptr_delete_min(&heap);

  {
    sfh_uint64_t_charptr_heap_t h1, h2, h3, *merged;
    sfh_uint64_t_charptr_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint64_t_charptr_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint64_t_charptr_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint64_t_charptr_init(&h3);
    sfh_uint64_t_charptr_insert(&h1, &n1, 1, 0);
    sfh_uint64_t_charptr_insert(&h1, &n2, 2, 0);
    sfh_uint64_t_charptr_insert(&h1, &n3, 3, 0);
    sfh_uint64_t_charptr_insert(&h1, &n4, 4, 0);
    sfh_uint64_t_charptr_insert(&h2, &n5, 5, 0);

    sfh_uint64_t_charptr_meld(&h1, &h2, &merged);
    sfh_uint64_t_charptr_delete_min(merged);
    sfh_uint64_t_charptr_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint64_t_charptr_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint64_t_charptr_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint64_t_charptr_insert(&heap, &fnodes[idx],
                                           (uint64_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint64_t_charptr_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint64_t_charptr_decrease_key(&heap, &fnodes[idx],
                                                 (uint64_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint64_t_charptr_node_t *min;
          sfh_uint64_t_charptr_find_min(&heap, &min);
          rc = sfh_uint64_t_charptr_delete_min(&heap);
          if (rc == sfh_uint64_t_charptr_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint64_t_charptr_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint64_t_charptr_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_uint64_t_voidptr(void) {
  sfh_uint64_t_voidptr_heap_t heap;
  sfh_uint64_t_voidptr_node_t node, node2;
  sfh_uint64_t_voidptr_node_t *out_node;
  sfh_uint64_t_voidptr_heap_t *out_heap;
  int is_empty;
  sfh_uint64_t_voidptr_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_uint64_t_voidptr_init(NULL);
  rc = sfh_uint64_t_voidptr_empty(NULL, &is_empty);
  rc = sfh_uint64_t_voidptr_find_min(NULL, &out_node);
  rc = sfh_uint64_t_voidptr_insert(NULL, &node, 1, 0);
  rc = sfh_uint64_t_voidptr_insert(&heap, NULL, 1, 0);
  rc = sfh_uint64_t_voidptr_delete_min(NULL);
  rc = sfh_uint64_t_voidptr_delete(NULL, &node);
  rc = sfh_uint64_t_voidptr_delete(&heap, NULL);
  rc = sfh_uint64_t_voidptr_decrease_key(NULL, &node, 1);
  rc = sfh_uint64_t_voidptr_decrease_key(&heap, NULL, 1);
  rc = sfh_uint64_t_voidptr_meld(NULL, &heap, &out_heap);
  rc = sfh_uint64_t_voidptr_meld(&heap, NULL, &out_heap);
  rc = sfh_uint64_t_voidptr_meld(&heap, &heap, NULL);

  sfh_uint64_t_voidptr_init(&heap);
  rc = sfh_uint64_t_voidptr_empty(&heap, &is_empty);
  rc = sfh_uint64_t_voidptr_find_min(&heap, &out_node);
  rc = sfh_uint64_t_voidptr_delete_min(&heap);

  rc = sfh_uint64_t_voidptr_insert(&heap, &node, 10, 0);
  rc = sfh_uint64_t_voidptr_empty(&heap, &is_empty);
  rc = sfh_uint64_t_voidptr_find_min(&heap, &out_node);

  rc = sfh_uint64_t_voidptr_insert(&heap, &node2, 10, 0);
  rc = sfh_uint64_t_voidptr_delete(&heap, &node);
  rc = sfh_uint64_t_voidptr_delete_min(&heap);

  {
    sfh_uint64_t_voidptr_heap_t h1, h2, h3, *merged;
    sfh_uint64_t_voidptr_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_uint64_t_voidptr_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_uint64_t_voidptr_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_uint64_t_voidptr_init(&h3);
    sfh_uint64_t_voidptr_insert(&h1, &n1, 1, 0);
    sfh_uint64_t_voidptr_insert(&h1, &n2, 2, 0);
    sfh_uint64_t_voidptr_insert(&h1, &n3, 3, 0);
    sfh_uint64_t_voidptr_insert(&h1, &n4, 4, 0);
    sfh_uint64_t_voidptr_insert(&h2, &n5, 5, 0);

    sfh_uint64_t_voidptr_meld(&h1, &h2, &merged);
    sfh_uint64_t_voidptr_delete_min(merged);
    sfh_uint64_t_voidptr_meld(&h3, merged, &merged);
  }

  {
    static sfh_uint64_t_voidptr_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_uint64_t_voidptr_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_uint64_t_voidptr_insert(&heap, &fnodes[idx],
                                           (uint64_t)((seed >> 8) % 1000), 0);
          if (rc == sfh_uint64_t_voidptr_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_uint64_t_voidptr_decrease_key(&heap, &fnodes[idx],
                                                 (uint64_t)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_uint64_t_voidptr_node_t *min;
          sfh_uint64_t_voidptr_find_min(&heap, &min);
          rc = sfh_uint64_t_voidptr_delete_min(&heap);
          if (rc == sfh_uint64_t_voidptr_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_uint64_t_voidptr_delete(&heap, &fnodes[idx]);
          if (rc == sfh_uint64_t_voidptr_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_float_int8_t(void) {
  sfh_float_int8_t_heap_t heap;
  sfh_float_int8_t_node_t node, node2;
  sfh_float_int8_t_node_t *out_node;
  sfh_float_int8_t_heap_t *out_heap;
  int is_empty;
  sfh_float_int8_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_float_int8_t_init(NULL);
  rc = sfh_float_int8_t_empty(NULL, &is_empty);
  rc = sfh_float_int8_t_find_min(NULL, &out_node);
  rc = sfh_float_int8_t_insert(NULL, &node, 1, 0);
  rc = sfh_float_int8_t_insert(&heap, NULL, 1, 0);
  rc = sfh_float_int8_t_delete_min(NULL);
  rc = sfh_float_int8_t_delete(NULL, &node);
  rc = sfh_float_int8_t_delete(&heap, NULL);
  rc = sfh_float_int8_t_decrease_key(NULL, &node, 1);
  rc = sfh_float_int8_t_decrease_key(&heap, NULL, 1);
  rc = sfh_float_int8_t_meld(NULL, &heap, &out_heap);
  rc = sfh_float_int8_t_meld(&heap, NULL, &out_heap);
  rc = sfh_float_int8_t_meld(&heap, &heap, NULL);

  sfh_float_int8_t_init(&heap);
  rc = sfh_float_int8_t_empty(&heap, &is_empty);
  rc = sfh_float_int8_t_find_min(&heap, &out_node);
  rc = sfh_float_int8_t_delete_min(&heap);

  rc = sfh_float_int8_t_insert(&heap, &node, 10, 0);
  rc = sfh_float_int8_t_empty(&heap, &is_empty);
  rc = sfh_float_int8_t_find_min(&heap, &out_node);

  rc = sfh_float_int8_t_insert(&heap, &node2, 10, 0);
  rc = sfh_float_int8_t_delete(&heap, &node);
  rc = sfh_float_int8_t_delete_min(&heap);

  {
    sfh_float_int8_t_heap_t h1, h2, h3, *merged;
    sfh_float_int8_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_float_int8_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_float_int8_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_float_int8_t_init(&h3);
    sfh_float_int8_t_insert(&h1, &n1, 1, 0);
    sfh_float_int8_t_insert(&h1, &n2, 2, 0);
    sfh_float_int8_t_insert(&h1, &n3, 3, 0);
    sfh_float_int8_t_insert(&h1, &n4, 4, 0);
    sfh_float_int8_t_insert(&h2, &n5, 5, 0);

    sfh_float_int8_t_meld(&h1, &h2, &merged);
    sfh_float_int8_t_delete_min(merged);
    sfh_float_int8_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_float_int8_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_float_int8_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_float_int8_t_insert(&heap, &fnodes[idx],
                                       (float)((seed >> 8) % 1000), 0);
          if (rc == sfh_float_int8_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_float_int8_t_decrease_key(&heap, &fnodes[idx], (float)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_float_int8_t_node_t *min;
          sfh_float_int8_t_find_min(&heap, &min);
          rc = sfh_float_int8_t_delete_min(&heap);
          if (rc == sfh_float_int8_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_float_int8_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_float_int8_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_float_int16_t(void) {
  sfh_float_int16_t_heap_t heap;
  sfh_float_int16_t_node_t node, node2;
  sfh_float_int16_t_node_t *out_node;
  sfh_float_int16_t_heap_t *out_heap;
  int is_empty;
  sfh_float_int16_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_float_int16_t_init(NULL);
  rc = sfh_float_int16_t_empty(NULL, &is_empty);
  rc = sfh_float_int16_t_find_min(NULL, &out_node);
  rc = sfh_float_int16_t_insert(NULL, &node, 1, 0);
  rc = sfh_float_int16_t_insert(&heap, NULL, 1, 0);
  rc = sfh_float_int16_t_delete_min(NULL);
  rc = sfh_float_int16_t_delete(NULL, &node);
  rc = sfh_float_int16_t_delete(&heap, NULL);
  rc = sfh_float_int16_t_decrease_key(NULL, &node, 1);
  rc = sfh_float_int16_t_decrease_key(&heap, NULL, 1);
  rc = sfh_float_int16_t_meld(NULL, &heap, &out_heap);
  rc = sfh_float_int16_t_meld(&heap, NULL, &out_heap);
  rc = sfh_float_int16_t_meld(&heap, &heap, NULL);

  sfh_float_int16_t_init(&heap);
  rc = sfh_float_int16_t_empty(&heap, &is_empty);
  rc = sfh_float_int16_t_find_min(&heap, &out_node);
  rc = sfh_float_int16_t_delete_min(&heap);

  rc = sfh_float_int16_t_insert(&heap, &node, 10, 0);
  rc = sfh_float_int16_t_empty(&heap, &is_empty);
  rc = sfh_float_int16_t_find_min(&heap, &out_node);

  rc = sfh_float_int16_t_insert(&heap, &node2, 10, 0);
  rc = sfh_float_int16_t_delete(&heap, &node);
  rc = sfh_float_int16_t_delete_min(&heap);

  {
    sfh_float_int16_t_heap_t h1, h2, h3, *merged;
    sfh_float_int16_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_float_int16_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_float_int16_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_float_int16_t_init(&h3);
    sfh_float_int16_t_insert(&h1, &n1, 1, 0);
    sfh_float_int16_t_insert(&h1, &n2, 2, 0);
    sfh_float_int16_t_insert(&h1, &n3, 3, 0);
    sfh_float_int16_t_insert(&h1, &n4, 4, 0);
    sfh_float_int16_t_insert(&h2, &n5, 5, 0);

    sfh_float_int16_t_meld(&h1, &h2, &merged);
    sfh_float_int16_t_delete_min(merged);
    sfh_float_int16_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_float_int16_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_float_int16_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_float_int16_t_insert(&heap, &fnodes[idx],
                                        (float)((seed >> 8) % 1000), 0);
          if (rc == sfh_float_int16_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_float_int16_t_decrease_key(&heap, &fnodes[idx], (float)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_float_int16_t_node_t *min;
          sfh_float_int16_t_find_min(&heap, &min);
          rc = sfh_float_int16_t_delete_min(&heap);
          if (rc == sfh_float_int16_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_float_int16_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_float_int16_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_float_int32_t(void) {
  sfh_float_int32_t_heap_t heap;
  sfh_float_int32_t_node_t node, node2;
  sfh_float_int32_t_node_t *out_node;
  sfh_float_int32_t_heap_t *out_heap;
  int is_empty;
  sfh_float_int32_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_float_int32_t_init(NULL);
  rc = sfh_float_int32_t_empty(NULL, &is_empty);
  rc = sfh_float_int32_t_find_min(NULL, &out_node);
  rc = sfh_float_int32_t_insert(NULL, &node, 1, 0);
  rc = sfh_float_int32_t_insert(&heap, NULL, 1, 0);
  rc = sfh_float_int32_t_delete_min(NULL);
  rc = sfh_float_int32_t_delete(NULL, &node);
  rc = sfh_float_int32_t_delete(&heap, NULL);
  rc = sfh_float_int32_t_decrease_key(NULL, &node, 1);
  rc = sfh_float_int32_t_decrease_key(&heap, NULL, 1);
  rc = sfh_float_int32_t_meld(NULL, &heap, &out_heap);
  rc = sfh_float_int32_t_meld(&heap, NULL, &out_heap);
  rc = sfh_float_int32_t_meld(&heap, &heap, NULL);

  sfh_float_int32_t_init(&heap);
  rc = sfh_float_int32_t_empty(&heap, &is_empty);
  rc = sfh_float_int32_t_find_min(&heap, &out_node);
  rc = sfh_float_int32_t_delete_min(&heap);

  rc = sfh_float_int32_t_insert(&heap, &node, 10, 0);
  rc = sfh_float_int32_t_empty(&heap, &is_empty);
  rc = sfh_float_int32_t_find_min(&heap, &out_node);

  rc = sfh_float_int32_t_insert(&heap, &node2, 10, 0);
  rc = sfh_float_int32_t_delete(&heap, &node);
  rc = sfh_float_int32_t_delete_min(&heap);

  {
    sfh_float_int32_t_heap_t h1, h2, h3, *merged;
    sfh_float_int32_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_float_int32_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_float_int32_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_float_int32_t_init(&h3);
    sfh_float_int32_t_insert(&h1, &n1, 1, 0);
    sfh_float_int32_t_insert(&h1, &n2, 2, 0);
    sfh_float_int32_t_insert(&h1, &n3, 3, 0);
    sfh_float_int32_t_insert(&h1, &n4, 4, 0);
    sfh_float_int32_t_insert(&h2, &n5, 5, 0);

    sfh_float_int32_t_meld(&h1, &h2, &merged);
    sfh_float_int32_t_delete_min(merged);
    sfh_float_int32_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_float_int32_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_float_int32_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_float_int32_t_insert(&heap, &fnodes[idx],
                                        (float)((seed >> 8) % 1000), 0);
          if (rc == sfh_float_int32_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_float_int32_t_decrease_key(&heap, &fnodes[idx], (float)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_float_int32_t_node_t *min;
          sfh_float_int32_t_find_min(&heap, &min);
          rc = sfh_float_int32_t_delete_min(&heap);
          if (rc == sfh_float_int32_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_float_int32_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_float_int32_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_float_int64_t(void) {
  sfh_float_int64_t_heap_t heap;
  sfh_float_int64_t_node_t node, node2;
  sfh_float_int64_t_node_t *out_node;
  sfh_float_int64_t_heap_t *out_heap;
  int is_empty;
  sfh_float_int64_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_float_int64_t_init(NULL);
  rc = sfh_float_int64_t_empty(NULL, &is_empty);
  rc = sfh_float_int64_t_find_min(NULL, &out_node);
  rc = sfh_float_int64_t_insert(NULL, &node, 1, 0);
  rc = sfh_float_int64_t_insert(&heap, NULL, 1, 0);
  rc = sfh_float_int64_t_delete_min(NULL);
  rc = sfh_float_int64_t_delete(NULL, &node);
  rc = sfh_float_int64_t_delete(&heap, NULL);
  rc = sfh_float_int64_t_decrease_key(NULL, &node, 1);
  rc = sfh_float_int64_t_decrease_key(&heap, NULL, 1);
  rc = sfh_float_int64_t_meld(NULL, &heap, &out_heap);
  rc = sfh_float_int64_t_meld(&heap, NULL, &out_heap);
  rc = sfh_float_int64_t_meld(&heap, &heap, NULL);

  sfh_float_int64_t_init(&heap);
  rc = sfh_float_int64_t_empty(&heap, &is_empty);
  rc = sfh_float_int64_t_find_min(&heap, &out_node);
  rc = sfh_float_int64_t_delete_min(&heap);

  rc = sfh_float_int64_t_insert(&heap, &node, 10, 0);
  rc = sfh_float_int64_t_empty(&heap, &is_empty);
  rc = sfh_float_int64_t_find_min(&heap, &out_node);

  rc = sfh_float_int64_t_insert(&heap, &node2, 10, 0);
  rc = sfh_float_int64_t_delete(&heap, &node);
  rc = sfh_float_int64_t_delete_min(&heap);

  {
    sfh_float_int64_t_heap_t h1, h2, h3, *merged;
    sfh_float_int64_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_float_int64_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_float_int64_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_float_int64_t_init(&h3);
    sfh_float_int64_t_insert(&h1, &n1, 1, 0);
    sfh_float_int64_t_insert(&h1, &n2, 2, 0);
    sfh_float_int64_t_insert(&h1, &n3, 3, 0);
    sfh_float_int64_t_insert(&h1, &n4, 4, 0);
    sfh_float_int64_t_insert(&h2, &n5, 5, 0);

    sfh_float_int64_t_meld(&h1, &h2, &merged);
    sfh_float_int64_t_delete_min(merged);
    sfh_float_int64_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_float_int64_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_float_int64_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_float_int64_t_insert(&heap, &fnodes[idx],
                                        (float)((seed >> 8) % 1000), 0);
          if (rc == sfh_float_int64_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_float_int64_t_decrease_key(&heap, &fnodes[idx], (float)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_float_int64_t_node_t *min;
          sfh_float_int64_t_find_min(&heap, &min);
          rc = sfh_float_int64_t_delete_min(&heap);
          if (rc == sfh_float_int64_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_float_int64_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_float_int64_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_float_uint8_t(void) {
  sfh_float_uint8_t_heap_t heap;
  sfh_float_uint8_t_node_t node, node2;
  sfh_float_uint8_t_node_t *out_node;
  sfh_float_uint8_t_heap_t *out_heap;
  int is_empty;
  sfh_float_uint8_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_float_uint8_t_init(NULL);
  rc = sfh_float_uint8_t_empty(NULL, &is_empty);
  rc = sfh_float_uint8_t_find_min(NULL, &out_node);
  rc = sfh_float_uint8_t_insert(NULL, &node, 1, 0);
  rc = sfh_float_uint8_t_insert(&heap, NULL, 1, 0);
  rc = sfh_float_uint8_t_delete_min(NULL);
  rc = sfh_float_uint8_t_delete(NULL, &node);
  rc = sfh_float_uint8_t_delete(&heap, NULL);
  rc = sfh_float_uint8_t_decrease_key(NULL, &node, 1);
  rc = sfh_float_uint8_t_decrease_key(&heap, NULL, 1);
  rc = sfh_float_uint8_t_meld(NULL, &heap, &out_heap);
  rc = sfh_float_uint8_t_meld(&heap, NULL, &out_heap);
  rc = sfh_float_uint8_t_meld(&heap, &heap, NULL);

  sfh_float_uint8_t_init(&heap);
  rc = sfh_float_uint8_t_empty(&heap, &is_empty);
  rc = sfh_float_uint8_t_find_min(&heap, &out_node);
  rc = sfh_float_uint8_t_delete_min(&heap);

  rc = sfh_float_uint8_t_insert(&heap, &node, 10, 0);
  rc = sfh_float_uint8_t_empty(&heap, &is_empty);
  rc = sfh_float_uint8_t_find_min(&heap, &out_node);

  rc = sfh_float_uint8_t_insert(&heap, &node2, 10, 0);
  rc = sfh_float_uint8_t_delete(&heap, &node);
  rc = sfh_float_uint8_t_delete_min(&heap);

  {
    sfh_float_uint8_t_heap_t h1, h2, h3, *merged;
    sfh_float_uint8_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_float_uint8_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_float_uint8_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_float_uint8_t_init(&h3);
    sfh_float_uint8_t_insert(&h1, &n1, 1, 0);
    sfh_float_uint8_t_insert(&h1, &n2, 2, 0);
    sfh_float_uint8_t_insert(&h1, &n3, 3, 0);
    sfh_float_uint8_t_insert(&h1, &n4, 4, 0);
    sfh_float_uint8_t_insert(&h2, &n5, 5, 0);

    sfh_float_uint8_t_meld(&h1, &h2, &merged);
    sfh_float_uint8_t_delete_min(merged);
    sfh_float_uint8_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_float_uint8_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_float_uint8_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_float_uint8_t_insert(&heap, &fnodes[idx],
                                        (float)((seed >> 8) % 1000), 0);
          if (rc == sfh_float_uint8_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_float_uint8_t_decrease_key(&heap, &fnodes[idx], (float)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_float_uint8_t_node_t *min;
          sfh_float_uint8_t_find_min(&heap, &min);
          rc = sfh_float_uint8_t_delete_min(&heap);
          if (rc == sfh_float_uint8_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_float_uint8_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_float_uint8_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_float_uint16_t(void) {
  sfh_float_uint16_t_heap_t heap;
  sfh_float_uint16_t_node_t node, node2;
  sfh_float_uint16_t_node_t *out_node;
  sfh_float_uint16_t_heap_t *out_heap;
  int is_empty;
  sfh_float_uint16_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_float_uint16_t_init(NULL);
  rc = sfh_float_uint16_t_empty(NULL, &is_empty);
  rc = sfh_float_uint16_t_find_min(NULL, &out_node);
  rc = sfh_float_uint16_t_insert(NULL, &node, 1, 0);
  rc = sfh_float_uint16_t_insert(&heap, NULL, 1, 0);
  rc = sfh_float_uint16_t_delete_min(NULL);
  rc = sfh_float_uint16_t_delete(NULL, &node);
  rc = sfh_float_uint16_t_delete(&heap, NULL);
  rc = sfh_float_uint16_t_decrease_key(NULL, &node, 1);
  rc = sfh_float_uint16_t_decrease_key(&heap, NULL, 1);
  rc = sfh_float_uint16_t_meld(NULL, &heap, &out_heap);
  rc = sfh_float_uint16_t_meld(&heap, NULL, &out_heap);
  rc = sfh_float_uint16_t_meld(&heap, &heap, NULL);

  sfh_float_uint16_t_init(&heap);
  rc = sfh_float_uint16_t_empty(&heap, &is_empty);
  rc = sfh_float_uint16_t_find_min(&heap, &out_node);
  rc = sfh_float_uint16_t_delete_min(&heap);

  rc = sfh_float_uint16_t_insert(&heap, &node, 10, 0);
  rc = sfh_float_uint16_t_empty(&heap, &is_empty);
  rc = sfh_float_uint16_t_find_min(&heap, &out_node);

  rc = sfh_float_uint16_t_insert(&heap, &node2, 10, 0);
  rc = sfh_float_uint16_t_delete(&heap, &node);
  rc = sfh_float_uint16_t_delete_min(&heap);

  {
    sfh_float_uint16_t_heap_t h1, h2, h3, *merged;
    sfh_float_uint16_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_float_uint16_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_float_uint16_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_float_uint16_t_init(&h3);
    sfh_float_uint16_t_insert(&h1, &n1, 1, 0);
    sfh_float_uint16_t_insert(&h1, &n2, 2, 0);
    sfh_float_uint16_t_insert(&h1, &n3, 3, 0);
    sfh_float_uint16_t_insert(&h1, &n4, 4, 0);
    sfh_float_uint16_t_insert(&h2, &n5, 5, 0);

    sfh_float_uint16_t_meld(&h1, &h2, &merged);
    sfh_float_uint16_t_delete_min(merged);
    sfh_float_uint16_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_float_uint16_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_float_uint16_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_float_uint16_t_insert(&heap, &fnodes[idx],
                                         (float)((seed >> 8) % 1000), 0);
          if (rc == sfh_float_uint16_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_float_uint16_t_decrease_key(&heap, &fnodes[idx], (float)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_float_uint16_t_node_t *min;
          sfh_float_uint16_t_find_min(&heap, &min);
          rc = sfh_float_uint16_t_delete_min(&heap);
          if (rc == sfh_float_uint16_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_float_uint16_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_float_uint16_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_float_uint32_t(void) {
  sfh_float_uint32_t_heap_t heap;
  sfh_float_uint32_t_node_t node, node2;
  sfh_float_uint32_t_node_t *out_node;
  sfh_float_uint32_t_heap_t *out_heap;
  int is_empty;
  sfh_float_uint32_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_float_uint32_t_init(NULL);
  rc = sfh_float_uint32_t_empty(NULL, &is_empty);
  rc = sfh_float_uint32_t_find_min(NULL, &out_node);
  rc = sfh_float_uint32_t_insert(NULL, &node, 1, 0);
  rc = sfh_float_uint32_t_insert(&heap, NULL, 1, 0);
  rc = sfh_float_uint32_t_delete_min(NULL);
  rc = sfh_float_uint32_t_delete(NULL, &node);
  rc = sfh_float_uint32_t_delete(&heap, NULL);
  rc = sfh_float_uint32_t_decrease_key(NULL, &node, 1);
  rc = sfh_float_uint32_t_decrease_key(&heap, NULL, 1);
  rc = sfh_float_uint32_t_meld(NULL, &heap, &out_heap);
  rc = sfh_float_uint32_t_meld(&heap, NULL, &out_heap);
  rc = sfh_float_uint32_t_meld(&heap, &heap, NULL);

  sfh_float_uint32_t_init(&heap);
  rc = sfh_float_uint32_t_empty(&heap, &is_empty);
  rc = sfh_float_uint32_t_find_min(&heap, &out_node);
  rc = sfh_float_uint32_t_delete_min(&heap);

  rc = sfh_float_uint32_t_insert(&heap, &node, 10, 0);
  rc = sfh_float_uint32_t_empty(&heap, &is_empty);
  rc = sfh_float_uint32_t_find_min(&heap, &out_node);

  rc = sfh_float_uint32_t_insert(&heap, &node2, 10, 0);
  rc = sfh_float_uint32_t_delete(&heap, &node);
  rc = sfh_float_uint32_t_delete_min(&heap);

  {
    sfh_float_uint32_t_heap_t h1, h2, h3, *merged;
    sfh_float_uint32_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_float_uint32_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_float_uint32_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_float_uint32_t_init(&h3);
    sfh_float_uint32_t_insert(&h1, &n1, 1, 0);
    sfh_float_uint32_t_insert(&h1, &n2, 2, 0);
    sfh_float_uint32_t_insert(&h1, &n3, 3, 0);
    sfh_float_uint32_t_insert(&h1, &n4, 4, 0);
    sfh_float_uint32_t_insert(&h2, &n5, 5, 0);

    sfh_float_uint32_t_meld(&h1, &h2, &merged);
    sfh_float_uint32_t_delete_min(merged);
    sfh_float_uint32_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_float_uint32_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_float_uint32_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_float_uint32_t_insert(&heap, &fnodes[idx],
                                         (float)((seed >> 8) % 1000), 0);
          if (rc == sfh_float_uint32_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_float_uint32_t_decrease_key(&heap, &fnodes[idx], (float)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_float_uint32_t_node_t *min;
          sfh_float_uint32_t_find_min(&heap, &min);
          rc = sfh_float_uint32_t_delete_min(&heap);
          if (rc == sfh_float_uint32_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_float_uint32_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_float_uint32_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_float_uint64_t(void) {
  sfh_float_uint64_t_heap_t heap;
  sfh_float_uint64_t_node_t node, node2;
  sfh_float_uint64_t_node_t *out_node;
  sfh_float_uint64_t_heap_t *out_heap;
  int is_empty;
  sfh_float_uint64_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_float_uint64_t_init(NULL);
  rc = sfh_float_uint64_t_empty(NULL, &is_empty);
  rc = sfh_float_uint64_t_find_min(NULL, &out_node);
  rc = sfh_float_uint64_t_insert(NULL, &node, 1, 0);
  rc = sfh_float_uint64_t_insert(&heap, NULL, 1, 0);
  rc = sfh_float_uint64_t_delete_min(NULL);
  rc = sfh_float_uint64_t_delete(NULL, &node);
  rc = sfh_float_uint64_t_delete(&heap, NULL);
  rc = sfh_float_uint64_t_decrease_key(NULL, &node, 1);
  rc = sfh_float_uint64_t_decrease_key(&heap, NULL, 1);
  rc = sfh_float_uint64_t_meld(NULL, &heap, &out_heap);
  rc = sfh_float_uint64_t_meld(&heap, NULL, &out_heap);
  rc = sfh_float_uint64_t_meld(&heap, &heap, NULL);

  sfh_float_uint64_t_init(&heap);
  rc = sfh_float_uint64_t_empty(&heap, &is_empty);
  rc = sfh_float_uint64_t_find_min(&heap, &out_node);
  rc = sfh_float_uint64_t_delete_min(&heap);

  rc = sfh_float_uint64_t_insert(&heap, &node, 10, 0);
  rc = sfh_float_uint64_t_empty(&heap, &is_empty);
  rc = sfh_float_uint64_t_find_min(&heap, &out_node);

  rc = sfh_float_uint64_t_insert(&heap, &node2, 10, 0);
  rc = sfh_float_uint64_t_delete(&heap, &node);
  rc = sfh_float_uint64_t_delete_min(&heap);

  {
    sfh_float_uint64_t_heap_t h1, h2, h3, *merged;
    sfh_float_uint64_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_float_uint64_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_float_uint64_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_float_uint64_t_init(&h3);
    sfh_float_uint64_t_insert(&h1, &n1, 1, 0);
    sfh_float_uint64_t_insert(&h1, &n2, 2, 0);
    sfh_float_uint64_t_insert(&h1, &n3, 3, 0);
    sfh_float_uint64_t_insert(&h1, &n4, 4, 0);
    sfh_float_uint64_t_insert(&h2, &n5, 5, 0);

    sfh_float_uint64_t_meld(&h1, &h2, &merged);
    sfh_float_uint64_t_delete_min(merged);
    sfh_float_uint64_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_float_uint64_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_float_uint64_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_float_uint64_t_insert(&heap, &fnodes[idx],
                                         (float)((seed >> 8) % 1000), 0);
          if (rc == sfh_float_uint64_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_float_uint64_t_decrease_key(&heap, &fnodes[idx], (float)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_float_uint64_t_node_t *min;
          sfh_float_uint64_t_find_min(&heap, &min);
          rc = sfh_float_uint64_t_delete_min(&heap);
          if (rc == sfh_float_uint64_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_float_uint64_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_float_uint64_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_float_float(void) {
  sfh_float_float_heap_t heap;
  sfh_float_float_node_t node, node2;
  sfh_float_float_node_t *out_node;
  sfh_float_float_heap_t *out_heap;
  int is_empty;
  sfh_float_float_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_float_float_init(NULL);
  rc = sfh_float_float_empty(NULL, &is_empty);
  rc = sfh_float_float_find_min(NULL, &out_node);
  rc = sfh_float_float_insert(NULL, &node, 1, 0);
  rc = sfh_float_float_insert(&heap, NULL, 1, 0);
  rc = sfh_float_float_delete_min(NULL);
  rc = sfh_float_float_delete(NULL, &node);
  rc = sfh_float_float_delete(&heap, NULL);
  rc = sfh_float_float_decrease_key(NULL, &node, 1);
  rc = sfh_float_float_decrease_key(&heap, NULL, 1);
  rc = sfh_float_float_meld(NULL, &heap, &out_heap);
  rc = sfh_float_float_meld(&heap, NULL, &out_heap);
  rc = sfh_float_float_meld(&heap, &heap, NULL);

  sfh_float_float_init(&heap);
  rc = sfh_float_float_empty(&heap, &is_empty);
  rc = sfh_float_float_find_min(&heap, &out_node);
  rc = sfh_float_float_delete_min(&heap);

  rc = sfh_float_float_insert(&heap, &node, 10, 0);
  rc = sfh_float_float_empty(&heap, &is_empty);
  rc = sfh_float_float_find_min(&heap, &out_node);

  rc = sfh_float_float_insert(&heap, &node2, 10, 0);
  rc = sfh_float_float_delete(&heap, &node);
  rc = sfh_float_float_delete_min(&heap);

  {
    sfh_float_float_heap_t h1, h2, h3, *merged;
    sfh_float_float_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_float_float_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_float_float_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_float_float_init(&h3);
    sfh_float_float_insert(&h1, &n1, 1, 0);
    sfh_float_float_insert(&h1, &n2, 2, 0);
    sfh_float_float_insert(&h1, &n3, 3, 0);
    sfh_float_float_insert(&h1, &n4, 4, 0);
    sfh_float_float_insert(&h2, &n5, 5, 0);

    sfh_float_float_meld(&h1, &h2, &merged);
    sfh_float_float_delete_min(merged);
    sfh_float_float_meld(&h3, merged, &merged);
  }

  {
    static sfh_float_float_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_float_float_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_float_float_insert(&heap, &fnodes[idx],
                                      (float)((seed >> 8) % 1000), 0);
          if (rc == sfh_float_float_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_float_float_decrease_key(&heap, &fnodes[idx], (float)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_float_float_node_t *min;
          sfh_float_float_find_min(&heap, &min);
          rc = sfh_float_float_delete_min(&heap);
          if (rc == sfh_float_float_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_float_float_delete(&heap, &fnodes[idx]);
          if (rc == sfh_float_float_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_float_double(void) {
  sfh_float_double_heap_t heap;
  sfh_float_double_node_t node, node2;
  sfh_float_double_node_t *out_node;
  sfh_float_double_heap_t *out_heap;
  int is_empty;
  sfh_float_double_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_float_double_init(NULL);
  rc = sfh_float_double_empty(NULL, &is_empty);
  rc = sfh_float_double_find_min(NULL, &out_node);
  rc = sfh_float_double_insert(NULL, &node, 1, 0);
  rc = sfh_float_double_insert(&heap, NULL, 1, 0);
  rc = sfh_float_double_delete_min(NULL);
  rc = sfh_float_double_delete(NULL, &node);
  rc = sfh_float_double_delete(&heap, NULL);
  rc = sfh_float_double_decrease_key(NULL, &node, 1);
  rc = sfh_float_double_decrease_key(&heap, NULL, 1);
  rc = sfh_float_double_meld(NULL, &heap, &out_heap);
  rc = sfh_float_double_meld(&heap, NULL, &out_heap);
  rc = sfh_float_double_meld(&heap, &heap, NULL);

  sfh_float_double_init(&heap);
  rc = sfh_float_double_empty(&heap, &is_empty);
  rc = sfh_float_double_find_min(&heap, &out_node);
  rc = sfh_float_double_delete_min(&heap);

  rc = sfh_float_double_insert(&heap, &node, 10, 0);
  rc = sfh_float_double_empty(&heap, &is_empty);
  rc = sfh_float_double_find_min(&heap, &out_node);

  rc = sfh_float_double_insert(&heap, &node2, 10, 0);
  rc = sfh_float_double_delete(&heap, &node);
  rc = sfh_float_double_delete_min(&heap);

  {
    sfh_float_double_heap_t h1, h2, h3, *merged;
    sfh_float_double_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_float_double_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_float_double_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_float_double_init(&h3);
    sfh_float_double_insert(&h1, &n1, 1, 0);
    sfh_float_double_insert(&h1, &n2, 2, 0);
    sfh_float_double_insert(&h1, &n3, 3, 0);
    sfh_float_double_insert(&h1, &n4, 4, 0);
    sfh_float_double_insert(&h2, &n5, 5, 0);

    sfh_float_double_meld(&h1, &h2, &merged);
    sfh_float_double_delete_min(merged);
    sfh_float_double_meld(&h3, merged, &merged);
  }

  {
    static sfh_float_double_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_float_double_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_float_double_insert(&heap, &fnodes[idx],
                                       (float)((seed >> 8) % 1000), 0);
          if (rc == sfh_float_double_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_float_double_decrease_key(&heap, &fnodes[idx], (float)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_float_double_node_t *min;
          sfh_float_double_find_min(&heap, &min);
          rc = sfh_float_double_delete_min(&heap);
          if (rc == sfh_float_double_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_float_double_delete(&heap, &fnodes[idx]);
          if (rc == sfh_float_double_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_float_charptr(void) {
  sfh_float_charptr_heap_t heap;
  sfh_float_charptr_node_t node, node2;
  sfh_float_charptr_node_t *out_node;
  sfh_float_charptr_heap_t *out_heap;
  int is_empty;
  sfh_float_charptr_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_float_charptr_init(NULL);
  rc = sfh_float_charptr_empty(NULL, &is_empty);
  rc = sfh_float_charptr_find_min(NULL, &out_node);
  rc = sfh_float_charptr_insert(NULL, &node, 1, 0);
  rc = sfh_float_charptr_insert(&heap, NULL, 1, 0);
  rc = sfh_float_charptr_delete_min(NULL);
  rc = sfh_float_charptr_delete(NULL, &node);
  rc = sfh_float_charptr_delete(&heap, NULL);
  rc = sfh_float_charptr_decrease_key(NULL, &node, 1);
  rc = sfh_float_charptr_decrease_key(&heap, NULL, 1);
  rc = sfh_float_charptr_meld(NULL, &heap, &out_heap);
  rc = sfh_float_charptr_meld(&heap, NULL, &out_heap);
  rc = sfh_float_charptr_meld(&heap, &heap, NULL);

  sfh_float_charptr_init(&heap);
  rc = sfh_float_charptr_empty(&heap, &is_empty);
  rc = sfh_float_charptr_find_min(&heap, &out_node);
  rc = sfh_float_charptr_delete_min(&heap);

  rc = sfh_float_charptr_insert(&heap, &node, 10, 0);
  rc = sfh_float_charptr_empty(&heap, &is_empty);
  rc = sfh_float_charptr_find_min(&heap, &out_node);

  rc = sfh_float_charptr_insert(&heap, &node2, 10, 0);
  rc = sfh_float_charptr_delete(&heap, &node);
  rc = sfh_float_charptr_delete_min(&heap);

  {
    sfh_float_charptr_heap_t h1, h2, h3, *merged;
    sfh_float_charptr_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_float_charptr_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_float_charptr_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_float_charptr_init(&h3);
    sfh_float_charptr_insert(&h1, &n1, 1, 0);
    sfh_float_charptr_insert(&h1, &n2, 2, 0);
    sfh_float_charptr_insert(&h1, &n3, 3, 0);
    sfh_float_charptr_insert(&h1, &n4, 4, 0);
    sfh_float_charptr_insert(&h2, &n5, 5, 0);

    sfh_float_charptr_meld(&h1, &h2, &merged);
    sfh_float_charptr_delete_min(merged);
    sfh_float_charptr_meld(&h3, merged, &merged);
  }

  {
    static sfh_float_charptr_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_float_charptr_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_float_charptr_insert(&heap, &fnodes[idx],
                                        (float)((seed >> 8) % 1000), 0);
          if (rc == sfh_float_charptr_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_float_charptr_decrease_key(&heap, &fnodes[idx], (float)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_float_charptr_node_t *min;
          sfh_float_charptr_find_min(&heap, &min);
          rc = sfh_float_charptr_delete_min(&heap);
          if (rc == sfh_float_charptr_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_float_charptr_delete(&heap, &fnodes[idx]);
          if (rc == sfh_float_charptr_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_float_voidptr(void) {
  sfh_float_voidptr_heap_t heap;
  sfh_float_voidptr_node_t node, node2;
  sfh_float_voidptr_node_t *out_node;
  sfh_float_voidptr_heap_t *out_heap;
  int is_empty;
  sfh_float_voidptr_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_float_voidptr_init(NULL);
  rc = sfh_float_voidptr_empty(NULL, &is_empty);
  rc = sfh_float_voidptr_find_min(NULL, &out_node);
  rc = sfh_float_voidptr_insert(NULL, &node, 1, 0);
  rc = sfh_float_voidptr_insert(&heap, NULL, 1, 0);
  rc = sfh_float_voidptr_delete_min(NULL);
  rc = sfh_float_voidptr_delete(NULL, &node);
  rc = sfh_float_voidptr_delete(&heap, NULL);
  rc = sfh_float_voidptr_decrease_key(NULL, &node, 1);
  rc = sfh_float_voidptr_decrease_key(&heap, NULL, 1);
  rc = sfh_float_voidptr_meld(NULL, &heap, &out_heap);
  rc = sfh_float_voidptr_meld(&heap, NULL, &out_heap);
  rc = sfh_float_voidptr_meld(&heap, &heap, NULL);

  sfh_float_voidptr_init(&heap);
  rc = sfh_float_voidptr_empty(&heap, &is_empty);
  rc = sfh_float_voidptr_find_min(&heap, &out_node);
  rc = sfh_float_voidptr_delete_min(&heap);

  rc = sfh_float_voidptr_insert(&heap, &node, 10, 0);
  rc = sfh_float_voidptr_empty(&heap, &is_empty);
  rc = sfh_float_voidptr_find_min(&heap, &out_node);

  rc = sfh_float_voidptr_insert(&heap, &node2, 10, 0);
  rc = sfh_float_voidptr_delete(&heap, &node);
  rc = sfh_float_voidptr_delete_min(&heap);

  {
    sfh_float_voidptr_heap_t h1, h2, h3, *merged;
    sfh_float_voidptr_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_float_voidptr_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_float_voidptr_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_float_voidptr_init(&h3);
    sfh_float_voidptr_insert(&h1, &n1, 1, 0);
    sfh_float_voidptr_insert(&h1, &n2, 2, 0);
    sfh_float_voidptr_insert(&h1, &n3, 3, 0);
    sfh_float_voidptr_insert(&h1, &n4, 4, 0);
    sfh_float_voidptr_insert(&h2, &n5, 5, 0);

    sfh_float_voidptr_meld(&h1, &h2, &merged);
    sfh_float_voidptr_delete_min(merged);
    sfh_float_voidptr_meld(&h3, merged, &merged);
  }

  {
    static sfh_float_voidptr_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_float_voidptr_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_float_voidptr_insert(&heap, &fnodes[idx],
                                        (float)((seed >> 8) % 1000), 0);
          if (rc == sfh_float_voidptr_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_float_voidptr_decrease_key(&heap, &fnodes[idx], (float)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_float_voidptr_node_t *min;
          sfh_float_voidptr_find_min(&heap, &min);
          rc = sfh_float_voidptr_delete_min(&heap);
          if (rc == sfh_float_voidptr_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_float_voidptr_delete(&heap, &fnodes[idx]);
          if (rc == sfh_float_voidptr_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_double_int8_t(void) {
  sfh_double_int8_t_heap_t heap;
  sfh_double_int8_t_node_t node, node2;
  sfh_double_int8_t_node_t *out_node;
  sfh_double_int8_t_heap_t *out_heap;
  int is_empty;
  sfh_double_int8_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_double_int8_t_init(NULL);
  rc = sfh_double_int8_t_empty(NULL, &is_empty);
  rc = sfh_double_int8_t_find_min(NULL, &out_node);
  rc = sfh_double_int8_t_insert(NULL, &node, 1, 0);
  rc = sfh_double_int8_t_insert(&heap, NULL, 1, 0);
  rc = sfh_double_int8_t_delete_min(NULL);
  rc = sfh_double_int8_t_delete(NULL, &node);
  rc = sfh_double_int8_t_delete(&heap, NULL);
  rc = sfh_double_int8_t_decrease_key(NULL, &node, 1);
  rc = sfh_double_int8_t_decrease_key(&heap, NULL, 1);
  rc = sfh_double_int8_t_meld(NULL, &heap, &out_heap);
  rc = sfh_double_int8_t_meld(&heap, NULL, &out_heap);
  rc = sfh_double_int8_t_meld(&heap, &heap, NULL);

  sfh_double_int8_t_init(&heap);
  rc = sfh_double_int8_t_empty(&heap, &is_empty);
  rc = sfh_double_int8_t_find_min(&heap, &out_node);
  rc = sfh_double_int8_t_delete_min(&heap);

  rc = sfh_double_int8_t_insert(&heap, &node, 10, 0);
  rc = sfh_double_int8_t_empty(&heap, &is_empty);
  rc = sfh_double_int8_t_find_min(&heap, &out_node);

  rc = sfh_double_int8_t_insert(&heap, &node2, 10, 0);
  rc = sfh_double_int8_t_delete(&heap, &node);
  rc = sfh_double_int8_t_delete_min(&heap);

  {
    sfh_double_int8_t_heap_t h1, h2, h3, *merged;
    sfh_double_int8_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_double_int8_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_double_int8_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_double_int8_t_init(&h3);
    sfh_double_int8_t_insert(&h1, &n1, 1, 0);
    sfh_double_int8_t_insert(&h1, &n2, 2, 0);
    sfh_double_int8_t_insert(&h1, &n3, 3, 0);
    sfh_double_int8_t_insert(&h1, &n4, 4, 0);
    sfh_double_int8_t_insert(&h2, &n5, 5, 0);

    sfh_double_int8_t_meld(&h1, &h2, &merged);
    sfh_double_int8_t_delete_min(merged);
    sfh_double_int8_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_double_int8_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_double_int8_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_double_int8_t_insert(&heap, &fnodes[idx],
                                        (double)((seed >> 8) % 1000), 0);
          if (rc == sfh_double_int8_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_double_int8_t_decrease_key(&heap, &fnodes[idx], (double)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_double_int8_t_node_t *min;
          sfh_double_int8_t_find_min(&heap, &min);
          rc = sfh_double_int8_t_delete_min(&heap);
          if (rc == sfh_double_int8_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_double_int8_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_double_int8_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_double_int16_t(void) {
  sfh_double_int16_t_heap_t heap;
  sfh_double_int16_t_node_t node, node2;
  sfh_double_int16_t_node_t *out_node;
  sfh_double_int16_t_heap_t *out_heap;
  int is_empty;
  sfh_double_int16_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_double_int16_t_init(NULL);
  rc = sfh_double_int16_t_empty(NULL, &is_empty);
  rc = sfh_double_int16_t_find_min(NULL, &out_node);
  rc = sfh_double_int16_t_insert(NULL, &node, 1, 0);
  rc = sfh_double_int16_t_insert(&heap, NULL, 1, 0);
  rc = sfh_double_int16_t_delete_min(NULL);
  rc = sfh_double_int16_t_delete(NULL, &node);
  rc = sfh_double_int16_t_delete(&heap, NULL);
  rc = sfh_double_int16_t_decrease_key(NULL, &node, 1);
  rc = sfh_double_int16_t_decrease_key(&heap, NULL, 1);
  rc = sfh_double_int16_t_meld(NULL, &heap, &out_heap);
  rc = sfh_double_int16_t_meld(&heap, NULL, &out_heap);
  rc = sfh_double_int16_t_meld(&heap, &heap, NULL);

  sfh_double_int16_t_init(&heap);
  rc = sfh_double_int16_t_empty(&heap, &is_empty);
  rc = sfh_double_int16_t_find_min(&heap, &out_node);
  rc = sfh_double_int16_t_delete_min(&heap);

  rc = sfh_double_int16_t_insert(&heap, &node, 10, 0);
  rc = sfh_double_int16_t_empty(&heap, &is_empty);
  rc = sfh_double_int16_t_find_min(&heap, &out_node);

  rc = sfh_double_int16_t_insert(&heap, &node2, 10, 0);
  rc = sfh_double_int16_t_delete(&heap, &node);
  rc = sfh_double_int16_t_delete_min(&heap);

  {
    sfh_double_int16_t_heap_t h1, h2, h3, *merged;
    sfh_double_int16_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_double_int16_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_double_int16_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_double_int16_t_init(&h3);
    sfh_double_int16_t_insert(&h1, &n1, 1, 0);
    sfh_double_int16_t_insert(&h1, &n2, 2, 0);
    sfh_double_int16_t_insert(&h1, &n3, 3, 0);
    sfh_double_int16_t_insert(&h1, &n4, 4, 0);
    sfh_double_int16_t_insert(&h2, &n5, 5, 0);

    sfh_double_int16_t_meld(&h1, &h2, &merged);
    sfh_double_int16_t_delete_min(merged);
    sfh_double_int16_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_double_int16_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_double_int16_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_double_int16_t_insert(&heap, &fnodes[idx],
                                         (double)((seed >> 8) % 1000), 0);
          if (rc == sfh_double_int16_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_double_int16_t_decrease_key(&heap, &fnodes[idx], (double)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_double_int16_t_node_t *min;
          sfh_double_int16_t_find_min(&heap, &min);
          rc = sfh_double_int16_t_delete_min(&heap);
          if (rc == sfh_double_int16_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_double_int16_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_double_int16_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_double_int32_t(void) {
  sfh_double_int32_t_heap_t heap;
  sfh_double_int32_t_node_t node, node2;
  sfh_double_int32_t_node_t *out_node;
  sfh_double_int32_t_heap_t *out_heap;
  int is_empty;
  sfh_double_int32_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_double_int32_t_init(NULL);
  rc = sfh_double_int32_t_empty(NULL, &is_empty);
  rc = sfh_double_int32_t_find_min(NULL, &out_node);
  rc = sfh_double_int32_t_insert(NULL, &node, 1, 0);
  rc = sfh_double_int32_t_insert(&heap, NULL, 1, 0);
  rc = sfh_double_int32_t_delete_min(NULL);
  rc = sfh_double_int32_t_delete(NULL, &node);
  rc = sfh_double_int32_t_delete(&heap, NULL);
  rc = sfh_double_int32_t_decrease_key(NULL, &node, 1);
  rc = sfh_double_int32_t_decrease_key(&heap, NULL, 1);
  rc = sfh_double_int32_t_meld(NULL, &heap, &out_heap);
  rc = sfh_double_int32_t_meld(&heap, NULL, &out_heap);
  rc = sfh_double_int32_t_meld(&heap, &heap, NULL);

  sfh_double_int32_t_init(&heap);
  rc = sfh_double_int32_t_empty(&heap, &is_empty);
  rc = sfh_double_int32_t_find_min(&heap, &out_node);
  rc = sfh_double_int32_t_delete_min(&heap);

  rc = sfh_double_int32_t_insert(&heap, &node, 10, 0);
  rc = sfh_double_int32_t_empty(&heap, &is_empty);
  rc = sfh_double_int32_t_find_min(&heap, &out_node);

  rc = sfh_double_int32_t_insert(&heap, &node2, 10, 0);
  rc = sfh_double_int32_t_delete(&heap, &node);
  rc = sfh_double_int32_t_delete_min(&heap);

  {
    sfh_double_int32_t_heap_t h1, h2, h3, *merged;
    sfh_double_int32_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_double_int32_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_double_int32_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_double_int32_t_init(&h3);
    sfh_double_int32_t_insert(&h1, &n1, 1, 0);
    sfh_double_int32_t_insert(&h1, &n2, 2, 0);
    sfh_double_int32_t_insert(&h1, &n3, 3, 0);
    sfh_double_int32_t_insert(&h1, &n4, 4, 0);
    sfh_double_int32_t_insert(&h2, &n5, 5, 0);

    sfh_double_int32_t_meld(&h1, &h2, &merged);
    sfh_double_int32_t_delete_min(merged);
    sfh_double_int32_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_double_int32_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_double_int32_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_double_int32_t_insert(&heap, &fnodes[idx],
                                         (double)((seed >> 8) % 1000), 0);
          if (rc == sfh_double_int32_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_double_int32_t_decrease_key(&heap, &fnodes[idx], (double)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_double_int32_t_node_t *min;
          sfh_double_int32_t_find_min(&heap, &min);
          rc = sfh_double_int32_t_delete_min(&heap);
          if (rc == sfh_double_int32_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_double_int32_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_double_int32_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_double_int64_t(void) {
  sfh_double_int64_t_heap_t heap;
  sfh_double_int64_t_node_t node, node2;
  sfh_double_int64_t_node_t *out_node;
  sfh_double_int64_t_heap_t *out_heap;
  int is_empty;
  sfh_double_int64_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_double_int64_t_init(NULL);
  rc = sfh_double_int64_t_empty(NULL, &is_empty);
  rc = sfh_double_int64_t_find_min(NULL, &out_node);
  rc = sfh_double_int64_t_insert(NULL, &node, 1, 0);
  rc = sfh_double_int64_t_insert(&heap, NULL, 1, 0);
  rc = sfh_double_int64_t_delete_min(NULL);
  rc = sfh_double_int64_t_delete(NULL, &node);
  rc = sfh_double_int64_t_delete(&heap, NULL);
  rc = sfh_double_int64_t_decrease_key(NULL, &node, 1);
  rc = sfh_double_int64_t_decrease_key(&heap, NULL, 1);
  rc = sfh_double_int64_t_meld(NULL, &heap, &out_heap);
  rc = sfh_double_int64_t_meld(&heap, NULL, &out_heap);
  rc = sfh_double_int64_t_meld(&heap, &heap, NULL);

  sfh_double_int64_t_init(&heap);
  rc = sfh_double_int64_t_empty(&heap, &is_empty);
  rc = sfh_double_int64_t_find_min(&heap, &out_node);
  rc = sfh_double_int64_t_delete_min(&heap);

  rc = sfh_double_int64_t_insert(&heap, &node, 10, 0);
  rc = sfh_double_int64_t_empty(&heap, &is_empty);
  rc = sfh_double_int64_t_find_min(&heap, &out_node);

  rc = sfh_double_int64_t_insert(&heap, &node2, 10, 0);
  rc = sfh_double_int64_t_delete(&heap, &node);
  rc = sfh_double_int64_t_delete_min(&heap);

  {
    sfh_double_int64_t_heap_t h1, h2, h3, *merged;
    sfh_double_int64_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_double_int64_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_double_int64_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_double_int64_t_init(&h3);
    sfh_double_int64_t_insert(&h1, &n1, 1, 0);
    sfh_double_int64_t_insert(&h1, &n2, 2, 0);
    sfh_double_int64_t_insert(&h1, &n3, 3, 0);
    sfh_double_int64_t_insert(&h1, &n4, 4, 0);
    sfh_double_int64_t_insert(&h2, &n5, 5, 0);

    sfh_double_int64_t_meld(&h1, &h2, &merged);
    sfh_double_int64_t_delete_min(merged);
    sfh_double_int64_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_double_int64_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_double_int64_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_double_int64_t_insert(&heap, &fnodes[idx],
                                         (double)((seed >> 8) % 1000), 0);
          if (rc == sfh_double_int64_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_double_int64_t_decrease_key(&heap, &fnodes[idx], (double)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_double_int64_t_node_t *min;
          sfh_double_int64_t_find_min(&heap, &min);
          rc = sfh_double_int64_t_delete_min(&heap);
          if (rc == sfh_double_int64_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_double_int64_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_double_int64_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_double_uint8_t(void) {
  sfh_double_uint8_t_heap_t heap;
  sfh_double_uint8_t_node_t node, node2;
  sfh_double_uint8_t_node_t *out_node;
  sfh_double_uint8_t_heap_t *out_heap;
  int is_empty;
  sfh_double_uint8_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_double_uint8_t_init(NULL);
  rc = sfh_double_uint8_t_empty(NULL, &is_empty);
  rc = sfh_double_uint8_t_find_min(NULL, &out_node);
  rc = sfh_double_uint8_t_insert(NULL, &node, 1, 0);
  rc = sfh_double_uint8_t_insert(&heap, NULL, 1, 0);
  rc = sfh_double_uint8_t_delete_min(NULL);
  rc = sfh_double_uint8_t_delete(NULL, &node);
  rc = sfh_double_uint8_t_delete(&heap, NULL);
  rc = sfh_double_uint8_t_decrease_key(NULL, &node, 1);
  rc = sfh_double_uint8_t_decrease_key(&heap, NULL, 1);
  rc = sfh_double_uint8_t_meld(NULL, &heap, &out_heap);
  rc = sfh_double_uint8_t_meld(&heap, NULL, &out_heap);
  rc = sfh_double_uint8_t_meld(&heap, &heap, NULL);

  sfh_double_uint8_t_init(&heap);
  rc = sfh_double_uint8_t_empty(&heap, &is_empty);
  rc = sfh_double_uint8_t_find_min(&heap, &out_node);
  rc = sfh_double_uint8_t_delete_min(&heap);

  rc = sfh_double_uint8_t_insert(&heap, &node, 10, 0);
  rc = sfh_double_uint8_t_empty(&heap, &is_empty);
  rc = sfh_double_uint8_t_find_min(&heap, &out_node);

  rc = sfh_double_uint8_t_insert(&heap, &node2, 10, 0);
  rc = sfh_double_uint8_t_delete(&heap, &node);
  rc = sfh_double_uint8_t_delete_min(&heap);

  {
    sfh_double_uint8_t_heap_t h1, h2, h3, *merged;
    sfh_double_uint8_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_double_uint8_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_double_uint8_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_double_uint8_t_init(&h3);
    sfh_double_uint8_t_insert(&h1, &n1, 1, 0);
    sfh_double_uint8_t_insert(&h1, &n2, 2, 0);
    sfh_double_uint8_t_insert(&h1, &n3, 3, 0);
    sfh_double_uint8_t_insert(&h1, &n4, 4, 0);
    sfh_double_uint8_t_insert(&h2, &n5, 5, 0);

    sfh_double_uint8_t_meld(&h1, &h2, &merged);
    sfh_double_uint8_t_delete_min(merged);
    sfh_double_uint8_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_double_uint8_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_double_uint8_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_double_uint8_t_insert(&heap, &fnodes[idx],
                                         (double)((seed >> 8) % 1000), 0);
          if (rc == sfh_double_uint8_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_double_uint8_t_decrease_key(&heap, &fnodes[idx], (double)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_double_uint8_t_node_t *min;
          sfh_double_uint8_t_find_min(&heap, &min);
          rc = sfh_double_uint8_t_delete_min(&heap);
          if (rc == sfh_double_uint8_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_double_uint8_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_double_uint8_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_double_uint16_t(void) {
  sfh_double_uint16_t_heap_t heap;
  sfh_double_uint16_t_node_t node, node2;
  sfh_double_uint16_t_node_t *out_node;
  sfh_double_uint16_t_heap_t *out_heap;
  int is_empty;
  sfh_double_uint16_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_double_uint16_t_init(NULL);
  rc = sfh_double_uint16_t_empty(NULL, &is_empty);
  rc = sfh_double_uint16_t_find_min(NULL, &out_node);
  rc = sfh_double_uint16_t_insert(NULL, &node, 1, 0);
  rc = sfh_double_uint16_t_insert(&heap, NULL, 1, 0);
  rc = sfh_double_uint16_t_delete_min(NULL);
  rc = sfh_double_uint16_t_delete(NULL, &node);
  rc = sfh_double_uint16_t_delete(&heap, NULL);
  rc = sfh_double_uint16_t_decrease_key(NULL, &node, 1);
  rc = sfh_double_uint16_t_decrease_key(&heap, NULL, 1);
  rc = sfh_double_uint16_t_meld(NULL, &heap, &out_heap);
  rc = sfh_double_uint16_t_meld(&heap, NULL, &out_heap);
  rc = sfh_double_uint16_t_meld(&heap, &heap, NULL);

  sfh_double_uint16_t_init(&heap);
  rc = sfh_double_uint16_t_empty(&heap, &is_empty);
  rc = sfh_double_uint16_t_find_min(&heap, &out_node);
  rc = sfh_double_uint16_t_delete_min(&heap);

  rc = sfh_double_uint16_t_insert(&heap, &node, 10, 0);
  rc = sfh_double_uint16_t_empty(&heap, &is_empty);
  rc = sfh_double_uint16_t_find_min(&heap, &out_node);

  rc = sfh_double_uint16_t_insert(&heap, &node2, 10, 0);
  rc = sfh_double_uint16_t_delete(&heap, &node);
  rc = sfh_double_uint16_t_delete_min(&heap);

  {
    sfh_double_uint16_t_heap_t h1, h2, h3, *merged;
    sfh_double_uint16_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_double_uint16_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_double_uint16_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_double_uint16_t_init(&h3);
    sfh_double_uint16_t_insert(&h1, &n1, 1, 0);
    sfh_double_uint16_t_insert(&h1, &n2, 2, 0);
    sfh_double_uint16_t_insert(&h1, &n3, 3, 0);
    sfh_double_uint16_t_insert(&h1, &n4, 4, 0);
    sfh_double_uint16_t_insert(&h2, &n5, 5, 0);

    sfh_double_uint16_t_meld(&h1, &h2, &merged);
    sfh_double_uint16_t_delete_min(merged);
    sfh_double_uint16_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_double_uint16_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_double_uint16_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_double_uint16_t_insert(&heap, &fnodes[idx],
                                          (double)((seed >> 8) % 1000), 0);
          if (rc == sfh_double_uint16_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_double_uint16_t_decrease_key(&heap, &fnodes[idx], (double)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_double_uint16_t_node_t *min;
          sfh_double_uint16_t_find_min(&heap, &min);
          rc = sfh_double_uint16_t_delete_min(&heap);
          if (rc == sfh_double_uint16_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_double_uint16_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_double_uint16_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_double_uint32_t(void) {
  sfh_double_uint32_t_heap_t heap;
  sfh_double_uint32_t_node_t node, node2;
  sfh_double_uint32_t_node_t *out_node;
  sfh_double_uint32_t_heap_t *out_heap;
  int is_empty;
  sfh_double_uint32_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_double_uint32_t_init(NULL);
  rc = sfh_double_uint32_t_empty(NULL, &is_empty);
  rc = sfh_double_uint32_t_find_min(NULL, &out_node);
  rc = sfh_double_uint32_t_insert(NULL, &node, 1, 0);
  rc = sfh_double_uint32_t_insert(&heap, NULL, 1, 0);
  rc = sfh_double_uint32_t_delete_min(NULL);
  rc = sfh_double_uint32_t_delete(NULL, &node);
  rc = sfh_double_uint32_t_delete(&heap, NULL);
  rc = sfh_double_uint32_t_decrease_key(NULL, &node, 1);
  rc = sfh_double_uint32_t_decrease_key(&heap, NULL, 1);
  rc = sfh_double_uint32_t_meld(NULL, &heap, &out_heap);
  rc = sfh_double_uint32_t_meld(&heap, NULL, &out_heap);
  rc = sfh_double_uint32_t_meld(&heap, &heap, NULL);

  sfh_double_uint32_t_init(&heap);
  rc = sfh_double_uint32_t_empty(&heap, &is_empty);
  rc = sfh_double_uint32_t_find_min(&heap, &out_node);
  rc = sfh_double_uint32_t_delete_min(&heap);

  rc = sfh_double_uint32_t_insert(&heap, &node, 10, 0);
  rc = sfh_double_uint32_t_empty(&heap, &is_empty);
  rc = sfh_double_uint32_t_find_min(&heap, &out_node);

  rc = sfh_double_uint32_t_insert(&heap, &node2, 10, 0);
  rc = sfh_double_uint32_t_delete(&heap, &node);
  rc = sfh_double_uint32_t_delete_min(&heap);

  {
    sfh_double_uint32_t_heap_t h1, h2, h3, *merged;
    sfh_double_uint32_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_double_uint32_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_double_uint32_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_double_uint32_t_init(&h3);
    sfh_double_uint32_t_insert(&h1, &n1, 1, 0);
    sfh_double_uint32_t_insert(&h1, &n2, 2, 0);
    sfh_double_uint32_t_insert(&h1, &n3, 3, 0);
    sfh_double_uint32_t_insert(&h1, &n4, 4, 0);
    sfh_double_uint32_t_insert(&h2, &n5, 5, 0);

    sfh_double_uint32_t_meld(&h1, &h2, &merged);
    sfh_double_uint32_t_delete_min(merged);
    sfh_double_uint32_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_double_uint32_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_double_uint32_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_double_uint32_t_insert(&heap, &fnodes[idx],
                                          (double)((seed >> 8) % 1000), 0);
          if (rc == sfh_double_uint32_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_double_uint32_t_decrease_key(&heap, &fnodes[idx], (double)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_double_uint32_t_node_t *min;
          sfh_double_uint32_t_find_min(&heap, &min);
          rc = sfh_double_uint32_t_delete_min(&heap);
          if (rc == sfh_double_uint32_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_double_uint32_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_double_uint32_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_double_uint64_t(void) {
  sfh_double_uint64_t_heap_t heap;
  sfh_double_uint64_t_node_t node, node2;
  sfh_double_uint64_t_node_t *out_node;
  sfh_double_uint64_t_heap_t *out_heap;
  int is_empty;
  sfh_double_uint64_t_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_double_uint64_t_init(NULL);
  rc = sfh_double_uint64_t_empty(NULL, &is_empty);
  rc = sfh_double_uint64_t_find_min(NULL, &out_node);
  rc = sfh_double_uint64_t_insert(NULL, &node, 1, 0);
  rc = sfh_double_uint64_t_insert(&heap, NULL, 1, 0);
  rc = sfh_double_uint64_t_delete_min(NULL);
  rc = sfh_double_uint64_t_delete(NULL, &node);
  rc = sfh_double_uint64_t_delete(&heap, NULL);
  rc = sfh_double_uint64_t_decrease_key(NULL, &node, 1);
  rc = sfh_double_uint64_t_decrease_key(&heap, NULL, 1);
  rc = sfh_double_uint64_t_meld(NULL, &heap, &out_heap);
  rc = sfh_double_uint64_t_meld(&heap, NULL, &out_heap);
  rc = sfh_double_uint64_t_meld(&heap, &heap, NULL);

  sfh_double_uint64_t_init(&heap);
  rc = sfh_double_uint64_t_empty(&heap, &is_empty);
  rc = sfh_double_uint64_t_find_min(&heap, &out_node);
  rc = sfh_double_uint64_t_delete_min(&heap);

  rc = sfh_double_uint64_t_insert(&heap, &node, 10, 0);
  rc = sfh_double_uint64_t_empty(&heap, &is_empty);
  rc = sfh_double_uint64_t_find_min(&heap, &out_node);

  rc = sfh_double_uint64_t_insert(&heap, &node2, 10, 0);
  rc = sfh_double_uint64_t_delete(&heap, &node);
  rc = sfh_double_uint64_t_delete_min(&heap);

  {
    sfh_double_uint64_t_heap_t h1, h2, h3, *merged;
    sfh_double_uint64_t_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_double_uint64_t_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_double_uint64_t_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_double_uint64_t_init(&h3);
    sfh_double_uint64_t_insert(&h1, &n1, 1, 0);
    sfh_double_uint64_t_insert(&h1, &n2, 2, 0);
    sfh_double_uint64_t_insert(&h1, &n3, 3, 0);
    sfh_double_uint64_t_insert(&h1, &n4, 4, 0);
    sfh_double_uint64_t_insert(&h2, &n5, 5, 0);

    sfh_double_uint64_t_meld(&h1, &h2, &merged);
    sfh_double_uint64_t_delete_min(merged);
    sfh_double_uint64_t_meld(&h3, merged, &merged);
  }

  {
    static sfh_double_uint64_t_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_double_uint64_t_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_double_uint64_t_insert(&heap, &fnodes[idx],
                                          (double)((seed >> 8) % 1000), 0);
          if (rc == sfh_double_uint64_t_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_double_uint64_t_decrease_key(&heap, &fnodes[idx], (double)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_double_uint64_t_node_t *min;
          sfh_double_uint64_t_find_min(&heap, &min);
          rc = sfh_double_uint64_t_delete_min(&heap);
          if (rc == sfh_double_uint64_t_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_double_uint64_t_delete(&heap, &fnodes[idx]);
          if (rc == sfh_double_uint64_t_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_double_float(void) {
  sfh_double_float_heap_t heap;
  sfh_double_float_node_t node, node2;
  sfh_double_float_node_t *out_node;
  sfh_double_float_heap_t *out_heap;
  int is_empty;
  sfh_double_float_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_double_float_init(NULL);
  rc = sfh_double_float_empty(NULL, &is_empty);
  rc = sfh_double_float_find_min(NULL, &out_node);
  rc = sfh_double_float_insert(NULL, &node, 1, 0);
  rc = sfh_double_float_insert(&heap, NULL, 1, 0);
  rc = sfh_double_float_delete_min(NULL);
  rc = sfh_double_float_delete(NULL, &node);
  rc = sfh_double_float_delete(&heap, NULL);
  rc = sfh_double_float_decrease_key(NULL, &node, 1);
  rc = sfh_double_float_decrease_key(&heap, NULL, 1);
  rc = sfh_double_float_meld(NULL, &heap, &out_heap);
  rc = sfh_double_float_meld(&heap, NULL, &out_heap);
  rc = sfh_double_float_meld(&heap, &heap, NULL);

  sfh_double_float_init(&heap);
  rc = sfh_double_float_empty(&heap, &is_empty);
  rc = sfh_double_float_find_min(&heap, &out_node);
  rc = sfh_double_float_delete_min(&heap);

  rc = sfh_double_float_insert(&heap, &node, 10, 0);
  rc = sfh_double_float_empty(&heap, &is_empty);
  rc = sfh_double_float_find_min(&heap, &out_node);

  rc = sfh_double_float_insert(&heap, &node2, 10, 0);
  rc = sfh_double_float_delete(&heap, &node);
  rc = sfh_double_float_delete_min(&heap);

  {
    sfh_double_float_heap_t h1, h2, h3, *merged;
    sfh_double_float_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_double_float_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_double_float_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_double_float_init(&h3);
    sfh_double_float_insert(&h1, &n1, 1, 0);
    sfh_double_float_insert(&h1, &n2, 2, 0);
    sfh_double_float_insert(&h1, &n3, 3, 0);
    sfh_double_float_insert(&h1, &n4, 4, 0);
    sfh_double_float_insert(&h2, &n5, 5, 0);

    sfh_double_float_meld(&h1, &h2, &merged);
    sfh_double_float_delete_min(merged);
    sfh_double_float_meld(&h3, merged, &merged);
  }

  {
    static sfh_double_float_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_double_float_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_double_float_insert(&heap, &fnodes[idx],
                                       (double)((seed >> 8) % 1000), 0);
          if (rc == sfh_double_float_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_double_float_decrease_key(&heap, &fnodes[idx], (double)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_double_float_node_t *min;
          sfh_double_float_find_min(&heap, &min);
          rc = sfh_double_float_delete_min(&heap);
          if (rc == sfh_double_float_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_double_float_delete(&heap, &fnodes[idx]);
          if (rc == sfh_double_float_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_double_double(void) {
  sfh_double_double_heap_t heap;
  sfh_double_double_node_t node, node2;
  sfh_double_double_node_t *out_node;
  sfh_double_double_heap_t *out_heap;
  int is_empty;
  sfh_double_double_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_double_double_init(NULL);
  rc = sfh_double_double_empty(NULL, &is_empty);
  rc = sfh_double_double_find_min(NULL, &out_node);
  rc = sfh_double_double_insert(NULL, &node, 1, 0);
  rc = sfh_double_double_insert(&heap, NULL, 1, 0);
  rc = sfh_double_double_delete_min(NULL);
  rc = sfh_double_double_delete(NULL, &node);
  rc = sfh_double_double_delete(&heap, NULL);
  rc = sfh_double_double_decrease_key(NULL, &node, 1);
  rc = sfh_double_double_decrease_key(&heap, NULL, 1);
  rc = sfh_double_double_meld(NULL, &heap, &out_heap);
  rc = sfh_double_double_meld(&heap, NULL, &out_heap);
  rc = sfh_double_double_meld(&heap, &heap, NULL);

  sfh_double_double_init(&heap);
  rc = sfh_double_double_empty(&heap, &is_empty);
  rc = sfh_double_double_find_min(&heap, &out_node);
  rc = sfh_double_double_delete_min(&heap);

  rc = sfh_double_double_insert(&heap, &node, 10, 0);
  rc = sfh_double_double_empty(&heap, &is_empty);
  rc = sfh_double_double_find_min(&heap, &out_node);

  rc = sfh_double_double_insert(&heap, &node2, 10, 0);
  rc = sfh_double_double_delete(&heap, &node);
  rc = sfh_double_double_delete_min(&heap);

  {
    sfh_double_double_heap_t h1, h2, h3, *merged;
    sfh_double_double_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_double_double_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_double_double_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_double_double_init(&h3);
    sfh_double_double_insert(&h1, &n1, 1, 0);
    sfh_double_double_insert(&h1, &n2, 2, 0);
    sfh_double_double_insert(&h1, &n3, 3, 0);
    sfh_double_double_insert(&h1, &n4, 4, 0);
    sfh_double_double_insert(&h2, &n5, 5, 0);

    sfh_double_double_meld(&h1, &h2, &merged);
    sfh_double_double_delete_min(merged);
    sfh_double_double_meld(&h3, merged, &merged);
  }

  {
    static sfh_double_double_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_double_double_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_double_double_insert(&heap, &fnodes[idx],
                                        (double)((seed >> 8) % 1000), 0);
          if (rc == sfh_double_double_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_double_double_decrease_key(&heap, &fnodes[idx], (double)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_double_double_node_t *min;
          sfh_double_double_find_min(&heap, &min);
          rc = sfh_double_double_delete_min(&heap);
          if (rc == sfh_double_double_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_double_double_delete(&heap, &fnodes[idx]);
          if (rc == sfh_double_double_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_double_charptr(void) {
  sfh_double_charptr_heap_t heap;
  sfh_double_charptr_node_t node, node2;
  sfh_double_charptr_node_t *out_node;
  sfh_double_charptr_heap_t *out_heap;
  int is_empty;
  sfh_double_charptr_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_double_charptr_init(NULL);
  rc = sfh_double_charptr_empty(NULL, &is_empty);
  rc = sfh_double_charptr_find_min(NULL, &out_node);
  rc = sfh_double_charptr_insert(NULL, &node, 1, 0);
  rc = sfh_double_charptr_insert(&heap, NULL, 1, 0);
  rc = sfh_double_charptr_delete_min(NULL);
  rc = sfh_double_charptr_delete(NULL, &node);
  rc = sfh_double_charptr_delete(&heap, NULL);
  rc = sfh_double_charptr_decrease_key(NULL, &node, 1);
  rc = sfh_double_charptr_decrease_key(&heap, NULL, 1);
  rc = sfh_double_charptr_meld(NULL, &heap, &out_heap);
  rc = sfh_double_charptr_meld(&heap, NULL, &out_heap);
  rc = sfh_double_charptr_meld(&heap, &heap, NULL);

  sfh_double_charptr_init(&heap);
  rc = sfh_double_charptr_empty(&heap, &is_empty);
  rc = sfh_double_charptr_find_min(&heap, &out_node);
  rc = sfh_double_charptr_delete_min(&heap);

  rc = sfh_double_charptr_insert(&heap, &node, 10, 0);
  rc = sfh_double_charptr_empty(&heap, &is_empty);
  rc = sfh_double_charptr_find_min(&heap, &out_node);

  rc = sfh_double_charptr_insert(&heap, &node2, 10, 0);
  rc = sfh_double_charptr_delete(&heap, &node);
  rc = sfh_double_charptr_delete_min(&heap);

  {
    sfh_double_charptr_heap_t h1, h2, h3, *merged;
    sfh_double_charptr_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_double_charptr_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_double_charptr_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_double_charptr_init(&h3);
    sfh_double_charptr_insert(&h1, &n1, 1, 0);
    sfh_double_charptr_insert(&h1, &n2, 2, 0);
    sfh_double_charptr_insert(&h1, &n3, 3, 0);
    sfh_double_charptr_insert(&h1, &n4, 4, 0);
    sfh_double_charptr_insert(&h2, &n5, 5, 0);

    sfh_double_charptr_meld(&h1, &h2, &merged);
    sfh_double_charptr_delete_min(merged);
    sfh_double_charptr_meld(&h3, merged, &merged);
  }

  {
    static sfh_double_charptr_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_double_charptr_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_double_charptr_insert(&heap, &fnodes[idx],
                                         (double)((seed >> 8) % 1000), 0);
          if (rc == sfh_double_charptr_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_double_charptr_decrease_key(&heap, &fnodes[idx], (double)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_double_charptr_node_t *min;
          sfh_double_charptr_find_min(&heap, &min);
          rc = sfh_double_charptr_delete_min(&heap);
          if (rc == sfh_double_charptr_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_double_charptr_delete(&heap, &fnodes[idx]);
          if (rc == sfh_double_charptr_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

TEST test_all_sfh_double_voidptr(void) {
  sfh_double_voidptr_heap_t heap;
  sfh_double_voidptr_node_t node, node2;
  sfh_double_voidptr_node_t *out_node;
  sfh_double_voidptr_heap_t *out_heap;
  int is_empty;
  sfh_double_voidptr_error_t rc;
  int i, j;

  memset(&heap, 0, sizeof(heap));

  rc = sfh_double_voidptr_init(NULL);
  rc = sfh_double_voidptr_empty(NULL, &is_empty);
  rc = sfh_double_voidptr_find_min(NULL, &out_node);
  rc = sfh_double_voidptr_insert(NULL, &node, 1, 0);
  rc = sfh_double_voidptr_insert(&heap, NULL, 1, 0);
  rc = sfh_double_voidptr_delete_min(NULL);
  rc = sfh_double_voidptr_delete(NULL, &node);
  rc = sfh_double_voidptr_delete(&heap, NULL);
  rc = sfh_double_voidptr_decrease_key(NULL, &node, 1);
  rc = sfh_double_voidptr_decrease_key(&heap, NULL, 1);
  rc = sfh_double_voidptr_meld(NULL, &heap, &out_heap);
  rc = sfh_double_voidptr_meld(&heap, NULL, &out_heap);
  rc = sfh_double_voidptr_meld(&heap, &heap, NULL);

  sfh_double_voidptr_init(&heap);
  rc = sfh_double_voidptr_empty(&heap, &is_empty);
  rc = sfh_double_voidptr_find_min(&heap, &out_node);
  rc = sfh_double_voidptr_delete_min(&heap);

  rc = sfh_double_voidptr_insert(&heap, &node, 10, 0);
  rc = sfh_double_voidptr_empty(&heap, &is_empty);
  rc = sfh_double_voidptr_find_min(&heap, &out_node);

  rc = sfh_double_voidptr_insert(&heap, &node2, 10, 0);
  rc = sfh_double_voidptr_delete(&heap, &node);
  rc = sfh_double_voidptr_delete_min(&heap);

  {
    sfh_double_voidptr_heap_t h1, h2, h3, *merged;
    sfh_double_voidptr_node_t n1, n2, n3, n4, n5;
    memset(&h1, 0, sizeof(h1));
    sfh_double_voidptr_init(&h1);
    memset(&h2, 0, sizeof(h2));
    sfh_double_voidptr_init(&h2);
    memset(&h3, 0, sizeof(h3));
    sfh_double_voidptr_init(&h3);
    sfh_double_voidptr_insert(&h1, &n1, 1, 0);
    sfh_double_voidptr_insert(&h1, &n2, 2, 0);
    sfh_double_voidptr_insert(&h1, &n3, 3, 0);
    sfh_double_voidptr_insert(&h1, &n4, 4, 0);
    sfh_double_voidptr_insert(&h2, &n5, 5, 0);

    sfh_double_voidptr_meld(&h1, &h2, &merged);
    sfh_double_voidptr_delete_min(merged);
    sfh_double_voidptr_meld(&h3, merged, &merged);
  }

  {
    static sfh_double_voidptr_node_t fnodes[2000];
    int in_heap[2000] = {0};
    int seed = 1337;
    memset(&heap, 0, sizeof(heap));
    sfh_double_voidptr_init(&heap);
    for (i = 0; i < 2000; ++i) {
      int op = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 100;
      int idx = (seed = (seed * 1103515245 + 12345) & 0x7fffffff) % 2000;
      if (op < 50) {
        if (!in_heap[idx]) {
          rc = sfh_double_voidptr_insert(&heap, &fnodes[idx],
                                         (double)((seed >> 8) % 1000), 0);
          if (rc == sfh_double_voidptr_SUCCESS)
            in_heap[idx] = 1;
        }
      } else if (op < 80) {
        if (in_heap[idx]) {
          rc = sfh_double_voidptr_decrease_key(&heap, &fnodes[idx], (double)0);
        }
      } else if (op < 95) {
        if (heap.size > 0) {
          sfh_double_voidptr_node_t *min;
          sfh_double_voidptr_find_min(&heap, &min);
          rc = sfh_double_voidptr_delete_min(&heap);
          if (rc == sfh_double_voidptr_SUCCESS) {
            for (j = 0; j < 2000; ++j) {
              if (in_heap[j] && &fnodes[j] == min) {
                in_heap[j] = 0;
                break;
              }
            }
          }
        }
      } else {
        if (in_heap[idx]) {
          rc = sfh_double_voidptr_delete(&heap, &fnodes[idx]);
          if (rc == sfh_double_voidptr_SUCCESS)
            in_heap[idx] = 0;
        }
      }
    }
  }

  PASS();
}

SUITE(strict_fibonacci_heaps_suite) {
  RUN_TEST(test_all_sfh_int8_t_int8_t);
  RUN_TEST(test_all_sfh_int8_t_int16_t);
  RUN_TEST(test_all_sfh_int8_t_int32_t);
  RUN_TEST(test_all_sfh_int8_t_int64_t);
  RUN_TEST(test_all_sfh_int8_t_uint8_t);
  RUN_TEST(test_all_sfh_int8_t_uint16_t);
  RUN_TEST(test_all_sfh_int8_t_uint32_t);
  RUN_TEST(test_all_sfh_int8_t_uint64_t);
  RUN_TEST(test_all_sfh_int8_t_float);
  RUN_TEST(test_all_sfh_int8_t_double);
  RUN_TEST(test_all_sfh_int8_t_charptr);
  RUN_TEST(test_all_sfh_int8_t_voidptr);
  RUN_TEST(test_all_sfh_int16_t_int8_t);
  RUN_TEST(test_all_sfh_int16_t_int16_t);
  RUN_TEST(test_all_sfh_int16_t_int32_t);
  RUN_TEST(test_all_sfh_int16_t_int64_t);
  RUN_TEST(test_all_sfh_int16_t_uint8_t);
  RUN_TEST(test_all_sfh_int16_t_uint16_t);
  RUN_TEST(test_all_sfh_int16_t_uint32_t);
  RUN_TEST(test_all_sfh_int16_t_uint64_t);
  RUN_TEST(test_all_sfh_int16_t_float);
  RUN_TEST(test_all_sfh_int16_t_double);
  RUN_TEST(test_all_sfh_int16_t_charptr);
  RUN_TEST(test_all_sfh_int16_t_voidptr);
  RUN_TEST(test_all_sfh_int32_t_int8_t);
  RUN_TEST(test_all_sfh_int32_t_int16_t);
  RUN_TEST(test_all_sfh_int32_t_int32_t);
  RUN_TEST(test_all_sfh_int32_t_int64_t);
  RUN_TEST(test_all_sfh_int32_t_uint8_t);
  RUN_TEST(test_all_sfh_int32_t_uint16_t);
  RUN_TEST(test_all_sfh_int32_t_uint32_t);
  RUN_TEST(test_all_sfh_int32_t_uint64_t);
  RUN_TEST(test_all_sfh_int32_t_float);
  RUN_TEST(test_all_sfh_int32_t_double);
  RUN_TEST(test_all_sfh_int32_t_charptr);
  RUN_TEST(test_all_sfh_int32_t_voidptr);
  RUN_TEST(test_all_sfh_int64_t_int8_t);
  RUN_TEST(test_all_sfh_int64_t_int16_t);
  RUN_TEST(test_all_sfh_int64_t_int32_t);
  RUN_TEST(test_all_sfh_int64_t_int64_t);
  RUN_TEST(test_all_sfh_int64_t_uint8_t);
  RUN_TEST(test_all_sfh_int64_t_uint16_t);
  RUN_TEST(test_all_sfh_int64_t_uint32_t);
  RUN_TEST(test_all_sfh_int64_t_uint64_t);
  RUN_TEST(test_all_sfh_int64_t_float);
  RUN_TEST(test_all_sfh_int64_t_double);
  RUN_TEST(test_all_sfh_int64_t_charptr);
  RUN_TEST(test_all_sfh_int64_t_voidptr);
  RUN_TEST(test_all_sfh_uint8_t_int8_t);
  RUN_TEST(test_all_sfh_uint8_t_int16_t);
  RUN_TEST(test_all_sfh_uint8_t_int32_t);
  RUN_TEST(test_all_sfh_uint8_t_int64_t);
  RUN_TEST(test_all_sfh_uint8_t_uint8_t);
  RUN_TEST(test_all_sfh_uint8_t_uint16_t);
  RUN_TEST(test_all_sfh_uint8_t_uint32_t);
  RUN_TEST(test_all_sfh_uint8_t_uint64_t);
  RUN_TEST(test_all_sfh_uint8_t_float);
  RUN_TEST(test_all_sfh_uint8_t_double);
  RUN_TEST(test_all_sfh_uint8_t_charptr);
  RUN_TEST(test_all_sfh_uint8_t_voidptr);
  RUN_TEST(test_all_sfh_uint16_t_int8_t);
  RUN_TEST(test_all_sfh_uint16_t_int16_t);
  RUN_TEST(test_all_sfh_uint16_t_int32_t);
  RUN_TEST(test_all_sfh_uint16_t_int64_t);
  RUN_TEST(test_all_sfh_uint16_t_uint8_t);
  RUN_TEST(test_all_sfh_uint16_t_uint16_t);
  RUN_TEST(test_all_sfh_uint16_t_uint32_t);
  RUN_TEST(test_all_sfh_uint16_t_uint64_t);
  RUN_TEST(test_all_sfh_uint16_t_float);
  RUN_TEST(test_all_sfh_uint16_t_double);
  RUN_TEST(test_all_sfh_uint16_t_charptr);
  RUN_TEST(test_all_sfh_uint16_t_voidptr);
  RUN_TEST(test_all_sfh_uint32_t_int8_t);
  RUN_TEST(test_all_sfh_uint32_t_int16_t);
  RUN_TEST(test_all_sfh_uint32_t_int32_t);
  RUN_TEST(test_all_sfh_uint32_t_int64_t);
  RUN_TEST(test_all_sfh_uint32_t_uint8_t);
  RUN_TEST(test_all_sfh_uint32_t_uint16_t);
  RUN_TEST(test_all_sfh_uint32_t_uint32_t);
  RUN_TEST(test_all_sfh_uint32_t_uint64_t);
  RUN_TEST(test_all_sfh_uint32_t_float);
  RUN_TEST(test_all_sfh_uint32_t_double);
  RUN_TEST(test_all_sfh_uint32_t_charptr);
  RUN_TEST(test_all_sfh_uint32_t_voidptr);
  RUN_TEST(test_all_sfh_uint64_t_int8_t);
  RUN_TEST(test_all_sfh_uint64_t_int16_t);
  RUN_TEST(test_all_sfh_uint64_t_int32_t);
  RUN_TEST(test_all_sfh_uint64_t_int64_t);
  RUN_TEST(test_all_sfh_uint64_t_uint8_t);
  RUN_TEST(test_all_sfh_uint64_t_uint16_t);
  RUN_TEST(test_all_sfh_uint64_t_uint32_t);
  RUN_TEST(test_all_sfh_uint64_t_uint64_t);
  RUN_TEST(test_all_sfh_uint64_t_float);
  RUN_TEST(test_all_sfh_uint64_t_double);
  RUN_TEST(test_all_sfh_uint64_t_charptr);
  RUN_TEST(test_all_sfh_uint64_t_voidptr);
  RUN_TEST(test_all_sfh_float_int8_t);
  RUN_TEST(test_all_sfh_float_int16_t);
  RUN_TEST(test_all_sfh_float_int32_t);
  RUN_TEST(test_all_sfh_float_int64_t);
  RUN_TEST(test_all_sfh_float_uint8_t);
  RUN_TEST(test_all_sfh_float_uint16_t);
  RUN_TEST(test_all_sfh_float_uint32_t);
  RUN_TEST(test_all_sfh_float_uint64_t);
  RUN_TEST(test_all_sfh_float_float);
  RUN_TEST(test_all_sfh_float_double);
  RUN_TEST(test_all_sfh_float_charptr);
  RUN_TEST(test_all_sfh_float_voidptr);
  RUN_TEST(test_all_sfh_double_int8_t);
  RUN_TEST(test_all_sfh_double_int16_t);
  RUN_TEST(test_all_sfh_double_int32_t);
  RUN_TEST(test_all_sfh_double_int64_t);
  RUN_TEST(test_all_sfh_double_uint8_t);
  RUN_TEST(test_all_sfh_double_uint16_t);
  RUN_TEST(test_all_sfh_double_uint32_t);
  RUN_TEST(test_all_sfh_double_uint64_t);
  RUN_TEST(test_all_sfh_double_float);
  RUN_TEST(test_all_sfh_double_double);
  RUN_TEST(test_all_sfh_double_charptr);
  RUN_TEST(test_all_sfh_double_voidptr);
}

GREATEST_MAIN_DEFS();
int main(int argc, char **argv) {
  GREATEST_MAIN_BEGIN();
  RUN_SUITE(strict_fibonacci_heaps_suite);
  GREATEST_MAIN_END();
}
