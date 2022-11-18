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

#include "cylinderproximity/EE_CylHole.h"

int EE_CylHole::Handler()
{
	if(Degen())
		return -1;
	SS();
	if(t1>0 && t1<1 && t2>0 && t2<1)
		CollisionCheck();
	double q[4]={q0,q1,q2,q3};
	double O21[3]={O2x,O2y,O2z};
	double t;
	CL(r1,l1,r2,l2,q,O21,t,1);
	if(t>0&&t<1)
		CollisionCheck();
	//     if (Case1_1())
	// 	exit(1);
	//     ResultDisp();
	//     CollisionCheck();
	//     CylOwnCheck();
	return 0;

}

