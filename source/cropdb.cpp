#include "cropdb.h"
#include "cropchild.h"
#include<iostream>
#include <list>
#include <iterator>
#include<iostream>
#include <algorithm>
bool cropdb::addCrop(std::string state, std::string district,int year, std::string season, std::string crop, double area,double production)
{
	crop_list.push_back(cropchild(state,district,year,season,crop,area,production));
	return true;
}
//Count total number of Records in the data-set file
int cropdb::countAll()
{
	std::list<cropchild> :: iterator iter;
	int count=0;
	iter=crop_list.begin();
   	for(;iter!=crop_list.end();++iter)
    	{
    		++count;
			
    	}
   	return count;
}
//Total Number of crops grown by a district in given year.
int cropdb::numberOfCropsGrown(std::string district,int year)
{
	int count=0;

	//using STL Algorithms and Lambda functions
	count = std::count_if(crop_list.begin(),crop_list.end(),[district, year](cropchild& ref)
															{
																return ( (!ref.getDistrictName().compare(district)) && ref.getCropYear()==year) ;
															});
	return count;
}
//For particular district Checking for Year which produced Maximum quantity of  given crop 
int cropdb::maxProductionYear(std::string district,std::string crop)
{
	std::list<cropchild> :: iterator iter;
	int year=0,maxProd=0;
    	auto maxyear = std::max_element(crop_list.begin(),crop_list.end(),[district,crop](cropchild& ref1,cropchild& ref2)
											{
												return( (ref1.getProduction() <ref2.getProduction() ) );
												
											});

		
		return maxyear->getCropYear();
}
//Checking for District which produced Maximum quantity of given crop in particular year. 
std::string cropdb::maxProductionDistrict(int year,std::string crop)
{
	std::list<cropchild> :: iterator iter;
	std::string district;
	int maxProd=0;
   	for(iter=crop_list.begin();iter!=crop_list.end();++iter)
    	{
        	if(  (iter->getCropYear()==year)  && !(iter->getCrop().compare(crop)) )  
        	{	
        		if(iter->getProduction() >= maxProd)
        		{
        			maxProd = iter->getProduction();
        			district=iter->getDistrictName();;
        		}
        	}
        	
    	}
    	
    	return district;
}




template <typename T>
T cropdb::maxProductionDistrict(T year,T crop)
{
	std::list<cropchild> :: iterator iter;
	std::string district;
	int maxProd=0;
   	for(iter=crop_list.begin();iter!=crop_list.end();iter++)
    	{
        	if(  (iter->getCropYear()==year)  && !(iter->getCrop().compare(crop)) )  
        	{	
        		if(iter->getProduction() >= maxProd)
        		{
        			maxProd = iter->getProduction();
        			district=iter->getDistrictName();;
        		}
        	}
        	
    	}
    	
    	return district;
}

//overloading
int cropdb::maxProductionYear(std::string district)
{
	std::list<cropchild> :: iterator iter;
	int year=0,maxProd=0;
   	for(iter=crop_list.begin();iter!=crop_list.end();iter++)
    	{
        	if(  !iter->getDistrictName().compare(district)  )  
        	{	
        		if(iter->getProduction() >= maxProd)
        		{
        			maxProd = iter->getProduction();
        			year = iter->getCropYear();
        		}
        	}
        	
    	}
    	
    	return year;
} 


/*
   	for(iter=crop_list.begin();iter!=crop_list.end();iter++)
    	{
        	if(  !iter->getDistrictName().compare(district) && !(iter->getCrop().compare(crop)) )  
        	{	
        		if(iter->getProduction() >= maxProd)
        		{
        			maxProd = iter->getProduction();
        			year = iter->getCropYear();
        		}
        	}
        	
    	}*/
		
