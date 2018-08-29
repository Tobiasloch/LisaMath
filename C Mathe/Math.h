#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <time.h>

#ifdef NAN
#endif

#define COUNT_PARMS2(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _, ...) _
#define COUNT_PARMS(...)\
	COUNT_PARMS2(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)

#define CAT(A, B) CAT2(A, B)
#define CAT2(A, B) A ## B
	
#define PI 3.14159265359
#define E 2.71828182845

#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))

#define pot(a, b) _Generic(a, int: pot_long, long: pot_long, float:pot_double, double: pot_double)(a,b)
#define quadrat(a) _Generic(a, int: quadrat_long, long: quadrat_long, float:quadrat_double, double: quadrat_double)(a)

#define sum(a) sum_with_size(a, NELEMS(a))
#define durchschnitt(a) durchschnitt_with_size(a, NELEMS(a))
#define varianz(a) varianz_with_size(a, NELEMS(a))
#define standardabw(a) standardabw_with_size(a, NELEMS(a))
#define median(a) median_with_size(a, NELEMS(a))

#define min1(a) _Generic(a, double*:min_double_array_with_size, long*: min_long_array_with_size)(a, NELEMS(a))
#define min2(a,b) _Generic(a, int: min_long, long: min_long, float:min_double, double: min_double)(a,b)

#define min(...)\
	CAT(min, COUNT_PARMS(__VA_ARGS__))(__VA_ARGS__)
	
	
#define max1(a) _Generic(a, double*:max_double_array_with_size, long*: max_long_array_with_size)(a, NELEMS(a))
#define max2(a,b) _Generic(a, int: max_long, long: max_long, float:max_double, double: max_double)(a,b)

#define max(...)\
	CAT(max, COUNT_PARMS(__VA_ARGS__))(__VA_ARGS__)

#define round1(a) round_normal(a)
#define round2(a, b) round_position(a,b)

#define round(...)\
	CAT(round, COUNT_PARMS(__VA_ARGS__))(__VA_ARGS__)

#define Zufallszahl(a, b) _Generic(a, int: Zufallszahl_long, long: Zufallszahl_long, float:Zufallszahl_double, double: Zufallszahl_double)(a, b)

#define Absolut(a) _Generic(a, int: Absolut_long, long: Absolut_long, float: Absolut_double, double: Absolut_double)(a)

double getPI();

double getE();

double wurzel(double x);

double wurzelExp(double x, double y);

double pot_double(double x, double y);
long pot_long(long x, long y);

double quadrat_double(double x);
long quadrat_long(long x);

double ln(double x);

double modulo(long x, long y);

double sum_with_size(double* values, size_t size);

double durchschnitt_with_size(double* values, size_t size);

double varianz_with_size(double* values, size_t size);

double standardabw_with_size(double* values, size_t size);

double median_with_size(double* values, size_t size);

double min_double(double x, double y);
long min_long(long x, long y);
double min_double_array_with_size(double* values, size_t size);
long min_long_array_with_size(long* values, size_t size);

double max_double(double x, double y);
long max_long(long x, long y);
double max_double_array_with_size(double* values, size_t size);
long max_long_array_with_size(long* values, size_t size);

double round_normal(double x);
double round_position(double x, int position);

long Zufallszahl_long(long start, long size);
double Zufallszahl_double(double start, double size);

double Absolut_double(double x);
long Absolut_long(long x);