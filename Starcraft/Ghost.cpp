#include "Ghost.h"
/**********
* File: Ghost.cpp
* Intended for Project 4: Starcraft
**********/


//Default Constructor
Ghost::Ghost():Terran(){}

//Overloaded Constructor
Ghost::Ghost(string name, int health):Terran(name, health){}

//Destructor
Ghost::~Ghost(){}

//Describes special attack of Ghost
int Ghost::SpecialAttack(){
  int maxDamage = 12;
  int minDamage = 2;
  int damage = rand() % maxDamage + minDamage;
  cout << GetName() << " performs a sneak attack!" << endl;
  cout << GetName() << " deals " << damage << " damage!" << endl;

  return damage;
}

