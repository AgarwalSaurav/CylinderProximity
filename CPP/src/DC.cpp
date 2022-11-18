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

#include "cylinderproximity/DC.h"
int EE::DC(double rD,double lD,double rC,double lC,double qCD[4],double OCD[3],double &s21) {

	//      std::cout<<"................\n";
	//  std::cout<<"DC Starts Here\n";
	//  std::cout<<rD<<"\t"<<lD<<"\t"<<rC<<"\t"<<lC<<"\t"<<qCD[0]<<"\t"<<qCD[1]<<"\t"<<qCD[2]<<"\t"<<qCD[3]<<"\t"<<OCD[0]<<"\t"<<OCD[1]<<"\t"<<OCD[2]<<"\n";

	double sqCD[4]={qCD[0]*qCD[0],qCD[1]*qCD[1],qCD[2]*qCD[2],qCD[3]*qCD[3]};
	double s_rC=rC*rC;
	double s_OCD[3]={OCD[0]*OCD[0],OCD[1]*OCD[1],OCD[2]*OCD[2]};

	double a[5] = {2*s_OCD[2]*Power(qCD[0]*qCD[1] - qCD[2]*qCD[3],2) + 
		4*Power(qCD[0]*qCD[2] + qCD[1]*qCD[3],2)*s_rC,
			8*(qCD[0]*qCD[1] - qCD[2]*qCD[3])*(OCD[0]*OCD[2]*(-sqCD[0] + sqCD[1] + sqCD[2] - 
						sqCD[3]) + 2*(qCD[0]*qCD[2] + qCD[1]*qCD[3])*(s_OCD[2] - s_rC)),
			2*(-8*OCD[0]*OCD[2]*(qCD[0]*qCD[2] + qCD[1]*qCD[3])*
					(sqCD[0] - sqCD[1] - sqCD[2] + sqCD[3]) - 
					s_OCD[2]*(Power(qCD[0],4) + Power(sqCD[1] + sqCD[2],2) - 
						24*qCD[0]*qCD[1]*qCD[2]*qCD[3] + 6*(-sqCD[1] + sqCD[2])*sqCD[3] + 
						Power(qCD[3],4) + 2*sqCD[0]*
						(3*sqCD[1] - 3*sqCD[2] + sqCD[3])) - 
					4*(2*s_OCD[0]*(sqCD[1] + sqCD[2])*
						(sqCD[0] + sqCD[3]) + 
						(sqCD[0]*(-2*sqCD[1] + sqCD[2]) + 6*qCD[0]*qCD[1]*qCD[2]*qCD[3] + 
						 (sqCD[1] - 2*sqCD[2])*sqCD[3])*s_rC)),
			8*(qCD[0]*qCD[1] - qCD[2]*qCD[3])*(OCD[0]*OCD[2]*(sqCD[0] - sqCD[1] - sqCD[2] + 
						sqCD[3]) - 2*(qCD[0]*qCD[2] + qCD[1]*qCD[3])*(s_OCD[2] - s_rC)),
			2*s_OCD[2]*Power(qCD[0]*qCD[1] - qCD[2]*qCD[3],2) + 
				4*Power(qCD[0]*qCD[2] + qCD[1]*qCD[3],2)*s_rC};


	double consta = (sqCD[0] - sqCD[1] - sqCD[2] +sqCD[3]) *(sqCD[0] - sqCD[1] - sqCD[2] +sqCD[3]);

	double b[5] = {consta*Power(qCD[0]*qCD[1] - qCD[2]*qCD[3],2)*s_rC,
		4*consta*(qCD[0]*qCD[2] + qCD[1]*qCD[3])*(qCD[0]*qCD[1] - qCD[2]*qCD[3])*s_rC,
		-4*s_OCD[0]*(sqCD[1] + sqCD[2])*
			(sqCD[0] + sqCD[3]) - 
			2*consta*(sqCD[0]*(sqCD[1] - 2*sqCD[2]) - 6*qCD[0]*qCD[1]*qCD[2]*qCD[3] + 
					(-2*sqCD[1] + sqCD[2])*sqCD[3])*s_rC,
		-4*consta*(qCD[0]*qCD[2] + qCD[1]*qCD[3])*(qCD[0]*qCD[1] - qCD[2]*qCD[3])*s_rC,
		consta*Power(qCD[0]*qCD[1] - qCD[2]*qCD[3],2)*s_rC};



	//    std::cout<<std::fixed<<std::setprecision(10);
	// std::cout<<a[0]<<"\t"<<a[1]<<"\t"<<a[2]<<"\t"<<a[3]<<"\t"<<a[4]<<"\n";
	std::complex <double> rt1[4];
	// std::cout<<b[0]<<"\t"<<b[1]<<"\t"<<b[2]<<"\t"<<b[3]<<"\t"<<b[4]<<"\n";
	std::complex <double> rt2[4];
	if(a[4]==0.0)
	{
		double aa[4]={a[0],a[1],a[2],a[3]};
		poly_roots(aa,rt1,3);
		rt1[3] = sqrt(-1) * 100;

	}
	else
	{
		poly_roots(a,rt1,4);
	}
	if(b[4]==0.0)
	{
		double bb[4]={b[0],b[1],b[2],b[3]};
		poly_roots(bb,rt2,3);
		rt2[3] = sqrt(-1) * 100;

	}
	else
	{
		poly_roots(b,rt2,4);
	}

	int c=0;
	for (int i=0;i<4;i++)
	{
		if(std::imag(rt1[i])==0)
			c++;

	}
	for (int i=0;i<4;i++)
	{
		if(std::imag(rt2[i])==0)
			c++;

	}
	double *k1,k2,s;
	double cosTh1,sinTh1,cosTh2,sinTh2;
	double dist;
	k1=new double [c];
	c=0;
	for (int i=0;i<4;i++)
	{
		if(std::imag(rt1[i])==0&&!std::isnan(std::abs(std::real(rt1[i]))))
		{
			k1[c]=std::real(rt1[i]);
			c++;
		}

	}
	for (int i=0;i<4;i++)
	{
		if(std::imag(rt2[i])==0&&!std::isnan(std::abs(std::real(rt1[i]))))
		{
			k1[c]=std::real(rt2[i]);
			c++;
		}

	}

	minD=DBL_MAX;
	for(int i=0;i<c;i++)
	{

		double sqrk1=k1[i]*k1[i];

		double coeffk2quad[3] = {2*(-((qCD[1]*qCD[2] + qCD[0]*qCD[3])*rC) +sqrk1*(qCD[1]*qCD[2] + qCD[0]*qCD[3])*rC + 
				k1[i]*(OCD[0] + (sqCD[0] + sqCD[1] - sqCD[2] - sqCD[3])*rC)
				),2*((-1 + sqrk1)*sqCD[0] - 
					(-1 + sqrk1)*sqCD[1] + 4*k1[i]*qCD[1]*qCD[2] - 4*k1[i]*qCD[0]*qCD[3] + 
					(-1 + sqrk1)*(qCD[2] - qCD[3])*(qCD[2] + qCD[3]))*rC,
			-2*(-(k1[i]*OCD[0]) - (qCD[1]*qCD[2] + qCD[0]*qCD[3])*rC + sqrk1*(qCD[1]*qCD[2] + qCD[0]*qCD[3])*rC + 
					k1[i]*(sqCD[0] + sqCD[1] - sqCD[2] - sqCD[3])*rC)};
		double disck2 = (coeffk2quad[1]*coeffk2quad[1] - 4 * coeffk2quad[2] * coeffk2quad[0]);
		if(disck2 <0.0)
			continue;

		sinTh1=(2*k1[i])/(1+sqrk1);
		cosTh1=(1-sqrk1)/(1+sqrk1);
		for (int ii=0;ii<2;ii++)
		{

			if(std::abs(coeffk2quad[2])<eps)
			{
				sinTh2=0.0;
				cosTh2=1.0; 
			}

			else
			{

				k2 = (-coeffk2quad[1]+ pow((-1),ii)*sqrt(disck2))/(2.0*coeffk2quad[2]);

				double sqrk2=k2*k2;

				sinTh2=(2*k2)/(1+sqrk2);
				cosTh2=(1-sqrk2)/(1+sqrk2);
			}


			s=((2*qCD[1]*qCD[2]*rC + 2*qCD[0]*qCD[3]*rC)*cosTh2*sinTh1 + 
					cosTh1*(OCD[0] + (sqCD[0]*rC + sqCD[1]*rC - 
							sqCD[2]*rC - sqCD[3]*rC)*cosTh2 + 
						(2*qCD[1]*qCD[2]*rC - 2*qCD[0]*qCD[3]*rC)*sinTh2) + 
					sinTh1*(OCD[1] + (sqCD[0]*rC - sqCD[1]*rC + 
							sqCD[2]*rC - sqCD[3]*rC)*sinTh2))/rD;

			if(s<0||sinTh1<-1||sinTh1>1||cosTh1<-1||cosTh1>1||sinTh2<-1||sinTh2>1||cosTh2<-1||cosTh2>1)
			{
				continue;
			}
			double t_p1[3]={rD*s*cosTh1,rD*s*sinTh1,0};
			double p2_L1[3]={rC*cosTh2,rC*sinTh2,0};
			double RCD[3][3];
			q2R(qCD,RCD);
			double tmp_p2_l1[3];
			MatVecMul(RCD,p2_L1,tmp_p2_l1);
			double t_p2[3];
			AddVec(tmp_p2_l1,OCD,t_p2);
			dist=distPnt(t_p1,t_p2);


			if(s<1&&s>0&&dist<eps)
			{
				minD=0.0;
				std::copy(t_p1,t_p1+3,p1);
				std::copy(t_p2,t_p2+3,p2);
				s21=s;
			}
			else if(dist<minD)
			{
				minD=dist;
				std::copy(t_p1,t_p1+3,p1);
				std::copy(t_p2,t_p2+3,p2);	  
				s21=s;
			}
		}

	}
	ResultDisp();
	delete [] k1;

	//  std::cout<<"DC Ends Here\n";
	//    std::cout<<"................\n";
	return 0;

}
