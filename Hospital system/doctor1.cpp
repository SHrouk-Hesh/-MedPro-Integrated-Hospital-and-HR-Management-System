#include "doctor1.h"
#include<string>
#include<iostream>
#include<iomanip>
#include<fstream>
void doctor1::addDoc() {
	doctor1 d;
	
	//displaying and input the data for new doctor in database
	    std::cout<<"Fill up the following details"<<"\n";
	    std::cout<<"ID:"<<"\n";
	    std::cin>>d.d_ID;
   		std::cout<<"First Name:"<<"\n";
   		std::cin>>d.d_fname;
   		//getline(std::cin, d.d_fname);
   		std::cout<<"Last Name:"<<"\n";
   		std::cin>>d.d_lname;
   		//getline(std::cin, d.d_lname);
   		std::cout<<"Age:"<<"\n";
   		std::cin>>d.d_age;
   		std::cout<<"Choose Qualification among the following:\n1.MBBS\n2.MD"<<"\n";
   		int q;
   		std::cin>>q;
   		if(q==1)
   			d.qual="MBBS";
		else d.qual="MD";
		std::cout<<"Choose Specialization among the following:"<<"\n";
		std::string spec=d.getSpec();
		std::cout<<"Experience (in Years):"<<"\n";
		std::cin>>d.experience;
		std::cout<<"City:"<<"\n";
		//gets(d.d_city);
		std::cin>>d.d_city;
		//scanf(" %[^\n]s",d.d_city);
		//getline(std::cin, d.d_city);
		system("cls");
		
		
		std::fstream fileObj;   //for wrinting data in text file
		fileObj.open("doctor.txt",std::ios::app );	//create / check text file
      //ID,firstname,lastname,age,qualification,specialization,experience,city

        fileObj.seekp (0, std::ios::end);	//control moves to end of the text file
		fileObj<<d.d_ID<<"\n"<<d.d_fname<<"\n"<<d.d_lname<<"\n"<<d.d_age<<"\n"<<d.qual<<"\n"<<spec<<"\n"<<d.experience<<"\n"<<d.d_city<<"\n";	//write data in text file
		fileObj.close();
	
	//after completion
	std::cout<<"\n\t\tNew Doctor profile created successfully!"<<"\n"<<"\n"<<"\n";
	std::cout<<"\n\n\n\nEnter 1 to return to Doctor Database\nEnter 2 to Exit."<<"\n";
	int c;
	std::cin>>c;
	if(c==1){
	  system("cls");
	  d.getDoctorDatabase();	//getback to doctor database
	}
	  
	else
	  exit(0);

}

