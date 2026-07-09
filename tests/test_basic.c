/* clang-format off */
#include <stdio.h>
#include <stdlib.h>
#include "greatest.h"
#include "c-strict-fibonacci-heaps.h"
/* clang-format on */

TEST test_all_sfh_int8_t_int8_t(void) {
  sfh_int8_t_int8_t_heap_t heap;
  sfh_int8_t_int8_t_node_t node;
  sfh_int8_t_int8_t_node_t *out_node;
  sfh_int8_t_int8_t_heap_t *out_heap;
  int is_empty;
  sfh_int8_t_int8_t_error_t rc;
  int i;

  rc = sfh_int8_t_int8_t_init(NULL);
  ASSERT_EQ(sfh_int8_t_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_int8_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int8_t_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_int8_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int8_t_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_int8_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int8_t_int8_t_ERR_NULL_ARG, rc);

  sfh_int8_t_int8_t_init(&heap);

  {
    sfh_int8_t_int8_t_node_t n1, n2, n3;
    rc = sfh_int8_t_int8_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int8_t_int8_t_SUCCESS, rc);
    rc = sfh_int8_t_int8_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int8_t_int8_t_SUCCESS, rc);
    rc = sfh_int8_t_int8_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int8_t_int8_t_SUCCESS, rc);
    rc = sfh_int8_t_int8_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int8_t_int8_t_SUCCESS, rc);
    rc = sfh_int8_t_int8_t_delete_min(&heap);
    ASSERT_EQ(sfh_int8_t_int8_t_SUCCESS, rc);
    rc = sfh_int8_t_int8_t_delete_min(&heap);
    ASSERT_EQ(sfh_int8_t_int8_t_SUCCESS, rc);
  }

  {
    sfh_int8_t_int8_t_node_t nodes[100];
    sfh_int8_t_int8_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int8_t_int8_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int8_t_int8_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int8_t_int8_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int8_t_int8_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int8_t_int8_t_init(&h1);
    sfh_int8_t_int8_t_init(&h2);
    sfh_int8_t_int8_t_init(&h3);
    sfh_int8_t_int8_t_init(&h4);
    sfh_int8_t_int8_t_insert(&h1, &n1, 1, 0);
    sfh_int8_t_int8_t_insert(&h1, &n2, 2, 0);
    sfh_int8_t_int8_t_insert(&h1, &n3, 3, 0);
    sfh_int8_t_int8_t_insert(&h1, &n4, 4, 0);
    sfh_int8_t_int8_t_insert(&h2, &m2, 10, 0);
    sfh_int8_t_int8_t_insert(&h3, &m3, 11, 0);
    sfh_int8_t_int8_t_insert(&h4, &m4, 12, 0);
    sfh_int8_t_int8_t_meld(&h1, &h2, &merged);
    sfh_int8_t_int8_t_meld(merged, &h3, &merged);
    sfh_int8_t_int8_t_meld(merged, &h4, &merged);
    sfh_int8_t_int8_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int8_t_int8_t_node_t large_nodes[1000];
    sfh_int8_t_int8_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int8_t_int8_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int8_t_int8_t_decrease_key(&heap, &large_nodes[i],
                                     large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int8_t_int8_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int8_t_int16_t(void) {
  sfh_int8_t_int16_t_heap_t heap;
  sfh_int8_t_int16_t_node_t node;
  sfh_int8_t_int16_t_node_t *out_node;
  sfh_int8_t_int16_t_heap_t *out_heap;
  int is_empty;
  sfh_int8_t_int16_t_error_t rc;
  int i;

  rc = sfh_int8_t_int16_t_init(NULL);
  ASSERT_EQ(sfh_int8_t_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_int16_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int8_t_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_int16_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int8_t_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_int16_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int8_t_int16_t_ERR_NULL_ARG, rc);

  sfh_int8_t_int16_t_init(&heap);

  {
    sfh_int8_t_int16_t_node_t n1, n2, n3;
    rc = sfh_int8_t_int16_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int8_t_int16_t_SUCCESS, rc);
    rc = sfh_int8_t_int16_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int8_t_int16_t_SUCCESS, rc);
    rc = sfh_int8_t_int16_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int8_t_int16_t_SUCCESS, rc);
    rc = sfh_int8_t_int16_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int8_t_int16_t_SUCCESS, rc);
    rc = sfh_int8_t_int16_t_delete_min(&heap);
    ASSERT_EQ(sfh_int8_t_int16_t_SUCCESS, rc);
    rc = sfh_int8_t_int16_t_delete_min(&heap);
    ASSERT_EQ(sfh_int8_t_int16_t_SUCCESS, rc);
  }

  {
    sfh_int8_t_int16_t_node_t nodes[100];
    sfh_int8_t_int16_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int8_t_int16_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int8_t_int16_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int8_t_int16_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int8_t_int16_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int8_t_int16_t_init(&h1);
    sfh_int8_t_int16_t_init(&h2);
    sfh_int8_t_int16_t_init(&h3);
    sfh_int8_t_int16_t_init(&h4);
    sfh_int8_t_int16_t_insert(&h1, &n1, 1, 0);
    sfh_int8_t_int16_t_insert(&h1, &n2, 2, 0);
    sfh_int8_t_int16_t_insert(&h1, &n3, 3, 0);
    sfh_int8_t_int16_t_insert(&h1, &n4, 4, 0);
    sfh_int8_t_int16_t_insert(&h2, &m2, 10, 0);
    sfh_int8_t_int16_t_insert(&h3, &m3, 11, 0);
    sfh_int8_t_int16_t_insert(&h4, &m4, 12, 0);
    sfh_int8_t_int16_t_meld(&h1, &h2, &merged);
    sfh_int8_t_int16_t_meld(merged, &h3, &merged);
    sfh_int8_t_int16_t_meld(merged, &h4, &merged);
    sfh_int8_t_int16_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int8_t_int16_t_node_t large_nodes[1000];
    sfh_int8_t_int16_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int8_t_int16_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int8_t_int16_t_decrease_key(&heap, &large_nodes[i],
                                      large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int8_t_int16_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int8_t_int32_t(void) {
  sfh_int8_t_int32_t_heap_t heap;
  sfh_int8_t_int32_t_node_t node;
  sfh_int8_t_int32_t_node_t *out_node;
  sfh_int8_t_int32_t_heap_t *out_heap;
  int is_empty;
  sfh_int8_t_int32_t_error_t rc;
  int i;

  rc = sfh_int8_t_int32_t_init(NULL);
  ASSERT_EQ(sfh_int8_t_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_int32_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int8_t_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_int32_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int8_t_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_int32_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int8_t_int32_t_ERR_NULL_ARG, rc);

  sfh_int8_t_int32_t_init(&heap);

  {
    sfh_int8_t_int32_t_node_t n1, n2, n3;
    rc = sfh_int8_t_int32_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int8_t_int32_t_SUCCESS, rc);
    rc = sfh_int8_t_int32_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int8_t_int32_t_SUCCESS, rc);
    rc = sfh_int8_t_int32_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int8_t_int32_t_SUCCESS, rc);
    rc = sfh_int8_t_int32_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int8_t_int32_t_SUCCESS, rc);
    rc = sfh_int8_t_int32_t_delete_min(&heap);
    ASSERT_EQ(sfh_int8_t_int32_t_SUCCESS, rc);
    rc = sfh_int8_t_int32_t_delete_min(&heap);
    ASSERT_EQ(sfh_int8_t_int32_t_SUCCESS, rc);
  }

  {
    sfh_int8_t_int32_t_node_t nodes[100];
    sfh_int8_t_int32_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int8_t_int32_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int8_t_int32_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int8_t_int32_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int8_t_int32_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int8_t_int32_t_init(&h1);
    sfh_int8_t_int32_t_init(&h2);
    sfh_int8_t_int32_t_init(&h3);
    sfh_int8_t_int32_t_init(&h4);
    sfh_int8_t_int32_t_insert(&h1, &n1, 1, 0);
    sfh_int8_t_int32_t_insert(&h1, &n2, 2, 0);
    sfh_int8_t_int32_t_insert(&h1, &n3, 3, 0);
    sfh_int8_t_int32_t_insert(&h1, &n4, 4, 0);
    sfh_int8_t_int32_t_insert(&h2, &m2, 10, 0);
    sfh_int8_t_int32_t_insert(&h3, &m3, 11, 0);
    sfh_int8_t_int32_t_insert(&h4, &m4, 12, 0);
    sfh_int8_t_int32_t_meld(&h1, &h2, &merged);
    sfh_int8_t_int32_t_meld(merged, &h3, &merged);
    sfh_int8_t_int32_t_meld(merged, &h4, &merged);
    sfh_int8_t_int32_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int8_t_int32_t_node_t large_nodes[1000];
    sfh_int8_t_int32_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int8_t_int32_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int8_t_int32_t_decrease_key(&heap, &large_nodes[i],
                                      large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int8_t_int32_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int8_t_int64_t(void) {
  sfh_int8_t_int64_t_heap_t heap;
  sfh_int8_t_int64_t_node_t node;
  sfh_int8_t_int64_t_node_t *out_node;
  sfh_int8_t_int64_t_heap_t *out_heap;
  int is_empty;
  sfh_int8_t_int64_t_error_t rc;
  int i;

  rc = sfh_int8_t_int64_t_init(NULL);
  ASSERT_EQ(sfh_int8_t_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_int64_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int8_t_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_int64_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int8_t_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_int64_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int8_t_int64_t_ERR_NULL_ARG, rc);

  sfh_int8_t_int64_t_init(&heap);

  {
    sfh_int8_t_int64_t_node_t n1, n2, n3;
    rc = sfh_int8_t_int64_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int8_t_int64_t_SUCCESS, rc);
    rc = sfh_int8_t_int64_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int8_t_int64_t_SUCCESS, rc);
    rc = sfh_int8_t_int64_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int8_t_int64_t_SUCCESS, rc);
    rc = sfh_int8_t_int64_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int8_t_int64_t_SUCCESS, rc);
    rc = sfh_int8_t_int64_t_delete_min(&heap);
    ASSERT_EQ(sfh_int8_t_int64_t_SUCCESS, rc);
    rc = sfh_int8_t_int64_t_delete_min(&heap);
    ASSERT_EQ(sfh_int8_t_int64_t_SUCCESS, rc);
  }

  {
    sfh_int8_t_int64_t_node_t nodes[100];
    sfh_int8_t_int64_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int8_t_int64_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int8_t_int64_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int8_t_int64_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int8_t_int64_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int8_t_int64_t_init(&h1);
    sfh_int8_t_int64_t_init(&h2);
    sfh_int8_t_int64_t_init(&h3);
    sfh_int8_t_int64_t_init(&h4);
    sfh_int8_t_int64_t_insert(&h1, &n1, 1, 0);
    sfh_int8_t_int64_t_insert(&h1, &n2, 2, 0);
    sfh_int8_t_int64_t_insert(&h1, &n3, 3, 0);
    sfh_int8_t_int64_t_insert(&h1, &n4, 4, 0);
    sfh_int8_t_int64_t_insert(&h2, &m2, 10, 0);
    sfh_int8_t_int64_t_insert(&h3, &m3, 11, 0);
    sfh_int8_t_int64_t_insert(&h4, &m4, 12, 0);
    sfh_int8_t_int64_t_meld(&h1, &h2, &merged);
    sfh_int8_t_int64_t_meld(merged, &h3, &merged);
    sfh_int8_t_int64_t_meld(merged, &h4, &merged);
    sfh_int8_t_int64_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int8_t_int64_t_node_t large_nodes[1000];
    sfh_int8_t_int64_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int8_t_int64_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int8_t_int64_t_decrease_key(&heap, &large_nodes[i],
                                      large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int8_t_int64_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int8_t_uint8_t(void) {
  sfh_int8_t_uint8_t_heap_t heap;
  sfh_int8_t_uint8_t_node_t node;
  sfh_int8_t_uint8_t_node_t *out_node;
  sfh_int8_t_uint8_t_heap_t *out_heap;
  int is_empty;
  sfh_int8_t_uint8_t_error_t rc;
  int i;

  rc = sfh_int8_t_uint8_t_init(NULL);
  ASSERT_EQ(sfh_int8_t_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_uint8_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int8_t_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_uint8_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int8_t_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_uint8_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int8_t_uint8_t_ERR_NULL_ARG, rc);

  sfh_int8_t_uint8_t_init(&heap);

  {
    sfh_int8_t_uint8_t_node_t n1, n2, n3;
    rc = sfh_int8_t_uint8_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int8_t_uint8_t_SUCCESS, rc);
    rc = sfh_int8_t_uint8_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int8_t_uint8_t_SUCCESS, rc);
    rc = sfh_int8_t_uint8_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int8_t_uint8_t_SUCCESS, rc);
    rc = sfh_int8_t_uint8_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int8_t_uint8_t_SUCCESS, rc);
    rc = sfh_int8_t_uint8_t_delete_min(&heap);
    ASSERT_EQ(sfh_int8_t_uint8_t_SUCCESS, rc);
    rc = sfh_int8_t_uint8_t_delete_min(&heap);
    ASSERT_EQ(sfh_int8_t_uint8_t_SUCCESS, rc);
  }

  {
    sfh_int8_t_uint8_t_node_t nodes[100];
    sfh_int8_t_uint8_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int8_t_uint8_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int8_t_uint8_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int8_t_uint8_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int8_t_uint8_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int8_t_uint8_t_init(&h1);
    sfh_int8_t_uint8_t_init(&h2);
    sfh_int8_t_uint8_t_init(&h3);
    sfh_int8_t_uint8_t_init(&h4);
    sfh_int8_t_uint8_t_insert(&h1, &n1, 1, 0);
    sfh_int8_t_uint8_t_insert(&h1, &n2, 2, 0);
    sfh_int8_t_uint8_t_insert(&h1, &n3, 3, 0);
    sfh_int8_t_uint8_t_insert(&h1, &n4, 4, 0);
    sfh_int8_t_uint8_t_insert(&h2, &m2, 10, 0);
    sfh_int8_t_uint8_t_insert(&h3, &m3, 11, 0);
    sfh_int8_t_uint8_t_insert(&h4, &m4, 12, 0);
    sfh_int8_t_uint8_t_meld(&h1, &h2, &merged);
    sfh_int8_t_uint8_t_meld(merged, &h3, &merged);
    sfh_int8_t_uint8_t_meld(merged, &h4, &merged);
    sfh_int8_t_uint8_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int8_t_uint8_t_node_t large_nodes[1000];
    sfh_int8_t_uint8_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int8_t_uint8_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int8_t_uint8_t_decrease_key(&heap, &large_nodes[i],
                                      large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int8_t_uint8_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int8_t_uint16_t(void) {
  sfh_int8_t_uint16_t_heap_t heap;
  sfh_int8_t_uint16_t_node_t node;
  sfh_int8_t_uint16_t_node_t *out_node;
  sfh_int8_t_uint16_t_heap_t *out_heap;
  int is_empty;
  sfh_int8_t_uint16_t_error_t rc;
  int i;

  rc = sfh_int8_t_uint16_t_init(NULL);
  ASSERT_EQ(sfh_int8_t_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_uint16_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int8_t_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_uint16_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int8_t_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_uint16_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int8_t_uint16_t_ERR_NULL_ARG, rc);

  sfh_int8_t_uint16_t_init(&heap);

  {
    sfh_int8_t_uint16_t_node_t n1, n2, n3;
    rc = sfh_int8_t_uint16_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int8_t_uint16_t_SUCCESS, rc);
    rc = sfh_int8_t_uint16_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int8_t_uint16_t_SUCCESS, rc);
    rc = sfh_int8_t_uint16_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int8_t_uint16_t_SUCCESS, rc);
    rc = sfh_int8_t_uint16_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int8_t_uint16_t_SUCCESS, rc);
    rc = sfh_int8_t_uint16_t_delete_min(&heap);
    ASSERT_EQ(sfh_int8_t_uint16_t_SUCCESS, rc);
    rc = sfh_int8_t_uint16_t_delete_min(&heap);
    ASSERT_EQ(sfh_int8_t_uint16_t_SUCCESS, rc);
  }

  {
    sfh_int8_t_uint16_t_node_t nodes[100];
    sfh_int8_t_uint16_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int8_t_uint16_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int8_t_uint16_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int8_t_uint16_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int8_t_uint16_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int8_t_uint16_t_init(&h1);
    sfh_int8_t_uint16_t_init(&h2);
    sfh_int8_t_uint16_t_init(&h3);
    sfh_int8_t_uint16_t_init(&h4);
    sfh_int8_t_uint16_t_insert(&h1, &n1, 1, 0);
    sfh_int8_t_uint16_t_insert(&h1, &n2, 2, 0);
    sfh_int8_t_uint16_t_insert(&h1, &n3, 3, 0);
    sfh_int8_t_uint16_t_insert(&h1, &n4, 4, 0);
    sfh_int8_t_uint16_t_insert(&h2, &m2, 10, 0);
    sfh_int8_t_uint16_t_insert(&h3, &m3, 11, 0);
    sfh_int8_t_uint16_t_insert(&h4, &m4, 12, 0);
    sfh_int8_t_uint16_t_meld(&h1, &h2, &merged);
    sfh_int8_t_uint16_t_meld(merged, &h3, &merged);
    sfh_int8_t_uint16_t_meld(merged, &h4, &merged);
    sfh_int8_t_uint16_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int8_t_uint16_t_node_t large_nodes[1000];
    sfh_int8_t_uint16_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int8_t_uint16_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int8_t_uint16_t_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int8_t_uint16_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int8_t_uint32_t(void) {
  sfh_int8_t_uint32_t_heap_t heap;
  sfh_int8_t_uint32_t_node_t node;
  sfh_int8_t_uint32_t_node_t *out_node;
  sfh_int8_t_uint32_t_heap_t *out_heap;
  int is_empty;
  sfh_int8_t_uint32_t_error_t rc;
  int i;

  rc = sfh_int8_t_uint32_t_init(NULL);
  ASSERT_EQ(sfh_int8_t_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_uint32_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int8_t_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_uint32_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int8_t_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_uint32_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int8_t_uint32_t_ERR_NULL_ARG, rc);

  sfh_int8_t_uint32_t_init(&heap);

  {
    sfh_int8_t_uint32_t_node_t n1, n2, n3;
    rc = sfh_int8_t_uint32_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int8_t_uint32_t_SUCCESS, rc);
    rc = sfh_int8_t_uint32_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int8_t_uint32_t_SUCCESS, rc);
    rc = sfh_int8_t_uint32_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int8_t_uint32_t_SUCCESS, rc);
    rc = sfh_int8_t_uint32_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int8_t_uint32_t_SUCCESS, rc);
    rc = sfh_int8_t_uint32_t_delete_min(&heap);
    ASSERT_EQ(sfh_int8_t_uint32_t_SUCCESS, rc);
    rc = sfh_int8_t_uint32_t_delete_min(&heap);
    ASSERT_EQ(sfh_int8_t_uint32_t_SUCCESS, rc);
  }

  {
    sfh_int8_t_uint32_t_node_t nodes[100];
    sfh_int8_t_uint32_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int8_t_uint32_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int8_t_uint32_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int8_t_uint32_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int8_t_uint32_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int8_t_uint32_t_init(&h1);
    sfh_int8_t_uint32_t_init(&h2);
    sfh_int8_t_uint32_t_init(&h3);
    sfh_int8_t_uint32_t_init(&h4);
    sfh_int8_t_uint32_t_insert(&h1, &n1, 1, 0);
    sfh_int8_t_uint32_t_insert(&h1, &n2, 2, 0);
    sfh_int8_t_uint32_t_insert(&h1, &n3, 3, 0);
    sfh_int8_t_uint32_t_insert(&h1, &n4, 4, 0);
    sfh_int8_t_uint32_t_insert(&h2, &m2, 10, 0);
    sfh_int8_t_uint32_t_insert(&h3, &m3, 11, 0);
    sfh_int8_t_uint32_t_insert(&h4, &m4, 12, 0);
    sfh_int8_t_uint32_t_meld(&h1, &h2, &merged);
    sfh_int8_t_uint32_t_meld(merged, &h3, &merged);
    sfh_int8_t_uint32_t_meld(merged, &h4, &merged);
    sfh_int8_t_uint32_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int8_t_uint32_t_node_t large_nodes[1000];
    sfh_int8_t_uint32_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int8_t_uint32_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int8_t_uint32_t_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int8_t_uint32_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int8_t_uint64_t(void) {
  sfh_int8_t_uint64_t_heap_t heap;
  sfh_int8_t_uint64_t_node_t node;
  sfh_int8_t_uint64_t_node_t *out_node;
  sfh_int8_t_uint64_t_heap_t *out_heap;
  int is_empty;
  sfh_int8_t_uint64_t_error_t rc;
  int i;

  rc = sfh_int8_t_uint64_t_init(NULL);
  ASSERT_EQ(sfh_int8_t_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_uint64_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int8_t_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_uint64_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int8_t_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_uint64_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int8_t_uint64_t_ERR_NULL_ARG, rc);

  sfh_int8_t_uint64_t_init(&heap);

  {
    sfh_int8_t_uint64_t_node_t n1, n2, n3;
    rc = sfh_int8_t_uint64_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int8_t_uint64_t_SUCCESS, rc);
    rc = sfh_int8_t_uint64_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int8_t_uint64_t_SUCCESS, rc);
    rc = sfh_int8_t_uint64_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int8_t_uint64_t_SUCCESS, rc);
    rc = sfh_int8_t_uint64_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int8_t_uint64_t_SUCCESS, rc);
    rc = sfh_int8_t_uint64_t_delete_min(&heap);
    ASSERT_EQ(sfh_int8_t_uint64_t_SUCCESS, rc);
    rc = sfh_int8_t_uint64_t_delete_min(&heap);
    ASSERT_EQ(sfh_int8_t_uint64_t_SUCCESS, rc);
  }

  {
    sfh_int8_t_uint64_t_node_t nodes[100];
    sfh_int8_t_uint64_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int8_t_uint64_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int8_t_uint64_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int8_t_uint64_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int8_t_uint64_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int8_t_uint64_t_init(&h1);
    sfh_int8_t_uint64_t_init(&h2);
    sfh_int8_t_uint64_t_init(&h3);
    sfh_int8_t_uint64_t_init(&h4);
    sfh_int8_t_uint64_t_insert(&h1, &n1, 1, 0);
    sfh_int8_t_uint64_t_insert(&h1, &n2, 2, 0);
    sfh_int8_t_uint64_t_insert(&h1, &n3, 3, 0);
    sfh_int8_t_uint64_t_insert(&h1, &n4, 4, 0);
    sfh_int8_t_uint64_t_insert(&h2, &m2, 10, 0);
    sfh_int8_t_uint64_t_insert(&h3, &m3, 11, 0);
    sfh_int8_t_uint64_t_insert(&h4, &m4, 12, 0);
    sfh_int8_t_uint64_t_meld(&h1, &h2, &merged);
    sfh_int8_t_uint64_t_meld(merged, &h3, &merged);
    sfh_int8_t_uint64_t_meld(merged, &h4, &merged);
    sfh_int8_t_uint64_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int8_t_uint64_t_node_t large_nodes[1000];
    sfh_int8_t_uint64_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int8_t_uint64_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int8_t_uint64_t_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int8_t_uint64_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int8_t_float(void) {
  sfh_int8_t_float_heap_t heap;
  sfh_int8_t_float_node_t node;
  sfh_int8_t_float_node_t *out_node;
  sfh_int8_t_float_heap_t *out_heap;
  int is_empty;
  sfh_int8_t_float_error_t rc;
  int i;

  rc = sfh_int8_t_float_init(NULL);
  ASSERT_EQ(sfh_int8_t_float_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_float_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int8_t_float_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_float_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int8_t_float_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_float_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int8_t_float_ERR_NULL_ARG, rc);

  sfh_int8_t_float_init(&heap);

  {
    sfh_int8_t_float_node_t n1, n2, n3;
    rc = sfh_int8_t_float_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int8_t_float_SUCCESS, rc);
    rc = sfh_int8_t_float_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int8_t_float_SUCCESS, rc);
    rc = sfh_int8_t_float_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int8_t_float_SUCCESS, rc);
    rc = sfh_int8_t_float_delete(&heap, &n2);
    ASSERT_EQ(sfh_int8_t_float_SUCCESS, rc);
    rc = sfh_int8_t_float_delete_min(&heap);
    ASSERT_EQ(sfh_int8_t_float_SUCCESS, rc);
    rc = sfh_int8_t_float_delete_min(&heap);
    ASSERT_EQ(sfh_int8_t_float_SUCCESS, rc);
  }

  {
    sfh_int8_t_float_node_t nodes[100];
    sfh_int8_t_float_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int8_t_float_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int8_t_float_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int8_t_float_heap_t h1, h2, h3, h4, *merged;
    sfh_int8_t_float_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int8_t_float_init(&h1);
    sfh_int8_t_float_init(&h2);
    sfh_int8_t_float_init(&h3);
    sfh_int8_t_float_init(&h4);
    sfh_int8_t_float_insert(&h1, &n1, 1, 0);
    sfh_int8_t_float_insert(&h1, &n2, 2, 0);
    sfh_int8_t_float_insert(&h1, &n3, 3, 0);
    sfh_int8_t_float_insert(&h1, &n4, 4, 0);
    sfh_int8_t_float_insert(&h2, &m2, 10, 0);
    sfh_int8_t_float_insert(&h3, &m3, 11, 0);
    sfh_int8_t_float_insert(&h4, &m4, 12, 0);
    sfh_int8_t_float_meld(&h1, &h2, &merged);
    sfh_int8_t_float_meld(merged, &h3, &merged);
    sfh_int8_t_float_meld(merged, &h4, &merged);
    sfh_int8_t_float_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int8_t_float_node_t large_nodes[1000];
    sfh_int8_t_float_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int8_t_float_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int8_t_float_decrease_key(&heap, &large_nodes[i],
                                    large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int8_t_float_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int8_t_double(void) {
  sfh_int8_t_double_heap_t heap;
  sfh_int8_t_double_node_t node;
  sfh_int8_t_double_node_t *out_node;
  sfh_int8_t_double_heap_t *out_heap;
  int is_empty;
  sfh_int8_t_double_error_t rc;
  int i;

  rc = sfh_int8_t_double_init(NULL);
  ASSERT_EQ(sfh_int8_t_double_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_double_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int8_t_double_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_double_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int8_t_double_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_double_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int8_t_double_ERR_NULL_ARG, rc);

  sfh_int8_t_double_init(&heap);

  {
    sfh_int8_t_double_node_t n1, n2, n3;
    rc = sfh_int8_t_double_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int8_t_double_SUCCESS, rc);
    rc = sfh_int8_t_double_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int8_t_double_SUCCESS, rc);
    rc = sfh_int8_t_double_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int8_t_double_SUCCESS, rc);
    rc = sfh_int8_t_double_delete(&heap, &n2);
    ASSERT_EQ(sfh_int8_t_double_SUCCESS, rc);
    rc = sfh_int8_t_double_delete_min(&heap);
    ASSERT_EQ(sfh_int8_t_double_SUCCESS, rc);
    rc = sfh_int8_t_double_delete_min(&heap);
    ASSERT_EQ(sfh_int8_t_double_SUCCESS, rc);
  }

  {
    sfh_int8_t_double_node_t nodes[100];
    sfh_int8_t_double_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int8_t_double_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int8_t_double_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int8_t_double_heap_t h1, h2, h3, h4, *merged;
    sfh_int8_t_double_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int8_t_double_init(&h1);
    sfh_int8_t_double_init(&h2);
    sfh_int8_t_double_init(&h3);
    sfh_int8_t_double_init(&h4);
    sfh_int8_t_double_insert(&h1, &n1, 1, 0);
    sfh_int8_t_double_insert(&h1, &n2, 2, 0);
    sfh_int8_t_double_insert(&h1, &n3, 3, 0);
    sfh_int8_t_double_insert(&h1, &n4, 4, 0);
    sfh_int8_t_double_insert(&h2, &m2, 10, 0);
    sfh_int8_t_double_insert(&h3, &m3, 11, 0);
    sfh_int8_t_double_insert(&h4, &m4, 12, 0);
    sfh_int8_t_double_meld(&h1, &h2, &merged);
    sfh_int8_t_double_meld(merged, &h3, &merged);
    sfh_int8_t_double_meld(merged, &h4, &merged);
    sfh_int8_t_double_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int8_t_double_node_t large_nodes[1000];
    sfh_int8_t_double_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int8_t_double_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int8_t_double_decrease_key(&heap, &large_nodes[i],
                                     large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int8_t_double_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int8_t_charptr(void) {
  sfh_int8_t_charptr_heap_t heap;
  sfh_int8_t_charptr_node_t node;
  sfh_int8_t_charptr_node_t *out_node;
  sfh_int8_t_charptr_heap_t *out_heap;
  int is_empty;
  sfh_int8_t_charptr_error_t rc;
  int i;

  rc = sfh_int8_t_charptr_init(NULL);
  ASSERT_EQ(sfh_int8_t_charptr_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_charptr_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int8_t_charptr_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_charptr_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int8_t_charptr_ERR_NULL_ARG, rc);
  rc = sfh_int8_t_charptr_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int8_t_charptr_ERR_NULL_ARG, rc);

  sfh_int8_t_charptr_init(&heap);

  {
    sfh_int8_t_charptr_node_t n1, n2, n3;
    rc = sfh_int8_t_charptr_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int8_t_charptr_SUCCESS, rc);
    rc = sfh_int8_t_charptr_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int8_t_charptr_SUCCESS, rc);
    rc = sfh_int8_t_charptr_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int8_t_charptr_SUCCESS, rc);
    rc = sfh_int8_t_charptr_delete(&heap, &n2);
    ASSERT_EQ(sfh_int8_t_charptr_SUCCESS, rc);
    rc = sfh_int8_t_charptr_delete_min(&heap);
    ASSERT_EQ(sfh_int8_t_charptr_SUCCESS, rc);
    rc = sfh_int8_t_charptr_delete_min(&heap);
    ASSERT_EQ(sfh_int8_t_charptr_SUCCESS, rc);
  }

  {
    sfh_int8_t_charptr_node_t nodes[100];
    sfh_int8_t_charptr_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int8_t_charptr_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int8_t_charptr_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int8_t_charptr_heap_t h1, h2, h3, h4, *merged;
    sfh_int8_t_charptr_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int8_t_charptr_init(&h1);
    sfh_int8_t_charptr_init(&h2);
    sfh_int8_t_charptr_init(&h3);
    sfh_int8_t_charptr_init(&h4);
    sfh_int8_t_charptr_insert(&h1, &n1, 1, 0);
    sfh_int8_t_charptr_insert(&h1, &n2, 2, 0);
    sfh_int8_t_charptr_insert(&h1, &n3, 3, 0);
    sfh_int8_t_charptr_insert(&h1, &n4, 4, 0);
    sfh_int8_t_charptr_insert(&h2, &m2, 10, 0);
    sfh_int8_t_charptr_insert(&h3, &m3, 11, 0);
    sfh_int8_t_charptr_insert(&h4, &m4, 12, 0);
    sfh_int8_t_charptr_meld(&h1, &h2, &merged);
    sfh_int8_t_charptr_meld(merged, &h3, &merged);
    sfh_int8_t_charptr_meld(merged, &h4, &merged);
    sfh_int8_t_charptr_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int8_t_charptr_node_t large_nodes[1000];
    sfh_int8_t_charptr_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int8_t_charptr_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int8_t_charptr_decrease_key(&heap, &large_nodes[i],
                                      large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int8_t_charptr_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int16_t_int8_t(void) {
  sfh_int16_t_int8_t_heap_t heap;
  sfh_int16_t_int8_t_node_t node;
  sfh_int16_t_int8_t_node_t *out_node;
  sfh_int16_t_int8_t_heap_t *out_heap;
  int is_empty;
  sfh_int16_t_int8_t_error_t rc;
  int i;

  rc = sfh_int16_t_int8_t_init(NULL);
  ASSERT_EQ(sfh_int16_t_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_int8_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int16_t_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_int8_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int16_t_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_int8_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int16_t_int8_t_ERR_NULL_ARG, rc);

  sfh_int16_t_int8_t_init(&heap);

  {
    sfh_int16_t_int8_t_node_t n1, n2, n3;
    rc = sfh_int16_t_int8_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int16_t_int8_t_SUCCESS, rc);
    rc = sfh_int16_t_int8_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int16_t_int8_t_SUCCESS, rc);
    rc = sfh_int16_t_int8_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int16_t_int8_t_SUCCESS, rc);
    rc = sfh_int16_t_int8_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int16_t_int8_t_SUCCESS, rc);
    rc = sfh_int16_t_int8_t_delete_min(&heap);
    ASSERT_EQ(sfh_int16_t_int8_t_SUCCESS, rc);
    rc = sfh_int16_t_int8_t_delete_min(&heap);
    ASSERT_EQ(sfh_int16_t_int8_t_SUCCESS, rc);
  }

  {
    sfh_int16_t_int8_t_node_t nodes[100];
    sfh_int16_t_int8_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int16_t_int8_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int16_t_int8_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int16_t_int8_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int16_t_int8_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int16_t_int8_t_init(&h1);
    sfh_int16_t_int8_t_init(&h2);
    sfh_int16_t_int8_t_init(&h3);
    sfh_int16_t_int8_t_init(&h4);
    sfh_int16_t_int8_t_insert(&h1, &n1, 1, 0);
    sfh_int16_t_int8_t_insert(&h1, &n2, 2, 0);
    sfh_int16_t_int8_t_insert(&h1, &n3, 3, 0);
    sfh_int16_t_int8_t_insert(&h1, &n4, 4, 0);
    sfh_int16_t_int8_t_insert(&h2, &m2, 10, 0);
    sfh_int16_t_int8_t_insert(&h3, &m3, 11, 0);
    sfh_int16_t_int8_t_insert(&h4, &m4, 12, 0);
    sfh_int16_t_int8_t_meld(&h1, &h2, &merged);
    sfh_int16_t_int8_t_meld(merged, &h3, &merged);
    sfh_int16_t_int8_t_meld(merged, &h4, &merged);
    sfh_int16_t_int8_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int16_t_int8_t_node_t large_nodes[1000];
    sfh_int16_t_int8_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int16_t_int8_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int16_t_int8_t_decrease_key(&heap, &large_nodes[i],
                                      large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int16_t_int8_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int16_t_int16_t(void) {
  sfh_int16_t_int16_t_heap_t heap;
  sfh_int16_t_int16_t_node_t node;
  sfh_int16_t_int16_t_node_t *out_node;
  sfh_int16_t_int16_t_heap_t *out_heap;
  int is_empty;
  sfh_int16_t_int16_t_error_t rc;
  int i;

  rc = sfh_int16_t_int16_t_init(NULL);
  ASSERT_EQ(sfh_int16_t_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_int16_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int16_t_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_int16_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int16_t_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_int16_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int16_t_int16_t_ERR_NULL_ARG, rc);

  sfh_int16_t_int16_t_init(&heap);

  {
    sfh_int16_t_int16_t_node_t n1, n2, n3;
    rc = sfh_int16_t_int16_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int16_t_int16_t_SUCCESS, rc);
    rc = sfh_int16_t_int16_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int16_t_int16_t_SUCCESS, rc);
    rc = sfh_int16_t_int16_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int16_t_int16_t_SUCCESS, rc);
    rc = sfh_int16_t_int16_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int16_t_int16_t_SUCCESS, rc);
    rc = sfh_int16_t_int16_t_delete_min(&heap);
    ASSERT_EQ(sfh_int16_t_int16_t_SUCCESS, rc);
    rc = sfh_int16_t_int16_t_delete_min(&heap);
    ASSERT_EQ(sfh_int16_t_int16_t_SUCCESS, rc);
  }

  {
    sfh_int16_t_int16_t_node_t nodes[100];
    sfh_int16_t_int16_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int16_t_int16_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int16_t_int16_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int16_t_int16_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int16_t_int16_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int16_t_int16_t_init(&h1);
    sfh_int16_t_int16_t_init(&h2);
    sfh_int16_t_int16_t_init(&h3);
    sfh_int16_t_int16_t_init(&h4);
    sfh_int16_t_int16_t_insert(&h1, &n1, 1, 0);
    sfh_int16_t_int16_t_insert(&h1, &n2, 2, 0);
    sfh_int16_t_int16_t_insert(&h1, &n3, 3, 0);
    sfh_int16_t_int16_t_insert(&h1, &n4, 4, 0);
    sfh_int16_t_int16_t_insert(&h2, &m2, 10, 0);
    sfh_int16_t_int16_t_insert(&h3, &m3, 11, 0);
    sfh_int16_t_int16_t_insert(&h4, &m4, 12, 0);
    sfh_int16_t_int16_t_meld(&h1, &h2, &merged);
    sfh_int16_t_int16_t_meld(merged, &h3, &merged);
    sfh_int16_t_int16_t_meld(merged, &h4, &merged);
    sfh_int16_t_int16_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int16_t_int16_t_node_t large_nodes[1000];
    sfh_int16_t_int16_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int16_t_int16_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int16_t_int16_t_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int16_t_int16_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int16_t_int32_t(void) {
  sfh_int16_t_int32_t_heap_t heap;
  sfh_int16_t_int32_t_node_t node;
  sfh_int16_t_int32_t_node_t *out_node;
  sfh_int16_t_int32_t_heap_t *out_heap;
  int is_empty;
  sfh_int16_t_int32_t_error_t rc;
  int i;

  rc = sfh_int16_t_int32_t_init(NULL);
  ASSERT_EQ(sfh_int16_t_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_int32_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int16_t_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_int32_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int16_t_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_int32_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int16_t_int32_t_ERR_NULL_ARG, rc);

  sfh_int16_t_int32_t_init(&heap);

  {
    sfh_int16_t_int32_t_node_t n1, n2, n3;
    rc = sfh_int16_t_int32_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int16_t_int32_t_SUCCESS, rc);
    rc = sfh_int16_t_int32_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int16_t_int32_t_SUCCESS, rc);
    rc = sfh_int16_t_int32_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int16_t_int32_t_SUCCESS, rc);
    rc = sfh_int16_t_int32_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int16_t_int32_t_SUCCESS, rc);
    rc = sfh_int16_t_int32_t_delete_min(&heap);
    ASSERT_EQ(sfh_int16_t_int32_t_SUCCESS, rc);
    rc = sfh_int16_t_int32_t_delete_min(&heap);
    ASSERT_EQ(sfh_int16_t_int32_t_SUCCESS, rc);
  }

  {
    sfh_int16_t_int32_t_node_t nodes[100];
    sfh_int16_t_int32_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int16_t_int32_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int16_t_int32_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int16_t_int32_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int16_t_int32_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int16_t_int32_t_init(&h1);
    sfh_int16_t_int32_t_init(&h2);
    sfh_int16_t_int32_t_init(&h3);
    sfh_int16_t_int32_t_init(&h4);
    sfh_int16_t_int32_t_insert(&h1, &n1, 1, 0);
    sfh_int16_t_int32_t_insert(&h1, &n2, 2, 0);
    sfh_int16_t_int32_t_insert(&h1, &n3, 3, 0);
    sfh_int16_t_int32_t_insert(&h1, &n4, 4, 0);
    sfh_int16_t_int32_t_insert(&h2, &m2, 10, 0);
    sfh_int16_t_int32_t_insert(&h3, &m3, 11, 0);
    sfh_int16_t_int32_t_insert(&h4, &m4, 12, 0);
    sfh_int16_t_int32_t_meld(&h1, &h2, &merged);
    sfh_int16_t_int32_t_meld(merged, &h3, &merged);
    sfh_int16_t_int32_t_meld(merged, &h4, &merged);
    sfh_int16_t_int32_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int16_t_int32_t_node_t large_nodes[1000];
    sfh_int16_t_int32_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int16_t_int32_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int16_t_int32_t_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int16_t_int32_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int16_t_int64_t(void) {
  sfh_int16_t_int64_t_heap_t heap;
  sfh_int16_t_int64_t_node_t node;
  sfh_int16_t_int64_t_node_t *out_node;
  sfh_int16_t_int64_t_heap_t *out_heap;
  int is_empty;
  sfh_int16_t_int64_t_error_t rc;
  int i;

  rc = sfh_int16_t_int64_t_init(NULL);
  ASSERT_EQ(sfh_int16_t_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_int64_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int16_t_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_int64_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int16_t_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_int64_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int16_t_int64_t_ERR_NULL_ARG, rc);

  sfh_int16_t_int64_t_init(&heap);

  {
    sfh_int16_t_int64_t_node_t n1, n2, n3;
    rc = sfh_int16_t_int64_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int16_t_int64_t_SUCCESS, rc);
    rc = sfh_int16_t_int64_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int16_t_int64_t_SUCCESS, rc);
    rc = sfh_int16_t_int64_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int16_t_int64_t_SUCCESS, rc);
    rc = sfh_int16_t_int64_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int16_t_int64_t_SUCCESS, rc);
    rc = sfh_int16_t_int64_t_delete_min(&heap);
    ASSERT_EQ(sfh_int16_t_int64_t_SUCCESS, rc);
    rc = sfh_int16_t_int64_t_delete_min(&heap);
    ASSERT_EQ(sfh_int16_t_int64_t_SUCCESS, rc);
  }

  {
    sfh_int16_t_int64_t_node_t nodes[100];
    sfh_int16_t_int64_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int16_t_int64_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int16_t_int64_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int16_t_int64_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int16_t_int64_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int16_t_int64_t_init(&h1);
    sfh_int16_t_int64_t_init(&h2);
    sfh_int16_t_int64_t_init(&h3);
    sfh_int16_t_int64_t_init(&h4);
    sfh_int16_t_int64_t_insert(&h1, &n1, 1, 0);
    sfh_int16_t_int64_t_insert(&h1, &n2, 2, 0);
    sfh_int16_t_int64_t_insert(&h1, &n3, 3, 0);
    sfh_int16_t_int64_t_insert(&h1, &n4, 4, 0);
    sfh_int16_t_int64_t_insert(&h2, &m2, 10, 0);
    sfh_int16_t_int64_t_insert(&h3, &m3, 11, 0);
    sfh_int16_t_int64_t_insert(&h4, &m4, 12, 0);
    sfh_int16_t_int64_t_meld(&h1, &h2, &merged);
    sfh_int16_t_int64_t_meld(merged, &h3, &merged);
    sfh_int16_t_int64_t_meld(merged, &h4, &merged);
    sfh_int16_t_int64_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int16_t_int64_t_node_t large_nodes[1000];
    sfh_int16_t_int64_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int16_t_int64_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int16_t_int64_t_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int16_t_int64_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int16_t_uint8_t(void) {
  sfh_int16_t_uint8_t_heap_t heap;
  sfh_int16_t_uint8_t_node_t node;
  sfh_int16_t_uint8_t_node_t *out_node;
  sfh_int16_t_uint8_t_heap_t *out_heap;
  int is_empty;
  sfh_int16_t_uint8_t_error_t rc;
  int i;

  rc = sfh_int16_t_uint8_t_init(NULL);
  ASSERT_EQ(sfh_int16_t_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_uint8_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int16_t_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_uint8_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int16_t_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_uint8_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int16_t_uint8_t_ERR_NULL_ARG, rc);

  sfh_int16_t_uint8_t_init(&heap);

  {
    sfh_int16_t_uint8_t_node_t n1, n2, n3;
    rc = sfh_int16_t_uint8_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int16_t_uint8_t_SUCCESS, rc);
    rc = sfh_int16_t_uint8_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int16_t_uint8_t_SUCCESS, rc);
    rc = sfh_int16_t_uint8_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int16_t_uint8_t_SUCCESS, rc);
    rc = sfh_int16_t_uint8_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int16_t_uint8_t_SUCCESS, rc);
    rc = sfh_int16_t_uint8_t_delete_min(&heap);
    ASSERT_EQ(sfh_int16_t_uint8_t_SUCCESS, rc);
    rc = sfh_int16_t_uint8_t_delete_min(&heap);
    ASSERT_EQ(sfh_int16_t_uint8_t_SUCCESS, rc);
  }

  {
    sfh_int16_t_uint8_t_node_t nodes[100];
    sfh_int16_t_uint8_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int16_t_uint8_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int16_t_uint8_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int16_t_uint8_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int16_t_uint8_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int16_t_uint8_t_init(&h1);
    sfh_int16_t_uint8_t_init(&h2);
    sfh_int16_t_uint8_t_init(&h3);
    sfh_int16_t_uint8_t_init(&h4);
    sfh_int16_t_uint8_t_insert(&h1, &n1, 1, 0);
    sfh_int16_t_uint8_t_insert(&h1, &n2, 2, 0);
    sfh_int16_t_uint8_t_insert(&h1, &n3, 3, 0);
    sfh_int16_t_uint8_t_insert(&h1, &n4, 4, 0);
    sfh_int16_t_uint8_t_insert(&h2, &m2, 10, 0);
    sfh_int16_t_uint8_t_insert(&h3, &m3, 11, 0);
    sfh_int16_t_uint8_t_insert(&h4, &m4, 12, 0);
    sfh_int16_t_uint8_t_meld(&h1, &h2, &merged);
    sfh_int16_t_uint8_t_meld(merged, &h3, &merged);
    sfh_int16_t_uint8_t_meld(merged, &h4, &merged);
    sfh_int16_t_uint8_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int16_t_uint8_t_node_t large_nodes[1000];
    sfh_int16_t_uint8_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int16_t_uint8_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int16_t_uint8_t_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int16_t_uint8_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int16_t_uint16_t(void) {
  sfh_int16_t_uint16_t_heap_t heap;
  sfh_int16_t_uint16_t_node_t node;
  sfh_int16_t_uint16_t_node_t *out_node;
  sfh_int16_t_uint16_t_heap_t *out_heap;
  int is_empty;
  sfh_int16_t_uint16_t_error_t rc;
  int i;

  rc = sfh_int16_t_uint16_t_init(NULL);
  ASSERT_EQ(sfh_int16_t_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_uint16_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int16_t_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_uint16_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int16_t_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_uint16_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int16_t_uint16_t_ERR_NULL_ARG, rc);

  sfh_int16_t_uint16_t_init(&heap);

  {
    sfh_int16_t_uint16_t_node_t n1, n2, n3;
    rc = sfh_int16_t_uint16_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int16_t_uint16_t_SUCCESS, rc);
    rc = sfh_int16_t_uint16_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int16_t_uint16_t_SUCCESS, rc);
    rc = sfh_int16_t_uint16_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int16_t_uint16_t_SUCCESS, rc);
    rc = sfh_int16_t_uint16_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int16_t_uint16_t_SUCCESS, rc);
    rc = sfh_int16_t_uint16_t_delete_min(&heap);
    ASSERT_EQ(sfh_int16_t_uint16_t_SUCCESS, rc);
    rc = sfh_int16_t_uint16_t_delete_min(&heap);
    ASSERT_EQ(sfh_int16_t_uint16_t_SUCCESS, rc);
  }

  {
    sfh_int16_t_uint16_t_node_t nodes[100];
    sfh_int16_t_uint16_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int16_t_uint16_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int16_t_uint16_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int16_t_uint16_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int16_t_uint16_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int16_t_uint16_t_init(&h1);
    sfh_int16_t_uint16_t_init(&h2);
    sfh_int16_t_uint16_t_init(&h3);
    sfh_int16_t_uint16_t_init(&h4);
    sfh_int16_t_uint16_t_insert(&h1, &n1, 1, 0);
    sfh_int16_t_uint16_t_insert(&h1, &n2, 2, 0);
    sfh_int16_t_uint16_t_insert(&h1, &n3, 3, 0);
    sfh_int16_t_uint16_t_insert(&h1, &n4, 4, 0);
    sfh_int16_t_uint16_t_insert(&h2, &m2, 10, 0);
    sfh_int16_t_uint16_t_insert(&h3, &m3, 11, 0);
    sfh_int16_t_uint16_t_insert(&h4, &m4, 12, 0);
    sfh_int16_t_uint16_t_meld(&h1, &h2, &merged);
    sfh_int16_t_uint16_t_meld(merged, &h3, &merged);
    sfh_int16_t_uint16_t_meld(merged, &h4, &merged);
    sfh_int16_t_uint16_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int16_t_uint16_t_node_t large_nodes[1000];
    sfh_int16_t_uint16_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int16_t_uint16_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int16_t_uint16_t_decrease_key(&heap, &large_nodes[i],
                                        large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int16_t_uint16_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int16_t_uint32_t(void) {
  sfh_int16_t_uint32_t_heap_t heap;
  sfh_int16_t_uint32_t_node_t node;
  sfh_int16_t_uint32_t_node_t *out_node;
  sfh_int16_t_uint32_t_heap_t *out_heap;
  int is_empty;
  sfh_int16_t_uint32_t_error_t rc;
  int i;

  rc = sfh_int16_t_uint32_t_init(NULL);
  ASSERT_EQ(sfh_int16_t_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_uint32_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int16_t_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_uint32_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int16_t_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_uint32_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int16_t_uint32_t_ERR_NULL_ARG, rc);

  sfh_int16_t_uint32_t_init(&heap);

  {
    sfh_int16_t_uint32_t_node_t n1, n2, n3;
    rc = sfh_int16_t_uint32_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int16_t_uint32_t_SUCCESS, rc);
    rc = sfh_int16_t_uint32_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int16_t_uint32_t_SUCCESS, rc);
    rc = sfh_int16_t_uint32_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int16_t_uint32_t_SUCCESS, rc);
    rc = sfh_int16_t_uint32_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int16_t_uint32_t_SUCCESS, rc);
    rc = sfh_int16_t_uint32_t_delete_min(&heap);
    ASSERT_EQ(sfh_int16_t_uint32_t_SUCCESS, rc);
    rc = sfh_int16_t_uint32_t_delete_min(&heap);
    ASSERT_EQ(sfh_int16_t_uint32_t_SUCCESS, rc);
  }

  {
    sfh_int16_t_uint32_t_node_t nodes[100];
    sfh_int16_t_uint32_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int16_t_uint32_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int16_t_uint32_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int16_t_uint32_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int16_t_uint32_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int16_t_uint32_t_init(&h1);
    sfh_int16_t_uint32_t_init(&h2);
    sfh_int16_t_uint32_t_init(&h3);
    sfh_int16_t_uint32_t_init(&h4);
    sfh_int16_t_uint32_t_insert(&h1, &n1, 1, 0);
    sfh_int16_t_uint32_t_insert(&h1, &n2, 2, 0);
    sfh_int16_t_uint32_t_insert(&h1, &n3, 3, 0);
    sfh_int16_t_uint32_t_insert(&h1, &n4, 4, 0);
    sfh_int16_t_uint32_t_insert(&h2, &m2, 10, 0);
    sfh_int16_t_uint32_t_insert(&h3, &m3, 11, 0);
    sfh_int16_t_uint32_t_insert(&h4, &m4, 12, 0);
    sfh_int16_t_uint32_t_meld(&h1, &h2, &merged);
    sfh_int16_t_uint32_t_meld(merged, &h3, &merged);
    sfh_int16_t_uint32_t_meld(merged, &h4, &merged);
    sfh_int16_t_uint32_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int16_t_uint32_t_node_t large_nodes[1000];
    sfh_int16_t_uint32_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int16_t_uint32_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int16_t_uint32_t_decrease_key(&heap, &large_nodes[i],
                                        large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int16_t_uint32_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int16_t_uint64_t(void) {
  sfh_int16_t_uint64_t_heap_t heap;
  sfh_int16_t_uint64_t_node_t node;
  sfh_int16_t_uint64_t_node_t *out_node;
  sfh_int16_t_uint64_t_heap_t *out_heap;
  int is_empty;
  sfh_int16_t_uint64_t_error_t rc;
  int i;

  rc = sfh_int16_t_uint64_t_init(NULL);
  ASSERT_EQ(sfh_int16_t_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_uint64_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int16_t_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_uint64_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int16_t_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_uint64_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int16_t_uint64_t_ERR_NULL_ARG, rc);

  sfh_int16_t_uint64_t_init(&heap);

  {
    sfh_int16_t_uint64_t_node_t n1, n2, n3;
    rc = sfh_int16_t_uint64_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int16_t_uint64_t_SUCCESS, rc);
    rc = sfh_int16_t_uint64_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int16_t_uint64_t_SUCCESS, rc);
    rc = sfh_int16_t_uint64_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int16_t_uint64_t_SUCCESS, rc);
    rc = sfh_int16_t_uint64_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int16_t_uint64_t_SUCCESS, rc);
    rc = sfh_int16_t_uint64_t_delete_min(&heap);
    ASSERT_EQ(sfh_int16_t_uint64_t_SUCCESS, rc);
    rc = sfh_int16_t_uint64_t_delete_min(&heap);
    ASSERT_EQ(sfh_int16_t_uint64_t_SUCCESS, rc);
  }

  {
    sfh_int16_t_uint64_t_node_t nodes[100];
    sfh_int16_t_uint64_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int16_t_uint64_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int16_t_uint64_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int16_t_uint64_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int16_t_uint64_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int16_t_uint64_t_init(&h1);
    sfh_int16_t_uint64_t_init(&h2);
    sfh_int16_t_uint64_t_init(&h3);
    sfh_int16_t_uint64_t_init(&h4);
    sfh_int16_t_uint64_t_insert(&h1, &n1, 1, 0);
    sfh_int16_t_uint64_t_insert(&h1, &n2, 2, 0);
    sfh_int16_t_uint64_t_insert(&h1, &n3, 3, 0);
    sfh_int16_t_uint64_t_insert(&h1, &n4, 4, 0);
    sfh_int16_t_uint64_t_insert(&h2, &m2, 10, 0);
    sfh_int16_t_uint64_t_insert(&h3, &m3, 11, 0);
    sfh_int16_t_uint64_t_insert(&h4, &m4, 12, 0);
    sfh_int16_t_uint64_t_meld(&h1, &h2, &merged);
    sfh_int16_t_uint64_t_meld(merged, &h3, &merged);
    sfh_int16_t_uint64_t_meld(merged, &h4, &merged);
    sfh_int16_t_uint64_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int16_t_uint64_t_node_t large_nodes[1000];
    sfh_int16_t_uint64_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int16_t_uint64_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int16_t_uint64_t_decrease_key(&heap, &large_nodes[i],
                                        large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int16_t_uint64_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int16_t_float(void) {
  sfh_int16_t_float_heap_t heap;
  sfh_int16_t_float_node_t node;
  sfh_int16_t_float_node_t *out_node;
  sfh_int16_t_float_heap_t *out_heap;
  int is_empty;
  sfh_int16_t_float_error_t rc;
  int i;

  rc = sfh_int16_t_float_init(NULL);
  ASSERT_EQ(sfh_int16_t_float_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_float_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int16_t_float_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_float_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int16_t_float_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_float_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int16_t_float_ERR_NULL_ARG, rc);

  sfh_int16_t_float_init(&heap);

  {
    sfh_int16_t_float_node_t n1, n2, n3;
    rc = sfh_int16_t_float_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int16_t_float_SUCCESS, rc);
    rc = sfh_int16_t_float_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int16_t_float_SUCCESS, rc);
    rc = sfh_int16_t_float_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int16_t_float_SUCCESS, rc);
    rc = sfh_int16_t_float_delete(&heap, &n2);
    ASSERT_EQ(sfh_int16_t_float_SUCCESS, rc);
    rc = sfh_int16_t_float_delete_min(&heap);
    ASSERT_EQ(sfh_int16_t_float_SUCCESS, rc);
    rc = sfh_int16_t_float_delete_min(&heap);
    ASSERT_EQ(sfh_int16_t_float_SUCCESS, rc);
  }

  {
    sfh_int16_t_float_node_t nodes[100];
    sfh_int16_t_float_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int16_t_float_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int16_t_float_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int16_t_float_heap_t h1, h2, h3, h4, *merged;
    sfh_int16_t_float_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int16_t_float_init(&h1);
    sfh_int16_t_float_init(&h2);
    sfh_int16_t_float_init(&h3);
    sfh_int16_t_float_init(&h4);
    sfh_int16_t_float_insert(&h1, &n1, 1, 0);
    sfh_int16_t_float_insert(&h1, &n2, 2, 0);
    sfh_int16_t_float_insert(&h1, &n3, 3, 0);
    sfh_int16_t_float_insert(&h1, &n4, 4, 0);
    sfh_int16_t_float_insert(&h2, &m2, 10, 0);
    sfh_int16_t_float_insert(&h3, &m3, 11, 0);
    sfh_int16_t_float_insert(&h4, &m4, 12, 0);
    sfh_int16_t_float_meld(&h1, &h2, &merged);
    sfh_int16_t_float_meld(merged, &h3, &merged);
    sfh_int16_t_float_meld(merged, &h4, &merged);
    sfh_int16_t_float_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int16_t_float_node_t large_nodes[1000];
    sfh_int16_t_float_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int16_t_float_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int16_t_float_decrease_key(&heap, &large_nodes[i],
                                     large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int16_t_float_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int16_t_double(void) {
  sfh_int16_t_double_heap_t heap;
  sfh_int16_t_double_node_t node;
  sfh_int16_t_double_node_t *out_node;
  sfh_int16_t_double_heap_t *out_heap;
  int is_empty;
  sfh_int16_t_double_error_t rc;
  int i;

  rc = sfh_int16_t_double_init(NULL);
  ASSERT_EQ(sfh_int16_t_double_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_double_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int16_t_double_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_double_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int16_t_double_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_double_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int16_t_double_ERR_NULL_ARG, rc);

  sfh_int16_t_double_init(&heap);

  {
    sfh_int16_t_double_node_t n1, n2, n3;
    rc = sfh_int16_t_double_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int16_t_double_SUCCESS, rc);
    rc = sfh_int16_t_double_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int16_t_double_SUCCESS, rc);
    rc = sfh_int16_t_double_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int16_t_double_SUCCESS, rc);
    rc = sfh_int16_t_double_delete(&heap, &n2);
    ASSERT_EQ(sfh_int16_t_double_SUCCESS, rc);
    rc = sfh_int16_t_double_delete_min(&heap);
    ASSERT_EQ(sfh_int16_t_double_SUCCESS, rc);
    rc = sfh_int16_t_double_delete_min(&heap);
    ASSERT_EQ(sfh_int16_t_double_SUCCESS, rc);
  }

  {
    sfh_int16_t_double_node_t nodes[100];
    sfh_int16_t_double_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int16_t_double_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int16_t_double_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int16_t_double_heap_t h1, h2, h3, h4, *merged;
    sfh_int16_t_double_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int16_t_double_init(&h1);
    sfh_int16_t_double_init(&h2);
    sfh_int16_t_double_init(&h3);
    sfh_int16_t_double_init(&h4);
    sfh_int16_t_double_insert(&h1, &n1, 1, 0);
    sfh_int16_t_double_insert(&h1, &n2, 2, 0);
    sfh_int16_t_double_insert(&h1, &n3, 3, 0);
    sfh_int16_t_double_insert(&h1, &n4, 4, 0);
    sfh_int16_t_double_insert(&h2, &m2, 10, 0);
    sfh_int16_t_double_insert(&h3, &m3, 11, 0);
    sfh_int16_t_double_insert(&h4, &m4, 12, 0);
    sfh_int16_t_double_meld(&h1, &h2, &merged);
    sfh_int16_t_double_meld(merged, &h3, &merged);
    sfh_int16_t_double_meld(merged, &h4, &merged);
    sfh_int16_t_double_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int16_t_double_node_t large_nodes[1000];
    sfh_int16_t_double_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int16_t_double_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int16_t_double_decrease_key(&heap, &large_nodes[i],
                                      large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int16_t_double_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int16_t_charptr(void) {
  sfh_int16_t_charptr_heap_t heap;
  sfh_int16_t_charptr_node_t node;
  sfh_int16_t_charptr_node_t *out_node;
  sfh_int16_t_charptr_heap_t *out_heap;
  int is_empty;
  sfh_int16_t_charptr_error_t rc;
  int i;

  rc = sfh_int16_t_charptr_init(NULL);
  ASSERT_EQ(sfh_int16_t_charptr_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_charptr_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int16_t_charptr_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_charptr_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int16_t_charptr_ERR_NULL_ARG, rc);
  rc = sfh_int16_t_charptr_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int16_t_charptr_ERR_NULL_ARG, rc);

  sfh_int16_t_charptr_init(&heap);

  {
    sfh_int16_t_charptr_node_t n1, n2, n3;
    rc = sfh_int16_t_charptr_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int16_t_charptr_SUCCESS, rc);
    rc = sfh_int16_t_charptr_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int16_t_charptr_SUCCESS, rc);
    rc = sfh_int16_t_charptr_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int16_t_charptr_SUCCESS, rc);
    rc = sfh_int16_t_charptr_delete(&heap, &n2);
    ASSERT_EQ(sfh_int16_t_charptr_SUCCESS, rc);
    rc = sfh_int16_t_charptr_delete_min(&heap);
    ASSERT_EQ(sfh_int16_t_charptr_SUCCESS, rc);
    rc = sfh_int16_t_charptr_delete_min(&heap);
    ASSERT_EQ(sfh_int16_t_charptr_SUCCESS, rc);
  }

  {
    sfh_int16_t_charptr_node_t nodes[100];
    sfh_int16_t_charptr_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int16_t_charptr_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int16_t_charptr_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int16_t_charptr_heap_t h1, h2, h3, h4, *merged;
    sfh_int16_t_charptr_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int16_t_charptr_init(&h1);
    sfh_int16_t_charptr_init(&h2);
    sfh_int16_t_charptr_init(&h3);
    sfh_int16_t_charptr_init(&h4);
    sfh_int16_t_charptr_insert(&h1, &n1, 1, 0);
    sfh_int16_t_charptr_insert(&h1, &n2, 2, 0);
    sfh_int16_t_charptr_insert(&h1, &n3, 3, 0);
    sfh_int16_t_charptr_insert(&h1, &n4, 4, 0);
    sfh_int16_t_charptr_insert(&h2, &m2, 10, 0);
    sfh_int16_t_charptr_insert(&h3, &m3, 11, 0);
    sfh_int16_t_charptr_insert(&h4, &m4, 12, 0);
    sfh_int16_t_charptr_meld(&h1, &h2, &merged);
    sfh_int16_t_charptr_meld(merged, &h3, &merged);
    sfh_int16_t_charptr_meld(merged, &h4, &merged);
    sfh_int16_t_charptr_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int16_t_charptr_node_t large_nodes[1000];
    sfh_int16_t_charptr_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int16_t_charptr_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int16_t_charptr_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int16_t_charptr_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int32_t_int8_t(void) {
  sfh_int32_t_int8_t_heap_t heap;
  sfh_int32_t_int8_t_node_t node;
  sfh_int32_t_int8_t_node_t *out_node;
  sfh_int32_t_int8_t_heap_t *out_heap;
  int is_empty;
  sfh_int32_t_int8_t_error_t rc;
  int i;

  rc = sfh_int32_t_int8_t_init(NULL);
  ASSERT_EQ(sfh_int32_t_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_int8_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int32_t_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_int8_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int32_t_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_int8_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int32_t_int8_t_ERR_NULL_ARG, rc);

  sfh_int32_t_int8_t_init(&heap);

  {
    sfh_int32_t_int8_t_node_t n1, n2, n3;
    rc = sfh_int32_t_int8_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int32_t_int8_t_SUCCESS, rc);
    rc = sfh_int32_t_int8_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int32_t_int8_t_SUCCESS, rc);
    rc = sfh_int32_t_int8_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int32_t_int8_t_SUCCESS, rc);
    rc = sfh_int32_t_int8_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int32_t_int8_t_SUCCESS, rc);
    rc = sfh_int32_t_int8_t_delete_min(&heap);
    ASSERT_EQ(sfh_int32_t_int8_t_SUCCESS, rc);
    rc = sfh_int32_t_int8_t_delete_min(&heap);
    ASSERT_EQ(sfh_int32_t_int8_t_SUCCESS, rc);
  }

  {
    sfh_int32_t_int8_t_node_t nodes[100];
    sfh_int32_t_int8_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int32_t_int8_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int32_t_int8_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int32_t_int8_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int32_t_int8_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int32_t_int8_t_init(&h1);
    sfh_int32_t_int8_t_init(&h2);
    sfh_int32_t_int8_t_init(&h3);
    sfh_int32_t_int8_t_init(&h4);
    sfh_int32_t_int8_t_insert(&h1, &n1, 1, 0);
    sfh_int32_t_int8_t_insert(&h1, &n2, 2, 0);
    sfh_int32_t_int8_t_insert(&h1, &n3, 3, 0);
    sfh_int32_t_int8_t_insert(&h1, &n4, 4, 0);
    sfh_int32_t_int8_t_insert(&h2, &m2, 10, 0);
    sfh_int32_t_int8_t_insert(&h3, &m3, 11, 0);
    sfh_int32_t_int8_t_insert(&h4, &m4, 12, 0);
    sfh_int32_t_int8_t_meld(&h1, &h2, &merged);
    sfh_int32_t_int8_t_meld(merged, &h3, &merged);
    sfh_int32_t_int8_t_meld(merged, &h4, &merged);
    sfh_int32_t_int8_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int32_t_int8_t_node_t large_nodes[1000];
    sfh_int32_t_int8_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int32_t_int8_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int32_t_int8_t_decrease_key(&heap, &large_nodes[i],
                                      large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int32_t_int8_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int32_t_int16_t(void) {
  sfh_int32_t_int16_t_heap_t heap;
  sfh_int32_t_int16_t_node_t node;
  sfh_int32_t_int16_t_node_t *out_node;
  sfh_int32_t_int16_t_heap_t *out_heap;
  int is_empty;
  sfh_int32_t_int16_t_error_t rc;
  int i;

  rc = sfh_int32_t_int16_t_init(NULL);
  ASSERT_EQ(sfh_int32_t_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_int16_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int32_t_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_int16_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int32_t_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_int16_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int32_t_int16_t_ERR_NULL_ARG, rc);

  sfh_int32_t_int16_t_init(&heap);

  {
    sfh_int32_t_int16_t_node_t n1, n2, n3;
    rc = sfh_int32_t_int16_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int32_t_int16_t_SUCCESS, rc);
    rc = sfh_int32_t_int16_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int32_t_int16_t_SUCCESS, rc);
    rc = sfh_int32_t_int16_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int32_t_int16_t_SUCCESS, rc);
    rc = sfh_int32_t_int16_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int32_t_int16_t_SUCCESS, rc);
    rc = sfh_int32_t_int16_t_delete_min(&heap);
    ASSERT_EQ(sfh_int32_t_int16_t_SUCCESS, rc);
    rc = sfh_int32_t_int16_t_delete_min(&heap);
    ASSERT_EQ(sfh_int32_t_int16_t_SUCCESS, rc);
  }

  {
    sfh_int32_t_int16_t_node_t nodes[100];
    sfh_int32_t_int16_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int32_t_int16_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int32_t_int16_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int32_t_int16_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int32_t_int16_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int32_t_int16_t_init(&h1);
    sfh_int32_t_int16_t_init(&h2);
    sfh_int32_t_int16_t_init(&h3);
    sfh_int32_t_int16_t_init(&h4);
    sfh_int32_t_int16_t_insert(&h1, &n1, 1, 0);
    sfh_int32_t_int16_t_insert(&h1, &n2, 2, 0);
    sfh_int32_t_int16_t_insert(&h1, &n3, 3, 0);
    sfh_int32_t_int16_t_insert(&h1, &n4, 4, 0);
    sfh_int32_t_int16_t_insert(&h2, &m2, 10, 0);
    sfh_int32_t_int16_t_insert(&h3, &m3, 11, 0);
    sfh_int32_t_int16_t_insert(&h4, &m4, 12, 0);
    sfh_int32_t_int16_t_meld(&h1, &h2, &merged);
    sfh_int32_t_int16_t_meld(merged, &h3, &merged);
    sfh_int32_t_int16_t_meld(merged, &h4, &merged);
    sfh_int32_t_int16_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int32_t_int16_t_node_t large_nodes[1000];
    sfh_int32_t_int16_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int32_t_int16_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int32_t_int16_t_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int32_t_int16_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int32_t_int32_t(void) {
  sfh_int32_t_int32_t_heap_t heap;
  sfh_int32_t_int32_t_node_t node;
  sfh_int32_t_int32_t_node_t *out_node;
  sfh_int32_t_int32_t_heap_t *out_heap;
  int is_empty;
  sfh_int32_t_int32_t_error_t rc;
  int i;

  rc = sfh_int32_t_int32_t_init(NULL);
  ASSERT_EQ(sfh_int32_t_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_int32_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int32_t_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_int32_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int32_t_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_int32_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int32_t_int32_t_ERR_NULL_ARG, rc);

  sfh_int32_t_int32_t_init(&heap);

  {
    sfh_int32_t_int32_t_node_t n1, n2, n3;
    rc = sfh_int32_t_int32_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int32_t_int32_t_SUCCESS, rc);
    rc = sfh_int32_t_int32_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int32_t_int32_t_SUCCESS, rc);
    rc = sfh_int32_t_int32_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int32_t_int32_t_SUCCESS, rc);
    rc = sfh_int32_t_int32_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int32_t_int32_t_SUCCESS, rc);
    rc = sfh_int32_t_int32_t_delete_min(&heap);
    ASSERT_EQ(sfh_int32_t_int32_t_SUCCESS, rc);
    rc = sfh_int32_t_int32_t_delete_min(&heap);
    ASSERT_EQ(sfh_int32_t_int32_t_SUCCESS, rc);
  }

  {
    sfh_int32_t_int32_t_node_t nodes[100];
    sfh_int32_t_int32_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int32_t_int32_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int32_t_int32_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int32_t_int32_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int32_t_int32_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int32_t_int32_t_init(&h1);
    sfh_int32_t_int32_t_init(&h2);
    sfh_int32_t_int32_t_init(&h3);
    sfh_int32_t_int32_t_init(&h4);
    sfh_int32_t_int32_t_insert(&h1, &n1, 1, 0);
    sfh_int32_t_int32_t_insert(&h1, &n2, 2, 0);
    sfh_int32_t_int32_t_insert(&h1, &n3, 3, 0);
    sfh_int32_t_int32_t_insert(&h1, &n4, 4, 0);
    sfh_int32_t_int32_t_insert(&h2, &m2, 10, 0);
    sfh_int32_t_int32_t_insert(&h3, &m3, 11, 0);
    sfh_int32_t_int32_t_insert(&h4, &m4, 12, 0);
    sfh_int32_t_int32_t_meld(&h1, &h2, &merged);
    sfh_int32_t_int32_t_meld(merged, &h3, &merged);
    sfh_int32_t_int32_t_meld(merged, &h4, &merged);
    sfh_int32_t_int32_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int32_t_int32_t_node_t large_nodes[1000];
    sfh_int32_t_int32_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int32_t_int32_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int32_t_int32_t_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int32_t_int32_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int32_t_int64_t(void) {
  sfh_int32_t_int64_t_heap_t heap;
  sfh_int32_t_int64_t_node_t node;
  sfh_int32_t_int64_t_node_t *out_node;
  sfh_int32_t_int64_t_heap_t *out_heap;
  int is_empty;
  sfh_int32_t_int64_t_error_t rc;
  int i;

  rc = sfh_int32_t_int64_t_init(NULL);
  ASSERT_EQ(sfh_int32_t_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_int64_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int32_t_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_int64_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int32_t_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_int64_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int32_t_int64_t_ERR_NULL_ARG, rc);

  sfh_int32_t_int64_t_init(&heap);

  {
    sfh_int32_t_int64_t_node_t n1, n2, n3;
    rc = sfh_int32_t_int64_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int32_t_int64_t_SUCCESS, rc);
    rc = sfh_int32_t_int64_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int32_t_int64_t_SUCCESS, rc);
    rc = sfh_int32_t_int64_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int32_t_int64_t_SUCCESS, rc);
    rc = sfh_int32_t_int64_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int32_t_int64_t_SUCCESS, rc);
    rc = sfh_int32_t_int64_t_delete_min(&heap);
    ASSERT_EQ(sfh_int32_t_int64_t_SUCCESS, rc);
    rc = sfh_int32_t_int64_t_delete_min(&heap);
    ASSERT_EQ(sfh_int32_t_int64_t_SUCCESS, rc);
  }

  {
    sfh_int32_t_int64_t_node_t nodes[100];
    sfh_int32_t_int64_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int32_t_int64_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int32_t_int64_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int32_t_int64_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int32_t_int64_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int32_t_int64_t_init(&h1);
    sfh_int32_t_int64_t_init(&h2);
    sfh_int32_t_int64_t_init(&h3);
    sfh_int32_t_int64_t_init(&h4);
    sfh_int32_t_int64_t_insert(&h1, &n1, 1, 0);
    sfh_int32_t_int64_t_insert(&h1, &n2, 2, 0);
    sfh_int32_t_int64_t_insert(&h1, &n3, 3, 0);
    sfh_int32_t_int64_t_insert(&h1, &n4, 4, 0);
    sfh_int32_t_int64_t_insert(&h2, &m2, 10, 0);
    sfh_int32_t_int64_t_insert(&h3, &m3, 11, 0);
    sfh_int32_t_int64_t_insert(&h4, &m4, 12, 0);
    sfh_int32_t_int64_t_meld(&h1, &h2, &merged);
    sfh_int32_t_int64_t_meld(merged, &h3, &merged);
    sfh_int32_t_int64_t_meld(merged, &h4, &merged);
    sfh_int32_t_int64_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int32_t_int64_t_node_t large_nodes[1000];
    sfh_int32_t_int64_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int32_t_int64_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int32_t_int64_t_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int32_t_int64_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int32_t_uint8_t(void) {
  sfh_int32_t_uint8_t_heap_t heap;
  sfh_int32_t_uint8_t_node_t node;
  sfh_int32_t_uint8_t_node_t *out_node;
  sfh_int32_t_uint8_t_heap_t *out_heap;
  int is_empty;
  sfh_int32_t_uint8_t_error_t rc;
  int i;

  rc = sfh_int32_t_uint8_t_init(NULL);
  ASSERT_EQ(sfh_int32_t_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_uint8_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int32_t_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_uint8_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int32_t_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_uint8_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int32_t_uint8_t_ERR_NULL_ARG, rc);

  sfh_int32_t_uint8_t_init(&heap);

  {
    sfh_int32_t_uint8_t_node_t n1, n2, n3;
    rc = sfh_int32_t_uint8_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int32_t_uint8_t_SUCCESS, rc);
    rc = sfh_int32_t_uint8_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int32_t_uint8_t_SUCCESS, rc);
    rc = sfh_int32_t_uint8_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int32_t_uint8_t_SUCCESS, rc);
    rc = sfh_int32_t_uint8_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int32_t_uint8_t_SUCCESS, rc);
    rc = sfh_int32_t_uint8_t_delete_min(&heap);
    ASSERT_EQ(sfh_int32_t_uint8_t_SUCCESS, rc);
    rc = sfh_int32_t_uint8_t_delete_min(&heap);
    ASSERT_EQ(sfh_int32_t_uint8_t_SUCCESS, rc);
  }

  {
    sfh_int32_t_uint8_t_node_t nodes[100];
    sfh_int32_t_uint8_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int32_t_uint8_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int32_t_uint8_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int32_t_uint8_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int32_t_uint8_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int32_t_uint8_t_init(&h1);
    sfh_int32_t_uint8_t_init(&h2);
    sfh_int32_t_uint8_t_init(&h3);
    sfh_int32_t_uint8_t_init(&h4);
    sfh_int32_t_uint8_t_insert(&h1, &n1, 1, 0);
    sfh_int32_t_uint8_t_insert(&h1, &n2, 2, 0);
    sfh_int32_t_uint8_t_insert(&h1, &n3, 3, 0);
    sfh_int32_t_uint8_t_insert(&h1, &n4, 4, 0);
    sfh_int32_t_uint8_t_insert(&h2, &m2, 10, 0);
    sfh_int32_t_uint8_t_insert(&h3, &m3, 11, 0);
    sfh_int32_t_uint8_t_insert(&h4, &m4, 12, 0);
    sfh_int32_t_uint8_t_meld(&h1, &h2, &merged);
    sfh_int32_t_uint8_t_meld(merged, &h3, &merged);
    sfh_int32_t_uint8_t_meld(merged, &h4, &merged);
    sfh_int32_t_uint8_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int32_t_uint8_t_node_t large_nodes[1000];
    sfh_int32_t_uint8_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int32_t_uint8_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int32_t_uint8_t_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int32_t_uint8_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int32_t_uint16_t(void) {
  sfh_int32_t_uint16_t_heap_t heap;
  sfh_int32_t_uint16_t_node_t node;
  sfh_int32_t_uint16_t_node_t *out_node;
  sfh_int32_t_uint16_t_heap_t *out_heap;
  int is_empty;
  sfh_int32_t_uint16_t_error_t rc;
  int i;

  rc = sfh_int32_t_uint16_t_init(NULL);
  ASSERT_EQ(sfh_int32_t_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_uint16_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int32_t_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_uint16_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int32_t_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_uint16_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int32_t_uint16_t_ERR_NULL_ARG, rc);

  sfh_int32_t_uint16_t_init(&heap);

  {
    sfh_int32_t_uint16_t_node_t n1, n2, n3;
    rc = sfh_int32_t_uint16_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int32_t_uint16_t_SUCCESS, rc);
    rc = sfh_int32_t_uint16_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int32_t_uint16_t_SUCCESS, rc);
    rc = sfh_int32_t_uint16_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int32_t_uint16_t_SUCCESS, rc);
    rc = sfh_int32_t_uint16_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int32_t_uint16_t_SUCCESS, rc);
    rc = sfh_int32_t_uint16_t_delete_min(&heap);
    ASSERT_EQ(sfh_int32_t_uint16_t_SUCCESS, rc);
    rc = sfh_int32_t_uint16_t_delete_min(&heap);
    ASSERT_EQ(sfh_int32_t_uint16_t_SUCCESS, rc);
  }

  {
    sfh_int32_t_uint16_t_node_t nodes[100];
    sfh_int32_t_uint16_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int32_t_uint16_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int32_t_uint16_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int32_t_uint16_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int32_t_uint16_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int32_t_uint16_t_init(&h1);
    sfh_int32_t_uint16_t_init(&h2);
    sfh_int32_t_uint16_t_init(&h3);
    sfh_int32_t_uint16_t_init(&h4);
    sfh_int32_t_uint16_t_insert(&h1, &n1, 1, 0);
    sfh_int32_t_uint16_t_insert(&h1, &n2, 2, 0);
    sfh_int32_t_uint16_t_insert(&h1, &n3, 3, 0);
    sfh_int32_t_uint16_t_insert(&h1, &n4, 4, 0);
    sfh_int32_t_uint16_t_insert(&h2, &m2, 10, 0);
    sfh_int32_t_uint16_t_insert(&h3, &m3, 11, 0);
    sfh_int32_t_uint16_t_insert(&h4, &m4, 12, 0);
    sfh_int32_t_uint16_t_meld(&h1, &h2, &merged);
    sfh_int32_t_uint16_t_meld(merged, &h3, &merged);
    sfh_int32_t_uint16_t_meld(merged, &h4, &merged);
    sfh_int32_t_uint16_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int32_t_uint16_t_node_t large_nodes[1000];
    sfh_int32_t_uint16_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int32_t_uint16_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int32_t_uint16_t_decrease_key(&heap, &large_nodes[i],
                                        large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int32_t_uint16_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int32_t_uint32_t(void) {
  sfh_int32_t_uint32_t_heap_t heap;
  sfh_int32_t_uint32_t_node_t node;
  sfh_int32_t_uint32_t_node_t *out_node;
  sfh_int32_t_uint32_t_heap_t *out_heap;
  int is_empty;
  sfh_int32_t_uint32_t_error_t rc;
  int i;

  rc = sfh_int32_t_uint32_t_init(NULL);
  ASSERT_EQ(sfh_int32_t_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_uint32_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int32_t_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_uint32_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int32_t_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_uint32_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int32_t_uint32_t_ERR_NULL_ARG, rc);

  sfh_int32_t_uint32_t_init(&heap);

  {
    sfh_int32_t_uint32_t_node_t n1, n2, n3;
    rc = sfh_int32_t_uint32_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int32_t_uint32_t_SUCCESS, rc);
    rc = sfh_int32_t_uint32_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int32_t_uint32_t_SUCCESS, rc);
    rc = sfh_int32_t_uint32_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int32_t_uint32_t_SUCCESS, rc);
    rc = sfh_int32_t_uint32_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int32_t_uint32_t_SUCCESS, rc);
    rc = sfh_int32_t_uint32_t_delete_min(&heap);
    ASSERT_EQ(sfh_int32_t_uint32_t_SUCCESS, rc);
    rc = sfh_int32_t_uint32_t_delete_min(&heap);
    ASSERT_EQ(sfh_int32_t_uint32_t_SUCCESS, rc);
  }

  {
    sfh_int32_t_uint32_t_node_t nodes[100];
    sfh_int32_t_uint32_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int32_t_uint32_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int32_t_uint32_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int32_t_uint32_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int32_t_uint32_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int32_t_uint32_t_init(&h1);
    sfh_int32_t_uint32_t_init(&h2);
    sfh_int32_t_uint32_t_init(&h3);
    sfh_int32_t_uint32_t_init(&h4);
    sfh_int32_t_uint32_t_insert(&h1, &n1, 1, 0);
    sfh_int32_t_uint32_t_insert(&h1, &n2, 2, 0);
    sfh_int32_t_uint32_t_insert(&h1, &n3, 3, 0);
    sfh_int32_t_uint32_t_insert(&h1, &n4, 4, 0);
    sfh_int32_t_uint32_t_insert(&h2, &m2, 10, 0);
    sfh_int32_t_uint32_t_insert(&h3, &m3, 11, 0);
    sfh_int32_t_uint32_t_insert(&h4, &m4, 12, 0);
    sfh_int32_t_uint32_t_meld(&h1, &h2, &merged);
    sfh_int32_t_uint32_t_meld(merged, &h3, &merged);
    sfh_int32_t_uint32_t_meld(merged, &h4, &merged);
    sfh_int32_t_uint32_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int32_t_uint32_t_node_t large_nodes[1000];
    sfh_int32_t_uint32_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int32_t_uint32_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int32_t_uint32_t_decrease_key(&heap, &large_nodes[i],
                                        large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int32_t_uint32_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int32_t_uint64_t(void) {
  sfh_int32_t_uint64_t_heap_t heap;
  sfh_int32_t_uint64_t_node_t node;
  sfh_int32_t_uint64_t_node_t *out_node;
  sfh_int32_t_uint64_t_heap_t *out_heap;
  int is_empty;
  sfh_int32_t_uint64_t_error_t rc;
  int i;

  rc = sfh_int32_t_uint64_t_init(NULL);
  ASSERT_EQ(sfh_int32_t_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_uint64_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int32_t_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_uint64_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int32_t_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_uint64_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int32_t_uint64_t_ERR_NULL_ARG, rc);

  sfh_int32_t_uint64_t_init(&heap);

  {
    sfh_int32_t_uint64_t_node_t n1, n2, n3;
    rc = sfh_int32_t_uint64_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int32_t_uint64_t_SUCCESS, rc);
    rc = sfh_int32_t_uint64_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int32_t_uint64_t_SUCCESS, rc);
    rc = sfh_int32_t_uint64_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int32_t_uint64_t_SUCCESS, rc);
    rc = sfh_int32_t_uint64_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int32_t_uint64_t_SUCCESS, rc);
    rc = sfh_int32_t_uint64_t_delete_min(&heap);
    ASSERT_EQ(sfh_int32_t_uint64_t_SUCCESS, rc);
    rc = sfh_int32_t_uint64_t_delete_min(&heap);
    ASSERT_EQ(sfh_int32_t_uint64_t_SUCCESS, rc);
  }

  {
    sfh_int32_t_uint64_t_node_t nodes[100];
    sfh_int32_t_uint64_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int32_t_uint64_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int32_t_uint64_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int32_t_uint64_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int32_t_uint64_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int32_t_uint64_t_init(&h1);
    sfh_int32_t_uint64_t_init(&h2);
    sfh_int32_t_uint64_t_init(&h3);
    sfh_int32_t_uint64_t_init(&h4);
    sfh_int32_t_uint64_t_insert(&h1, &n1, 1, 0);
    sfh_int32_t_uint64_t_insert(&h1, &n2, 2, 0);
    sfh_int32_t_uint64_t_insert(&h1, &n3, 3, 0);
    sfh_int32_t_uint64_t_insert(&h1, &n4, 4, 0);
    sfh_int32_t_uint64_t_insert(&h2, &m2, 10, 0);
    sfh_int32_t_uint64_t_insert(&h3, &m3, 11, 0);
    sfh_int32_t_uint64_t_insert(&h4, &m4, 12, 0);
    sfh_int32_t_uint64_t_meld(&h1, &h2, &merged);
    sfh_int32_t_uint64_t_meld(merged, &h3, &merged);
    sfh_int32_t_uint64_t_meld(merged, &h4, &merged);
    sfh_int32_t_uint64_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int32_t_uint64_t_node_t large_nodes[1000];
    sfh_int32_t_uint64_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int32_t_uint64_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int32_t_uint64_t_decrease_key(&heap, &large_nodes[i],
                                        large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int32_t_uint64_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int32_t_float(void) {
  sfh_int32_t_float_heap_t heap;
  sfh_int32_t_float_node_t node;
  sfh_int32_t_float_node_t *out_node;
  sfh_int32_t_float_heap_t *out_heap;
  int is_empty;
  sfh_int32_t_float_error_t rc;
  int i;

  rc = sfh_int32_t_float_init(NULL);
  ASSERT_EQ(sfh_int32_t_float_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_float_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int32_t_float_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_float_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int32_t_float_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_float_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int32_t_float_ERR_NULL_ARG, rc);

  sfh_int32_t_float_init(&heap);

  {
    sfh_int32_t_float_node_t n1, n2, n3;
    rc = sfh_int32_t_float_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int32_t_float_SUCCESS, rc);
    rc = sfh_int32_t_float_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int32_t_float_SUCCESS, rc);
    rc = sfh_int32_t_float_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int32_t_float_SUCCESS, rc);
    rc = sfh_int32_t_float_delete(&heap, &n2);
    ASSERT_EQ(sfh_int32_t_float_SUCCESS, rc);
    rc = sfh_int32_t_float_delete_min(&heap);
    ASSERT_EQ(sfh_int32_t_float_SUCCESS, rc);
    rc = sfh_int32_t_float_delete_min(&heap);
    ASSERT_EQ(sfh_int32_t_float_SUCCESS, rc);
  }

  {
    sfh_int32_t_float_node_t nodes[100];
    sfh_int32_t_float_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int32_t_float_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int32_t_float_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int32_t_float_heap_t h1, h2, h3, h4, *merged;
    sfh_int32_t_float_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int32_t_float_init(&h1);
    sfh_int32_t_float_init(&h2);
    sfh_int32_t_float_init(&h3);
    sfh_int32_t_float_init(&h4);
    sfh_int32_t_float_insert(&h1, &n1, 1, 0);
    sfh_int32_t_float_insert(&h1, &n2, 2, 0);
    sfh_int32_t_float_insert(&h1, &n3, 3, 0);
    sfh_int32_t_float_insert(&h1, &n4, 4, 0);
    sfh_int32_t_float_insert(&h2, &m2, 10, 0);
    sfh_int32_t_float_insert(&h3, &m3, 11, 0);
    sfh_int32_t_float_insert(&h4, &m4, 12, 0);
    sfh_int32_t_float_meld(&h1, &h2, &merged);
    sfh_int32_t_float_meld(merged, &h3, &merged);
    sfh_int32_t_float_meld(merged, &h4, &merged);
    sfh_int32_t_float_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int32_t_float_node_t large_nodes[1000];
    sfh_int32_t_float_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int32_t_float_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int32_t_float_decrease_key(&heap, &large_nodes[i],
                                     large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int32_t_float_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int32_t_double(void) {
  sfh_int32_t_double_heap_t heap;
  sfh_int32_t_double_node_t node;
  sfh_int32_t_double_node_t *out_node;
  sfh_int32_t_double_heap_t *out_heap;
  int is_empty;
  sfh_int32_t_double_error_t rc;
  int i;

  rc = sfh_int32_t_double_init(NULL);
  ASSERT_EQ(sfh_int32_t_double_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_double_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int32_t_double_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_double_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int32_t_double_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_double_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int32_t_double_ERR_NULL_ARG, rc);

  sfh_int32_t_double_init(&heap);

  {
    sfh_int32_t_double_node_t n1, n2, n3;
    rc = sfh_int32_t_double_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int32_t_double_SUCCESS, rc);
    rc = sfh_int32_t_double_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int32_t_double_SUCCESS, rc);
    rc = sfh_int32_t_double_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int32_t_double_SUCCESS, rc);
    rc = sfh_int32_t_double_delete(&heap, &n2);
    ASSERT_EQ(sfh_int32_t_double_SUCCESS, rc);
    rc = sfh_int32_t_double_delete_min(&heap);
    ASSERT_EQ(sfh_int32_t_double_SUCCESS, rc);
    rc = sfh_int32_t_double_delete_min(&heap);
    ASSERT_EQ(sfh_int32_t_double_SUCCESS, rc);
  }

  {
    sfh_int32_t_double_node_t nodes[100];
    sfh_int32_t_double_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int32_t_double_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int32_t_double_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int32_t_double_heap_t h1, h2, h3, h4, *merged;
    sfh_int32_t_double_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int32_t_double_init(&h1);
    sfh_int32_t_double_init(&h2);
    sfh_int32_t_double_init(&h3);
    sfh_int32_t_double_init(&h4);
    sfh_int32_t_double_insert(&h1, &n1, 1, 0);
    sfh_int32_t_double_insert(&h1, &n2, 2, 0);
    sfh_int32_t_double_insert(&h1, &n3, 3, 0);
    sfh_int32_t_double_insert(&h1, &n4, 4, 0);
    sfh_int32_t_double_insert(&h2, &m2, 10, 0);
    sfh_int32_t_double_insert(&h3, &m3, 11, 0);
    sfh_int32_t_double_insert(&h4, &m4, 12, 0);
    sfh_int32_t_double_meld(&h1, &h2, &merged);
    sfh_int32_t_double_meld(merged, &h3, &merged);
    sfh_int32_t_double_meld(merged, &h4, &merged);
    sfh_int32_t_double_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int32_t_double_node_t large_nodes[1000];
    sfh_int32_t_double_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int32_t_double_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int32_t_double_decrease_key(&heap, &large_nodes[i],
                                      large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int32_t_double_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int32_t_charptr(void) {
  sfh_int32_t_charptr_heap_t heap;
  sfh_int32_t_charptr_node_t node;
  sfh_int32_t_charptr_node_t *out_node;
  sfh_int32_t_charptr_heap_t *out_heap;
  int is_empty;
  sfh_int32_t_charptr_error_t rc;
  int i;

  rc = sfh_int32_t_charptr_init(NULL);
  ASSERT_EQ(sfh_int32_t_charptr_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_charptr_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int32_t_charptr_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_charptr_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int32_t_charptr_ERR_NULL_ARG, rc);
  rc = sfh_int32_t_charptr_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int32_t_charptr_ERR_NULL_ARG, rc);

  sfh_int32_t_charptr_init(&heap);

  {
    sfh_int32_t_charptr_node_t n1, n2, n3;
    rc = sfh_int32_t_charptr_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int32_t_charptr_SUCCESS, rc);
    rc = sfh_int32_t_charptr_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int32_t_charptr_SUCCESS, rc);
    rc = sfh_int32_t_charptr_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int32_t_charptr_SUCCESS, rc);
    rc = sfh_int32_t_charptr_delete(&heap, &n2);
    ASSERT_EQ(sfh_int32_t_charptr_SUCCESS, rc);
    rc = sfh_int32_t_charptr_delete_min(&heap);
    ASSERT_EQ(sfh_int32_t_charptr_SUCCESS, rc);
    rc = sfh_int32_t_charptr_delete_min(&heap);
    ASSERT_EQ(sfh_int32_t_charptr_SUCCESS, rc);
  }

  {
    sfh_int32_t_charptr_node_t nodes[100];
    sfh_int32_t_charptr_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int32_t_charptr_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int32_t_charptr_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int32_t_charptr_heap_t h1, h2, h3, h4, *merged;
    sfh_int32_t_charptr_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int32_t_charptr_init(&h1);
    sfh_int32_t_charptr_init(&h2);
    sfh_int32_t_charptr_init(&h3);
    sfh_int32_t_charptr_init(&h4);
    sfh_int32_t_charptr_insert(&h1, &n1, 1, 0);
    sfh_int32_t_charptr_insert(&h1, &n2, 2, 0);
    sfh_int32_t_charptr_insert(&h1, &n3, 3, 0);
    sfh_int32_t_charptr_insert(&h1, &n4, 4, 0);
    sfh_int32_t_charptr_insert(&h2, &m2, 10, 0);
    sfh_int32_t_charptr_insert(&h3, &m3, 11, 0);
    sfh_int32_t_charptr_insert(&h4, &m4, 12, 0);
    sfh_int32_t_charptr_meld(&h1, &h2, &merged);
    sfh_int32_t_charptr_meld(merged, &h3, &merged);
    sfh_int32_t_charptr_meld(merged, &h4, &merged);
    sfh_int32_t_charptr_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int32_t_charptr_node_t large_nodes[1000];
    sfh_int32_t_charptr_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int32_t_charptr_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int32_t_charptr_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int32_t_charptr_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int64_t_int8_t(void) {
  sfh_int64_t_int8_t_heap_t heap;
  sfh_int64_t_int8_t_node_t node;
  sfh_int64_t_int8_t_node_t *out_node;
  sfh_int64_t_int8_t_heap_t *out_heap;
  int is_empty;
  sfh_int64_t_int8_t_error_t rc;
  int i;

  rc = sfh_int64_t_int8_t_init(NULL);
  ASSERT_EQ(sfh_int64_t_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_int8_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int64_t_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_int8_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int64_t_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_int8_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int64_t_int8_t_ERR_NULL_ARG, rc);

  sfh_int64_t_int8_t_init(&heap);

  {
    sfh_int64_t_int8_t_node_t n1, n2, n3;
    rc = sfh_int64_t_int8_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int64_t_int8_t_SUCCESS, rc);
    rc = sfh_int64_t_int8_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int64_t_int8_t_SUCCESS, rc);
    rc = sfh_int64_t_int8_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int64_t_int8_t_SUCCESS, rc);
    rc = sfh_int64_t_int8_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int64_t_int8_t_SUCCESS, rc);
    rc = sfh_int64_t_int8_t_delete_min(&heap);
    ASSERT_EQ(sfh_int64_t_int8_t_SUCCESS, rc);
    rc = sfh_int64_t_int8_t_delete_min(&heap);
    ASSERT_EQ(sfh_int64_t_int8_t_SUCCESS, rc);
  }

  {
    sfh_int64_t_int8_t_node_t nodes[100];
    sfh_int64_t_int8_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int64_t_int8_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int64_t_int8_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int64_t_int8_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int64_t_int8_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int64_t_int8_t_init(&h1);
    sfh_int64_t_int8_t_init(&h2);
    sfh_int64_t_int8_t_init(&h3);
    sfh_int64_t_int8_t_init(&h4);
    sfh_int64_t_int8_t_insert(&h1, &n1, 1, 0);
    sfh_int64_t_int8_t_insert(&h1, &n2, 2, 0);
    sfh_int64_t_int8_t_insert(&h1, &n3, 3, 0);
    sfh_int64_t_int8_t_insert(&h1, &n4, 4, 0);
    sfh_int64_t_int8_t_insert(&h2, &m2, 10, 0);
    sfh_int64_t_int8_t_insert(&h3, &m3, 11, 0);
    sfh_int64_t_int8_t_insert(&h4, &m4, 12, 0);
    sfh_int64_t_int8_t_meld(&h1, &h2, &merged);
    sfh_int64_t_int8_t_meld(merged, &h3, &merged);
    sfh_int64_t_int8_t_meld(merged, &h4, &merged);
    sfh_int64_t_int8_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int64_t_int8_t_node_t large_nodes[1000];
    sfh_int64_t_int8_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int64_t_int8_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int64_t_int8_t_decrease_key(&heap, &large_nodes[i],
                                      large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int64_t_int8_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int64_t_int16_t(void) {
  sfh_int64_t_int16_t_heap_t heap;
  sfh_int64_t_int16_t_node_t node;
  sfh_int64_t_int16_t_node_t *out_node;
  sfh_int64_t_int16_t_heap_t *out_heap;
  int is_empty;
  sfh_int64_t_int16_t_error_t rc;
  int i;

  rc = sfh_int64_t_int16_t_init(NULL);
  ASSERT_EQ(sfh_int64_t_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_int16_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int64_t_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_int16_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int64_t_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_int16_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int64_t_int16_t_ERR_NULL_ARG, rc);

  sfh_int64_t_int16_t_init(&heap);

  {
    sfh_int64_t_int16_t_node_t n1, n2, n3;
    rc = sfh_int64_t_int16_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int64_t_int16_t_SUCCESS, rc);
    rc = sfh_int64_t_int16_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int64_t_int16_t_SUCCESS, rc);
    rc = sfh_int64_t_int16_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int64_t_int16_t_SUCCESS, rc);
    rc = sfh_int64_t_int16_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int64_t_int16_t_SUCCESS, rc);
    rc = sfh_int64_t_int16_t_delete_min(&heap);
    ASSERT_EQ(sfh_int64_t_int16_t_SUCCESS, rc);
    rc = sfh_int64_t_int16_t_delete_min(&heap);
    ASSERT_EQ(sfh_int64_t_int16_t_SUCCESS, rc);
  }

  {
    sfh_int64_t_int16_t_node_t nodes[100];
    sfh_int64_t_int16_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int64_t_int16_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int64_t_int16_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int64_t_int16_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int64_t_int16_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int64_t_int16_t_init(&h1);
    sfh_int64_t_int16_t_init(&h2);
    sfh_int64_t_int16_t_init(&h3);
    sfh_int64_t_int16_t_init(&h4);
    sfh_int64_t_int16_t_insert(&h1, &n1, 1, 0);
    sfh_int64_t_int16_t_insert(&h1, &n2, 2, 0);
    sfh_int64_t_int16_t_insert(&h1, &n3, 3, 0);
    sfh_int64_t_int16_t_insert(&h1, &n4, 4, 0);
    sfh_int64_t_int16_t_insert(&h2, &m2, 10, 0);
    sfh_int64_t_int16_t_insert(&h3, &m3, 11, 0);
    sfh_int64_t_int16_t_insert(&h4, &m4, 12, 0);
    sfh_int64_t_int16_t_meld(&h1, &h2, &merged);
    sfh_int64_t_int16_t_meld(merged, &h3, &merged);
    sfh_int64_t_int16_t_meld(merged, &h4, &merged);
    sfh_int64_t_int16_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int64_t_int16_t_node_t large_nodes[1000];
    sfh_int64_t_int16_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int64_t_int16_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int64_t_int16_t_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int64_t_int16_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int64_t_int32_t(void) {
  sfh_int64_t_int32_t_heap_t heap;
  sfh_int64_t_int32_t_node_t node;
  sfh_int64_t_int32_t_node_t *out_node;
  sfh_int64_t_int32_t_heap_t *out_heap;
  int is_empty;
  sfh_int64_t_int32_t_error_t rc;
  int i;

  rc = sfh_int64_t_int32_t_init(NULL);
  ASSERT_EQ(sfh_int64_t_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_int32_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int64_t_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_int32_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int64_t_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_int32_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int64_t_int32_t_ERR_NULL_ARG, rc);

  sfh_int64_t_int32_t_init(&heap);

  {
    sfh_int64_t_int32_t_node_t n1, n2, n3;
    rc = sfh_int64_t_int32_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int64_t_int32_t_SUCCESS, rc);
    rc = sfh_int64_t_int32_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int64_t_int32_t_SUCCESS, rc);
    rc = sfh_int64_t_int32_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int64_t_int32_t_SUCCESS, rc);
    rc = sfh_int64_t_int32_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int64_t_int32_t_SUCCESS, rc);
    rc = sfh_int64_t_int32_t_delete_min(&heap);
    ASSERT_EQ(sfh_int64_t_int32_t_SUCCESS, rc);
    rc = sfh_int64_t_int32_t_delete_min(&heap);
    ASSERT_EQ(sfh_int64_t_int32_t_SUCCESS, rc);
  }

  {
    sfh_int64_t_int32_t_node_t nodes[100];
    sfh_int64_t_int32_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int64_t_int32_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int64_t_int32_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int64_t_int32_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int64_t_int32_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int64_t_int32_t_init(&h1);
    sfh_int64_t_int32_t_init(&h2);
    sfh_int64_t_int32_t_init(&h3);
    sfh_int64_t_int32_t_init(&h4);
    sfh_int64_t_int32_t_insert(&h1, &n1, 1, 0);
    sfh_int64_t_int32_t_insert(&h1, &n2, 2, 0);
    sfh_int64_t_int32_t_insert(&h1, &n3, 3, 0);
    sfh_int64_t_int32_t_insert(&h1, &n4, 4, 0);
    sfh_int64_t_int32_t_insert(&h2, &m2, 10, 0);
    sfh_int64_t_int32_t_insert(&h3, &m3, 11, 0);
    sfh_int64_t_int32_t_insert(&h4, &m4, 12, 0);
    sfh_int64_t_int32_t_meld(&h1, &h2, &merged);
    sfh_int64_t_int32_t_meld(merged, &h3, &merged);
    sfh_int64_t_int32_t_meld(merged, &h4, &merged);
    sfh_int64_t_int32_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int64_t_int32_t_node_t large_nodes[1000];
    sfh_int64_t_int32_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int64_t_int32_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int64_t_int32_t_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int64_t_int32_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int64_t_int64_t(void) {
  sfh_int64_t_int64_t_heap_t heap;
  sfh_int64_t_int64_t_node_t node;
  sfh_int64_t_int64_t_node_t *out_node;
  sfh_int64_t_int64_t_heap_t *out_heap;
  int is_empty;
  sfh_int64_t_int64_t_error_t rc;
  int i;

  rc = sfh_int64_t_int64_t_init(NULL);
  ASSERT_EQ(sfh_int64_t_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_int64_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int64_t_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_int64_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int64_t_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_int64_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int64_t_int64_t_ERR_NULL_ARG, rc);

  sfh_int64_t_int64_t_init(&heap);

  {
    sfh_int64_t_int64_t_node_t n1, n2, n3;
    rc = sfh_int64_t_int64_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int64_t_int64_t_SUCCESS, rc);
    rc = sfh_int64_t_int64_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int64_t_int64_t_SUCCESS, rc);
    rc = sfh_int64_t_int64_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int64_t_int64_t_SUCCESS, rc);
    rc = sfh_int64_t_int64_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int64_t_int64_t_SUCCESS, rc);
    rc = sfh_int64_t_int64_t_delete_min(&heap);
    ASSERT_EQ(sfh_int64_t_int64_t_SUCCESS, rc);
    rc = sfh_int64_t_int64_t_delete_min(&heap);
    ASSERT_EQ(sfh_int64_t_int64_t_SUCCESS, rc);
  }

  {
    sfh_int64_t_int64_t_node_t nodes[100];
    sfh_int64_t_int64_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int64_t_int64_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int64_t_int64_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int64_t_int64_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int64_t_int64_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int64_t_int64_t_init(&h1);
    sfh_int64_t_int64_t_init(&h2);
    sfh_int64_t_int64_t_init(&h3);
    sfh_int64_t_int64_t_init(&h4);
    sfh_int64_t_int64_t_insert(&h1, &n1, 1, 0);
    sfh_int64_t_int64_t_insert(&h1, &n2, 2, 0);
    sfh_int64_t_int64_t_insert(&h1, &n3, 3, 0);
    sfh_int64_t_int64_t_insert(&h1, &n4, 4, 0);
    sfh_int64_t_int64_t_insert(&h2, &m2, 10, 0);
    sfh_int64_t_int64_t_insert(&h3, &m3, 11, 0);
    sfh_int64_t_int64_t_insert(&h4, &m4, 12, 0);
    sfh_int64_t_int64_t_meld(&h1, &h2, &merged);
    sfh_int64_t_int64_t_meld(merged, &h3, &merged);
    sfh_int64_t_int64_t_meld(merged, &h4, &merged);
    sfh_int64_t_int64_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int64_t_int64_t_node_t large_nodes[1000];
    sfh_int64_t_int64_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int64_t_int64_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int64_t_int64_t_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int64_t_int64_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int64_t_uint8_t(void) {
  sfh_int64_t_uint8_t_heap_t heap;
  sfh_int64_t_uint8_t_node_t node;
  sfh_int64_t_uint8_t_node_t *out_node;
  sfh_int64_t_uint8_t_heap_t *out_heap;
  int is_empty;
  sfh_int64_t_uint8_t_error_t rc;
  int i;

  rc = sfh_int64_t_uint8_t_init(NULL);
  ASSERT_EQ(sfh_int64_t_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_uint8_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int64_t_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_uint8_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int64_t_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_uint8_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int64_t_uint8_t_ERR_NULL_ARG, rc);

  sfh_int64_t_uint8_t_init(&heap);

  {
    sfh_int64_t_uint8_t_node_t n1, n2, n3;
    rc = sfh_int64_t_uint8_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int64_t_uint8_t_SUCCESS, rc);
    rc = sfh_int64_t_uint8_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int64_t_uint8_t_SUCCESS, rc);
    rc = sfh_int64_t_uint8_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int64_t_uint8_t_SUCCESS, rc);
    rc = sfh_int64_t_uint8_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int64_t_uint8_t_SUCCESS, rc);
    rc = sfh_int64_t_uint8_t_delete_min(&heap);
    ASSERT_EQ(sfh_int64_t_uint8_t_SUCCESS, rc);
    rc = sfh_int64_t_uint8_t_delete_min(&heap);
    ASSERT_EQ(sfh_int64_t_uint8_t_SUCCESS, rc);
  }

  {
    sfh_int64_t_uint8_t_node_t nodes[100];
    sfh_int64_t_uint8_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int64_t_uint8_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int64_t_uint8_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int64_t_uint8_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int64_t_uint8_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int64_t_uint8_t_init(&h1);
    sfh_int64_t_uint8_t_init(&h2);
    sfh_int64_t_uint8_t_init(&h3);
    sfh_int64_t_uint8_t_init(&h4);
    sfh_int64_t_uint8_t_insert(&h1, &n1, 1, 0);
    sfh_int64_t_uint8_t_insert(&h1, &n2, 2, 0);
    sfh_int64_t_uint8_t_insert(&h1, &n3, 3, 0);
    sfh_int64_t_uint8_t_insert(&h1, &n4, 4, 0);
    sfh_int64_t_uint8_t_insert(&h2, &m2, 10, 0);
    sfh_int64_t_uint8_t_insert(&h3, &m3, 11, 0);
    sfh_int64_t_uint8_t_insert(&h4, &m4, 12, 0);
    sfh_int64_t_uint8_t_meld(&h1, &h2, &merged);
    sfh_int64_t_uint8_t_meld(merged, &h3, &merged);
    sfh_int64_t_uint8_t_meld(merged, &h4, &merged);
    sfh_int64_t_uint8_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int64_t_uint8_t_node_t large_nodes[1000];
    sfh_int64_t_uint8_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int64_t_uint8_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int64_t_uint8_t_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int64_t_uint8_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int64_t_uint16_t(void) {
  sfh_int64_t_uint16_t_heap_t heap;
  sfh_int64_t_uint16_t_node_t node;
  sfh_int64_t_uint16_t_node_t *out_node;
  sfh_int64_t_uint16_t_heap_t *out_heap;
  int is_empty;
  sfh_int64_t_uint16_t_error_t rc;
  int i;

  rc = sfh_int64_t_uint16_t_init(NULL);
  ASSERT_EQ(sfh_int64_t_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_uint16_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int64_t_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_uint16_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int64_t_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_uint16_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int64_t_uint16_t_ERR_NULL_ARG, rc);

  sfh_int64_t_uint16_t_init(&heap);

  {
    sfh_int64_t_uint16_t_node_t n1, n2, n3;
    rc = sfh_int64_t_uint16_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int64_t_uint16_t_SUCCESS, rc);
    rc = sfh_int64_t_uint16_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int64_t_uint16_t_SUCCESS, rc);
    rc = sfh_int64_t_uint16_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int64_t_uint16_t_SUCCESS, rc);
    rc = sfh_int64_t_uint16_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int64_t_uint16_t_SUCCESS, rc);
    rc = sfh_int64_t_uint16_t_delete_min(&heap);
    ASSERT_EQ(sfh_int64_t_uint16_t_SUCCESS, rc);
    rc = sfh_int64_t_uint16_t_delete_min(&heap);
    ASSERT_EQ(sfh_int64_t_uint16_t_SUCCESS, rc);
  }

  {
    sfh_int64_t_uint16_t_node_t nodes[100];
    sfh_int64_t_uint16_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int64_t_uint16_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int64_t_uint16_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int64_t_uint16_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int64_t_uint16_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int64_t_uint16_t_init(&h1);
    sfh_int64_t_uint16_t_init(&h2);
    sfh_int64_t_uint16_t_init(&h3);
    sfh_int64_t_uint16_t_init(&h4);
    sfh_int64_t_uint16_t_insert(&h1, &n1, 1, 0);
    sfh_int64_t_uint16_t_insert(&h1, &n2, 2, 0);
    sfh_int64_t_uint16_t_insert(&h1, &n3, 3, 0);
    sfh_int64_t_uint16_t_insert(&h1, &n4, 4, 0);
    sfh_int64_t_uint16_t_insert(&h2, &m2, 10, 0);
    sfh_int64_t_uint16_t_insert(&h3, &m3, 11, 0);
    sfh_int64_t_uint16_t_insert(&h4, &m4, 12, 0);
    sfh_int64_t_uint16_t_meld(&h1, &h2, &merged);
    sfh_int64_t_uint16_t_meld(merged, &h3, &merged);
    sfh_int64_t_uint16_t_meld(merged, &h4, &merged);
    sfh_int64_t_uint16_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int64_t_uint16_t_node_t large_nodes[1000];
    sfh_int64_t_uint16_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int64_t_uint16_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int64_t_uint16_t_decrease_key(&heap, &large_nodes[i],
                                        large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int64_t_uint16_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int64_t_uint32_t(void) {
  sfh_int64_t_uint32_t_heap_t heap;
  sfh_int64_t_uint32_t_node_t node;
  sfh_int64_t_uint32_t_node_t *out_node;
  sfh_int64_t_uint32_t_heap_t *out_heap;
  int is_empty;
  sfh_int64_t_uint32_t_error_t rc;
  int i;

  rc = sfh_int64_t_uint32_t_init(NULL);
  ASSERT_EQ(sfh_int64_t_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_uint32_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int64_t_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_uint32_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int64_t_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_uint32_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int64_t_uint32_t_ERR_NULL_ARG, rc);

  sfh_int64_t_uint32_t_init(&heap);

  {
    sfh_int64_t_uint32_t_node_t n1, n2, n3;
    rc = sfh_int64_t_uint32_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int64_t_uint32_t_SUCCESS, rc);
    rc = sfh_int64_t_uint32_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int64_t_uint32_t_SUCCESS, rc);
    rc = sfh_int64_t_uint32_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int64_t_uint32_t_SUCCESS, rc);
    rc = sfh_int64_t_uint32_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int64_t_uint32_t_SUCCESS, rc);
    rc = sfh_int64_t_uint32_t_delete_min(&heap);
    ASSERT_EQ(sfh_int64_t_uint32_t_SUCCESS, rc);
    rc = sfh_int64_t_uint32_t_delete_min(&heap);
    ASSERT_EQ(sfh_int64_t_uint32_t_SUCCESS, rc);
  }

  {
    sfh_int64_t_uint32_t_node_t nodes[100];
    sfh_int64_t_uint32_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int64_t_uint32_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int64_t_uint32_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int64_t_uint32_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int64_t_uint32_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int64_t_uint32_t_init(&h1);
    sfh_int64_t_uint32_t_init(&h2);
    sfh_int64_t_uint32_t_init(&h3);
    sfh_int64_t_uint32_t_init(&h4);
    sfh_int64_t_uint32_t_insert(&h1, &n1, 1, 0);
    sfh_int64_t_uint32_t_insert(&h1, &n2, 2, 0);
    sfh_int64_t_uint32_t_insert(&h1, &n3, 3, 0);
    sfh_int64_t_uint32_t_insert(&h1, &n4, 4, 0);
    sfh_int64_t_uint32_t_insert(&h2, &m2, 10, 0);
    sfh_int64_t_uint32_t_insert(&h3, &m3, 11, 0);
    sfh_int64_t_uint32_t_insert(&h4, &m4, 12, 0);
    sfh_int64_t_uint32_t_meld(&h1, &h2, &merged);
    sfh_int64_t_uint32_t_meld(merged, &h3, &merged);
    sfh_int64_t_uint32_t_meld(merged, &h4, &merged);
    sfh_int64_t_uint32_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int64_t_uint32_t_node_t large_nodes[1000];
    sfh_int64_t_uint32_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int64_t_uint32_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int64_t_uint32_t_decrease_key(&heap, &large_nodes[i],
                                        large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int64_t_uint32_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int64_t_uint64_t(void) {
  sfh_int64_t_uint64_t_heap_t heap;
  sfh_int64_t_uint64_t_node_t node;
  sfh_int64_t_uint64_t_node_t *out_node;
  sfh_int64_t_uint64_t_heap_t *out_heap;
  int is_empty;
  sfh_int64_t_uint64_t_error_t rc;
  int i;

  rc = sfh_int64_t_uint64_t_init(NULL);
  ASSERT_EQ(sfh_int64_t_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_uint64_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int64_t_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_uint64_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int64_t_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_uint64_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int64_t_uint64_t_ERR_NULL_ARG, rc);

  sfh_int64_t_uint64_t_init(&heap);

  {
    sfh_int64_t_uint64_t_node_t n1, n2, n3;
    rc = sfh_int64_t_uint64_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int64_t_uint64_t_SUCCESS, rc);
    rc = sfh_int64_t_uint64_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int64_t_uint64_t_SUCCESS, rc);
    rc = sfh_int64_t_uint64_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int64_t_uint64_t_SUCCESS, rc);
    rc = sfh_int64_t_uint64_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_int64_t_uint64_t_SUCCESS, rc);
    rc = sfh_int64_t_uint64_t_delete_min(&heap);
    ASSERT_EQ(sfh_int64_t_uint64_t_SUCCESS, rc);
    rc = sfh_int64_t_uint64_t_delete_min(&heap);
    ASSERT_EQ(sfh_int64_t_uint64_t_SUCCESS, rc);
  }

  {
    sfh_int64_t_uint64_t_node_t nodes[100];
    sfh_int64_t_uint64_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int64_t_uint64_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int64_t_uint64_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int64_t_uint64_t_heap_t h1, h2, h3, h4, *merged;
    sfh_int64_t_uint64_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int64_t_uint64_t_init(&h1);
    sfh_int64_t_uint64_t_init(&h2);
    sfh_int64_t_uint64_t_init(&h3);
    sfh_int64_t_uint64_t_init(&h4);
    sfh_int64_t_uint64_t_insert(&h1, &n1, 1, 0);
    sfh_int64_t_uint64_t_insert(&h1, &n2, 2, 0);
    sfh_int64_t_uint64_t_insert(&h1, &n3, 3, 0);
    sfh_int64_t_uint64_t_insert(&h1, &n4, 4, 0);
    sfh_int64_t_uint64_t_insert(&h2, &m2, 10, 0);
    sfh_int64_t_uint64_t_insert(&h3, &m3, 11, 0);
    sfh_int64_t_uint64_t_insert(&h4, &m4, 12, 0);
    sfh_int64_t_uint64_t_meld(&h1, &h2, &merged);
    sfh_int64_t_uint64_t_meld(merged, &h3, &merged);
    sfh_int64_t_uint64_t_meld(merged, &h4, &merged);
    sfh_int64_t_uint64_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int64_t_uint64_t_node_t large_nodes[1000];
    sfh_int64_t_uint64_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int64_t_uint64_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int64_t_uint64_t_decrease_key(&heap, &large_nodes[i],
                                        large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int64_t_uint64_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int64_t_float(void) {
  sfh_int64_t_float_heap_t heap;
  sfh_int64_t_float_node_t node;
  sfh_int64_t_float_node_t *out_node;
  sfh_int64_t_float_heap_t *out_heap;
  int is_empty;
  sfh_int64_t_float_error_t rc;
  int i;

  rc = sfh_int64_t_float_init(NULL);
  ASSERT_EQ(sfh_int64_t_float_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_float_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int64_t_float_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_float_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int64_t_float_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_float_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int64_t_float_ERR_NULL_ARG, rc);

  sfh_int64_t_float_init(&heap);

  {
    sfh_int64_t_float_node_t n1, n2, n3;
    rc = sfh_int64_t_float_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int64_t_float_SUCCESS, rc);
    rc = sfh_int64_t_float_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int64_t_float_SUCCESS, rc);
    rc = sfh_int64_t_float_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int64_t_float_SUCCESS, rc);
    rc = sfh_int64_t_float_delete(&heap, &n2);
    ASSERT_EQ(sfh_int64_t_float_SUCCESS, rc);
    rc = sfh_int64_t_float_delete_min(&heap);
    ASSERT_EQ(sfh_int64_t_float_SUCCESS, rc);
    rc = sfh_int64_t_float_delete_min(&heap);
    ASSERT_EQ(sfh_int64_t_float_SUCCESS, rc);
  }

  {
    sfh_int64_t_float_node_t nodes[100];
    sfh_int64_t_float_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int64_t_float_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int64_t_float_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int64_t_float_heap_t h1, h2, h3, h4, *merged;
    sfh_int64_t_float_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int64_t_float_init(&h1);
    sfh_int64_t_float_init(&h2);
    sfh_int64_t_float_init(&h3);
    sfh_int64_t_float_init(&h4);
    sfh_int64_t_float_insert(&h1, &n1, 1, 0);
    sfh_int64_t_float_insert(&h1, &n2, 2, 0);
    sfh_int64_t_float_insert(&h1, &n3, 3, 0);
    sfh_int64_t_float_insert(&h1, &n4, 4, 0);
    sfh_int64_t_float_insert(&h2, &m2, 10, 0);
    sfh_int64_t_float_insert(&h3, &m3, 11, 0);
    sfh_int64_t_float_insert(&h4, &m4, 12, 0);
    sfh_int64_t_float_meld(&h1, &h2, &merged);
    sfh_int64_t_float_meld(merged, &h3, &merged);
    sfh_int64_t_float_meld(merged, &h4, &merged);
    sfh_int64_t_float_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int64_t_float_node_t large_nodes[1000];
    sfh_int64_t_float_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int64_t_float_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int64_t_float_decrease_key(&heap, &large_nodes[i],
                                     large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int64_t_float_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int64_t_double(void) {
  sfh_int64_t_double_heap_t heap;
  sfh_int64_t_double_node_t node;
  sfh_int64_t_double_node_t *out_node;
  sfh_int64_t_double_heap_t *out_heap;
  int is_empty;
  sfh_int64_t_double_error_t rc;
  int i;

  rc = sfh_int64_t_double_init(NULL);
  ASSERT_EQ(sfh_int64_t_double_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_double_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int64_t_double_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_double_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int64_t_double_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_double_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int64_t_double_ERR_NULL_ARG, rc);

  sfh_int64_t_double_init(&heap);

  {
    sfh_int64_t_double_node_t n1, n2, n3;
    rc = sfh_int64_t_double_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int64_t_double_SUCCESS, rc);
    rc = sfh_int64_t_double_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int64_t_double_SUCCESS, rc);
    rc = sfh_int64_t_double_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int64_t_double_SUCCESS, rc);
    rc = sfh_int64_t_double_delete(&heap, &n2);
    ASSERT_EQ(sfh_int64_t_double_SUCCESS, rc);
    rc = sfh_int64_t_double_delete_min(&heap);
    ASSERT_EQ(sfh_int64_t_double_SUCCESS, rc);
    rc = sfh_int64_t_double_delete_min(&heap);
    ASSERT_EQ(sfh_int64_t_double_SUCCESS, rc);
  }

  {
    sfh_int64_t_double_node_t nodes[100];
    sfh_int64_t_double_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int64_t_double_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int64_t_double_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int64_t_double_heap_t h1, h2, h3, h4, *merged;
    sfh_int64_t_double_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int64_t_double_init(&h1);
    sfh_int64_t_double_init(&h2);
    sfh_int64_t_double_init(&h3);
    sfh_int64_t_double_init(&h4);
    sfh_int64_t_double_insert(&h1, &n1, 1, 0);
    sfh_int64_t_double_insert(&h1, &n2, 2, 0);
    sfh_int64_t_double_insert(&h1, &n3, 3, 0);
    sfh_int64_t_double_insert(&h1, &n4, 4, 0);
    sfh_int64_t_double_insert(&h2, &m2, 10, 0);
    sfh_int64_t_double_insert(&h3, &m3, 11, 0);
    sfh_int64_t_double_insert(&h4, &m4, 12, 0);
    sfh_int64_t_double_meld(&h1, &h2, &merged);
    sfh_int64_t_double_meld(merged, &h3, &merged);
    sfh_int64_t_double_meld(merged, &h4, &merged);
    sfh_int64_t_double_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int64_t_double_node_t large_nodes[1000];
    sfh_int64_t_double_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int64_t_double_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int64_t_double_decrease_key(&heap, &large_nodes[i],
                                      large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int64_t_double_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_int64_t_charptr(void) {
  sfh_int64_t_charptr_heap_t heap;
  sfh_int64_t_charptr_node_t node;
  sfh_int64_t_charptr_node_t *out_node;
  sfh_int64_t_charptr_heap_t *out_heap;
  int is_empty;
  sfh_int64_t_charptr_error_t rc;
  int i;

  rc = sfh_int64_t_charptr_init(NULL);
  ASSERT_EQ(sfh_int64_t_charptr_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_charptr_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_int64_t_charptr_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_charptr_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_int64_t_charptr_ERR_NULL_ARG, rc);
  rc = sfh_int64_t_charptr_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_int64_t_charptr_ERR_NULL_ARG, rc);

  sfh_int64_t_charptr_init(&heap);

  {
    sfh_int64_t_charptr_node_t n1, n2, n3;
    rc = sfh_int64_t_charptr_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_int64_t_charptr_SUCCESS, rc);
    rc = sfh_int64_t_charptr_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_int64_t_charptr_SUCCESS, rc);
    rc = sfh_int64_t_charptr_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_int64_t_charptr_SUCCESS, rc);
    rc = sfh_int64_t_charptr_delete(&heap, &n2);
    ASSERT_EQ(sfh_int64_t_charptr_SUCCESS, rc);
    rc = sfh_int64_t_charptr_delete_min(&heap);
    ASSERT_EQ(sfh_int64_t_charptr_SUCCESS, rc);
    rc = sfh_int64_t_charptr_delete_min(&heap);
    ASSERT_EQ(sfh_int64_t_charptr_SUCCESS, rc);
  }

  {
    sfh_int64_t_charptr_node_t nodes[100];
    sfh_int64_t_charptr_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_int64_t_charptr_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_int64_t_charptr_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_int64_t_charptr_heap_t h1, h2, h3, h4, *merged;
    sfh_int64_t_charptr_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_int64_t_charptr_init(&h1);
    sfh_int64_t_charptr_init(&h2);
    sfh_int64_t_charptr_init(&h3);
    sfh_int64_t_charptr_init(&h4);
    sfh_int64_t_charptr_insert(&h1, &n1, 1, 0);
    sfh_int64_t_charptr_insert(&h1, &n2, 2, 0);
    sfh_int64_t_charptr_insert(&h1, &n3, 3, 0);
    sfh_int64_t_charptr_insert(&h1, &n4, 4, 0);
    sfh_int64_t_charptr_insert(&h2, &m2, 10, 0);
    sfh_int64_t_charptr_insert(&h3, &m3, 11, 0);
    sfh_int64_t_charptr_insert(&h4, &m4, 12, 0);
    sfh_int64_t_charptr_meld(&h1, &h2, &merged);
    sfh_int64_t_charptr_meld(merged, &h3, &merged);
    sfh_int64_t_charptr_meld(merged, &h4, &merged);
    sfh_int64_t_charptr_decrease_key(merged, &m4, 0);
  }

  {
    sfh_int64_t_charptr_node_t large_nodes[1000];
    sfh_int64_t_charptr_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_int64_t_charptr_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_int64_t_charptr_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_int64_t_charptr_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint8_t_int8_t(void) {
  sfh_uint8_t_int8_t_heap_t heap;
  sfh_uint8_t_int8_t_node_t node;
  sfh_uint8_t_int8_t_node_t *out_node;
  sfh_uint8_t_int8_t_heap_t *out_heap;
  int is_empty;
  sfh_uint8_t_int8_t_error_t rc;
  int i;

  rc = sfh_uint8_t_int8_t_init(NULL);
  ASSERT_EQ(sfh_uint8_t_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_int8_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint8_t_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_int8_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint8_t_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_int8_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint8_t_int8_t_ERR_NULL_ARG, rc);

  sfh_uint8_t_int8_t_init(&heap);

  {
    sfh_uint8_t_int8_t_node_t n1, n2, n3;
    rc = sfh_uint8_t_int8_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint8_t_int8_t_SUCCESS, rc);
    rc = sfh_uint8_t_int8_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint8_t_int8_t_SUCCESS, rc);
    rc = sfh_uint8_t_int8_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint8_t_int8_t_SUCCESS, rc);
    rc = sfh_uint8_t_int8_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint8_t_int8_t_SUCCESS, rc);
    rc = sfh_uint8_t_int8_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint8_t_int8_t_SUCCESS, rc);
    rc = sfh_uint8_t_int8_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint8_t_int8_t_SUCCESS, rc);
  }

  {
    sfh_uint8_t_int8_t_node_t nodes[100];
    sfh_uint8_t_int8_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint8_t_int8_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint8_t_int8_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint8_t_int8_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint8_t_int8_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint8_t_int8_t_init(&h1);
    sfh_uint8_t_int8_t_init(&h2);
    sfh_uint8_t_int8_t_init(&h3);
    sfh_uint8_t_int8_t_init(&h4);
    sfh_uint8_t_int8_t_insert(&h1, &n1, 1, 0);
    sfh_uint8_t_int8_t_insert(&h1, &n2, 2, 0);
    sfh_uint8_t_int8_t_insert(&h1, &n3, 3, 0);
    sfh_uint8_t_int8_t_insert(&h1, &n4, 4, 0);
    sfh_uint8_t_int8_t_insert(&h2, &m2, 10, 0);
    sfh_uint8_t_int8_t_insert(&h3, &m3, 11, 0);
    sfh_uint8_t_int8_t_insert(&h4, &m4, 12, 0);
    sfh_uint8_t_int8_t_meld(&h1, &h2, &merged);
    sfh_uint8_t_int8_t_meld(merged, &h3, &merged);
    sfh_uint8_t_int8_t_meld(merged, &h4, &merged);
    sfh_uint8_t_int8_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint8_t_int8_t_node_t large_nodes[1000];
    sfh_uint8_t_int8_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint8_t_int8_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint8_t_int8_t_decrease_key(&heap, &large_nodes[i],
                                      large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint8_t_int8_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint8_t_int16_t(void) {
  sfh_uint8_t_int16_t_heap_t heap;
  sfh_uint8_t_int16_t_node_t node;
  sfh_uint8_t_int16_t_node_t *out_node;
  sfh_uint8_t_int16_t_heap_t *out_heap;
  int is_empty;
  sfh_uint8_t_int16_t_error_t rc;
  int i;

  rc = sfh_uint8_t_int16_t_init(NULL);
  ASSERT_EQ(sfh_uint8_t_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_int16_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint8_t_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_int16_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint8_t_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_int16_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint8_t_int16_t_ERR_NULL_ARG, rc);

  sfh_uint8_t_int16_t_init(&heap);

  {
    sfh_uint8_t_int16_t_node_t n1, n2, n3;
    rc = sfh_uint8_t_int16_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint8_t_int16_t_SUCCESS, rc);
    rc = sfh_uint8_t_int16_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint8_t_int16_t_SUCCESS, rc);
    rc = sfh_uint8_t_int16_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint8_t_int16_t_SUCCESS, rc);
    rc = sfh_uint8_t_int16_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint8_t_int16_t_SUCCESS, rc);
    rc = sfh_uint8_t_int16_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint8_t_int16_t_SUCCESS, rc);
    rc = sfh_uint8_t_int16_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint8_t_int16_t_SUCCESS, rc);
  }

  {
    sfh_uint8_t_int16_t_node_t nodes[100];
    sfh_uint8_t_int16_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint8_t_int16_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint8_t_int16_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint8_t_int16_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint8_t_int16_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint8_t_int16_t_init(&h1);
    sfh_uint8_t_int16_t_init(&h2);
    sfh_uint8_t_int16_t_init(&h3);
    sfh_uint8_t_int16_t_init(&h4);
    sfh_uint8_t_int16_t_insert(&h1, &n1, 1, 0);
    sfh_uint8_t_int16_t_insert(&h1, &n2, 2, 0);
    sfh_uint8_t_int16_t_insert(&h1, &n3, 3, 0);
    sfh_uint8_t_int16_t_insert(&h1, &n4, 4, 0);
    sfh_uint8_t_int16_t_insert(&h2, &m2, 10, 0);
    sfh_uint8_t_int16_t_insert(&h3, &m3, 11, 0);
    sfh_uint8_t_int16_t_insert(&h4, &m4, 12, 0);
    sfh_uint8_t_int16_t_meld(&h1, &h2, &merged);
    sfh_uint8_t_int16_t_meld(merged, &h3, &merged);
    sfh_uint8_t_int16_t_meld(merged, &h4, &merged);
    sfh_uint8_t_int16_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint8_t_int16_t_node_t large_nodes[1000];
    sfh_uint8_t_int16_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint8_t_int16_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint8_t_int16_t_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint8_t_int16_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint8_t_int32_t(void) {
  sfh_uint8_t_int32_t_heap_t heap;
  sfh_uint8_t_int32_t_node_t node;
  sfh_uint8_t_int32_t_node_t *out_node;
  sfh_uint8_t_int32_t_heap_t *out_heap;
  int is_empty;
  sfh_uint8_t_int32_t_error_t rc;
  int i;

  rc = sfh_uint8_t_int32_t_init(NULL);
  ASSERT_EQ(sfh_uint8_t_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_int32_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint8_t_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_int32_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint8_t_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_int32_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint8_t_int32_t_ERR_NULL_ARG, rc);

  sfh_uint8_t_int32_t_init(&heap);

  {
    sfh_uint8_t_int32_t_node_t n1, n2, n3;
    rc = sfh_uint8_t_int32_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint8_t_int32_t_SUCCESS, rc);
    rc = sfh_uint8_t_int32_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint8_t_int32_t_SUCCESS, rc);
    rc = sfh_uint8_t_int32_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint8_t_int32_t_SUCCESS, rc);
    rc = sfh_uint8_t_int32_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint8_t_int32_t_SUCCESS, rc);
    rc = sfh_uint8_t_int32_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint8_t_int32_t_SUCCESS, rc);
    rc = sfh_uint8_t_int32_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint8_t_int32_t_SUCCESS, rc);
  }

  {
    sfh_uint8_t_int32_t_node_t nodes[100];
    sfh_uint8_t_int32_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint8_t_int32_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint8_t_int32_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint8_t_int32_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint8_t_int32_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint8_t_int32_t_init(&h1);
    sfh_uint8_t_int32_t_init(&h2);
    sfh_uint8_t_int32_t_init(&h3);
    sfh_uint8_t_int32_t_init(&h4);
    sfh_uint8_t_int32_t_insert(&h1, &n1, 1, 0);
    sfh_uint8_t_int32_t_insert(&h1, &n2, 2, 0);
    sfh_uint8_t_int32_t_insert(&h1, &n3, 3, 0);
    sfh_uint8_t_int32_t_insert(&h1, &n4, 4, 0);
    sfh_uint8_t_int32_t_insert(&h2, &m2, 10, 0);
    sfh_uint8_t_int32_t_insert(&h3, &m3, 11, 0);
    sfh_uint8_t_int32_t_insert(&h4, &m4, 12, 0);
    sfh_uint8_t_int32_t_meld(&h1, &h2, &merged);
    sfh_uint8_t_int32_t_meld(merged, &h3, &merged);
    sfh_uint8_t_int32_t_meld(merged, &h4, &merged);
    sfh_uint8_t_int32_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint8_t_int32_t_node_t large_nodes[1000];
    sfh_uint8_t_int32_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint8_t_int32_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint8_t_int32_t_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint8_t_int32_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint8_t_int64_t(void) {
  sfh_uint8_t_int64_t_heap_t heap;
  sfh_uint8_t_int64_t_node_t node;
  sfh_uint8_t_int64_t_node_t *out_node;
  sfh_uint8_t_int64_t_heap_t *out_heap;
  int is_empty;
  sfh_uint8_t_int64_t_error_t rc;
  int i;

  rc = sfh_uint8_t_int64_t_init(NULL);
  ASSERT_EQ(sfh_uint8_t_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_int64_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint8_t_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_int64_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint8_t_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_int64_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint8_t_int64_t_ERR_NULL_ARG, rc);

  sfh_uint8_t_int64_t_init(&heap);

  {
    sfh_uint8_t_int64_t_node_t n1, n2, n3;
    rc = sfh_uint8_t_int64_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint8_t_int64_t_SUCCESS, rc);
    rc = sfh_uint8_t_int64_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint8_t_int64_t_SUCCESS, rc);
    rc = sfh_uint8_t_int64_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint8_t_int64_t_SUCCESS, rc);
    rc = sfh_uint8_t_int64_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint8_t_int64_t_SUCCESS, rc);
    rc = sfh_uint8_t_int64_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint8_t_int64_t_SUCCESS, rc);
    rc = sfh_uint8_t_int64_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint8_t_int64_t_SUCCESS, rc);
  }

  {
    sfh_uint8_t_int64_t_node_t nodes[100];
    sfh_uint8_t_int64_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint8_t_int64_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint8_t_int64_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint8_t_int64_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint8_t_int64_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint8_t_int64_t_init(&h1);
    sfh_uint8_t_int64_t_init(&h2);
    sfh_uint8_t_int64_t_init(&h3);
    sfh_uint8_t_int64_t_init(&h4);
    sfh_uint8_t_int64_t_insert(&h1, &n1, 1, 0);
    sfh_uint8_t_int64_t_insert(&h1, &n2, 2, 0);
    sfh_uint8_t_int64_t_insert(&h1, &n3, 3, 0);
    sfh_uint8_t_int64_t_insert(&h1, &n4, 4, 0);
    sfh_uint8_t_int64_t_insert(&h2, &m2, 10, 0);
    sfh_uint8_t_int64_t_insert(&h3, &m3, 11, 0);
    sfh_uint8_t_int64_t_insert(&h4, &m4, 12, 0);
    sfh_uint8_t_int64_t_meld(&h1, &h2, &merged);
    sfh_uint8_t_int64_t_meld(merged, &h3, &merged);
    sfh_uint8_t_int64_t_meld(merged, &h4, &merged);
    sfh_uint8_t_int64_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint8_t_int64_t_node_t large_nodes[1000];
    sfh_uint8_t_int64_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint8_t_int64_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint8_t_int64_t_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint8_t_int64_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint8_t_uint8_t(void) {
  sfh_uint8_t_uint8_t_heap_t heap;
  sfh_uint8_t_uint8_t_node_t node;
  sfh_uint8_t_uint8_t_node_t *out_node;
  sfh_uint8_t_uint8_t_heap_t *out_heap;
  int is_empty;
  sfh_uint8_t_uint8_t_error_t rc;
  int i;

  rc = sfh_uint8_t_uint8_t_init(NULL);
  ASSERT_EQ(sfh_uint8_t_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_uint8_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint8_t_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_uint8_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint8_t_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_uint8_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint8_t_uint8_t_ERR_NULL_ARG, rc);

  sfh_uint8_t_uint8_t_init(&heap);

  {
    sfh_uint8_t_uint8_t_node_t n1, n2, n3;
    rc = sfh_uint8_t_uint8_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint8_t_uint8_t_SUCCESS, rc);
    rc = sfh_uint8_t_uint8_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint8_t_uint8_t_SUCCESS, rc);
    rc = sfh_uint8_t_uint8_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint8_t_uint8_t_SUCCESS, rc);
    rc = sfh_uint8_t_uint8_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint8_t_uint8_t_SUCCESS, rc);
    rc = sfh_uint8_t_uint8_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint8_t_uint8_t_SUCCESS, rc);
    rc = sfh_uint8_t_uint8_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint8_t_uint8_t_SUCCESS, rc);
  }

  {
    sfh_uint8_t_uint8_t_node_t nodes[100];
    sfh_uint8_t_uint8_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint8_t_uint8_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint8_t_uint8_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint8_t_uint8_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint8_t_uint8_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint8_t_uint8_t_init(&h1);
    sfh_uint8_t_uint8_t_init(&h2);
    sfh_uint8_t_uint8_t_init(&h3);
    sfh_uint8_t_uint8_t_init(&h4);
    sfh_uint8_t_uint8_t_insert(&h1, &n1, 1, 0);
    sfh_uint8_t_uint8_t_insert(&h1, &n2, 2, 0);
    sfh_uint8_t_uint8_t_insert(&h1, &n3, 3, 0);
    sfh_uint8_t_uint8_t_insert(&h1, &n4, 4, 0);
    sfh_uint8_t_uint8_t_insert(&h2, &m2, 10, 0);
    sfh_uint8_t_uint8_t_insert(&h3, &m3, 11, 0);
    sfh_uint8_t_uint8_t_insert(&h4, &m4, 12, 0);
    sfh_uint8_t_uint8_t_meld(&h1, &h2, &merged);
    sfh_uint8_t_uint8_t_meld(merged, &h3, &merged);
    sfh_uint8_t_uint8_t_meld(merged, &h4, &merged);
    sfh_uint8_t_uint8_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint8_t_uint8_t_node_t large_nodes[1000];
    sfh_uint8_t_uint8_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint8_t_uint8_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint8_t_uint8_t_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint8_t_uint8_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint8_t_uint16_t(void) {
  sfh_uint8_t_uint16_t_heap_t heap;
  sfh_uint8_t_uint16_t_node_t node;
  sfh_uint8_t_uint16_t_node_t *out_node;
  sfh_uint8_t_uint16_t_heap_t *out_heap;
  int is_empty;
  sfh_uint8_t_uint16_t_error_t rc;
  int i;

  rc = sfh_uint8_t_uint16_t_init(NULL);
  ASSERT_EQ(sfh_uint8_t_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_uint16_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint8_t_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_uint16_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint8_t_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_uint16_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint8_t_uint16_t_ERR_NULL_ARG, rc);

  sfh_uint8_t_uint16_t_init(&heap);

  {
    sfh_uint8_t_uint16_t_node_t n1, n2, n3;
    rc = sfh_uint8_t_uint16_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint8_t_uint16_t_SUCCESS, rc);
    rc = sfh_uint8_t_uint16_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint8_t_uint16_t_SUCCESS, rc);
    rc = sfh_uint8_t_uint16_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint8_t_uint16_t_SUCCESS, rc);
    rc = sfh_uint8_t_uint16_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint8_t_uint16_t_SUCCESS, rc);
    rc = sfh_uint8_t_uint16_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint8_t_uint16_t_SUCCESS, rc);
    rc = sfh_uint8_t_uint16_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint8_t_uint16_t_SUCCESS, rc);
  }

  {
    sfh_uint8_t_uint16_t_node_t nodes[100];
    sfh_uint8_t_uint16_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint8_t_uint16_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint8_t_uint16_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint8_t_uint16_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint8_t_uint16_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint8_t_uint16_t_init(&h1);
    sfh_uint8_t_uint16_t_init(&h2);
    sfh_uint8_t_uint16_t_init(&h3);
    sfh_uint8_t_uint16_t_init(&h4);
    sfh_uint8_t_uint16_t_insert(&h1, &n1, 1, 0);
    sfh_uint8_t_uint16_t_insert(&h1, &n2, 2, 0);
    sfh_uint8_t_uint16_t_insert(&h1, &n3, 3, 0);
    sfh_uint8_t_uint16_t_insert(&h1, &n4, 4, 0);
    sfh_uint8_t_uint16_t_insert(&h2, &m2, 10, 0);
    sfh_uint8_t_uint16_t_insert(&h3, &m3, 11, 0);
    sfh_uint8_t_uint16_t_insert(&h4, &m4, 12, 0);
    sfh_uint8_t_uint16_t_meld(&h1, &h2, &merged);
    sfh_uint8_t_uint16_t_meld(merged, &h3, &merged);
    sfh_uint8_t_uint16_t_meld(merged, &h4, &merged);
    sfh_uint8_t_uint16_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint8_t_uint16_t_node_t large_nodes[1000];
    sfh_uint8_t_uint16_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint8_t_uint16_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint8_t_uint16_t_decrease_key(&heap, &large_nodes[i],
                                        large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint8_t_uint16_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint8_t_uint32_t(void) {
  sfh_uint8_t_uint32_t_heap_t heap;
  sfh_uint8_t_uint32_t_node_t node;
  sfh_uint8_t_uint32_t_node_t *out_node;
  sfh_uint8_t_uint32_t_heap_t *out_heap;
  int is_empty;
  sfh_uint8_t_uint32_t_error_t rc;
  int i;

  rc = sfh_uint8_t_uint32_t_init(NULL);
  ASSERT_EQ(sfh_uint8_t_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_uint32_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint8_t_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_uint32_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint8_t_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_uint32_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint8_t_uint32_t_ERR_NULL_ARG, rc);

  sfh_uint8_t_uint32_t_init(&heap);

  {
    sfh_uint8_t_uint32_t_node_t n1, n2, n3;
    rc = sfh_uint8_t_uint32_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint8_t_uint32_t_SUCCESS, rc);
    rc = sfh_uint8_t_uint32_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint8_t_uint32_t_SUCCESS, rc);
    rc = sfh_uint8_t_uint32_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint8_t_uint32_t_SUCCESS, rc);
    rc = sfh_uint8_t_uint32_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint8_t_uint32_t_SUCCESS, rc);
    rc = sfh_uint8_t_uint32_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint8_t_uint32_t_SUCCESS, rc);
    rc = sfh_uint8_t_uint32_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint8_t_uint32_t_SUCCESS, rc);
  }

  {
    sfh_uint8_t_uint32_t_node_t nodes[100];
    sfh_uint8_t_uint32_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint8_t_uint32_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint8_t_uint32_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint8_t_uint32_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint8_t_uint32_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint8_t_uint32_t_init(&h1);
    sfh_uint8_t_uint32_t_init(&h2);
    sfh_uint8_t_uint32_t_init(&h3);
    sfh_uint8_t_uint32_t_init(&h4);
    sfh_uint8_t_uint32_t_insert(&h1, &n1, 1, 0);
    sfh_uint8_t_uint32_t_insert(&h1, &n2, 2, 0);
    sfh_uint8_t_uint32_t_insert(&h1, &n3, 3, 0);
    sfh_uint8_t_uint32_t_insert(&h1, &n4, 4, 0);
    sfh_uint8_t_uint32_t_insert(&h2, &m2, 10, 0);
    sfh_uint8_t_uint32_t_insert(&h3, &m3, 11, 0);
    sfh_uint8_t_uint32_t_insert(&h4, &m4, 12, 0);
    sfh_uint8_t_uint32_t_meld(&h1, &h2, &merged);
    sfh_uint8_t_uint32_t_meld(merged, &h3, &merged);
    sfh_uint8_t_uint32_t_meld(merged, &h4, &merged);
    sfh_uint8_t_uint32_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint8_t_uint32_t_node_t large_nodes[1000];
    sfh_uint8_t_uint32_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint8_t_uint32_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint8_t_uint32_t_decrease_key(&heap, &large_nodes[i],
                                        large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint8_t_uint32_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint8_t_uint64_t(void) {
  sfh_uint8_t_uint64_t_heap_t heap;
  sfh_uint8_t_uint64_t_node_t node;
  sfh_uint8_t_uint64_t_node_t *out_node;
  sfh_uint8_t_uint64_t_heap_t *out_heap;
  int is_empty;
  sfh_uint8_t_uint64_t_error_t rc;
  int i;

  rc = sfh_uint8_t_uint64_t_init(NULL);
  ASSERT_EQ(sfh_uint8_t_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_uint64_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint8_t_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_uint64_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint8_t_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_uint64_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint8_t_uint64_t_ERR_NULL_ARG, rc);

  sfh_uint8_t_uint64_t_init(&heap);

  {
    sfh_uint8_t_uint64_t_node_t n1, n2, n3;
    rc = sfh_uint8_t_uint64_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint8_t_uint64_t_SUCCESS, rc);
    rc = sfh_uint8_t_uint64_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint8_t_uint64_t_SUCCESS, rc);
    rc = sfh_uint8_t_uint64_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint8_t_uint64_t_SUCCESS, rc);
    rc = sfh_uint8_t_uint64_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint8_t_uint64_t_SUCCESS, rc);
    rc = sfh_uint8_t_uint64_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint8_t_uint64_t_SUCCESS, rc);
    rc = sfh_uint8_t_uint64_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint8_t_uint64_t_SUCCESS, rc);
  }

  {
    sfh_uint8_t_uint64_t_node_t nodes[100];
    sfh_uint8_t_uint64_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint8_t_uint64_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint8_t_uint64_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint8_t_uint64_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint8_t_uint64_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint8_t_uint64_t_init(&h1);
    sfh_uint8_t_uint64_t_init(&h2);
    sfh_uint8_t_uint64_t_init(&h3);
    sfh_uint8_t_uint64_t_init(&h4);
    sfh_uint8_t_uint64_t_insert(&h1, &n1, 1, 0);
    sfh_uint8_t_uint64_t_insert(&h1, &n2, 2, 0);
    sfh_uint8_t_uint64_t_insert(&h1, &n3, 3, 0);
    sfh_uint8_t_uint64_t_insert(&h1, &n4, 4, 0);
    sfh_uint8_t_uint64_t_insert(&h2, &m2, 10, 0);
    sfh_uint8_t_uint64_t_insert(&h3, &m3, 11, 0);
    sfh_uint8_t_uint64_t_insert(&h4, &m4, 12, 0);
    sfh_uint8_t_uint64_t_meld(&h1, &h2, &merged);
    sfh_uint8_t_uint64_t_meld(merged, &h3, &merged);
    sfh_uint8_t_uint64_t_meld(merged, &h4, &merged);
    sfh_uint8_t_uint64_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint8_t_uint64_t_node_t large_nodes[1000];
    sfh_uint8_t_uint64_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint8_t_uint64_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint8_t_uint64_t_decrease_key(&heap, &large_nodes[i],
                                        large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint8_t_uint64_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint8_t_float(void) {
  sfh_uint8_t_float_heap_t heap;
  sfh_uint8_t_float_node_t node;
  sfh_uint8_t_float_node_t *out_node;
  sfh_uint8_t_float_heap_t *out_heap;
  int is_empty;
  sfh_uint8_t_float_error_t rc;
  int i;

  rc = sfh_uint8_t_float_init(NULL);
  ASSERT_EQ(sfh_uint8_t_float_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_float_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint8_t_float_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_float_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint8_t_float_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_float_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint8_t_float_ERR_NULL_ARG, rc);

  sfh_uint8_t_float_init(&heap);

  {
    sfh_uint8_t_float_node_t n1, n2, n3;
    rc = sfh_uint8_t_float_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint8_t_float_SUCCESS, rc);
    rc = sfh_uint8_t_float_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint8_t_float_SUCCESS, rc);
    rc = sfh_uint8_t_float_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint8_t_float_SUCCESS, rc);
    rc = sfh_uint8_t_float_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint8_t_float_SUCCESS, rc);
    rc = sfh_uint8_t_float_delete_min(&heap);
    ASSERT_EQ(sfh_uint8_t_float_SUCCESS, rc);
    rc = sfh_uint8_t_float_delete_min(&heap);
    ASSERT_EQ(sfh_uint8_t_float_SUCCESS, rc);
  }

  {
    sfh_uint8_t_float_node_t nodes[100];
    sfh_uint8_t_float_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint8_t_float_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint8_t_float_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint8_t_float_heap_t h1, h2, h3, h4, *merged;
    sfh_uint8_t_float_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint8_t_float_init(&h1);
    sfh_uint8_t_float_init(&h2);
    sfh_uint8_t_float_init(&h3);
    sfh_uint8_t_float_init(&h4);
    sfh_uint8_t_float_insert(&h1, &n1, 1, 0);
    sfh_uint8_t_float_insert(&h1, &n2, 2, 0);
    sfh_uint8_t_float_insert(&h1, &n3, 3, 0);
    sfh_uint8_t_float_insert(&h1, &n4, 4, 0);
    sfh_uint8_t_float_insert(&h2, &m2, 10, 0);
    sfh_uint8_t_float_insert(&h3, &m3, 11, 0);
    sfh_uint8_t_float_insert(&h4, &m4, 12, 0);
    sfh_uint8_t_float_meld(&h1, &h2, &merged);
    sfh_uint8_t_float_meld(merged, &h3, &merged);
    sfh_uint8_t_float_meld(merged, &h4, &merged);
    sfh_uint8_t_float_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint8_t_float_node_t large_nodes[1000];
    sfh_uint8_t_float_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint8_t_float_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint8_t_float_decrease_key(&heap, &large_nodes[i],
                                     large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint8_t_float_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint8_t_double(void) {
  sfh_uint8_t_double_heap_t heap;
  sfh_uint8_t_double_node_t node;
  sfh_uint8_t_double_node_t *out_node;
  sfh_uint8_t_double_heap_t *out_heap;
  int is_empty;
  sfh_uint8_t_double_error_t rc;
  int i;

  rc = sfh_uint8_t_double_init(NULL);
  ASSERT_EQ(sfh_uint8_t_double_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_double_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint8_t_double_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_double_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint8_t_double_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_double_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint8_t_double_ERR_NULL_ARG, rc);

  sfh_uint8_t_double_init(&heap);

  {
    sfh_uint8_t_double_node_t n1, n2, n3;
    rc = sfh_uint8_t_double_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint8_t_double_SUCCESS, rc);
    rc = sfh_uint8_t_double_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint8_t_double_SUCCESS, rc);
    rc = sfh_uint8_t_double_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint8_t_double_SUCCESS, rc);
    rc = sfh_uint8_t_double_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint8_t_double_SUCCESS, rc);
    rc = sfh_uint8_t_double_delete_min(&heap);
    ASSERT_EQ(sfh_uint8_t_double_SUCCESS, rc);
    rc = sfh_uint8_t_double_delete_min(&heap);
    ASSERT_EQ(sfh_uint8_t_double_SUCCESS, rc);
  }

  {
    sfh_uint8_t_double_node_t nodes[100];
    sfh_uint8_t_double_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint8_t_double_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint8_t_double_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint8_t_double_heap_t h1, h2, h3, h4, *merged;
    sfh_uint8_t_double_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint8_t_double_init(&h1);
    sfh_uint8_t_double_init(&h2);
    sfh_uint8_t_double_init(&h3);
    sfh_uint8_t_double_init(&h4);
    sfh_uint8_t_double_insert(&h1, &n1, 1, 0);
    sfh_uint8_t_double_insert(&h1, &n2, 2, 0);
    sfh_uint8_t_double_insert(&h1, &n3, 3, 0);
    sfh_uint8_t_double_insert(&h1, &n4, 4, 0);
    sfh_uint8_t_double_insert(&h2, &m2, 10, 0);
    sfh_uint8_t_double_insert(&h3, &m3, 11, 0);
    sfh_uint8_t_double_insert(&h4, &m4, 12, 0);
    sfh_uint8_t_double_meld(&h1, &h2, &merged);
    sfh_uint8_t_double_meld(merged, &h3, &merged);
    sfh_uint8_t_double_meld(merged, &h4, &merged);
    sfh_uint8_t_double_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint8_t_double_node_t large_nodes[1000];
    sfh_uint8_t_double_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint8_t_double_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint8_t_double_decrease_key(&heap, &large_nodes[i],
                                      large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint8_t_double_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint8_t_charptr(void) {
  sfh_uint8_t_charptr_heap_t heap;
  sfh_uint8_t_charptr_node_t node;
  sfh_uint8_t_charptr_node_t *out_node;
  sfh_uint8_t_charptr_heap_t *out_heap;
  int is_empty;
  sfh_uint8_t_charptr_error_t rc;
  int i;

  rc = sfh_uint8_t_charptr_init(NULL);
  ASSERT_EQ(sfh_uint8_t_charptr_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_charptr_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint8_t_charptr_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_charptr_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint8_t_charptr_ERR_NULL_ARG, rc);
  rc = sfh_uint8_t_charptr_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint8_t_charptr_ERR_NULL_ARG, rc);

  sfh_uint8_t_charptr_init(&heap);

  {
    sfh_uint8_t_charptr_node_t n1, n2, n3;
    rc = sfh_uint8_t_charptr_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint8_t_charptr_SUCCESS, rc);
    rc = sfh_uint8_t_charptr_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint8_t_charptr_SUCCESS, rc);
    rc = sfh_uint8_t_charptr_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint8_t_charptr_SUCCESS, rc);
    rc = sfh_uint8_t_charptr_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint8_t_charptr_SUCCESS, rc);
    rc = sfh_uint8_t_charptr_delete_min(&heap);
    ASSERT_EQ(sfh_uint8_t_charptr_SUCCESS, rc);
    rc = sfh_uint8_t_charptr_delete_min(&heap);
    ASSERT_EQ(sfh_uint8_t_charptr_SUCCESS, rc);
  }

  {
    sfh_uint8_t_charptr_node_t nodes[100];
    sfh_uint8_t_charptr_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint8_t_charptr_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint8_t_charptr_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint8_t_charptr_heap_t h1, h2, h3, h4, *merged;
    sfh_uint8_t_charptr_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint8_t_charptr_init(&h1);
    sfh_uint8_t_charptr_init(&h2);
    sfh_uint8_t_charptr_init(&h3);
    sfh_uint8_t_charptr_init(&h4);
    sfh_uint8_t_charptr_insert(&h1, &n1, 1, 0);
    sfh_uint8_t_charptr_insert(&h1, &n2, 2, 0);
    sfh_uint8_t_charptr_insert(&h1, &n3, 3, 0);
    sfh_uint8_t_charptr_insert(&h1, &n4, 4, 0);
    sfh_uint8_t_charptr_insert(&h2, &m2, 10, 0);
    sfh_uint8_t_charptr_insert(&h3, &m3, 11, 0);
    sfh_uint8_t_charptr_insert(&h4, &m4, 12, 0);
    sfh_uint8_t_charptr_meld(&h1, &h2, &merged);
    sfh_uint8_t_charptr_meld(merged, &h3, &merged);
    sfh_uint8_t_charptr_meld(merged, &h4, &merged);
    sfh_uint8_t_charptr_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint8_t_charptr_node_t large_nodes[1000];
    sfh_uint8_t_charptr_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint8_t_charptr_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint8_t_charptr_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint8_t_charptr_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint16_t_int8_t(void) {
  sfh_uint16_t_int8_t_heap_t heap;
  sfh_uint16_t_int8_t_node_t node;
  sfh_uint16_t_int8_t_node_t *out_node;
  sfh_uint16_t_int8_t_heap_t *out_heap;
  int is_empty;
  sfh_uint16_t_int8_t_error_t rc;
  int i;

  rc = sfh_uint16_t_int8_t_init(NULL);
  ASSERT_EQ(sfh_uint16_t_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_int8_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint16_t_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_int8_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint16_t_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_int8_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint16_t_int8_t_ERR_NULL_ARG, rc);

  sfh_uint16_t_int8_t_init(&heap);

  {
    sfh_uint16_t_int8_t_node_t n1, n2, n3;
    rc = sfh_uint16_t_int8_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint16_t_int8_t_SUCCESS, rc);
    rc = sfh_uint16_t_int8_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint16_t_int8_t_SUCCESS, rc);
    rc = sfh_uint16_t_int8_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint16_t_int8_t_SUCCESS, rc);
    rc = sfh_uint16_t_int8_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint16_t_int8_t_SUCCESS, rc);
    rc = sfh_uint16_t_int8_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint16_t_int8_t_SUCCESS, rc);
    rc = sfh_uint16_t_int8_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint16_t_int8_t_SUCCESS, rc);
  }

  {
    sfh_uint16_t_int8_t_node_t nodes[100];
    sfh_uint16_t_int8_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint16_t_int8_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint16_t_int8_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint16_t_int8_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint16_t_int8_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint16_t_int8_t_init(&h1);
    sfh_uint16_t_int8_t_init(&h2);
    sfh_uint16_t_int8_t_init(&h3);
    sfh_uint16_t_int8_t_init(&h4);
    sfh_uint16_t_int8_t_insert(&h1, &n1, 1, 0);
    sfh_uint16_t_int8_t_insert(&h1, &n2, 2, 0);
    sfh_uint16_t_int8_t_insert(&h1, &n3, 3, 0);
    sfh_uint16_t_int8_t_insert(&h1, &n4, 4, 0);
    sfh_uint16_t_int8_t_insert(&h2, &m2, 10, 0);
    sfh_uint16_t_int8_t_insert(&h3, &m3, 11, 0);
    sfh_uint16_t_int8_t_insert(&h4, &m4, 12, 0);
    sfh_uint16_t_int8_t_meld(&h1, &h2, &merged);
    sfh_uint16_t_int8_t_meld(merged, &h3, &merged);
    sfh_uint16_t_int8_t_meld(merged, &h4, &merged);
    sfh_uint16_t_int8_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint16_t_int8_t_node_t large_nodes[1000];
    sfh_uint16_t_int8_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint16_t_int8_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint16_t_int8_t_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint16_t_int8_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint16_t_int16_t(void) {
  sfh_uint16_t_int16_t_heap_t heap;
  sfh_uint16_t_int16_t_node_t node;
  sfh_uint16_t_int16_t_node_t *out_node;
  sfh_uint16_t_int16_t_heap_t *out_heap;
  int is_empty;
  sfh_uint16_t_int16_t_error_t rc;
  int i;

  rc = sfh_uint16_t_int16_t_init(NULL);
  ASSERT_EQ(sfh_uint16_t_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_int16_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint16_t_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_int16_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint16_t_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_int16_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint16_t_int16_t_ERR_NULL_ARG, rc);

  sfh_uint16_t_int16_t_init(&heap);

  {
    sfh_uint16_t_int16_t_node_t n1, n2, n3;
    rc = sfh_uint16_t_int16_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint16_t_int16_t_SUCCESS, rc);
    rc = sfh_uint16_t_int16_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint16_t_int16_t_SUCCESS, rc);
    rc = sfh_uint16_t_int16_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint16_t_int16_t_SUCCESS, rc);
    rc = sfh_uint16_t_int16_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint16_t_int16_t_SUCCESS, rc);
    rc = sfh_uint16_t_int16_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint16_t_int16_t_SUCCESS, rc);
    rc = sfh_uint16_t_int16_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint16_t_int16_t_SUCCESS, rc);
  }

  {
    sfh_uint16_t_int16_t_node_t nodes[100];
    sfh_uint16_t_int16_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint16_t_int16_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint16_t_int16_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint16_t_int16_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint16_t_int16_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint16_t_int16_t_init(&h1);
    sfh_uint16_t_int16_t_init(&h2);
    sfh_uint16_t_int16_t_init(&h3);
    sfh_uint16_t_int16_t_init(&h4);
    sfh_uint16_t_int16_t_insert(&h1, &n1, 1, 0);
    sfh_uint16_t_int16_t_insert(&h1, &n2, 2, 0);
    sfh_uint16_t_int16_t_insert(&h1, &n3, 3, 0);
    sfh_uint16_t_int16_t_insert(&h1, &n4, 4, 0);
    sfh_uint16_t_int16_t_insert(&h2, &m2, 10, 0);
    sfh_uint16_t_int16_t_insert(&h3, &m3, 11, 0);
    sfh_uint16_t_int16_t_insert(&h4, &m4, 12, 0);
    sfh_uint16_t_int16_t_meld(&h1, &h2, &merged);
    sfh_uint16_t_int16_t_meld(merged, &h3, &merged);
    sfh_uint16_t_int16_t_meld(merged, &h4, &merged);
    sfh_uint16_t_int16_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint16_t_int16_t_node_t large_nodes[1000];
    sfh_uint16_t_int16_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint16_t_int16_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint16_t_int16_t_decrease_key(&heap, &large_nodes[i],
                                        large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint16_t_int16_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint16_t_int32_t(void) {
  sfh_uint16_t_int32_t_heap_t heap;
  sfh_uint16_t_int32_t_node_t node;
  sfh_uint16_t_int32_t_node_t *out_node;
  sfh_uint16_t_int32_t_heap_t *out_heap;
  int is_empty;
  sfh_uint16_t_int32_t_error_t rc;
  int i;

  rc = sfh_uint16_t_int32_t_init(NULL);
  ASSERT_EQ(sfh_uint16_t_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_int32_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint16_t_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_int32_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint16_t_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_int32_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint16_t_int32_t_ERR_NULL_ARG, rc);

  sfh_uint16_t_int32_t_init(&heap);

  {
    sfh_uint16_t_int32_t_node_t n1, n2, n3;
    rc = sfh_uint16_t_int32_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint16_t_int32_t_SUCCESS, rc);
    rc = sfh_uint16_t_int32_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint16_t_int32_t_SUCCESS, rc);
    rc = sfh_uint16_t_int32_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint16_t_int32_t_SUCCESS, rc);
    rc = sfh_uint16_t_int32_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint16_t_int32_t_SUCCESS, rc);
    rc = sfh_uint16_t_int32_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint16_t_int32_t_SUCCESS, rc);
    rc = sfh_uint16_t_int32_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint16_t_int32_t_SUCCESS, rc);
  }

  {
    sfh_uint16_t_int32_t_node_t nodes[100];
    sfh_uint16_t_int32_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint16_t_int32_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint16_t_int32_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint16_t_int32_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint16_t_int32_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint16_t_int32_t_init(&h1);
    sfh_uint16_t_int32_t_init(&h2);
    sfh_uint16_t_int32_t_init(&h3);
    sfh_uint16_t_int32_t_init(&h4);
    sfh_uint16_t_int32_t_insert(&h1, &n1, 1, 0);
    sfh_uint16_t_int32_t_insert(&h1, &n2, 2, 0);
    sfh_uint16_t_int32_t_insert(&h1, &n3, 3, 0);
    sfh_uint16_t_int32_t_insert(&h1, &n4, 4, 0);
    sfh_uint16_t_int32_t_insert(&h2, &m2, 10, 0);
    sfh_uint16_t_int32_t_insert(&h3, &m3, 11, 0);
    sfh_uint16_t_int32_t_insert(&h4, &m4, 12, 0);
    sfh_uint16_t_int32_t_meld(&h1, &h2, &merged);
    sfh_uint16_t_int32_t_meld(merged, &h3, &merged);
    sfh_uint16_t_int32_t_meld(merged, &h4, &merged);
    sfh_uint16_t_int32_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint16_t_int32_t_node_t large_nodes[1000];
    sfh_uint16_t_int32_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint16_t_int32_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint16_t_int32_t_decrease_key(&heap, &large_nodes[i],
                                        large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint16_t_int32_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint16_t_int64_t(void) {
  sfh_uint16_t_int64_t_heap_t heap;
  sfh_uint16_t_int64_t_node_t node;
  sfh_uint16_t_int64_t_node_t *out_node;
  sfh_uint16_t_int64_t_heap_t *out_heap;
  int is_empty;
  sfh_uint16_t_int64_t_error_t rc;
  int i;

  rc = sfh_uint16_t_int64_t_init(NULL);
  ASSERT_EQ(sfh_uint16_t_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_int64_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint16_t_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_int64_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint16_t_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_int64_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint16_t_int64_t_ERR_NULL_ARG, rc);

  sfh_uint16_t_int64_t_init(&heap);

  {
    sfh_uint16_t_int64_t_node_t n1, n2, n3;
    rc = sfh_uint16_t_int64_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint16_t_int64_t_SUCCESS, rc);
    rc = sfh_uint16_t_int64_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint16_t_int64_t_SUCCESS, rc);
    rc = sfh_uint16_t_int64_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint16_t_int64_t_SUCCESS, rc);
    rc = sfh_uint16_t_int64_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint16_t_int64_t_SUCCESS, rc);
    rc = sfh_uint16_t_int64_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint16_t_int64_t_SUCCESS, rc);
    rc = sfh_uint16_t_int64_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint16_t_int64_t_SUCCESS, rc);
  }

  {
    sfh_uint16_t_int64_t_node_t nodes[100];
    sfh_uint16_t_int64_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint16_t_int64_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint16_t_int64_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint16_t_int64_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint16_t_int64_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint16_t_int64_t_init(&h1);
    sfh_uint16_t_int64_t_init(&h2);
    sfh_uint16_t_int64_t_init(&h3);
    sfh_uint16_t_int64_t_init(&h4);
    sfh_uint16_t_int64_t_insert(&h1, &n1, 1, 0);
    sfh_uint16_t_int64_t_insert(&h1, &n2, 2, 0);
    sfh_uint16_t_int64_t_insert(&h1, &n3, 3, 0);
    sfh_uint16_t_int64_t_insert(&h1, &n4, 4, 0);
    sfh_uint16_t_int64_t_insert(&h2, &m2, 10, 0);
    sfh_uint16_t_int64_t_insert(&h3, &m3, 11, 0);
    sfh_uint16_t_int64_t_insert(&h4, &m4, 12, 0);
    sfh_uint16_t_int64_t_meld(&h1, &h2, &merged);
    sfh_uint16_t_int64_t_meld(merged, &h3, &merged);
    sfh_uint16_t_int64_t_meld(merged, &h4, &merged);
    sfh_uint16_t_int64_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint16_t_int64_t_node_t large_nodes[1000];
    sfh_uint16_t_int64_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint16_t_int64_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint16_t_int64_t_decrease_key(&heap, &large_nodes[i],
                                        large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint16_t_int64_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint16_t_uint8_t(void) {
  sfh_uint16_t_uint8_t_heap_t heap;
  sfh_uint16_t_uint8_t_node_t node;
  sfh_uint16_t_uint8_t_node_t *out_node;
  sfh_uint16_t_uint8_t_heap_t *out_heap;
  int is_empty;
  sfh_uint16_t_uint8_t_error_t rc;
  int i;

  rc = sfh_uint16_t_uint8_t_init(NULL);
  ASSERT_EQ(sfh_uint16_t_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_uint8_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint16_t_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_uint8_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint16_t_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_uint8_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint16_t_uint8_t_ERR_NULL_ARG, rc);

  sfh_uint16_t_uint8_t_init(&heap);

  {
    sfh_uint16_t_uint8_t_node_t n1, n2, n3;
    rc = sfh_uint16_t_uint8_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint16_t_uint8_t_SUCCESS, rc);
    rc = sfh_uint16_t_uint8_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint16_t_uint8_t_SUCCESS, rc);
    rc = sfh_uint16_t_uint8_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint16_t_uint8_t_SUCCESS, rc);
    rc = sfh_uint16_t_uint8_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint16_t_uint8_t_SUCCESS, rc);
    rc = sfh_uint16_t_uint8_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint16_t_uint8_t_SUCCESS, rc);
    rc = sfh_uint16_t_uint8_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint16_t_uint8_t_SUCCESS, rc);
  }

  {
    sfh_uint16_t_uint8_t_node_t nodes[100];
    sfh_uint16_t_uint8_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint16_t_uint8_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint16_t_uint8_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint16_t_uint8_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint16_t_uint8_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint16_t_uint8_t_init(&h1);
    sfh_uint16_t_uint8_t_init(&h2);
    sfh_uint16_t_uint8_t_init(&h3);
    sfh_uint16_t_uint8_t_init(&h4);
    sfh_uint16_t_uint8_t_insert(&h1, &n1, 1, 0);
    sfh_uint16_t_uint8_t_insert(&h1, &n2, 2, 0);
    sfh_uint16_t_uint8_t_insert(&h1, &n3, 3, 0);
    sfh_uint16_t_uint8_t_insert(&h1, &n4, 4, 0);
    sfh_uint16_t_uint8_t_insert(&h2, &m2, 10, 0);
    sfh_uint16_t_uint8_t_insert(&h3, &m3, 11, 0);
    sfh_uint16_t_uint8_t_insert(&h4, &m4, 12, 0);
    sfh_uint16_t_uint8_t_meld(&h1, &h2, &merged);
    sfh_uint16_t_uint8_t_meld(merged, &h3, &merged);
    sfh_uint16_t_uint8_t_meld(merged, &h4, &merged);
    sfh_uint16_t_uint8_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint16_t_uint8_t_node_t large_nodes[1000];
    sfh_uint16_t_uint8_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint16_t_uint8_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint16_t_uint8_t_decrease_key(&heap, &large_nodes[i],
                                        large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint16_t_uint8_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint16_t_uint16_t(void) {
  sfh_uint16_t_uint16_t_heap_t heap;
  sfh_uint16_t_uint16_t_node_t node;
  sfh_uint16_t_uint16_t_node_t *out_node;
  sfh_uint16_t_uint16_t_heap_t *out_heap;
  int is_empty;
  sfh_uint16_t_uint16_t_error_t rc;
  int i;

  rc = sfh_uint16_t_uint16_t_init(NULL);
  ASSERT_EQ(sfh_uint16_t_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_uint16_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint16_t_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_uint16_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint16_t_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_uint16_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint16_t_uint16_t_ERR_NULL_ARG, rc);

  sfh_uint16_t_uint16_t_init(&heap);

  {
    sfh_uint16_t_uint16_t_node_t n1, n2, n3;
    rc = sfh_uint16_t_uint16_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint16_t_uint16_t_SUCCESS, rc);
    rc = sfh_uint16_t_uint16_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint16_t_uint16_t_SUCCESS, rc);
    rc = sfh_uint16_t_uint16_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint16_t_uint16_t_SUCCESS, rc);
    rc = sfh_uint16_t_uint16_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint16_t_uint16_t_SUCCESS, rc);
    rc = sfh_uint16_t_uint16_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint16_t_uint16_t_SUCCESS, rc);
    rc = sfh_uint16_t_uint16_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint16_t_uint16_t_SUCCESS, rc);
  }

  {
    sfh_uint16_t_uint16_t_node_t nodes[100];
    sfh_uint16_t_uint16_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint16_t_uint16_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint16_t_uint16_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint16_t_uint16_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint16_t_uint16_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint16_t_uint16_t_init(&h1);
    sfh_uint16_t_uint16_t_init(&h2);
    sfh_uint16_t_uint16_t_init(&h3);
    sfh_uint16_t_uint16_t_init(&h4);
    sfh_uint16_t_uint16_t_insert(&h1, &n1, 1, 0);
    sfh_uint16_t_uint16_t_insert(&h1, &n2, 2, 0);
    sfh_uint16_t_uint16_t_insert(&h1, &n3, 3, 0);
    sfh_uint16_t_uint16_t_insert(&h1, &n4, 4, 0);
    sfh_uint16_t_uint16_t_insert(&h2, &m2, 10, 0);
    sfh_uint16_t_uint16_t_insert(&h3, &m3, 11, 0);
    sfh_uint16_t_uint16_t_insert(&h4, &m4, 12, 0);
    sfh_uint16_t_uint16_t_meld(&h1, &h2, &merged);
    sfh_uint16_t_uint16_t_meld(merged, &h3, &merged);
    sfh_uint16_t_uint16_t_meld(merged, &h4, &merged);
    sfh_uint16_t_uint16_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint16_t_uint16_t_node_t large_nodes[1000];
    sfh_uint16_t_uint16_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint16_t_uint16_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint16_t_uint16_t_decrease_key(&heap, &large_nodes[i],
                                         large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint16_t_uint16_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint16_t_uint32_t(void) {
  sfh_uint16_t_uint32_t_heap_t heap;
  sfh_uint16_t_uint32_t_node_t node;
  sfh_uint16_t_uint32_t_node_t *out_node;
  sfh_uint16_t_uint32_t_heap_t *out_heap;
  int is_empty;
  sfh_uint16_t_uint32_t_error_t rc;
  int i;

  rc = sfh_uint16_t_uint32_t_init(NULL);
  ASSERT_EQ(sfh_uint16_t_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_uint32_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint16_t_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_uint32_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint16_t_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_uint32_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint16_t_uint32_t_ERR_NULL_ARG, rc);

  sfh_uint16_t_uint32_t_init(&heap);

  {
    sfh_uint16_t_uint32_t_node_t n1, n2, n3;
    rc = sfh_uint16_t_uint32_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint16_t_uint32_t_SUCCESS, rc);
    rc = sfh_uint16_t_uint32_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint16_t_uint32_t_SUCCESS, rc);
    rc = sfh_uint16_t_uint32_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint16_t_uint32_t_SUCCESS, rc);
    rc = sfh_uint16_t_uint32_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint16_t_uint32_t_SUCCESS, rc);
    rc = sfh_uint16_t_uint32_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint16_t_uint32_t_SUCCESS, rc);
    rc = sfh_uint16_t_uint32_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint16_t_uint32_t_SUCCESS, rc);
  }

  {
    sfh_uint16_t_uint32_t_node_t nodes[100];
    sfh_uint16_t_uint32_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint16_t_uint32_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint16_t_uint32_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint16_t_uint32_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint16_t_uint32_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint16_t_uint32_t_init(&h1);
    sfh_uint16_t_uint32_t_init(&h2);
    sfh_uint16_t_uint32_t_init(&h3);
    sfh_uint16_t_uint32_t_init(&h4);
    sfh_uint16_t_uint32_t_insert(&h1, &n1, 1, 0);
    sfh_uint16_t_uint32_t_insert(&h1, &n2, 2, 0);
    sfh_uint16_t_uint32_t_insert(&h1, &n3, 3, 0);
    sfh_uint16_t_uint32_t_insert(&h1, &n4, 4, 0);
    sfh_uint16_t_uint32_t_insert(&h2, &m2, 10, 0);
    sfh_uint16_t_uint32_t_insert(&h3, &m3, 11, 0);
    sfh_uint16_t_uint32_t_insert(&h4, &m4, 12, 0);
    sfh_uint16_t_uint32_t_meld(&h1, &h2, &merged);
    sfh_uint16_t_uint32_t_meld(merged, &h3, &merged);
    sfh_uint16_t_uint32_t_meld(merged, &h4, &merged);
    sfh_uint16_t_uint32_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint16_t_uint32_t_node_t large_nodes[1000];
    sfh_uint16_t_uint32_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint16_t_uint32_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint16_t_uint32_t_decrease_key(&heap, &large_nodes[i],
                                         large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint16_t_uint32_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint16_t_uint64_t(void) {
  sfh_uint16_t_uint64_t_heap_t heap;
  sfh_uint16_t_uint64_t_node_t node;
  sfh_uint16_t_uint64_t_node_t *out_node;
  sfh_uint16_t_uint64_t_heap_t *out_heap;
  int is_empty;
  sfh_uint16_t_uint64_t_error_t rc;
  int i;

  rc = sfh_uint16_t_uint64_t_init(NULL);
  ASSERT_EQ(sfh_uint16_t_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_uint64_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint16_t_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_uint64_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint16_t_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_uint64_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint16_t_uint64_t_ERR_NULL_ARG, rc);

  sfh_uint16_t_uint64_t_init(&heap);

  {
    sfh_uint16_t_uint64_t_node_t n1, n2, n3;
    rc = sfh_uint16_t_uint64_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint16_t_uint64_t_SUCCESS, rc);
    rc = sfh_uint16_t_uint64_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint16_t_uint64_t_SUCCESS, rc);
    rc = sfh_uint16_t_uint64_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint16_t_uint64_t_SUCCESS, rc);
    rc = sfh_uint16_t_uint64_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint16_t_uint64_t_SUCCESS, rc);
    rc = sfh_uint16_t_uint64_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint16_t_uint64_t_SUCCESS, rc);
    rc = sfh_uint16_t_uint64_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint16_t_uint64_t_SUCCESS, rc);
  }

  {
    sfh_uint16_t_uint64_t_node_t nodes[100];
    sfh_uint16_t_uint64_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint16_t_uint64_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint16_t_uint64_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint16_t_uint64_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint16_t_uint64_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint16_t_uint64_t_init(&h1);
    sfh_uint16_t_uint64_t_init(&h2);
    sfh_uint16_t_uint64_t_init(&h3);
    sfh_uint16_t_uint64_t_init(&h4);
    sfh_uint16_t_uint64_t_insert(&h1, &n1, 1, 0);
    sfh_uint16_t_uint64_t_insert(&h1, &n2, 2, 0);
    sfh_uint16_t_uint64_t_insert(&h1, &n3, 3, 0);
    sfh_uint16_t_uint64_t_insert(&h1, &n4, 4, 0);
    sfh_uint16_t_uint64_t_insert(&h2, &m2, 10, 0);
    sfh_uint16_t_uint64_t_insert(&h3, &m3, 11, 0);
    sfh_uint16_t_uint64_t_insert(&h4, &m4, 12, 0);
    sfh_uint16_t_uint64_t_meld(&h1, &h2, &merged);
    sfh_uint16_t_uint64_t_meld(merged, &h3, &merged);
    sfh_uint16_t_uint64_t_meld(merged, &h4, &merged);
    sfh_uint16_t_uint64_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint16_t_uint64_t_node_t large_nodes[1000];
    sfh_uint16_t_uint64_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint16_t_uint64_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint16_t_uint64_t_decrease_key(&heap, &large_nodes[i],
                                         large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint16_t_uint64_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint16_t_float(void) {
  sfh_uint16_t_float_heap_t heap;
  sfh_uint16_t_float_node_t node;
  sfh_uint16_t_float_node_t *out_node;
  sfh_uint16_t_float_heap_t *out_heap;
  int is_empty;
  sfh_uint16_t_float_error_t rc;
  int i;

  rc = sfh_uint16_t_float_init(NULL);
  ASSERT_EQ(sfh_uint16_t_float_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_float_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint16_t_float_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_float_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint16_t_float_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_float_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint16_t_float_ERR_NULL_ARG, rc);

  sfh_uint16_t_float_init(&heap);

  {
    sfh_uint16_t_float_node_t n1, n2, n3;
    rc = sfh_uint16_t_float_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint16_t_float_SUCCESS, rc);
    rc = sfh_uint16_t_float_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint16_t_float_SUCCESS, rc);
    rc = sfh_uint16_t_float_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint16_t_float_SUCCESS, rc);
    rc = sfh_uint16_t_float_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint16_t_float_SUCCESS, rc);
    rc = sfh_uint16_t_float_delete_min(&heap);
    ASSERT_EQ(sfh_uint16_t_float_SUCCESS, rc);
    rc = sfh_uint16_t_float_delete_min(&heap);
    ASSERT_EQ(sfh_uint16_t_float_SUCCESS, rc);
  }

  {
    sfh_uint16_t_float_node_t nodes[100];
    sfh_uint16_t_float_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint16_t_float_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint16_t_float_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint16_t_float_heap_t h1, h2, h3, h4, *merged;
    sfh_uint16_t_float_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint16_t_float_init(&h1);
    sfh_uint16_t_float_init(&h2);
    sfh_uint16_t_float_init(&h3);
    sfh_uint16_t_float_init(&h4);
    sfh_uint16_t_float_insert(&h1, &n1, 1, 0);
    sfh_uint16_t_float_insert(&h1, &n2, 2, 0);
    sfh_uint16_t_float_insert(&h1, &n3, 3, 0);
    sfh_uint16_t_float_insert(&h1, &n4, 4, 0);
    sfh_uint16_t_float_insert(&h2, &m2, 10, 0);
    sfh_uint16_t_float_insert(&h3, &m3, 11, 0);
    sfh_uint16_t_float_insert(&h4, &m4, 12, 0);
    sfh_uint16_t_float_meld(&h1, &h2, &merged);
    sfh_uint16_t_float_meld(merged, &h3, &merged);
    sfh_uint16_t_float_meld(merged, &h4, &merged);
    sfh_uint16_t_float_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint16_t_float_node_t large_nodes[1000];
    sfh_uint16_t_float_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint16_t_float_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint16_t_float_decrease_key(&heap, &large_nodes[i],
                                      large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint16_t_float_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint16_t_double(void) {
  sfh_uint16_t_double_heap_t heap;
  sfh_uint16_t_double_node_t node;
  sfh_uint16_t_double_node_t *out_node;
  sfh_uint16_t_double_heap_t *out_heap;
  int is_empty;
  sfh_uint16_t_double_error_t rc;
  int i;

  rc = sfh_uint16_t_double_init(NULL);
  ASSERT_EQ(sfh_uint16_t_double_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_double_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint16_t_double_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_double_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint16_t_double_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_double_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint16_t_double_ERR_NULL_ARG, rc);

  sfh_uint16_t_double_init(&heap);

  {
    sfh_uint16_t_double_node_t n1, n2, n3;
    rc = sfh_uint16_t_double_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint16_t_double_SUCCESS, rc);
    rc = sfh_uint16_t_double_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint16_t_double_SUCCESS, rc);
    rc = sfh_uint16_t_double_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint16_t_double_SUCCESS, rc);
    rc = sfh_uint16_t_double_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint16_t_double_SUCCESS, rc);
    rc = sfh_uint16_t_double_delete_min(&heap);
    ASSERT_EQ(sfh_uint16_t_double_SUCCESS, rc);
    rc = sfh_uint16_t_double_delete_min(&heap);
    ASSERT_EQ(sfh_uint16_t_double_SUCCESS, rc);
  }

  {
    sfh_uint16_t_double_node_t nodes[100];
    sfh_uint16_t_double_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint16_t_double_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint16_t_double_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint16_t_double_heap_t h1, h2, h3, h4, *merged;
    sfh_uint16_t_double_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint16_t_double_init(&h1);
    sfh_uint16_t_double_init(&h2);
    sfh_uint16_t_double_init(&h3);
    sfh_uint16_t_double_init(&h4);
    sfh_uint16_t_double_insert(&h1, &n1, 1, 0);
    sfh_uint16_t_double_insert(&h1, &n2, 2, 0);
    sfh_uint16_t_double_insert(&h1, &n3, 3, 0);
    sfh_uint16_t_double_insert(&h1, &n4, 4, 0);
    sfh_uint16_t_double_insert(&h2, &m2, 10, 0);
    sfh_uint16_t_double_insert(&h3, &m3, 11, 0);
    sfh_uint16_t_double_insert(&h4, &m4, 12, 0);
    sfh_uint16_t_double_meld(&h1, &h2, &merged);
    sfh_uint16_t_double_meld(merged, &h3, &merged);
    sfh_uint16_t_double_meld(merged, &h4, &merged);
    sfh_uint16_t_double_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint16_t_double_node_t large_nodes[1000];
    sfh_uint16_t_double_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint16_t_double_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint16_t_double_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint16_t_double_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint16_t_charptr(void) {
  sfh_uint16_t_charptr_heap_t heap;
  sfh_uint16_t_charptr_node_t node;
  sfh_uint16_t_charptr_node_t *out_node;
  sfh_uint16_t_charptr_heap_t *out_heap;
  int is_empty;
  sfh_uint16_t_charptr_error_t rc;
  int i;

  rc = sfh_uint16_t_charptr_init(NULL);
  ASSERT_EQ(sfh_uint16_t_charptr_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_charptr_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint16_t_charptr_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_charptr_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint16_t_charptr_ERR_NULL_ARG, rc);
  rc = sfh_uint16_t_charptr_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint16_t_charptr_ERR_NULL_ARG, rc);

  sfh_uint16_t_charptr_init(&heap);

  {
    sfh_uint16_t_charptr_node_t n1, n2, n3;
    rc = sfh_uint16_t_charptr_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint16_t_charptr_SUCCESS, rc);
    rc = sfh_uint16_t_charptr_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint16_t_charptr_SUCCESS, rc);
    rc = sfh_uint16_t_charptr_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint16_t_charptr_SUCCESS, rc);
    rc = sfh_uint16_t_charptr_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint16_t_charptr_SUCCESS, rc);
    rc = sfh_uint16_t_charptr_delete_min(&heap);
    ASSERT_EQ(sfh_uint16_t_charptr_SUCCESS, rc);
    rc = sfh_uint16_t_charptr_delete_min(&heap);
    ASSERT_EQ(sfh_uint16_t_charptr_SUCCESS, rc);
  }

  {
    sfh_uint16_t_charptr_node_t nodes[100];
    sfh_uint16_t_charptr_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint16_t_charptr_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint16_t_charptr_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint16_t_charptr_heap_t h1, h2, h3, h4, *merged;
    sfh_uint16_t_charptr_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint16_t_charptr_init(&h1);
    sfh_uint16_t_charptr_init(&h2);
    sfh_uint16_t_charptr_init(&h3);
    sfh_uint16_t_charptr_init(&h4);
    sfh_uint16_t_charptr_insert(&h1, &n1, 1, 0);
    sfh_uint16_t_charptr_insert(&h1, &n2, 2, 0);
    sfh_uint16_t_charptr_insert(&h1, &n3, 3, 0);
    sfh_uint16_t_charptr_insert(&h1, &n4, 4, 0);
    sfh_uint16_t_charptr_insert(&h2, &m2, 10, 0);
    sfh_uint16_t_charptr_insert(&h3, &m3, 11, 0);
    sfh_uint16_t_charptr_insert(&h4, &m4, 12, 0);
    sfh_uint16_t_charptr_meld(&h1, &h2, &merged);
    sfh_uint16_t_charptr_meld(merged, &h3, &merged);
    sfh_uint16_t_charptr_meld(merged, &h4, &merged);
    sfh_uint16_t_charptr_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint16_t_charptr_node_t large_nodes[1000];
    sfh_uint16_t_charptr_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint16_t_charptr_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint16_t_charptr_decrease_key(&heap, &large_nodes[i],
                                        large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint16_t_charptr_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint32_t_int8_t(void) {
  sfh_uint32_t_int8_t_heap_t heap;
  sfh_uint32_t_int8_t_node_t node;
  sfh_uint32_t_int8_t_node_t *out_node;
  sfh_uint32_t_int8_t_heap_t *out_heap;
  int is_empty;
  sfh_uint32_t_int8_t_error_t rc;
  int i;

  rc = sfh_uint32_t_int8_t_init(NULL);
  ASSERT_EQ(sfh_uint32_t_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_int8_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint32_t_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_int8_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint32_t_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_int8_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint32_t_int8_t_ERR_NULL_ARG, rc);

  sfh_uint32_t_int8_t_init(&heap);

  {
    sfh_uint32_t_int8_t_node_t n1, n2, n3;
    rc = sfh_uint32_t_int8_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint32_t_int8_t_SUCCESS, rc);
    rc = sfh_uint32_t_int8_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint32_t_int8_t_SUCCESS, rc);
    rc = sfh_uint32_t_int8_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint32_t_int8_t_SUCCESS, rc);
    rc = sfh_uint32_t_int8_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint32_t_int8_t_SUCCESS, rc);
    rc = sfh_uint32_t_int8_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint32_t_int8_t_SUCCESS, rc);
    rc = sfh_uint32_t_int8_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint32_t_int8_t_SUCCESS, rc);
  }

  {
    sfh_uint32_t_int8_t_node_t nodes[100];
    sfh_uint32_t_int8_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint32_t_int8_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint32_t_int8_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint32_t_int8_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint32_t_int8_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint32_t_int8_t_init(&h1);
    sfh_uint32_t_int8_t_init(&h2);
    sfh_uint32_t_int8_t_init(&h3);
    sfh_uint32_t_int8_t_init(&h4);
    sfh_uint32_t_int8_t_insert(&h1, &n1, 1, 0);
    sfh_uint32_t_int8_t_insert(&h1, &n2, 2, 0);
    sfh_uint32_t_int8_t_insert(&h1, &n3, 3, 0);
    sfh_uint32_t_int8_t_insert(&h1, &n4, 4, 0);
    sfh_uint32_t_int8_t_insert(&h2, &m2, 10, 0);
    sfh_uint32_t_int8_t_insert(&h3, &m3, 11, 0);
    sfh_uint32_t_int8_t_insert(&h4, &m4, 12, 0);
    sfh_uint32_t_int8_t_meld(&h1, &h2, &merged);
    sfh_uint32_t_int8_t_meld(merged, &h3, &merged);
    sfh_uint32_t_int8_t_meld(merged, &h4, &merged);
    sfh_uint32_t_int8_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint32_t_int8_t_node_t large_nodes[1000];
    sfh_uint32_t_int8_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint32_t_int8_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint32_t_int8_t_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint32_t_int8_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint32_t_int16_t(void) {
  sfh_uint32_t_int16_t_heap_t heap;
  sfh_uint32_t_int16_t_node_t node;
  sfh_uint32_t_int16_t_node_t *out_node;
  sfh_uint32_t_int16_t_heap_t *out_heap;
  int is_empty;
  sfh_uint32_t_int16_t_error_t rc;
  int i;

  rc = sfh_uint32_t_int16_t_init(NULL);
  ASSERT_EQ(sfh_uint32_t_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_int16_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint32_t_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_int16_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint32_t_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_int16_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint32_t_int16_t_ERR_NULL_ARG, rc);

  sfh_uint32_t_int16_t_init(&heap);

  {
    sfh_uint32_t_int16_t_node_t n1, n2, n3;
    rc = sfh_uint32_t_int16_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint32_t_int16_t_SUCCESS, rc);
    rc = sfh_uint32_t_int16_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint32_t_int16_t_SUCCESS, rc);
    rc = sfh_uint32_t_int16_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint32_t_int16_t_SUCCESS, rc);
    rc = sfh_uint32_t_int16_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint32_t_int16_t_SUCCESS, rc);
    rc = sfh_uint32_t_int16_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint32_t_int16_t_SUCCESS, rc);
    rc = sfh_uint32_t_int16_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint32_t_int16_t_SUCCESS, rc);
  }

  {
    sfh_uint32_t_int16_t_node_t nodes[100];
    sfh_uint32_t_int16_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint32_t_int16_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint32_t_int16_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint32_t_int16_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint32_t_int16_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint32_t_int16_t_init(&h1);
    sfh_uint32_t_int16_t_init(&h2);
    sfh_uint32_t_int16_t_init(&h3);
    sfh_uint32_t_int16_t_init(&h4);
    sfh_uint32_t_int16_t_insert(&h1, &n1, 1, 0);
    sfh_uint32_t_int16_t_insert(&h1, &n2, 2, 0);
    sfh_uint32_t_int16_t_insert(&h1, &n3, 3, 0);
    sfh_uint32_t_int16_t_insert(&h1, &n4, 4, 0);
    sfh_uint32_t_int16_t_insert(&h2, &m2, 10, 0);
    sfh_uint32_t_int16_t_insert(&h3, &m3, 11, 0);
    sfh_uint32_t_int16_t_insert(&h4, &m4, 12, 0);
    sfh_uint32_t_int16_t_meld(&h1, &h2, &merged);
    sfh_uint32_t_int16_t_meld(merged, &h3, &merged);
    sfh_uint32_t_int16_t_meld(merged, &h4, &merged);
    sfh_uint32_t_int16_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint32_t_int16_t_node_t large_nodes[1000];
    sfh_uint32_t_int16_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint32_t_int16_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint32_t_int16_t_decrease_key(&heap, &large_nodes[i],
                                        large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint32_t_int16_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint32_t_int32_t(void) {
  sfh_uint32_t_int32_t_heap_t heap;
  sfh_uint32_t_int32_t_node_t node;
  sfh_uint32_t_int32_t_node_t *out_node;
  sfh_uint32_t_int32_t_heap_t *out_heap;
  int is_empty;
  sfh_uint32_t_int32_t_error_t rc;
  int i;

  rc = sfh_uint32_t_int32_t_init(NULL);
  ASSERT_EQ(sfh_uint32_t_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_int32_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint32_t_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_int32_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint32_t_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_int32_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint32_t_int32_t_ERR_NULL_ARG, rc);

  sfh_uint32_t_int32_t_init(&heap);

  {
    sfh_uint32_t_int32_t_node_t n1, n2, n3;
    rc = sfh_uint32_t_int32_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint32_t_int32_t_SUCCESS, rc);
    rc = sfh_uint32_t_int32_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint32_t_int32_t_SUCCESS, rc);
    rc = sfh_uint32_t_int32_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint32_t_int32_t_SUCCESS, rc);
    rc = sfh_uint32_t_int32_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint32_t_int32_t_SUCCESS, rc);
    rc = sfh_uint32_t_int32_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint32_t_int32_t_SUCCESS, rc);
    rc = sfh_uint32_t_int32_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint32_t_int32_t_SUCCESS, rc);
  }

  {
    sfh_uint32_t_int32_t_node_t nodes[100];
    sfh_uint32_t_int32_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint32_t_int32_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint32_t_int32_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint32_t_int32_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint32_t_int32_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint32_t_int32_t_init(&h1);
    sfh_uint32_t_int32_t_init(&h2);
    sfh_uint32_t_int32_t_init(&h3);
    sfh_uint32_t_int32_t_init(&h4);
    sfh_uint32_t_int32_t_insert(&h1, &n1, 1, 0);
    sfh_uint32_t_int32_t_insert(&h1, &n2, 2, 0);
    sfh_uint32_t_int32_t_insert(&h1, &n3, 3, 0);
    sfh_uint32_t_int32_t_insert(&h1, &n4, 4, 0);
    sfh_uint32_t_int32_t_insert(&h2, &m2, 10, 0);
    sfh_uint32_t_int32_t_insert(&h3, &m3, 11, 0);
    sfh_uint32_t_int32_t_insert(&h4, &m4, 12, 0);
    sfh_uint32_t_int32_t_meld(&h1, &h2, &merged);
    sfh_uint32_t_int32_t_meld(merged, &h3, &merged);
    sfh_uint32_t_int32_t_meld(merged, &h4, &merged);
    sfh_uint32_t_int32_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint32_t_int32_t_node_t large_nodes[1000];
    sfh_uint32_t_int32_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint32_t_int32_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint32_t_int32_t_decrease_key(&heap, &large_nodes[i],
                                        large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint32_t_int32_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint32_t_int64_t(void) {
  sfh_uint32_t_int64_t_heap_t heap;
  sfh_uint32_t_int64_t_node_t node;
  sfh_uint32_t_int64_t_node_t *out_node;
  sfh_uint32_t_int64_t_heap_t *out_heap;
  int is_empty;
  sfh_uint32_t_int64_t_error_t rc;
  int i;

  rc = sfh_uint32_t_int64_t_init(NULL);
  ASSERT_EQ(sfh_uint32_t_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_int64_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint32_t_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_int64_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint32_t_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_int64_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint32_t_int64_t_ERR_NULL_ARG, rc);

  sfh_uint32_t_int64_t_init(&heap);

  {
    sfh_uint32_t_int64_t_node_t n1, n2, n3;
    rc = sfh_uint32_t_int64_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint32_t_int64_t_SUCCESS, rc);
    rc = sfh_uint32_t_int64_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint32_t_int64_t_SUCCESS, rc);
    rc = sfh_uint32_t_int64_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint32_t_int64_t_SUCCESS, rc);
    rc = sfh_uint32_t_int64_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint32_t_int64_t_SUCCESS, rc);
    rc = sfh_uint32_t_int64_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint32_t_int64_t_SUCCESS, rc);
    rc = sfh_uint32_t_int64_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint32_t_int64_t_SUCCESS, rc);
  }

  {
    sfh_uint32_t_int64_t_node_t nodes[100];
    sfh_uint32_t_int64_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint32_t_int64_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint32_t_int64_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint32_t_int64_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint32_t_int64_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint32_t_int64_t_init(&h1);
    sfh_uint32_t_int64_t_init(&h2);
    sfh_uint32_t_int64_t_init(&h3);
    sfh_uint32_t_int64_t_init(&h4);
    sfh_uint32_t_int64_t_insert(&h1, &n1, 1, 0);
    sfh_uint32_t_int64_t_insert(&h1, &n2, 2, 0);
    sfh_uint32_t_int64_t_insert(&h1, &n3, 3, 0);
    sfh_uint32_t_int64_t_insert(&h1, &n4, 4, 0);
    sfh_uint32_t_int64_t_insert(&h2, &m2, 10, 0);
    sfh_uint32_t_int64_t_insert(&h3, &m3, 11, 0);
    sfh_uint32_t_int64_t_insert(&h4, &m4, 12, 0);
    sfh_uint32_t_int64_t_meld(&h1, &h2, &merged);
    sfh_uint32_t_int64_t_meld(merged, &h3, &merged);
    sfh_uint32_t_int64_t_meld(merged, &h4, &merged);
    sfh_uint32_t_int64_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint32_t_int64_t_node_t large_nodes[1000];
    sfh_uint32_t_int64_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint32_t_int64_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint32_t_int64_t_decrease_key(&heap, &large_nodes[i],
                                        large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint32_t_int64_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint32_t_uint8_t(void) {
  sfh_uint32_t_uint8_t_heap_t heap;
  sfh_uint32_t_uint8_t_node_t node;
  sfh_uint32_t_uint8_t_node_t *out_node;
  sfh_uint32_t_uint8_t_heap_t *out_heap;
  int is_empty;
  sfh_uint32_t_uint8_t_error_t rc;
  int i;

  rc = sfh_uint32_t_uint8_t_init(NULL);
  ASSERT_EQ(sfh_uint32_t_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_uint8_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint32_t_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_uint8_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint32_t_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_uint8_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint32_t_uint8_t_ERR_NULL_ARG, rc);

  sfh_uint32_t_uint8_t_init(&heap);

  {
    sfh_uint32_t_uint8_t_node_t n1, n2, n3;
    rc = sfh_uint32_t_uint8_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint32_t_uint8_t_SUCCESS, rc);
    rc = sfh_uint32_t_uint8_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint32_t_uint8_t_SUCCESS, rc);
    rc = sfh_uint32_t_uint8_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint32_t_uint8_t_SUCCESS, rc);
    rc = sfh_uint32_t_uint8_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint32_t_uint8_t_SUCCESS, rc);
    rc = sfh_uint32_t_uint8_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint32_t_uint8_t_SUCCESS, rc);
    rc = sfh_uint32_t_uint8_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint32_t_uint8_t_SUCCESS, rc);
  }

  {
    sfh_uint32_t_uint8_t_node_t nodes[100];
    sfh_uint32_t_uint8_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint32_t_uint8_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint32_t_uint8_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint32_t_uint8_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint32_t_uint8_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint32_t_uint8_t_init(&h1);
    sfh_uint32_t_uint8_t_init(&h2);
    sfh_uint32_t_uint8_t_init(&h3);
    sfh_uint32_t_uint8_t_init(&h4);
    sfh_uint32_t_uint8_t_insert(&h1, &n1, 1, 0);
    sfh_uint32_t_uint8_t_insert(&h1, &n2, 2, 0);
    sfh_uint32_t_uint8_t_insert(&h1, &n3, 3, 0);
    sfh_uint32_t_uint8_t_insert(&h1, &n4, 4, 0);
    sfh_uint32_t_uint8_t_insert(&h2, &m2, 10, 0);
    sfh_uint32_t_uint8_t_insert(&h3, &m3, 11, 0);
    sfh_uint32_t_uint8_t_insert(&h4, &m4, 12, 0);
    sfh_uint32_t_uint8_t_meld(&h1, &h2, &merged);
    sfh_uint32_t_uint8_t_meld(merged, &h3, &merged);
    sfh_uint32_t_uint8_t_meld(merged, &h4, &merged);
    sfh_uint32_t_uint8_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint32_t_uint8_t_node_t large_nodes[1000];
    sfh_uint32_t_uint8_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint32_t_uint8_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint32_t_uint8_t_decrease_key(&heap, &large_nodes[i],
                                        large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint32_t_uint8_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint32_t_uint16_t(void) {
  sfh_uint32_t_uint16_t_heap_t heap;
  sfh_uint32_t_uint16_t_node_t node;
  sfh_uint32_t_uint16_t_node_t *out_node;
  sfh_uint32_t_uint16_t_heap_t *out_heap;
  int is_empty;
  sfh_uint32_t_uint16_t_error_t rc;
  int i;

  rc = sfh_uint32_t_uint16_t_init(NULL);
  ASSERT_EQ(sfh_uint32_t_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_uint16_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint32_t_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_uint16_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint32_t_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_uint16_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint32_t_uint16_t_ERR_NULL_ARG, rc);

  sfh_uint32_t_uint16_t_init(&heap);

  {
    sfh_uint32_t_uint16_t_node_t n1, n2, n3;
    rc = sfh_uint32_t_uint16_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint32_t_uint16_t_SUCCESS, rc);
    rc = sfh_uint32_t_uint16_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint32_t_uint16_t_SUCCESS, rc);
    rc = sfh_uint32_t_uint16_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint32_t_uint16_t_SUCCESS, rc);
    rc = sfh_uint32_t_uint16_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint32_t_uint16_t_SUCCESS, rc);
    rc = sfh_uint32_t_uint16_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint32_t_uint16_t_SUCCESS, rc);
    rc = sfh_uint32_t_uint16_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint32_t_uint16_t_SUCCESS, rc);
  }

  {
    sfh_uint32_t_uint16_t_node_t nodes[100];
    sfh_uint32_t_uint16_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint32_t_uint16_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint32_t_uint16_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint32_t_uint16_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint32_t_uint16_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint32_t_uint16_t_init(&h1);
    sfh_uint32_t_uint16_t_init(&h2);
    sfh_uint32_t_uint16_t_init(&h3);
    sfh_uint32_t_uint16_t_init(&h4);
    sfh_uint32_t_uint16_t_insert(&h1, &n1, 1, 0);
    sfh_uint32_t_uint16_t_insert(&h1, &n2, 2, 0);
    sfh_uint32_t_uint16_t_insert(&h1, &n3, 3, 0);
    sfh_uint32_t_uint16_t_insert(&h1, &n4, 4, 0);
    sfh_uint32_t_uint16_t_insert(&h2, &m2, 10, 0);
    sfh_uint32_t_uint16_t_insert(&h3, &m3, 11, 0);
    sfh_uint32_t_uint16_t_insert(&h4, &m4, 12, 0);
    sfh_uint32_t_uint16_t_meld(&h1, &h2, &merged);
    sfh_uint32_t_uint16_t_meld(merged, &h3, &merged);
    sfh_uint32_t_uint16_t_meld(merged, &h4, &merged);
    sfh_uint32_t_uint16_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint32_t_uint16_t_node_t large_nodes[1000];
    sfh_uint32_t_uint16_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint32_t_uint16_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint32_t_uint16_t_decrease_key(&heap, &large_nodes[i],
                                         large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint32_t_uint16_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint32_t_uint32_t(void) {
  sfh_uint32_t_uint32_t_heap_t heap;
  sfh_uint32_t_uint32_t_node_t node;
  sfh_uint32_t_uint32_t_node_t *out_node;
  sfh_uint32_t_uint32_t_heap_t *out_heap;
  int is_empty;
  sfh_uint32_t_uint32_t_error_t rc;
  int i;

  rc = sfh_uint32_t_uint32_t_init(NULL);
  ASSERT_EQ(sfh_uint32_t_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_uint32_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint32_t_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_uint32_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint32_t_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_uint32_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint32_t_uint32_t_ERR_NULL_ARG, rc);

  sfh_uint32_t_uint32_t_init(&heap);

  {
    sfh_uint32_t_uint32_t_node_t n1, n2, n3;
    rc = sfh_uint32_t_uint32_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint32_t_uint32_t_SUCCESS, rc);
    rc = sfh_uint32_t_uint32_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint32_t_uint32_t_SUCCESS, rc);
    rc = sfh_uint32_t_uint32_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint32_t_uint32_t_SUCCESS, rc);
    rc = sfh_uint32_t_uint32_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint32_t_uint32_t_SUCCESS, rc);
    rc = sfh_uint32_t_uint32_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint32_t_uint32_t_SUCCESS, rc);
    rc = sfh_uint32_t_uint32_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint32_t_uint32_t_SUCCESS, rc);
  }

  {
    sfh_uint32_t_uint32_t_node_t nodes[100];
    sfh_uint32_t_uint32_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint32_t_uint32_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint32_t_uint32_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint32_t_uint32_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint32_t_uint32_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint32_t_uint32_t_init(&h1);
    sfh_uint32_t_uint32_t_init(&h2);
    sfh_uint32_t_uint32_t_init(&h3);
    sfh_uint32_t_uint32_t_init(&h4);
    sfh_uint32_t_uint32_t_insert(&h1, &n1, 1, 0);
    sfh_uint32_t_uint32_t_insert(&h1, &n2, 2, 0);
    sfh_uint32_t_uint32_t_insert(&h1, &n3, 3, 0);
    sfh_uint32_t_uint32_t_insert(&h1, &n4, 4, 0);
    sfh_uint32_t_uint32_t_insert(&h2, &m2, 10, 0);
    sfh_uint32_t_uint32_t_insert(&h3, &m3, 11, 0);
    sfh_uint32_t_uint32_t_insert(&h4, &m4, 12, 0);
    sfh_uint32_t_uint32_t_meld(&h1, &h2, &merged);
    sfh_uint32_t_uint32_t_meld(merged, &h3, &merged);
    sfh_uint32_t_uint32_t_meld(merged, &h4, &merged);
    sfh_uint32_t_uint32_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint32_t_uint32_t_node_t large_nodes[1000];
    sfh_uint32_t_uint32_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint32_t_uint32_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint32_t_uint32_t_decrease_key(&heap, &large_nodes[i],
                                         large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint32_t_uint32_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint32_t_uint64_t(void) {
  sfh_uint32_t_uint64_t_heap_t heap;
  sfh_uint32_t_uint64_t_node_t node;
  sfh_uint32_t_uint64_t_node_t *out_node;
  sfh_uint32_t_uint64_t_heap_t *out_heap;
  int is_empty;
  sfh_uint32_t_uint64_t_error_t rc;
  int i;

  rc = sfh_uint32_t_uint64_t_init(NULL);
  ASSERT_EQ(sfh_uint32_t_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_uint64_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint32_t_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_uint64_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint32_t_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_uint64_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint32_t_uint64_t_ERR_NULL_ARG, rc);

  sfh_uint32_t_uint64_t_init(&heap);

  {
    sfh_uint32_t_uint64_t_node_t n1, n2, n3;
    rc = sfh_uint32_t_uint64_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint32_t_uint64_t_SUCCESS, rc);
    rc = sfh_uint32_t_uint64_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint32_t_uint64_t_SUCCESS, rc);
    rc = sfh_uint32_t_uint64_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint32_t_uint64_t_SUCCESS, rc);
    rc = sfh_uint32_t_uint64_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint32_t_uint64_t_SUCCESS, rc);
    rc = sfh_uint32_t_uint64_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint32_t_uint64_t_SUCCESS, rc);
    rc = sfh_uint32_t_uint64_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint32_t_uint64_t_SUCCESS, rc);
  }

  {
    sfh_uint32_t_uint64_t_node_t nodes[100];
    sfh_uint32_t_uint64_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint32_t_uint64_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint32_t_uint64_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint32_t_uint64_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint32_t_uint64_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint32_t_uint64_t_init(&h1);
    sfh_uint32_t_uint64_t_init(&h2);
    sfh_uint32_t_uint64_t_init(&h3);
    sfh_uint32_t_uint64_t_init(&h4);
    sfh_uint32_t_uint64_t_insert(&h1, &n1, 1, 0);
    sfh_uint32_t_uint64_t_insert(&h1, &n2, 2, 0);
    sfh_uint32_t_uint64_t_insert(&h1, &n3, 3, 0);
    sfh_uint32_t_uint64_t_insert(&h1, &n4, 4, 0);
    sfh_uint32_t_uint64_t_insert(&h2, &m2, 10, 0);
    sfh_uint32_t_uint64_t_insert(&h3, &m3, 11, 0);
    sfh_uint32_t_uint64_t_insert(&h4, &m4, 12, 0);
    sfh_uint32_t_uint64_t_meld(&h1, &h2, &merged);
    sfh_uint32_t_uint64_t_meld(merged, &h3, &merged);
    sfh_uint32_t_uint64_t_meld(merged, &h4, &merged);
    sfh_uint32_t_uint64_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint32_t_uint64_t_node_t large_nodes[1000];
    sfh_uint32_t_uint64_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint32_t_uint64_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint32_t_uint64_t_decrease_key(&heap, &large_nodes[i],
                                         large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint32_t_uint64_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint32_t_float(void) {
  sfh_uint32_t_float_heap_t heap;
  sfh_uint32_t_float_node_t node;
  sfh_uint32_t_float_node_t *out_node;
  sfh_uint32_t_float_heap_t *out_heap;
  int is_empty;
  sfh_uint32_t_float_error_t rc;
  int i;

  rc = sfh_uint32_t_float_init(NULL);
  ASSERT_EQ(sfh_uint32_t_float_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_float_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint32_t_float_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_float_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint32_t_float_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_float_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint32_t_float_ERR_NULL_ARG, rc);

  sfh_uint32_t_float_init(&heap);

  {
    sfh_uint32_t_float_node_t n1, n2, n3;
    rc = sfh_uint32_t_float_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint32_t_float_SUCCESS, rc);
    rc = sfh_uint32_t_float_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint32_t_float_SUCCESS, rc);
    rc = sfh_uint32_t_float_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint32_t_float_SUCCESS, rc);
    rc = sfh_uint32_t_float_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint32_t_float_SUCCESS, rc);
    rc = sfh_uint32_t_float_delete_min(&heap);
    ASSERT_EQ(sfh_uint32_t_float_SUCCESS, rc);
    rc = sfh_uint32_t_float_delete_min(&heap);
    ASSERT_EQ(sfh_uint32_t_float_SUCCESS, rc);
  }

  {
    sfh_uint32_t_float_node_t nodes[100];
    sfh_uint32_t_float_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint32_t_float_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint32_t_float_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint32_t_float_heap_t h1, h2, h3, h4, *merged;
    sfh_uint32_t_float_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint32_t_float_init(&h1);
    sfh_uint32_t_float_init(&h2);
    sfh_uint32_t_float_init(&h3);
    sfh_uint32_t_float_init(&h4);
    sfh_uint32_t_float_insert(&h1, &n1, 1, 0);
    sfh_uint32_t_float_insert(&h1, &n2, 2, 0);
    sfh_uint32_t_float_insert(&h1, &n3, 3, 0);
    sfh_uint32_t_float_insert(&h1, &n4, 4, 0);
    sfh_uint32_t_float_insert(&h2, &m2, 10, 0);
    sfh_uint32_t_float_insert(&h3, &m3, 11, 0);
    sfh_uint32_t_float_insert(&h4, &m4, 12, 0);
    sfh_uint32_t_float_meld(&h1, &h2, &merged);
    sfh_uint32_t_float_meld(merged, &h3, &merged);
    sfh_uint32_t_float_meld(merged, &h4, &merged);
    sfh_uint32_t_float_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint32_t_float_node_t large_nodes[1000];
    sfh_uint32_t_float_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint32_t_float_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint32_t_float_decrease_key(&heap, &large_nodes[i],
                                      large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint32_t_float_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint32_t_double(void) {
  sfh_uint32_t_double_heap_t heap;
  sfh_uint32_t_double_node_t node;
  sfh_uint32_t_double_node_t *out_node;
  sfh_uint32_t_double_heap_t *out_heap;
  int is_empty;
  sfh_uint32_t_double_error_t rc;
  int i;

  rc = sfh_uint32_t_double_init(NULL);
  ASSERT_EQ(sfh_uint32_t_double_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_double_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint32_t_double_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_double_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint32_t_double_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_double_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint32_t_double_ERR_NULL_ARG, rc);

  sfh_uint32_t_double_init(&heap);

  {
    sfh_uint32_t_double_node_t n1, n2, n3;
    rc = sfh_uint32_t_double_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint32_t_double_SUCCESS, rc);
    rc = sfh_uint32_t_double_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint32_t_double_SUCCESS, rc);
    rc = sfh_uint32_t_double_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint32_t_double_SUCCESS, rc);
    rc = sfh_uint32_t_double_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint32_t_double_SUCCESS, rc);
    rc = sfh_uint32_t_double_delete_min(&heap);
    ASSERT_EQ(sfh_uint32_t_double_SUCCESS, rc);
    rc = sfh_uint32_t_double_delete_min(&heap);
    ASSERT_EQ(sfh_uint32_t_double_SUCCESS, rc);
  }

  {
    sfh_uint32_t_double_node_t nodes[100];
    sfh_uint32_t_double_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint32_t_double_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint32_t_double_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint32_t_double_heap_t h1, h2, h3, h4, *merged;
    sfh_uint32_t_double_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint32_t_double_init(&h1);
    sfh_uint32_t_double_init(&h2);
    sfh_uint32_t_double_init(&h3);
    sfh_uint32_t_double_init(&h4);
    sfh_uint32_t_double_insert(&h1, &n1, 1, 0);
    sfh_uint32_t_double_insert(&h1, &n2, 2, 0);
    sfh_uint32_t_double_insert(&h1, &n3, 3, 0);
    sfh_uint32_t_double_insert(&h1, &n4, 4, 0);
    sfh_uint32_t_double_insert(&h2, &m2, 10, 0);
    sfh_uint32_t_double_insert(&h3, &m3, 11, 0);
    sfh_uint32_t_double_insert(&h4, &m4, 12, 0);
    sfh_uint32_t_double_meld(&h1, &h2, &merged);
    sfh_uint32_t_double_meld(merged, &h3, &merged);
    sfh_uint32_t_double_meld(merged, &h4, &merged);
    sfh_uint32_t_double_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint32_t_double_node_t large_nodes[1000];
    sfh_uint32_t_double_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint32_t_double_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint32_t_double_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint32_t_double_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint32_t_charptr(void) {
  sfh_uint32_t_charptr_heap_t heap;
  sfh_uint32_t_charptr_node_t node;
  sfh_uint32_t_charptr_node_t *out_node;
  sfh_uint32_t_charptr_heap_t *out_heap;
  int is_empty;
  sfh_uint32_t_charptr_error_t rc;
  int i;

  rc = sfh_uint32_t_charptr_init(NULL);
  ASSERT_EQ(sfh_uint32_t_charptr_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_charptr_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint32_t_charptr_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_charptr_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint32_t_charptr_ERR_NULL_ARG, rc);
  rc = sfh_uint32_t_charptr_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint32_t_charptr_ERR_NULL_ARG, rc);

  sfh_uint32_t_charptr_init(&heap);

  {
    sfh_uint32_t_charptr_node_t n1, n2, n3;
    rc = sfh_uint32_t_charptr_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint32_t_charptr_SUCCESS, rc);
    rc = sfh_uint32_t_charptr_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint32_t_charptr_SUCCESS, rc);
    rc = sfh_uint32_t_charptr_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint32_t_charptr_SUCCESS, rc);
    rc = sfh_uint32_t_charptr_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint32_t_charptr_SUCCESS, rc);
    rc = sfh_uint32_t_charptr_delete_min(&heap);
    ASSERT_EQ(sfh_uint32_t_charptr_SUCCESS, rc);
    rc = sfh_uint32_t_charptr_delete_min(&heap);
    ASSERT_EQ(sfh_uint32_t_charptr_SUCCESS, rc);
  }

  {
    sfh_uint32_t_charptr_node_t nodes[100];
    sfh_uint32_t_charptr_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint32_t_charptr_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint32_t_charptr_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint32_t_charptr_heap_t h1, h2, h3, h4, *merged;
    sfh_uint32_t_charptr_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint32_t_charptr_init(&h1);
    sfh_uint32_t_charptr_init(&h2);
    sfh_uint32_t_charptr_init(&h3);
    sfh_uint32_t_charptr_init(&h4);
    sfh_uint32_t_charptr_insert(&h1, &n1, 1, 0);
    sfh_uint32_t_charptr_insert(&h1, &n2, 2, 0);
    sfh_uint32_t_charptr_insert(&h1, &n3, 3, 0);
    sfh_uint32_t_charptr_insert(&h1, &n4, 4, 0);
    sfh_uint32_t_charptr_insert(&h2, &m2, 10, 0);
    sfh_uint32_t_charptr_insert(&h3, &m3, 11, 0);
    sfh_uint32_t_charptr_insert(&h4, &m4, 12, 0);
    sfh_uint32_t_charptr_meld(&h1, &h2, &merged);
    sfh_uint32_t_charptr_meld(merged, &h3, &merged);
    sfh_uint32_t_charptr_meld(merged, &h4, &merged);
    sfh_uint32_t_charptr_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint32_t_charptr_node_t large_nodes[1000];
    sfh_uint32_t_charptr_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint32_t_charptr_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint32_t_charptr_decrease_key(&heap, &large_nodes[i],
                                        large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint32_t_charptr_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint64_t_int8_t(void) {
  sfh_uint64_t_int8_t_heap_t heap;
  sfh_uint64_t_int8_t_node_t node;
  sfh_uint64_t_int8_t_node_t *out_node;
  sfh_uint64_t_int8_t_heap_t *out_heap;
  int is_empty;
  sfh_uint64_t_int8_t_error_t rc;
  int i;

  rc = sfh_uint64_t_int8_t_init(NULL);
  ASSERT_EQ(sfh_uint64_t_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_int8_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint64_t_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_int8_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint64_t_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_int8_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint64_t_int8_t_ERR_NULL_ARG, rc);

  sfh_uint64_t_int8_t_init(&heap);

  {
    sfh_uint64_t_int8_t_node_t n1, n2, n3;
    rc = sfh_uint64_t_int8_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint64_t_int8_t_SUCCESS, rc);
    rc = sfh_uint64_t_int8_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint64_t_int8_t_SUCCESS, rc);
    rc = sfh_uint64_t_int8_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint64_t_int8_t_SUCCESS, rc);
    rc = sfh_uint64_t_int8_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint64_t_int8_t_SUCCESS, rc);
    rc = sfh_uint64_t_int8_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint64_t_int8_t_SUCCESS, rc);
    rc = sfh_uint64_t_int8_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint64_t_int8_t_SUCCESS, rc);
  }

  {
    sfh_uint64_t_int8_t_node_t nodes[100];
    sfh_uint64_t_int8_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint64_t_int8_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint64_t_int8_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint64_t_int8_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint64_t_int8_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint64_t_int8_t_init(&h1);
    sfh_uint64_t_int8_t_init(&h2);
    sfh_uint64_t_int8_t_init(&h3);
    sfh_uint64_t_int8_t_init(&h4);
    sfh_uint64_t_int8_t_insert(&h1, &n1, 1, 0);
    sfh_uint64_t_int8_t_insert(&h1, &n2, 2, 0);
    sfh_uint64_t_int8_t_insert(&h1, &n3, 3, 0);
    sfh_uint64_t_int8_t_insert(&h1, &n4, 4, 0);
    sfh_uint64_t_int8_t_insert(&h2, &m2, 10, 0);
    sfh_uint64_t_int8_t_insert(&h3, &m3, 11, 0);
    sfh_uint64_t_int8_t_insert(&h4, &m4, 12, 0);
    sfh_uint64_t_int8_t_meld(&h1, &h2, &merged);
    sfh_uint64_t_int8_t_meld(merged, &h3, &merged);
    sfh_uint64_t_int8_t_meld(merged, &h4, &merged);
    sfh_uint64_t_int8_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint64_t_int8_t_node_t large_nodes[1000];
    sfh_uint64_t_int8_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint64_t_int8_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint64_t_int8_t_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint64_t_int8_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint64_t_int16_t(void) {
  sfh_uint64_t_int16_t_heap_t heap;
  sfh_uint64_t_int16_t_node_t node;
  sfh_uint64_t_int16_t_node_t *out_node;
  sfh_uint64_t_int16_t_heap_t *out_heap;
  int is_empty;
  sfh_uint64_t_int16_t_error_t rc;
  int i;

  rc = sfh_uint64_t_int16_t_init(NULL);
  ASSERT_EQ(sfh_uint64_t_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_int16_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint64_t_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_int16_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint64_t_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_int16_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint64_t_int16_t_ERR_NULL_ARG, rc);

  sfh_uint64_t_int16_t_init(&heap);

  {
    sfh_uint64_t_int16_t_node_t n1, n2, n3;
    rc = sfh_uint64_t_int16_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint64_t_int16_t_SUCCESS, rc);
    rc = sfh_uint64_t_int16_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint64_t_int16_t_SUCCESS, rc);
    rc = sfh_uint64_t_int16_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint64_t_int16_t_SUCCESS, rc);
    rc = sfh_uint64_t_int16_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint64_t_int16_t_SUCCESS, rc);
    rc = sfh_uint64_t_int16_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint64_t_int16_t_SUCCESS, rc);
    rc = sfh_uint64_t_int16_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint64_t_int16_t_SUCCESS, rc);
  }

  {
    sfh_uint64_t_int16_t_node_t nodes[100];
    sfh_uint64_t_int16_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint64_t_int16_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint64_t_int16_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint64_t_int16_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint64_t_int16_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint64_t_int16_t_init(&h1);
    sfh_uint64_t_int16_t_init(&h2);
    sfh_uint64_t_int16_t_init(&h3);
    sfh_uint64_t_int16_t_init(&h4);
    sfh_uint64_t_int16_t_insert(&h1, &n1, 1, 0);
    sfh_uint64_t_int16_t_insert(&h1, &n2, 2, 0);
    sfh_uint64_t_int16_t_insert(&h1, &n3, 3, 0);
    sfh_uint64_t_int16_t_insert(&h1, &n4, 4, 0);
    sfh_uint64_t_int16_t_insert(&h2, &m2, 10, 0);
    sfh_uint64_t_int16_t_insert(&h3, &m3, 11, 0);
    sfh_uint64_t_int16_t_insert(&h4, &m4, 12, 0);
    sfh_uint64_t_int16_t_meld(&h1, &h2, &merged);
    sfh_uint64_t_int16_t_meld(merged, &h3, &merged);
    sfh_uint64_t_int16_t_meld(merged, &h4, &merged);
    sfh_uint64_t_int16_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint64_t_int16_t_node_t large_nodes[1000];
    sfh_uint64_t_int16_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint64_t_int16_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint64_t_int16_t_decrease_key(&heap, &large_nodes[i],
                                        large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint64_t_int16_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint64_t_int32_t(void) {
  sfh_uint64_t_int32_t_heap_t heap;
  sfh_uint64_t_int32_t_node_t node;
  sfh_uint64_t_int32_t_node_t *out_node;
  sfh_uint64_t_int32_t_heap_t *out_heap;
  int is_empty;
  sfh_uint64_t_int32_t_error_t rc;
  int i;

  rc = sfh_uint64_t_int32_t_init(NULL);
  ASSERT_EQ(sfh_uint64_t_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_int32_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint64_t_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_int32_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint64_t_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_int32_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint64_t_int32_t_ERR_NULL_ARG, rc);

  sfh_uint64_t_int32_t_init(&heap);

  {
    sfh_uint64_t_int32_t_node_t n1, n2, n3;
    rc = sfh_uint64_t_int32_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint64_t_int32_t_SUCCESS, rc);
    rc = sfh_uint64_t_int32_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint64_t_int32_t_SUCCESS, rc);
    rc = sfh_uint64_t_int32_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint64_t_int32_t_SUCCESS, rc);
    rc = sfh_uint64_t_int32_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint64_t_int32_t_SUCCESS, rc);
    rc = sfh_uint64_t_int32_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint64_t_int32_t_SUCCESS, rc);
    rc = sfh_uint64_t_int32_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint64_t_int32_t_SUCCESS, rc);
  }

  {
    sfh_uint64_t_int32_t_node_t nodes[100];
    sfh_uint64_t_int32_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint64_t_int32_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint64_t_int32_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint64_t_int32_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint64_t_int32_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint64_t_int32_t_init(&h1);
    sfh_uint64_t_int32_t_init(&h2);
    sfh_uint64_t_int32_t_init(&h3);
    sfh_uint64_t_int32_t_init(&h4);
    sfh_uint64_t_int32_t_insert(&h1, &n1, 1, 0);
    sfh_uint64_t_int32_t_insert(&h1, &n2, 2, 0);
    sfh_uint64_t_int32_t_insert(&h1, &n3, 3, 0);
    sfh_uint64_t_int32_t_insert(&h1, &n4, 4, 0);
    sfh_uint64_t_int32_t_insert(&h2, &m2, 10, 0);
    sfh_uint64_t_int32_t_insert(&h3, &m3, 11, 0);
    sfh_uint64_t_int32_t_insert(&h4, &m4, 12, 0);
    sfh_uint64_t_int32_t_meld(&h1, &h2, &merged);
    sfh_uint64_t_int32_t_meld(merged, &h3, &merged);
    sfh_uint64_t_int32_t_meld(merged, &h4, &merged);
    sfh_uint64_t_int32_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint64_t_int32_t_node_t large_nodes[1000];
    sfh_uint64_t_int32_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint64_t_int32_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint64_t_int32_t_decrease_key(&heap, &large_nodes[i],
                                        large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint64_t_int32_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint64_t_int64_t(void) {
  sfh_uint64_t_int64_t_heap_t heap;
  sfh_uint64_t_int64_t_node_t node;
  sfh_uint64_t_int64_t_node_t *out_node;
  sfh_uint64_t_int64_t_heap_t *out_heap;
  int is_empty;
  sfh_uint64_t_int64_t_error_t rc;
  int i;

  rc = sfh_uint64_t_int64_t_init(NULL);
  ASSERT_EQ(sfh_uint64_t_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_int64_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint64_t_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_int64_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint64_t_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_int64_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint64_t_int64_t_ERR_NULL_ARG, rc);

  sfh_uint64_t_int64_t_init(&heap);

  {
    sfh_uint64_t_int64_t_node_t n1, n2, n3;
    rc = sfh_uint64_t_int64_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint64_t_int64_t_SUCCESS, rc);
    rc = sfh_uint64_t_int64_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint64_t_int64_t_SUCCESS, rc);
    rc = sfh_uint64_t_int64_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint64_t_int64_t_SUCCESS, rc);
    rc = sfh_uint64_t_int64_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint64_t_int64_t_SUCCESS, rc);
    rc = sfh_uint64_t_int64_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint64_t_int64_t_SUCCESS, rc);
    rc = sfh_uint64_t_int64_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint64_t_int64_t_SUCCESS, rc);
  }

  {
    sfh_uint64_t_int64_t_node_t nodes[100];
    sfh_uint64_t_int64_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint64_t_int64_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint64_t_int64_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint64_t_int64_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint64_t_int64_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint64_t_int64_t_init(&h1);
    sfh_uint64_t_int64_t_init(&h2);
    sfh_uint64_t_int64_t_init(&h3);
    sfh_uint64_t_int64_t_init(&h4);
    sfh_uint64_t_int64_t_insert(&h1, &n1, 1, 0);
    sfh_uint64_t_int64_t_insert(&h1, &n2, 2, 0);
    sfh_uint64_t_int64_t_insert(&h1, &n3, 3, 0);
    sfh_uint64_t_int64_t_insert(&h1, &n4, 4, 0);
    sfh_uint64_t_int64_t_insert(&h2, &m2, 10, 0);
    sfh_uint64_t_int64_t_insert(&h3, &m3, 11, 0);
    sfh_uint64_t_int64_t_insert(&h4, &m4, 12, 0);
    sfh_uint64_t_int64_t_meld(&h1, &h2, &merged);
    sfh_uint64_t_int64_t_meld(merged, &h3, &merged);
    sfh_uint64_t_int64_t_meld(merged, &h4, &merged);
    sfh_uint64_t_int64_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint64_t_int64_t_node_t large_nodes[1000];
    sfh_uint64_t_int64_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint64_t_int64_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint64_t_int64_t_decrease_key(&heap, &large_nodes[i],
                                        large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint64_t_int64_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint64_t_uint8_t(void) {
  sfh_uint64_t_uint8_t_heap_t heap;
  sfh_uint64_t_uint8_t_node_t node;
  sfh_uint64_t_uint8_t_node_t *out_node;
  sfh_uint64_t_uint8_t_heap_t *out_heap;
  int is_empty;
  sfh_uint64_t_uint8_t_error_t rc;
  int i;

  rc = sfh_uint64_t_uint8_t_init(NULL);
  ASSERT_EQ(sfh_uint64_t_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_uint8_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint64_t_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_uint8_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint64_t_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_uint8_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint64_t_uint8_t_ERR_NULL_ARG, rc);

  sfh_uint64_t_uint8_t_init(&heap);

  {
    sfh_uint64_t_uint8_t_node_t n1, n2, n3;
    rc = sfh_uint64_t_uint8_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint64_t_uint8_t_SUCCESS, rc);
    rc = sfh_uint64_t_uint8_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint64_t_uint8_t_SUCCESS, rc);
    rc = sfh_uint64_t_uint8_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint64_t_uint8_t_SUCCESS, rc);
    rc = sfh_uint64_t_uint8_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint64_t_uint8_t_SUCCESS, rc);
    rc = sfh_uint64_t_uint8_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint64_t_uint8_t_SUCCESS, rc);
    rc = sfh_uint64_t_uint8_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint64_t_uint8_t_SUCCESS, rc);
  }

  {
    sfh_uint64_t_uint8_t_node_t nodes[100];
    sfh_uint64_t_uint8_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint64_t_uint8_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint64_t_uint8_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint64_t_uint8_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint64_t_uint8_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint64_t_uint8_t_init(&h1);
    sfh_uint64_t_uint8_t_init(&h2);
    sfh_uint64_t_uint8_t_init(&h3);
    sfh_uint64_t_uint8_t_init(&h4);
    sfh_uint64_t_uint8_t_insert(&h1, &n1, 1, 0);
    sfh_uint64_t_uint8_t_insert(&h1, &n2, 2, 0);
    sfh_uint64_t_uint8_t_insert(&h1, &n3, 3, 0);
    sfh_uint64_t_uint8_t_insert(&h1, &n4, 4, 0);
    sfh_uint64_t_uint8_t_insert(&h2, &m2, 10, 0);
    sfh_uint64_t_uint8_t_insert(&h3, &m3, 11, 0);
    sfh_uint64_t_uint8_t_insert(&h4, &m4, 12, 0);
    sfh_uint64_t_uint8_t_meld(&h1, &h2, &merged);
    sfh_uint64_t_uint8_t_meld(merged, &h3, &merged);
    sfh_uint64_t_uint8_t_meld(merged, &h4, &merged);
    sfh_uint64_t_uint8_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint64_t_uint8_t_node_t large_nodes[1000];
    sfh_uint64_t_uint8_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint64_t_uint8_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint64_t_uint8_t_decrease_key(&heap, &large_nodes[i],
                                        large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint64_t_uint8_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint64_t_uint16_t(void) {
  sfh_uint64_t_uint16_t_heap_t heap;
  sfh_uint64_t_uint16_t_node_t node;
  sfh_uint64_t_uint16_t_node_t *out_node;
  sfh_uint64_t_uint16_t_heap_t *out_heap;
  int is_empty;
  sfh_uint64_t_uint16_t_error_t rc;
  int i;

  rc = sfh_uint64_t_uint16_t_init(NULL);
  ASSERT_EQ(sfh_uint64_t_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_uint16_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint64_t_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_uint16_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint64_t_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_uint16_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint64_t_uint16_t_ERR_NULL_ARG, rc);

  sfh_uint64_t_uint16_t_init(&heap);

  {
    sfh_uint64_t_uint16_t_node_t n1, n2, n3;
    rc = sfh_uint64_t_uint16_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint64_t_uint16_t_SUCCESS, rc);
    rc = sfh_uint64_t_uint16_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint64_t_uint16_t_SUCCESS, rc);
    rc = sfh_uint64_t_uint16_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint64_t_uint16_t_SUCCESS, rc);
    rc = sfh_uint64_t_uint16_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint64_t_uint16_t_SUCCESS, rc);
    rc = sfh_uint64_t_uint16_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint64_t_uint16_t_SUCCESS, rc);
    rc = sfh_uint64_t_uint16_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint64_t_uint16_t_SUCCESS, rc);
  }

  {
    sfh_uint64_t_uint16_t_node_t nodes[100];
    sfh_uint64_t_uint16_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint64_t_uint16_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint64_t_uint16_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint64_t_uint16_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint64_t_uint16_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint64_t_uint16_t_init(&h1);
    sfh_uint64_t_uint16_t_init(&h2);
    sfh_uint64_t_uint16_t_init(&h3);
    sfh_uint64_t_uint16_t_init(&h4);
    sfh_uint64_t_uint16_t_insert(&h1, &n1, 1, 0);
    sfh_uint64_t_uint16_t_insert(&h1, &n2, 2, 0);
    sfh_uint64_t_uint16_t_insert(&h1, &n3, 3, 0);
    sfh_uint64_t_uint16_t_insert(&h1, &n4, 4, 0);
    sfh_uint64_t_uint16_t_insert(&h2, &m2, 10, 0);
    sfh_uint64_t_uint16_t_insert(&h3, &m3, 11, 0);
    sfh_uint64_t_uint16_t_insert(&h4, &m4, 12, 0);
    sfh_uint64_t_uint16_t_meld(&h1, &h2, &merged);
    sfh_uint64_t_uint16_t_meld(merged, &h3, &merged);
    sfh_uint64_t_uint16_t_meld(merged, &h4, &merged);
    sfh_uint64_t_uint16_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint64_t_uint16_t_node_t large_nodes[1000];
    sfh_uint64_t_uint16_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint64_t_uint16_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint64_t_uint16_t_decrease_key(&heap, &large_nodes[i],
                                         large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint64_t_uint16_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint64_t_uint32_t(void) {
  sfh_uint64_t_uint32_t_heap_t heap;
  sfh_uint64_t_uint32_t_node_t node;
  sfh_uint64_t_uint32_t_node_t *out_node;
  sfh_uint64_t_uint32_t_heap_t *out_heap;
  int is_empty;
  sfh_uint64_t_uint32_t_error_t rc;
  int i;

  rc = sfh_uint64_t_uint32_t_init(NULL);
  ASSERT_EQ(sfh_uint64_t_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_uint32_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint64_t_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_uint32_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint64_t_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_uint32_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint64_t_uint32_t_ERR_NULL_ARG, rc);

  sfh_uint64_t_uint32_t_init(&heap);

  {
    sfh_uint64_t_uint32_t_node_t n1, n2, n3;
    rc = sfh_uint64_t_uint32_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint64_t_uint32_t_SUCCESS, rc);
    rc = sfh_uint64_t_uint32_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint64_t_uint32_t_SUCCESS, rc);
    rc = sfh_uint64_t_uint32_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint64_t_uint32_t_SUCCESS, rc);
    rc = sfh_uint64_t_uint32_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint64_t_uint32_t_SUCCESS, rc);
    rc = sfh_uint64_t_uint32_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint64_t_uint32_t_SUCCESS, rc);
    rc = sfh_uint64_t_uint32_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint64_t_uint32_t_SUCCESS, rc);
  }

  {
    sfh_uint64_t_uint32_t_node_t nodes[100];
    sfh_uint64_t_uint32_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint64_t_uint32_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint64_t_uint32_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint64_t_uint32_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint64_t_uint32_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint64_t_uint32_t_init(&h1);
    sfh_uint64_t_uint32_t_init(&h2);
    sfh_uint64_t_uint32_t_init(&h3);
    sfh_uint64_t_uint32_t_init(&h4);
    sfh_uint64_t_uint32_t_insert(&h1, &n1, 1, 0);
    sfh_uint64_t_uint32_t_insert(&h1, &n2, 2, 0);
    sfh_uint64_t_uint32_t_insert(&h1, &n3, 3, 0);
    sfh_uint64_t_uint32_t_insert(&h1, &n4, 4, 0);
    sfh_uint64_t_uint32_t_insert(&h2, &m2, 10, 0);
    sfh_uint64_t_uint32_t_insert(&h3, &m3, 11, 0);
    sfh_uint64_t_uint32_t_insert(&h4, &m4, 12, 0);
    sfh_uint64_t_uint32_t_meld(&h1, &h2, &merged);
    sfh_uint64_t_uint32_t_meld(merged, &h3, &merged);
    sfh_uint64_t_uint32_t_meld(merged, &h4, &merged);
    sfh_uint64_t_uint32_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint64_t_uint32_t_node_t large_nodes[1000];
    sfh_uint64_t_uint32_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint64_t_uint32_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint64_t_uint32_t_decrease_key(&heap, &large_nodes[i],
                                         large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint64_t_uint32_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint64_t_uint64_t(void) {
  sfh_uint64_t_uint64_t_heap_t heap;
  sfh_uint64_t_uint64_t_node_t node;
  sfh_uint64_t_uint64_t_node_t *out_node;
  sfh_uint64_t_uint64_t_heap_t *out_heap;
  int is_empty;
  sfh_uint64_t_uint64_t_error_t rc;
  int i;

  rc = sfh_uint64_t_uint64_t_init(NULL);
  ASSERT_EQ(sfh_uint64_t_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_uint64_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint64_t_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_uint64_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint64_t_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_uint64_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint64_t_uint64_t_ERR_NULL_ARG, rc);

  sfh_uint64_t_uint64_t_init(&heap);

  {
    sfh_uint64_t_uint64_t_node_t n1, n2, n3;
    rc = sfh_uint64_t_uint64_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint64_t_uint64_t_SUCCESS, rc);
    rc = sfh_uint64_t_uint64_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint64_t_uint64_t_SUCCESS, rc);
    rc = sfh_uint64_t_uint64_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint64_t_uint64_t_SUCCESS, rc);
    rc = sfh_uint64_t_uint64_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint64_t_uint64_t_SUCCESS, rc);
    rc = sfh_uint64_t_uint64_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint64_t_uint64_t_SUCCESS, rc);
    rc = sfh_uint64_t_uint64_t_delete_min(&heap);
    ASSERT_EQ(sfh_uint64_t_uint64_t_SUCCESS, rc);
  }

  {
    sfh_uint64_t_uint64_t_node_t nodes[100];
    sfh_uint64_t_uint64_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint64_t_uint64_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint64_t_uint64_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint64_t_uint64_t_heap_t h1, h2, h3, h4, *merged;
    sfh_uint64_t_uint64_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint64_t_uint64_t_init(&h1);
    sfh_uint64_t_uint64_t_init(&h2);
    sfh_uint64_t_uint64_t_init(&h3);
    sfh_uint64_t_uint64_t_init(&h4);
    sfh_uint64_t_uint64_t_insert(&h1, &n1, 1, 0);
    sfh_uint64_t_uint64_t_insert(&h1, &n2, 2, 0);
    sfh_uint64_t_uint64_t_insert(&h1, &n3, 3, 0);
    sfh_uint64_t_uint64_t_insert(&h1, &n4, 4, 0);
    sfh_uint64_t_uint64_t_insert(&h2, &m2, 10, 0);
    sfh_uint64_t_uint64_t_insert(&h3, &m3, 11, 0);
    sfh_uint64_t_uint64_t_insert(&h4, &m4, 12, 0);
    sfh_uint64_t_uint64_t_meld(&h1, &h2, &merged);
    sfh_uint64_t_uint64_t_meld(merged, &h3, &merged);
    sfh_uint64_t_uint64_t_meld(merged, &h4, &merged);
    sfh_uint64_t_uint64_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint64_t_uint64_t_node_t large_nodes[1000];
    sfh_uint64_t_uint64_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint64_t_uint64_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint64_t_uint64_t_decrease_key(&heap, &large_nodes[i],
                                         large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint64_t_uint64_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint64_t_float(void) {
  sfh_uint64_t_float_heap_t heap;
  sfh_uint64_t_float_node_t node;
  sfh_uint64_t_float_node_t *out_node;
  sfh_uint64_t_float_heap_t *out_heap;
  int is_empty;
  sfh_uint64_t_float_error_t rc;
  int i;

  rc = sfh_uint64_t_float_init(NULL);
  ASSERT_EQ(sfh_uint64_t_float_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_float_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint64_t_float_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_float_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint64_t_float_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_float_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint64_t_float_ERR_NULL_ARG, rc);

  sfh_uint64_t_float_init(&heap);

  {
    sfh_uint64_t_float_node_t n1, n2, n3;
    rc = sfh_uint64_t_float_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint64_t_float_SUCCESS, rc);
    rc = sfh_uint64_t_float_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint64_t_float_SUCCESS, rc);
    rc = sfh_uint64_t_float_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint64_t_float_SUCCESS, rc);
    rc = sfh_uint64_t_float_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint64_t_float_SUCCESS, rc);
    rc = sfh_uint64_t_float_delete_min(&heap);
    ASSERT_EQ(sfh_uint64_t_float_SUCCESS, rc);
    rc = sfh_uint64_t_float_delete_min(&heap);
    ASSERT_EQ(sfh_uint64_t_float_SUCCESS, rc);
  }

  {
    sfh_uint64_t_float_node_t nodes[100];
    sfh_uint64_t_float_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint64_t_float_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint64_t_float_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint64_t_float_heap_t h1, h2, h3, h4, *merged;
    sfh_uint64_t_float_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint64_t_float_init(&h1);
    sfh_uint64_t_float_init(&h2);
    sfh_uint64_t_float_init(&h3);
    sfh_uint64_t_float_init(&h4);
    sfh_uint64_t_float_insert(&h1, &n1, 1, 0);
    sfh_uint64_t_float_insert(&h1, &n2, 2, 0);
    sfh_uint64_t_float_insert(&h1, &n3, 3, 0);
    sfh_uint64_t_float_insert(&h1, &n4, 4, 0);
    sfh_uint64_t_float_insert(&h2, &m2, 10, 0);
    sfh_uint64_t_float_insert(&h3, &m3, 11, 0);
    sfh_uint64_t_float_insert(&h4, &m4, 12, 0);
    sfh_uint64_t_float_meld(&h1, &h2, &merged);
    sfh_uint64_t_float_meld(merged, &h3, &merged);
    sfh_uint64_t_float_meld(merged, &h4, &merged);
    sfh_uint64_t_float_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint64_t_float_node_t large_nodes[1000];
    sfh_uint64_t_float_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint64_t_float_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint64_t_float_decrease_key(&heap, &large_nodes[i],
                                      large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint64_t_float_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint64_t_double(void) {
  sfh_uint64_t_double_heap_t heap;
  sfh_uint64_t_double_node_t node;
  sfh_uint64_t_double_node_t *out_node;
  sfh_uint64_t_double_heap_t *out_heap;
  int is_empty;
  sfh_uint64_t_double_error_t rc;
  int i;

  rc = sfh_uint64_t_double_init(NULL);
  ASSERT_EQ(sfh_uint64_t_double_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_double_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint64_t_double_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_double_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint64_t_double_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_double_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint64_t_double_ERR_NULL_ARG, rc);

  sfh_uint64_t_double_init(&heap);

  {
    sfh_uint64_t_double_node_t n1, n2, n3;
    rc = sfh_uint64_t_double_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint64_t_double_SUCCESS, rc);
    rc = sfh_uint64_t_double_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint64_t_double_SUCCESS, rc);
    rc = sfh_uint64_t_double_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint64_t_double_SUCCESS, rc);
    rc = sfh_uint64_t_double_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint64_t_double_SUCCESS, rc);
    rc = sfh_uint64_t_double_delete_min(&heap);
    ASSERT_EQ(sfh_uint64_t_double_SUCCESS, rc);
    rc = sfh_uint64_t_double_delete_min(&heap);
    ASSERT_EQ(sfh_uint64_t_double_SUCCESS, rc);
  }

  {
    sfh_uint64_t_double_node_t nodes[100];
    sfh_uint64_t_double_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint64_t_double_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint64_t_double_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint64_t_double_heap_t h1, h2, h3, h4, *merged;
    sfh_uint64_t_double_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint64_t_double_init(&h1);
    sfh_uint64_t_double_init(&h2);
    sfh_uint64_t_double_init(&h3);
    sfh_uint64_t_double_init(&h4);
    sfh_uint64_t_double_insert(&h1, &n1, 1, 0);
    sfh_uint64_t_double_insert(&h1, &n2, 2, 0);
    sfh_uint64_t_double_insert(&h1, &n3, 3, 0);
    sfh_uint64_t_double_insert(&h1, &n4, 4, 0);
    sfh_uint64_t_double_insert(&h2, &m2, 10, 0);
    sfh_uint64_t_double_insert(&h3, &m3, 11, 0);
    sfh_uint64_t_double_insert(&h4, &m4, 12, 0);
    sfh_uint64_t_double_meld(&h1, &h2, &merged);
    sfh_uint64_t_double_meld(merged, &h3, &merged);
    sfh_uint64_t_double_meld(merged, &h4, &merged);
    sfh_uint64_t_double_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint64_t_double_node_t large_nodes[1000];
    sfh_uint64_t_double_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint64_t_double_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint64_t_double_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint64_t_double_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_uint64_t_charptr(void) {
  sfh_uint64_t_charptr_heap_t heap;
  sfh_uint64_t_charptr_node_t node;
  sfh_uint64_t_charptr_node_t *out_node;
  sfh_uint64_t_charptr_heap_t *out_heap;
  int is_empty;
  sfh_uint64_t_charptr_error_t rc;
  int i;

  rc = sfh_uint64_t_charptr_init(NULL);
  ASSERT_EQ(sfh_uint64_t_charptr_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_charptr_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_uint64_t_charptr_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_charptr_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_uint64_t_charptr_ERR_NULL_ARG, rc);
  rc = sfh_uint64_t_charptr_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_uint64_t_charptr_ERR_NULL_ARG, rc);

  sfh_uint64_t_charptr_init(&heap);

  {
    sfh_uint64_t_charptr_node_t n1, n2, n3;
    rc = sfh_uint64_t_charptr_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_uint64_t_charptr_SUCCESS, rc);
    rc = sfh_uint64_t_charptr_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_uint64_t_charptr_SUCCESS, rc);
    rc = sfh_uint64_t_charptr_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_uint64_t_charptr_SUCCESS, rc);
    rc = sfh_uint64_t_charptr_delete(&heap, &n2);
    ASSERT_EQ(sfh_uint64_t_charptr_SUCCESS, rc);
    rc = sfh_uint64_t_charptr_delete_min(&heap);
    ASSERT_EQ(sfh_uint64_t_charptr_SUCCESS, rc);
    rc = sfh_uint64_t_charptr_delete_min(&heap);
    ASSERT_EQ(sfh_uint64_t_charptr_SUCCESS, rc);
  }

  {
    sfh_uint64_t_charptr_node_t nodes[100];
    sfh_uint64_t_charptr_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_uint64_t_charptr_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_uint64_t_charptr_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_uint64_t_charptr_heap_t h1, h2, h3, h4, *merged;
    sfh_uint64_t_charptr_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_uint64_t_charptr_init(&h1);
    sfh_uint64_t_charptr_init(&h2);
    sfh_uint64_t_charptr_init(&h3);
    sfh_uint64_t_charptr_init(&h4);
    sfh_uint64_t_charptr_insert(&h1, &n1, 1, 0);
    sfh_uint64_t_charptr_insert(&h1, &n2, 2, 0);
    sfh_uint64_t_charptr_insert(&h1, &n3, 3, 0);
    sfh_uint64_t_charptr_insert(&h1, &n4, 4, 0);
    sfh_uint64_t_charptr_insert(&h2, &m2, 10, 0);
    sfh_uint64_t_charptr_insert(&h3, &m3, 11, 0);
    sfh_uint64_t_charptr_insert(&h4, &m4, 12, 0);
    sfh_uint64_t_charptr_meld(&h1, &h2, &merged);
    sfh_uint64_t_charptr_meld(merged, &h3, &merged);
    sfh_uint64_t_charptr_meld(merged, &h4, &merged);
    sfh_uint64_t_charptr_decrease_key(merged, &m4, 0);
  }

  {
    sfh_uint64_t_charptr_node_t large_nodes[1000];
    sfh_uint64_t_charptr_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_uint64_t_charptr_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_uint64_t_charptr_decrease_key(&heap, &large_nodes[i],
                                        large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_uint64_t_charptr_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_float_int8_t(void) {
  sfh_float_int8_t_heap_t heap;
  sfh_float_int8_t_node_t node;
  sfh_float_int8_t_node_t *out_node;
  sfh_float_int8_t_heap_t *out_heap;
  int is_empty;
  sfh_float_int8_t_error_t rc;
  int i;

  rc = sfh_float_int8_t_init(NULL);
  ASSERT_EQ(sfh_float_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_float_int8_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_float_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_float_int8_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_float_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_float_int8_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_float_int8_t_ERR_NULL_ARG, rc);

  sfh_float_int8_t_init(&heap);

  {
    sfh_float_int8_t_node_t n1, n2, n3;
    rc = sfh_float_int8_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_float_int8_t_SUCCESS, rc);
    rc = sfh_float_int8_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_float_int8_t_SUCCESS, rc);
    rc = sfh_float_int8_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_float_int8_t_SUCCESS, rc);
    rc = sfh_float_int8_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_float_int8_t_SUCCESS, rc);
    rc = sfh_float_int8_t_delete_min(&heap);
    ASSERT_EQ(sfh_float_int8_t_SUCCESS, rc);
    rc = sfh_float_int8_t_delete_min(&heap);
    ASSERT_EQ(sfh_float_int8_t_SUCCESS, rc);
  }

  {
    sfh_float_int8_t_node_t nodes[100];
    sfh_float_int8_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_float_int8_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_float_int8_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_float_int8_t_heap_t h1, h2, h3, h4, *merged;
    sfh_float_int8_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_float_int8_t_init(&h1);
    sfh_float_int8_t_init(&h2);
    sfh_float_int8_t_init(&h3);
    sfh_float_int8_t_init(&h4);
    sfh_float_int8_t_insert(&h1, &n1, 1, 0);
    sfh_float_int8_t_insert(&h1, &n2, 2, 0);
    sfh_float_int8_t_insert(&h1, &n3, 3, 0);
    sfh_float_int8_t_insert(&h1, &n4, 4, 0);
    sfh_float_int8_t_insert(&h2, &m2, 10, 0);
    sfh_float_int8_t_insert(&h3, &m3, 11, 0);
    sfh_float_int8_t_insert(&h4, &m4, 12, 0);
    sfh_float_int8_t_meld(&h1, &h2, &merged);
    sfh_float_int8_t_meld(merged, &h3, &merged);
    sfh_float_int8_t_meld(merged, &h4, &merged);
    sfh_float_int8_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_float_int8_t_node_t large_nodes[1000];
    sfh_float_int8_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_float_int8_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_float_int8_t_decrease_key(&heap, &large_nodes[i],
                                    large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_float_int8_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_float_int16_t(void) {
  sfh_float_int16_t_heap_t heap;
  sfh_float_int16_t_node_t node;
  sfh_float_int16_t_node_t *out_node;
  sfh_float_int16_t_heap_t *out_heap;
  int is_empty;
  sfh_float_int16_t_error_t rc;
  int i;

  rc = sfh_float_int16_t_init(NULL);
  ASSERT_EQ(sfh_float_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_float_int16_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_float_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_float_int16_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_float_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_float_int16_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_float_int16_t_ERR_NULL_ARG, rc);

  sfh_float_int16_t_init(&heap);

  {
    sfh_float_int16_t_node_t n1, n2, n3;
    rc = sfh_float_int16_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_float_int16_t_SUCCESS, rc);
    rc = sfh_float_int16_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_float_int16_t_SUCCESS, rc);
    rc = sfh_float_int16_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_float_int16_t_SUCCESS, rc);
    rc = sfh_float_int16_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_float_int16_t_SUCCESS, rc);
    rc = sfh_float_int16_t_delete_min(&heap);
    ASSERT_EQ(sfh_float_int16_t_SUCCESS, rc);
    rc = sfh_float_int16_t_delete_min(&heap);
    ASSERT_EQ(sfh_float_int16_t_SUCCESS, rc);
  }

  {
    sfh_float_int16_t_node_t nodes[100];
    sfh_float_int16_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_float_int16_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_float_int16_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_float_int16_t_heap_t h1, h2, h3, h4, *merged;
    sfh_float_int16_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_float_int16_t_init(&h1);
    sfh_float_int16_t_init(&h2);
    sfh_float_int16_t_init(&h3);
    sfh_float_int16_t_init(&h4);
    sfh_float_int16_t_insert(&h1, &n1, 1, 0);
    sfh_float_int16_t_insert(&h1, &n2, 2, 0);
    sfh_float_int16_t_insert(&h1, &n3, 3, 0);
    sfh_float_int16_t_insert(&h1, &n4, 4, 0);
    sfh_float_int16_t_insert(&h2, &m2, 10, 0);
    sfh_float_int16_t_insert(&h3, &m3, 11, 0);
    sfh_float_int16_t_insert(&h4, &m4, 12, 0);
    sfh_float_int16_t_meld(&h1, &h2, &merged);
    sfh_float_int16_t_meld(merged, &h3, &merged);
    sfh_float_int16_t_meld(merged, &h4, &merged);
    sfh_float_int16_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_float_int16_t_node_t large_nodes[1000];
    sfh_float_int16_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_float_int16_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_float_int16_t_decrease_key(&heap, &large_nodes[i],
                                     large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_float_int16_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_float_int32_t(void) {
  sfh_float_int32_t_heap_t heap;
  sfh_float_int32_t_node_t node;
  sfh_float_int32_t_node_t *out_node;
  sfh_float_int32_t_heap_t *out_heap;
  int is_empty;
  sfh_float_int32_t_error_t rc;
  int i;

  rc = sfh_float_int32_t_init(NULL);
  ASSERT_EQ(sfh_float_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_float_int32_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_float_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_float_int32_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_float_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_float_int32_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_float_int32_t_ERR_NULL_ARG, rc);

  sfh_float_int32_t_init(&heap);

  {
    sfh_float_int32_t_node_t n1, n2, n3;
    rc = sfh_float_int32_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_float_int32_t_SUCCESS, rc);
    rc = sfh_float_int32_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_float_int32_t_SUCCESS, rc);
    rc = sfh_float_int32_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_float_int32_t_SUCCESS, rc);
    rc = sfh_float_int32_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_float_int32_t_SUCCESS, rc);
    rc = sfh_float_int32_t_delete_min(&heap);
    ASSERT_EQ(sfh_float_int32_t_SUCCESS, rc);
    rc = sfh_float_int32_t_delete_min(&heap);
    ASSERT_EQ(sfh_float_int32_t_SUCCESS, rc);
  }

  {
    sfh_float_int32_t_node_t nodes[100];
    sfh_float_int32_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_float_int32_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_float_int32_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_float_int32_t_heap_t h1, h2, h3, h4, *merged;
    sfh_float_int32_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_float_int32_t_init(&h1);
    sfh_float_int32_t_init(&h2);
    sfh_float_int32_t_init(&h3);
    sfh_float_int32_t_init(&h4);
    sfh_float_int32_t_insert(&h1, &n1, 1, 0);
    sfh_float_int32_t_insert(&h1, &n2, 2, 0);
    sfh_float_int32_t_insert(&h1, &n3, 3, 0);
    sfh_float_int32_t_insert(&h1, &n4, 4, 0);
    sfh_float_int32_t_insert(&h2, &m2, 10, 0);
    sfh_float_int32_t_insert(&h3, &m3, 11, 0);
    sfh_float_int32_t_insert(&h4, &m4, 12, 0);
    sfh_float_int32_t_meld(&h1, &h2, &merged);
    sfh_float_int32_t_meld(merged, &h3, &merged);
    sfh_float_int32_t_meld(merged, &h4, &merged);
    sfh_float_int32_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_float_int32_t_node_t large_nodes[1000];
    sfh_float_int32_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_float_int32_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_float_int32_t_decrease_key(&heap, &large_nodes[i],
                                     large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_float_int32_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_float_int64_t(void) {
  sfh_float_int64_t_heap_t heap;
  sfh_float_int64_t_node_t node;
  sfh_float_int64_t_node_t *out_node;
  sfh_float_int64_t_heap_t *out_heap;
  int is_empty;
  sfh_float_int64_t_error_t rc;
  int i;

  rc = sfh_float_int64_t_init(NULL);
  ASSERT_EQ(sfh_float_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_float_int64_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_float_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_float_int64_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_float_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_float_int64_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_float_int64_t_ERR_NULL_ARG, rc);

  sfh_float_int64_t_init(&heap);

  {
    sfh_float_int64_t_node_t n1, n2, n3;
    rc = sfh_float_int64_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_float_int64_t_SUCCESS, rc);
    rc = sfh_float_int64_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_float_int64_t_SUCCESS, rc);
    rc = sfh_float_int64_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_float_int64_t_SUCCESS, rc);
    rc = sfh_float_int64_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_float_int64_t_SUCCESS, rc);
    rc = sfh_float_int64_t_delete_min(&heap);
    ASSERT_EQ(sfh_float_int64_t_SUCCESS, rc);
    rc = sfh_float_int64_t_delete_min(&heap);
    ASSERT_EQ(sfh_float_int64_t_SUCCESS, rc);
  }

  {
    sfh_float_int64_t_node_t nodes[100];
    sfh_float_int64_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_float_int64_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_float_int64_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_float_int64_t_heap_t h1, h2, h3, h4, *merged;
    sfh_float_int64_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_float_int64_t_init(&h1);
    sfh_float_int64_t_init(&h2);
    sfh_float_int64_t_init(&h3);
    sfh_float_int64_t_init(&h4);
    sfh_float_int64_t_insert(&h1, &n1, 1, 0);
    sfh_float_int64_t_insert(&h1, &n2, 2, 0);
    sfh_float_int64_t_insert(&h1, &n3, 3, 0);
    sfh_float_int64_t_insert(&h1, &n4, 4, 0);
    sfh_float_int64_t_insert(&h2, &m2, 10, 0);
    sfh_float_int64_t_insert(&h3, &m3, 11, 0);
    sfh_float_int64_t_insert(&h4, &m4, 12, 0);
    sfh_float_int64_t_meld(&h1, &h2, &merged);
    sfh_float_int64_t_meld(merged, &h3, &merged);
    sfh_float_int64_t_meld(merged, &h4, &merged);
    sfh_float_int64_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_float_int64_t_node_t large_nodes[1000];
    sfh_float_int64_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_float_int64_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_float_int64_t_decrease_key(&heap, &large_nodes[i],
                                     large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_float_int64_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_float_uint8_t(void) {
  sfh_float_uint8_t_heap_t heap;
  sfh_float_uint8_t_node_t node;
  sfh_float_uint8_t_node_t *out_node;
  sfh_float_uint8_t_heap_t *out_heap;
  int is_empty;
  sfh_float_uint8_t_error_t rc;
  int i;

  rc = sfh_float_uint8_t_init(NULL);
  ASSERT_EQ(sfh_float_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_float_uint8_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_float_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_float_uint8_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_float_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_float_uint8_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_float_uint8_t_ERR_NULL_ARG, rc);

  sfh_float_uint8_t_init(&heap);

  {
    sfh_float_uint8_t_node_t n1, n2, n3;
    rc = sfh_float_uint8_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_float_uint8_t_SUCCESS, rc);
    rc = sfh_float_uint8_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_float_uint8_t_SUCCESS, rc);
    rc = sfh_float_uint8_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_float_uint8_t_SUCCESS, rc);
    rc = sfh_float_uint8_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_float_uint8_t_SUCCESS, rc);
    rc = sfh_float_uint8_t_delete_min(&heap);
    ASSERT_EQ(sfh_float_uint8_t_SUCCESS, rc);
    rc = sfh_float_uint8_t_delete_min(&heap);
    ASSERT_EQ(sfh_float_uint8_t_SUCCESS, rc);
  }

  {
    sfh_float_uint8_t_node_t nodes[100];
    sfh_float_uint8_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_float_uint8_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_float_uint8_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_float_uint8_t_heap_t h1, h2, h3, h4, *merged;
    sfh_float_uint8_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_float_uint8_t_init(&h1);
    sfh_float_uint8_t_init(&h2);
    sfh_float_uint8_t_init(&h3);
    sfh_float_uint8_t_init(&h4);
    sfh_float_uint8_t_insert(&h1, &n1, 1, 0);
    sfh_float_uint8_t_insert(&h1, &n2, 2, 0);
    sfh_float_uint8_t_insert(&h1, &n3, 3, 0);
    sfh_float_uint8_t_insert(&h1, &n4, 4, 0);
    sfh_float_uint8_t_insert(&h2, &m2, 10, 0);
    sfh_float_uint8_t_insert(&h3, &m3, 11, 0);
    sfh_float_uint8_t_insert(&h4, &m4, 12, 0);
    sfh_float_uint8_t_meld(&h1, &h2, &merged);
    sfh_float_uint8_t_meld(merged, &h3, &merged);
    sfh_float_uint8_t_meld(merged, &h4, &merged);
    sfh_float_uint8_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_float_uint8_t_node_t large_nodes[1000];
    sfh_float_uint8_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_float_uint8_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_float_uint8_t_decrease_key(&heap, &large_nodes[i],
                                     large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_float_uint8_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_float_uint16_t(void) {
  sfh_float_uint16_t_heap_t heap;
  sfh_float_uint16_t_node_t node;
  sfh_float_uint16_t_node_t *out_node;
  sfh_float_uint16_t_heap_t *out_heap;
  int is_empty;
  sfh_float_uint16_t_error_t rc;
  int i;

  rc = sfh_float_uint16_t_init(NULL);
  ASSERT_EQ(sfh_float_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_float_uint16_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_float_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_float_uint16_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_float_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_float_uint16_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_float_uint16_t_ERR_NULL_ARG, rc);

  sfh_float_uint16_t_init(&heap);

  {
    sfh_float_uint16_t_node_t n1, n2, n3;
    rc = sfh_float_uint16_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_float_uint16_t_SUCCESS, rc);
    rc = sfh_float_uint16_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_float_uint16_t_SUCCESS, rc);
    rc = sfh_float_uint16_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_float_uint16_t_SUCCESS, rc);
    rc = sfh_float_uint16_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_float_uint16_t_SUCCESS, rc);
    rc = sfh_float_uint16_t_delete_min(&heap);
    ASSERT_EQ(sfh_float_uint16_t_SUCCESS, rc);
    rc = sfh_float_uint16_t_delete_min(&heap);
    ASSERT_EQ(sfh_float_uint16_t_SUCCESS, rc);
  }

  {
    sfh_float_uint16_t_node_t nodes[100];
    sfh_float_uint16_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_float_uint16_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_float_uint16_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_float_uint16_t_heap_t h1, h2, h3, h4, *merged;
    sfh_float_uint16_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_float_uint16_t_init(&h1);
    sfh_float_uint16_t_init(&h2);
    sfh_float_uint16_t_init(&h3);
    sfh_float_uint16_t_init(&h4);
    sfh_float_uint16_t_insert(&h1, &n1, 1, 0);
    sfh_float_uint16_t_insert(&h1, &n2, 2, 0);
    sfh_float_uint16_t_insert(&h1, &n3, 3, 0);
    sfh_float_uint16_t_insert(&h1, &n4, 4, 0);
    sfh_float_uint16_t_insert(&h2, &m2, 10, 0);
    sfh_float_uint16_t_insert(&h3, &m3, 11, 0);
    sfh_float_uint16_t_insert(&h4, &m4, 12, 0);
    sfh_float_uint16_t_meld(&h1, &h2, &merged);
    sfh_float_uint16_t_meld(merged, &h3, &merged);
    sfh_float_uint16_t_meld(merged, &h4, &merged);
    sfh_float_uint16_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_float_uint16_t_node_t large_nodes[1000];
    sfh_float_uint16_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_float_uint16_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_float_uint16_t_decrease_key(&heap, &large_nodes[i],
                                      large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_float_uint16_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_float_uint32_t(void) {
  sfh_float_uint32_t_heap_t heap;
  sfh_float_uint32_t_node_t node;
  sfh_float_uint32_t_node_t *out_node;
  sfh_float_uint32_t_heap_t *out_heap;
  int is_empty;
  sfh_float_uint32_t_error_t rc;
  int i;

  rc = sfh_float_uint32_t_init(NULL);
  ASSERT_EQ(sfh_float_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_float_uint32_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_float_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_float_uint32_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_float_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_float_uint32_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_float_uint32_t_ERR_NULL_ARG, rc);

  sfh_float_uint32_t_init(&heap);

  {
    sfh_float_uint32_t_node_t n1, n2, n3;
    rc = sfh_float_uint32_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_float_uint32_t_SUCCESS, rc);
    rc = sfh_float_uint32_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_float_uint32_t_SUCCESS, rc);
    rc = sfh_float_uint32_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_float_uint32_t_SUCCESS, rc);
    rc = sfh_float_uint32_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_float_uint32_t_SUCCESS, rc);
    rc = sfh_float_uint32_t_delete_min(&heap);
    ASSERT_EQ(sfh_float_uint32_t_SUCCESS, rc);
    rc = sfh_float_uint32_t_delete_min(&heap);
    ASSERT_EQ(sfh_float_uint32_t_SUCCESS, rc);
  }

  {
    sfh_float_uint32_t_node_t nodes[100];
    sfh_float_uint32_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_float_uint32_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_float_uint32_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_float_uint32_t_heap_t h1, h2, h3, h4, *merged;
    sfh_float_uint32_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_float_uint32_t_init(&h1);
    sfh_float_uint32_t_init(&h2);
    sfh_float_uint32_t_init(&h3);
    sfh_float_uint32_t_init(&h4);
    sfh_float_uint32_t_insert(&h1, &n1, 1, 0);
    sfh_float_uint32_t_insert(&h1, &n2, 2, 0);
    sfh_float_uint32_t_insert(&h1, &n3, 3, 0);
    sfh_float_uint32_t_insert(&h1, &n4, 4, 0);
    sfh_float_uint32_t_insert(&h2, &m2, 10, 0);
    sfh_float_uint32_t_insert(&h3, &m3, 11, 0);
    sfh_float_uint32_t_insert(&h4, &m4, 12, 0);
    sfh_float_uint32_t_meld(&h1, &h2, &merged);
    sfh_float_uint32_t_meld(merged, &h3, &merged);
    sfh_float_uint32_t_meld(merged, &h4, &merged);
    sfh_float_uint32_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_float_uint32_t_node_t large_nodes[1000];
    sfh_float_uint32_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_float_uint32_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_float_uint32_t_decrease_key(&heap, &large_nodes[i],
                                      large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_float_uint32_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_float_uint64_t(void) {
  sfh_float_uint64_t_heap_t heap;
  sfh_float_uint64_t_node_t node;
  sfh_float_uint64_t_node_t *out_node;
  sfh_float_uint64_t_heap_t *out_heap;
  int is_empty;
  sfh_float_uint64_t_error_t rc;
  int i;

  rc = sfh_float_uint64_t_init(NULL);
  ASSERT_EQ(sfh_float_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_float_uint64_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_float_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_float_uint64_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_float_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_float_uint64_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_float_uint64_t_ERR_NULL_ARG, rc);

  sfh_float_uint64_t_init(&heap);

  {
    sfh_float_uint64_t_node_t n1, n2, n3;
    rc = sfh_float_uint64_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_float_uint64_t_SUCCESS, rc);
    rc = sfh_float_uint64_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_float_uint64_t_SUCCESS, rc);
    rc = sfh_float_uint64_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_float_uint64_t_SUCCESS, rc);
    rc = sfh_float_uint64_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_float_uint64_t_SUCCESS, rc);
    rc = sfh_float_uint64_t_delete_min(&heap);
    ASSERT_EQ(sfh_float_uint64_t_SUCCESS, rc);
    rc = sfh_float_uint64_t_delete_min(&heap);
    ASSERT_EQ(sfh_float_uint64_t_SUCCESS, rc);
  }

  {
    sfh_float_uint64_t_node_t nodes[100];
    sfh_float_uint64_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_float_uint64_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_float_uint64_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_float_uint64_t_heap_t h1, h2, h3, h4, *merged;
    sfh_float_uint64_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_float_uint64_t_init(&h1);
    sfh_float_uint64_t_init(&h2);
    sfh_float_uint64_t_init(&h3);
    sfh_float_uint64_t_init(&h4);
    sfh_float_uint64_t_insert(&h1, &n1, 1, 0);
    sfh_float_uint64_t_insert(&h1, &n2, 2, 0);
    sfh_float_uint64_t_insert(&h1, &n3, 3, 0);
    sfh_float_uint64_t_insert(&h1, &n4, 4, 0);
    sfh_float_uint64_t_insert(&h2, &m2, 10, 0);
    sfh_float_uint64_t_insert(&h3, &m3, 11, 0);
    sfh_float_uint64_t_insert(&h4, &m4, 12, 0);
    sfh_float_uint64_t_meld(&h1, &h2, &merged);
    sfh_float_uint64_t_meld(merged, &h3, &merged);
    sfh_float_uint64_t_meld(merged, &h4, &merged);
    sfh_float_uint64_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_float_uint64_t_node_t large_nodes[1000];
    sfh_float_uint64_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_float_uint64_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_float_uint64_t_decrease_key(&heap, &large_nodes[i],
                                      large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_float_uint64_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_float_float(void) {
  sfh_float_float_heap_t heap;
  sfh_float_float_node_t node;
  sfh_float_float_node_t *out_node;
  sfh_float_float_heap_t *out_heap;
  int is_empty;
  sfh_float_float_error_t rc;
  int i;

  rc = sfh_float_float_init(NULL);
  ASSERT_EQ(sfh_float_float_ERR_NULL_ARG, rc);
  rc = sfh_float_float_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_float_float_ERR_NULL_ARG, rc);
  rc = sfh_float_float_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_float_float_ERR_NULL_ARG, rc);
  rc = sfh_float_float_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_float_float_ERR_NULL_ARG, rc);

  sfh_float_float_init(&heap);

  {
    sfh_float_float_node_t n1, n2, n3;
    rc = sfh_float_float_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_float_float_SUCCESS, rc);
    rc = sfh_float_float_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_float_float_SUCCESS, rc);
    rc = sfh_float_float_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_float_float_SUCCESS, rc);
    rc = sfh_float_float_delete(&heap, &n2);
    ASSERT_EQ(sfh_float_float_SUCCESS, rc);
    rc = sfh_float_float_delete_min(&heap);
    ASSERT_EQ(sfh_float_float_SUCCESS, rc);
    rc = sfh_float_float_delete_min(&heap);
    ASSERT_EQ(sfh_float_float_SUCCESS, rc);
  }

  {
    sfh_float_float_node_t nodes[100];
    sfh_float_float_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_float_float_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_float_float_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_float_float_heap_t h1, h2, h3, h4, *merged;
    sfh_float_float_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_float_float_init(&h1);
    sfh_float_float_init(&h2);
    sfh_float_float_init(&h3);
    sfh_float_float_init(&h4);
    sfh_float_float_insert(&h1, &n1, 1, 0);
    sfh_float_float_insert(&h1, &n2, 2, 0);
    sfh_float_float_insert(&h1, &n3, 3, 0);
    sfh_float_float_insert(&h1, &n4, 4, 0);
    sfh_float_float_insert(&h2, &m2, 10, 0);
    sfh_float_float_insert(&h3, &m3, 11, 0);
    sfh_float_float_insert(&h4, &m4, 12, 0);
    sfh_float_float_meld(&h1, &h2, &merged);
    sfh_float_float_meld(merged, &h3, &merged);
    sfh_float_float_meld(merged, &h4, &merged);
    sfh_float_float_decrease_key(merged, &m4, 0);
  }

  {
    sfh_float_float_node_t large_nodes[1000];
    sfh_float_float_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_float_float_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_float_float_decrease_key(&heap, &large_nodes[i],
                                   large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_float_float_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_float_double(void) {
  sfh_float_double_heap_t heap;
  sfh_float_double_node_t node;
  sfh_float_double_node_t *out_node;
  sfh_float_double_heap_t *out_heap;
  int is_empty;
  sfh_float_double_error_t rc;
  int i;

  rc = sfh_float_double_init(NULL);
  ASSERT_EQ(sfh_float_double_ERR_NULL_ARG, rc);
  rc = sfh_float_double_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_float_double_ERR_NULL_ARG, rc);
  rc = sfh_float_double_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_float_double_ERR_NULL_ARG, rc);
  rc = sfh_float_double_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_float_double_ERR_NULL_ARG, rc);

  sfh_float_double_init(&heap);

  {
    sfh_float_double_node_t n1, n2, n3;
    rc = sfh_float_double_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_float_double_SUCCESS, rc);
    rc = sfh_float_double_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_float_double_SUCCESS, rc);
    rc = sfh_float_double_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_float_double_SUCCESS, rc);
    rc = sfh_float_double_delete(&heap, &n2);
    ASSERT_EQ(sfh_float_double_SUCCESS, rc);
    rc = sfh_float_double_delete_min(&heap);
    ASSERT_EQ(sfh_float_double_SUCCESS, rc);
    rc = sfh_float_double_delete_min(&heap);
    ASSERT_EQ(sfh_float_double_SUCCESS, rc);
  }

  {
    sfh_float_double_node_t nodes[100];
    sfh_float_double_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_float_double_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_float_double_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_float_double_heap_t h1, h2, h3, h4, *merged;
    sfh_float_double_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_float_double_init(&h1);
    sfh_float_double_init(&h2);
    sfh_float_double_init(&h3);
    sfh_float_double_init(&h4);
    sfh_float_double_insert(&h1, &n1, 1, 0);
    sfh_float_double_insert(&h1, &n2, 2, 0);
    sfh_float_double_insert(&h1, &n3, 3, 0);
    sfh_float_double_insert(&h1, &n4, 4, 0);
    sfh_float_double_insert(&h2, &m2, 10, 0);
    sfh_float_double_insert(&h3, &m3, 11, 0);
    sfh_float_double_insert(&h4, &m4, 12, 0);
    sfh_float_double_meld(&h1, &h2, &merged);
    sfh_float_double_meld(merged, &h3, &merged);
    sfh_float_double_meld(merged, &h4, &merged);
    sfh_float_double_decrease_key(merged, &m4, 0);
  }

  {
    sfh_float_double_node_t large_nodes[1000];
    sfh_float_double_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_float_double_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_float_double_decrease_key(&heap, &large_nodes[i],
                                    large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_float_double_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_float_charptr(void) {
  sfh_float_charptr_heap_t heap;
  sfh_float_charptr_node_t node;
  sfh_float_charptr_node_t *out_node;
  sfh_float_charptr_heap_t *out_heap;
  int is_empty;
  sfh_float_charptr_error_t rc;
  int i;

  rc = sfh_float_charptr_init(NULL);
  ASSERT_EQ(sfh_float_charptr_ERR_NULL_ARG, rc);
  rc = sfh_float_charptr_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_float_charptr_ERR_NULL_ARG, rc);
  rc = sfh_float_charptr_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_float_charptr_ERR_NULL_ARG, rc);
  rc = sfh_float_charptr_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_float_charptr_ERR_NULL_ARG, rc);

  sfh_float_charptr_init(&heap);

  {
    sfh_float_charptr_node_t n1, n2, n3;
    rc = sfh_float_charptr_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_float_charptr_SUCCESS, rc);
    rc = sfh_float_charptr_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_float_charptr_SUCCESS, rc);
    rc = sfh_float_charptr_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_float_charptr_SUCCESS, rc);
    rc = sfh_float_charptr_delete(&heap, &n2);
    ASSERT_EQ(sfh_float_charptr_SUCCESS, rc);
    rc = sfh_float_charptr_delete_min(&heap);
    ASSERT_EQ(sfh_float_charptr_SUCCESS, rc);
    rc = sfh_float_charptr_delete_min(&heap);
    ASSERT_EQ(sfh_float_charptr_SUCCESS, rc);
  }

  {
    sfh_float_charptr_node_t nodes[100];
    sfh_float_charptr_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_float_charptr_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_float_charptr_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_float_charptr_heap_t h1, h2, h3, h4, *merged;
    sfh_float_charptr_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_float_charptr_init(&h1);
    sfh_float_charptr_init(&h2);
    sfh_float_charptr_init(&h3);
    sfh_float_charptr_init(&h4);
    sfh_float_charptr_insert(&h1, &n1, 1, 0);
    sfh_float_charptr_insert(&h1, &n2, 2, 0);
    sfh_float_charptr_insert(&h1, &n3, 3, 0);
    sfh_float_charptr_insert(&h1, &n4, 4, 0);
    sfh_float_charptr_insert(&h2, &m2, 10, 0);
    sfh_float_charptr_insert(&h3, &m3, 11, 0);
    sfh_float_charptr_insert(&h4, &m4, 12, 0);
    sfh_float_charptr_meld(&h1, &h2, &merged);
    sfh_float_charptr_meld(merged, &h3, &merged);
    sfh_float_charptr_meld(merged, &h4, &merged);
    sfh_float_charptr_decrease_key(merged, &m4, 0);
  }

  {
    sfh_float_charptr_node_t large_nodes[1000];
    sfh_float_charptr_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_float_charptr_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_float_charptr_decrease_key(&heap, &large_nodes[i],
                                     large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_float_charptr_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_double_int8_t(void) {
  sfh_double_int8_t_heap_t heap;
  sfh_double_int8_t_node_t node;
  sfh_double_int8_t_node_t *out_node;
  sfh_double_int8_t_heap_t *out_heap;
  int is_empty;
  sfh_double_int8_t_error_t rc;
  int i;

  rc = sfh_double_int8_t_init(NULL);
  ASSERT_EQ(sfh_double_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_double_int8_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_double_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_double_int8_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_double_int8_t_ERR_NULL_ARG, rc);
  rc = sfh_double_int8_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_double_int8_t_ERR_NULL_ARG, rc);

  sfh_double_int8_t_init(&heap);

  {
    sfh_double_int8_t_node_t n1, n2, n3;
    rc = sfh_double_int8_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_double_int8_t_SUCCESS, rc);
    rc = sfh_double_int8_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_double_int8_t_SUCCESS, rc);
    rc = sfh_double_int8_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_double_int8_t_SUCCESS, rc);
    rc = sfh_double_int8_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_double_int8_t_SUCCESS, rc);
    rc = sfh_double_int8_t_delete_min(&heap);
    ASSERT_EQ(sfh_double_int8_t_SUCCESS, rc);
    rc = sfh_double_int8_t_delete_min(&heap);
    ASSERT_EQ(sfh_double_int8_t_SUCCESS, rc);
  }

  {
    sfh_double_int8_t_node_t nodes[100];
    sfh_double_int8_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_double_int8_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_double_int8_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_double_int8_t_heap_t h1, h2, h3, h4, *merged;
    sfh_double_int8_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_double_int8_t_init(&h1);
    sfh_double_int8_t_init(&h2);
    sfh_double_int8_t_init(&h3);
    sfh_double_int8_t_init(&h4);
    sfh_double_int8_t_insert(&h1, &n1, 1, 0);
    sfh_double_int8_t_insert(&h1, &n2, 2, 0);
    sfh_double_int8_t_insert(&h1, &n3, 3, 0);
    sfh_double_int8_t_insert(&h1, &n4, 4, 0);
    sfh_double_int8_t_insert(&h2, &m2, 10, 0);
    sfh_double_int8_t_insert(&h3, &m3, 11, 0);
    sfh_double_int8_t_insert(&h4, &m4, 12, 0);
    sfh_double_int8_t_meld(&h1, &h2, &merged);
    sfh_double_int8_t_meld(merged, &h3, &merged);
    sfh_double_int8_t_meld(merged, &h4, &merged);
    sfh_double_int8_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_double_int8_t_node_t large_nodes[1000];
    sfh_double_int8_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_double_int8_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_double_int8_t_decrease_key(&heap, &large_nodes[i],
                                     large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_double_int8_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_double_int16_t(void) {
  sfh_double_int16_t_heap_t heap;
  sfh_double_int16_t_node_t node;
  sfh_double_int16_t_node_t *out_node;
  sfh_double_int16_t_heap_t *out_heap;
  int is_empty;
  sfh_double_int16_t_error_t rc;
  int i;

  rc = sfh_double_int16_t_init(NULL);
  ASSERT_EQ(sfh_double_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_double_int16_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_double_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_double_int16_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_double_int16_t_ERR_NULL_ARG, rc);
  rc = sfh_double_int16_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_double_int16_t_ERR_NULL_ARG, rc);

  sfh_double_int16_t_init(&heap);

  {
    sfh_double_int16_t_node_t n1, n2, n3;
    rc = sfh_double_int16_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_double_int16_t_SUCCESS, rc);
    rc = sfh_double_int16_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_double_int16_t_SUCCESS, rc);
    rc = sfh_double_int16_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_double_int16_t_SUCCESS, rc);
    rc = sfh_double_int16_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_double_int16_t_SUCCESS, rc);
    rc = sfh_double_int16_t_delete_min(&heap);
    ASSERT_EQ(sfh_double_int16_t_SUCCESS, rc);
    rc = sfh_double_int16_t_delete_min(&heap);
    ASSERT_EQ(sfh_double_int16_t_SUCCESS, rc);
  }

  {
    sfh_double_int16_t_node_t nodes[100];
    sfh_double_int16_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_double_int16_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_double_int16_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_double_int16_t_heap_t h1, h2, h3, h4, *merged;
    sfh_double_int16_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_double_int16_t_init(&h1);
    sfh_double_int16_t_init(&h2);
    sfh_double_int16_t_init(&h3);
    sfh_double_int16_t_init(&h4);
    sfh_double_int16_t_insert(&h1, &n1, 1, 0);
    sfh_double_int16_t_insert(&h1, &n2, 2, 0);
    sfh_double_int16_t_insert(&h1, &n3, 3, 0);
    sfh_double_int16_t_insert(&h1, &n4, 4, 0);
    sfh_double_int16_t_insert(&h2, &m2, 10, 0);
    sfh_double_int16_t_insert(&h3, &m3, 11, 0);
    sfh_double_int16_t_insert(&h4, &m4, 12, 0);
    sfh_double_int16_t_meld(&h1, &h2, &merged);
    sfh_double_int16_t_meld(merged, &h3, &merged);
    sfh_double_int16_t_meld(merged, &h4, &merged);
    sfh_double_int16_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_double_int16_t_node_t large_nodes[1000];
    sfh_double_int16_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_double_int16_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_double_int16_t_decrease_key(&heap, &large_nodes[i],
                                      large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_double_int16_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_double_int32_t(void) {
  sfh_double_int32_t_heap_t heap;
  sfh_double_int32_t_node_t node;
  sfh_double_int32_t_node_t *out_node;
  sfh_double_int32_t_heap_t *out_heap;
  int is_empty;
  sfh_double_int32_t_error_t rc;
  int i;

  rc = sfh_double_int32_t_init(NULL);
  ASSERT_EQ(sfh_double_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_double_int32_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_double_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_double_int32_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_double_int32_t_ERR_NULL_ARG, rc);
  rc = sfh_double_int32_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_double_int32_t_ERR_NULL_ARG, rc);

  sfh_double_int32_t_init(&heap);

  {
    sfh_double_int32_t_node_t n1, n2, n3;
    rc = sfh_double_int32_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_double_int32_t_SUCCESS, rc);
    rc = sfh_double_int32_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_double_int32_t_SUCCESS, rc);
    rc = sfh_double_int32_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_double_int32_t_SUCCESS, rc);
    rc = sfh_double_int32_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_double_int32_t_SUCCESS, rc);
    rc = sfh_double_int32_t_delete_min(&heap);
    ASSERT_EQ(sfh_double_int32_t_SUCCESS, rc);
    rc = sfh_double_int32_t_delete_min(&heap);
    ASSERT_EQ(sfh_double_int32_t_SUCCESS, rc);
  }

  {
    sfh_double_int32_t_node_t nodes[100];
    sfh_double_int32_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_double_int32_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_double_int32_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_double_int32_t_heap_t h1, h2, h3, h4, *merged;
    sfh_double_int32_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_double_int32_t_init(&h1);
    sfh_double_int32_t_init(&h2);
    sfh_double_int32_t_init(&h3);
    sfh_double_int32_t_init(&h4);
    sfh_double_int32_t_insert(&h1, &n1, 1, 0);
    sfh_double_int32_t_insert(&h1, &n2, 2, 0);
    sfh_double_int32_t_insert(&h1, &n3, 3, 0);
    sfh_double_int32_t_insert(&h1, &n4, 4, 0);
    sfh_double_int32_t_insert(&h2, &m2, 10, 0);
    sfh_double_int32_t_insert(&h3, &m3, 11, 0);
    sfh_double_int32_t_insert(&h4, &m4, 12, 0);
    sfh_double_int32_t_meld(&h1, &h2, &merged);
    sfh_double_int32_t_meld(merged, &h3, &merged);
    sfh_double_int32_t_meld(merged, &h4, &merged);
    sfh_double_int32_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_double_int32_t_node_t large_nodes[1000];
    sfh_double_int32_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_double_int32_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_double_int32_t_decrease_key(&heap, &large_nodes[i],
                                      large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_double_int32_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_double_int64_t(void) {
  sfh_double_int64_t_heap_t heap;
  sfh_double_int64_t_node_t node;
  sfh_double_int64_t_node_t *out_node;
  sfh_double_int64_t_heap_t *out_heap;
  int is_empty;
  sfh_double_int64_t_error_t rc;
  int i;

  rc = sfh_double_int64_t_init(NULL);
  ASSERT_EQ(sfh_double_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_double_int64_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_double_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_double_int64_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_double_int64_t_ERR_NULL_ARG, rc);
  rc = sfh_double_int64_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_double_int64_t_ERR_NULL_ARG, rc);

  sfh_double_int64_t_init(&heap);

  {
    sfh_double_int64_t_node_t n1, n2, n3;
    rc = sfh_double_int64_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_double_int64_t_SUCCESS, rc);
    rc = sfh_double_int64_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_double_int64_t_SUCCESS, rc);
    rc = sfh_double_int64_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_double_int64_t_SUCCESS, rc);
    rc = sfh_double_int64_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_double_int64_t_SUCCESS, rc);
    rc = sfh_double_int64_t_delete_min(&heap);
    ASSERT_EQ(sfh_double_int64_t_SUCCESS, rc);
    rc = sfh_double_int64_t_delete_min(&heap);
    ASSERT_EQ(sfh_double_int64_t_SUCCESS, rc);
  }

  {
    sfh_double_int64_t_node_t nodes[100];
    sfh_double_int64_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_double_int64_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_double_int64_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_double_int64_t_heap_t h1, h2, h3, h4, *merged;
    sfh_double_int64_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_double_int64_t_init(&h1);
    sfh_double_int64_t_init(&h2);
    sfh_double_int64_t_init(&h3);
    sfh_double_int64_t_init(&h4);
    sfh_double_int64_t_insert(&h1, &n1, 1, 0);
    sfh_double_int64_t_insert(&h1, &n2, 2, 0);
    sfh_double_int64_t_insert(&h1, &n3, 3, 0);
    sfh_double_int64_t_insert(&h1, &n4, 4, 0);
    sfh_double_int64_t_insert(&h2, &m2, 10, 0);
    sfh_double_int64_t_insert(&h3, &m3, 11, 0);
    sfh_double_int64_t_insert(&h4, &m4, 12, 0);
    sfh_double_int64_t_meld(&h1, &h2, &merged);
    sfh_double_int64_t_meld(merged, &h3, &merged);
    sfh_double_int64_t_meld(merged, &h4, &merged);
    sfh_double_int64_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_double_int64_t_node_t large_nodes[1000];
    sfh_double_int64_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_double_int64_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_double_int64_t_decrease_key(&heap, &large_nodes[i],
                                      large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_double_int64_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_double_uint8_t(void) {
  sfh_double_uint8_t_heap_t heap;
  sfh_double_uint8_t_node_t node;
  sfh_double_uint8_t_node_t *out_node;
  sfh_double_uint8_t_heap_t *out_heap;
  int is_empty;
  sfh_double_uint8_t_error_t rc;
  int i;

  rc = sfh_double_uint8_t_init(NULL);
  ASSERT_EQ(sfh_double_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_double_uint8_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_double_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_double_uint8_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_double_uint8_t_ERR_NULL_ARG, rc);
  rc = sfh_double_uint8_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_double_uint8_t_ERR_NULL_ARG, rc);

  sfh_double_uint8_t_init(&heap);

  {
    sfh_double_uint8_t_node_t n1, n2, n3;
    rc = sfh_double_uint8_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_double_uint8_t_SUCCESS, rc);
    rc = sfh_double_uint8_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_double_uint8_t_SUCCESS, rc);
    rc = sfh_double_uint8_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_double_uint8_t_SUCCESS, rc);
    rc = sfh_double_uint8_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_double_uint8_t_SUCCESS, rc);
    rc = sfh_double_uint8_t_delete_min(&heap);
    ASSERT_EQ(sfh_double_uint8_t_SUCCESS, rc);
    rc = sfh_double_uint8_t_delete_min(&heap);
    ASSERT_EQ(sfh_double_uint8_t_SUCCESS, rc);
  }

  {
    sfh_double_uint8_t_node_t nodes[100];
    sfh_double_uint8_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_double_uint8_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_double_uint8_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_double_uint8_t_heap_t h1, h2, h3, h4, *merged;
    sfh_double_uint8_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_double_uint8_t_init(&h1);
    sfh_double_uint8_t_init(&h2);
    sfh_double_uint8_t_init(&h3);
    sfh_double_uint8_t_init(&h4);
    sfh_double_uint8_t_insert(&h1, &n1, 1, 0);
    sfh_double_uint8_t_insert(&h1, &n2, 2, 0);
    sfh_double_uint8_t_insert(&h1, &n3, 3, 0);
    sfh_double_uint8_t_insert(&h1, &n4, 4, 0);
    sfh_double_uint8_t_insert(&h2, &m2, 10, 0);
    sfh_double_uint8_t_insert(&h3, &m3, 11, 0);
    sfh_double_uint8_t_insert(&h4, &m4, 12, 0);
    sfh_double_uint8_t_meld(&h1, &h2, &merged);
    sfh_double_uint8_t_meld(merged, &h3, &merged);
    sfh_double_uint8_t_meld(merged, &h4, &merged);
    sfh_double_uint8_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_double_uint8_t_node_t large_nodes[1000];
    sfh_double_uint8_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_double_uint8_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_double_uint8_t_decrease_key(&heap, &large_nodes[i],
                                      large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_double_uint8_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_double_uint16_t(void) {
  sfh_double_uint16_t_heap_t heap;
  sfh_double_uint16_t_node_t node;
  sfh_double_uint16_t_node_t *out_node;
  sfh_double_uint16_t_heap_t *out_heap;
  int is_empty;
  sfh_double_uint16_t_error_t rc;
  int i;

  rc = sfh_double_uint16_t_init(NULL);
  ASSERT_EQ(sfh_double_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_double_uint16_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_double_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_double_uint16_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_double_uint16_t_ERR_NULL_ARG, rc);
  rc = sfh_double_uint16_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_double_uint16_t_ERR_NULL_ARG, rc);

  sfh_double_uint16_t_init(&heap);

  {
    sfh_double_uint16_t_node_t n1, n2, n3;
    rc = sfh_double_uint16_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_double_uint16_t_SUCCESS, rc);
    rc = sfh_double_uint16_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_double_uint16_t_SUCCESS, rc);
    rc = sfh_double_uint16_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_double_uint16_t_SUCCESS, rc);
    rc = sfh_double_uint16_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_double_uint16_t_SUCCESS, rc);
    rc = sfh_double_uint16_t_delete_min(&heap);
    ASSERT_EQ(sfh_double_uint16_t_SUCCESS, rc);
    rc = sfh_double_uint16_t_delete_min(&heap);
    ASSERT_EQ(sfh_double_uint16_t_SUCCESS, rc);
  }

  {
    sfh_double_uint16_t_node_t nodes[100];
    sfh_double_uint16_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_double_uint16_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_double_uint16_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_double_uint16_t_heap_t h1, h2, h3, h4, *merged;
    sfh_double_uint16_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_double_uint16_t_init(&h1);
    sfh_double_uint16_t_init(&h2);
    sfh_double_uint16_t_init(&h3);
    sfh_double_uint16_t_init(&h4);
    sfh_double_uint16_t_insert(&h1, &n1, 1, 0);
    sfh_double_uint16_t_insert(&h1, &n2, 2, 0);
    sfh_double_uint16_t_insert(&h1, &n3, 3, 0);
    sfh_double_uint16_t_insert(&h1, &n4, 4, 0);
    sfh_double_uint16_t_insert(&h2, &m2, 10, 0);
    sfh_double_uint16_t_insert(&h3, &m3, 11, 0);
    sfh_double_uint16_t_insert(&h4, &m4, 12, 0);
    sfh_double_uint16_t_meld(&h1, &h2, &merged);
    sfh_double_uint16_t_meld(merged, &h3, &merged);
    sfh_double_uint16_t_meld(merged, &h4, &merged);
    sfh_double_uint16_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_double_uint16_t_node_t large_nodes[1000];
    sfh_double_uint16_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_double_uint16_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_double_uint16_t_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_double_uint16_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_double_uint32_t(void) {
  sfh_double_uint32_t_heap_t heap;
  sfh_double_uint32_t_node_t node;
  sfh_double_uint32_t_node_t *out_node;
  sfh_double_uint32_t_heap_t *out_heap;
  int is_empty;
  sfh_double_uint32_t_error_t rc;
  int i;

  rc = sfh_double_uint32_t_init(NULL);
  ASSERT_EQ(sfh_double_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_double_uint32_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_double_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_double_uint32_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_double_uint32_t_ERR_NULL_ARG, rc);
  rc = sfh_double_uint32_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_double_uint32_t_ERR_NULL_ARG, rc);

  sfh_double_uint32_t_init(&heap);

  {
    sfh_double_uint32_t_node_t n1, n2, n3;
    rc = sfh_double_uint32_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_double_uint32_t_SUCCESS, rc);
    rc = sfh_double_uint32_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_double_uint32_t_SUCCESS, rc);
    rc = sfh_double_uint32_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_double_uint32_t_SUCCESS, rc);
    rc = sfh_double_uint32_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_double_uint32_t_SUCCESS, rc);
    rc = sfh_double_uint32_t_delete_min(&heap);
    ASSERT_EQ(sfh_double_uint32_t_SUCCESS, rc);
    rc = sfh_double_uint32_t_delete_min(&heap);
    ASSERT_EQ(sfh_double_uint32_t_SUCCESS, rc);
  }

  {
    sfh_double_uint32_t_node_t nodes[100];
    sfh_double_uint32_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_double_uint32_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_double_uint32_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_double_uint32_t_heap_t h1, h2, h3, h4, *merged;
    sfh_double_uint32_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_double_uint32_t_init(&h1);
    sfh_double_uint32_t_init(&h2);
    sfh_double_uint32_t_init(&h3);
    sfh_double_uint32_t_init(&h4);
    sfh_double_uint32_t_insert(&h1, &n1, 1, 0);
    sfh_double_uint32_t_insert(&h1, &n2, 2, 0);
    sfh_double_uint32_t_insert(&h1, &n3, 3, 0);
    sfh_double_uint32_t_insert(&h1, &n4, 4, 0);
    sfh_double_uint32_t_insert(&h2, &m2, 10, 0);
    sfh_double_uint32_t_insert(&h3, &m3, 11, 0);
    sfh_double_uint32_t_insert(&h4, &m4, 12, 0);
    sfh_double_uint32_t_meld(&h1, &h2, &merged);
    sfh_double_uint32_t_meld(merged, &h3, &merged);
    sfh_double_uint32_t_meld(merged, &h4, &merged);
    sfh_double_uint32_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_double_uint32_t_node_t large_nodes[1000];
    sfh_double_uint32_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_double_uint32_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_double_uint32_t_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_double_uint32_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_double_uint64_t(void) {
  sfh_double_uint64_t_heap_t heap;
  sfh_double_uint64_t_node_t node;
  sfh_double_uint64_t_node_t *out_node;
  sfh_double_uint64_t_heap_t *out_heap;
  int is_empty;
  sfh_double_uint64_t_error_t rc;
  int i;

  rc = sfh_double_uint64_t_init(NULL);
  ASSERT_EQ(sfh_double_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_double_uint64_t_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_double_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_double_uint64_t_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_double_uint64_t_ERR_NULL_ARG, rc);
  rc = sfh_double_uint64_t_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_double_uint64_t_ERR_NULL_ARG, rc);

  sfh_double_uint64_t_init(&heap);

  {
    sfh_double_uint64_t_node_t n1, n2, n3;
    rc = sfh_double_uint64_t_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_double_uint64_t_SUCCESS, rc);
    rc = sfh_double_uint64_t_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_double_uint64_t_SUCCESS, rc);
    rc = sfh_double_uint64_t_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_double_uint64_t_SUCCESS, rc);
    rc = sfh_double_uint64_t_delete(&heap, &n2);
    ASSERT_EQ(sfh_double_uint64_t_SUCCESS, rc);
    rc = sfh_double_uint64_t_delete_min(&heap);
    ASSERT_EQ(sfh_double_uint64_t_SUCCESS, rc);
    rc = sfh_double_uint64_t_delete_min(&heap);
    ASSERT_EQ(sfh_double_uint64_t_SUCCESS, rc);
  }

  {
    sfh_double_uint64_t_node_t nodes[100];
    sfh_double_uint64_t_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_double_uint64_t_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_double_uint64_t_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_double_uint64_t_heap_t h1, h2, h3, h4, *merged;
    sfh_double_uint64_t_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_double_uint64_t_init(&h1);
    sfh_double_uint64_t_init(&h2);
    sfh_double_uint64_t_init(&h3);
    sfh_double_uint64_t_init(&h4);
    sfh_double_uint64_t_insert(&h1, &n1, 1, 0);
    sfh_double_uint64_t_insert(&h1, &n2, 2, 0);
    sfh_double_uint64_t_insert(&h1, &n3, 3, 0);
    sfh_double_uint64_t_insert(&h1, &n4, 4, 0);
    sfh_double_uint64_t_insert(&h2, &m2, 10, 0);
    sfh_double_uint64_t_insert(&h3, &m3, 11, 0);
    sfh_double_uint64_t_insert(&h4, &m4, 12, 0);
    sfh_double_uint64_t_meld(&h1, &h2, &merged);
    sfh_double_uint64_t_meld(merged, &h3, &merged);
    sfh_double_uint64_t_meld(merged, &h4, &merged);
    sfh_double_uint64_t_decrease_key(merged, &m4, 0);
  }

  {
    sfh_double_uint64_t_node_t large_nodes[1000];
    sfh_double_uint64_t_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_double_uint64_t_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_double_uint64_t_decrease_key(&heap, &large_nodes[i],
                                       large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_double_uint64_t_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_double_float(void) {
  sfh_double_float_heap_t heap;
  sfh_double_float_node_t node;
  sfh_double_float_node_t *out_node;
  sfh_double_float_heap_t *out_heap;
  int is_empty;
  sfh_double_float_error_t rc;
  int i;

  rc = sfh_double_float_init(NULL);
  ASSERT_EQ(sfh_double_float_ERR_NULL_ARG, rc);
  rc = sfh_double_float_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_double_float_ERR_NULL_ARG, rc);
  rc = sfh_double_float_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_double_float_ERR_NULL_ARG, rc);
  rc = sfh_double_float_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_double_float_ERR_NULL_ARG, rc);

  sfh_double_float_init(&heap);

  {
    sfh_double_float_node_t n1, n2, n3;
    rc = sfh_double_float_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_double_float_SUCCESS, rc);
    rc = sfh_double_float_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_double_float_SUCCESS, rc);
    rc = sfh_double_float_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_double_float_SUCCESS, rc);
    rc = sfh_double_float_delete(&heap, &n2);
    ASSERT_EQ(sfh_double_float_SUCCESS, rc);
    rc = sfh_double_float_delete_min(&heap);
    ASSERT_EQ(sfh_double_float_SUCCESS, rc);
    rc = sfh_double_float_delete_min(&heap);
    ASSERT_EQ(sfh_double_float_SUCCESS, rc);
  }

  {
    sfh_double_float_node_t nodes[100];
    sfh_double_float_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_double_float_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_double_float_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_double_float_heap_t h1, h2, h3, h4, *merged;
    sfh_double_float_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_double_float_init(&h1);
    sfh_double_float_init(&h2);
    sfh_double_float_init(&h3);
    sfh_double_float_init(&h4);
    sfh_double_float_insert(&h1, &n1, 1, 0);
    sfh_double_float_insert(&h1, &n2, 2, 0);
    sfh_double_float_insert(&h1, &n3, 3, 0);
    sfh_double_float_insert(&h1, &n4, 4, 0);
    sfh_double_float_insert(&h2, &m2, 10, 0);
    sfh_double_float_insert(&h3, &m3, 11, 0);
    sfh_double_float_insert(&h4, &m4, 12, 0);
    sfh_double_float_meld(&h1, &h2, &merged);
    sfh_double_float_meld(merged, &h3, &merged);
    sfh_double_float_meld(merged, &h4, &merged);
    sfh_double_float_decrease_key(merged, &m4, 0);
  }

  {
    sfh_double_float_node_t large_nodes[1000];
    sfh_double_float_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_double_float_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_double_float_decrease_key(&heap, &large_nodes[i],
                                    large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_double_float_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_double_double(void) {
  sfh_double_double_heap_t heap;
  sfh_double_double_node_t node;
  sfh_double_double_node_t *out_node;
  sfh_double_double_heap_t *out_heap;
  int is_empty;
  sfh_double_double_error_t rc;
  int i;

  rc = sfh_double_double_init(NULL);
  ASSERT_EQ(sfh_double_double_ERR_NULL_ARG, rc);
  rc = sfh_double_double_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_double_double_ERR_NULL_ARG, rc);
  rc = sfh_double_double_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_double_double_ERR_NULL_ARG, rc);
  rc = sfh_double_double_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_double_double_ERR_NULL_ARG, rc);

  sfh_double_double_init(&heap);

  {
    sfh_double_double_node_t n1, n2, n3;
    rc = sfh_double_double_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_double_double_SUCCESS, rc);
    rc = sfh_double_double_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_double_double_SUCCESS, rc);
    rc = sfh_double_double_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_double_double_SUCCESS, rc);
    rc = sfh_double_double_delete(&heap, &n2);
    ASSERT_EQ(sfh_double_double_SUCCESS, rc);
    rc = sfh_double_double_delete_min(&heap);
    ASSERT_EQ(sfh_double_double_SUCCESS, rc);
    rc = sfh_double_double_delete_min(&heap);
    ASSERT_EQ(sfh_double_double_SUCCESS, rc);
  }

  {
    sfh_double_double_node_t nodes[100];
    sfh_double_double_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_double_double_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_double_double_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_double_double_heap_t h1, h2, h3, h4, *merged;
    sfh_double_double_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_double_double_init(&h1);
    sfh_double_double_init(&h2);
    sfh_double_double_init(&h3);
    sfh_double_double_init(&h4);
    sfh_double_double_insert(&h1, &n1, 1, 0);
    sfh_double_double_insert(&h1, &n2, 2, 0);
    sfh_double_double_insert(&h1, &n3, 3, 0);
    sfh_double_double_insert(&h1, &n4, 4, 0);
    sfh_double_double_insert(&h2, &m2, 10, 0);
    sfh_double_double_insert(&h3, &m3, 11, 0);
    sfh_double_double_insert(&h4, &m4, 12, 0);
    sfh_double_double_meld(&h1, &h2, &merged);
    sfh_double_double_meld(merged, &h3, &merged);
    sfh_double_double_meld(merged, &h4, &merged);
    sfh_double_double_decrease_key(merged, &m4, 0);
  }

  {
    sfh_double_double_node_t large_nodes[1000];
    sfh_double_double_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_double_double_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_double_double_decrease_key(&heap, &large_nodes[i],
                                     large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_double_double_delete_min(&heap);
    }
  }

  PASS();
}

