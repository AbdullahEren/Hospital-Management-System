#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <iostream>
#include <mysql.h>

using namespace std;

const int PopulationSize = 1000;
const int Shifts = 14;
const int Generations = 1000;  
const double MutationRate = 0.01;

class Schedule {
 public:
  int schedule[Shifts]; 
  int nurse[Shifts];
  int fitness;  

  
  Schedule() {
    for (int i = 0; i < Shifts; i++) {
      schedule[i] = rand() % 2;  
    }
  }
};
#endif
