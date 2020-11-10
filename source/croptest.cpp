#include "cropparent.h"
#include "cropchild.h"

#include <bits/stdc++.h>
using namespace std;
#include <list>
#include <iterator>
#include <gtest/gtest.h>
namespace 
{

	class  croptest : public ::testing::Test 
	{

		protected:

  			void SetUp() 
  			{ 
  			
		  		std::list<string> res;
		     		std::list<string> ::iterator iter;
		     		std::string state,district,season,crop;
		     		double area,production;
		     		int year;
		    		std::string S, T;
		    		fstream fin;
		    		int count=1;
		    		fin.open("Crop_Dataset.csv", ios::in);
		    		while(getline(fin, S))
		    		{
		    			stringstream X(S);
		    			while (getline(X, T,'\n'))
		   			 {
		   	 			res.push_back(T);
		    			 }
		   	        }
		    		iter=res.begin();
		   		 ++iter;
		    		for(;iter!=res.end();++iter)
		    		{
		    			stringstream ss(*iter); 
		    			while (ss.good()) 
		    			{ 
						string substr; 
						getline(ss, substr, ','); 
						//cout<<substr<<"  ";
						switch(count)
						{
							case 1:
								state=substr;
								break;
							case 2:
								district=substr;
								break;
							case 3:
								year=std::stoi(substr);
								break;
							case 4:
								season=substr;
								break;
							case 5:
								crop=substr;
								break;
							case 6:
								area=std::stod(substr);
								break;
							case 7:
								production=std::stod(substr);
								ptr = new cropchild(state, district,year,season,crop,area,production);
								
								state="";district="";season="";crop="";
								count=0;year=0;area=0.0;production=0.0;
								break;
						
						}
						++count;
						
		    			} 
		  		}
    
 			 }
  			void TearDown()
  			 {
    				delete ptr;
 			 }
  		cropparent *ptr;  
	};

	TEST_F(croptest, DefaultConstructor) 
	{
	  cropchild cc;
	  EXPECT_EQ(0, cc.getCropYear());
	  EXPECT_EQ(0, cc.getSeason().length());
	  EXPECT_EQ(0, cc.getStateName().length());
	  EXPECT_EQ(0, cc.getDistrictName().length());
	  EXPECT_EQ(0, cc.getCrop().length());
	  EXPECT_EQ(0, cc.getArea());
	  EXPECT_EQ(0, cc.getProduction());
	 
	}
	
	TEST_F(croptest, ParameterizedConstructor) 
	{
	  cropchild *cptr = dynamic_cast<cropchild*>(ptr);
	  EXPECT_EQ(2014, cptr->getCropYear());
	  EXPECT_EQ("Whole Year", cptr->getSeason());
	  EXPECT_EQ("Karnataka", cptr->getStateName());
	  EXPECT_EQ("UDUPI", cptr->getDistrictName());
	  EXPECT_EQ("Turmeric", cptr->getCrop());
	  EXPECT_EQ(52, cptr->getArea());  
	  EXPECT_EQ(311, cptr->getProduction());
	  
	  
	}
	
	TEST_F(croptest, ComputationPrice) 
	{
		  cropchild *cptr = dynamic_cast<cropchild*>(ptr);
	      EXPECT_EQ(9330, ptr->computePrice(cptr->getCrop(),cptr->getProduction()));      //311*30 = 9330
	}
	
	//OPERATOR OVERLOADING  for AREA 
	TEST_F(croptest, operatorOverloading)
	{
		cropchild c1("Karnataka","BELLARY",2012,"Whole Year","Rice",2502,3500);
		cropchild c2("Karnataka","BELGAUM",2012,"Kharif","Rice",2321,1250);
		EXPECT_EQ(4823,c1+c2);
		
	}
	

} 

