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

#include "cylinderproximity/DL.h"
/**
 *
 * Point 1 from Disk
 * Point 2 from Line
 * 
 * */
/** @returns 	0 when successful
 * 		-1 No solution
 * */
int EE:: DL(double rD,double lD,double rS,double lS,double qSD[4],double OSD[3],double &th1,double &s,double &tl)
{
	/*    std::cout<<"................\n";
				std::cout<<"DL Starts Here\n";
				std::cout<<rD<<"\t"<<lD<<"\t"<<rS<<"\t"<<lS<<"\t"<<qSD[0]<<"\t"<<qSD[1]<<"\t"<<qSD[2]<<"\t"<<qSD[3]<<"\t"<<OSD[0]<<"\t"<<OSD[1]<<"\t"<<OSD[2]<<"\n";
				*/double eps_0=10e-10;
	if(fabs(qSD[3])<=eps_0)
	{
		double byrt2=1/(sqrt(2));
		if(fabs(qSD[0]-byrt2)<eps_0||fabs(qSD[0]+byrt2)<eps_0)
		{
			double c1=qSD[1]/qSD[0],c2=qSD[2]/qSD[0];
			if(c1*c1+c2*c2-1<eps_0)
			{
				std::cout<<"Case 3 (Degenerate) : Perpendicular Cylinders\n";
				// 		minD=DBL_MAX;
				// 		return 1;
			}
		}
	}
	double s_qSD[4]={qSD[0]*qSD[0],qSD[1]*qSD[1],qSD[2]*qSD[2],qSD[3]*qSD[3]};
	double A=-OSD[1] + 4*s_qSD[0]*s_qSD[1]*OSD[1] + 4*s_qSD[0]*s_qSD[2]*OSD[1] +
		4*s_qSD[1]*s_qSD[3]*OSD[1] + 4*s_qSD[2]*s_qSD[3]*OSD[1] -
		2*pow(qSD[0],3)*qSD[1]*OSD[2] + 2*qSD[0]*pow(qSD[1],3)*OSD[2] +
		2*qSD[0]*qSD[1]*s_qSD[2]*OSD[2] + 2*s_qSD[0]*qSD[2]*qSD[3]*OSD[2] -
		2*s_qSD[1]*qSD[2]*qSD[3]*OSD[2] - 2*pow(qSD[2],3)*qSD[3]*OSD[2] -
		2*qSD[0]*qSD[1]*s_qSD[3]*OSD[2] + 2*qSD[2]*pow(qSD[3],3)*OSD[2];
	double B=OSD[0] - 4*s_qSD[0]*s_qSD[1]*OSD[0] - 4*s_qSD[0]*s_qSD[2]*OSD[0] -
		4*s_qSD[1]*s_qSD[3]*OSD[0] - 4*s_qSD[2]*s_qSD[3]*OSD[0] -
		2*pow(qSD[0],3)*qSD[2]*OSD[2] + 2*qSD[0]*s_qSD[1]*qSD[2]*OSD[2] +
		2*qSD[0]*pow(qSD[2],3)*OSD[2] - 2*s_qSD[0]*qSD[1]*qSD[3]*OSD[2] +
		2*pow(qSD[1],3)*qSD[3]*OSD[2] + 2*qSD[1]*s_qSD[2]*qSD[3]*OSD[2] -
		2*qSD[0]*qSD[2]*s_qSD[3]*OSD[2] - 2*qSD[1]*pow(qSD[3],3)*OSD[2];
	double C=0.0;
	double tht1[2];
	if(EqnTrig(A,B,C,tht1))
	{
		std::cout<<"Error in DL. No soln for Theta\n";
		std::cout<<"DL Ended with no real solution\n";
		std::cout<<"................\n";
		return -1;
	}
	double C1[2]={cos(tht1[0]),cos(tht1[1])};
	double S1[2]={sin(tht1[0]),sin(tht1[1])};
	double s1[2],t2[2];
	for(int i=0;i<2;i++)
	{


		s1[i]=(OSD[0]*C1[i] - 4*s_qSD[0]*s_qSD[2]*OSD[0]*C1[i] -
				8*qSD[0]*qSD[1]*qSD[2]*qSD[3]*OSD[0]*C1[i] -
				4*s_qSD[1]*s_qSD[3]*OSD[0]*C1[i] +
				4*s_qSD[0]*qSD[1]*qSD[2]*OSD[1]*C1[i] +
				4*qSD[0]*s_qSD[1]*qSD[3]*OSD[1]*C1[i] -
				4*qSD[0]*s_qSD[2]*qSD[3]*OSD[1]*C1[i] -
				4*qSD[1]*qSD[2]*s_qSD[3]*OSD[1]*C1[i] - 2*pow(qSD[0],3)*qSD[2]*OSD[2]*C1[i] +
				2*qSD[0]*s_qSD[1]*qSD[2]*OSD[2]*C1[i] + 2*qSD[0]*pow(qSD[2],3)*OSD[2]*C1[i] -
				2*s_qSD[0]*qSD[1]*qSD[3]*OSD[2]*C1[i] + 2*pow(qSD[1],3)*qSD[3]*OSD[2]*C1[i] +
				2*qSD[1]*s_qSD[2]*qSD[3]*OSD[2]*C1[i] -
				2*qSD[0]*qSD[2]*s_qSD[3]*OSD[2]*C1[i] - 2*qSD[1]*pow(qSD[3],3)*OSD[2]*C1[i] +
				4*s_qSD[0]*qSD[1]*qSD[2]*OSD[0]*S1[i] +
				4*qSD[0]*s_qSD[1]*qSD[3]*OSD[0]*S1[i] -
				4*qSD[0]*s_qSD[2]*qSD[3]*OSD[0]*S1[i] -
				4*qSD[1]*qSD[2]*s_qSD[3]*OSD[0]*S1[i] + OSD[1]*S1[i] -
				4*s_qSD[0]*s_qSD[1]*OSD[1]*S1[i] +
				8*qSD[0]*qSD[1]*qSD[2]*qSD[3]*OSD[1]*S1[i] -
				4*s_qSD[2]*s_qSD[3]*OSD[1]*S1[i] +
				2*pow(qSD[0],3)*qSD[1]*OSD[2]*S1[i] - 2*qSD[0]*pow(qSD[1],3)*OSD[2]*S1[i] -
				2*qSD[0]*qSD[1]*s_qSD[2]*OSD[2]*S1[i] -
				2*s_qSD[0]*qSD[2]*qSD[3]*OSD[2]*S1[i] +
				2*s_qSD[1]*qSD[2]*qSD[3]*OSD[2]*S1[i] + 2*pow(qSD[2],3)*qSD[3]*OSD[2]*S1[i] +
				2*qSD[0]*qSD[1]*s_qSD[3]*OSD[2]*S1[i] - 2*qSD[2]*pow(qSD[3],3)*OSD[2]*S1[i])/
				(rD*(1 - 2*s_qSD[0]*s_qSD[1] - 2*s_qSD[0]*s_qSD[2] -
						 2*s_qSD[1]*s_qSD[3] - 2*s_qSD[2]*s_qSD[3] +
						 2*s_qSD[0]*s_qSD[1]*pow(C1[i],2) -
						 2*s_qSD[0]*s_qSD[2]*pow(C1[i],2) -
						 8*qSD[0]*qSD[1]*qSD[2]*qSD[3]*pow(C1[i],2) -
						 2*s_qSD[1]*s_qSD[3]*pow(C1[i],2) +
						 2*s_qSD[2]*s_qSD[3]*pow(C1[i],2) +
						 8*s_qSD[0]*qSD[1]*qSD[2]*C1[i]*S1[i] +
						 8*qSD[0]*s_qSD[1]*qSD[3]*C1[i]*S1[i] -
						 8*qSD[0]*s_qSD[2]*qSD[3]*C1[i]*S1[i] -
						 8*qSD[1]*qSD[2]*s_qSD[3]*C1[i]*S1[i] -
						 2*s_qSD[0]*s_qSD[1]*pow(S1[i],2) +
						 2*s_qSD[0]*s_qSD[2]*pow(S1[i],2) +
						 8*qSD[0]*qSD[1]*qSD[2]*qSD[3]*pow(S1[i],2) +
						 2*s_qSD[1]*s_qSD[3]*pow(S1[i],2) -
						 2*s_qSD[2]*s_qSD[3]*pow(S1[i],2)));

		t2[i]=(-2*qSD[0]*qSD[2]*OSD[0] - 2*qSD[1]*qSD[3]*OSD[0] + 2*qSD[0]*qSD[1]*OSD[1] - 2*qSD[2]*qSD[3]*OSD[1] -
				s_qSD[0]*OSD[2] + s_qSD[1]*OSD[2] + s_qSD[2]*OSD[2] -
				s_qSD[3]*OSD[2] + 2*qSD[0]*qSD[2]*rD*s1[i]*C1[i] +
				2*qSD[1]*qSD[3]*rD*s1[i]*C1[i] - 2*qSD[0]*qSD[1]*rD*s1[i]*S1[i] +
				2*qSD[2]*qSD[3]*rD*s1[i]*S1[i])/lS;

	}



	double p1_1[3]={rD*s1[0]*cos(tht1[0]),rD*s1[0]*sin(tht1[0]),0};
	double p2_L1[3]={0,0,lS*t2[0]};
	double RSD[3][3];
	q2R(qSD,RSD);
	double tmp_p2_l1[3];
	MatVecMul(RSD,p2_L1,tmp_p2_l1);
	double p2_1[3];
	AddVec(tmp_p2_l1,OSD,p2_1);

	double p1_2[3]={rD*s1[1]*cos(tht1[1]),rD*s1[1]*sin(tht1[1]),0};
	double p2_L2[3]={0,0,lS*t2[1]};
	double tmp_p2_l2[3];
	MatVecMul(RSD,p2_L2,tmp_p2_l2);
	double p2_2[3];
	AddVec(tmp_p2_l2,OSD,p2_2);
	double dist1=distPnt(p1_1,p2_1);
	double dist2=distPnt(p1_2,p2_2);
	if(s1[0]>0&&s1[0]<1&&t2[0]>0&&t2[0]<1&&dist1<eps)
	{
		minD=0.0;
		std::copy(p1_1,p1_1+3,p1);
		std::copy(p2_1,p2_1+3,p2);
		th1=tht1[0];
		s=s1[0];
		tl=t2[0];
	}
	else if(s1[1]>0&&s1[1]<1&&t2[1]>0&&t2[1]<1&&dist2<eps)
	{
		minD=0.0;
		std::copy(p1_2,p1_2+3,p1);
		std::copy(p2_2,p2_2+3,p2);
		th1=tht1[1];
		s=s1[1];
		tl=t2[1];
	}
	else if(dist1<dist2)
	{
		minD=dist1;
		std::copy(p1_1,p1_1+3,p1);
		std::copy(p2_1,p2_1+3,p2);
		th1=tht1[0];
		s=s1[0];
		tl=t2[0];
	}
	else
	{
		minD=dist2;
		std::copy(p1_2,p1_2+3,p1);
		std::copy(p2_2,p2_2+3,p2);
		th1=tht1[1];
		s=s1[1];
		tl=t2[1];
	}
	//	std::cout<<"s1="<<s1[0]<<"\tt2="<<t2[0]<<"\tdist="<<dist1<<"\n";
	//	std::cout<<"s1="<<s1[1]<<"\tt2="<<t2[1]<<"\tdist="<<dist2<<"\n";
	ResultDisp();
	//	std::cout<<"DL Ends Here\n";
	//	std::cout<<"................\n";
	return 0;
}
