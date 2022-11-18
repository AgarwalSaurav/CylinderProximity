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

#ifndef CYL_H
#define CYL_H 1

#include "Utils.h"
#include <iostream>

class Cyl {
	double r,l;
	double q[4];
	double O[3];
	bool fixed,hole;
	double R[3][3];

	public:
	void Set(double r1,double l1,bool fixed1,bool hole1);
	void SetOQ(double O1[3],double q1[4]);
	void Get(double &r1,double &l1,double R1[3][3],double O2[3]);
	void Get(double R1[3][3],double O2[3]);
};

#endif	/*	CYL_H	*/
