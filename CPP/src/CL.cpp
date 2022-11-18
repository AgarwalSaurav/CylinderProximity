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

  /**************************************************************
   * Errors in the code:
   *----------------------------------------------------------------
   * 1. Correct the final proximal points
   * **************************************************************/
   #include "cylinderproximity/CL.h"
/**
 *
 * Point 1 from Circle
 * Point 2 from Line
 * 
 * */
/** @returns 	0 when successful
 * 		-1 No real solution
 * */
int EE::CL(double rD,double lD,double rS,double lS,double qSD[4],double OSD[3],double &tCL2,bool hole) {
	//    std::cout<<"................\n";
	// std::cout<<"CL Starts Here\n";
	double dist_ratio=0;

	double q[4], RSD[3][3], R[3][3];
	q2R(qSD,RSD);

	double distO21=sqrt(OSD[0]*OSD[0]+OSD[1]*OSD[1]);
	double denoRtr=1./distO21;
	double RtrCos1 = OSD[0]*denoRtr;
	double RtrSin1 = OSD[1]*denoRtr;
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

	MatMul(Rtr,RSD,R,0);
	R2q(R,q);
	qSD[0]=q[0];
	qSD[1]=q[1];
	qSD[2]=q[2];
	qSD[3]=q[3];

	OSD[0]=distO21;
	OSD[1]=0;

	double sqSD[4]={qSD[0]*qSD[0],qSD[1]*qSD[1],qSD[2]*qSD[2],qSD[3]*qSD[3]};	 
	double a[5] = {2*(qSD[0]*qSD[1] - qSD[2]*qSD[3])*(OSD[2]*(1 - 2*sqSD[1] - 2*sqSD[2]) + 
			2*(qSD[0]*qSD[2] + qSD[1]*qSD[3])*(OSD[0] - rD)),2*
		(-2*OSD[2]*(-1 + 2*sqSD[1] + 2*sqSD[2])*(qSD[0]*qSD[2] + qSD[1]*qSD[3]) + 
		 OSD[0]*(-1 + 2*qSD[0]*qSD[2] + 2*qSD[1]*qSD[3])*(1 + 2*qSD[0]*qSD[2] + 2*qSD[1]*qSD[3]) + 
		 4*(qSD[0]*(qSD[1] + qSD[2]) + (qSD[1] - qSD[2])*qSD[3])*(qSD[0]*(qSD[1] - qSD[2]) - (qSD[1] + qSD[2])*qSD[3])*rD),
		24*(qSD[0]*qSD[2] + qSD[1]*qSD[3])*(qSD[0]*qSD[1] - qSD[2]*qSD[3])*rD,
		2*(OSD[0]*(-1 + 2*qSD[0]*qSD[2] + 2*qSD[1]*qSD[3])*(1 + 2*qSD[0]*qSD[2] + 2*qSD[1]*qSD[3]) + 
				2*OSD[2]*(qSD[0]*qSD[2] + qSD[1]*qSD[3])*(sqSD[0] - sqSD[1] - sqSD[2] + sqSD[3]) + 
				4*(qSD[0]*(qSD[1] + qSD[2]) + (qSD[1] - qSD[2])*qSD[3])*(qSD[0]*(-qSD[1] + qSD[2]) + (qSD[1] + qSD[2])*qSD[3])*rD),
		-2*(qSD[0]*qSD[1] - qSD[2]*qSD[3])*(OSD[2]*(1 - 2*sqSD[1] - 2*sqSD[2]) + 
				2*(qSD[0]*qSD[2] + qSD[1]*qSD[3])*(OSD[0] + rD))};

	std::complex <double>rt [4];
	std::cout<<std::fixed<<std::setprecision(15);

	if(a[4]==0.0)
	{
		double aa[4]={a[0],a[1],a[2],a[3]}; 
		poly_roots(aa,rt,3);
		rt[3]=sqrt(-1);

	}
	else
	{
		poly_roots(a,rt,4);
	}
	double *k1;
	double cosTh1,sinTh1;
	hole?minD=0.0:minD=DBL_MAX;
	int c=0;
	for (int i=0;i<4;i++)
	{
		if(std::imag(rt[i])==0)
			c++;

	}
	if(c==0)
	{
		std::cout<<"CL Ended with no real roots\n";
		std::cout<<"................\n";
		return -1;

	}
	k1=new double [c];
	c=0;
	for (int i=0;i<4;i++)
	{
		if(imag(rt[i])==0)
		{
			k1[c]=std::real(rt[i]);
			c++;
		}    

	}
	double tcl2;
	double sk1,dist;
	for (int i=0;i<c;i++)
	{
		sk1=k1[i]*k1[i];
		cosTh1=(1-sk1)/(1+sk1);
		sinTh1=(2*k1[i])/(1+sk1);
		tcl2=(-2*qSD[0]*qSD[2]*OSD[0] - 2*qSD[1]*qSD[3]*OSD[0] + 2*qSD[0]*qSD[1]*OSD[1] - 2*qSD[2]*qSD[3]*OSD[1] -
				sqSD[0]*OSD[2] + sqSD[1]*OSD[2] + sqSD[2]*OSD[2] -
				sqSD[3]*OSD[2] + 2*(qSD[0]*qSD[2] + qSD[1]*qSD[3])*rD*cosTh1 -
				2*(qSD[0]*qSD[1] - qSD[2]*qSD[3])*rD*sinTh1)/lS;
		double t_p1[3]={rD*cosTh1,rD*sinTh1,0};
		double local_p2[3]={0,0,lS*tcl2};
		double RSD[3][3];
		q2R(qSD,RSD);
		double tmp_p2[3],t_p2[3];
		MatVecMul(RSD,local_p2,tmp_p2);
		AddVec(tmp_p2,OSD,t_p2);
		dist=distPnt(t_p1,t_p2);


		dist_ratio=(dist-rS)/dist;
		t_p2[0]=t_p1[0]-dist_ratio*(t_p1[0]-t_p2[0]);
		t_p2[1]=t_p1[1]-dist_ratio*(t_p1[1]-t_p2[1]);
		t_p2[2]=t_p1[2]-dist_ratio*(t_p1[2]-t_p2[2]);

		pointtransform1(RtrCos1,RtrSin1,t_p1,t_p2);
		if(tcl2>0&&tcl2<1&&dist<eps)
		{
			minD=0.0;
			std::copy(t_p1,t_p1+3,p1);
			std::copy(t_p2,t_p2+3,p2);
			tCL2=tcl2;

		}
		else if(hole?dist>minD:dist<minD)
		{
			minD=dist;
			std::copy(t_p1,t_p1+3,p1);
			std::copy(t_p2,t_p2+3,p2);
			tCL2=tcl2;
		}
	}
	delete [] k1;
	ResultDisp();
	//   std::cout<<"CL Ends Here\n";
	// std::cout<<"................\n";
	return 0;

}
