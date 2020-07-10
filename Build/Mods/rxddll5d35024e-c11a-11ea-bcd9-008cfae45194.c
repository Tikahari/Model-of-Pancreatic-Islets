#include <math.h>
/*Some functions supported by numpy that aren't included in math.h
 * names and arguments match the wrappers used in rxdmath.py
 */
double factorial(const double);
double degrees(const double);
void radians(const double, double*);
double log1p(const double);
double vtrap(const double, const double);
void reaction(double** species, double** params, double** rhs, double* mult, double* species_3d, double* params_3d, double* rhs_3d, double** flux, double v)
{
	double rate;
	rate = (species[0][0])*(100000.0)-((species_3d[0])*(1000.0));
	rhs[0][0] = mult[0] * rate;
	rhs_3d[0] = mult[1] * rate;
}
