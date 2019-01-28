#include "MathLISA.h"

float wurzel(float x) {
	if (x < 0) {
		perror("Der Wert von x ist kleiner 0!\n");
		return NAN;
	}
	
	return sqrt(x);
}

float wurzelExp(float x, float y) {
	if (x < 0) {
		perror("Der Wert von x ist kleiner 0!\n");
		return NAN;
	}
	
	return pow(x, (1/y));
}

float quadrat_float(float x) {
	return pow(x,2);
}

int quadrat_int(int x) {
	return (int)pow((float)x,2);
}
// pot_float is just a macro that redirects to pow
int pot_int(int x, int y) {
	return (int)pow((float)x,(float)y);
}

float ln(float x) {
	if (x <=0) {
		perror("Der Wert von x ist kleiner 0!\n");
		return NAN;
	}
	
	return log(x);
}

int modulo_int(int x, int y) {
	return (int)fmod((float)x,(float)y);
}

float modulo_float(float x, float y) {
	return fmod(x,y);
}

float sum_with_size(float* values, size_t size) {
	if (size <= 0) return NAN;
		
	float sum = 0;
	
	for (int i = 0; i < size; i++) {
		sum+=values[i];
	}
	
	return sum;
}

float durchschnitt_with_size(float* values, size_t size) {
	if (size <= 0) return NAN;
	
	float s = sum_with_size(values, size);
	
	return s/size;
}

float varianz_with_size(float* values, size_t size) {
	if (size <= 0) return NAN;
	
	float average = durchschnitt_with_size(values, size);
	
	float varianz = 0;
	for (int i = 0; i < size; i++) {
		varianz += quadrat(values[i] - average);
	}
	
	return varianz/size;
}

float standardabw_with_size(float* values, size_t size) {
	if (size <= 0) return NAN;
	
	float v = varianz_with_size(values, size);
	
	return sqrt(v);
}

// comparator for numbers
int comp(const void * elem1, const void * elem2) 
{
    float f = *((float*)elem1);
    float s = *((float*)elem2);
	
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

float median_with_size(float* values, size_t size) {
	if (size <= 0) return NAN;
	
	qsort(values, size, sizeof(float), comp);
	
	float m = 0;
	if (fmod(size, 2) == 0) {
		m = (values[size/2] + values[(size/2)-1])/2;
	} else {
		m = values[size/2];
	}
	
	return m;
}

float min_float(float x, float y) {
	if (x < y) return x;
	return y;
}

int min_int(int x, int y) {
	if (x < y) return x;
	return y;
}

float min_float_array_with_size(float* values, size_t size){
	if (size <= 0) return NAN;
	
	float m = values[0];
	
	for (int i = 1; i < size; i++) {
		m = min_float(m, values[i]);
	}
	
	return m;
}

int min_int_array_with_size(int* values, size_t size){
	if (size <= 0) return (int)NAN;
	
	int m = values[0];
	
	for (int i = 1; i < size; i++) {
		m = min_int(m, values[i]);
	}
	
	return m;
}


float max_float(float x, float y) {
	if (x > y) return x;
	return y;
}

int max_int(int x, int y) {
	if (x > y) return x;
	return y;
}

float max_float_array_with_size(float* values, size_t size){
	if (size <= 0) return NAN;
	
	float m = values[0];
	
	for (int i = 1; i < size; i++) {
		m = max_float(m, values[i]);
	}
	
	return m;
}

int max_int_array_with_size(int* values, size_t size){
	if (size <= 0) return (int)NAN;
	
	int m = values[0];
	
	for (int i = 1; i < size; i++) {
		m = max_int(m, values[i]);
	}
	
	return m;
}

float round_position(float x, int position) {
	if (position < 0) return NAN;
	
	float p = pow(10, (float)position);
	float r = round(x*p)/p;
	
	return r;
}

float Zufallszahl_float(float start, float size) {
	if (size < 0) return NAN;
	
	srand(time(NULL));
	float r = (float)rand()/RAND_MAX;

	r = (r*size)+start;
	
	return r;
}

int Zufallszahl_int(int start, int size) {
	float r = Zufallszahl_float(start, size);
	
	return (int)round(r);
}

float Absolut_float(float x) {
	return fabs(x);
}

int Absolut_int(int x) {
	return (int)fabs(x);
}
