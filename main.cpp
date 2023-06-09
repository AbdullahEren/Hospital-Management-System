#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <sstream>
#include <stdio.h>
#include "doctor.h"
#include "manager.h"
#include "surgery.h"
#include "patient.h"
#include "schedule.h"
#include <stdio.h>
#include <time.h>
#include "nurse.h"
#include <cstdlib>
#include<ctime>
#include <algorithm>
#include<locale.h>
using namespace std;



const char HOST[] = "localhost";
const char USER[] = "root";
const char PASS[] = "123456";
string dummy;
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;


int nursegenetic();
bool dbconn();
int login();
int patientLogin();
void setSurgery(string department);
void chooseDepartment();
void viewDoctor(string department);
void chooseSurgeryNum(string department);
void updateSurgery(char id[40],string department,int surgeryNum);
//void updatetimetabledoctor(char id[40],int day,int month,int year,int appointmentTime);
string currentDate();
string currentTime();

manager manager;
doctor doctor;
surgery surgery;
patient patient;
nurse nurse;

int runforever = 1;
int chooseRoleAnswer;
	
int	chooseRole(){
  int ans;
  cout << endl << endl << "---------------" << endl << endl << "1.Manager" << endl << "2.Patient / Guest"<< endl<<"-------------"<<endl;
  cout << endl << "Your Answer : ";
  cin >> ans;
  return ans;
}

int managerMenu() {
  int ans;
  cout << endl << endl << "---------------" << endl << endl << "1. Add Manager" << endl << "2. Edit Manager Record" << endl << "3. Find Manager" << endl << "4. View Managers" << endl << "5. Delete Manager" << endl <<"6.End"<< endl << endl << "---------------" << endl;
  cout << endl << "Your Answer : ";
  cin >> ans;
  switch(ans){
    case 1:
      manager.addman();
      break;
    case 2:
      manager.editman();
      break;
    case 3:
      manager.findman();
      break;
    case 4:
      manager.viewman();
      break;
    case 5:
      manager.delman();
      break;
    default:
      break;    		
    }
}

int doctorMenu() {
  int ans;
  cout << endl << endl << "---------------" << endl << endl << "1. Add Doctor" << endl << "2. Edit Doctor Record" << endl << "3. Find Doctor" << endl << "4. View Doctors" << endl << "5. Delete Doctors" << endl <<"6.End"<< endl << endl << "---------------" << endl;
  cout << endl << "Your Answer : ";
	cin >> ans;
  switch(ans){
    case 1:
      doctor.addrec();
     // doctor.editTimeTable();
      break;
    case 2:
      doctor.editrec();
      break;
    case 3:
      doctor.findmed();
      break;
    case 4:
      doctor.view();
      break;
    case 5:	
      doctor.delrec();
      break;
    default:
  		break;
  }
}

int surgeryMenu() {
  int ans;
  cout << endl << endl << "---------------" << endl << endl << "1. Add surgery number" << endl << "2. Edit surgery information" << endl << "3. Find surgery department" << endl << "4. View surgery " << endl << "5. Delete surgery" << endl <<"6.End"<< endl << endl << "---------------" << endl;
  cout << endl << "Your Answer : ";
  cin >> ans;
  switch(ans){ 
    case 1:
      surgery.addSur();
      break;
    case 2:
      surgery.editSur();
      break;
    case 3:
      surgery.findSur();
      break;
    case 4:
      surgery.viewSur();
      break;
    case 5:
      surgery.delSur();
      break;
  	default:
  		break;    		
  }
}

int patientMenu() {
  int ans;
  cout << endl << endl << "---------------" << endl << endl << "1. Add patient" << endl << "2. Edit patients" << endl << "3. Find patient" << endl << "4. View patients " << endl << "5. Delete patient" << endl <<"6.End"<< endl << endl << "---------------" << endl;
  cout << endl << "Your Answer : ";
  cin >> ans;
  switch(ans){
    case 1:
      patient.addPatient();
      break;
    case 2:
      patient.editPatient();
      break;
    case 3:
      patient.findPatient();
      break;
    case 4:
      patient.viewPatient();
      break;
    case 5:
      patient.delPatient();
      break;
    default:
      break;    		
  }
}

int nurseMenu(){
  int ans;
  cout << endl << endl << "---------------" << endl << endl << "1. Add nurse" << endl << "2. Edit nurse" << endl << "3. Find nurse" << endl << "4. View nurse " << endl << "5. Delete nurse" << endl<< "6. add nurse time table" <<endl <<"7.update nurse time table with genetic algorithm"<< endl <<"8.End"<<endl<< endl << "---------------" << endl;
  cout << endl << "Your Answer : ";
  cin >> ans;
  switch(ans){
    case 1:
      nurse.addNur();
      break;
    case 2:
      nurse.editNur();
      break;
    case 3:
      nurse.findNur();
      break;
    case 4:
      nurse.viewNur();
      break;
    case 5:
      nurse.delNur();
      break;
    case 6:
    	nurse.editTimeTableNurse();
      	break;
    case 7:
      	nursegenetic();
      	break;
    default:
      break;    		
  }
}


