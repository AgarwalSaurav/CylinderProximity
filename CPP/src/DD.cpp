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

#include "cylinderproximity/DD.h"

int EE::DD(double rD1,double lD1,double rD2,double lD2,double qD21[4],double OD21[3])
{

	/* std::cout<<"................\n";
		 std::cout<<"DD Starts Here\n";
		 std::cout<<rD1<<"\t"<<lD1<<"\t"<<rD2<<"\t"<<lD2<<"\t"<<qD21[0]<<"\t"<<qD21[1]<<"\t"<<qD21[2]<<"\t"<<qD21[3]<<"\t"<<OD21[0]<<"\t"<<OD21[1]<<"\t"<<OD21[2]<<"\n";*/


	double q[4], RD21[3][3], R[3][3];
	q2R(qD21,RD21);

	double distO21=sqrt(OD21[0]*OD21[0]+OD21[1]*OD21[1]);
	double denoRtr=1./distO21;
	double RtrCos1 = OD21[0]*denoRtr;
	double RtrSin1 = OD21[1]*denoRtr;
	double Rtr[3][3];   
	Rtr[0][0] = RtrCos1;
	Rtr[0][1] = RtrSin1;
	Rtr[0][2] = 0;
	Rtr[1][0] = -RtrSin1;
	Rtr[1][1] = RtrCos1;
	Rtr[1][2] = 0;
	Rtr[2][0] = 0;
	Rtr[2][1] = 0;
	Rtr[2][2] = 1;

	//    Transpose(Rtr,RtrF);

	MatMul(Rtr,RD21,R,0);
	R2q(R,q);
	qD21[0]=q[0];
	qD21[1]=q[1];
	qD21[2]=q[2];
	qD21[3]=q[3];

	OD21[0]=distO21;
	OD21[1]=0;



	double s21,s12;
	cc_check=0;
	DC(rD1,lD1,rD2,lD2, qD21,OD21,s21);
	cyl1_primitive=D_b;
	cyl2_primitive=C_b;
	if(s21>=1||s21<=0)
	{
		CC(rD1,lD1,rD2,lD2, qD21,OD21);
		cyl1_primitive=C_b;
	}
	double dist1=minD;
	double p1_1[3],p2_1[3];
	std::copy(p1,p1+3,p1_1);
	std::copy(p2,p2+3,p2_1);
	double qD12[4];
	// std::copy(qD21,qD21+4,qD12);
	qD12[0]=-qD12[0];
	double OD12[3]={-OD21[0],-OD21[1],-OD21[2]};
	double R12[3][3],R21[3][3];
	q2R(qD21,R21);
	q2R(qD12,R12);
	double p_OD12[3];
	MatVecMul(R12,OD12,p_OD12);
	DC(rD2,lD2,rD1,lD1,qD12,p_OD12,s12);
	cyl1_primitive=C_b;
	cyl2_primitive=D_b;
	if(s12>=1||s12<=0)
	{
		if(!cc_check)
		{
			algoPath[++algoChar]='b';
			CC(rD2,lD2,rD1,lD1,qD12,p_OD12);
			cyl2_primitive=C_b;

		}
		else
		{
			algoPath[++algoChar]='c';
			cyl1_primitive=C_b;
			cyl2_primitive=C_b;
			minD=dist1;

			std::copy(p1_1,p1_1+3,p1);
			std::copy(p2_1,p2_1+3,p2);
			pointtransform1(RtrCos1,RtrSin1,p1,p2);
			ResultDisp();
			//		std::cout<<"DD Ends Here\n";
			//	std::cout<<"................\n";
			return 0;
		}

	}
	else if(cc_check)
		algoPath[++algoChar]='b';
	else
		algoPath[++algoChar]='a';
	double dist2=minD;
	if(dist1>dist2)
	{
		double tmp_p1[3],tmp_p2[3];
		MatVecMul(R21,p1,tmp_p1);
		MatVecMul(R21,p2,tmp_p2);
		AddVec(tmp_p1,OD21,p2);
		AddVec(tmp_p2,OD21,p1);

	}
	else
	{
		minD=dist1;
		std::copy(p1_1,p1_1+3,p1);
		std::copy(p2_1,p2_1+3,p2);

	}
	pointtransform1(RtrCos1,RtrSin1,p1,p2);
	ResultDisp();
	//    std::cout<<"DD Ends Here\n";
	//    std::cout<<"................\n";
	return 0;
}
