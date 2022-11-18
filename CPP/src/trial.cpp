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

#include<iostream>
#include <cmath>
inline void MatMul(double R1[3][3],double R2[3][3],double res[3][3],bool tr=0)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			res[i][j]=0;
			for(int k=0;k<3;k++)
			{
				res[i][j]=res[i][j]+R1[i*!tr+k*tr][k*!tr+i*tr]*R2[k][j];
			}
		}
	}

}
void dummyfunc(int a )
{
	for (int i=0;i<3;i++)
	{
	}
}
inline double SIGN(double x) {return (x >= 0.0) ? +1.0 : -1.0;}
inline double Trace(double R[3][3])
{
	double tr=0.0;
	for(int i=0;i<3;i++)
		tr+=R[i][i];

	return tr;
}
inline double NORM(double a, double b, double c, double d) {return sqrt(a * a + b * b + c * c + d * d);}


int R2q1(double R[3][3],double q[4])
{
	double tr=Trace(R);
	q[0]=sqrt((tr+1)/4);
	double x=(R[2][1]-R[1][2])/4;
	double y=(R[0][2]-R[2][0])/4;
	double z=(R[1][0]-R[0][1])/4;
	if(q[0]==0)
	{
		q[1]=sqrt((R[0][0]+1)/2);
		if(q[1]==0)
		{
			q[2]=sqrt((R[1][1]+1)/2);
			if(q[2]==0)
				q[3]=1;
			else
				q[3]=R[1][2]/(2*q[2]);
		}
		else
		{
			q[2]=R[0][1]/(1*q[0]);
			q[3]=R[0][2]/(2*q[1]);
		}
	}
	else
	{
		q[1]=x/q[0];
		q[2]=y/q[0];
		q[3]=z/q[0];
	}
	return 0;
}

