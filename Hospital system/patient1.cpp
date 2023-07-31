#include "patient1.h"
#include<string>
#include<iostream>
#include<iomanip>
#include<fstream>
void patient1::addPat() {
	patient1 p;										//ID,firstname,lastname,age,phnumber,occupation,city,disease,Adate,Rdate,bill,spec
	    std::cout<<"Fill up the following details"<<"\n";
	    std::cout<<"ID:"<<"\n";
	    std::cin>>p.p_ID;
   		std::cout<<"First Name:"<<"\n";
   		std::cin>>p.fname;
   		std::cout<<"Last Name:"<<"\n";
   		std::cin>>p.lname;
   		std::cout<<"Age:"<<"\n";
   		std::cin>>p.p_age;
		std::cout<<"Phone No.:"<<"\n";
   		std::cin>>p.phnumber;
   		std::cout<<"Occupation:"<<"\n";
		std::cin>>p.occupation;
		std::cout<<"City:"<<"\n";
		std::cin>>p.p_city;
   		std::cout<<"Disease/Symptoms:"<<"\n";
   		std::cin>>p.dis;
   		std::cout<<"Admission date  (DD/MM/YYYY):"<<"\n";
   		std::cin>>p.addDate;
   		std::cout<<"Release date  (DD/MM/YYYY):"<<"\n";
   		std::cin>>p.relDate;	
   		std::cout<<"Total Bill generated:"<<"\n";
   		std::cin>>p.bill;
		std::cout<<"Kind of Specialization required:"<<"\n";
		std::string dept=p.getDept();
		system("cls");
		std::fstream patObj;   //declaration for Object of file save data
		patObj.open("patient.txt",std::ios::app );	//create text file for save data
      //ID,firstname,lastname,age,phnumber,occupation,city,disease,Adate,Rdate,bill,dept

        patObj.seekp (0, std::ios::end);	//check data in file at the end
		patObj<<p.p_ID<<"\n"<<p.fname<<"\n"<<p.lname<<"\n"<<p.p_age<<"\n"<<p.phnumber<<"\n"<<p.occupation<<"\n"<<p.p_city<<"\n"<<p.dis<<"\n"<<p.addDate<<"\n"<<p.relDate<<"\n"<<p.bill<<"\n"<<dept<<"\n";	//Assign values
		patObj.close();	
	
	std::cout<<"\n\t\tNew Patient profile created successfully!"<<"\n"<<"\n"<<"\n";
	std::cout<<"\n\n\n\nEnter 1 to return to Patient Database\nEnter 2 to Exit."<<"\n";
	int c;
	std::cin>>c;	//input for futher process EXit or continue
	if(c==1){
	  system("cls");
	  getPatientDatabase();	 //backtoPatientMenu
	}
	  
	else
	  exit(0); 
}

