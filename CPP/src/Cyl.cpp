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

#include "cylinderproximity/Cyl.h"

// Cyl::Cyl(double r1,double l1,bool fixed1,bool hole1,CylType type1)
// {
//     r=r1;
//     l=l1;
//     fixed=fixed1;
//     hole=hole1;
//     type=type1;
// }


void Cyl::Set(double r1,double l1,bool fixed1,bool hole1)
{
	r=r1;
	l=l1;
	fixed=fixed1;
	hole=hole1;     
}
void Cyl::SetOQ(double O1[3],double q1[4])
{
	O[0]=O1[0];
	O[1]=O1[1];
	O[2]=O1[2];

	q[0]=q1[0];
	q[1]=q1[1];
	q[2]=q1[2];
	q[3]=q1[3];

	q2R(q,R);
}
void Cyl::Get(double &r1,double &l1,double R1[3][3],double O2[3])
{
	r1=r;
	l1=l;
	for(int i=0;i<3;i++)
	{
		O2[i]=O[i];
		for(int j=0;j<3;j++)
			R1[i][j]=R[i][j];
	}
}
void Cyl::Get(double R1[3][3],double O2[3])
{
	for(int i=0;i<3;i++)
	{
		O2[i]=O[i];
		for(int j=0;j<3;j++)
			R1[i][j]=R[i][j];
	}
}