void doctor1::deleteDoc() {
	doctor1 d;
	std::string x;
	std::cout<<"\nEnter the ID of the Doctor whose profile you want to Delete:"<<"\n";
	std::cin>>x;									 //ID,firstname,lastname,age,qualification,specialization,experience,city
	std::fstream fileObj("doctor.txt");		//Access text file
	fileObj.seekg(0);	//control goes the begining of text file
	
	int age,exp,count=0;
	std::string ID,fname,lname,ci,qua,spe;
	while(fileObj>>ID>>fname>>lname>>age>>qua>>spe>>exp>>ci)	
	{
		if(ID==x){
		std::cout<<"\n\n1.ID:"<<ID<<"\n"<<"2.First Name:"<<fname<<"\n"<<"3.Last Name:"<<lname<<"\n"<<"4.Age:"<<age<<"\n"<<"5.Qualification:"<<qua<<"\n"<<"6.Specialization:"<<spe<<"\n"<<"7.Experience:"<<exp<<"\n"<<"8.City:"<<ci<<"\n"<<"\n";
		count++;
		break;
		}
	}
	
	fileObj.close();
	if(count==0){	
		system("cls");
		std::cout<<"\nNo matching records found!"<<"\n";
			  d.getDoctorDatabase();	//getback to Doctor Database
	}
	std::cout<<"Are you sure you want to delete this profile?\n1.YES\n2.NO"<<"\n";
	int n;std::cin>>n;
	if(n==1){
	std::fstream file("doctor.txt");
	file.seekg (0, std::ios::beg);	//seek data from the begining in text file
	file.seekg(0);
	std::string line;
    std::ofstream tempObj;
	tempObj.open("copy.txt");
    tempObj.seekp(0);
  int skip = 0;
  int age1,exp1;
	std::string fname1,lname1,ci1,qua1,spe1;
	file.seekg(0);file.seekg(0,std::ios::cur); //setting the pointer to beginning of file
		
//	 if (tempObj.is_open())
// 		 std::cout << "File successfully open";
//	else
//    	std::cout << "Error opening file";
	while(file>>line>>fname1>>lname1>>age1>>qua1>>spe1>>exp1>>ci1)
	{
		if(line!=x){
			tempObj<<line<<"\n"<<fname1<<"\n"<<lname1<<"\n"<<age1<<"\n"<<qua1<<"\n"<<spe1<<"\n"<<exp1<<"\n"<<ci1<<"\n";
		}			
	}

  file.close();
  tempObj.close();
  remove("doctor.txt");
  int result;
  char oldname[] ="copy.txt";
  char newname[] ="doctor.txt";
  result= rename( oldname , newname );
  system("cls");
  std::cout<<"\n\t\tFile successfully deleted"<<"\n";
  
}
	std::cout<<"\n\nEnter 1 to return to Doctor Database\nEnter 2 to Exit."<<"\n";
	int c;
	std::cin>>c;
	if(c==1){
	  system("cls");
	  d.getDoctorDatabase();
	}
	  
	else
	  exit(0);
}

void doctor1::dispDatabase() {
	doctor1 d;
	std::fstream fileObj("doctor.txt");
	fileObj.seekg(0);
	std::cout<<std::right<<std::setw(70)<<std::setfill(' ')<<"DOCTOR DATABASE"<<"\n"<<"\n";
	int age,exp,count=0;
	std::string ID,fname,lname,ci,qua,spe;
	while(fileObj>>ID>>fname>>lname>>age>>qua>>spe>>exp>>ci)
	{
		count++;
		std::cout<<std::right<<std::setw(50)<<std::setfill(' ')<<"Doctor Profile:"<<count<<"\n";
		std::cout<<"\n\n1.ID:"<<ID<<"\n"<<"2.First Name:"<<fname<<"\n"<<"3.Last Name:"<<lname<<"\n"<<"4.Age:"<<age<<"\n"<<"5.Qualification:"<<qua<<"\n"<<"6.Specialization:"<<spe<<"\n"<<"7.Experience:"<<exp<<"\n"<<"8.City:"<<ci<<"\n"<<"\n";
	}
	if(count==0)
	{
	system("cls");
	std::cout<<"\nNo matching records found!"<<"\n";
 	 d.getDoctorDatabase();
	}
	
	std::cout<<"\n\nEnter 1 to return to Doctor Database\nEnter 2 to Exit."<<"\n";
	int c;
	std::cin>>c;
	if(c==1)
	{
	  system("cls");
	  d.getDoctorDatabase();
	} 
	else
	  exit(0);
}

