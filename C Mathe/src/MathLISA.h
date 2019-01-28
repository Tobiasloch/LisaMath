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

#define MathePot(a, b) _Generic(a, lsa_int: MathePot_int, lsa_float: pow)(a,b)
#define MatheQuadrat(a) _Generic(a, lsa_int: MatheQuadrat_int, lsa_float: MatheQuadrat_float)(a)

#define MatheSum(a) MatheSum_with_size(a, NELEMS(a))
#define MatheDurchschnitt(a) MatheDurchschnitt_with_size(a, NELEMS(a))
#define MatheVarianz(a) MatheVarianz_with_size(a, NELEMS(a))
#define MatheStandardabw(a) MatheStandardabw_with_size(a, NELEMS(a))
#define MatheMedian(a) MatheMedian_with_size(a, NELEMS(a))

#define MatheMin(a) _Generic(a, lsa_float*:MatheMin_float_array_with_size, lsa_int*: MatheMin_int_array_with_size)(a, NELEMS(a))
#define MatheMinAtomar(a,b) _Generic(a, lsa_int: MatheMin_int, lsa_int: MatheMin_int, double:MatheMin_float, lsa_float: MatheMin_float)(a,b)
	
#define MatheMax(a) _Generic(a, lsa_float*:MatheMax_float_array_with_size, lsa_int*: MatheMax_int_array_with_size)(a, NELEMS(a))
#define MatheMaxAtomar(a,b) _Generic(a, lsa_int: MatheMax_int, lsa_float: MatheMax_float)(a,b)

#define MatheRound(a) round(a)
#define MatheRoundPosition(a, b) MatheRound_position(a,b)

#define MatheZufallszahl(a, b) _Generic(a, lsa_int: MatheZufallszahl_int, lsa_float: MatheZufallszahl_float)(a, b)

#define MatheAbsolut(a) _Generic(a, lsa_int: MatheAbsolut_int, lsa_float: MatheAbsolut_float)(a)

#define MatheModulo(a,b) _Generic(a, lsa_int:MatheModulo_int, lsa_float:MatheModulo_float)(a,b)

#define MatheExp(x) pot_float(E, x)

#define MatheGetPI() PI

#define MatheGetE() E

lsa_float MatheWurzel(lsa_float x);
lsa_float MatheWurzelExp(lsa_float x, lsa_float y);

lsa_float MatheQuadrat_float(lsa_float x);
lsa_int MatheQuadrat_int(lsa_int x);

lsa_int MathePot_int(lsa_int x, lsa_int y);

lsa_float MatheLn(lsa_float x);

lsa_int MatheModulo_int(lsa_int x, lsa_int y);
lsa_float MatheModulo_float(lsa_float x, lsa_float y);

lsa_float MatheSum_with_size(lsa_float* values, size_t size);
lsa_float MatheDurchschnitt_with_size(lsa_float* values, size_t size);
lsa_float MatheVarianz_with_size(lsa_float* values, size_t size);
lsa_float MatheStandardabw_with_size(lsa_float* values, size_t size);
lsa_float MatheMedian_with_size(lsa_float* values, size_t size);

lsa_float MatheMin_float(lsa_float x, lsa_float y);
lsa_int MatheMin_int(lsa_int x, lsa_int y);
lsa_float MatheMin_float_array_with_size(lsa_float* values, size_t size);
lsa_int MatheMin_int_array_with_size(lsa_int* values, size_t size);

lsa_float MatheMax_float(lsa_float x, lsa_float y);
lsa_int MatheMax_int(lsa_int x, lsa_int y);
lsa_float MatheMax_float_array_with_size(lsa_float* values, size_t size);
lsa_int MatheMax_int_array_with_size(lsa_int* values, size_t size);

lsa_float MatheRound_position(lsa_float x, lsa_int position);

lsa_float MatheZufallszahl_float(lsa_float start, lsa_float size);
lsa_int MatheZufallszahl_int(lsa_int start, lsa_int size);

lsa_float MatheAbsolut_float(lsa_float x);
lsa_int MatheAbsolut_int(lsa_int x);
