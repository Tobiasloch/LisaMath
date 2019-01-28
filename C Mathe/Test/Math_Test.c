/*
 * Math_Test.c
 *
 *  Created on: 11.09.2018
 *      Author: t.loch
 */
#include "Math_Test.h"

#define NUMBER_OF_TESTS 100
#define roundPosition_FACTOR 4
#define MAX_SQUARE 10
#define ACCURACY 0.0001

// bei den testdaten ist jeder ungerade wert eine Testdatenreihe und jeder darauffolgende gerade Wert das ergebnis.
// Das gilt analog für alle Testdatenreihen eines jeden Tests.

// test_standardabw data
// jedes Ergebnis besteht aus der Summe, dem Durchschnitt, der Varianz und der Standardabweichung der Testwerte
static float DEFAULT_test_Standardabw_DATA[][7] = {{8, 7, 9, 10, 6}, {40, 8, 2, 1.4142135623730951},
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
static float DEFAULT_test_median_DATA[][12] = {{5,3,7,4,4,3,6,4,7,8,7,6},{5.5},
											{2,21,-5,5,2.3}, {2.3},
											{2.445,5.554,775,221}, {113.277},
											{-19,-54,-2.24,-8,-9648,-17},{-18},
											{565423,545456456,53541355,121147544,144244145},{121147544},
											{2.245,77,24,365,0,0.5},{13.1225},
											{0.5,0.25,0.225,0.78,0.99},{0.5}};
static size_t DEFAULT_test_median_DATA_size_x = NELEMS(DEFAULT_test_median_DATA);
static size_t DEFAULT_test_median_DATA_size_y[] = {12, 5, 4, 6, 5, 6, 5};

// test_roundPosition data
// der erste Wert des Ergebnisses (alle geraden indizes) bezeichnet auf den zu rundenden Wert und der zweite das zu erwartende Ergebnis
static float DEFAULT_test_roundPosition_DATA[][2] = {{5.54556}, {2, 5.55},
		{15.21353}, {3, 15.214},
		{15.1}, {3, 15.1},
		{-0.1111}, {1, -0.1},
		{-0.6}, {0, -1},
		{5.93}, {0, 6}};
static size_t DEFAULT_test_roundPosition_DATA_size_x = NELEMS(DEFAULT_test_roundPosition_DATA);
//static size_t DEFAULT_test_roundPosition_DATA_size_y = 1;

void test_Random(void) {
	srand(time(NULL));

	float lastValue = -1;
	for (int i = 0; i < NUMBER_OF_TESTS; i++) {
		float r = 0;
		while (r == lastValue) r = rand();

		float start = r;
		float end = 2*r;
		float zufall = Zufallszahl(r, r);

		CU_ASSERT((zufall >= start) && (zufall <= end));
		//printf("random: %f; start: %f; end: %f\n", zufall, start, end);

		lastValue = r;
	}
}

void test_Standardabw(void){
	for (int i = 0; i<DEFAULT_test_Standardabw_DATA_size_x; i+=2) {
		float sum = roundPosition(sum_with_size(DEFAULT_test_Standardabw_DATA[i], DEFAULT_test_Standardabw_DATA_size_y[i/2]), roundPosition_FACTOR);
		float durch = roundPosition(durchschnitt_with_size(DEFAULT_test_Standardabw_DATA[i], DEFAULT_test_Standardabw_DATA_size_y[i/2]), roundPosition_FACTOR);
		float var = roundPosition(varianz_with_size(DEFAULT_test_Standardabw_DATA[i], DEFAULT_test_Standardabw_DATA_size_y[i/2]), roundPosition_FACTOR);
		float std = roundPosition(standardabw_with_size(DEFAULT_test_Standardabw_DATA[i], DEFAULT_test_Standardabw_DATA_size_y[i/2]), roundPosition_FACTOR);

		CU_ASSERT_EQUAL(sum, roundPosition(DEFAULT_test_Standardabw_DATA[i+1][0], roundPosition_FACTOR));
		CU_ASSERT_EQUAL(durch, roundPosition(DEFAULT_test_Standardabw_DATA[i+1][1], roundPosition_FACTOR));
		CU_ASSERT_EQUAL(var, roundPosition(DEFAULT_test_Standardabw_DATA[i+1][2], roundPosition_FACTOR));
		CU_ASSERT_EQUAL(std, roundPosition(DEFAULT_test_Standardabw_DATA[i+1][3], roundPosition_FACTOR));
	}
}

void test_Median(void){
	for (int i = 0; i < DEFAULT_test_median_DATA_size_x; i+=2) {
		float result = roundPosition(DEFAULT_test_median_DATA[i+1][0], roundPosition_FACTOR);

		float median = roundPosition(median_with_size(DEFAULT_test_median_DATA[i], DEFAULT_test_median_DATA_size_y[i/2]), roundPosition_FACTOR);

		CU_ASSERT_EQUAL(median, result);
	}
}

void test_roundPosition(void){
	for (int i = 0; i < DEFAULT_test_roundPosition_DATA_size_x; i+=2) {
		float roundPosition = roundPosition(DEFAULT_test_roundPosition_DATA[i][0], DEFAULT_test_roundPosition_DATA[i+1][0]);

		CU_ASSERT_EQUAL(roundPosition, DEFAULT_test_roundPosition_DATA[i+1][1]);
	}
}

void test_MinMax(void){
	int arraySize = (int)Zufallszahl(2, 10);
	srand(time(NULL));

	int* array;
	if ((array=calloc(arraySize, sizeof(int))) == NULL) {
		CU_FAIL("The array could not be allocated! Test is being exited!");
		return;
	}
	int maxArray = 0;
	int minArray = 0;

	for (int i = 0; i < NUMBER_OF_TESTS; i++) {
		int x = rand()-(RAND_MAX/2);
		int y = x;
		while (x==y) y = rand()-(RAND_MAX/2);

		int mi = fmin(x,y);
		int ma = fmax(x,y);

		CU_ASSERT_EQUAL(minAtomar(x,y), mi);
		CU_ASSERT_EQUAL(maxAtomar(x,y), ma);

		if (i%arraySize == 0) {
			for (int k = 0; k < arraySize; k++) array[k] = 0;
			minArray = 0;
			maxArray = 0;
		} else {
			array[i%arraySize] = x;
			maxArray = maxAtomar(maxArray, x);
			minArray = minAtomar(minArray, x);
	
			// test with just min or max!
			CU_ASSERT_EQUAL(max_int_array_with_size(array, arraySize), maxArray);
			CU_ASSERT_EQUAL(min_int_array_with_size(array, arraySize), minArray);
		}
	}
	
	free(array);
}

void test_Wurzel() {
	for (int i = 0; i < NUMBER_OF_TESTS; i++) {
		float y = Zufallszahl(0, NUMBER_OF_TESTS);
		
		float expected = roundPosition((float) sqrt(y), roundPosition_FACTOR);
		float actual = roundPosition(wurzel(y), roundPosition_FACTOR);
		CU_ASSERT_EQUAL(expected, actual);
			
		int rad = Zufallszahl(1, MAX_SQUARE);
		
		expected = roundPosition(y, roundPosition_FACTOR);
		actual = roundPosition(wurzelExp((float)pow(expected, rad), rad), roundPosition_FACTOR);

		CU_ASSERT(abs(expected-actual) <= ACCURACY);
	}
}

void test_Potenz() {
	for (int i = 0; i < NUMBER_OF_TESTS; i++) {
		float y = Zufallszahl(-NUMBER_OF_TESTS, NUMBER_OF_TESTS*2);
		int rad = Zufallszahl(1, MAX_SQUARE);
			
		// test float version of quadrat
		float fExpected = roundPosition((float)pow(y,2), roundPosition_FACTOR);
		float fActual = roundPosition(quadrat(y), roundPosition_FACTOR);
		CU_ASSERT_EQUAL(fExpected, fActual);
		
		// test int version of quadrat
		int iExpected = (int) pow((int)y,2);
		int iActual = quadrat((int) y);
		CU_ASSERT_EQUAL(iExpected, iActual);
			
		fExpected = roundPosition(abs(y), roundPosition_FACTOR);
		fActual = roundPosition(pot((float)wurzelExp(fExpected, rad), rad), roundPosition_FACTOR);
		CU_ASSERT(abs(fExpected-fActual) <= ACCURACY);
	}
}

void test_log() {
	for (int i = 0; i < NUMBER_OF_TESTS; i++) {
		float y = Zufallszahl(NUMBER_OF_TESTS, NUMBER_OF_TESTS*2);
			
		float expected = (float) log(y);
		float actual = ln(y);
			
		CU_ASSERT(abs(abs(expected) - abs(actual)) <= ACCURACY);
	}
}

void test_modulo() {
	for (int i = 0; i < NUMBER_OF_TESTS; i++) {
		float x = Zufallszahl(-NUMBER_OF_TESTS, NUMBER_OF_TESTS*2);
		float y = Zufallszahl(-NUMBER_OF_TESTS*2, NUMBER_OF_TESTS*4);
		if ((int)x==0) x+=2;
		
		double expected = fmod(y,x);
		double actual = modulo(y, x);
		 
		CU_ASSERT(abs(abs(expected) - abs(actual)) <= ACCURACY);
		
		expected = ((int)y%(int)x);
		actual = modulo((int)y,(int)x);
		
		CU_ASSERT_EQUAL(expected, actual);
	}
}

void run_All_Math_Tests() {
	test_Random();
	test_Standardabw();
	test_Median();
	test_roundPosition();
	test_MinMax();
	test_Wurzel();
	test_Potenz();
	test_log();
	test_modulo();
	
	print_Summary();
}
