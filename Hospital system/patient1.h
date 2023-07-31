#ifndef PATIENT1_H
#define PATIENT1_H
#include<iostream>
#include<string>
class patient1
{
	//decleration for variable and funtion used in class
	public:
		
		std::string fname,lname,occupation,p_city,dis,addDate,relDate;
		int p_age,p_ID;
		long double phnumber,bill;
		std::string getDept();
		void getDoctor();
		void addPat();
		void editPat(patient1 &pat);
		void displayPat();
		void deletePat();
		void dispPatDatabase();
		void numberofPats();
   		void getPatientDatabase();
   		
	protected:
};

#endif
