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

#include "cylinderproximity/EE.h"

void EE::poly_roots(double coeff[], std::complex <double> roots[], int size) {
	/*coeff[0] is constant term*/

	double z[2*size], val;
	int narr=size+1;

	gsl_poly_complex_workspace * w
		= gsl_poly_complex_workspace_alloc (narr);

	gsl_poly_complex_solve (coeff, narr, w, z);

	gsl_poly_complex_workspace_free (w);

	for(int i=0;i<size;i++) {
		roots[i]=z[2*i]+sqrt(-1)*z[2*i+1];
	}
}