int mainManagerMenu() {
  if(login()==1){
    int ans;
    while(runforever=1){
    	cout << endl << endl << "---------------" << endl << endl << "1.Manager" << endl << "2.Doctor"<< endl<< "3.Surgery"<< endl <<"4.Patient"<<endl <<"5.Nurse"<<endl <<"-------------"<<endl;
      cout << endl << "Your Answer : ";
      cin >> ans;
      switch(ans){
        case 1:
        	managerMenu();
        	break;
        case 2:
			doctorMenu();
        	break;
        case 3:
          surgeryMenu();
          break;
        case 4:
          patientMenu();
          break;
        case 5 :
        	nurseMenu();
        	break;
        default:
        	break;
      }
	}
  }
}

int setAppointment(){
	int doctor, month, year;
	string doctorName, time, day;
	
	conn = mysql_init(0);
	conn = mysql_real_connect(conn,HOST, USER, PASS, "hms", 3306, NULL, 0);
    if(conn){
        int qstate = 0;
      
		cout <<"Select doctor: ";
		cin >> doctor;
		cout << "Enter day (DD): ";
		cin >> day;
		cout << "Enter month (MM): ";
		cin >> month;
		cout << "Enter year (YYYY): ";
		cin >> year;
		cout << "Enter time (00): ";
		cin >> time;
        stringstream ss;
        ss << "INSERT INTO timetabledoctor(DoctorId, doctorName, date, 9) VALUES('"<< doctor<< "','" << doctorName << "','" << day <<"','"<<time<<"'"<<")";
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
}

int mainPatientMenu() {
  int ans;
  if (patientLogin()==1) {
    cout << endl << endl << "---------------" << endl << endl << "1.View Doctors list" << endl << "2.View Surgery list"<< endl<< "3.View nurse list" << endl <<"4.End"<<endl<<endl<<"-------------"<<endl;
    cout << endl << "Your Answer : ";
    cin >> ans;
    switch(ans){
    case 1:
      doctor.view();
     /*char id[40];
     int day ,month ,year,appointmentTime;
     cout <<"Select doctor: ";
		cin >> id;
		cout << "Enter day (DD): ";
		cin >> day;
		cout << "Enter month (MM): ";
		cin >> month;
		cout << "Enter year (YYYY): ";
		cin >> year;
		cout << "Enter time (00): ";
		cin >> appointmentTime;
	 updatetimetabledoctor(id,day,month,year,appointmentTime);*/
      break;
    case 2:
      surgery.viewSur();
      break;
      
    case 3:
	  nurse.viewNur(); 
      break;
   	case 4:
      if (runforever=1){
          runforever=0;	
      }	
      break;
	   default:
      break;
    }
   
  }
}


int main() { 
setlocale(LC_ALL, "Turkish");   
	cout<< currentDate();  
	cout<< "\n"+currentTime();
	while(runforever = 1) {
   	chooseRoleAnswer = chooseRole();
   	switch(chooseRoleAnswer){
   		case 1:
        mainManagerMenu();
        break;
			case 2:
      	mainPatientMenu();
      	break; 
    }
  }	
}
int calculateFitness(int schedule[],int nurses,int nurseSchedule[][14]) {
	Schedule bestNurse;
  
  int fitness = 0;
  int bestFitness=0;
  int scheduleSum=0,scheduleSum2=0;
  for (int i = 0; i < Shifts; i++) {
  	
  	scheduleSum+=schedule[i];
  	if(scheduleSum<=4){
  		fitness =fitness + schedule[i]+2;
	  }
	  int k=i-1;
	  if(schedule[k]==1 && schedule[i]==0){
	  	fitness=fitness+1;
	  }
	  if(schedule[k]==0 && schedule[i]==1){
	  	fitness=fitness+1;
	  }
	  
	scheduleSum2=schedule[i];
	for(int l=0;l<nurses;l++){
	  	scheduleSum2=scheduleSum2+nurseSchedule[l][i];	  
	  	
	if(i<10){
	
	if(scheduleSum2<=4){
	  		fitness=fitness+1;
	  		
	if (fitness > bestFitness) 
	  {    
   	   bestFitness = fitness;
	  }
   }
}
else if(i>=10){

	  	if(scheduleSum2<=2){
	  		fitness=fitness+1;
	  		
		  if (fitness > bestFitness) {    
   	 	  	bestFitness = fitness;
	 	  }
	   }
	 } 
  }
}

	if(bestFitness==0){
		return fitness;
	}else{
		return bestFitness;
	}  
  
}

void crossover(int schedule1[], int schedule2[], int newSchedule[]) {
  int crossoverPoint = rand() % Shifts;
  for (int i = 0; i < Shifts; i++) {
    if (i < crossoverPoint) {
      newSchedule[i] = schedule1[i];
    } else {
      newSchedule[i] = schedule2[i];
    }
  }
}
void mutate(int schedule[]) {
  int mutationPoint = rand() % Shifts;  
  schedule[mutationPoint] = !schedule[mutationPoint];  
}
int nursegenetic(){
	conn = mysql_init(0);
	conn = mysql_real_connect(conn,"localhost","root","123456","hms",3306,NULL,0);	
	srand(time(0));
	Schedule bestNurse;
	string nurseIds[100];
	
	stringstream ss;
		ss<<"SELECT * FROM nurse";
		string query = ss.str();
		const char* q = query.c_str();
		mysql_query(conn,q);
			res = mysql_store_result(conn);
			int nurses=0;
			while(row = mysql_fetch_row(res))
			{	
				nurseIds[nurses]=row[0];
				nurses++;
			}
			
			for(int j=0;j<nurses;j++){
				cout<<"\n"<<nurseIds[j];
			}
			int nurseSchedule[nurses][14];
			
			for(int l=0;l<nurses;l++){
			

  Schedule population[PopulationSize];
  for (int i = 0; i < PopulationSize; i++) {
    
    population[i].fitness = calculateFitness(population[i].schedule,nurses,nurseSchedule);
  

  }
 
  for (int i = 0; i < Generations; i++) {
 
    Schedule newPopulation[PopulationSize];

    Schedule parent1 = population[rand() % PopulationSize];
    
    Schedule parent2 = population[rand() % PopulationSize];

    Schedule child;
  	crossover(parent1.schedule, parent2.schedule, child.schedule);

  
    if (rand() < MutationRate * RAND_MAX) {
      mutate(child.schedule);
    }
    
    newPopulation[0] = child;
    newPopulation[0].fitness = calculateFitness(child.schedule,nurses,nurseSchedule);
   
    for (int j = 1; j < PopulationSize; j++) {
    	
      newPopulation[j] = population[j];
    }
    
    for (int j = 0; j < PopulationSize; j++) {
      population[j] = newPopulation[j];
      
    }
}

int bestFitness = 0;
for (int i = 0; i < PopulationSize; i++) {
    if (population[i].fitness > bestFitness) {
      bestNurse = population[i];
      bestFitness = population[i].fitness;
    }
}

  cout << "\nBest schedule: ";
  for (int i = 0; i < Shifts; i++){
    cout << bestNurse.schedule[i] << " ";
	nurseSchedule[l][i]=bestNurse.schedule[i];
  }
  cout << endl;
 
	 nurse.updatetimetablenurse(l,nurseIds,nurseSchedule);					
	} 
}

void viewDoctor(string department){
	conn = mysql_init(0);
    conn = mysql_real_connect(conn,HOST, USER, PASS, "hms", 3306, NULL, 0);
    if(conn){
    	
        stringstream ss;
            ss<<"SELECT * FROM doctors where department ='"+department+"'";
            string query = ss.str();
			const char* q = query.c_str();
			mysql_query(conn,q);
            
            	res=mysql_store_result(conn);
            	
            	while(row = mysql_fetch_row(res)){
        	
		
                cout << row[0] <<"\t | \t" << row[1] <<"\t | \t" << row[2] <<"\t | \t" << row[3] <<"\t | \t" << row[4]<<"\t | \t" << row[5] <<endl;
        }
    }
    
	}
	
void chooseSurgeryNum(string department){
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, HOST, USER, PASS, "hms", 3306, NULL, 0);

    if(conn){
        	
            stringstream ss;
            ss<<"SELECT * FROM surgery where surgeryDepartment='"+department+"'"+" AND surgeryAvailibility!='busy'";
            string query = ss.str();
			const char* q = query.c_str();
			mysql_query(conn,q);
            
            	res=mysql_store_result(conn);
            	
            	while(row = mysql_fetch_row(res)){
                cout << row[0] <<"\t | \t" << row[1] <<"\t | \t" << row[2] <<"\t | \t" << row[3] <<endl;
       }  
    }	
	}
