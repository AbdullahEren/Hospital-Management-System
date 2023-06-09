#ifndef DOCTOR_H
#define DOCTOR_H
#include <string>
#include <iostream>
#include <mysql.h>

using namespace std;

class doctor{
	public:

		void addrec();
		void editrec();
		void findmed();
		void viewDetails();
		void view();
		void delrec();
		string currentDay();
		string currentMonthYear();
		void editTimeTable(char id[45],int day,string monthyear);
		
	
//char HOST[] = "localhost";
//char USER[] = "root";
//char PASS[] = "Erena741";
	private:
		
		int age;
        string gender,department;
        char id[45];
        char name[40];
        char phoneNumber[40];
	 string dummy;
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
};

#endif
