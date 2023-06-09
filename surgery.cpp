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
		
void surgery::addSur(){
   
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,HOST, USER, PASS, "hms", 3306, NULL, 0);
    if(conn){
        int qstate = 0;
		

		cout << "Enter number of surgery : ";
        cin >> surgeryNum;
        
        cout << "Enter department of surgery : ";
        cin >> surgeryDepartment;
        
        cout << "Enter availibility of surgery : ";
        cin >> surgeryAvailibility;
        
        cout << "Enter doctor's ID  : ";
        cin >> surgeryDoctorid;
        
        stringstream ss;
        ss << "INSERT INTO surgery(surgeryNum, surgeryDepartment,surgeryAvailibility,surgeryDoctorid) VALUES(" << surgeryNum<<",'" << surgeryDepartment <<"','" << surgeryAvailibility<<"','" << surgeryDoctorid<<"')";

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

void surgery::editSur(){
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,HOST, USER, PASS, "hms", 3306, NULL, 0);
    if(conn){
        int qstate = 0;

       	cout << "Enter number of surgery : ";
        cin >> surgeryNum;
        
        cout << "Enter department of surgery : ";
        cin >> surgeryDepartment;
        
        cout << "Enter availibility of surgery : ";
        cin >> surgeryAvailibility;
        
        cout << "Enter doctor's ID: ";
        cin >> surgeryDoctorid;
        
        stringstream ss;
        ss<<"UPDATE `hms`.`surgery` SET `surgeryNum` = "<< surgeryNum <<", `surgeryDepartment` = '"<<surgeryDepartment<<"',`surgeryAvailibility`='"<<surgeryAvailibility<<"',`surgeryDoctorid`='"<<surgeryDoctorid<<"' WHERE (`surgeryNum` = "<<surgeryNum<<")";
        
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

void surgery::findSur(){
	
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, HOST, USER, PASS, "hms", 3306, NULL, 0);

    if(conn){
        string surgeryNum;
        
        cout << "Enter surgery number : ";
        cin >> surgeryNum;
            stringstream ss;
            ss<<"SELECT * FROM surgery where surgeryNum ='"+surgeryNum+"'";
            string query = ss.str();
			const char* q = query.c_str();
			mysql_query(conn,q);
            
            	res=mysql_store_result(conn);
            	
            	while(row = mysql_fetch_row(res)){
        	
		
                cout << row[0] <<"\t | \t" << row[1] <<"\t | \t" << row[2] <<"\t | \t" << row[3] <<endl;
       }
    }
    cout << "Press B to go back";
    cin >> dummy;

    system("pause");
    system("cls");
}

void surgery::viewSur(){
	
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,HOST, USER, PASS, "hms", 3306, NULL, 0);
    if(conn){
    	
        int qstate = mysql_query(conn, "SELECT  surgeryNum,surgeryDepartment,surgeryAvailibility,surgeryDoctorid FROM surgery ");

        if(!qstate){
            res = mysql_store_result(conn);

            while(row = mysql_fetch_row(res)){
                cout << row[0] <<"\t | \t" << row[1]<<"\t | \t" << row[2] <<"\t | \t" << row[3] << endl << endl;
             }
        }
    }

    cout << "Press B to go back";
    cin >> dummy;

    system("pause");
    system("cls");
}

void surgery::delSur(){
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, HOST, USER, PASS, "hms", 3306, NULL, 0);
	
	if(conn){
		int qstate=0;
        string surgeryNum;
        
        cout << "Enter surgery number : ";
        cin >> surgeryNum;
            stringstream ss;
            ss<<"DELETE FROM `surgery` WHERE surgeryNum=\""<<surgeryNum<<"\"";
            
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


		
/*		
		
void surgery::addMedicines(){
   
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,HOST, USER, PASS, "hms", 3306, NULL, 0);
    if(conn){
        int qstate = 0;
		

		cout << "Enter medicine name: ";
        cin >> medicineName;
        
        cout << "Enter medicine price : ";
        cin >> medicinePrice;
        
        stringstream ss;
        ss << "INSERT INTO surgery(medicineName, medicinePrice) VALUES(" << medicineName<<",'" << medicinePrice <<"')";

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

void surgery::findMedicines(){
	
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, HOST, USER, PASS, "hms", 3306, NULL, 0);

    if(conn){
        
        cout << "Enter medicine name : ";
        cin >> medicineName;
            stringstream ss;
            ss<<"SELECT * FROM surgery where medicineName ='"+medicineName+"'";
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

void surgery::viewMedicines(){
	
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,HOST, USER, PASS, "hms", 3306, NULL, 0);
    if(conn){
    	
        int qstate = mysql_query(conn, "SELECT  medicineName, medicinePrice FROM surgery ");

        if(!qstate){
            res = mysql_store_result(conn);

            while(row = mysql_fetch_row(res)){
                cout << row[0] <<"\t | \t" << row[1]<<"\t | \t" << row[2] <<"\t | \t" << row[3] << endl << endl;
             }
        }
    }

    cout << "Press B to go back";
    cin >> dummy;

    system("pause");
    system("cls");
}

void surgery::delMedicines(){
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, HOST, USER, PASS, "hms", 3306, NULL, 0);
	
	if(conn){
		int qstate=0;
        
        cout << "Enter medicine name : ";
        cin >> medicineName;
            stringstream ss;
            ss<<"DELETE FROM `surgery` WHERE medicineName=\""<<medicineName<<"\"";
            
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
}*/


