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

#include "cylinderproximity/EE_Rand.h"

int EE_Rand::Handler()
{

	DisplayInput();
	if(Degen())
	{    ResultDisp();
		return -1;
	}
	if (Case1_1())
		exit(1);
	ResultDisp();
	CollisionCheck();
	//CylOwnCheck();

	return 0;

}
void EE_Rand::WriteFile(std::fstream& ioRandCheck)
{
	double q_temp[4]={q0,q1,q2,q3};
	double R_temp[3][3];
	q2R(q_temp,R_temp);
	ioRandCheck<<r1<<","<<l1<<","<<r2<<","<<l2<<","<<cyl1_primitive<<","<<cyl2_primitive<<","<<algoPath[0]<<algoPath[1]<<algoPath[2]<<algoPath[3]<<algoPath[4]<<","<<minD<<","<<p1[0]<<","<<p1[1]<<","<<p1[2]<<","<<p2[0]<<","<<p2[1]<<","<<p2[2]<<","<<q0<<","<<q1<<","<<q2<<","<<q3<<","<<R_temp[0][0]<<","<<R_temp[0][1]<<","<<R_temp[0][2]<<","<<O2x<<","<<R_temp[1][0]<<","<<R_temp[1][1]<<","<<R_temp[1][2]<<","<<O2y<<","<<R_temp[2][0]<<","<<R_temp[2][1]<<","<<R_temp[2][2]<<","<<O2z<<","<<kvec[0]<<","<<kvec[1]<<","<<kvec[2]<<","<<kphi<<"\n";
}
