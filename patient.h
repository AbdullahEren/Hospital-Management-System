#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>
#include <mysql.h>

using namespace std;

class patient{
	public:
	
		void addPatient();
		void editPatient();
		void findPatient();
		void viewPatient();
		void delPatient();

	private:
	
	string patientUsername, patientPassword, patientName, patientAge, patientGender, patientDisease;
	char patientId[40];
	char patientPhone[40];
    string dummy;
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
};

#endif
