#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <sstream>
#include <stdio.h>
#include "manager.h"
#include "doctor.h"
#include "patient.h"
#include "nurse.h"

using namespace std;

const char HOST[] = "localhost";
const char USER[] = "root";
const char PASS[] = "123456";
void manager::addman(){
	
	conn = mysql_init(0);
	conn = mysql_real_connect(conn,HOST, USER, PASS, "hms", 3306, NULL, 0);
    if(conn){
        int qstate = 0;
        
        cout << "Enter username : ";
        cin >> username;
        
        cout << "Enter password : ";
        cin >> password;

        stringstream ss;
        ss << "INSERT INTO manager(username,password) VALUES('"<<username << "','" << password <<"')";

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

    
    system("cls");
}
void manager::editman(){
    
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,HOST, USER, PASS, "hms", 3306, NULL, 0);
    if(conn){
        int qstate = 0;
        string username,password;

        cout << "Enter username : ";
        cin >> username;
        
        cout << "Enter password : ";
        cin >> password;

        stringstream ss;
        ss<<"UPDATE `hms`.`manager` SET `username` = '"<<username<<"', `password` = '"<<password<<"' where username=('"<<username<<"')";
        
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
void manager::findman(){
	
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, HOST, USER, PASS, "hms", 3306, NULL, 0);

    if(conn){
        string username;
        
        cout << "Enter username : ";
        cin >> username;
            stringstream ss;
            ss<<"SELECT * FROM manager where username ='"+username+"'";
            string query = ss.str();
			const char* q = query.c_str();
			mysql_query(conn,q);
            
            	res=mysql_store_result(conn);
            	
            	while(row = mysql_fetch_row(res)){
        	
		
                cout << row[0] <<"\t | \t" << row[1] <<"\t | \t"<<endl;
       }
    }
    cout << "Press B to go back";
    cin >> dummy;

    system("pause");
    system("cls");
}
void manager::viewman(){
	
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,HOST, USER, PASS, "hms", 3306, NULL, 0);
    if(conn){
    	
        int qstate = mysql_query(conn, "SELECT  username, password FROM manager ");

        if(!qstate){
            res = mysql_store_result(conn);

            while(row = mysql_fetch_row(res)){
                cout << row[0] <<"\t | \t" << row[1] <<"\t | \t" << endl << endl;
             }
        }
    }

    cout << "Press B to go back";
    cin >> dummy;

    system("pause");
    system("cls");
}
void manager::delman(){
	
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, HOST, USER, PASS, "hms", 3306, NULL, 0);
	
	if(conn){
		int qstate=0;
        string username;
        
        cout << "Enter username : ";
        cin >> username;
        
            stringstream ss;
            ss<<"DELETE FROM manager WHERE username='"<<username<<"' ";
            
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


