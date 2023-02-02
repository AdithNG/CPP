#include "Marine.h"
/**********
* File: Marine.cpp
* Intended for Project 4: Starcraft
**********/


//Default Constructor
Marine::Marine():Terran(){}

//Overloaded Constructor
Marine::Marine(string name, int health):Terran(name, health){}

//Destructor
Marine::~Marine(){}

//Describes special attack of Marine
int Marine::SpecialAttack(){
  int maxDamage = 8;
  int damage = rand() % maxDamage + 1;
  cout << GetName() << " spins up doing GATLING DAMAGE!" << endl;
  cout << GetName() << " deals " << damage << " damage!" << endl;
  return damage;
}

