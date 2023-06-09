#include <iostream>
#include <string>
#include<random>
#include<cstdlib>
#include <windows.h>
#include <mysql.h>
#include <sstream>
#include <stdio.h>
#include "doctor.h"
#include "manager.h"
#include "surgery.h"
#include "patient.h"
#include "patient.h"
#include "nurse.h"
#include <numeric>
#include <ctime>  
 #include <algorithm>

using namespace std;

const char HOST[] = "localhost";
const char USER[] = "root";
const char PASS[] = "123456";

	
void nurse::editTimeTableNurse(){
	//,9,10,11,13,14,15,16,17
   
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,HOST, USER, PASS, "hms", 3306, NULL, 0);
    if(conn){
        int qstate = 0;
        cout<<"Enter the nurse Id:";
        cin>>nurseId;
        stringstream ss;
        ss << "INSERT INTO timetablenurse(nurseId) VALUES("<<"'" << nurseId<<"'"<<")";

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
void nurse::updatetimetablenurse(int l,string nurseIds[],int nurseSchedule[][14]){
   	conn = mysql_init(0);
    conn = mysql_real_connect(conn,HOST, USER, PASS, "hms", 3306, NULL, 0);
    if(conn){ 
        int qstate = 0;        
        stringstream ss;
        ss<<"UPDATE `hms`.`timetablenurse` SET `mondayMorning` = "<<nurseSchedule[l][0]<<",`mondayNight` = "<<nurseSchedule[l][1]<<",`tuesdayMorning` = "<<nurseSchedule[l][2]<<",`tuesdayNight` = "<<nurseSchedule[l][3]<<",`wednesdayMorning` = "<<nurseSchedule[l][4]<<",`wednesdayNight` = "<<nurseSchedule[l][5]<<",`thursdayMorning` = "<<nurseSchedule[l][6]<<",`thursdayNight` = "<<nurseSchedule[l][7]<<",`fridayMorning` = "<<nurseSchedule[l][8]<<",`fridayNight` = "<<nurseSchedule[l][9]<<",`saturdayMorning` = "<<nurseSchedule[l][10]<<",`saturdayNight` = "<<nurseSchedule[l][11]<<",`sundayMorning` = "<<nurseSchedule[l][12]<<",`sundayNight` = "<<nurseSchedule[l][13]<<" WHERE (`nurseId`='"<<nurseIds[l]<<"'"<<")";
        
		string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0){
            cout << "Record Updated..." << endl;
        }else{
            cout << "Insert Error" << mysql_error(conn) << endl;
        }
    }else{
        cout << "Connection Error" << endl;
    }
	}	
	
void nurse::addNur(){
   
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,HOST, USER, PASS, "hms", 3306, NULL, 0);
    if(conn){
        int qstate = 0;
		

		cout << "Enter nurse ýd : ";
        cin >> nurseId;
        
        cout << "Enter nurse name : ";
        cin >> nurseName;
        
        cout << "Enter nurse department : ";
        cin >> nurseDepartment;
        
        cout << "Enter nurse Patient: ";
        cin >> nursesPatient;
        
        stringstream ss;
        ss << "INSERT INTO nurse(nurseId, nurseName, nurseDepartment, nursesPatient) VALUES('" << nurseId<<"','"<<nurseName << "','" << nurseDepartment <<"','" << nursesPatient <<"'"<< ")";

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

void nurse::editNur(){
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,HOST, USER, PASS, "hms", 3306, NULL, 0);
    if(conn){
        int qstate = 0;
        
		cout << "Enter nurse group : ";
        cin >> nurseId;
        
        cout << "Enter nurse name : ";
        cin>>nurseName;
        
        cout << "Enter nurse department : ";
        cin >> nurseDepartment;
    
        stringstream ss;
        ss<<"UPDATE `hms`.`nurse` SET `nurseId` = '"<<nurseId<<"', `nurseName` = '"<<nurseName<<"', `nurseDepratment` = "<<nurseDepartment<<" WHERE (`nurseId` = '"<<nurseId<<"'"<<")";
        
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

void nurse::findNur(){
	
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, HOST, USER, PASS, "hms", 3306, NULL, 0);

    if(conn){       
        cout << "Enter nurse id : ";
        cin >> nurseId;
            stringstream ss;
            ss<<"SELECT * FROM nurse where nurseId ='"<<nurseId<<"'";
            string query = ss.str();
			const char* q = query.c_str();
			mysql_query(conn,q);
            
            	res=mysql_store_result(conn);
            	
            	while(row = mysql_fetch_row(res)){
        	
		
                cout << row[0] <<"\t | \t" << row[1] <<"\t | \t" << row[2] <<"\t | \t" << row[3]<<endl;
       }
    }
    cout << "Press B to go back";
    cin >> dummy;

    system("pause");
    system("cls");
}

void nurse::viewNur(){
	
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,HOST, USER, PASS, "hms", 3306, NULL, 0);
    if(conn){
    	
        int qstate = mysql_query(conn, "SELECT nurseId, nusreName, nurseDepartment, nursesPatient, nurseAvailibility FROM nurse ");

        if(!qstate){
            res = mysql_store_result(conn);

            while(row = mysql_fetch_row(res)){
                cout << row[0] <<"\t | \t" << row[1] <<"\t | \t" << row[2] <<"\t | \t" << row[3] <<"\t | \t" << row[4] << endl << endl;
             }
        }
    }

    cout << "Press B to go back";
    cin >> dummy;

    system("pause");
    system("cls");
}

void nurse::delNur(){
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, HOST, USER, PASS, "hms", 3306, NULL, 0);
	
	if(conn){
		int qstate=0;
        string id;
        
        cout << "Enter nurse group : ";
        cin >> nurseId;
            stringstream ss;
            ss<<"DELETE FROM `nurse` WHERE nurseId=\""<<nurseId<<"\"";
            
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
