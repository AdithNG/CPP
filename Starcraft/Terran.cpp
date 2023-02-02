#include "Terran.h"
/**********
* File: Terran.cpp
* Intended for Project 4: Starcraft
**********/

//Default Constructor
Terran::Terran():Entity(){}

//Overloaded Constructor
Terran::Terran(string name, int health):Entity(name, health){}

//Destructor
Terran::~Terran(){}

//Describes standard Zerg attack
int Terran::Attack(){
  int maxDamage = 6;
  int damage = rand() % maxDamage + 1;
  cout << GetName() << " attacks dealing " << damage << " damage" << endl;
  return damage;
}

//Describes Special attack of Terran
int Terran::SpecialAttack(){
  cout << "You do not have a special attack!" << endl;
  return 0;
}
