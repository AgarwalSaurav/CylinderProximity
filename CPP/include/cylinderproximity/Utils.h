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

#ifndef UTILS_H
#define UTILS_H 1

#include <iostream>
#include <cmath>
#include <cstdlib>

void RandomRot(double R[3][3]);
int EqnTrig(double a,double b,double c,double soln[2]);
int q2R(double q[4],double R[3][3]);
int R2q(double R[3][3],double q[4]);

void RandomRot(double R[3][3]);
void quartMul(double q1[4], double q2[4], double q3[4]);
void TransformDH(double T[4][4],double a,double d,double tht, double alpha);
void TransMatMul(double T1[4][4],double T2[4][4],double res[4][4],bool tr=0);
void MatMul(double R1[3][3],double R2[3][3],double res[3][3],bool tr=0);

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
inline void DisplayT(double T[4][4])
{	std::cout<<"{";
	for(int i=0;i<4;i++)
	{std::cout<<"{";
		for(int j=0;j<4;j++)
		{
			if(j==3)
				std::cout<<T[i][j];
			else
				std::cout<<T[i][j]<<",";
		}
		if(i==3)
			std::cout<<"}";
		else
			std::cout<<"},";
	}
	std::cout<<"}\n";

}
inline void T2OQ(double T[4][4],double O[3],double q[4])
{
	double R[3][3];
	O[0]=T[0][3];
	O[1]=T[1][3];
	O[2]=T[2][3];
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			R[i][j]=T[i][j];
	R2q(R,q);
}
inline double Power(double x,int n)
{
	double y = 1.0;// used for multiplication
	while (n != 0) 
	{
		//loop for each bit in nn
		if (n & 1) y *= x;
		//multiply if bit = 1
		x *= x;
		//square x
		n >>= 1;
	}
	return y;

} 

inline int Transpose(double R[3][3],double tr_R[3][3])
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			tr_R[i][j]=R[j][i];

	return 0;
}

inline double Trace(double R[3][3])
{
	double tr=0.0;
	for(int i=0;i<3;i++)
		tr+=R[i][i];

	return tr;
}

inline double SIGN(double x) {return (x >= 0.0) ? +1.0 : -1.0;}

inline double NORM(double a, double b, double c, double d) {return sqrt(a * a + b * b + c * c + d * d);};



inline double distPnt(double a[3],double b[3])
{
	return sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1])+(a[2]-b[2])*(a[2]-b[2]));
}

inline void AddVec(double v1[3],double v2[3],double res[3])
{
	res[0]=v1[0]+v2[0];
	res[1]=v1[1]+v2[1];
	res[2]=v1[2]+v2[2];

}

inline void MatVecMul(double mat[3][3],double vec[3],double mul_result[3],bool tr=0)
{
	if(tr)
	{
		mul_result[0]=mat[0][0]*vec[0]+mat[1][0]*vec[1]+mat[2][0]*vec[2];
		mul_result[1]=mat[0][1]*vec[0]+mat[1][1]*vec[1]+mat[2][1]*vec[2];
		mul_result[2]=mat[0][2]*vec[0]+mat[1][2]*vec[1]+mat[2][2]*vec[2];
	}
	else
	{
		mul_result[0]=mat[0][0]*vec[0]+mat[0][1]*vec[1]+mat[0][2]*vec[2];
		mul_result[1]=mat[1][0]*vec[0]+mat[1][1]*vec[1]+mat[1][2]*vec[2];
		mul_result[2]=mat[2][0]*vec[0]+mat[2][1]*vec[1]+mat[2][2]*vec[2];
	}
}
inline void Randomize(double &a)
{
	a=((double) rand() / (RAND_MAX));

}
inline void Randomize(double &a,int b)
{
	a=((double) rand() / (RAND_MAX))*b;

}





#endif /* UTILS_H */
