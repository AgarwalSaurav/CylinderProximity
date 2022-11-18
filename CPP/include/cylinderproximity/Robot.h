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

#ifndef ROBOT_H
#define ROBOT_H 1
#include <iostream>
#include <fstream>
#include <cmath>
#include "Utils.h"
#include "System.h"
#include "Cyl.h"

class Robot:public System
{
	//     Cyl base,baseJt,cntctBaseL2,Jt2,L2,Jt3,L3,L4,Jt5,L5,L6;
	Cyl roboCyl[11];
	public:   
	int ForwardKinem(double tht[6],double T06[4][4]);
	int InverseKinem(double T06[4][4],double tht[6]);
	int Motion(double T1[4][4],double T2[4][4],bool floatCylActive,bool rackActive);
	void SetRobo(double r[11],double l[11]);
	int Handler(double tht[5][6]);
	int SystemCollisionCheck(bool floatCylActive,bool rackActive);
};

#endif /*	ROBOT_H	*/
