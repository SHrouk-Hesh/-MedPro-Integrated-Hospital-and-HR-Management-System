#include "bed1.h"
#include<fstream>
#include<iostream>
#include<iomanip>
void bed1::getStatus() {
	bed1 b;
  	std::cout<<"\n\tTotal Number of Beds in the hospital:"<<b.total<<"\n";
  	std::fstream file("patient.txt");			//access patient text file
  	file.seekg(0);	//control goes to start of file
	std::string fname,lname,occupation,p_city,dis,addDate,relDate,dept;
	int p_age,p_ID,count=0;
	long double phnumber,bill;
	while(file>>p_ID>>fname>>lname>>p_age>>phnumber>>occupation>>p_city>>dis>>addDate>>relDate>>bill>>dept)		//check alldata from text file
	{  
	 count++;	//count the total number of patients	
	}
		
	file.close();
	std::cout<<"\n\tThe number of Occupied Beds="<<count<<"\n";		//display total patients entered in text file
	std::cout<<"\n\tThe number of Empty Beds="<<b.total-count<<"\n";	//display total empty beds 
	
	std::cout<<"\n\nEnter 1 to return to Bed Database\nEnter 2 to Exit."<<"\n";
	int c;
	std::cin>>c;
	if(c==1){
	  system("cls");
	  b.getBedDatabase();	//getback to Bed Database
	}
	  
	else
	  exit(0);	//Exit Program
}

void bed1::getBedDatabase() {
	int choice_bed;
	repeatBed:
	std::cout<<"\n                         "<<"WELCOME TO BED DATABASE"<<"\n"<<"\n";
	std::cout<<"			"<<"1.Check Bed Status"<<"\n";	
	std::cout<<"			"<<"2.Exit"<<"\n"<<"\n";	
		std::cout<<std::right<<std::setw(80)<<std::setfill('-')<<"----------"<<"\n";
	
	std::cout<<std::right<<std::setw(60)<<std::setfill(' ')<<"\nEnter the number corresponding to your choice:"<<"\n"<<"\n";
	std::cin>>choice_bed;
	system("cls");
	switch(choice_bed)
	{
		case 1:{
//getStatus()
		    getStatus();	//calling function of Bed Status function
			break;
		}
		case 2:{
//exit	
			exit(0);	//Exit Program
			break;
		}
	}
	if(choice_bed>2) {	//condition if wrong choice selection
		std::cout<<"\n Wrong Information, Please Enter Correct Information";
		goto repeatBed;
	}
}
