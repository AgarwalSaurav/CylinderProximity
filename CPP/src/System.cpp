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

#include "cylinderproximity/System.h"

void System::SetBox(double qx[4],double qy[4],double qz[4],double Ox[8][3],double Oy[8][3],double Oz[4][3],double r, double lx,double ly,double lz)
{
	int c=0;

	for(int i=0;i<4;i++)
	{
		box[c].Set(r,lz,1,0);
		box[c].SetOQ(Oz[i],qz);
		c++;
	}
	for(int i=0;i<8;i++)
	{
		box[c].Set(r,lx,1,0);
		box[c].SetOQ(Ox[i],qx);
		c++;
		box[c].Set(r,ly,1,0);
		box[c].SetOQ(Oy[i],qy);
		c++;
	}
}
void System::SetRack(double q[4],double Obase[3],double Ohole[7][3],double rbase,double lbase, double rhole,double lhole,double rcyl,double lcyl)
{
	int c=0;
	rack[c].Set(rbase,lbase,1,0);
	rack[c].SetOQ(Obase,q);
	c++;
	for(int i=0;i<6;i++)
	{
		rack[c].Set(rcyl,lcyl,1,0);
		rack[c].SetOQ(Ohole[i],q);
		c++;
	}
	rack[c].Set(rhole,lhole,1,1);
	rack[c].SetOQ(Ohole[6],q);

}
void System::SetFloatCyl(double r, double l)
{
	floatCyl.Set(r,l,0,0);
}
void System::SetFloatCyl(double T[4][4])
{
	double O[3];
	double q[4];
	T2OQ(T,O,q);
	floatCyl.SetOQ(O,q);
}
void System::SetFloatCyl(double R[3][3],double O[3])
{

	double q[4];
	R2q(R,q);
	floatCyl.SetOQ(O,q);
}
