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


#ifndef EE_H
#define EE_H 1 
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cfloat>
#include <complex>
#include "cylinderproximity/Utils.h"
#include "cylinderproximity/Cyl.h"
#include <cfloat>
#include <climits>
#include <gsl/gsl_poly.h>
enum Primitive
{
	S=1,L=2,D_b=3,D_t=4,C_b=5,C_t=6,NA=0
};
class EE
{
	protected:
		double r1,r2;
		double l1,l2;
		double q0,q1,q2,q3;
		double O2x,O2y,O2z;
		double minD,p1[3],p2[3],t1,t2;
		double ss_p1[3],ss_p2[3],ss_minD;
		double eps;
		bool cc_check;
		Primitive cyl1_primitive,cyl2_primitive,tmp_pri;
		char algoPath[10];
		int algoChar;
		double kvec[3];
		double kphi;
		double RtrCos, RtrSin;

	public:
		//     EE(int a,float n,double);
		//     EE(double r1[2],double l1[2],double q1[4],double O21[3],double);
		//     ~EE();
		//Pure Virtual function  Hnadler 
		virtual int Handler()=0;
		int Set(Cyl &E1,Cyl &E2,double eps1=10e-5);
		void DisplayInput();
		void RandomGen(int a,float n);
		int Degen();
		int CylOwnCheck();
		void CollisionCheck();
		int CC(double rC1,double lC1,double rC2,double lC2,double qC21[4],double OD21[3]);
		int DS(double rD,double lD,double rS,double lS,double qSD[4],double ODS[3]);
		int SS();
		int SS_aux(double R[3][3],double th1,double th2,double t1,double t2,double &ss_minD,double p1[3],double p2[3]);
		int DC(double rD,double lD,double rC,double lC,double qCD[4],double OCD[3],double &s21);
		int DD(double rD1,double lD1,double rD2,double lD2,double qD21[4],double OD21[3]);
		int DL(double rD,double lD,double rS,double lS,double qSD[4],double OSD[3],double &th1,double &s,double &tl);
		int CL(double rD,double lD,double rS,double lS,double qSD[4],double OSD[3],double &tCL2,bool hole=0);

		int Case1_1();
		int Case1_2();
		int Case1_3();
		void pointtransform();
		void pointtransform1(double a, double b, double pa[3], double pb[3]);
		void ResultDisp();
		void poly_roots(double coeff[],    std::complex <double> roots[],int size);
};
#endif /*  EE_H */
