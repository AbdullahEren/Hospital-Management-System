#include <iostream>
#include <string>
#include <windows.h>
#include <mysql.h>
#include <sstream>
#include <stdio.h>
#include "doctor.h"
#include "manager.h"
#include "surgery.h"
#include "patient.h"
#include "nurse.h"
#include "time.h"
#include <cstdlib>
using namespace std;

const char HOST[] = "localhost";
const char USER[] = "root";
const char PASS[] = "123456";

string doctor::currentDay() {
    time_t     now = time(0);
    struct tm  tstruct;    
    char       day[80];   
    tstruct = *localtime(&now);  
    strftime(day, sizeof(day), "%d", &tstruct);
    return day;
}		
string doctor::currentMonthYear() {
    time_t     now = time(0);
    struct tm  tstruct;    
    char       monthyear[80];   
    tstruct = *localtime(&now);  
    strftime(monthyear, sizeof(monthyear), "%m-%Y", &tstruct);
    return monthyear;
}

void doctor::addrec(){
   
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,HOST, USER, PASS, "hms", 3306, NULL, 0);
    if(conn){
        int qstate = 0;
		

		cout << "Enter id : ";
        cin >> id;
        
        cout << "Enter name : ";
        cin>>name;
        
        cout << "Enter gender : ";
        cin >> gender;

        cout << "Enter age : ";
        cin >> age;

        cout << "Enter department: ";
        cin >> department;
        
        cout << "Enter phone number : ";
        cin >> phoneNumber;

        stringstream ss;
        ss << "INSERT INTO doctors(id,name, gender, age,department,phoneNumber) VALUES('" << id<<"','"<<name << "','" << gender << "'," << age <<",'"<<department<<"','"<<phoneNumber<<"'"<<")";

        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0){
            cout << "Record Inserted..." << endl;
            ss.clear();
            string day1=currentDay();
            int day ;
  		    stringstream sss;
  		    sss.str(day1);
   			sss >> day;
			string monthyear=currentMonthYear();
            for(int i=0; i<7;i++) {
    			editTimeTable(id, day,monthyear);
				day++;
			}
            cout << "Press B to go back";
            cin >> dummy;
        }else{
            cout << "Insert Error" << mysql_error(conn) << endl;
            cout << "Press B to go back";
            cin >> dummy;
        }
    }else{
        cout << "Connection Error" << endl;
        cout << "Press B to go back";
        cin >> dummy;
    }

    system("pause");
    system("cls");

}

void doctor::editrec(){
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,HOST, USER, PASS, "hms", 3306, NULL, 0);
    if(conn){
        int qstate = 0;

        cout << "Enter id : ";
        cin >> id;
        
        cout << "Enter name : ";
        cin >> name;
        
        cout << "Enter gender : ";
        cin >> gender;

        cout << "Enter age : ";
        cin >> age;

        cout << "Enter department: ";
        cin >> department;
        
        cout << "Enter phone number : ";
        cin >> phoneNumber;

        stringstream ss;
        ss<<"UPDATE `hms`.`doctors` SET `name` = '"<<name<<"', `gender` = '"<<gender<<"', `age` = "<<age<<", `department` = '"<<department<<"', `phoneNumber` = "<<phoneNumber<<" WHERE (`id` = '"<<id<<"'"<<")";
        
		string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        
        if(qstate == 0){
            cout << "Record Updated..." << endl;
            cout << "Press B to go back";
            cin >> dummy;
        }else{
            cout << "Insert Error" << mysql_error(conn) << endl;
            cout << "Press B to go back";
            cin >> dummy;
        }
    }else{
        cout << "Connection Error" << endl;
        cout << "Press B to go back";
        cin >> dummy;
    }

    system("pause");
    system("cls");

}

void doctor::findmed(){
	
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, HOST, USER, PASS, "hms", 3306, NULL, 0);

    if(conn){
        string id;
        
        cout << "Enter id : ";
        cin >> id;
            stringstream ss;
            ss<<"SELECT * FROM doctors where id ='"+id+"'";
            string query = ss.str();
			const char* q = query.c_str();
			mysql_query(conn,q);
            
            	res=mysql_store_result(conn);
            	
            	while(row = mysql_fetch_row(res)){
        	
		
                cout << row[0] <<"\t | \t" << row[1] <<"\t | \t" << row[2] <<"\t | \t" << row[3] <<"\t | \t" << row[4]<<"\t | \t" << row[5] <<endl;
       }
    }
    cout << "Press B to go back";
    cin >> dummy;

    system("pause");
    system("cls");
}

void doctor::view(){
	conn = mysql_init(0);
    conn = mysql_real_connect(conn,HOST, USER, PASS, "hms", 3306, NULL, 0);
    if(conn){
    	
        int qstate = mysql_query(conn, "SELECT  id,name, gender, age, department,phoneNumber FROM doctors ");
        int rowNumber = 1;
        if(!qstate){
            res = mysql_store_result(conn);

            while(row = mysql_fetch_row(res)){
                cout << rowNumber << ". " << row[4] << " doctor - " << row[1] << "ID - " << row[0] << endl;
                rowNumber++;
             }
        }
    }
}

void doctor::viewDetails(){
	
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,HOST, USER, PASS, "hms", 3306, NULL, 0);
    if(conn){
    	
        int qstate = mysql_query(conn, "SELECT  id,name, gender, age, department,phoneNumber FROM doctors ");

        if(!qstate){
            res = mysql_store_result(conn);

            while(row = mysql_fetch_row(res)){
                cout << row[0] <<"\t | \t" << row[1] <<"\t | \t" << row[2] <<"\t | \t" << row[3] <<"\t | \t" << row[4] <<"\t | \t" << row[5] << endl << endl;
             }
        }
    }

    cout << "Press B to go back";
    cin >> dummy;

    system("pause");
    system("cls");
}

void doctor::delrec(){
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, HOST, USER, PASS, "hms", 3306, NULL, 0);
	
	if(conn){
		int qstate=0;
        string id;
        
        cout << "Enter id : ";
        cin >> id;
            stringstream ss;
            ss<<"DELETE FROM `doctors` WHERE id=\""<<id<<"\"";
            
            string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        
        if(qstate == 0){
            cout << "Record Deleted..." << endl;
            cout << "Press B to go back";
            cin >> dummy;
        }else{
            cout << "Insert Error" << mysql_error(conn) << endl;
            cout << "Press B to go back";
            cin >> dummy;
        }
    }else{
        cout << "Connection Error" << endl;
        cout << "Press B to go back";
        cin >> dummy;
    }
}


void doctor::editTimeTable(char id[45], int day,string monthyear){
	//,9,10,11,13,14,15,16,17
   
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,HOST, USER, PASS, "hms", 3306, NULL, 0);
    if(conn){
        int qstate = 0;
        string empty="empty";
        stringstream ss;
        ss << "INSERT INTO timetabledoctor(DoctorId, date) VALUES("<<"'" << id<<"','"<<day<<"-"<<monthyear<<"'"<</*,'"<<empty<<"','"<<empty<<"','"<<empty<<"','"<<empty<<"','"<<empty<<"','"<<empty<<"','"<<empty<<"','"<<empty<<"'"<<*/")";

        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0){
            cout << "Record Inserted..." << endl;
            cout << "Press B to go back";
            cin >> dummy;
        }else{
            cout << "Insert Error" << mysql_error(conn) << endl;
            cout << "Press B to go back";
            cin >> dummy;
        }
    }else{
        cout << "Connection Error" << endl;
        cout << "Press B to go back";
        cin >> dummy;
    }

    system("pause");
    system("cls");

}

