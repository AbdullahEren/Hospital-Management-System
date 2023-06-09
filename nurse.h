#ifndef NURSE_H
#define NURSE_H
#include <iostream>
#include <mysql.h>

using namespace std;

class nurse{
	public:
  		int calculateFitness(int schedule[]);
  		void crossover(int schedule1[], int schedule2[], int newSchedule[]);
  		void mutate(int schedule[]);
  		
  		void editTimeTableNurse();
  		void updatetimetablenurse(int l,string nurseIds[],int nurseSchedule[][14]);
		void addNur();
		void editNur();
		void findNur();
		void viewNur();
		void delNur();
		int selectNurse();
		
//char HOST[] = "localhost";
//char USER[] = "root";
//char PASS[] = "Erena741";
	private:
		
        char nurseId[40];
        char nurseName[45];
        char nurseDepartment[45];
        char nursesPatient[45]; 
        char nurseAvailibility[45];
	string dummy;
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
};

#endif
