#include "Mutalisk.h"
/**********
* File: Mutalisk.cpp
* Intended for Project 4: Starcraft
**********/


//Default Constructor
Mutalisk::Mutalisk():Zerg(){}

//Overloaded Constructor
Mutalisk::Mutalisk(string name, int health):Zerg(name, health){}

//Describes special attack of Mutalisk
int Mutalisk::SpecialAttack(){
  int damage = 4;
  cout << GetName() << " blasts you with their ir attack!" << endl;
  cout << GetName() << " deals "<< damage << " points of damage!" << endl;
  return damage;
}
