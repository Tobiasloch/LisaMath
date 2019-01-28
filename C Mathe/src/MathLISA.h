#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <time.h>

#ifndef NAN
#define NAN -1
#endif

#define COUNT_PARMS2(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _, ...) _
#define COUNT_PARMS(...)\
	COUNT_PARMS2(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)

#define CAT(A, B) CAT2(A, B)
#define CAT2(A, B) A ## B
	
#define PI 3.141592653589793
#define E 2.718281828459045

#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))

#define pot(a, b) _Generic(a, long: pot_int, int: pot_int, double:pow, float: pow)(a,b)
#define quadrat(a) _Generic(a, long: quadrat_int, int: quadrat_int, double:quadrat_float, float: quadrat_float)(a)

#define sum(a) sum_with_size(a, NELEMS(a))
#define durchschnitt(a) durchschnitt_with_size(a, NELEMS(a))
#define varianz(a) varianz_with_size(a, NELEMS(a))
#define standardabw(a) standardabw_with_size(a, NELEMS(a))
#define median(a) median_with_size(a, NELEMS(a))

#define min(a) _Generic(a, float*:min_float_array_with_size, int*: min_int_array_with_size)(a, NELEMS(a))
#define minAtomar(a,b) _Generic(a, long: min_int, int: min_int, double:min_float, float: min_float)(a,b)
	
#define max(a) _Generic(a, float*:max_float_array_with_size, int*: max_int_array_with_size)(a, NELEMS(a))
#define maxAtomar(a,b) _Generic(a, long: max_int, int: max_int, double:max_float, float: max_float)(a,b)

#define round(a) round(a)
#define roundPosition(a, b) round_position(a,b)

#define Absolut(a) _Generic(a, long: Absolut_int, int: Absolut_int, double: Absolut_float, float: Absolut_float)(a)

#define modulo(a,b) _Generic(a, long:modulo_int, int:modulo_int, double:modulo_float, float:modulo_float)(a,b)

#define exp(x) pot_float(E, x)

#define CHECK_TYPE(var,type) { __typeof(var) *__tmp; __tmp = (type *)NULL; }

#define getPI() PI

#define getE() E

#define wurzel(x) \
	({ float retval;\
	CHECK_TYPE(x,float);\
	if (x < 0) {\
		perror("Der Wert von x ist kleiner 0!\n");\
		retval = NAN;\
	} else {\
	\
	retval = sqrt(x);}\
	retval;})


#define wurzelExp(x, y) \
	({ float retval;\
	CHECK_TYPE(x,float);\
	CHECK_TYPE(x,float);\
	if (x < 0) {\
		perror("Der Wert von x ist kleiner 0!\n");\
		return NAN;\
	} else {\
	\
	retval = pow(x, (1/y));}\
	retval;})


#define quadrat_float(x) \
	({ float retval;\
	CHECK_TYPE(x,float);\
	retval = pow(x,2);\
	retval;})


#define quadrat_int(x) \
	({ int retval;\
	CHECK_TYPE(x,int);\
	retval = (int)pow((float)x,2);\
	retval;})


// pot_float is just a macro that redirects to pow
#define pot_int(x, y) \
	({ int retval;\
	CHECK_TYPE(x,int);\
	CHECK_TYPE(x,int);\
	retval = (int)pow((float)x,(float)y);\
	retval;})

#define ln(x) \
	({ float retval;\
	CHECK_TYPE(x,float);\
	if (x <=0) {\
		perror("Der Wert von x ist kleiner 0!\n");\
		return NAN;\
	} else {\
	\
	retval = log(x);}\
	retval;})

#define modulo_int(x, y) \
	({ int retval;\
	CHECK_TYPE(x,int);\
	retval = (int)fmod((float)x,(float)y);\
	retval;})

#define modulo_float(x, y) \
	({ float retval;\
	CHECK_TYPE(x,float);\
	CHECK_TYPE(y,float);\
	retval = fmod(x,y);\
	retval;})

#define sum_with_size(values, size) \
	({ float retval;\
	CHECK_TYPE(values, float*);\
	CHECK_TYPE(size, int);\
	if (size <= 0) retval = NAN;\
	else {\
	float sum = 0;\
	\
	for (int i = 0; i < size; i++) {\
		sum+=values[i];\
	}\
	\
	retval = sum;}\
	retval;})

#define durchschnitt_with_size(values, size) \
	({ float retval;\
	CHECK_TYPE(values, float*);\
	CHECK_TYPE(size, int);\
	if (size <= 0) return NAN;\
	else {\
	float s = sum_with_size(values, size);\
	\
	retval = s/size;}\
	retval;})


#define varianz_with_size(values, size) \
	({ float retval;\
	CHECK_TYPE(values, float*);\
	CHECK_TYPE(size, int);\
	if (size <= 0) return NAN;\
	else {\
	float average = durchschnitt_with_size(values, size);\
	\
	float varianz = 0;\
	for (int i = 0; i < size; i++) {\
		varianz += quadrat(values[i] - average);\
	}\
	\
	retval = varianz/size;} \
	retval;})

