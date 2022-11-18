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

#ifndef EQSOLVER_H
#define EQSOLVER_H
#include <math.h>
#include <cstdlib>
double fRand(double fMin = 0, double fMax = 100);
int solveQuadratic(double *, double *, int&);
int solveCubic(double *, double *, int&);
int solveQuartic(double *, double *, int & );
#endif /*EQSOLVER_H*/
