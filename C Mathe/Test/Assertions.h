/*
 * Assertions.h
 *
 *  Created on: 11.09.2018
 *      Author: t.loch
 */

#include <stdio.h>
#include <string.h>

#ifndef CU_ASSERT
#define CU_ASSERT(a) assert(a, __FUNCTION__, __LINE__)
#endif

#ifndef CU_ASSERT_EQUAL
#define CU_ASSERT_EQUAL(a,b) assert_equal(a, b, __FUNCTION__, __LINE__)
#endif

#ifndef CU_FAIL
#define CU_FAIL(a) assert_fail(a, __FUNCTION__, __LINE__);
#endif

char f_name[64];
int t_count;
int failed_count;
int runned_count;

void assert(int expression, const char funcName[], const int line);
void assert_equal(int actual, int expected, const char funcName[], const int line);
void assert_fail(char* message, const char funcName[], const int line);

void print_Summary(void);