int R2q(double R[3][3],double q[4])
{
	q[0] = ( R[0][0] + R[1][1] + R[2][2] + 1.0) / 4.0;
	q[1] = ( R[0][0] - R[1][1] - R[2][2] + 1.0) / 4.0;
	q[2] = (-R[0][0] + R[1][1] - R[2][2] + 1.0) / 4.0;
	q[3] = (-R[0][0] - R[1][1] + R[2][2] + 1.0) / 4.0;
	if(q[0] < 0.0) q[0] = 0.0;
	if(q[1] < 0.0) q[1] = 0.0;
	if(q[2] < 0.0) q[2] = 0.0;
	if(q[3] < 0.0) q[3] = 0.0;
	q[0] = sqrt(q[0]);
	q[1] = sqrt(q[1]);
	q[2] = sqrt(q[2]);
	q[3] = sqrt(q[3]);
	if(q[0] >= q[1] && q[0] >= q[2] && q[0] >= q[3])
	{
		q[0] *= +1.0;
		q[1] *= SIGN(R[2][1] - R[1][2]);
		q[2] *= SIGN(R[0][2] - R[2][0]);
		q[3] *= SIGN(R[1][0] - R[0][1]);
	}
	else if(q[1] >= q[0] && q[1] >= q[2] && q[1] >= q[3])
	{
		q[0] *= SIGN(R[2][1] - R[1][2]);
		q[1] *= +1.0;
		q[2] *= SIGN(R[1][0] + R[0][1]);
		q[3] *= SIGN(R[0][2] + R[2][0]);
	}
	else if(q[2] >= q[0] && q[2] >= q[1] && q[2] >= q[3])
	{
		q[0] *= SIGN(R[0][2] - R[2][0]);
		q[1] *= SIGN(R[1][0] + R[0][1]);
		q[2] *= +1.0;
		q[3] *= SIGN(R[2][1] + R[1][2]);
	}
	else if(q[3] >= q[0] && q[3] >= q[1] && q[3] >= q[2])
	{
		q[0] *= SIGN(R[1][0] - R[0][1]);
		q[1] *= SIGN(R[2][0] + R[0][2]);
		q[2] *= SIGN(R[2][1] + R[1][2]);
		q[3] *= +1.0;
	}
	else
	{
		//std::cout<<"coding error\n";
		return 1;
	}
	double r = NORM(q[0], q[1], q[2], q[3]);
	q[0] /= r;
	q[1] /= r;
	q[2] /= r;
	q[3] /= r;
	return 0;
}
int q2R(double q[4],double R[3][3])
{
	double a=q[0];
	double b=q[1];
	double c=q[2];
	double d=q[3];
	double asqr=a*a;
	double bsqr=b*b;
	double csqr=c*c;
	double dsqr=d*d;
	double ab2=2*a*b;
	double ac2=2*a*c;
	double ad2=2*a*d;
	double bc2=2*b*c;
	double bd2=2*b*d;
	double cd2=2*c*d;
	R[0][0]=asqr+bsqr-csqr-dsqr;
	R[0][1]=bc2-ad2;
	R[0][2]=bd2+ac2;
	R[1][0]=bc2+ad2;
	R[1][1]=asqr-bsqr+csqr-dsqr;
	R[1][2]=cd2-ab2;
	R[2][0]=bd2-ac2;
	R[2][1]=cd2+ab2;
	R[2][2]=asqr-bsqr-csqr+dsqr;
	return 0;
}
int R2q2(double R[3][3],double q[4])
{
	double tr=Trace(R);
	if(tr>R[0][0]&&tr>R[2][2]&&tr>R[1][1])
	{
		q[0]=sqrt((tr+1))/2;
		q[1]=(R[1][2]-R[2][1])/(4*q[0]);
		q[2]=(R[2][0]-R[0][2])/(4*q[0]);
		q[3]=(R[0][1]-R[1][0])/(4*q[0]);
		std::cout<<"\nCase1\n";
	}
	else if(tr<R[0][0]&&R[0][0]>R[1][1]&&R[0][0]>R[2][2])
	{
		q[1]=sqrt(1+R[0][0]-R[1][1]-R[2][2])/2;
		q[0]=(R[1][2]-R[2][1])/(4*q[1]);
		q[2]=(R[0][1]+R[1][0])/(4*q[1]);
		q[3]=(R[2][0]+R[0][2])/(4*q[1]);
		std::cout<<"\nCase2\n";
	}
	else if(R[1][1]>R[2][2]&&R[0][0]<R[1][1]&&tr<R[1][1])
	{
		q[2]=sqrt(1-R[0][0]+R[1][1]-R[2][2])/2;
		q[0]=(R[2][0]-R[0][2])/(4*q[2]);
		q[1]=(R[0][1]+R[1][0])/(4*q[2]);
		q[3]=(R[1][2]+R[2][1])/(4*q[2]);
		std::cout<<"\nCase3\n";
	}
	else if(R[1][1]<R[2][2]&&tr<R[2][2]&&R[0][0]<R[2][2])
	{
		q[3]=sqrt(1-R[0][0]-R[1][1]+R[2][2])/2;
		q[0]=(R[0][1]-R[1][0])/(4*q[3]);
		q[1]=(R[2][0]+R[0][2])/(4*q[3]);
		q[2]=(R[1][2]+R[2][1])/(4*q[3]);
		std::cout<<"\nCase4\n";
	}
	else
		return 1;
	return 0;
}
inline void DisplayR(double R[3][3])
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			std::cout<<R[i][j]<<"\t";
		}
		std::cout<<"\n";
	}

}

int main()
{
	double R[3][3]={{0.882687, -0.329107,
		0.335488}, {-0.338735, -0.940363, -0.0312488}, {0.325765, \
			-0.0860584, -0.941526}};
	double q1[4],q2[4],q3[3],R1[3][3],R2[3][3],R3[3][3],R0[3][3];
	R2q1(R,q1);
	for(int i=0;i<4;i++)
		std::cout<<q1[i]<<"\t";
	std::cout<<"\n";
	q2R(q1,R1);
	MatMul(R1,R,R0,1);
	DisplayR(R0);

	R2q(R,q2);
	for(int i=0;i<4;i++)
		std::cout<<q2[i]<<"\t";
	std::cout<<"\n";
	q2R(q2,R2);
	MatMul(R2,R,R0,1);
	DisplayR(R0);

	R2q2(R1,q3);
	for(int i=0;i<4;i++)
		std::cout<<q3[i]<<"\t";
	std::cout<<"\n";
	q2R(q3,R3);
	MatMul(R3,R,R0,1);
	DisplayR(R0);

	return 0;
}
