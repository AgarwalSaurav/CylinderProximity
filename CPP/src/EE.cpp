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

# include "cylinderproximity/EE.h"

// This class is designed to be a base class only as it is an abstract class. No objects of this class can be created.


/** Displays the point p1, p2 and minimum distance
 * */
void EE::ResultDisp()
{
	/*   std::cout<<"................\n";
			 std::cout<<p1[0]<<"\t"<<p1[1]<<"\t"<<p1[2]<<"\n";
			 std::cout<<p2[0]<<"\t"<<p2[1]<<"\t"<<p2[2]<<"\n";
			 std::cout<<minD<<"\n";
			 std::cout<<cyl1_primitive<<"\n";
			 std::cout<<cyl2_primitive<<"\n";
			 for(int i=0;i<=algoChar;i++)
			 std::cout<<algoPath[i];
			 std::cout<<"\n................\n"; */

}
void EE::CollisionCheck()
{
	/*   if(minD<eps)
			 std::cout<<"COLLISION HAS OCCURRED\n";
			 else
			 std::cout<<"COLLISION SAFE\n";*/
}

int EE::Set(Cyl &E1,Cyl &E2,double eps1)
{
	double R1[3][3],R2[3][3],R3[3][3],O10[3],O20[3];
	E1.Get(r1,l1,R1,O10);
	E2.Get(r2,l2,R2,O20);
	double R[3][3],q[4];
	MatMul(R1,R2,R3,1);

	double Otemp[3],O21[3];
	Otemp[0]=O20[0]-O10[0];
	Otemp[1]=O20[1]-O10[1];
	Otemp[2]=O20[2]-O10[2];
	MatVecMul(R1,Otemp,O21,1);

	double distO21=sqrt(O21[0]*O21[0]+O21[1]*O21[1]);
	double denoRtr=1./distO21;
	RtrCos = O21[0]*denoRtr;
	RtrSin = O21[1]*denoRtr;
	double Rtr[3][3];   
	Rtr[0][0] = RtrCos;
	Rtr[0][1] = RtrSin;
	Rtr[0][2] = 0;
	Rtr[1][0] = -RtrSin;
	Rtr[1][1] = RtrCos;
	Rtr[1][2] = 0;
	Rtr[2][0] = 0;
	Rtr[2][1] = 0;
	Rtr[2][2] = 1;

	//    Transpose(Rtr,RtrF);

	MatMul(Rtr,R3,R,0);
	R2q(R,q);

	q0=q[0];
	q1=q[1];
	q2=q[2];
	q3=q[3];
	//    std::cout <<"Quaternions: "<<q0<<"\t"<<q1<<"\t"<<q2<<"\t"<<q3<<"\t"<< std::endl;
	O2x=distO21;
	O2y=0;
	O2z=O21[2];

	cc_check=0;

	eps=eps1;

	cyl1_primitive=NA;
	cyl2_primitive=NA;

	algoPath[9]='\0';
	for (algoChar=8;algoChar>=0;algoChar--)
	{
		algoPath[algoChar]='X';
	}
	return 0;

}

