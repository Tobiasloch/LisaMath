/*
 * Math_Test.c
 *
 *  Created on: 11.09.2018
 *      Author: t.loch
 */
#include "Math_Test.h"

#define NUMBER_OF_TESTS 100
#define ROUND_FACTOR 4

// bei den testdaten ist jeder ungerade wert eine Testdatenreihe und jeder darauffolgende gerade Wert das ergebnis.
// Das gilt analog für alle Testdatenreihen eines jeden Tests.

// test_standardabw data
// jedes Ergebnis besteht aus der Summe, dem Durchschnitt, der Varianz und der Standardabweichung der Testwerte
static double DEFAULT_test_Standardabw_DATA[][7] = {{8, 7, 9, 10, 6}, {40, 8, 2, 1.4142135623730951},
		{5,10,-10,9,-55,8,6}, {-27, -3.8571, 475.2653, 21.80058041},
		{10, 10}, {20, 10, 0, 0},
		{5,6}, {11, 5.5, 0.25, 0.5},
		{15,16,15,17}, {63, 15.75, 0.6875, 0.829156198},
		{5.5, 1, 2.68, 0.001}, {9.181, 2.29525, 4.3399, 2.0832}};
// Größe des oben genannten Arrays
static size_t DEFAULT_test_Standardabw_DATA_size_x = NELEMS(DEFAULT_test_Standardabw_DATA);
// Größe der Testdatenreihe
static size_t DEFAULT_test_Standardabw_DATA_size_y[] = {5, 7, 2, 2, 4, 4};

// test_median data
static double DEFAULT_test_median_DATA[][12] = {{5,3,7,4,4,3,6,4,7,8,7,6},{5.5},
											{2,21,-5,5,2.3}, {2.3},
											{2.445,5.554,775,221}, {113.277},
											{-19,-54,-2.24,-8,-9648,-17},{-18},
											{565423,545456456,53541355,121147544,144244145},{121147544},
											{2.245,77,24,365,0,0.5},{13.1225},
											{0.5,0.25,0.225,0.78,0.99},{0.5}};
static size_t DEFAULT_test_median_DATA_size_x = NELEMS(DEFAULT_test_median_DATA);
static size_t DEFAULT_test_median_DATA_size_y[] = {12, 5, 4, 6, 5, 6, 5};

// test_round data
// der erste Wert des Ergebnisses (alle geraden indizes) bezeichnet auf den zu rundenden Wert und der zweite das zu erwartende Ergebnis
static double DEFAULT_test_round_DATA[][2] = {{5.54556}, {2, 5.55},
		{15.21353}, {3, 15.214},
		{15.1}, {3, 15.1},
		{-0.1111}, {1, -0.1},
		{-0.6}, {0, -1},
		{5.93}, {0, 6}};
static size_t DEFAULT_test_round_DATA_size_x = NELEMS(DEFAULT_test_round_DATA);
//static size_t DEFAULT_test_round_DATA_size_y = 1;

void test_Random(void) {
	srand(time(NULL));

	double lastValue = -1;
	for (int i = 0; i < NUMBER_OF_TESTS; i++) {
		double r = 0;
		while (r == lastValue) r = rand();

		double start = r;
		double end = 2*r;
		double zufall = Zufallszahl(r, r);

		CU_ASSERT((zufall >= start) && (zufall <= end));
		//printf("random: %f; start: %f; end: %f\n", zufall, start, end);

		lastValue = r;
	}
}

void test_Standardabw(void){
	for (int i = 0; i<DEFAULT_test_Standardabw_DATA_size_x; i+=2) {
		double sum = round(sum_with_size(DEFAULT_test_Standardabw_DATA[i], DEFAULT_test_Standardabw_DATA_size_y[i/2]), ROUND_FACTOR);
		double durch = round(durchschnitt_with_size(DEFAULT_test_Standardabw_DATA[i], DEFAULT_test_Standardabw_DATA_size_y[i/2]), ROUND_FACTOR);
		double var = round(varianz_with_size(DEFAULT_test_Standardabw_DATA[i], DEFAULT_test_Standardabw_DATA_size_y[i/2]), ROUND_FACTOR);
		double std = round(standardabw_with_size(DEFAULT_test_Standardabw_DATA[i], DEFAULT_test_Standardabw_DATA_size_y[i/2]), ROUND_FACTOR);

		CU_ASSERT_EQUAL(sum, round(DEFAULT_test_Standardabw_DATA[i+1][0], ROUND_FACTOR));
		CU_ASSERT_EQUAL(durch, round(DEFAULT_test_Standardabw_DATA[i+1][1], ROUND_FACTOR));
		CU_ASSERT_EQUAL(var, round(DEFAULT_test_Standardabw_DATA[i+1][2], ROUND_FACTOR));
		CU_ASSERT_EQUAL(std, round(DEFAULT_test_Standardabw_DATA[i+1][3], ROUND_FACTOR));
	}
}

void test_Median(void){
	for (int i = 0; i < DEFAULT_test_median_DATA_size_x; i+=2) {
		double result = round(DEFAULT_test_median_DATA[i+1][0], ROUND_FACTOR);

		double median = round(median_with_size(DEFAULT_test_median_DATA[i], DEFAULT_test_median_DATA_size_y[i/2]), ROUND_FACTOR);

		CU_ASSERT_EQUAL(median, result);
	}
}

void test_Round(void){
	for (int i = 0; i < DEFAULT_test_round_DATA_size_x; i+=2) {
		double round = round(DEFAULT_test_round_DATA[i][0], DEFAULT_test_round_DATA[i+1][0]);

		CU_ASSERT_EQUAL(round, DEFAULT_test_round_DATA[i+1][1]);
	}
}

void test_MinMax(void){
	int arraySize = (int)Zufallszahl(2, 10);
	srand(time(NULL));

	long* array;
	if ((array=calloc(arraySize, sizeof(long))) == NULL) {
		CU_FAIL("The array could not be allocated! Test is being exited!");
		return;
	}
	long maxArray = 0;
	long minArray = 0;

	printf("arraySize= %d; NELEMS(array)=%d\n", arraySize, NELEMS(array));

	for (int i = 0; i < NUMBER_OF_TESTS; i++) {
		long x = rand()-(RAND_MAX/2);
		long y = x;
		while (x==y) y = rand()-(RAND_MAX/2);

		long mi = fmin(x,y);
		long ma = fmax(x,y);

		CU_ASSERT_EQUAL(min(x,y), mi);
		CU_ASSERT_EQUAL(max(x,y), ma);

		if (i%arraySize == 0) {
			for (int k = 0; k < arraySize; k++) array[k] = 0;
			minArray = 0;
			maxArray = 0;
		} else {
			array[i%arraySize] = x;
			maxArray = max(maxArray, x);
			minArray = min(minArray, x);

			CU_ASSERT_EQUAL(max_long_array_with_size(array, arraySize), maxArray);
			CU_ASSERT_EQUAL(min_long_array_with_size(array, arraySize), minArray);
		}
	}
}

void run_All_Math_Tests() {
	test_Random();
	test_Standardabw();
	test_Median();
	test_Round();
	test_MinMax();

	print_Summary();
}
