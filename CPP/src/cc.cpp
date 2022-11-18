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

#include "cylinderproximity/cc.h"


int EE::CC(double rC1,double lC1,double rC2,double lC2,double qC21[4],double OD21[3])
{
	//    std::cout<<"................\n";
	//   std::cout<<"CC Starts Here\n";
	// std::cout<<rC1<<"\t"<<lC1<<"\t"<<rC2<<"\t"<<lC2<<"\t"<<qC21[0]<<"\t"<<qC21[1]<<"\t"<<qC21[2]<<"\t"<<qC21[3]<<"\t"<<OD21[0]<<"\t"<<OD21[1]<<"\t"<<OD21[2]<<"\n";
	cc_check=1;
	double R21[3][3];
	q2R(qC21,R21);
	double sqC21[4]={qC21[0]*qC21[0],qC21[1]*qC21[1],qC21[2]*qC21[2],qC21[3]*qC21[3]};
	double srC1=rC1*rC1,srC2=rC2*rC2;
	double s_OD21[3]={pow(OD21[0],2),pow(OD21[1],2),pow(OD21[2],2)};
	double pow3_qC21[4]={pow(qC21[0],3),pow(qC21[1],3),pow(qC21[2],3),pow(qC21[3],3)};
	double pow4_qC21[4]={pow(qC21[0],4),pow(qC21[1],4),pow(qC21[2],4),pow(qC21[3],4)};
	double a[9]=  {-4*Power(qC21[0]*qC21[1] - qC21[2]*qC21[3],2)*Power(OD21[2]*(1 - 2*sqC21[1] - 2*sqC21[2]) + 
			2*(qC21[0]*qC21[2] + qC21[1]*qC21[3])*(OD21[0] - rC1),2)*srC2,
				 -16*(qC21[0]*qC21[1] - qC21[2]*qC21[3])*(OD21[2]*(-1 + 2*sqC21[1] + 2*sqC21[2]) - 
						 2*(qC21[0]*qC21[2] + qC21[1]*qC21[3])*(OD21[0] - rC1))*
					 (OD21[2]*(-1 + 2*sqC21[1] + 2*sqC21[2])*(qC21[0]*qC21[2] + qC21[1]*qC21[3]) - 
						2*OD21[0]*Power(qC21[0]*qC21[2] + qC21[1]*qC21[3],2) + 
						2*(qC21[0]*(qC21[1] + qC21[2]) + (qC21[1] - qC21[2])*qC21[3])*(qC21[0]*(-qC21[1] + qC21[2]) + (qC21[1] + qC21[2])*qC21[3])*rC1)*srC2,
				 4*(Power(OD21[0],4)*(1 + 4*pow4_qC21[0] + 
							 4*sqC21[1]*(-1 + sqC21[1] + sqC21[2]) - 8*qC21[0]*qC21[1]*qC21[2]*qC21[3] + 
							 4*sqC21[0]*(-1 + 2*sqC21[1] + sqC21[3])) + 
						 2*Power(OD21[0],3)*(2*OD21[2]*(qC21[1]*(-1 + 2*sqC21[1])*qC21[3] + 
								 qC21[2]*(qC21[0] - 2*pow3_qC21[0] + 2*qC21[1]*qC21[2]*qC21[3] - 2*qC21[0]*sqC21[3])) + 
							 (1 - 2*sqC21[2] + sqC21[0]*(-2 + 4*sqC21[2]) + 8*qC21[0]*qC21[1]*qC21[2]*qC21[3] - 
								2*sqC21[3] + sqC21[1]*(-2 + 4*sqC21[3]))*rC1) + 
						 16*OD21[0]*Power(qC21[0]*qC21[2] + qC21[1]*qC21[3],2)*
						 (OD21[2]*(-1 + 2*sqC21[1] + 2*sqC21[2])*(qC21[0]*qC21[2] + qC21[1]*qC21[3]) + 
							(sqC21[0]*(-5*sqC21[1] + 2*sqC21[2]) + 14*qC21[0]*qC21[1]*qC21[2]*qC21[3] + 
							 (2*sqC21[1] - 5*sqC21[2])*sqC21[3])*rC1)*srC2 - 
						 4*(s_OD21[2]*Power(-1 + 2*sqC21[1] + 2*sqC21[2],2)*
							 Power(qC21[0]*qC21[2] + qC21[1]*qC21[3],2) - 
							 2*OD21[2]*(-1 + 2*sqC21[1] + 2*sqC21[2])*(qC21[0]*qC21[2] + qC21[1]*qC21[3])*
							 (sqC21[0]*(5*sqC21[1] - 2*sqC21[2]) - 14*qC21[0]*qC21[1]*qC21[2]*qC21[3] + 
								(-2*sqC21[1] + 5*sqC21[2])*sqC21[3])*rC1 + 
							 4*(pow4_qC21[0]*(pow4_qC21[1] - 5*sqC21[1]*sqC21[2] + pow4_qC21[2]) + 
								 14*pow3_qC21[0]*qC21[1]*qC21[2]*(-sqC21[1] + sqC21[2])*qC21[3] + 
								 sqC21[0]*(-5*pow4_qC21[1] + 32*sqC21[1]*sqC21[2] - 5*pow4_qC21[2])*
								 sqC21[3] + 14*qC21[0]*qC21[1]*(qC21[1] - qC21[2])*qC21[2]*(qC21[1] + qC21[2])*Power(qC21[3],3) + 
								 (pow4_qC21[1] - 5*sqC21[1]*sqC21[2] + pow4_qC21[2])*pow4_qC21[3])*
							 srC1)*srC2 + 
						 s_OD21[0]*(4*s_OD21[2]*(sqC21[1] + sqC21[2])*
								 (sqC21[0] + sqC21[3]) + 
								 4*OD21[2]*(qC21[0]*qC21[2]*(1 - 2*sqC21[1] - 2*sqC21[2]) + 
									 (-1 + 2*sqC21[0])*qC21[1]*qC21[3] + 2*qC21[1]*Power(qC21[3],3))*rC1 + 
								 (1 + 4*(sqC21[2]*(-1 + sqC21[1] + sqC21[2]) - 2*qC21[0]*qC21[1]*qC21[2]*qC21[3] + 
												 (-1 + sqC21[0] + 2*sqC21[2])*sqC21[3] + pow4_qC21[3]))*
								 srC1 - 16*Power(qC21[0]*qC21[2] + qC21[1]*qC21[3],4)*srC2)),
				 -16*(4*Power(OD21[0],3)*(sqC21[0]*qC21[1]*qC21[2] + pow3_qC21[0]*qC21[3] - qC21[1]*qC21[2]*sqC21[3] + 
							 qC21[0]*qC21[3]*(-1 + 2*sqC21[1] + sqC21[3]))*rC1 - 
						 4*OD21[0]*(qC21[0]*qC21[2] + qC21[1]*qC21[3])*(qC21[0]*qC21[1] - qC21[2]*qC21[3])*
						 (OD21[2]*(-1 + 2*sqC21[1] + 2*sqC21[2])*(qC21[0]*qC21[2] + qC21[1]*qC21[3]) + 
							(sqC21[0]*(sqC21[1] - 6*sqC21[2]) - 14*qC21[0]*qC21[1]*qC21[2]*qC21[3] + 
							 (-6*sqC21[1] + sqC21[2])*sqC21[3])*rC1)*srC2 + 
						 (qC21[0]*qC21[1] - qC21[2]*qC21[3])*(s_OD21[2]*Power(-1 + 2*sqC21[1] + 2*sqC21[2],2)*
							 (qC21[0]*qC21[2] + qC21[1]*qC21[3]) + 2*OD21[2]*(-1 + 2*sqC21[1] + 2*sqC21[2])*
							 (sqC21[0]*(sqC21[1] - 6*sqC21[2]) - 14*qC21[0]*qC21[1]*qC21[2]*qC21[3] + 
								(-6*sqC21[1] + sqC21[2])*sqC21[3])*rC1 - 
							 28*(qC21[0]*qC21[2] + qC21[1]*qC21[3])*(qC21[0]*(qC21[1] + qC21[2]) + (qC21[1] - qC21[2])*qC21[3])*
							 (qC21[0]*(-qC21[1] + qC21[2]) + (qC21[1] + qC21[2])*qC21[3])*srC1)*srC2 + 
						 2*s_OD21[0]*(rC1*(OD21[2]*(qC21[0]*(qC21[1] - 2*pow3_qC21[1] - 2*qC21[1]*sqC21[2]) + qC21[2]*qC21[3] - 
									 2*sqC21[0]*qC21[2]*qC21[3] - 2*qC21[2]*Power(qC21[3],3)) + 
								 2*(qC21[1]*qC21[2]*(-1 + sqC21[1] + sqC21[2]) + 
									 qC21[0]*(-sqC21[1] + sqC21[2])*qC21[3] + 2*qC21[1]*qC21[2]*sqC21[3])*rC1) + 
							 2*Power(qC21[0]*qC21[2] + qC21[1]*qC21[3],3)*(qC21[0]*qC21[1] - qC21[2]*qC21[3])*srC2)),
				 8*(Power(OD21[0],4)*(1 + 4*pow4_qC21[0] + 
							 4*sqC21[1]*(-1 + sqC21[1] + sqC21[2]) - 8*qC21[0]*qC21[1]*qC21[2]*qC21[3] + 
							 4*sqC21[0]*(-1 + 2*sqC21[1] + sqC21[3])) + 
						 4*Power(OD21[0],3)*OD21[2]*(qC21[1]*(-1 + 2*sqC21[1])*qC21[3] + 
							 qC21[2]*(qC21[0] - 2*pow3_qC21[0] + 2*qC21[1]*qC21[2]*qC21[3] - 2*qC21[0]*sqC21[3])) + 
						 4*OD21[0]*OD21[2]*(-1 + 2*sqC21[1] + 2*sqC21[2])*(qC21[0]*qC21[2] + qC21[1]*qC21[3])*
						 (qC21[0]*qC21[1] + 2*qC21[0]*qC21[2] + 2*qC21[1]*qC21[3] - qC21[2]*qC21[3])*(-(qC21[0]*qC21[1]) + 2*qC21[0]*qC21[2] + 2*qC21[1]*qC21[3] + qC21[2]*qC21[3])*
						 srC2 + (s_OD21[2]*Power(-1 + 2*sqC21[1] + 2*sqC21[2],2)*
							 (qC21[0]*qC21[1] + 2*qC21[0]*qC21[2] + 2*qC21[1]*qC21[3] - qC21[2]*qC21[3])*(qC21[0]*(qC21[1] - 2*qC21[2]) - (2*qC21[1] + qC21[2])*qC21[3]) + 
							 4*(pow4_qC21[0]*(4*pow4_qC21[1] - 27*sqC21[1]*sqC21[2] + 
									 4*pow4_qC21[2]) + 70*pow3_qC21[0]*qC21[1]*qC21[2]*(-sqC21[1] + sqC21[2])*
								 qC21[3] - 3*sqC21[0]*(9*pow4_qC21[1] - 52*sqC21[1]*sqC21[2] + 
									 9*pow4_qC21[2])*sqC21[3] + 
								 70*qC21[0]*qC21[1]*(qC21[1] - qC21[2])*qC21[2]*(qC21[1] + qC21[2])*Power(qC21[3],3) + 
								 (4*pow4_qC21[1] - 27*sqC21[1]*sqC21[2] + 4*pow4_qC21[2])*pow4_qC21[3])*
							 srC1)*srC2 + 
						 s_OD21[0]*(srC1 + 4*
							 (s_OD21[2]*(sqC21[1] + sqC21[2])*(sqC21[0] + sqC21[3]) + 
								(2*pow4_qC21[1] + sqC21[2] - pow4_qC21[2] + 6*qC21[0]*qC21[1]*qC21[2]*qC21[3] + 
								 (-1 + sqC21[0] - 2*sqC21[2])*sqC21[3] + pow4_qC21[3] + 
								 sqC21[1]*(-2 + sqC21[2] + 4*sqC21[3]))*srC1 + 
								Power(qC21[0]*qC21[2] + qC21[1]*qC21[3],2)*(qC21[0]*qC21[1] + 2*qC21[0]*qC21[2] + 2*qC21[1]*qC21[3] - qC21[2]*qC21[3])*
								(qC21[0]*(qC21[1] - 2*qC21[2]) - (2*qC21[1] + qC21[2])*qC21[3])*srC2))),
				 -16*(4*Power(OD21[0],3)*(sqC21[0]*qC21[1]*qC21[2] + pow3_qC21[0]*qC21[3] - qC21[1]*qC21[2]*sqC21[3] + 
							 qC21[0]*qC21[3]*(-1 + 2*sqC21[1] + sqC21[3]))*rC1 - 
						 4*OD21[0]*(qC21[0]*qC21[2] + qC21[1]*qC21[3])*(qC21[0]*qC21[1] - qC21[2]*qC21[3])*
						 (-(OD21[2]*(-1 + 2*sqC21[1] + 2*sqC21[2])*(qC21[0]*qC21[2] + qC21[1]*qC21[3])) + 
							(sqC21[0]*(sqC21[1] - 6*sqC21[2]) - 14*qC21[0]*qC21[1]*qC21[2]*qC21[3] + 
							 (-6*sqC21[1] + sqC21[2])*sqC21[3])*rC1)*srC2 + 
						 (-(qC21[0]*qC21[1]) + qC21[2]*qC21[3])*(s_OD21[2]*Power(-1 + 2*sqC21[1] + 2*sqC21[2],2)*
							 (qC21[0]*qC21[2] + qC21[1]*qC21[3]) - 2*OD21[2]*(-1 + 2*sqC21[1] + 2*sqC21[2])*
							 (sqC21[0]*(sqC21[1] - 6*sqC21[2]) - 14*qC21[0]*qC21[1]*qC21[2]*qC21[3] + 
								(-6*sqC21[1] + sqC21[2])*sqC21[3])*rC1 - 
							 28*(qC21[0]*qC21[2] + qC21[1]*qC21[3])*(qC21[0]*(qC21[1] + qC21[2]) + (qC21[1] - qC21[2])*qC21[3])*
							 (qC21[0]*(-qC21[1] + qC21[2]) + (qC21[1] + qC21[2])*qC21[3])*srC1)*srC2 + 
						 2*s_OD21[0]*(OD21[2]*(qC21[0]*(qC21[1] - 2*pow3_qC21[1] - 2*qC21[1]*sqC21[2]) + qC21[2]*qC21[3] - 
								 2*sqC21[0]*qC21[2]*qC21[3] - 2*qC21[2]*Power(qC21[3],3))*rC1 - 
							 2*(qC21[1]*qC21[2]*(-1 + sqC21[1] + sqC21[2]) + 
								 qC21[0]*(-sqC21[1] + sqC21[2])*qC21[3] + 2*qC21[1]*qC21[2]*sqC21[3])*srC1 + 
							 2*Power(qC21[0]*qC21[2] + qC21[1]*qC21[3],3)*(-(qC21[0]*qC21[1]) + qC21[2]*qC21[3])*srC2)),
				 4*(Power(OD21[0],4)*(1 + 4*pow4_qC21[0] + 
							 4*sqC21[1]*(-1 + sqC21[1] + sqC21[2]) - 8*qC21[0]*qC21[1]*qC21[2]*qC21[3] + 
							 4*sqC21[0]*(-1 + 2*sqC21[1] + sqC21[3])) + 
						 2*Power(OD21[0],3)*(-rC1 + 2*(OD21[2]*(qC21[1]*(-1 + 2*sqC21[1])*qC21[3] + 
									 qC21[2]*(qC21[0] - 2*pow3_qC21[0] + 2*qC21[1]*qC21[2]*qC21[3] - 2*qC21[0]*sqC21[3])) + 
								 (sqC21[0] + sqC21[1] + sqC21[2] - 2*sqC21[0]*sqC21[2] - 
									4*qC21[0]*qC21[1]*qC21[2]*qC21[3] + sqC21[3] - 2*sqC21[1]*sqC21[3])*rC1)) - 
						 16*OD21[0]*Power(qC21[0]*qC21[2] + qC21[1]*qC21[3],2)*
						 (-(OD21[2]*(-1 + 2*sqC21[1] + 2*sqC21[2])*(qC21[0]*qC21[2] + qC21[1]*qC21[3])) + 
							(sqC21[0]*(-5*sqC21[1] + 2*sqC21[2]) + 14*qC21[0]*qC21[1]*qC21[2]*qC21[3] + 
							 (2*sqC21[1] - 5*sqC21[2])*sqC21[3])*rC1)*srC2 - 
						 4*(s_OD21[2]*Power(-1 + 2*sqC21[1] + 2*sqC21[2],2)*
							 Power(qC21[0]*qC21[2] + qC21[1]*qC21[3],2) + 
							 2*OD21[2]*(-1 + 2*sqC21[1] + 2*sqC21[2])*(qC21[0]*qC21[2] + qC21[1]*qC21[3])*
							 (sqC21[0]*(5*sqC21[1] - 2*sqC21[2]) - 14*qC21[0]*qC21[1]*qC21[2]*qC21[3] + 
								(-2*sqC21[1] + 5*sqC21[2])*sqC21[3])*rC1 + 
							 4*(pow4_qC21[0]*(pow4_qC21[1] - 5*sqC21[1]*sqC21[2] + pow4_qC21[2]) + 
								 14*pow3_qC21[0]*qC21[1]*qC21[2]*(-sqC21[1] + sqC21[2])*qC21[3] + 
								 sqC21[0]*(-5*pow4_qC21[1] + 32*sqC21[1]*sqC21[2] - 5*pow4_qC21[2])*
								 sqC21[3] + 14*qC21[0]*qC21[1]*(qC21[1] - qC21[2])*qC21[2]*(qC21[1] + qC21[2])*Power(qC21[3],3) + 
								 (pow4_qC21[1] - 5*sqC21[1]*sqC21[2] + pow4_qC21[2])*pow4_qC21[3])*
							 srC1)*srC2 + 
						 s_OD21[0]*(4*s_OD21[2]*(sqC21[1] + sqC21[2])*
								 (sqC21[0] + sqC21[3]) + 
								 4*OD21[2]*(qC21[0]*qC21[2]*(-1 + 2*sqC21[1] + 2*sqC21[2]) + qC21[1]*qC21[3] - 
									 2*sqC21[0]*qC21[1]*qC21[3] - 2*qC21[1]*Power(qC21[3],3))*rC1 + 
								 (1 + 4*(pow4_qC21[2] - 2*qC21[0]*qC21[1]*qC21[2]*qC21[3] + 
												 sqC21[3]*(-1 + sqC21[0] + sqC21[3]) + 
												 sqC21[2]*(-1 + sqC21[1] + 2*sqC21[3])))*srC1 - 
								 16*Power(qC21[0]*qC21[2] + qC21[1]*qC21[3],4)*srC2)),
				 16*(qC21[0]*qC21[1] - qC21[2]*qC21[3])*(OD21[2]*(-1 + 2*sqC21[1] + 2*sqC21[2])*(qC21[0]*qC21[2] + qC21[1]*qC21[3]) - 
						 2*OD21[0]*Power(qC21[0]*qC21[2] + qC21[1]*qC21[3],2) + 
						 2*(qC21[0]*(qC21[1] + qC21[2]) + (qC21[1] - qC21[2])*qC21[3])*(qC21[0]*(qC21[1] - qC21[2]) - (qC21[1] + qC21[2])*qC21[3])*rC1)*
					 (OD21[2]*(-1 + 2*sqC21[1] + 2*sqC21[2]) - 2*(qC21[0]*qC21[2] + qC21[1]*qC21[3])*(OD21[0] + rC1))*
					 srC2,-4*Power(qC21[0]*qC21[1] - qC21[2]*qC21[3],2)*
					 Power(OD21[2]*(1 - 2*sqC21[1] - 2*sqC21[2]) + 2*(qC21[0]*qC21[2] + qC21[1]*qC21[3])*(OD21[0] + rC1),2)*
					 srC2};


	for(int i=0;i<9;i++)
	{
		//	std::cout<<a[i]<<std::endl;
	}
	//     std::cout<<"1\n";
	std::complex <double> rt[8];
	//    std::cout<<"2\n";
	if(a[8]==0.0)
	{
		// 	std::cout<<"1here\n";
		double aa[8]={a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7]};
		poly_roots(aa,rt,7);
		rt[7]=sqrt(-1);

	}
	else
	{
		// 	std::cout<<"here\n";
		poly_roots(a,rt,8);
	}       
	int c=0;
	for (int i=0;i<8;i++)
	{
		//      std::cout<<"Root "<<i<<": "<<rt[i]<<std::endl;  
		if(std::imag(rt[i])==0)
			c++;

	}
	double *real_rt;
	double cosTh1,sinTh1,cosTh2,sinTh2;
	minD=DBL_MAX;
	if(c==0)
	{
		//	std::cout<<"CC Ended with no real roots\n";
		//	std::cout<<"................\n";
		return -1;
	}
	real_rt=new double [c];
	c=0;
	for (int i=0;i<8;i++)
	{
		if(imag(rt[i])==0)
		{
			real_rt[c]=std::real(rt[i]);
			c++;
		}    

	}

	double sqrRt,a1,b1,c1,a2,b2,c2;
	for (int i=0;i<c;i++)
	{
		//	std::cout<<real_rt[i]<<"\n";
		sqrRt=real_rt[i]*real_rt[i];
		cosTh1=(1-sqrRt)/(1+sqrRt);
		sinTh1=(2*real_rt[i])/(1+sqrRt);
		//a1 costh2 + b1 sinth2 + c1 = 0
		c1= OD21[0]*sinTh1;
		b1=-(sqC21[0]*rC2*cosTh1) + sqC21[1]*rC2*cosTh1 -
			sqC21[2]*rC2*cosTh1 + sqC21[3]*rC2*cosTh1 +
			2*qC21[1]*qC21[2]*rC2*sinTh1 - 2*qC21[0]*qC21[3]*rC2*sinTh1;
		a1=-2*qC21[1]*qC21[2]*rC2*cosTh1 - 2*qC21[0]*qC21[3]*rC2*cosTh1 +
			sqC21[0]*rC2*sinTh1 + sqC21[1]*rC2*sinTh1 -
			sqC21[2]*rC2*sinTh1 - sqC21[3]*rC2*sinTh1;

		a2=2*qC21[1]*qC21[2]*OD21[0] - 2*qC21[0]*qC21[3]*OD21[0]  + 2*qC21[0]*qC21[1]*OD21[2] + 2*qC21[2]*qC21[3]*OD21[2] -
			2*qC21[1]*qC21[2]*rC1*cosTh1 + 2*qC21[0]*qC21[3]*rC1*cosTh1 -
			sqC21[0]*rC1*sinTh1 + sqC21[1]*rC1*sinTh1 -
			sqC21[2]*rC1*sinTh1 + sqC21[3]*rC1*sinTh1;

		b2=-(sqC21[0]*OD21[0]) - sqC21[1]*OD21[0] + sqC21[2]*OD21[0] +
			sqC21[3]*OD21[0]  + 2*qC21[0]*qC21[2]*OD21[2] -
			2*qC21[1]*qC21[3]*OD21[2] + sqC21[0]*rC1*cosTh1 + sqC21[1]*rC1*cosTh1 -
			sqC21[2]*rC1*cosTh1 - sqC21[3]*rC1*cosTh1 +
			2*qC21[1]*qC21[2]*rC1*sinTh1 + 2*qC21[0]*qC21[3]*rC1*sinTh1;
		c2=0.0;
		//Solving two linear equations
		cosTh2=(c1*b2-b1*c2)/(b1*a2-b2*a1);     
		sinTh2=(c1*a2-a1*c2)/(a1*b2-a2*b1);

		double tmp_vec[3];
		double p_DE1[3]={rC1*cosTh1,rC1*sinTh1,0};
		double c2Local[3]={rC2*cosTh2,rC2*sinTh2,0};
		MatVecMul(R21,c2Local,tmp_vec);
		double p_DE2[3]={OD21[0]+tmp_vec[0],OD21[1]+tmp_vec[1],OD21[2]+tmp_vec[2]};
		double dist=distPnt(p_DE1,p_DE2);
		//     std::cout<<"dist="<<dist<<"\n";
		if(dist<minD)
		{
			minD=dist;
			std::copy(p_DE1,p_DE1+3,p1);
			std::copy(p_DE2,p_DE2+3,p2);

		}
	}    
	delete [] real_rt;
	// ResultDisp();
	//       std::cout<<"CC Ends Here\n";
	// std::cout<<"................\n";
	return 0;

}