int EE::Degen()
{
	double dotprod=q0*q0-q1*q1-q2*q2+q3*q3;
	double eps0=10e-10;
	if(fabs(fabs(dotprod)-1)<eps0)
	{
		std::cout<<"Case 2 (Degenerate) : Parallel Cylinders\n";
		algoPath[0]='P';
		double dist=sqrt(O2x*O2x)-r1-r2;
		if(dotprod>0)
		{
			if (O2z>=-l2 && O2z<=l1)
			{
				cyl1_primitive=S;
				cyl2_primitive=S;
				minD=dist;
			}

			else if (dist<eps)
			{
				if(O2z < -l2)
				{
					cyl1_primitive=D_b;
					cyl2_primitive=D_t;
					minD=-O2z+l2;
				}    
				if(O2z > l1)
				{
					cyl1_primitive=D_t;
					cyl2_primitive=D_b;
					minD=O2z-l1;    
				}		    
			}
			else
			{
				if (O2z<-l2)
				{
					// 		        double q[4]={q0,q1,q2,q3};
					double O2[3]={O2x,O2y,O2z+l2};
					// 		        CC(r1,l1,r2,l2,q,O2);
					minD=sqrt(dist*dist+O2[2]*O2[2]);
					cyl1_primitive=C_b;
					cyl2_primitive=C_t;
				}
				if (O2z>l1)
				{
					double O2[3]={O2x,O2y,O2z-l1};
					cyl1_primitive=C_t;
					cyl2_primitive=C_b;
					minD=sqrt(dist*dist+O2[2]*O2[2]);
					// 		        if(!CC(r1,l1,r2,l2,q,O2))
					// 		        {
					// 			    p1[2]+=l1;
					// 			    p2[2]+=l1;
					// 		        }
				}
			}
			return 2;
		}
		if(dotprod<0)
		{
			if(O2z>=0 && O2z<=l1+l2)
			{
				cyl1_primitive=S;
				cyl2_primitive=S;
				minD=dist;
			}
			else if (dist<eps)
			{
				if (O2z<0)
				{
					cyl1_primitive=D_b;
					cyl2_primitive=D_b;
					minD=-O2z;
				}		        
				if( O2z>l1+l2)
				{
					cyl1_primitive=D_t;
					cyl2_primitive=D_t;
					minD=O2z-l1-l2;
				}

			}
			else
			{
				if (O2z<0)
				{
					//double q[4]={q0,q1,q2,q3};
					double O2[3]={O2x,O2y,O2z};
					minD=sqrt(dist*dist+O2[2]*O2[2]);
					// 		    CC(r1,l1,r2,l2,q,O2);
					cyl1_primitive=D_b;
					cyl2_primitive=D_b;
				}
				if (O2z>l1+l2)
				{
					//double q[4]={q0,q1,q2,q3};
					double O2[3]={O2x,O2y,O2z+l2-l1};
					minD=sqrt(dist*dist+O2[2]*O2[2]);
					cyl1_primitive=D_t;
					cyl2_primitive=D_t;
					// 		    if(!CC(r1,l1,r2,l2,q,O2))
					// 		    {
					// 			p1[2]+=l1;
					// 			p2[2]+=l1;
					// 		    }
				}
			}
			return 2;
		}
	}

	return 0;

}

int EE::CylOwnCheck()
{
	if(ss_minD<eps||ss_minD==DBL_MAX)
		return 0;
	std::cout<<"In CylOwnCheck now\n";
	std::cout<<ss_p1[0]<<"\t"<<ss_p1[1]<<"\t"<<ss_p1[2]<<"\n";
	std::cout<<ss_p2[0]<<"\t"<<ss_p2[1]<<"\t"<<ss_p2[2]<<"\n";
	double rad1=sqrt(ss_p2[0]*ss_p2[0]+ss_p2[1]*ss_p2[1])-r2;
	std::cout<<"Rad1="<<rad1<<"\n";

	if(rad1<eps && ss_p2[2]<l1)
	{
		std::cout<<"Owned: Cylinder 1 in Cyl 2\n";
		// 	return 1;
	}

	double q12[4]={-q0,q1,q2,q3};
	double O12[3]={-O2x,-O2y,-O2z};
	double R12[3][3];
	q2R(q12,R12);
	double tmp_p1[3],p1_E2[3];
	AddVec(O12,ss_p1,tmp_p1);
	MatVecMul(R12,tmp_p1,p1_E2);
	double rad2=sqrt(p1_E2[0]*p1_E2[0]+p1_E2[1]*p1_E2[1])-r1;
	std::cout<<"Rad2="<<rad2<<"\n";
	if(rad2<eps && p1_E2[2]<l2)
	{
		std::cout<<"Owned: Cylinder 2 in Cyl 1\n";
		return 2;
	}
	return 0;
}
/**Case 1.1 handler
 *
 * Calls SS()
 * Checks condition for Case 1.2 and 1.3
 * @returns 	0 successful
 * 		1 Error in SS()
 * 		2 Error in Case1_2()
 * 		3 Error in Case1_3()
 * 		-1 Error in Case1_1()
 *
 **/
int EE::Case1_1()
{
	//  std::cout<<"................\n";
	// std::cout<<"Case1_1\n";
	// std::cout<<"................\n";
	int flag1=SS();
	if(flag1)
	{
		std::cout<<"................\n";
		std::cout<<"Error in SS, Code "<<flag1<<"\n";
		std::cout<<"................\n";
		return 1;
	}
	if(t1>0 && t1<1 && t2>0 && t2<1)
	{
		cyl1_primitive=S;
		cyl2_primitive=S;
		algoPath[++algoChar]='A';
		return 0;
	}

	if((t1>=1||t1<=0) && (t2>=1||t2<=0))
	{
		int flag3=Case1_3();
		if(flag3)
		{
			std::cout<<"................\n";
			std::cout<<"Error in Case1_3, Code "<<flag3<<"\n";
			std::cout<<"................\n";
			return 3;

		}
		return 0;

	}
	else
	{
		int flag2=Case1_2();
		if(flag2)
		{
			std::cout<<"................\n";
			std::cout<<"Error in Case1_2, Code "<<flag2<<"\n";
			std::cout<<"................\n";
			return 2;
		}
		return 0;
	}
	return -1;
}