void doctor1::displayDoc() {
	int x;
doctor1 d;
std::cout<<"\n\nEnter the ID of the Doctor whose profile you want to display:"<<"\n";
std::cin>>x;									 //ID,firstname,lastname,age,qualification,specialization,experience,city
	std::ifstream file;file.open("doctor.txt",std::ios::out|std::ios::in);
	file.seekg(0);
		
	int ID,age,exp,count=0;
	std::string fname,lname,ci,qua,spe;
	
//	 if (file.is_open())
// 		 std::cout << "File successfully open";
//	else
//    std::cout << "Error opening file";
  
	while(file >> ID >> fname >> lname >>age >>qua >> spe >>exp >> ci)   //!fileObj.eof()
	{
	
		if(ID==x)
		{
		std::cout<<"\n\n1.ID:"<<ID<<"\n"<<"2.First Name:"<<fname<<"\n"<<"3.Last Name:"<<lname<<"\n"<<"4.Age:"<<age<<"\n"<<"5.Qualification:"<<qua<<"\n"<<"6.Specialization:"<<spe<<"\n"<<"7.Experience:"<<exp<<"\n"<<"8.City:"<<ci<<"\n"<<"\n";
		count++;
		}
	}
	file.close();
	if (count==0)
			std::cout<<"\nNo matching records found!"<<"\n";
			
	std::cout<<"\n\nEnter 1 to return to Doctor Database\nEnter 2 to Exit."<<"\n";
	int c;
	std::cin>>c;
	if(c==1){
	  system("cls");
	  d.getDoctorDatabase();
	}
	  
	else
	  exit(0);

}

void doctor1::editDoc(doctor1 &docobj) {
	doctor1 d;
	std::string x;
	std::cout<<"\nEnter the ID of the Doctor whose profile you want to Edit:"<<"\n";
	std::cin>>x;									 //ID,firstname,lastname,age,qualification,specialization,experience,city
	std::fstream fileObj("doctor.txt");
	fileObj.seekg(0);
	
	int age,exp,count=0;
	std::string ID,fname,lname,ci,qua,spe;
	while(fileObj>>ID>>fname>>lname>>age>>qua>>spe>>exp>>ci)
	{
		if(ID==x){
		std::cout<<"\n\n1.ID:"<<ID<<"\n"<<"2.First Name:"<<fname<<"\n"<<"3.Last Name:"<<lname<<"\n"<<"4.Age:"<<age<<"\n"<<"5.Qualification:"<<qua<<"\n"<<"6.Specialization:"<<spe<<"\n"<<"7.Experience:"<<exp<<"\n"<<"8.City:"<<ci<<"\n"<<"\n";
		count++;
		break;
		}
	}
	
	fileObj.close();
	if(count==0){
		std::cout<<"\nNo matching records found!"<<"\n";
		system("cls");
	  d.getDoctorDatabase();
	}
	
							//datatransfer begins
	std::fstream file("doctor.txt");
	file.seekg (0, std::ios::beg);
	file.seekg(0);
	std::string line;
    std::ofstream tempObj;
	tempObj.open("copy.txt");
    tempObj.seekp(0);
  int skip = 0;
  int age1,exp1;
	std::string fname1,lname1,ci1,qua1,spe1;
	file.seekg(0);file.seekg(0,std::ios::cur); //setting the pointer to beginning of file
//		
//	 if (tempObj.is_open())
// 		 std::cout << "File successfully open";
//	else
//    	std::cout << "Error opening file";

	while(file>>line>>fname1>>lname1>>age1>>qua1>>spe1>>exp1>>ci1)
	{
		if(line!=x){
			tempObj<<line<<"\n"<<fname1<<"\n"<<lname1<<"\n"<<age1<<"\n"<<qua1<<"\n"<<spe1<<"\n"<<exp1<<"\n"<<ci1<<"\n";
		}			
	}

  file.close();
  tempObj.close();
  remove("doctor.txt");
  int result;
  char oldname[] ="copy.txt";
  char newname[] ="doctor.txt";
  result= rename( oldname , newname );
	repeatEdit:							//datatransfer ends
	int edit;
	std::cout<<"Enter number corresponding to the Field you want to Edit:"<<"\n";
	std::cin>>edit;
	std::cout<<"\n";
	switch(edit)							//ID,firstname,lastname,age,qualification,specialization,experience,city
	{
		case 1:{
			std::cout<<"ID"<<"\n";
			std::cin>>ID;
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
			std::cin>>age;
			break;
		}
		case 5:{
			std::cout<<"Choose Qualification among the following:\n1.MBBS\n2.MD"<<"\n";
   		int q;
   		std::cin>>q;
   		if(q=1){
		   	qua="MBBS";
		   }
   		
		else {
			qua="MD";
		}
			
		break;
		}
		case 6:{
			system("cls");
			spe=docobj.getSpec();
			break;
		}
		case 7:{std::cout<<"Experience:"<<"\n";
			std::cin>>exp;
			break;
		}
		case 8:{std::cout<<"City:"<<"\n";
			std::cin>>ci;
			break;
		}
		default:{
		std::cout<<"Invalid Input!"<<"\n";
		goto repeatEdit;
		}
}
}

