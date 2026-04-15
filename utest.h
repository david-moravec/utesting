#pragma once
#include <stdio.h>
#include <stdlib.h>

static int tests_run = 0;
static int tests_passed = 0;

#define ASSERT(condition, msg)                                                 \
  do {                                                                         \
    tests_run++;                                                               \
    if (condition) {                                                           \
      tests_passed++;                                                          \
      printf("  PASS: %s\n", msg);                                             \
    } else {                                                                   \
      printf("  FAIL: %s (line %d)\n", msg, __LINE__);                         \
    }                                                                          \
  } while (0)

#define TEST(name) static void name(void)

#define RUN_TEST(name)                                                         \
  do {                                                                         \
    printf("\n[%s]\n", #name);                                                 \
    name();                                                                    \
  } while (0)

#define SUMMARY()                                                              \
  do {                                                                         \
    printf("\n--- Results: %d/%d passed ---\n", tests_passed, tests_run);      \
    return (tests_passed == tests_run) ? 0 : 1;                                \
  } while (0)