/** @returns 	0 successful
 * 		1 Error in 1st DS()
 * 		2 Error in 2nd DS()
 * 		-1 Error in Case1_2()
 * 
 **/
int EE::Case1_2()
{
	//  std::cout<<"................\n";
	// std::cout<<"Case1_2\n";
	// std::cout<<"................\n";
	algoPath[++algoChar]='B';
	if((t1<=0||t1>=1)&&t2>0&&t2<1)
	{
		//	  std::cout<<"t1 out "<<t1<<"\n";
		bool u=(t1>1?1:0);
		double OD[3]={O2x,O2y,O2z-l1*u};
		double q21[4]={q0,q1,q2,q3};
		int flag1_2DS1=DS(r1,l1,r2,l2,q21,OD);
		if(!flag1_2DS1)
		{
			p1[2]+=l1*u;
			p2[2]+=l1*u;
			if(u)
			{
				if(cyl1_primitive==C_b)
					cyl1_primitive=C_t;
				if(cyl1_primitive==D_b)
					cyl1_primitive=D_t ;
			}
			return 0;
		} 
		else
		{
			std::cout<<"................\n";
			std::cout<<"Error in DS, Code "<<flag1_2DS1<<"\n";
			std::cout<<"................\n";
			return 1;
		}
	}
	if(t1>0&&t1<1&&(t2<=0||t2>=1))
	{
		double q21[4]={q0,q1,q2,q3};
		double q12[4]={-q0,q1,q2,q3};
		double O12[3]={-O2x,-O2y,-O2z};
		double O21[3]={O2x,O2y,O2z};
		bool v=(t2>1?1:0);
		double R12[3][3],R21[3][3];
		q2R(q12,R12);
		q2R(q21,R21);	
		double OD[3];
		MatVecMul(R12,O12,OD);
		OD[2]-=v*l2;
		int flag1_2DS2=DS(r2,l2,r1,l1,q12,OD);
		if(!flag1_2DS2)
		{
			double tmp_p[3],tmp1_p[3];
			tmp_p[0]=p1[0];
			tmp_p[1]=p1[1];
			tmp_p[2]=p1[2]+l2*v;
			MatVecMul(R21,tmp_p,tmp1_p);
			AddVec(tmp1_p,O21,p1);

			tmp_p[0]=p2[0];
			tmp_p[1]=p2[1];
			tmp_p[2]=p2[2]+l2*v;
			MatVecMul(R21,tmp_p,tmp1_p);
			AddVec(tmp1_p,O21,p2);
			tmp_pri=cyl1_primitive;
			cyl1_primitive=cyl2_primitive;
			cyl2_primitive=tmp_pri;
			if(v)
			{
				if(cyl2_primitive==C_b)
					cyl2_primitive=C_t;
				if(cyl2_primitive==D_b)
					cyl2_primitive=D_t; 
			}
			return 0;
		}
		else
		{
			std::cout<<"................\n";
			std::cout<<"Error in DS, Code "<<flag1_2DS2<<"\n";
			std::cout<<"................\n";
			return 2;
		}
	}
	return -1;

}

/** @returns 	0 successful
 * 		1 Error in 1st DS()
 * 		2 Error in 2nd DS() 
 **/
int EE::Case1_3()
{
	// std::cout<<"................\n";
	// std::cout<<"Case1_3\n";
	/// std::cout<<"................\n";
	algoPath[++algoChar]='C';
	bool u=(t1>1?1:0);
	double OD[3]={O2x,O2y,O2z+l1*u};
	double q21[4]={q0,q1,q2,q3};
	double q12[4]={-q0,q1,q2,q3};
	double O21[3]={O2x,O2y,O2z};
	double O12[3]={-O2x,-O2y,-O2z};
	double R12[3][3],R21[3][3];
	q2R(q12,R12);
	q2R(q21,R21);
	double ppp[3];
	double pp1[3]={0,0,l2};
	MatVecMul(R21,pp1,ppp);    
	AddVec(O21,ppp,ppp);
	// std::cout<<ppp[0]<<"\t"<<ppp[1]<<"\t"<<ppp[2]<<"\n";

	//1st DS
	int flag1_3DS1=DS(r1,l1,r2,l2,q21,OD);
	if(flag1_3DS1)
	{
		std::cout<<"................\n";
		std::cout<<"Error in DS, Code "<<flag1_3DS1<<"\n";
		std::cout<<"................\n";
		return 1;
	}
	p1[2]+=l1*u;
	p2[2]+=l1*u;
	double tmpD=minD;

	bool v=(t2>1?1:0);

	MatVecMul(R12,O12,OD);
	OD[2]-=v*l2;
	double t_p1[3],t_p2[3];
	std::copy(p1,p1+3,t_p1);
	std::copy(p2,p2+3,t_p2);
	//2nd DS
	int flag1_3DS2=DS(r2,l2,r1,l1,q12,OD);
	if(flag1_3DS2)
	{
		std::cout<<"................\n";
		std::cout<<"Error in DS, Code "<<flag1_3DS2<<"\n";
		std::cout<<"................\n";
		return 2;
	}
	if(minD<tmpD)
	{
		double tmp_p[3],tmp1_p[3],tmp2_p[3];
		tmp_p[0]=p1[0];
		tmp_p[1]=p1[1];
		tmp_p[2]=p1[2]+l2*v;
		MatVecMul(R21,tmp_p,tmp1_p);
		tmp_p[0]=p2[0];
		tmp_p[1]=p2[1];
		tmp_p[2]=p2[2]+l2*v;
		MatVecMul(R21,tmp_p,tmp2_p);
		AddVec(tmp1_p,O21,p2);
		AddVec(tmp2_p,O21,p1);
	}
	else
	{
		minD=tmpD;
		std::copy(t_p1,t_p1+3,p1);
		std::copy(t_p2,t_p2+3,p2);
	}
	return 0;
}

