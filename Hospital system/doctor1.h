#ifndef DOCTOR1_H
#define DOCTOR1_H
#include<string>
#include<iostream>
class doctor1
{
	public:
		std::string d_fname,d_lname;
		int d_ID, d_age,experience,d_totalno;
		std::string qual,d_city;
		std::string getSpec();
   		void addDoc();
   	 	void editDoc(doctor1 &docobj);
   	 	void displayDoc();
   	 	void deleteDoc();
   	 	void dispDatabase();
   	 	void numberofDocs();
   	 	void getDoctorDatabase();
	protected:
};

#endif
