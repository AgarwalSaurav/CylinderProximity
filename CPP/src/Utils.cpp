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

#include "cylinderproximity/Utils.h"

void RandomRot(double R[3][3])
{
	double ang1,ang2,ang3;
	Randomize(ang1,M_PI);
	Randomize(ang2,M_PI);
	Randomize(ang3,M_PI);
	double cosang1=cos(ang1),cosang2=cos(ang2),cosang3=cos(ang3);
	double sinang1=sin(ang1),sinang2=sin(ang2),sinang3=sin(ang3);
	R[0][0]=cosang2*cosang3;
	R[0][1]=-cosang2*sinang3;
	R[0][2]=sinang2;
	R[1][0]=cosang3*sinang1*sinang2+ cosang1*sinang3;
	R[1][1]=cosang1*cosang3-sinang1*sinang2*sinang3;
	R[1][2]=-cosang2*sinang1;
	R[2][0]=-cosang1*cosang3*sinang2 +sinang1*sinang3;
	R[2][1]=cosang3*sinang1 + cosang1*sinang2*sinang3;
	R[2][2]=cosang1*cosang2;
}
int EqnTrig(double a,double b,double c,double soln[2])
{
	//a cosTh +b sinTh +c=0
	if(a==0&&b==0)
		return -1;
	double alpha=atan2(b,a);
	double tmp=-c/(sqrt(a*a+b*b));
	if(tmp>1.0||tmp<-1.0)
		return 1;
	soln[0]=acos(tmp);
	soln[1]=-soln[0];
	soln[0]+=alpha;
	soln[1]+=alpha;
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

void TransformDH(double T[4][4],double a,double d,double tht, double alpha)
{
	double Sth=sin(tht);
	double Cth=cos(tht);
	double Sal=sin(alpha);
	double Cal=cos(alpha);
	T[0][0]=Cth;
	T[0][1]=-Sth;
	T[0][2]=0;
	T[0][3]=a;

	T[1][0]=Sth*Cal;
	T[1][1]=Cth*Cal;
	T[1][2]=-Sal;
	T[1][3]=-Sal*d;

	T[2][0]=Sth*Sal;
	T[2][1]=Cth*Sal;
	T[2][2]=Cal;
	T[2][3]=Cal*d;

	T[3][0]=0;
	T[3][1]=0;
	T[3][2]=0;
	T[3][3]=1;

}

void TransMatMul(double T1[4][4],double T2[4][4],double res[4][4],bool tr)
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			res[i][j]=0;
			for(int k=0;k<4;k++)
			{
				res[i][j]=res[i][j]+T1[i*!tr+k*tr][k*!tr+i*tr]*T2[k][j];
			}
		}
	}
}
void MatMul(double R1[3][3],double R2[3][3],double res[3][3],bool tr)
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

void quartMul(double q1[4], double q2[4], double q3[4])
{
	q3[0] = q1[0] * q2[0] - q1[1] * q2[1] - q1[2] * q2[2] - q1[3] * q2[3];
	q3[1] = q1[0] * q2[1] + q1[1] * q2[0] + q1[2] * q2[3] - q1[3] * q2[2];
	q3[2] = q1[0] * q2[2] - q1[1] * q2[3] + q1[2] * q2[0] + q1[3] * q2[1];
	q3[3] = q1[0] * q2[3] + q1[1] * q2[2] - q1[2] * q2[1] + q1[3] * q2[0];


}

// int main()
// {
//     double R[3][3]={{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
//     double q[4];
//     R2q(R,q);
//     for(int i=0;i<4;i++)
// 	std::cout<<q[i]<<std::endl;
// }
//    double R[3][3]={{}};
//    double q[4]={-.2,.3,1/sqrt(2),0.604};
//    q2R(q,R);
//    for(int i=0;i<3;i++)
//    {
//        for(int j=0;j<3;j++)
//        {
//            //std::cout<<*(*(R+i)+j)<<"\t\t";
//        }
//        //std::cout<<"\n";
//    }
//    //std::cout<<Trace(R)<<std::endl;
//    double q1[4];
//    //std::cout<<"\n"<<R2q(R,q1)<<"\n";
//    for(int i=0;i<4;i++)
//        //std::cout<<q[i]<<"\t";
//    //std::cout<<"\n";
//    for(int i=0;i<4;i++)
//        //std::cout<<q1[i]<<"\t";
//    //std::cout<<std::endl;
//    return 0;   

//     double a=23.12,bb=0,cc=0;
//     int n=5;
//     for(int i=0;i<1000000000;i++)
//     {
////          bb=pow(a,n);
//         cc=Power(a,n);
//              
//     }
//     //std::cout<<bb-cc;

//}
