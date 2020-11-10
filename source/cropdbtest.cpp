#include "cropparent.h"
#include "cropchild.h"
#include "cropdb.h"
#include <gtest/gtest.h>

#include <bits/stdc++.h>
using namespace std;
#include <list>
#include <iterator>

namespace {

class cropdbtest : public ::testing::Test {

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
    			//cout<<*iter<<endl;
    			stringstream ss(*iter); 
    			while (ss.good()) 
    			{ 
        			string substr; 
        			getline(ss, substr, ','); 
        			switch(count)
        			{
        				case 1:
        					state=substr;
        					break;
        				case 2:
        					district=substr;
        					break;
        				case 3:
        					year=stoi(substr);
        					break;
        				case 4:
        					season=substr;
        					break;
        				case 5:
        					crop=substr;
        					break;
        				case 6:
        					area=stod(substr);
        					break;
        				case 7:
        					production=stod(substr);
        					c.addCrop(state, district,year,season,crop,area,production);
        					
        					state="";district="";season="";crop="";
        					count=0;year=0;area=0.0;production=0.0;
        					break;
        			
        			}
        			++count;
        			
    			} 
  		}
    
  }
  void TearDown() {}
  cropdb c;
};

//Count total number of Records in the data-set file
TEST_F(cropdbtest, countDataSet) 
{
  //c.countAll()
  EXPECT_EQ(5755, c.countAll());
}

//Total Number of crops grown by a district in given year.
TEST_F(cropdbtest, numberofcropsgrown) {
 
 //c.numberOfCropsGrown("BELLARY",1997)
  EXPECT_EQ(19, c.numberOfCropsGrown("BELLARY",1997));
}


//Checking for District which produced Maximum quantity of given crop in particular year. 
TEST_F(cropdbtest, maxProductionDistrict)
{
	//c.maxProductionDistrict(2005,"Rice")
   EXPECT_EQ("MYSORE",c.maxProductionDistrict(2005,"Rice"));
}

//For particular district Checking for Year which produced Maximum quantity of  given crop 
TEST_F(cropdbtest, maxProduction)
{
	//c.maxProductionYear("DHARWAD","Mango")
   EXPECT_EQ(2010, c.maxProductionYear("DHARWAD","Mango"));
}

//overloading
TEST_F(cropdbtest, maxProductionOverloading)
{
   EXPECT_EQ(2000, c.maxProductionYear("BELLARY"));//sugarcane
}


} // namespace



//template usage
/*
TEST_F(cropdbtest, maxProductionDistrict)
{
   EXPECT_EQ("BELGAUM",(c.maxProductionDistrict<int,std::string>(1998,"Wheat")));  
   EXPECT_EQ("MYSORE",(c.maxProductionDistrict<int,std::string>(2005,"Rice")));
   EXPECT_EQ("GULBARGA",(c.maxProductionDistrict<int,std::string>(2008,"Jowar")));
}*/

/*


TEST_F(cropdbtest, maxProduction)
{
   EXPECT_EQ(2010, c.maxProductionYear("BELLARY","Bajra"));
   EXPECT_EQ(2010, c.maxProductionYear("DHARWAD","Mango"));
}
TEST_F(cropdbtest, maxProductionDistrict)
{
   EXPECT_EQ("BELGAUM",c.maxProductionDistrict(1998,"Wheat"));  
   EXPECT_EQ("MYSORE",c.maxProductionDistrict(2005,"Rice"));
   EXPECT_EQ("GULBARGA",c.maxProductionDistrict(2008,"Jowar"));
}


*/
