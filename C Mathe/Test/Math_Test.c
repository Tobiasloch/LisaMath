/*
 * Math_Test.c
 *
 *  Created on: 11.09.2018
 *      Author: t.loch
 */
#include "Math_Test.h"

#define NUMBER_OF_TESTS 100
#define MatheRoundPosition_FACTOR 4
#define Max_SQUARE 10
#define ACCURACY 0.0001

// bei den testdaten ist jeder ungerade wert eine Testdatenreihe und jeder darauffolgende gerade Wert das ergebnis.
// Das gilt analog für alle Testdatenreihen eines jeden Tests.

// test_MatheStandardabw data
// jedes Ergebnis besteht aus der MatheSumme, dem MatheDurchschnitt, der MatheVarianz und der MatheStandardabweichung der Testwerte
static float DEFAULT_test_MatheStandardabw_DATA[][7] = {{8, 7, 9, 10, 6}, {40, 8, 2, 1.4142135623730951},
		{5,10,-10,9,-55,8,6}, {-27, -3.8571, 475.2653, 21.80058041},
		{10, 10}, {20, 10, 0, 0},
		{5,6}, {11, 5.5, 0.25, 0.5},
		{15,16,15,17}, {63, 15.75, 0.6875, 0.829156198},
		{5.5, 1, 2.68, 0.001}, {9.181, 2.29525, 4.3399, 2.0832}};
// Größe des oben genannten Arrays
static size_t DEFAULT_test_MatheStandardabw_DATA_size_x = NELEMS(DEFAULT_test_MatheStandardabw_DATA);
// Größe der Testdatenreihe
static size_t DEFAULT_test_MatheStandardabw_DATA_size_y[] = {5, 7, 2, 2, 4, 4};

// test_MatheMedian data
static float DEFAULT_test_MatheMedian_DATA[][12] = {{5,3,7,4,4,3,6,4,7,8,7,6},{5.5},
											{2,21,-5,5,2.3}, {2.3},
											{2.445,5.554,775,221}, {113.277},
											{-19,-54,-2.24,-8,-9648,-17},{-18},
											{565423,545456456,53541355,121147544,144244145},{121147544},
											{2.245,77,24,365,0,0.5},{13.1225},
											{0.5,0.25,0.225,0.78,0.99},{0.5}};
static size_t DEFAULT_test_MatheMedian_DATA_size_x = NELEMS(DEFAULT_test_MatheMedian_DATA);
static size_t DEFAULT_test_MatheMedian_DATA_size_y[] = {12, 5, 4, 6, 5, 6, 5};

// test_MatheRoundPosition data
// der erste Wert des Ergebnisses (alle geraden indizes) bezeichnet auf den zu rundenden Wert und der zweite das zu erwartende Ergebnis
static float DEFAULT_test_MatheRoundPosition_DATA[][2] = {{5.54556}, {2, 5.55},
		{15.21353}, {3, 15.214},
		{15.1}, {3, 15.1},
		{-0.1111}, {1, -0.1},
		{-0.6}, {0, -1},
		{5.93}, {0, 6}};
static size_t DEFAULT_test_MatheRoundPosition_DATA_size_x = NELEMS(DEFAULT_test_MatheRoundPosition_DATA);
//static size_t DEFAULT_test_MatheRoundPosition_DATA_size_y = 1;

void test_Random(void) {
	srand(time(NULL));

	float lastValue = -1;
	for (int i = 0; i < NUMBER_OF_TESTS; i++) {
		float r = 0;
		while (r == lastValue) r = rand();

		float start = r;
		float end = 2*r;
		float zufall = MatheZufallszahl(r, r);

		CU_ASSERT((zufall >= start) && (zufall <= end));
		//printf("random: %f; start: %f; end: %f\n", zufall, start, end);

		lastValue = r;
	}
}

void test_MatheStandardabw(void){
	for (int i = 0; i<DEFAULT_test_MatheStandardabw_DATA_size_x; i+=2) {
		float MatheSum = MatheRoundPosition(MatheSum_with_size(DEFAULT_test_MatheStandardabw_DATA[i], DEFAULT_test_MatheStandardabw_DATA_size_y[i/2]), MatheRoundPosition_FACTOR);
		float durch = MatheRoundPosition(MatheDurchschnitt_with_size(DEFAULT_test_MatheStandardabw_DATA[i], DEFAULT_test_MatheStandardabw_DATA_size_y[i/2]), MatheRoundPosition_FACTOR);
		float var = MatheRoundPosition(MatheVarianz_with_size(DEFAULT_test_MatheStandardabw_DATA[i], DEFAULT_test_MatheStandardabw_DATA_size_y[i/2]), MatheRoundPosition_FACTOR);
		float std = MatheRoundPosition(MatheStandardabw_with_size(DEFAULT_test_MatheStandardabw_DATA[i], DEFAULT_test_MatheStandardabw_DATA_size_y[i/2]), MatheRoundPosition_FACTOR);

		CU_ASSERT_EQUAL(MatheSum, MatheRoundPosition(DEFAULT_test_MatheStandardabw_DATA[i+1][0], MatheRoundPosition_FACTOR));
		CU_ASSERT_EQUAL(durch, MatheRoundPosition(DEFAULT_test_MatheStandardabw_DATA[i+1][1], MatheRoundPosition_FACTOR));
		CU_ASSERT_EQUAL(var, MatheRoundPosition(DEFAULT_test_MatheStandardabw_DATA[i+1][2], MatheRoundPosition_FACTOR));
		CU_ASSERT_EQUAL(std, MatheRoundPosition(DEFAULT_test_MatheStandardabw_DATA[i+1][3], MatheRoundPosition_FACTOR));
	}
}

