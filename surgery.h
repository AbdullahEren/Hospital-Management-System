#ifndef SURGERY_H
#define SURGERY_H
#include <iostream>
#include <mysql.h>

using namespace std;

class surgery{
	public:
	
		void addSur();
		void editSur();
		void findSur();
		void viewSur();
		void delSur();
		

	private:
	char surgeryDoctorid[45];
	string surgeryDepartment, surgeryNum,surgeryAvailibility;
	
    string dummy;
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
};

#endif
