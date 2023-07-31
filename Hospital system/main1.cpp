#include<iostream>
#include<iomanip>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include "password1.h"
#include "doctor1.h"
#include "patient1.h"
#include "bed1.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int chooseMain();
int main() {
	password1 pswd;
	doctor1 dr;
	patient1 pt;
	bed1 bd;
	pswd.getPassword();
	int choice1;
	do { 
		 system("cls");
	std::cout<<"\n";
	std::cout<<std::right<<std::setw(60)<<std::setfill(' ')<<"WELCOME TO HOSPITAL MANAGEMENT SYSTEM "<<"\n";
	std::cout<<"\n"<<"\n";
	std::cout<<std::right<<std::setw(60)<<std::setfill(' ')<<"------------------------------------------------"<<"\n";
	
	std::cout<<std::right<<std::setw(40)<<std::setfill(' ')<<"1.Main Menu"<<"\n";
	std::cout<<std::right<<std::setw(35)<<std::setfill(' ')<<"2.Exit"<<"\n";
	std::cout<<std::right<<std::setw(60)<<std::setfill(' ')<<"------------------------------------------------"<<"\n"<<"\n";
	std::cout<<"Enter your choice:"<<"\n"<<"\n";
	//aove lines are display to help in choice
	
	std::cin>>choice1; //input for selection
	
	if (choice1==1){ 	//execution condition for above choice
		 system("cls");	//clear screen
		 int var=chooseMain(); //calling of second choice function which is given below
		 system("cls");

		 	switch(var){	//execution condition for second choice
			case 1:{ 
				pswd.passwordProtect();	//function calling for password verification/protection
				system("cls");
				dr.getDoctorDatabase(); //if above condition (password) is true then calling this function to enter doctor database
				break;
			}
			
			case 2:{
			   pswd.passwordProtect(); //same as line 40
				system("cls");
				pt.getPatientDatabase(); //if above condition (password) is true then calling this function to enter Patient database
				break;
				
			}
				
			case 3:{
			    pswd.passwordProtect();
				system("cls");
				bd.getBedDatabase();	//if above condition (password) is true then calling this function to enter Bed database
				break;
			}
					 
			case 4:
				{
				return 0;
				break;
				}
			default:
				std::cout<<"\nCome on!Enter a valid option."<<"\n";	//condition if someone enter wrong number in second choice selection
		}
		
	}
	else if(choice1==2){
		return 0;
	}
	else
	 std::cout<<"\nCome on!Enter a valid option."<<"\n";	//condition if someone enter wrong number in first choice selection
	 
	} while (choice1!=2);
   

	return 0;
}

int chooseMain(){	//second choice selection
	
	int choice2;
	repeat:
	std::cout<<std::right<<std::setw(40)<<std::setfill(' ')<<"\nMAIN MENU"<<"\n"<<"\n"<<"\n";
	std::cout<<std::right<<std::setw(80)<<std::setfill('-')<<"----------"<<"\n";
	std::cout<<"			"<<"1.Enter Into Doctors' Database"<<"\n";
	std::cout<<"			"<<"2.Enter Into Patients' Database"<<"\n";
	std::cout<<"			"<<"3.Check for Hospital Bed Availability"<<"\n";
	std::cout<<"			"<<"4.Exit"<<"\n"<<"\n";
	std::cout<<std::right<<std::setw(80)<<std::setfill('-')<<"----------"<<"\n"; //above lines are just for display
	
	std::cout<<"\nEnter the number corresponding to your choice:"<<"\n";
	std::cin>>choice2;	//input for second choice
	if(choice2==1||choice2==2||choice2==3||choice2==4) {	//condition if choice number is wrong then it repeat the choice
		goto last;
	} else {
		std::cout<<"\n                    You Entered Wrong Number, Please Enter Correct Number";	//display if entered wrong number for choice
		goto repeat;
		
	}
		
		last:
			return choice2;		//return the choice number
	
}