TEST test_all_sfh_double_charptr(void) {
  sfh_double_charptr_heap_t heap;
  sfh_double_charptr_node_t node;
  sfh_double_charptr_node_t *out_node;
  sfh_double_charptr_heap_t *out_heap;
  int is_empty;
  sfh_double_charptr_error_t rc;
  int i;

  rc = sfh_double_charptr_init(NULL);
  ASSERT_EQ(sfh_double_charptr_ERR_NULL_ARG, rc);
  rc = sfh_double_charptr_empty(NULL, &is_empty);
  ASSERT_EQ(sfh_double_charptr_ERR_NULL_ARG, rc);
  rc = sfh_double_charptr_find_min(NULL, &out_node);
  ASSERT_EQ(sfh_double_charptr_ERR_NULL_ARG, rc);
  rc = sfh_double_charptr_insert(NULL, &node, 1, 0);
  ASSERT_EQ(sfh_double_charptr_ERR_NULL_ARG, rc);

  sfh_double_charptr_init(&heap);

  {
    sfh_double_charptr_node_t n1, n2, n3;
    rc = sfh_double_charptr_insert(&heap, &n1, 10, 0);
    ASSERT_EQ(sfh_double_charptr_SUCCESS, rc);
    rc = sfh_double_charptr_insert(&heap, &n2, 20, 0);
    ASSERT_EQ(sfh_double_charptr_SUCCESS, rc);
    rc = sfh_double_charptr_insert(&heap, &n3, 30, 0);
    ASSERT_EQ(sfh_double_charptr_SUCCESS, rc);
    rc = sfh_double_charptr_delete(&heap, &n2);
    ASSERT_EQ(sfh_double_charptr_SUCCESS, rc);
    rc = sfh_double_charptr_delete_min(&heap);
    ASSERT_EQ(sfh_double_charptr_SUCCESS, rc);
    rc = sfh_double_charptr_delete_min(&heap);
    ASSERT_EQ(sfh_double_charptr_SUCCESS, rc);
  }

  {
    sfh_double_charptr_node_t nodes[100];
    sfh_double_charptr_init(&heap);
    for (i = 0; i < 100; ++i) {
      rc = sfh_double_charptr_insert(&heap, &nodes[i], i, 0);
      if (rc == sfh_double_charptr_ERR_OUT_OF_RANKS)
        break;
    }
  }

  {
    sfh_double_charptr_heap_t h1, h2, h3, h4, *merged;
    sfh_double_charptr_node_t n1, n2, n3, n4, m2, m3, m4;
    sfh_double_charptr_init(&h1);
    sfh_double_charptr_init(&h2);
    sfh_double_charptr_init(&h3);
    sfh_double_charptr_init(&h4);
    sfh_double_charptr_insert(&h1, &n1, 1, 0);
    sfh_double_charptr_insert(&h1, &n2, 2, 0);
    sfh_double_charptr_insert(&h1, &n3, 3, 0);
    sfh_double_charptr_insert(&h1, &n4, 4, 0);
    sfh_double_charptr_insert(&h2, &m2, 10, 0);
    sfh_double_charptr_insert(&h3, &m3, 11, 0);
    sfh_double_charptr_insert(&h4, &m4, 12, 0);
    sfh_double_charptr_meld(&h1, &h2, &merged);
    sfh_double_charptr_meld(merged, &h3, &merged);
    sfh_double_charptr_meld(merged, &h4, &merged);
    sfh_double_charptr_decrease_key(merged, &m4, 0);
  }

  {
    sfh_double_charptr_node_t large_nodes[1000];
    sfh_double_charptr_init(&heap);
    for (i = 0; i < 1000; ++i) {
      int k = (i * 137) % 1000;
      sfh_double_charptr_insert(&heap, &large_nodes[i], k, 0);
    }
    for (i = 0; i < 1000; i += 10) {
      sfh_double_charptr_decrease_key(&heap, &large_nodes[i],
                                      large_nodes[i].key - 100);
    }
    for (i = 0; i < 1000; ++i) {
      sfh_double_charptr_delete_min(&heap);
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
}

GREATEST_MAIN_DEFS();
int main(int argc, char **argv) {
  GREATEST_MAIN_BEGIN();
  RUN_SUITE(strict_fibonacci_heaps_suite);
  GREATEST_MAIN_END();
}
