#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <sstream>
#include <stdio.h>
#include "doctor.h"
#include "manager.h"
#include "surgery.h"
#include "patient.h"
#include "nurse.h"

using namespace std;

const char HOST[] = "localhost";
const char USER[] = "root";
const char PASS[] = "123456";
		
void patient::addPatient(){
   
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,HOST, USER, PASS, "hms", 3306, NULL, 0);
    if(conn){
        int qstate = 0;
		
	 
		cout << "Enter patient username : ";
        cin >> patientUsername;
        
        cout << "Enter patient password : ";
        cin >> patientPassword;
        
        cout << "Enter patient identity: ";
        cin>>patientId;
        
        cout << "Enter patient name and surname : ";
        cin>>patientName;
        
        cout << "Enter patient gender: ";
        cin >> patientGender;
        
        cout << "Enter patient age : ";
        cin >> patientAge;
        
        cout << "Enter patient disease: ";
        cin >> patientDisease;
        
        cout << "Enter patient phone number : ";
        cin >> patientPhone;

        stringstream ss;
        ss << "INSERT INTO patients(patientUsername, patientPassword,patientId, patientName, patientGender,patientAge, patientDisease, patientPhone) VALUES('"<< patientUsername<<"','"<< patientPassword << "','" << patientId<<"','"<< patientName << "','" << patientGender<<"',"<<patientAge<<",'"<<patientDisease<<"','"<<patientPhone<<"'"<<")";

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

void patient::editPatient(){
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,HOST, USER, PASS, "hms", 3306, NULL, 0);
    if(conn){
        int qstate = 0;
        
		cout << "Enter patient identity : ";
        cin>>patientId;
        
		cout << "Enter patient username : ";
        cin >> patientUsername;
        
        cout << "Enter patient password : ";
        cin >> patientPassword;

        cout << "Enter patient name and surname : ";
        cin>>patientName;
        
        cout << "Enter patient gender: ";
        cin >> patientGender;
        
        cout << "Enter patient age : ";
        cin >> patientAge;
        
        cout << "Enter patient disease: ";
        cin >> patientDisease;
        
        cout << "Enter patient phone number : ";
        cin >> patientPhone;

        stringstream ss;
        ss<<"UPDATE `hms`.`patients` SET `patientUsername` = '"<<patientUsername<<"', `patientPassword` = '"<<patientPassword<<"', `patientName` = '"<<patientName<<"', `patientGender` = '"<<patientGender<<"', `patientAge` = "<<patientAge<<", `patientDisease` ='"<<patientDisease<<"', `patientPhone` ='"<<patientPhone<<"'"<<" WHERE (`patientId` = '"<<patientId<<"'"<<")";
        
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

void patient::findPatient(){
	
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, HOST, USER, PASS, "hms", 3306, NULL, 0);

    if(conn){
        string patientId;
        
        cout << "Enter id : ";
        cin >> patientId;
            stringstream ss;
            ss<<"SELECT * FROM patients where patientId ='"+patientId+"'";
            string query = ss.str();
			const char* q = query.c_str();
			mysql_query(conn,q);
            
            	res=mysql_store_result(conn);
            	
            	while(row = mysql_fetch_row(res)){
        	
		
                cout << row[0] <<"\t | \t" << row[1] <<"\t | \t" << row[2] <<"\t | \t" << row[3] <<"\t | \t" << row[4]<<"\t | \t" << row[5] <<"\t | \t" << row[6] <<"\t | \t" << row[7] <<endl;
       }
    }
    cout << "Press B to go back";
    cin >> dummy;

    system("pause");
    system("cls");
}

void patient::viewPatient(){
	
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,HOST, USER, PASS, "hms", 3306, NULL, 0);
    if(conn){
    	
        int qstate = mysql_query(conn, "SELECT  patientUsername, patientPassword,patientId, patientName, patientGender,patientAge, patientDisease, patientPhone FROM patients ");

        if(!qstate){
            res = mysql_store_result(conn);

            while(row = mysql_fetch_row(res)){
                cout << row[0] <<"\t | \t" << row[1] <<"\t | \t" << row[2] <<"\t | \t" << row[3] <<"\t | \t" << row[4]<<"\t | \t" << row[5] <<"\t | \t" << row[6] <<"\t | \t" << row[7] << endl;
             }
        }
    }

    cout << "Press B to go back";
    cin >> dummy;

    system("pause");
    system("cls");
}

void patient::delPatient(){
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, HOST, USER, PASS, "hms", 3306, NULL, 0);
	
	if(conn){
		int qstate=0;
        string id;
        
        cout << "Enter patient identity : ";
        cin >> patientId;
            stringstream ss;
            ss<<"DELETE FROM `patients` WHERE patientId=\""<<patientId<<"\"";
            
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