void patient1::deletePat() {
	int x;
	std::cout<<"\nEnter the ID of the Patient whose profile you want to Delete:"<<"\n";
	std::cin>>x;									 
	std::fstream patObj("patient.txt");	//create/check text file 
	patObj.seekg(0);
													//ID,firstname,lastname,age,phnumber,occupation,city,disease,Adate,Rdate,bill,dept
	std::string fname,lname,occupation,p_city,dis,addDate,relDate,dept;
	int p_age,p_ID,count=0;
	long double phnumber,bill;
	while(patObj>>p_ID>>fname>>lname>>p_age>>phnumber>>occupation>>p_city>>dis>>addDate>>relDate>>bill>>dept) 	//condition for searching required patient from text file
	{
		if(p_ID==x){
		std::cout<<"1.ID:"<<p_ID<<"\n"<<"2.First Name:"<<fname<<"\n"<<"3.Last Name:"<<lname<<"\n"<<"4.Age"<<p_age<<"\n"<<"5.Phone No.:"<<phnumber<<"\n"<<"6.Occupation:"<<occupation<<"\n"<<"7.City:"<<p_city<<"\n"<<"8.Disease/Symptoms:"<<dis<<"\n"<<"9.Admission date(DD/MM/YYYY):"<<addDate<<"\n"<<"10.Release date(DD/MM/YYYY):"<<relDate<<"\n"<<"11.Total Bill generated:"<<bill<<"\n"<<"12.Kind of Specialization required:"<<dept<<"\n";		//display the output
		count++;
		break;
		}
	}
	
	patObj.close();
	if(count==0){
		system("cls");
		std::cout<<"\nNo matching records found!"<<"\n";
		getPatientDatabase();	//getback to patient database
	}
	std::cout<<"Are you sure you want to delete this profile?\n1.YES\n2.NO"<<"\n";
	int n;std::cin>>n;
	if(n==1)
	{
	std::fstream file("patient.txt");
	file.seekg (0, std::ios::beg);		//for checking data in text file from the begining
	file.seekg(0);
	int line;
    std::ofstream tempObj;		//object declaration for output from text file
	tempObj.open("copy2.txt");	//create/check text file for copy data ie edit data
    tempObj.seekp(0);
  	int skip = 0;
  	std::string fname1,lname1,occupation1,p_city1,dis1,addDate1,relDate1,dept1;
	int p_age1;
	long double phnumber1,bill1;
	file.seekg(0);file.seekg(0,std::ios::cur); //setting the pointer to beginning of file
		
//	 if (tempObj.is_open())
// 		 std::cout << "File successfully open";
//	else
//    	std::cout << "Error opening file";
	while(file>>line>>fname1>>lname1>>p_age1>>phnumber1>>occupation1>>p_city1>>dis1>>addDate1>>relDate1>>bill1>>dept1)
	{
		if(line!=x){
			tempObj<<line<<"\n"<<fname1<<"\n"<<lname1<<"\n"<<p_age1<<"\n"<<phnumber1<<"\n"<<occupation1<<"\n"<<p_city1<<"\n"<<dis1<<"\n"<<addDate1<<"\n"<<relDate1<<"\n"<<bill1<<"\n"<<dept1<<"\n";
		}			
	}
	//removing data from patient text file and assigned to copy text file

  file.close();
  tempObj.close();
  remove("patient.txt");
  int result;
  char oldname[] ="copy2.txt";
  char newname[] ="patient.txt";
  result= rename( oldname , newname );
  system("cls");
  std::cout<<"\n\t\tFile successfully deleted"<<"\n";
}

std::cout<<"\n\nEnter 1 to return to Patient Database\nEnter 2 to Exit."<<"\n";
	int c;
	std::cin>>c;
	if(c==1){
	  system("cls");
	  getPatientDatabase();		//getback patient database
	}
	  
	else
	  exit(0);
}

void patient1::displayPat() {
	int x;
	std::cout<<"\nEnter the ID of the Patient whose profile you want to Display:"<<"\n";
	std::cin>>x;									 
	std::fstream patObj("patient.txt");
	patObj.seekg(0);
													//ID,firstname,lastname,age,phnumber,occupation,city,disease,Adate,Rdate,bill,dept
	std::string fname,lname,occupation,p_city,dis,addDate,relDate,dept;
	int p_age,p_ID,count=0;
	long double phnumber,bill;
	while(patObj>>p_ID>>fname>>lname>>p_age>>phnumber>>occupation>>p_city>>dis>>addDate>>relDate>>bill>>dept)		//Assigning values
	{
		if(p_ID==x){
		std::cout<<"1.ID:"<<p_ID<<"\n"<<"2.First Name:"<<fname<<"\n"<<"3.Last Name:"<<lname<<"\n"<<"4.Age"<<p_age<<"\n"<<"5.Phone No.:"<<phnumber<<"\n"<<"6.Occupation:"<<occupation<<"\n"<<"7.City:"<<p_city<<"\n"<<"8.Disease/Symptoms:"<<dis<<"\n"<<"9.Admission date(DD/MM/YYYY):"<<addDate<<"\n"<<"10.Release date(DD/MM/YYYY):"<<relDate<<"\n"<<"11.Total Bill generated:"<<bill<<"\n"<<"12.Kind of Specialization required:"<<dept<<"\n";
		count++;
		break;
		}
	}
	
	patObj.close();
	if(count==0){	//conditon if not matcing any number
		system("cls");
		std::cout<<"\nNo matching records found!"<<"\n";
		getPatientDatabase();	//getback patient database
	}
	
std::cout<<"\n\nEnter 1 to return to Patient Database\nEnter 2 to Exit."<<"\n";
	int c;
	std::cin>>c;
	if(c==1){
	  system("cls");
	  getPatientDatabase();		//getback patient database
	}
	  
	else
	  exit(0);	
}
	
		
void patient1::dispPatDatabase() {
		std::fstream Obj("patient.txt");	//Access patient text file
	Obj.seekg(0);
	std::cout<<std::right<<std::setw(70)<<std::setfill(' ')<<"PATIENT DATABASE"<<"\n"<<"\n";
	std::string fname,lname,occupation,p_city,dis,addDate,relDate,dept;
	int p_age,p_ID,count=0;
	long double phnumber,bill;
	while(Obj>>p_ID>>fname>>lname>>p_age>>phnumber>>occupation>>p_city>>dis>>addDate>>relDate>>bill>>dept)	//Assigning and displaying values from text file
	{   count++;
		std::cout<<std::right<<std::setw(50)<<std::setfill(' ')<<"Patient Profile:"<<count<<"\n";
		std::cout<<"1.ID:"<<p_ID<<"\n"<<"2.First Name:"<<fname<<"\n"<<"3.Last Name:"<<lname<<"\n"<<"4.Age"<<p_age<<"\n"<<"5.Phone No.:"<<phnumber<<"\n"<<"6.Occupation:"<<occupation<<"\n"<<"7.City:"<<p_city<<"\n"<<"8.Disease/Symptoms:"<<dis<<"\n"<<"9.Admission date(DD/MM/YYYY):"<<addDate<<"\n"<<"10.Release date(DD/MM/YYYY):"<<relDate<<"\n"<<"11.Total Bill generated:"<<bill<<"\n"<<"12.Kind of Specialization required:"<<dept<<"\n"<<"\n";
		
		}
		
	Obj.close();
	
	if(count==0){
		//system("cls");
		std::cout<<"\nNo matching records found!"<<"\n";
		getPatientDatabase();	//getback to patient database
	}
	
std::cout<<"\n\nEnter 1 to return to Patient Database\nEnter 2 to Exit."<<"\n";
	int c;
	std::cin>>c;
	if(c==1){
	  system("cls");
	  getPatientDatabase();		//getback to patient database
	}
	  
	else
	  exit(0);	//exit program
}