#define standardabw_with_size(values, size) \
	({ float retval;\
	CHECK_TYPE(values, float*);\
	CHECK_TYPE(size, int);\
	if (size <= 0) retval = NAN;\
	else {\
	float v = varianz_with_size(values, size);\
	\
	retval = sqrt(v);}\
	retval;})

// comparator for numbers
#define compPointer \
{int comp(const void * elem1, const void * elem2) \
{\
    float f = *((float*)elem1);\
    float s = *((float*)elem2);\
	\
    if (f > s) return  1;\
    if (f < s) return -1;\
    return 0;\
}\
}

#define median_with_size(values, size) \
	({ float retval;\
	CHECK_TYPE(values, float*);\
	CHECK_TYPE(size, int);\
	if (size <= 0) \
		retval = NAN;\
	else {\
	qsort(values, size, sizeof(float), compPointer);\
	\
	float m = 0;\
	if (fmod(size, 2) == 0) {\
		m = (values[size/2] + values[(size/2)-1])/2;\
	} else {\
		m = values[size/2];\
	}\
	\
	retval = m;}\
	retval;})

#define min_float(x, y) \
	({ float retval;\
	CHECK_TYPE(x, float);\
	CHECK_TYPE(y, float);\
	if (x < y) retval = x;\
	else retval = y;\
	retval;})


#define min_int(x, y) \
	({ int retval;\
	CHECK_TYPE(x, int);\
	CHECK_TYPE(y, int);\
	if (x < y) retval = x;\
	else retval = y;\
	retval;})


#define min_float_array_with_size(values, size){\
	({ float retval;\
	CHECK_TYPE(values, float*);\
	CHECK_TYPE(size, int);\
	if (size <= 0) retval = NAN;\
	else {\
	float m = values[0];\
	\
	for (int i = 1; i < size; i++) {\
		m = min_float(m, values[i]);\
	}\
	\
	retval = m;}\
	retval;})

#define min_int_array_with_size(values, size)\
	({ int retval;\
	CHECK_TYPE(values, int*);\
	CHECK_TYPE(size, int);\
	if (size <= 0) retval = (int)NAN;\
	\
	int m = values[0];\
	\
	for (int i = 1; i < size; i++) {\
		m = min_int(m, values[i]);\
	}\
	\
	retval = m;\
	retval;})


#define max_float(x, y) \
	({ float retval;\
	CHECK_TYPE(x, float);\
	CHECK_TYPE(y, float);\
	if (x > y) retval = x;\
	else retval = y;\
	retval;})

#define max_int(x, y) \
	({ int retval;\
	CHECK_TYPE(x, int);\
	CHECK_TYPE(y, int);\
	if (x > y) retval = x;\
	else retval = y;\
	retval;})

#define max_float_array_with_size(values, size)\
	({ float retval;\
	CHECK_TYPE(values, float*);\
	CHECK_TYPE(size, int);\
	if (size <= 0) retval = NAN;\
	else {\
	float m = values[0];\
	\
	for (int i = 1; i < size; i++) {\
		m = max_float(m, values[i]);\
	}\
	\
	retval = m;}\
	retval;})

#define max_int_array_with_size(values, size)\
	({ int retval;\
	CHECK_TYPE(values, int);\
	CHECK_TYPE(size, int);\
	if (size <= 0) retval = (int)NAN;\
	else {\
	int m = values[0];\
	\
	for (int i = 1; i < size; i++) {\
		m = max_int(m, values[i]);\
	}\
	\
	retval = m;}\
	retval;})

#define round_position(x, position) \
	({ float retval;\
	CHECK_TYPE(x, float);\
	CHECK_TYPE(position, int);\
	if (position < 0) retval = NAN;\
	else {\
	float p = pow(10, (float)position);\
	float r = round(x*p)/p;\
	\
	retval = r;}\
	retval;})

#define Zufallszahl_float(start, size) \
	({ float retval;\
	CHECK_TYPE(start, float);\
	CHECK_TYPE(size, float);\
	if (size < 0) retval = NAN;\
	else {\
	srand(time(NULL));\
	float r = (float)rand()/RAND_MAX;\
\
	r = (r*size)+start;\
	\
	retval = r;}\
	retval;})

#define Zufallszahl_int(start, size) \
	({ int retval;\
	CHECK_TYPE(x, int);\
	CHECK_TYPE(y, int);\
	float r = Zufallszahl_float(start, size);\
	\
	retval = (int)round(r);\
	retval;})

#define Absolut_float(x) fabs(x)

#define Absolut_int(x) (int)fabs(x)

#define Zufallszahl(a, b) _Generic(a, long: (long)round(Zufallszahl_float(start, size)), int: (int)round(Zufallszahl_float(start, size)), double:Zufallszahl_float(a,b), float: Zufallszahl_float(a,b))
