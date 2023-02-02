#include "Area.h"
/**********
* File: Area.cpp
* Intended for Project 4: Starcraft
**********/

//Overloaded Constructor
Area::Area(int ID, string name, string desc, int north, int east, int south, int west){
  m_ID = ID;
  m_name = name;
  m_desc = desc;
  m_direction[0] = north;
  m_direction[1] = east;
  m_direction[2] = south;
  m_direction[3] = west;
}

//Getter
string Area::GetName(){
  return m_name;
}

//Getter
int Area::GetID(){
  return m_ID;
}

//Getter
string Area::GetDesc(){
  return m_desc;
}

//Returns ID of area in adjacent direction
int Area::CheckDirection(char myDirection){
  return m_direction[myDirection];
}

//Print description of Area
void Area::PrintArea(){
  cout << m_name << endl;
  cout << m_desc << endl;
  cout << "Possible Exits: ";

  if (CheckDirection('N') != -1){
    cout << "N ";
  }if (CheckDirection(E) != -1){
    cout << "E ";
  }if (CheckDirection(S) != -1){
    cout << "S ";
  }if (CheckDirection(W) != -1){
    cout << "W ";
  }
  cout << endl;
}

