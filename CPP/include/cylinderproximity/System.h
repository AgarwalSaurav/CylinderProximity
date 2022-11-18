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

#ifndef SYSTEM_H
#define SYSTEM_H 1
#include "EE_Cyl.h"
#include "EE_CylHole.h"
#include "Cyl.h"   
#include "Utils.h"
class System
{
	protected:
		Cyl box[20];
		Cyl rack[8];
		Cyl floatCyl;
		EE_Cyl ob_EE;
		EE_CylHole ob_EHole;
	public:
		void SetBox(double qx[4],double qy[4],double qz[4],double Ox[8][3],double Oy[8][3],double Oz[4][3],double r,double lx,double ly,double lz);
		void SetRack(double q[4],double Obase[3],double Ohole[7][3],double rbase,double lbase, double rhole,double lhole,double rcyl,double lcyl);
		void SetFloatCyl(double r, double l);
		void SetFloatCyl(double T[4][4]);
		void SetFloatCyl(double R[3][3],double O[3]);

};

#endif	/*	SYSTEM_H	*/
