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

#define Zufallszahl(a, b) _Generic(a, long: Zufallszahl_int, int: Zufallszahl_int, double:Zufallszahl_float, float: Zufallszahl_float)(a, b)

#define Absolut(a) _Generic(a, long: Absolut_int, int: Absolut_int, double: Absolut_float, float: Absolut_float)(a)

#define modulo(a,b) _Generic(a, long:modulo_int, int:modulo_int, double:modulo_float, float:modulo_float)(a,b)

#define exp(x) pot_float(E, x)

float wurzel(float x);

float wurzelExp(float x, float y);

float pot_float(float x, float y);
int pot_int(int x, int y);

float quadrat_float(float x);
int quadrat_int(int x);

float ln(float x);

int modulo_int(int x, int y);
float modulo_float(float x, float y);

float sum_with_size(float* values, size_t size);

float durchschnitt_with_size(float* values, size_t size);

float varianz_with_size(float* values, size_t size);

float standardabw_with_size(float* values, size_t size);

float median_with_size(float* values, size_t size);

float min_float(float x, float y);
int min_int(int x, int y);
float min_float_array_with_size(float* values, size_t size);
int min_int_array_with_size(int* values, size_t size);

float max_float(float x, float y);
int max_int(int x, int y);
float max_float_array_with_size(float* values, size_t size);
int max_int_array_with_size(int* values, size_t size);

float round_position(float x, int position);

int Zufallszahl_int(int start, int size);
float Zufallszahl_float(float start, float size);

float Absolut_float(float x);
int Absolut_int(int x);
