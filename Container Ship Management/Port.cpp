#include "Port.h"
/**********
 * File: Port.cpp
 * Intended for Project 3: Container Ship Management
 **********/

//Default Constructor
Port::Port() {
  m_name = "New Port";
  m_location = "New Location";
  m_north = 0;
  m_west = 0;
  m_next = nullptr;
}

//Overloaded Constructor
Port::Port(string name, string location, double north, double west) {
  m_name = name;
  m_location = location;
  m_north = north;
  m_west = west;
  m_next = nullptr;
}

//Destructor
Port::~Port(){}

//Getters
string Port::GetName() {
  return m_name;
}

Port* Port::GetNext() {
  return m_next;
}

double Port::GetNorth() {
  return m_north;
}

double Port::GetWest() {
  return m_west;
}

string Port::GetLocation() {
  return m_location;
}

//Setter
void Port::SetNext(Port* port) {
  m_next = port;
}
