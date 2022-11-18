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

#include "cylinderproximity/SS.h"
int EE::SS()
{
	//	std::cout<<"................\n";
	//	std::cout<<"SS Starts Here\n";

	double q[4]={q0,q1,q2,q3};
	double R[3][3];
	q2R(q,R);
	double sq0=q0*q0;
	double sq1=q1*q1;
	double sq2=q2*q2;
	double sq3=q3*q3;

	double mA=q0*q2+q1*q3;
	double mB=(-q0*q1+q2*q3);
	double mC=0.0;

	double jA=q0*q2-q1*q3;
	double jB=-(q0*q1+q2*q3);
	double jC=0.0;

	double th1m[2]={};
	int flagM,flagJ,flagK_J1,flagK_J0,flagK_M0,flagK_M1;
	double tM0J[2][2],tM1J[2][2],tK_M0[2][2],tK_M1[2][2],tK_J0[2][2],tK_J1[2][2];

	double t1M=1/(4*l1*l2*(sq1 + sq2)*(sq0 + sq3));
	double t1C1=(2*l2*sq0*q0*q2*r1 - 2*l2*q0*sq1*q2*r1 - 2*l2*q0*sq2*q2*r1 + 2*l2*sq0*q1*q3*r1 - 2*l2*sq1*q1*q3*r1 - 2*l2*q1*sq2*q3*r1 + 2*l2*q0*q2*sq3*r1 + 2*l2*q1*sq3*q3*r1);
	double t1S1=2*(q0 *q1 - q2*q3)*r1*-l2*(sq0 - sq1 - sq2 + sq3); 
	double t1C2=l2*2*(-q0*q2 + q1*q3)*r2;
	double t1S2=l2*2*(q0*q1 + q2*q3)*r2;
	// 	double t1C2=l2*((sq0 + sq1 + sq2 + sq3)*(sq0 + sq1 + sq2 + sq3))*2*(-q0*q2 + q1*q3)*r2;
	// 	double t1S2=l2*((sq0 + sq1 + sq2 + sq3)*(sq0 + sq1 + sq2 + sq3))*2*(q0*q1 + q2*q3)*r2;
	double t1C=l2*O2z - l2*(sq0 - sq1 - sq2 + sq3)*(2*O2x*(q0*q2 + q1*q3) + (sq0 - sq1 - sq2 + sq3)*O2z);

	double t2M=1/(2*l2*(sq1 + sq2)*(sq0 + sq3));
	double t2C1=(q0*q2 + q1*q3) *r1;
	double t2C=(q0*(-q2*O2x ) - q3*(q1*O2x));
	double t2S1=(-q0*q1 + q2*q3)*r1;
	double t2C2=(sq0 - sq1 - sq2 + sq3)*r2*(-q0*q2 + q1*q3) ;
	double t2S2=(sq0 - sq1 - sq2 + sq3)*r2*(q0*q1 + q2*q3);

	minD=DBL_MAX;
	ss_minD=DBL_MAX;
	// 	double p	1[3],p2[3];
	flagM=EqnTrig(mA,mB,mC,th1m);
	if(!flagM)
	{
		double cosTh1m0=cos(th1m[0]);
		double sinTh1m0=sin(th1m[0]);
		double cosTh1m1=cos(th1m[1]);
		double sinTh1m1=sin(th1m[1]);

		double kCm[2]={(q0*q1-q2*q3)*O2x+(-q0*q1+q2*q3)*r1*cosTh1m0-(q0*q2+q1*q3)*r1*sinTh1m0,
			(q0*q1-q2*q3)*O2x+(-q0*q1+q2*q3)*r1*cosTh1m1-(q0*q2+q1*q3)*r1*sinTh1m1};
		double kAm=r2*(q0*q1+q2*q3);
		double kBm=r2*(q0*q2-q1*q3);
		double th2m1[2]={},th2m2[2]={};
		flagK_M0=EqnTrig(kAm,kBm,kCm[0],th2m1);
		if(!flagK_M0)
		{

			tK_M0[0][0]=t1M*(t1C+t1C2*cos(th2m1[0])+t1S2*sin(th2m1[0])+t1C1*cosTh1m0+t1S1*sinTh1m0);
			tK_M0[0][1]=t1M*(t1C+t1C2*cos(th2m1[1])+t1S2*sin(th2m1[1])+t1C1*cosTh1m0+t1S1*sinTh1m0);
			tK_M0[1][0]=t2M*(t2C+t2C2*cos(th2m1[0])+t2S2*sin(th2m1[0])+t2C1*cosTh1m0+t2S1*sinTh1m0);
			tK_M0[1][1]=t2M*(t2C+t2C2*cos(th2m1[1])+t2S2*sin(th2m1[1])+t2C1*cosTh1m0+t2S1*sinTh1m0);
			//	std::cout<<"t1="<<tK_M0[0][0]<<"\t"<<"t2="<<tK_M0[1][0]<<"\t"<<"tht1="<<th1m[0]<<"\t"<<"tht2="<<th2m1[0]<<"\n";
			if(!SS_aux(R,th1m[0],th2m1[0],tK_M0[0][0],tK_M0[1][0],ss_minD,p1,p2))
			{
				t1=tK_M0[0][0];
				t2=tK_M0[1][0];
				//			std::cout<<"1\n";
			}
			//	std::cout<<"t1="<<tK_M0[0][1]<<"\t"<<"t2="<<tK_M0[1][1]<<"\t"<<"tht1="<<th1m[0]<<"\t"<<"tht2="<<th2m1[1]<<"\n";
			if(!SS_aux(R,th1m[0],th2m1[1],tK_M0[0][1],tK_M0[1][1],ss_minD,p1,p2))
			{
				t1=tK_M0[0][1];
				t2=tK_M0[1][1];
				//	std::cout<<"2\n";
			}

		}
		flagK_M1=EqnTrig(kAm,kBm,kCm[1],th2m2);
		if(!flagK_M1)
		{
			tK_M1[0][0]=t1M*(t1C+t1C2*cos(th2m2[0])+t1S2*sin(th2m2[0])+t1C1*cosTh1m1+t1S1*sinTh1m1);
			tK_M1[0][1]=t1M*(t1C+t1C2*cos(th2m2[1])+t1S2*sin(th2m2[1])+t1C1*cosTh1m1+t1S1*sinTh1m1);
			tK_M1[1][0]=t2M*(t2C+t2C2*cos(th2m2[0])+t2S2*sin(th2m2[0])+t2C1*cosTh1m1+t2S1*sinTh1m1);
			tK_M1[1][1]=t2M*(t2C+t2C2*cos(th2m2[1])+t2S2*sin(th2m2[1])+t2C1*cosTh1m1+t2S1*sinTh1m1);
			//	std::cout<<"t1="<<tK_M1[0][0]<<"\t"<<"t2="<<tK_M1[1][0]<<"\t"<<"tht1="<<th1m[1]<<"\t"<<"tht2="<<th2m2[0]<<"\n";
			if(!SS_aux(R,th1m[1],th2m2[0],tK_M1[0][0],tK_M1[1][0],ss_minD,p1,p2))
			{
				t1=tK_M1[0][0];
				t2=tK_M1[1][0];
				//		std::cout<<"3\n";
			}
			//		std::cout<<"t1="<<tK_M1[0][1]<<"\t"<<"t2="<<tK_M1[1][1]<<"\t"<<"tht1="<<th1m[1]<<"\t"<<"tht2="<<th2m2[1]<<"\n";
			if(!SS_aux(R,th1m[1],th2m2[1],tK_M1[0][1],tK_M1[1][1],ss_minD,p1,p2))
			{
				t1=tK_M1[0][1];
				t2=tK_M1[1][1];
				//	std::cout<<"4\n";
			}
		}
	}
	double th2j[2]={};
	flagJ=EqnTrig(jA,jB,jC,th2j);
	if(!flagJ)
	{
		double sinTh2j0=sin(th2j[0]);
		double cosTh2j0=cos(th2j[0]);
		double sinTh2j1=sin(th2j[1]);
		double cosTh2j1=cos(th2j[1]);

		double cosTh1m0=cos(th1m[0]);
		double sinTh1m0=sin(th1m[0]);
		double cosTh1m1=cos(th1m[1]);
		double sinTh1m1=sin(th1m[1]);

		double kCj[2]={(q0*q1-q2*q3)*O2x+(q0*q1+q2*q3)*r2*cosTh2j0+(q0*q2-q1*q3)*r2*sinTh2j0,
			(q0*q1-q2*q3)*O2x+(q0*q1+q2*q3)*r2*cosTh2j1+(q0*q2-q1*q3)*r2*sinTh2j1};
		double kAj=r1*(-q0*q1+q2*q3);
		double kBj=-r1*(q0*q2+q1*q3);
		double th1j1[2]={},th1j2[2]={};
		flagK_J0=EqnTrig(kAj,kBj,kCj[0],th1j1);
		if(!flagK_J0)
		{
			tK_J0[0][0]=t1M*(t1C+t1C2*cosTh2j0+t1S2*sinTh2j0+t1C1*cos(th1j1[0])+t1S1*sin(th1j1[0]));
			tK_J0[0][1]=t1M*(t1C+t1C2*cosTh2j0+t1S2*sinTh2j0+t1C1*cos(th1j1[1])+t1S1*sin(th1j1[1]));
			tK_J0[1][0]=t2M*(t2C+t2C2*cosTh2j0+t2S2*sinTh2j0+t2C1*cos(th1j1[0])+t2S1*sin(th1j1[0]));
			tK_J0[1][1]=t2M*(t2C+t2C2*cosTh2j0+t2S2*sinTh2j0+t2C1*cos(th1j1[1])+t2S1*sin(th1j1[1]));
			//		std::cout<<"t1="<<tK_J0[0][0]<<"\t"<<"t2="<<tK_J0[1][0]<<"\t"<<"tht1="<<th1j1[0]<<"\t"<<"tht2="<<th2j[0]<<"\n";
			if(!SS_aux(R,th1j1[0],th2j[0],tK_J0[0][0],tK_J0[1][0],ss_minD,p1,p2))
			{
				t1=tK_J0[0][0];
				t2=tK_J0[1][0];
				//	std::cout<<"5\n";
			}
			//	std::cout<<"t1="<<tK_J0[0][1]<<"\t"<<"t2="<<tK_J0[1][1]<<"\t"<<"tht1="<<th1j1[1]<<"\t"<<"tht2="<<th2j[0]<<"\n";
			if(!SS_aux(R,th1j1[1],th2j[0],tK_J0[0][1],tK_J0[1][1],ss_minD,p1,p2))
			{
				t1=tK_J0[0][1];
				t2=tK_J0[1][1];
				//	std::cout<<"6\n";
			}	
		}
		flagK_J1=EqnTrig(kAj,kBj,kCj[1],th1j2);			    
		if(!flagK_J1)
		{
			tK_J1[0][0]=t1M*(t1C+t1C2*cosTh2j1+t1S2*sinTh2j1+t1C1*cos(th1j2[0])+t1S1*sin(th1j2[0]));
			tK_J1[0][1]=t1M*(t1C+t1C2*cosTh2j1+t1S2*sinTh2j1+t1C1*cos(th1j2[1])+t1S1*sin(th1j2[1]));
			tK_J1[1][0]=t2M*(t2C+t2C2*cosTh2j1+t2S2*sinTh2j1+t2C1*cos(th1j2[0])+t2S1*sin(th1j2[0]));
			tK_J1[1][1]=t2M*(t2C+t2C2*cosTh2j1+t2S2*sinTh2j1+t2C1*cos(th1j2[1])+t2S1*sin(th1j2[1]));
			//	std::cout<<"t1="<<tK_J1[0][0]<<"\t"<<"t2="<<tK_J1[1][0]<<"\t"<<"tht1="<<th1j2[0]<<"\t"<<"tht2="<<th2j[1]<<"\n";
			if(!SS_aux(R,th1j2[0],th2j[1],tK_J1[0][0],tK_J1[1][0],ss_minD,p1,p2))
			{
				t1=tK_J1[0][0];
				t2=tK_J1[1][0];
				//	std::cout<<"7\n";
			}
			//		std::cout<<"t1="<<tK_J1[0][1]<<"\t"<<"t2="<<tK_J1[1][1]<<"\t"<<"tht1="<<th1j2[1]<<"\t"<<"tht2="<<th2j[1]<<"\n";
			if(!SS_aux(R,th1j2[1],th2j[1],tK_J1[0][1],tK_J1[1][1],ss_minD,p1,p2))
			{
				t1=tK_J1[0][1];
				t2=tK_J1[1][1];
				//	std::cout<<"8\n";
			}		
		}    
		if(!flagM)
		{
			tM0J[0][0]=t1M*(t1C+t1C2*cosTh2j0+t1S2*sinTh2j0+t1C1*cosTh1m0+t1S1*sinTh1m0);
			tM0J[0][1]=t1M*(t1C+t1C2*cosTh2j1+t1S2*sinTh2j1+t1C1*cosTh1m0+t1S1*sinTh1m0);
			tM0J[1][0]=t2M*(t2C+t2C2*cosTh2j0+t2S2*sinTh2j0+t2C1*cosTh1m0+t2S1*sinTh1m0);
			tM0J[1][1]=t2M*(t2C+t2C2*cosTh2j1+t2S2*sinTh2j1+t2C1*cosTh1m0+t2S1*sinTh1m0);
			//	std::cout<<"t1="<<tM0J[0][0]<<"\t"<<"t2="<<tM0J[1][0]<<"\t"<<"tht1="<<th1m[0]<<"\t"<<"tht2="<<th2j[0]<<"\n";
			if(!SS_aux(R,th1m[0],th2j[0],tM0J[0][0],tM0J[1][0],ss_minD,p1,p2))
			{
				t1=tM0J[0][0];
				t2=tM0J[1][0];
				////std::cout<<"9\n";
			}
			//		std::cout<<"t1="<<tM0J[0][1]<<"\t"<<"t2="<<tM0J[1][1]<<"\t"<<"tht1="<<th1m[0]<<"\t"<<"tht2="<<th2j[1]<<"\n";
			if(!SS_aux(R,th1m[0],th2j[1],tM0J[0][1],tM0J[1][1],ss_minD,p1,p2))
			{
				t1=tM0J[0][1];
				t2=tM0J[1][1];
				////std::cout<<"10\n";
			}

			tM1J[0][0]=t1M*(t1C+t1C2*cosTh2j0+t1S2*sinTh2j0+t1C1*cosTh1m1+t1S1*sinTh1m1);
			tM1J[0][1]=t1M*(t1C+t1C2*cosTh2j1+t1S2*sinTh2j1+t1C1*cosTh1m1+t1S1*sinTh1m1);
			tM1J[1][0]=t2M*(t2C+t2C2*cosTh2j0+t2S2*sinTh2j0+t2C1*cosTh1m1+t2S1*sinTh1m1);
			tM1J[1][1]=t2M*(t2C+t2C2*cosTh2j1+t2S2*sinTh2j1+t2C1*cosTh1m1+t2S1*sinTh1m1);
			//	std::cout<<"t1="<<tM1J[0][0]<<"\t"<<"t2="<<tM1J[1][0]<<"\t"<<"tht1="<<th1m[1]<<"\t"<<"tht2="<<th2j[0]<<"\n";
			if(!SS_aux(R,th1m[1],th2j[0],tM1J[0][0],tM1J[1][0],ss_minD,p1,p2))
			{
				t1=tM1J[0][0];
				t2=tM1J[1][0];
				//	std::cout<<"11\n";
			}
			//		std::cout<<"t1="<<tM1J[0][1]<<"\t"<<"t2="<<tM1J[1][1]<<"\t"<<"tht1="<<th1m[1]<<"\t"<<"tht2="<<th2j[1]<<"\n";
			if(!SS_aux(R,th1m[1],th2j[1],tM1J[0][1],tM1J[1][1],ss_minD,p1,p2))
			{
				t1=tM1J[0][1];
				t2=tM1J[1][1];
				//			std::cout<<"12\n";
			}
		}
	}
	if(minD==DBL_MAX)
	{
		// std::cout<<"SS Ended with no real roots\n";
		// std::cout<<"................\n";
		return -1;
	}
	//	std::cout<<t1<<"\t"<<t2<<std::endl;
	ResultDisp();
	//	std::cout<<"SS Ends Here\n";
	//	std::cout<<"................\n";
	return 0;	
}
int EE::SS_aux(double R[3][3],double th1,double th2,double p_t1,double p_t2,double &ss_minD,double p1[3],double p2[3])
{
	double p_S1[3],p_S2[3],lp_S2[3],tmp_vec[3],dist;
	p_S1[0]=r1*cos(th1);
	p_S1[1]=r1*sin(th1);
	p_S1[2]=l1*p_t1;
	lp_S2[0]=r2*cos(th2);
	lp_S2[1]=r2*sin(th2);
	lp_S2[2]=l2*p_t2;
	MatVecMul(R,lp_S2,tmp_vec);
	p_S2[0]=O2x+tmp_vec[0];
	p_S2[1]=O2y+tmp_vec[1];
	p_S2[2]=O2z+tmp_vec[2];
	dist=distPnt(p_S1,p_S2);
	//	std::cout<<"dist="<<dist<<"\n";
	if(p_t1>0&&p_t1<1&&p_t2>0&&p_t2<1)
	{
		if(dist<ss_minD)
		{
			std::copy(p_S1,p_S1+3,ss_p1);
			std::copy(p_S2,p_S2+3,ss_p2);
			ss_minD=dist;
			if(dist<eps)
			{
				minD=0.0;
				std::copy(p_S1,p_S1+3,p1);
				std::copy(p_S2,p_S2+3,p2);
				return 0;
			}
		} 
	}
	if(dist<=minD)
	{
		minD=dist;
		std::copy(p_S1,p_S1+3,p1);
		std::copy(p_S2,p_S2+3,p2);
		return 0;
	}
	else
		return 1;
}
