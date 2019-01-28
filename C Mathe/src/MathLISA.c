#include "MathLISA.h"

lsa_float MatheWurzel(lsa_float x) {
	if (x < 0) {
		perror("Der Wert von x ist kleiner 0!\n");
		return NAN;
	}
	
	return sqrt(x);
}

lsa_float MatheWurzelExp(lsa_float x, lsa_float y) {
	if (x < 0) {
		perror("Der Wert von x ist kleiner 0!\n");
		return NAN;
	}
	
	return pow(x, (1/y));
}

lsa_float MatheQuadrat_float(lsa_float x) {
	return pow(x,2);
}

lsa_int MatheQuadrat_int(lsa_int x) {
	return (lsa_int)pow((lsa_float)x,2);
}
// pot_float is just a macro that redirects to pow
lsa_int MathePot_int(lsa_int x, lsa_int y) {
	return (lsa_int)pow((lsa_float)x,(lsa_float)y);
}

lsa_float MatheLn(lsa_float x) {
	if (x <=0) {
		perror("Der Wert von x ist kleiner 0!\n");
		return NAN;
	}
	
	return log(x);
}

lsa_int MatheModulo_int(lsa_int x, lsa_int y) {
	return (lsa_int)fmod((lsa_float)x,(lsa_float)y);
}

lsa_float MatheModulo_float(lsa_float x, lsa_float y) {
	return fmod(x,y);
}

lsa_float MatheSum_with_size(lsa_float* values, size_t size) {
	if (size <= 0) return NAN;
		
	lsa_float sum = 0;
	
	for (lsa_int i = 0; i < size; i++) {
		sum+=values[i];
	}
	
	return sum;
}

lsa_float MatheDurchschnitt_with_size(lsa_float* values, size_t size) {
	if (size <= 0) return NAN;
	
	lsa_float s = MatheSum_with_size(values, size);
	
	return s/size;
}

lsa_float MatheVarianz_with_size(lsa_float* values, size_t size) {
	if (size <= 0) return NAN;
	
	lsa_float average = MatheDurchschnitt_with_size(values, size);
	
	lsa_float varianz = 0;
	for (lsa_int i = 0; i < size; i++) {
		varianz += MatheQuadrat_float(values[i] - average);
	}
	
	return varianz/size;
}

lsa_float MatheStandardabw_with_size(lsa_float* values, size_t size) {
	if (size <= 0) return NAN;
	
	lsa_float v = MatheVarianz_with_size(values, size);
	
	return sqrt(v);
}

// comparator for numbers
lsa_int comp(const void * elem1, const void * elem2) 
{
    lsa_float f = *((lsa_float*)elem1);
    lsa_float s = *((lsa_float*)elem2);
	
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

lsa_float MatheMedian_with_size(lsa_float* values, size_t size) {
	if (size <= 0) return NAN;
	
	qsort(values, size, sizeof(lsa_float), comp);
	
	lsa_float m = 0;
	if (fmod(size, 2) == 0) {
		m = (values[size/2] + values[(size/2)-1])/2;
	} else {
		m = values[size/2];
	}
	
	return m;
}

lsa_float MatheMin_float(lsa_float x, lsa_float y) {
	if (x < y) return x;
	return y;
}

lsa_int MatheMin_int(lsa_int x, lsa_int y) {
	if (x < y) return x;
	return y;
}

lsa_float MatheMin_float_array_with_size(lsa_float* values, size_t size){
	if (size <= 0) return NAN;
	
	lsa_float m = values[0];
	
	for (lsa_int i = 1; i < size; i++) {
		m = MatheMin_float(m, values[i]);
	}
	
	return m;
}

lsa_int MatheMin_int_array_with_size(lsa_int* values, size_t size){
	if (size <= 0) return (lsa_int)NAN;
	
	lsa_int m = values[0];
	
	for (lsa_int i = 1; i < size; i++) {
		m = MatheMin_int(m, values[i]);
	}
	
	return m;
}


lsa_float MatheMax_float(lsa_float x, lsa_float y) {
	if (x > y) return x;
	return y;
}

lsa_int MatheMax_int(lsa_int x, lsa_int y) {
	if (x > y) return x;
	return y;
}

lsa_float MatheMax_float_array_with_size(lsa_float* values, size_t size){
	if (size <= 0) return NAN;
	
	lsa_float m = values[0];
	
	for (lsa_int i = 1; i < size; i++) {
		m = MatheMax_float(m, values[i]);
	}
	
	return m;
}

lsa_int MatheMax_int_array_with_size(lsa_int* values, size_t size){
	if (size <= 0) return (lsa_int)NAN;
	
	lsa_int m = values[0];
	
	for (lsa_int i = 1; i < size; i++) {
		m = MatheMax_int(m, values[i]);
	}
	
	return m;
}

lsa_float MatheRound_position(lsa_float x, lsa_int position) {
	if (position < 0) return NAN;
	
	lsa_float p = pow(10, (lsa_float)position);
	lsa_float r = MatheRound(x*p)/p;
	
	return r;
}

lsa_float MatheZufallszahl_float(lsa_float start, lsa_float size) {
	if (size < 0) return NAN;
	
	srand(time(NULL));
	lsa_float r = (lsa_float)rand()/RAND_MAX;

	r = (r*size)+start;
	
	return r;
}

lsa_int MatheZufallszahl_int(lsa_int start, lsa_int size) {
	lsa_float r = MatheZufallszahl_float(start, size);
	
	return (lsa_int)round(r);
}

lsa_float MatheAbsolut_float(lsa_float x) {
	return fabs(x);
}

lsa_int MatheAbsolut_int(lsa_int x) {
	return (lsa_int)fabs(x);
}
