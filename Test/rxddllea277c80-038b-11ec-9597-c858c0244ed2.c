#include <math.h>
/*Some functions supported by numpy that aren't included in math.h
 * names and arguments match the wrappers used in rxdmath.py
 */
double factorial(const double);
double degrees(const double);
void radians(const double, double*);
double log1p(const double);
double vtrap(const double, const double);
void reaction(double* species_3d, double* params_3d, double* rhs)
{
	rhs[0] = Vector[31]-2000*(species_3d[0]);
}
