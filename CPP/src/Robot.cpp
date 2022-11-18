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

#include "cylinderproximity/Robot.h"

void Robot::SetRobo(double r[11],double l[11])
{
	for(int i=0;i<11;i++)
	{
		//         std::cout<<r[i]<<l[i]<<std::endl;
		roboCyl[i].Set(r[i],l[i],0,0);
	}
}
int Robot::Handler(double tht[5][6])
{
	double T1[4][4];
	ForwardKinem(tht[0],T1);
	double Ttemp[4][4]={{0.707107, 0., -0.707107, 1373.22}, {0., 1., 0., 345.856}, {0.707107,
		0., 0.707107, 326.777}},thttemp[6];
	InverseKinem(Ttemp,thttemp);
	//     for(int i=0;i<4;i++)
	//     {
	// 	for(int j=0;j<4;j++)
	// 	    std::cout<<T1[i][j]<<"\t";
	// 	std::cout<<"\n";
	//     }
	Cyl tra,trb;
	tra.Set(1,5,0,0);
	trb.Set(5,10,0,0);
	double trO1[3]={0,0,0};
	double trO2[3]={-3,0,2};
	double trq1[4]={1,0,0,0};
	double trq2[4]={0,0.4,-0.3,0.866};
	tra.SetOQ(trO1,trq1);
	trb.SetOQ(trO2,trq2);
	ob_EE.Set(tra,trb);
	//     ob_EE.Set(roboCyl[10],roboCyl[0]);
	ob_EE.Handler();
	//     ForwardKinem(tht[1],T2);
	// //     double RFloat[3][3],OFloat[3];
	// //     roboCyl[10].Get(RFloat,OFloat);
	// //     SetFloatCyl(RFloat,OFloat);
	//    Motion(T1,T2,0,0);
	// //     SystemCollisionCheck(0,0);
	return 0;
}


