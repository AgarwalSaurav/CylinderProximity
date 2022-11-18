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

#include "Robot.h"

int Robot::Motion(double T1[4][4],double T2[4][4])
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
	}
	iotht1.close();
	iotht2.close();
	iotht3.close();
	iotht4.close();
	iotht5.close();
	iotht6.close();
	return 0;
}