void test_MatheMedian(void){
	for (int i = 0; i < DEFAULT_test_MatheMedian_DATA_size_x; i+=2) {
		float result = MatheRoundPosition(DEFAULT_test_MatheMedian_DATA[i+1][0], MatheRoundPosition_FACTOR);

		float MatheMedian = MatheRoundPosition(MatheMedian_with_size(DEFAULT_test_MatheMedian_DATA[i], DEFAULT_test_MatheMedian_DATA_size_y[i/2]), MatheRoundPosition_FACTOR);

		CU_ASSERT_EQUAL(MatheMedian, result);
	}
}

void test_MatheRoundPosition(void){
	for (int i = 0; i < DEFAULT_test_MatheRoundPosition_DATA_size_x; i+=2) {
		float MatheRoundPosition = MatheRoundPosition(DEFAULT_test_MatheRoundPosition_DATA[i][0], DEFAULT_test_MatheRoundPosition_DATA[i+1][0]);

		CU_ASSERT_EQUAL(MatheRoundPosition, DEFAULT_test_MatheRoundPosition_DATA[i+1][1]);
	}
}

void test_MinMax(void){
	int arraySize = (int)MatheZufallszahl(2, 10);
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

		CU_ASSERT_EQUAL(MatheMinAtomar(x,y), mi);
		CU_ASSERT_EQUAL(MatheMaxAtomar(x,y), ma);

		if (i%arraySize == 0) {
			for (int k = 0; k < arraySize; k++) array[k] = 0;
			minArray = 0;
			maxArray = 0;
		} else {
			array[i%arraySize] = x;
			maxArray = MatheMaxAtomar(maxArray, x);
			minArray = MatheMinAtomar(minArray, x);
	
			// test with just min or max!
			CU_ASSERT_EQUAL(MatheMax_int_array_with_size(array, arraySize), maxArray);
			CU_ASSERT_EQUAL(MatheMin_int_array_with_size(array, arraySize), minArray);
		}
	}
	
	free(array);
}

void test_MatheWurzel() {
	for (int i = 0; i < NUMBER_OF_TESTS; i++) {
		float y = MatheZufallszahl(0, NUMBER_OF_TESTS);
		
		float expected = MatheRoundPosition((float) sqrt(y), MatheRoundPosition_FACTOR);
		float actual = MatheRoundPosition(MatheWurzel(y), MatheRoundPosition_FACTOR);
		CU_ASSERT_EQUAL(expected, actual);
			
		int rad = MatheZufallszahl(1, Max_SQUARE);
		
		expected = MatheRoundPosition(y, MatheRoundPosition_FACTOR);
		actual = MatheRoundPosition(MatheWurzelExp((float)pow(expected, rad), rad), MatheRoundPosition_FACTOR);

		CU_ASSERT(abs(expected-actual) <= ACCURACY);
	}
}

void test_MathePotenz() {
	for (int i = 0; i < NUMBER_OF_TESTS; i++) {
		float y = MatheZufallszahl(-NUMBER_OF_TESTS, NUMBER_OF_TESTS*2);
		int rad = MatheZufallszahl(1, Max_SQUARE);
			
		// test float version of MatheQuadrat
		float fExpected = MatheRoundPosition((float)pow(y,2), MatheRoundPosition_FACTOR);
		float fActual = MatheRoundPosition(MatheQuadrat(y), MatheRoundPosition_FACTOR);
		CU_ASSERT_EQUAL(fExpected, fActual);
		
		// test int version of MatheQuadrat
		int iExpected = (int) pow((int)y,2);
		int iActual = MatheQuadrat((int) y);
		CU_ASSERT_EQUAL(iExpected, iActual);
			
		fExpected = MatheRoundPosition(abs(y), MatheRoundPosition_FACTOR);
		fActual = MatheRoundPosition(MathePot((float)MatheWurzelExp(fExpected, rad), rad), MatheRoundPosition_FACTOR);
		CU_ASSERT(abs(fExpected-fActual) <= ACCURACY);
	}
}

void test_log() {
	for (int i = 0; i < NUMBER_OF_TESTS; i++) {
		float y = MatheZufallszahl(NUMBER_OF_TESTS, NUMBER_OF_TESTS*2);
			
		float expected = (float) log(y);
		float actual = MatheLn(y);
			
		CU_ASSERT(abs(abs(expected) - abs(actual)) <= ACCURACY);
	}
}

void test_MatheModulo() {
	for (int i = 0; i < NUMBER_OF_TESTS; i++) {
		float x = MatheZufallszahl(-NUMBER_OF_TESTS, NUMBER_OF_TESTS*2);
		float y = MatheZufallszahl(-NUMBER_OF_TESTS*2, NUMBER_OF_TESTS*4);
		if ((int)x==0) x+=2;
		
		double expected = fmod(y,x);
		double actual = MatheModulo(y, x);
		 
		CU_ASSERT(abs(abs(expected) - abs(actual)) <= ACCURACY);
		
		expected = ((int)y%(int)x);
		actual = MatheModulo((int)y,(int)x);
		
		CU_ASSERT_EQUAL(expected, actual);
	}
}

void run_All_Math_Tests() {
	test_Random();
	test_MatheStandardabw();
	test_MatheMedian();
	test_MatheRoundPosition();
	test_MinMax();
	test_MatheWurzel();
	test_MathePotenz();
	test_log();
	test_MatheModulo();
	
	print_Summary();
}