int Robot::ForwardKinem(double tht[6],double T06[4][4])
{
	double d[6]={378,0,13.5,610,0,0};
	double dtool=205;
	double a[6]={0,180,582,182,0,0};
	double alpha[6]={0,-M_PI/2,M_PI,M_PI/2,M_PI/2,-M_PI/2};
	double T01[4][4],T12[4][4],T23[4][4],T34[4][4],T45[4][4],T56[4][4];

	TransformDH(T01,a[0],d[0],tht[0],alpha[0]);
	TransformDH(T12,a[1],d[1],(-M_PI/2+tht[1]),alpha[1]);
	TransformDH(T23,a[2],d[2],tht[2],alpha[2]);
	TransformDH(T34,a[3],d[3],tht[3],alpha[3]);
	TransformDH(T45,a[4],d[4],tht[4],alpha[4]);
	TransformDH(T56,a[5],d[5],tht[5],alpha[5]);

	double T02[4][4],T03[4][4],T04[4][4],T05[4][4];

	TransMatMul(T01,T12,T02);
	TransMatMul(T02,T23,T03);
	TransMatMul(T03,T34,T04);
	TransMatMul(T04,T45,T05);
	TransMatMul(T05,T56,T06);

	double Tbase[4][4],TbaseJt[4][4],TcntctBaseL2[4][4],Tjt2[4][4],TL2[4][4],Tjt3[4][4];
	double TL3[4][4],TL4[4][4],Tjt5[4][4],TL5[4][4],TL6[4][4];
	double Ttemp[4][4],Ttemp1[4][4];
	double O[3],q[4];

	TransformDH(Tbase,0,0,0,0);
	T2OQ(Tbase,O,q);
	roboCyl[0].SetOQ(O,q);

	TransformDH(TbaseJt,0,255,tht[0],0);
	T2OQ(TbaseJt,O,q);
	roboCyl[1].SetOQ(O,q);

	TransformDH(Ttemp,0,190,tht[0],0);
	double byrt2=1/sqrt(2);
	double roty[4][4]={{byrt2, 0.,byrt2,-10}, {0., 1., 0.,0}, {-byrt2, 0., byrt2,0},{0,0,0,1}};
	TransMatMul(Ttemp,roty,TcntctBaseL2);
	T2OQ(TcntctBaseL2,O,q);
	roboCyl[2].SetOQ(O,q);

	//     std::cout<<q[0]<<"\t"<<q[1]<<"\t"<<q[2]<<"\t"<<q[3]<<"\t"<<O[0]<<"\t"<<O[1]<<"\t"<<O[2]<<"\n";

	TransformDH(Ttemp,0,-198.5,M_PI,0);
	TransMatMul(T02,Ttemp,Tjt2);
	T2OQ(Tjt2,O,q);
	roboCyl[3].SetOQ(O,q);

	TransformDH(Ttemp,0,390,-M_PI/2,0);
	TransMatMul(Tjt2,Ttemp,Ttemp1);
	TransformDH(Ttemp,0,-95,0,M_PI/2);
	TransMatMul(Ttemp1,Ttemp,TL2);
	T2OQ(TL2,O,q);
	roboCyl[4].SetOQ(O,q);

	TransformDH(Ttemp,0,-205,0,0);
	TransMatMul(T03,Ttemp,Tjt3);
	T2OQ(Tjt3,O,q);
	roboCyl[5].SetOQ(O,q);

	TransformDH(Ttemp,0,205,-M_PI/2,0);
	TransMatMul(Tjt3,Ttemp,Ttemp1);
	TransformDH(Ttemp,0,-73,0,-M_PI/2);
	TransMatMul(Ttemp1,Ttemp,TL3);
	T2OQ(TL3,O,q);
	roboCyl[6].SetOQ(O,q);

	TransformDH(Ttemp,0,-610,M_PI,0);
	TransMatMul(T04,Ttemp,TL4);
	T2OQ(TL4,O,q);
	roboCyl[7].SetOQ(O,q);

	TransformDH(Ttemp,0,-90,M_PI/2,0);
	TransMatMul(T05,Ttemp,Tjt5);
	T2OQ(Tjt5,O,q);
	roboCyl[8].SetOQ(O,q);

	TransformDH(Ttemp,0,-60,0,-M_PI/2);
	TransMatMul(T05,Ttemp,TL5);
	T2OQ(TL5,O,q);
	roboCyl[9].SetOQ(O,q);

	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++) {
			Ttemp[i][j]=T06[i][j];
		}
	}
	TransformDH(Ttemp1,0,195,0,0);
	TransMatMul(Ttemp,Ttemp1,TL6);
	T2OQ(TL6,O,q);
	roboCyl[10].SetOQ(O,q);

	return 0;

	/*
	 *    TransformDH(TbaseJt,0,255,tht[0],0);
	 *    TransformDH(Ttemp,0,198.5,-M_PI/2+ tht[1],0)
	 *    TransMatMul(T02,Ttemp,Tjt2);
	 *    for(int i=0;i<4;i++)
	 *	for(int j=0;j<4;j++)
	 *	    Ttemp[i][j]=Tjt2[i][j];
	 *    Ttemp[2][3]+=390;
	 *    TransformDH(Ttemp1,0,0,0,M_PI/2);
	 *    TransMatMul(Ttemp,Ttemp1,TL2);
	 *    TL2[2][3]-=95;
	 *    for(int i=0;i<4;i++)
	 *	for(int j=0;j<4;j++)
	 *	    Tjt3[i][j]=T02[i][j];*/


}
int Robot::InverseKinem(double T06[4][4],double tht[6])
{
	double d[6]={378,0,13.5,610,0,0};
	double dtool=205;
	double a[6]={0,180,582,182,0,0};
	double alpha[6]={0,-M_PI/2,M_PI,M_PI/2,M_PI/2,-M_PI/2};

	double a1=a[0],a2=a[1],a3=a[2],a4=a[3],a5=a[4],a6=a[5];
	double d1=d[0],d2=d[1],d3=d[2],d4=d[3],d5=d[4],d6=d[5];

	double x=T06[0][3],y=T06[1][3],z=T06[2][3];
	double xsqr=x*x,ysqr=y*y,zsqr=z*z;

	//tht 1
	double tmp1=sqrt(xsqr-d3*d3+ysqr);
	if(y==d3)
		tht[0]=2*atan(y/x);
	else
		tht[0]=2*atan((x-tmp1)/(d3-y));
	//tht 3
	double tht3A=2*a3*a4;
	double tht3B=2*a3*d4;
	double tht3C=a3*a3+a4*a4+d4*d4-(-a2+tmp1)*(-a2+tmp1)-(-d1+z)*(-d1+z);
	if(tht3C==tht3A)
		tht[2]=2*atan(-tht3A/tht3B);
	else
		tht[2]=2*atan((-tht3B+sqrt(tht3A*tht3A+tht3B*tht3B-tht3C*tht3C))/(tht3C-tht3A));
	//tht 2
	double tht2A=a3+a4*cos(tht[2])+d4*sin(tht[2]);
	double tht2B=-d4*cos(tht[2])+a4*sin(tht[2]);
	double tht2C=d1-z;
	if (tht2C==tht2A)
		tht[1]=2*atan(-tht2A/tht2B);
	else
		tht[1]=2*atan((-tht2B-sqrt(tht2A*tht2A+tht2B*tht2B-tht2C*tht2C))/(tht2C-tht2A));

	//T03
	double T01[4][4],T12[4][4],T23[4][4],T02[4][4],T03[4][4];
	TransformDH(T01,a1,d1,tht[0],alpha[0]);
	TransformDH(T12,a2,d2,(-M_PI/2+tht[1]),alpha[1]);
	TransformDH(T23,a3,d3,tht[2],alpha[2]);

	TransMatMul(T01,T12,T02);
	TransMatMul(T02,T23,T03);
	double T36[4][4];
	TransMatMul(T03,T06,T36,1);
	//     for(int i=0;i<4;i++)
	//     {
	// 	for(int j=0;j<4;j++)
	// 	    std::cout<<T36[i][j]<<"\t";
	// 	std::cout<<std::endl;
	//     }
	//Wrist Angles
	if (T36[1][2]==-1)
	{
		tht[3]=0;
		tht[4]=0;

		tht[5]=atan2(-T36[0][1],T36[0][0]);
	}
	else if(T36[1][2]==1)
	{
		tht[3]=0;
		tht[4]=M_PI;
		tht[5]=atan2(T36[0][1],-T36[0][0]);
	}
	else
	{
		//tht 5
		tht[4]=atan2(sqrt(T36[1][0]*T36[1][0]+T36[1][1]*T36[1][1]),-T36[1][2]);

		//tht 4
		double Sth5=sin(tht[4]);
		tht[3]=atan2(-T36[2][2]/Sth5,-T36[0][2]/Sth5);

		//tht 6
		tht[5]=atan2(T36[1][1]/Sth5,-T36[1][0]/Sth5);
	}
	for(int i=0;i<6;i++)
		std::cout<<tht[i]*180/M_PI<<std::endl;
	return 0;
}

