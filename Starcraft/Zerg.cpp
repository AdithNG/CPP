#include "Zerg.h"
/**********
* File: Zerg.cpp
* Intended for Project 4: Starcraft
**********/

//Default Constructor
Zerg::Zerg():Entity(){}

//Overloaded Constructor
Zerg::Zerg(string name, int health):Entity(name, health){}

//Describes standard Zerg attack
int Zerg::Attack(){
  cout << GetName() << " deals 1 point of damage!" << endl;
  return 1;
}

