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

// #include "EE_Cyl.h"
// #include "EE_CylHole.h"
#include <cmath>
#include <fstream>
#include <ctime>
#include "cylinderproximity/Robot.h"
#include "cylinderproximity/EE_Rand.h"
int main() {
	std::clock_t    start;
	std::clock_t time_run = std::clock()-std::clock();


	double Oa[3]={0,0,0},qa[4]={1,0,0,0};
	// 	double Ob[3]={8,-8,8},qb[4]={-0.2,0.3,1./sqrt(2),sqrt(37)/10.};
	//	double Ob[3]={-12,12,-18},qb[4]={0.3,0.4,-0.3,sqrt(33)/(5.0*sqrt(2))};
	double Ob[3]={-12,12,-18},qb[4]={0.3,0.4,-0.3,sqrt(33)/(5.0*sqrt(2))};//case 3

	Cyl cyl_a,cyl_b;
	cyl_a.Set(2,12,0,0);
	cyl_b.Set(2.5,18,0,0);
	cyl_a.SetOQ(Oa,qa);
	cyl_b.SetOQ(Ob,qb);

	start = std::clock();

	EE_Cyl obEE;
	obEE.Set(cyl_a,cyl_b);

	obEE.Handler();

	time_run+=(std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
	std::cout << "Time: " << time_run << " ms" << std::endl;

	/*
	//--------------------------------------------------------------------------------
	Robot robo;
	double qbox_x[4]={0.707107,0,0.707107,0};
	double qbox_y[4]={0.707107,-0.707107,0,0};
	double qbox_z[4]={1,0,0,0};
	double l_box_x=500,l_box_y=400,l_box_z=300;
	double Obox_x[8][3]={
	{1000,0,0},
	{1000,0,l_box_z/3},
	{1000,0,l_box_z*2/3},
	{1000,0,l_box_z},
	{1000,l_box_y,0},
	{1000,l_box_y,l_box_z/3},
	{1000,l_box_y,l_box_z*2/3},
	{1000,l_box_y,l_box_z}
	};
	double Obox_y[8][3]={
	{1000,0,0},
	{1000,0,l_box_z/3},
	{1000,0,l_box_z*2/3},
	{1000,0,l_box_z},
	{1000+l_box_x,0,0},
	{1000+l_box_x,0,l_box_z/3},
	{1000+l_box_x,0,l_box_z*2/3},
	{1000+l_box_x,0,l_box_z}
	};
	double Obox_z[4][3]={
	{1000,0,0},
	{1000,l_box_y,0},
	{1000+l_box_x,0,0},
	{1000+l_box_x,l_box_y,0},
	};
	double r_box;
	r_box=20.0;
	robo.SetBox(qbox_x,qbox_y,qbox_z,Obox_x,Obox_y,Obox_z,r_box,l_box_x,l_box_y,l_box_z);

	double qrack[4]={1,0,0,0};
	double Obase[3]={1000,1000,0};
	double Ohole[7][3]={
	{1000+125,1000,200},
	{1000+125*cos(2*M_PI/6),1000+125*sin(2*M_PI/6),200},
	{1000+125*cos(2*2*M_PI/6),1000+125*sin(2*2*M_PI/6),200},
	{1000+125*cos(3*2*M_PI/6),1000+125*sin(3*2*M_PI/6),200},
	{1000+125*cos(4*2*M_PI/6),1000+125*sin(4*2*M_PI/6),200},
	{1000+125*cos(5*2*M_PI/6),1000+125*sin(5*2*M_PI/6),200},
	{1000,1000,200},
	};
	double rRackBase=250,lRackBase=300,rRackHole=25,lRackHole=100,rRackCyl=20,lRackCyl=200;
	robo.SetRack(qrack,Obase,Ohole,rRackBase,lRackBase,rRackHole,lRackHole,rRackCyl,lRackCyl);

	double rFloatCyl=20,lFloatCyl=200;
	robo.SetFloatCyl(rFloatCyl,lFloatCyl);

	//     double Tbase[4][4],TbaseJt[4][4],TcntctBaseL2[4][4],Tjt2[4][4],TL2[4][4],Tjt3[4][4];
	//     double TL3[4][4],TL4[4][4],Tjt5[4][4],TL5[4][4],TL6[4][4];
	double l[11]={255,198,375,340,750,330,350,670,180,255,10};
	double r[11]={
	180,
	70,
	90,
	85,
	100,
	63,
	100,
	85,
	50,
	85,
	85};
	robo.SetRobo(r,l);

	double thtRobot[5][6]={
		{0*M_PI/180,0*M_PI/180,0*M_PI/180,0*M_PI/180,0*M_PI/180,0*M_PI/180},
		{0.13877,0.916028,-0.120733,-3.14159,2.60756,-0.138767},
		{0.138767,0.916028,-0.120733,-3.14159,2.60756,-0.138767},
		{0.138767,0.916028,-0.120733,-3.14159,2.60756,-0.138767},
		{0.138767,0.916028,-0.120733,-3.14159,2.60756,-0.138767}
	};

	robo.Handler(thtRobot);

	//-------------------------------------------------------------------------------------------------------------
	*/
		/*
			 EE_Rand ob_rand;
			 std::fstream ioRandCheck;
			 ioRandCheck.open("randomCheck1.csv");
			 if(!ioRandCheck)
			 {
			 std::cout<<"Error Writing file ioRandCheck\n";
		//return 1;
		}
		ioRandCheck<<"i,r1,l1,r2,l2,cyl1_primitive,cyl2_primitive,algoPath,minD,p1x,p1y,p1z,p2x,p2y,p2z,q0,q1,q2,q3,R_temp[0][0],R_temp[0][1],R_temp[0][2],O2x,R_temp[1][0],R_temp[1][1],R_temp[1][2],O2y,R_temp[2][0],R_temp[2][1],R_temp[2][2],O2z,kvec[0],kvec[1],kvec[2],kphi\n";
		ob_rand.RandomGen(5,0.5);
		for(int i=10000;i>=9386;i++)
		{
		//	    std::cout<<i<<"iiiiiiiiiiiii\n";
		//	    ioRandCheck<<i<<",";
		//	ob_rand.RandomGen(5,0.5);
		ob_rand.Handler();
		//	ob_rand.WriteFile(ioRandCheck);

		}
		ioRandCheck.close();
		//------------------------------------------------------------------
		*/

		//void System::SetBox(double qx[4],double qy[4],double qz[4],double Ox[8][3],double Oy[8][3],double Oz[4][3],double r, double l)
		//     void SetRack(double q[4],double Obase[3],double Ohole[7][3],double rbase,double lbase, double rhole,double lhole,double rcyl,double lcyl);
		//     void SetFloatCyl(double r, double l);

		//     double T1[4][4],T2[4][4];
		//     double tht1[6]={0,0,0,0,0,0};
		//     double tht2[6]={8.79*M_PI/180,63.96*M_PI/180,9.32*M_PI/180,123.08*M_PI/180,-34.12*M_PI/180,5.50*M_PI/180};
		//     ForwardKinem(tht1,T1);
		//     for(int i=0;i<4;i++)
		// 	for(int j=0;j<4;j++)
		// 	    std::cout<<T1[i][j]<<"\n";
		//     ForwardKinem(tht2,T2);
		//     Motion(T1,T2);
		//     
		//     double r[2]={1,5};
		//     double l[2]={5,10};
		//     double q[4]={0,0.4,-0.3,0.866};
		//     double O2[3]={-3,0,2};
		// double r1,l1,r2,l2,q0,q1,q2,q3,O2x,O2y,O2z;
		// r1 = 1;
		// r2 = 1;
		// l1 = 5;
		// l2 = 10;
		// q0 = 1/sqrt(2);
		// q1 = 0;
		// q2 = 1/sqrt(2);
		// q3 = 0;
		// O2x = -3;
		// O2y = 0;
		// O2z = -4;
		// double r[2]={r1,r2};
		//     double l[2]={l1,l2};
		//     double q[4]={q0,q1,q2,q3};  
		//     double O2[3]={O2x,O2y,O2z};
		//     EE_Cyl ob_Cyl;
		//     EE_CylHole ob_CylHole;
		//     EE* basep[]={&ob_Cyl,&ob_CylHole};
		//     basep[0] -> Set(r,l,q,O2);
		//     basep[0] -> Handler();
		//     
		//     std::cout<<"Here?\n";

		// double r1,l1,r2,l2,q0,q1,q2,q3,O2x,O2y,O2z;
		// r1=5.2307798552;
		// r2=3.7202873052;
		// l1=7.3510299005;
		// l2=2.0093912454;
		// q0=0.8471928852;
		// q1=0.1994730109;
		// q2=-0.4035480550;
		// q3=0.2821767187;
		// O2x=6.8563951297;
		// O2y=6.1722766255;
		// O2z=6.2896361683;
		// 
		// 
		//  
		// double r[2]={r1,r2};
		//     double l[2]={l1,l2};
		//     double q[4]={q0,q1,q2,q3};       
		//     double O2[3]={O2x,O2y,O2z};
		//      for(int i=0;i<10000;i++)
		//      {
		// 	std::cout<<i<<"\n";
		// 	 EE_Cyl obj(10,1.0);
		//      }
		//     EE obj(r,l,q,O2);
		//     int DL(double rD,double lD,double rS,double lS,double qSD[4],double OSD[3],double &th1,double &s,double &tl);

		// obj.ResultDisp();
		//     std::cout<<tl<<"\t"<<t2<<"\n";
		return 0;
}
