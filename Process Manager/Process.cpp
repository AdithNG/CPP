#include "Process.h"
/**********
* File: Process.cpp
* Intended for Project 5: Process Manager
**********/

//Default Constructor
Process::Process(){
  m_name = "test";
  m_id = -1;
  m_call = -1;
  m_duration = -1;
}


//Overloaded Constructor
Process::Process(string name, int id, int call, int duration){
  m_name = name;
  m_id = id;
  m_call = call;
  m_duration = duration;
}

//Overloaded Insertion Operator
ostream& operator<< (ostream& output, Process& process){
  output << process.m_name << " " << process.m_id << " " << process.m_call << " " << process.m_duration;
  return output;
}
