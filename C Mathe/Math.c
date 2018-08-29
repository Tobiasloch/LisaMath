#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Math.h"

#ifdef NAN
#endif

#define PI 3.14159265359
#define E 2.71828182845

double getPI() {
	return PI;
}

double getE() {
	return E;
}

double wurzel(double x) {
	if (x < 0) {
		perror("Der Wert von x ist kleiner 0!\n");
		return NAN;
	}
	
	return sqrt(x);
}

double wurzelExp(double x, double y) {
	if (x < 0) {
		perror("Der Wert von x ist kleiner 0!\n");
		return NAN;
	}
	
	return pow(x, (1/y));
}

double pot_double(double x, double y) {
	return pow(x,y);
}

long pot_long(long x, long y) {
	return (long)pow((double)x,(double)y);
}

double quadrat_double(double x) {
	return pow(x, 2);
}

long quadrat_long(long x) {
	return pot(x,2);
}

double ln(double x) {
	if (x <=0) {
		perror("Der Wert von x ist kleiner 0!\n");
		return NAN;
	}
	
	return log(x);
}

double modulo(long x, long y) {
	return x%y;
}

double sum_with_size(double* values, size_t size) {
	if (size <= 0) return NAN;
		
	double sum = 0;
	
	for (int i = 0; i < size; i++) {
		sum+=values[i];
	}
	
	return sum;
}

double durchschnitt_with_size(double* values, size_t size) {
	if (size <= 0) return NAN;
	
	double s = sum_with_size(values, size);
	
	return s/size;
}

double varianz_with_size(double* values, size_t size) {
	if (size <= 0) return NAN;
	
	double average = durchschnitt_with_size(values, size);
	
	double varianz = 0;
	for (int i = 0; i < size; i++) {
		varianz += quadrat(values[i] - average);
	}
	
	return varianz/size;
}

double standardabw_with_size(double* values, size_t size) {
	if (size <= 0) return NAN;
	
	double v = varianz_with_size(values, size);
	
	return sqrt(v);
}

int comp(const void * elem1, const void * elem2) 
{
    double f = *((double*)elem1);
    double s = *((double*)elem2);
	
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

double median_with_size(double* values, size_t size) {
	if (size <= 0) return NAN;
	
	qsort(values, size, sizeof(double), comp);
	
	double m = 0;
	if (size%2 == 0) {
		m = (values[size/2] + values[(size/2)-1])/2;
	} else {
		m = values[size/2];
	}
	
	return m;
}

double min_double(double x, double y) {
	if (x < y) return x;
	return y;
}

long min_long(long x, long y) {
	if (x < y) return x;
	return y;
}

double min_double_array_with_size(double* values, size_t size){
	if (size <= 0) return NAN;
	
	double m = values[0];
	
	for (int i = 1; i < size; i++) {
		m = min_double(m, values[i]);
	}
	
	return m;
}

long min_long_array_with_size(long* values, size_t size){
	if (size <= 0) return (long)NAN;
	
	long m = values[0];
	
	for (int i = 1; i < size; i++) {
		m = min_long(m, values[i]);
	}
	
	return m;
}


double max_double(double x, double y) {
	if (x > y) return x;
	return y;
}

long max_long(long x, long y) {
	if (x > y) return x;
	return y;
}

double max_double_array_with_size(double* values, size_t size){
	if (size <= 0) return NAN;
	
	double m = values[0];
	
	for (int i = 1; i < size; i++) {
		m = max_double(m, values[i]);
	}
	
	return m;
}

long max_long_array_with_size(long* values, size_t size){
	if (size <= 0) return (long)NAN;
	
	long m = values[0];
	
	for (int i = 1; i < size; i++) {
		m = max_long(m, values[i]);
	}
	
	return m;
}

double round_normal(double x) {
	return (int)(x+0.5);
}

double round_position(double x, int position) {
	if (position < 0) return NAN;
	
	double p = pow(10, (double)position);
	double r = round_normal(x*p)/p;
	
	return r;
}

double Zufallszahl_double(double start, double size) {
	if (start > size) return NAN;
	
	srand(time(NULL));
	
	double r = (double)rand()/RAND_MAX;
	r = (r*size)+start;
	
	return r;
}

long Zufallszahl_long(long start, long size) {
	double r = Zufallszahl_double(start, size);
	
	return (long)round(r);
}

double Absolut_double(double x) {
	return fabs(x);
}

long Absolut_long(long x) {
	return (long)fabs(x);
}