int Robot::Motion(double T1[4][4],double T2[4][4],bool floatCylActive=0,bool rackActive=0)
{

	double R1[3][3],R2[3][3],R[3][3];
	int n=100;
	double t=10.0;//No. of divisions
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			R1[i][j]=T1[i][j];
			R2[i][j]=T2[i][j];
		}
	}
	MatMul(R1,R2,R,1);
	double q[4];
	R2q(R,q);
	double phi=2*acos(q[0]);
	double Sphi=sqrt(1-q[0]*q[0]);
	double kx,ky,kz;
	kx=q[1]/Sphi;
	ky=q[2]/Sphi;
	kz=q[3]/Sphi;

	double p1[3],p2[3],p[3];
	for(int i=0;i<3;i++)
	{
		p1[i]=T1[i][3];
		p2[i]=T2[i][3];
	}

	std::fstream iotht1("tht1.txt");
	if(!iotht1)
	{
		std::cout<<"Error Writing file 1\n";
		return 1;
	}
	std::fstream iotht2("tht2.txt");
	if(!iotht2)
	{
		std::cout<<"Error Writing file 2\n";
		return 1;
	}
	std::fstream iotht3("tht3.txt");
	if(!iotht3)
	{
		std::cout<<"Error Writing file 3\n";
		return 1;
	}
	std::fstream iotht4("tht4.txt");
	if(!iotht4)
	{
		std::cout<<"Error Writing file 4\n";
		return 1;
	}
	std::fstream iotht5("tht5.txt");
	if(!iotht5)
	{
		std::cout<<"Error Writing file 5\n";
		return 1;
	}
	std::fstream iotht6("tht6.txt");
	if(!iotht6)
	{
		std::cout<<"Error Writing file 6\n";
		return 1;
	}
	double T[4][4],tht[6],psi,R21new[3][3];
	for(int i=1;i<=n;i++)
	{
		std::cout<<"\ni="<<i<<"\n";
		for(int j=0;j<3;j++)
		{
			p[j]=p1[j]+(p2[j]-p1[j])*i/n;
		}
		psi=phi/n*i;
		q[0]=cos(psi/2);
		double Spsi=sin(psi/2);
		q[1]=kx*Spsi;
		q[2]=ky*Spsi;
		q[3]=kz*Spsi;
		q2R(q,R21new);
		MatMul(R1,R21new,R);
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				T[j][k]=R[j][k];
			}
		}
		for(int j=0;j<3;j++)
		{
			T[j][3]=p[j];
			T[3][j]=0;
		}
		T[3][3]=1;
		InverseKinem(T,tht);

		iotht1<<(t/n*i)<<" "<<tht[0]*180/M_PI<<"\n";
		iotht2<<(t/n*i)<<" "<<tht[1]*180/M_PI<<"\n";
		iotht3<<(t/n*i)<<" "<<tht[2]*180/M_PI<<"\n";
		iotht4<<(t/n*i)<<" "<<tht[3]*180/M_PI<<"\n";
		iotht5<<(t/n*i)<<" "<<tht[4]*180/M_PI<<"\n";
		iotht6<<(t/n*i)<<" "<<tht[5]*180/M_PI<<"\n";

		double T06[4][4],eps=10e-05;
		ForwardKinem(tht,T06);
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				if(fabs(T[i][j]-T06[i][j])>eps)
				{
					std::cout<<"Inverse and Forward Kinematics in Motion Interpolation do not match\n";
					return -1;
				}
			}
		}
		if(floatCylActive)
		{
			SetFloatCyl(T);
		}
		SystemCollisionCheck(floatCylActive,rackActive);
	}
	iotht1.close();
	iotht2.close();
	iotht3.close();
	iotht4.close();
	iotht5.close();
	iotht6.close();
	return 0;
}

int Robot::SystemCollisionCheck(bool floatCylActive=0,bool rackActive=0)
{
	for(int i=0;i<=10;i++)
	{
		std::cout<<i<<std::endl;
		for(int j=0;j<1;j++)
		{

			ob_EE.Set(roboCyl[j],roboCyl[i]);
			ob_EE.Handler();
		}
		if(rackActive)
		{
			for(int j=0;j<20;j++)
			{
				ob_EHole.Set(roboCyl[i],box[j]);
				ob_EHole.Handler();
			}
		}
	}
	return 0;
}
// int main()
// {
//     Robot ob;
//     double T06[4][4]={{1,0,0,1100},{0,1,0,140},{0,0,1,300},{0,0,0,1}};
//     double tht[6];
//     ob.ForwardKinem(tht,T06);
//     for(int i=0;i<6;i++)
//     {
// 	std::cout<<tht[i]<<std::endl;
//     }
//     return 0;
// }