void patient1::editPat(patient1 &pat ) {
		int x;
	std::cout<<"\nEnter the ID of the Patient whose profile you want to Edit:"<<"\n";
	std::cin>>x;									 
	std::fstream patObj("patient.txt");		//Access Pateint Text file
	patObj.seekg(0);		//search from start
													//ID,firstname,lastname,age,phnumber,occupation,city,disease,Adate,Rdate,bill,dept
	std::string fname,lname,occupation,p_city,dis,addDate,relDate,dept;
	int p_age,p_ID,count=0;
	long double phnumber,bill;
	while(patObj>>p_ID>>fname>>lname>>p_age>>phnumber>>occupation>>p_city>>dis>>addDate>>relDate>>bill>>dept)	//Assigning and display access values from text file
	{
		if(p_ID==x){
		std::cout<<"1.ID:"<<p_ID<<"\n"<<"2.First Name:"<<fname<<"\n"<<"3.Last Name:"<<lname<<"\n"<<"4.Age"<<p_age<<"\n"<<"5.Phone No.:"<<phnumber<<"\n"<<"6.Occupation:"<<occupation<<"\n"<<"7.City:"<<p_city<<"\n"<<"8.Disease/Symptoms:"<<dis<<"\n"<<"9.Admission date(DD/MM/YYYY):"<<addDate<<"\n"<<"10.Release date(DD/MM/YYYY):"<<relDate<<"\n"<<"11.Total Bill generated:"<<bill<<"\n"<<"12.Kind of Specialization required:"<<dept<<"\n";
		count++;
		break;
		}
	}
	
	patObj.close();
	if(count==0){	//diplay if no record found against given value
		system("cls");
		std::cout<<"\nNo matching records found!\n"<<"\n";
		getPatientDatabase();	//getback to Patient Database
	}
	
							//datatransfer begins
	std::fstream file("patient.txt");
	file.seekg (0, std::ios::beg);	//search from the begining
	file.seekg(0);
	int line;
    std::ofstream tempObj;	//create object to write data in copy.text file
	tempObj.open("copy2.txt");
    tempObj.seekp(0);
  	int skip = 0;
  	std::string fname1,lname1,occupation1,p_city1,dis1,addDate1,relDate1,dept1;
	int p_age1;
	long double phnumber1,bill1;
	file.seekg(0);file.seekg(0,std::ios::cur); //setting the pointer to beginning of file
		
//	 if (tempObj.is_open())
// 		 std::cout << "File successfully open";
//	else
//    	std::cout << "Error opening file";
	while(file>>line>>fname1>>lname1>>p_age1>>phnumber1>>occupation1>>p_city1>>dis1>>addDate1>>relDate1>>bill1>>dept1)	//same as previous comments
	{
		if(line!=x){
			tempObj<<line<<"\n"<<fname1<<"\n"<<lname1<<"\n"<<p_age1<<"\n"<<phnumber1<<"\n"<<occupation1<<"\n"<<p_city1<<"\n"<<dis1<<"\n"<<addDate1<<"\n"<<relDate1<<"\n"<<bill1<<"\n"<<dept1<<"\n";
		}			
	}

  file.close();
  tempObj.close();
  remove("patient.txt");
  int result;
  char oldname[] ="copy2.txt";
  char newname[] ="patient.txt";
  result= rename( oldname , newname );
								//datatransfer ends
	repeatEditPatient:
	int edit;
	std::cout<<"\nEnter number corresponding to the Field you want to Edit:"<<"\n"<<"\n";
	std::cin>>edit;										//ID,firstname,lastname,age,phnumber,occupation,city,disease,Adate,Rdate,bill,spec
	switch(edit)						
	{
		case 1:{
			std::cout<<"ID"<<"\n";
			std::cin>>p_ID;
			break;
		}
		case 2:{
			std::cout<<"First Name:"<<"\n";
			std::cin>>fname;
			
			break;
		}
		case 3:{
			std::cout<<"Last Name:"<<"\n";
			std::cin>>lname;
			
			break;
		}
		case 4:{std::cout<<"Age:"<<"\n";
			std::cin>>p_age;
			break;
		}
		case 5:{
			std::cout<<"Phone No.:"<<"\n";
   			std::cin>>phnumber;
			break;
		}
		case 6:{
			std::cout<<"Occupation:"<<"\n";
			std::cin>>occupation;
			break;
		}
		case 7:{
			std::cout<<"City:"<<"\n";
			std::cin>>p_city;
			break;
		}
		
		case 8:{
			std::cout<<"Disease/Symptoms:"<<"\n";
			std::cin>>dis;
			break;
		}
		case 9:{
			std::cout<<"Admission date  (DD/MM/YYYY):"<<"\n";
			std::cin>>addDate;
			break;
		}
		case 10:
		{
		std::cout<<"Release date  (DD/MM/YYYY):"<<"\n";
		std::cin>>relDate;
		}
		case 11:{
			std::cout<<"Total Bill generated:"<<"\n";
			std::cin>>bill;
			break;
		}
		case 12:{
			std::cout<<"Kind of Specialization required:"<<"\n";
			dept=pat.getDept();
			break;
		}
		default:{
			std::cout<<"\nCome on!Enter a valid option."<<"\n";
			goto repeatEditPatient;
		}
	}

	system("cls");
	std::cout<<std::right<<std::setw(50)<<std::setfill(' ')<<"--Updated Profile--"<<"\n"<<"\n";
	std::cout<<"1.ID:"<<p_ID<<"\n"<<"2.First Name:"<<fname<<"\n"<<"3.Last Name:"<<lname<<"\n"<<"4.Age"<<p_age<<"\n"<<"5.Phone No.:"<<phnumber<<"\n"<<"6.Occupation:"<<occupation<<"\n"<<"7.City:"<<p_city<<"\n"<<"8.Disease/Symptoms:"<<dis<<"\n"<<"9.Admission date(DD/MM/YYYY):"<<addDate<<"\n"<<"10.Release date(DD/MM/YYYY):"<<relDate<<"\n"<<"11.Total Bill generated:"<<bill<<"\n"<<"12.Kind of Specialization required:"<<dept<<"\n";
	
	//updated datatransfer
	std::fstream newObj;	
	newObj.open("patient.txt", std::ios::app);
	 newObj.seekp (0, std::ios::end);
	 newObj<<p_ID<<"\n"<<fname<<"\n"<<lname<<"\n"<<p_age<<"\n"<<phnumber<<"\n"<<occupation<<"\n"<<p_city<<"\n"<<dis<<"\n"<<addDate<<"\n"<<relDate<<"\n"<<bill<<"\n"<<dept<<"\n";
	 newObj.close();
	 
	 //after completion
	std::cout<<"\n\nEnter 1 to return to Patient Database\nEnter 2 to Exit."<<"\n";
	int c;
	std::cin>>c;
	if(c==1){
	  system("cls");
	  getPatientDatabase();
	}
	  
	else
	  exit(0);

	
}