void EE::RandomGen(int a,float n)
{
	cyl1_primitive=NA;
	cyl2_primitive=NA;

	algoPath[9]='\0';
	for (algoChar=8;algoChar>=0;algoChar--)
	{
		algoPath[algoChar]='X';
	}

	eps=10e-5;
	Randomize(r1,a);
	Randomize(r2,a);
	r2=a+r2;
	Randomize(l1,a);
	Randomize(l2,a);
	double R[3][3];
	RandomRot(R);
	double l_k[3]={0,0,1};
	MatVecMul(R,l_k,kvec);
	double r;
	Randomize(r,a);
	O2x=(a+r)*kvec[0];
	O2y=(a+r)*kvec[1];
	O2z=(a+r)*kvec[2];
	RandomRot(R);
	MatVecMul(R,l_k,kvec);

	Randomize(kphi,n*M_PI);
	double sinphiby2=sin(kphi/2);
	q0=cos(kphi/2);
	q1=kvec[0]*sinphiby2;
	q2=kvec[1]*sinphiby2;
	q3=kvec[2]*sinphiby2;
	std::cout<<std::fixed<<std::setprecision(10);

}
void EE::DisplayInput()
{
	/*    std::cout<<std::fixed<<std::setprecision(15);
				std::cout<<"r1="<<r1<<"\n";
				std::cout<<"r2="<<r2<<"\n";
				std::cout<<"l1="<<l1<<"\n";
				std::cout<<"l2="<<l2<<"\n";
				std::cout<<"q0="<<q0<<"\n";
				std::cout<<"q1="<<q1<<"\n";
				std::cout<<"q2="<<q2<<"\n";
				std::cout<<"q3="<<q3<<"\n";
				std::cout<<"O2x="<<O2x<<"\n";
				std::cout<<"O2y="<<O2y<<"\n";
				std::cout<<"O2z="<<O2z<<"\n";*/
}

void EE::pointtransform()
{
	double Rtr[3][3];

	Rtr[0][0] = RtrCos;
	Rtr[0][1] = -RtrSin;
	Rtr[0][2] = 0;
	Rtr[1][0] = RtrSin;
	Rtr[1][1] = RtrCos;
	Rtr[1][2] = 0;
	Rtr[2][0] = 0;
	Rtr[2][1] = 0;
	Rtr[2][2] = 1;

	double p1p[3]=
	{
		p1[0],p1[1],p1[2]
	};

	double p2p[3]=
	{
		p2[0],p2[1],p2[2]
	};


	MatVecMul(Rtr,p1p,p1);
	MatVecMul(Rtr,p2p,p2);

}
void EE::pointtransform1(double a, double b, double pa[3], double pb[3])
{
	double Rtr[3][3];

	Rtr[0][0] = a;
	Rtr[0][1] = -b;
	Rtr[0][2] = 0;
	Rtr[1][0] = b;
	Rtr[1][1] = a;
	Rtr[1][2] = 0;
	Rtr[2][0] = 0;
	Rtr[2][1] = 0;
	Rtr[2][2] = 1;

	double p1p[3]=
	{
		pa[0],pa[1],pa[2]
	};

	double p2p[3]=
	{
		pb[0],pb[1],pb[2]
	};


	MatVecMul(Rtr,p1p,pa);
	MatVecMul(Rtr,p2p,pb);

}
