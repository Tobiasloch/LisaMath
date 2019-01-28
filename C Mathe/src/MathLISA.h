#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <time.h>
#include "omtcBas.h"

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

#define getPI() PI

#define getE() E

lsa_float wurzel(lsa_float x);
lsa_float wurzelExp(lsa_float x, lsa_float y);

lsa_float quadrat_float(lsa_float x);
lsa_int quadrat_int(lsa_int x);

lsa_int pot_int(lsa_int x, lsa_int y);

lsa_float ln(lsa_float x);

lsa_int modulo_int(lsa_int x, lsa_int y);
lsa_float modulo_float(lsa_float x, lsa_float y);

lsa_float sum_with_size(lsa_float* values, size_t size);
lsa_float durchschnitt_with_size(lsa_float* values, size_t size);
lsa_float varianz_with_size(lsa_float* values, size_t size);
lsa_float standardabw_with_size(lsa_float* values, size_t size);
lsa_float median_with_size(lsa_float* values, size_t size);

lsa_float min_float(lsa_float x, lsa_float y);
lsa_int min_int(lsa_int x, lsa_int y);
lsa_float min_float_array_with_size(lsa_float* values, size_t size);
lsa_int min_int_array_with_size(lsa_int* values, size_t size);

lsa_float max_float(lsa_float x, lsa_float y);
lsa_int max_int(lsa_int x, lsa_int y);
lsa_float max_float_array_with_size(lsa_float* values, size_t size);
lsa_int max_int_array_with_size(lsa_int* values, size_t size);

lsa_float round_position(lsa_float x, lsa_int position);

lsa_float Zufallszahl_float(lsa_float start, lsa_float size);
lsa_int Zufallszahl_int(lsa_int start, lsa_int size);

lsa_float Absolut_float(lsa_float x);
lsa_int Absolut_int(lsa_int x);
