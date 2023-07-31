#include "password1.h"
#include<iostream>
#include<string>
void password1::getPassword(){
    std::cout<<"\nChoose a password for your system:"<<"\n";
    std::cin>>pass;
    }
    
	int password1::verifyPassword()
	{
	std::string x;
	std::cout<<"\nEnter the password:"<<"\n";
	std::cin>>x;
	if (x==pass)
	return 1;
	else 
	return 0;	 	
   }
    
    void password1::passwordProtect(){
    	int veri=verifyPassword();
	
		 if(veri==1){
		 	std::cout<<"\nAccess Granted!"<<"\n";
		 }
		 else 
		 {
		//std::cout<<std::right<<std::setw(40)<<std::setfill(' ')<<"\nWrong Password\nAccess Denied!\n\nSystem will shut down\n\nPlease come back again."<<"\n";
		
		 exit(0);
		 }
	}
