#include "Entity.h"
/**********
* File: Entity.cpp
* Intended for Project 4: Starcraft
**********/

//Default Constructor
Entity::Entity(){
  m_name = "New Name";
  m_health = 1;
}

//Overloaded Constructor
Entity::Entity(string name, int health){
  m_name = name;
  m_health = health;
}

//Destructor
Entity::~Entity(){}

//Getter
string Entity::GetName(){
  return m_name;
}

//Getter
int Entity::GetHealth(){
  return m_health;
}

//Setter
void Entity::SetName(string name){
  m_name = name;
}

//Setter
void Entity::SetHealth(int health){
  m_health = health;
}

//Overloaded operator (<<)
ostream &operator<<(ostream &output, Entity &E){

  if (E.m_name == "Zergling"){
      output << "A small terrifying zergling waits here." << endl;

  }else if (E.m_name == "Hydralisk"){
      output << "A medium sized hydralisk slithers here waiting to cover you with acid." << endl;

  }else if(E.m_name == "Mutalisk"){
      output << "A large flying mutalisk hovers here." << endl;
  }

  return output;
}









