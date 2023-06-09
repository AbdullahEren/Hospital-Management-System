#ifndef MANAGER_H
#define MANAGER _H
#include <iostream>
#include <mysql.h>

using namespace std;

class manager{
	public:
	
		void addman();
		void editman();
		void findman();
		void viewman();
		void delman();

	private:
	
	string username,password;
    string dummy;
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
};

#endif
