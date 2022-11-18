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

#include "cylinderproximity/DS.h"
/**
 *
 * Point 1 from Disk
 * Point 2 from Shell
 * 
 * */
/** @returns 	0 when successful
 * 		1 Error in DL()
 * 		2 Error in Cl()
 * 		3 Error in DD()
 * 		-1 Error in DS()
 * */
int EE::DS(double rD,double lD,double rS,double lS,double qSD[4],double OSD[3])
{
	/*     std::cout<<"................\n";
				 std::cout<<"DS Starts Here\n";
				 std::cout<<rD<<"\t"<<lD<<"\t"<<rS<<"\t"<<lS<<"\t"<<qSD[0]<<"\t"<<qSD[1]<<"\t"<<qSD[2]<<"\t"<<qSD[3]<<"\t"<<OSD[0]<<"\t"<<OSD[1]<<"\t"<<OSD[2]<<"\n";
				 */

	double th1,s1,tl2;
	short int flagDL=DL(rD,lD,rS,lS,qSD,OSD,th1,s1,tl2);
	// std::cout<<s1<<"\t"<<tl2<<"\n";
	if(flagDL)
	{
		std::cout<<"................\n";
		std::cout<<"Error in DL, Code "<<flagDL<<"\n";
		std::cout<<"................\n";
		return 1;
	}
	if(s1>0&&s1<1&&tl2>0&&tl2<1)
	{
		minD-=rS;       
		cyl1_primitive=D_b;
		cyl2_primitive=L;               
		//	std::cout<<"DS Ends Here\n";
		//	std::cout<<"................\n";
		algoPath[++algoChar]='1';
		return 0;
	}
	else
	{
		if (s1<=0||s1>=1)//Outside the disk
		{

			double tCL2;
			short int flagCL=CL(rD,lD,rS,lS,qSD,OSD,tCL2);
			// 	    std::cout<<tCL2<<"\n";
			if(flagCL)
			{
				std::cout<<"................\n";
				std::cout<<"Error in CL, Code "<<flagCL<<"\n";
				std::cout<<"................\n";
				return 2;
			}
			if (tCL2>0&&tCL2<1)
			{
				minD-=rS;
				cyl1_primitive=C_b;
				cyl2_primitive=L;
				//		std::cout<<"DS Ends Here\n";
				//	std::cout<<"................\n";
				algoPath[++algoChar]='2';
				return 0;
			}
			else
			{
				algoPath[++algoChar]='4';
				bool v=(tCL2>1?1:0);
				double RSD[3][3];
				q2R(qSD,RSD);
				double local_D[3]={0,0,v*lS};
				double tmp_D[3],ODD[3];    
				MatVecMul(RSD,local_D,tmp_D);
				AddVec(tmp_D,OSD,ODD);
				short int flagDD=DD(rD,lD,rS,lS, qSD,ODD);
				if(flagDD)
				{
					std::cout<<"................\n";
					std::cout<<"Error in DD, Code "<<flagDD<<"\n";
					std::cout<<"................\n";
					return 3;
				}
				if(v)
				{
					if(cyl2_primitive==C_b)
						cyl2_primitive=C_t;
					if(cyl2_primitive==D_b)
						cyl2_primitive=D_t ;
				}
				//	std::cout<<"DS Ends Here\n";
				//	std::cout<<"................\n";
				return 0;
			}
		}
		else
		{
			algoPath[++algoChar]='3';
			bool v=(tl2>1?1:0);
			double RSD[3][3];
			q2R(qSD,RSD);
			double local_D[3]={0,0,v*lS};
			double tmp_D[3],ODD[3];    
			MatVecMul(RSD,local_D,tmp_D);
			AddVec(tmp_D,OSD,ODD);
			short int flagDD=DD(rD,lD,rS,lS, qSD,ODD);
			if(flagDD)
			{
				std::cout<<"................\n";
				std::cout<<"Error in DD, Code "<<flagDD<<"\n";
				std::cout<<"................\n";
				return 3;
			}
			if(v)
			{
				if(cyl2_primitive==C_b)
					cyl2_primitive=C_t;
				if(cyl2_primitive==D_b)
					cyl2_primitive=D_t; 
			}
			//  std::cout<<"DS Ends Here\n";
			//  std::cout<<"................\n";
			return 0;
		}
	}
	std::cout<<".............................\n";
	std::cout<<"Error in DS\n";
	std::cout<<".............................\n";
	return -1;    

}