std::string patient1::getDept() {		//Patient required Department function
	std::string sp;
	repeatPatientDep:
	std::cout<<"1.GENERAL_MEDICINE"<<"\n";
	std::cout<<"2.NEUROLOGY"<<"\n";
	std::cout<<"3.ONCOLOGY"<<"\n";
	std::cout<<"4.HAEMATOLOGY"<<"\n";
	std::cout<<"5.GASTROENTEROLOGY"<<"\n";
	std::cout<<"6.GYNAECOLOGY "<<"\n"<<"\n";
	int s;
	std::cin>>s;
	switch(s){
		
		case 1:{
			sp= "GENERAL_MEDICINE";
			break;
		}
		case 2:{
			sp="NEUROLOGY";
			break;
		}
		case 3:{
		    sp="ONCOLOGY";
			break;
		}
		case 4:{
			sp= "HAEMATOLOGY";
			break;
		}
		case 5:{
			sp= "GASTROENTEROLOGY";
			break;
		}
		case 6:{
			sp= "GYNAECOLOGY ";
			break;
		}
		default:{
		std::cout<<"\nCome on!Enter a valid option.\n"<<"\n";
			goto repeatPatientDep;
		}
	
	}
		return sp;
}


void patient1::getPatientDatabase() {	
		int choice_pat;
	repeatPtDb:
	std::cout<<"\n                         "<<"WELCOME TO PATIENT'S DATABASE"<<"\n"<<"\n";
	std::cout<<"			"<<"1.Add New Patient's Information"<<"\n";
	std::cout<<"			"<<"2.Edit a Patient's Information"<<"\n";
	std::cout<<"			"<<"3.Display a Patient's Information"<<"\n";
	std::cout<<"			"<<"4.Delete a Patient's Information"<<"\n";
	std::cout<<"			"<<"5.Display Entire Patient Database"<<"\n";
	std::cout<<"			"<<"6.Total Number of Patients"<<"\n";
	std::cout<<"			"<<"7.Check for doctor availability"<<"\n";
	std::cout<<"			"<<"8.Exit"<<"\n";
	std::cout<<std::right<<std::setw(80)<<std::setfill('-')<<"----------"<<"\n";	
	
	std::cout<<std::right<<std::setw(60)<<std::setfill(' ')<<"\nEnter the number corresponding to your choice:"<<"\n"<<"\n";
	std::cin>>choice_pat;	//input for choice
	system("cls");
	switch(choice_pat){
		case 1:{
		    addPat();	//calling of add patient function
			break;
		}
		case 2:{ 
			patient1 p;		//create patient class object
			editPat(p);		//calling of edit patient function
			break;
		}
		case 3:{
			displayPat();		//calling function of display patients
			break;
		}
		case 4:{
			deletePat();		//calling function of delete patient
			break;
		}
		case 5:{
			dispPatDatabase();		//calling function of display all patient data
			break;
		}
		case 6:{
//numberOfPats()
			numberofPats();		//calling function of diplay total number of patient entered in database
			break;
		}
		case 7:{
//getDoctor	  
			getDoctor();
			break;
		}
		

		case 8:{
//exit	
			exit(0);	//Exit Program
			break;
		}
			
	}
	if( choice_pat>8) {
		std::cout<<"\n Wrong Information, Please Enter Correct Information";
		goto repeatPtDb;
	}
}
void patient1::getDoctor() {
	
}
void patient1::numberofPats() {
		std::fstream Obj("patient.txt");	//Access Text file
	Obj.seekg(0);
	std::string fname,lname,occupation,p_city,dis,addDate,relDate,dept;
	int p_age,p_ID,count=0;
	long double phnumber,bill;
	while(Obj>>p_ID>>fname>>lname>>p_age>>phnumber>>occupation>>p_city>>dis>>addDate>>relDate>>bill>>dept)	//Condtion for checking data in file
	{  
	 count++;		//count total number of patients
	}
		
	Obj.close();
	std::cout<<"\n\n\tThe number of patients in the hospital="<<count<<"\n";
	
std::cout<<"\n\nEnter 1 to return to Patient Database\nEnter 2 to Exit."<<"\n";
	int c;
	std::cin>>c;
	if(c==1){
	  system("cls");
	  getPatientDatabase();	//getback patient database
	}
	  
	else
	  exit(0);	
}
