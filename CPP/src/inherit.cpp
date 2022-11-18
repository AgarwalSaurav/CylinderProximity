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

#include <iostream>
class EE
{
	double r, l;
	public:
	virtual int handler()=0;
	int func();
	int func1(double r, double l);
	void Set(double r,double l);
};
void EE::Set(double r1,double l1)
{
	r=r1;
	l=l1;

}
int EE::func()
{
	std::cout<<"In   .func\n";
	std::cout<<"r="<<r<<"\t"<<"l="<<l<<"\n";
	return 0;

}
int EE::func1(double r,double l)
{
	std::cout<<"In func1\n";
	std::cout<<"r="<<r<<"\t"<<"l="<<l<<"\n";
	return 0;

}
class EE_00:public EE
{
	//     double r, l;
	public:
		//     EE_00(double r1=0.0,double l1=0.0):r(r1),l(l1)
		//     {
		// 	
		//     }
		int handler ()
		{
			std::cout<<"Handler of class EE_00\n";
			func();
			func1(5,10);
			return 0;
		}
		int func1(double r, double l);


};
int EE_00::func1(double r,double l)
{
	std::cout<<"In modified func1\n";
	std::cout<<"r="<<r<<"\t"<<"l="<<l<<"\n";
	return 0;

}

class EE_01:public EE
{
	double r, l;
	public:

	//     EE_01(double r1=0.0,double l1=0.0):r(r1),l(l1)
	//     {
	// 	
	//     }
	int handler ()
	{
		std::cout<<"Handler of class EE_01\n";
		func();
		func1(0.0,0.0);
		return 0;
	}

};
int main()
{
	EE_00 obEE_00;
	EE_01 obEE_01;
	EE* basep[]={&obEE_00,&obEE_01};
	//     std::cout<<"size of basep"<<sizeof(basep)<<"\n";
	for(int i=0;i<2;i++)
	{
		std::cout<<i<<"\n";
		basep[i]-> Set(5,10);
		basep[i]-> handler();

	}
	return 0;

}
