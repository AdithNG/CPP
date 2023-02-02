#include "Battlecruiser.h"
/**********
* File: Battlecruiser.cpp
* Intended for Project 4: Starcraft
**********/


//Default Constructor
Battlecruiser::Battlecruiser():Terran(){}

//Overloaded Constructor
Battlecruiser::Battlecruiser(string name, int health):Terran(name, health){}

//Destructor
Battlecruiser::~Battlecruiser(){}

//Describes special attack of Battlecruiser
int Battlecruiser::SpecialAttack(){
  int maxDamage = 12;
  int minDamage = 3;
  int damage = rand() % maxDamage + minDamage;
  cout << GetName() << " spins up doing GATLING DAMAGE!" << endl;
  cout << GetName() << " deals " << damage << " damage!" << endl;
  return damage;
}