void updatetimetabledoctor(char id[40], int day, int month, int year, int appointmentTime){
   	conn = mysql_init(0);
    conn = mysql_real_connect(conn,HOST, USER, PASS, "hms", 3306, NULL, 0);
    if(conn){ 
        int qstate = 0;        
        stringstream ss;
        string busy ="busy";
        ss<<"UPDATE `hms`.`timetabledoctor` SET `'"<<appointmentTime<<"'` = '"<<busy<<"' WHERE (`DoctorId`='"<<id<<"',`date`='"<<day<<"-"<<month<<"-"<<year<</*"',`"<<appointmentTime<<"` != '"<<busy<<*/"'"<<")";
        
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
	}
void setSurgery(string department){
	viewDoctor(department);
	char id[40];
	std::string date, time;
	int day, month, year;	
	cout<<"Enter a doctor Id: ";
	cin>>id;

	cout<<"Enter a date for appointment(day-month-year): ";
	cin>>date;
	char *dateArr = strtok(dateArr, "-");  // 06-07-2022  [06, 07, 2022]
	day = (int)dateArr[0];	
	month = (int)dateArr[1];
	year = (int)dateArr[2];	
	
	cout<<"Enter time  for appointment(00-00)";
	cin>>time;
	
//	updatetimetabledoctor(id, day, month, year, time);
}

    void updateSurgery(char id[40],string department,int surgeryNum){
   	conn = mysql_init(0);
    conn = mysql_real_connect(conn,HOST, USER, PASS, "hms", 3306, NULL, 0);
    if(conn){ 
        int qstate = 0;        
        stringstream ss;
        string busy ="busy";
        ss<<"UPDATE `hms`.`surgery` SET `surgeryAvailibility`='"<<busy<<"',`surgeryDoctorid`='"<<id<<"' WHERE (`surgeryNum` = '"<<surgeryNum<<"')";
        
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
	}
/*void setSurgery(string department){
	viewDoctor(department);
	char id[40];	
	cout<<"Enter a doctor Id: ";
	cin>>id;
	chooseSurgeryNum(department);
 	int surgeryNum;
 	cout<<"Choose a surgery number: ";
 	cin>>surgeryNum;
	updateSurgery(id,department,surgeryNum);
}

void chooseDepartment(){
	cout << endl << endl << "---------------" << endl << endl << "1.Eye" << endl << "2.Ear "<< endl<< "3.Lung "<< endl <<"4.Heart"<<endl<<"5.END"<<endl<<"-------------"<<endl;
   	cout << endl << "Your Answer : ";

	cin >> ans;
	string eye="eye",ear="ear",lung="lung",heart="heart";	
	switch(ans){
				case 1:
			        setSurgery(eye);
			        break;
			    case 2:
		            setSurgery(ear);
		            break;
		        case 3:
				
				    setSurgery(lung);
			        break;
		       case 4:
		       	setSurgery(heart);
		            break;
		        case 5:
		        	runforever==0;
		           	break;
		        }	
}*/
int login(){
	string dummy;
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, HOST, USER, PASS, "hms", 3306, NULL, 0);
	int message;
	int qstate=0;
	string username, password;
    	cout << "Enter username : ";
        cin >> username;
        cout << "Enter password : ";
        cin >> password;
        stringstream ss;
        ss<<"SELECT * FROM manager WHERE username= '"  +username+"'"+"AND password = '"+password+"'";
		string query = ss.str();
			const char* q = query.c_str();
			mysql_query(conn,q);
            
            	res=mysql_store_result(conn);
            	
            	
            	if(row = mysql_fetch_row(res)){
            		
					message =1;
            		
				}else{
					
					message=0;
					
				}
				return message;
}

int patientLogin(){
	string dummy;
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, HOST, USER, PASS, "hms", 3306, NULL, 0);
	int message;
	int qstate=0;
	string patientUsername, patientPassword;
    	cout << "Enter patient Username : ";
        cin >> patientUsername;
        cout << "Enter patient Password : ";
        cin >> patientPassword;
		stringstream ss1;
        ss1<<"SELECT * FROM patients WHERE patientUsername= '"+patientUsername+"' " + "AND patientPassword = '"+patientPassword+"'";
		string query = ss1.str();
			const char* q = query.c_str();
			mysql_query(conn,q);
            
            	res=mysql_store_result(conn);
            	
            	
            	if(row = mysql_fetch_row(res)){
            		
					message =1;
            		
				}else{
					
					message=0;
					
				}
				return message;
}

 string currentDate() {
    time_t     now = time(0);
    struct tm  tstruct;    
    char       buf[80];   
    tstruct = *localtime(&now);  
    strftime(buf, sizeof(buf), "%d-%m-%Y", &tstruct);
    return buf;
    
}
string currentTime(){
	time_t     now = time(0);
	struct tm  ttime;
	char       buf1[80];
	ttime= *localtime(&now);
	strftime(buf1, sizeof(buf1), "%H-%M", &ttime);
	return buf1;
}



