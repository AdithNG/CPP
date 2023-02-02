#include "Hydralisk.h"
/**********
* File: Zergling.cpp
* Intended for Project 4: Starcraft
**********/


//Default Constructor
Hydralisk::Hydralisk():Zerg(){}

//Overloaded Constructor
Hydralisk::Hydralisk(string name, int health):Zerg(name, health){}

//Describes special attack of Hydralisk
int Hydralisk::SpecialAttack(){
  int damage = 2;
  cout << GetName() << " sprays you with deadly acid!" << endl;
  cout << GetName() << " deals " << damage << " points of damage!" << endl;
  return damage;
}