void doctor1::getDoctorDatabase() {
	int choice_doc;
	repeatDocDb:
	std::cout<<"\n                         " <<"WELCOME TO DOCTOR'S DATABASE"<<"\n"<<"\n";
	std::cout<<"			"<<"1.Add New Doctor's Information"<<"\n";
	std::cout<<"			"<<"2.Edit a Doctor's Information"<<"\n";
	std::cout<<"			"<<"3.Display a Doctor's Information"<<"\n";
	std::cout<<"			"<<"4.Delete a Doctor's Information"<<"\n";
	std::cout<<"			"<<"5.Display Entire Doctor Database"<<"\n";
	std::cout<<"			"<<"6.Total Number of Doctors"<<"\n";
	std::cout<<"			"<<"7.Exit"<<"\n";
	std::cout<<std::right<<std::setw(80)<<std::setfill('-')<<"----------"<<"\n";
	
	std::cout<<std::right<<std::setw(60)<<std::setfill(' ')<<"\nEnter the number corresponding to your choice:"<<"\n"<<"\n";
	std::cin>>choice_doc;
	system("cls");
	switch(choice_doc){
		case 1:{
//addDoc()
		   addDoc();
			break;
		}
		case 2:{
//editDoc()  
			doctor1 k;
			editDoc(k);
			break;
		}
		case 3:{
//displayDoc()
			displayDoc();
			break;
		}
		case 4:{
//deleteDoc()
			deleteDoc();
			break;
		}
		case 5:{
//dispDatabase()
			dispDatabase();
			break;
		}
		case 6:{
//numberOfDocs()
			numberofDocs();
			break;
		}

		case 7:{
//exit	
			exit(0);
			break;
		}
			
	}
	if(choice_doc>7) {
	std::cout<<"\nWong Information, Please Enter correct Information";
	goto repeatDocDb;
}
}

std::string doctor1::getSpec() {
 	std::string sp;
 	int s;
 	repeatSpec:
 	std::cout<<"1.GENERAL_MEDICNE"<<"\n";
	std::cout<<"2.NEUROLOGY"<<"\n";
	std::cout<<"3.ONCOLOGY"<<"\n";
	std::cout<<"4.HAEMATOLOGY"<<"\n";
	std::cout<<"5.GASTROENTEROLOGY"<<"\n";
	std::cout<<"6.GYNAECOLOGY "<<"\n";
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
			std::cout<<"\nCome on!Enter a valid option."<<"\n";
			
		}
	
	}
		if(s>6)	
			goto repeatSpec;
	return sp;	
}

void doctor1::numberofDocs() {
	doctor1 d;
	std::fstream fileObj("doctor.txt");
	fileObj.seekg(0);
	int age,exp,count=0;
	std::string ID,fname,lname,ci,qua,spe;
	while(fileObj>>ID>>fname>>lname>>age>>qua>>spe>>exp>>ci)
	{	count++;
	}
	std::cout<<"\n\n\tThe no. of doctors in the hospital="<<count<<"\n"<<"\n";
	
	std::cout<<"\n\nEnter 1 to return to Doctor Database\nEnter 2 to Exit."<<"\n";
	int c;
	std::cin>>c;
	if(c==1)
	{
	  system("cls");
	  d.getDoctorDatabase();
	} 
	else
	  exit(0);
}

