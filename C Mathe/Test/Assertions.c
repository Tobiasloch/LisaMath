/*
 * Assertions.c
 *
 *  Created on: 11.09.2018
 *      Author: t.loch
 */
#include "Assertions.h"

void testCounter(const char funcName[]) {
	runned_count++;

	if (strcmp(funcName, f_name) == 0) {
		t_count++;
	} else {
		printf("\nRunning Test %s:\n", funcName);

		strcpy(f_name, funcName);
		t_count = 1;
	}

	printf("\t%s %d:", funcName, t_count);
}

void assert(int expression, const char funcName[], const int line) {
	testCounter(funcName);

	if (!expression) {
		printf(" Failed in line %d!\n", line);
		failed_count++;
	} else {
		printf(" passed.\n");
	}
}

void assert_equal(int actual, int expected, const char funcName[], const int line) {
	testCounter(funcName);

	if (actual != expected) {
		printf(" Failed in line %d! Value was %d, but expected was %d\n", line, actual, expected);
		failed_count++;
	} else {
		printf(" passed.\n");
	}
}

void assert_fail(char* message, const char funcName[], const int line) {
	testCounter(funcName);
	failed_count++;

	printf(" Failed in line %d! Message: %s\n", line, message);
}

void print_Summary(void) {
	printf("\n###TEST SUMMARY###\n");
	printf("\tTests runned: %d\n", runned_count);
	printf("\tTests failed: %d\n", failed_count);
}


