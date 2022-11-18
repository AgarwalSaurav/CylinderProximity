/**
 * Author: Saurav Agarwal, agr.saurav1@gmail.com
 *
 * This file is part of CylinderProximity.
 *
 * CylinderProximity is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 *
 * CylinderProximity is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with CylinderProximity. If not, see <https://www.gnu.org/licenses/>. 
 *
**/

/*
 *
 *  Utility functions to find cubic and quartic roots,
 *  coefficients are passed like this:
 *
 *      c[0] + c[1]*x + c[2]*x^2 + c[3]*x^3 + c[4]*x^4 = 0
 *
 *  The functions return the number of non-complex roots and
 *  put the values into the s array.
 *

*/



/* epsilon surrounding for near zero values */

#include "cylinderproximity/eqsolver.h"
#define     EQN_EPS     1e-9
#define	    isZero(x)	((x) > -EQN_EPS && (x) < EQN_EPS)

#ifdef NOCBRT
#define     cbrt(x)     ((x) > 0.0 ? pow((double)(x), 1.0/3.0) : ((x) < 0.0 ? -pow((double)-(x), 1.0/3.0) : 0.0))
#endif

double fRand(double fMin, double fMax)
{
	double f = (double)std::rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

int solveQuadratic(double c[], double s[], int &roots)
{
	double p, q, D;

	/* normal form: x^2 + px + q = 0 */

	if(isZero(c[2]))
	{
		roots = 0;
		return 1;
	}
	p = c[ 1 ] / (2 * c[ 2 ]);
	q = c[ 0 ] / c[ 2 ];

	D = p * p - q;

	if (isZero(D))
	{
		s[ 0 ] = - p;
		s[ 1 ] = s[ 0 ];
		roots = 1;
		return -2;
	}
	else if (D < 0)
	{
		roots = 0;
		return -1;
	}
	else if (D > 0)
	{
		double sqrt_D = sqrt(D);

		s[ 0 ] =   sqrt_D - p;
		s[ 1 ] = - sqrt_D - p;
		roots = 2;
		return 0;
	}
	return 0;
}


int solveCubic(double c[], double s[], int &roots)
{
	int     i, num;
	double  sub;
	double  A, B, C;
	double  sq_A, p, q;
	double  cb_p, D;


	if (isZero(c[ 3 ]))
	{
		roots = 0;
		return 1;
	}

	/* normal form: x^3 + Ax^2 + Bx + C = 0 */

	A = c[ 2 ] / c[ 3 ];
	B = c[ 1 ] / c[ 3 ];
	C = c[ 0 ] / c[ 3 ];

	/*  substitute x = y - A/3 to eliminate quadric term:
			x^3 +px + q = 0 */

	sq_A = A * A;
	p = 1.0/3 * (- 1.0/3 * sq_A + B);
	q = 1.0/2 * (2.0/27 * A * sq_A - 1.0/3 * A * B + C);

	/* use Cardano's formula */

	cb_p = p * p * p;
	D = q * q + cb_p;

	if (isZero(D))
	{
		if (isZero(q)) /* one triple solution */
		{
			s[ 0 ] = 0;
			num = 1;
		}
		else /* one single and one double solution */
		{
			double u = cbrt(-q);
			s[ 0 ] = 2 * u;
			s[ 1 ] = - u;
			num = 2;
		}
	}
	else if (D < 0) /* Casus irreducibilis: three real solutions */
	{
		double phi = 1.0/3 * acos(-q / sqrt(-cb_p));
		double t = 2 * sqrt(-p);

		s[ 0 ] =   t * cos(phi);
		s[ 1 ] = - t * cos(phi + M_PI / 3);
		s[ 2 ] = - t * cos(phi - M_PI / 3);
		num = 3;
	}
	else /* one real solution */
	{
		double sqrt_D = sqrt(D);
		double u = cbrt(sqrt_D - q);
		double v = - cbrt(sqrt_D + q);

		s[ 0 ] = u + v;
		num = 1;
	}

	/* resubstitute */

	sub = 1.0/3 * A;

	for (i = 0; i < num; ++i) {
		s[ i ] -= sub;
	}

	roots = num;
	return 0;
}


int solveQuartic(double c[], double s[], int &roots )
{
	double  coeffs[ 4 ];
	double  z, u, v, sub;
	double  A, B, C, D;
	double  sq_A, p, q, r;
	int     i, num;

	int ncubic = 0;
	int nquad = 0;

	if (isZero(c[ 4 ]))
	{
		roots = 0;
		return 1;
	}


	/* normal form: x^4 + Ax^3 + Bx^2 + Cx + D = 0 */

	A = c[ 3 ] / c[ 4 ];
	B = c[ 2 ] / c[ 4 ];
	C = c[ 1 ] / c[ 4 ];
	D = c[ 0 ] / c[ 4 ];

	/*  substitute x = y - A/4 to eliminate cubic term:
			x^4 + px^2 + qx + r = 0 */

	sq_A = A * A;
	p = - 3.0/8 * sq_A + B;
	q = 1.0/8 * sq_A * A - 1.0/2 * A * B + C;
	r = - 3.0/256*sq_A*sq_A + 1.0/16*sq_A*B - 1.0/4*A*C + D;

	if (isZero(r))
	{
		/* no absolute term: y(y^3 + py + q) = 0 */

		coeffs[ 0 ] = q;
		coeffs[ 1 ] = p;
		coeffs[ 2 ] = 0;
		coeffs[ 3 ] = 1;

		num = solveCubic(coeffs, s, ncubic);

		s[ num++ ] = 0;
	}
	else
	{
		/* solve the resolvent cubic ... */

		coeffs[ 0 ] = 1.0/2 * r * p - 1.0/8 * q * q;
		coeffs[ 1 ] = - r;
		coeffs[ 2 ] = - 1.0/2 * p;
		coeffs[ 3 ] = 1;

		solveCubic(coeffs, s, ncubic);

		/* ... and take the one real solution ... */

		z = s[ 0 ];

		/* ... to build two quadric equations */

		u = z * z - r;
		v = 2 * z - p;

		if (isZero(u))
			u = 0;
		else if (u > 0)
			u = sqrt(u);
		else
			return 0;

		if (isZero(v))
			v = 0;
		else if (v > 0)
			v = sqrt(v);
		else
			return 0;

		coeffs[ 0 ] = z - u;
		coeffs[ 1 ] = q < 0 ? -v : v;
		coeffs[ 2 ] = 1;

		solveQuadratic(coeffs, s, nquad);
		num = nquad;

		coeffs[ 0 ]= z + u;
		coeffs[ 1 ] = q < 0 ? v : -v;
		coeffs[ 2 ] = 1;

		solveQuadratic(coeffs, s + num, nquad);
		num += nquad;
	}

	/* resubstitute */

	sub = 1.0/4 * A;

	for (i = 0; i < num; ++i) {
		s[ i ] -= sub;
	}

	roots = num;
	return 0;
}
