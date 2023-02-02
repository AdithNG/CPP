#include "Zergling.h"
/**********
* File: Zergling.cpp
* Intended for Project 4: Starcraft
**********/


//Default Constructor
Zergling::Zergling():Zerg(){}

//Overloaded Constructor
Zergling::Zergling(string name, int health):Zerg(name, health){}

//Describes special attack of Zergling
int Zergling::SpecialAttack(){
  cout << GetName() << " scratches at you ferociously!" << endl;
  cout << GetName() << " dealt 1 damage!" << endl;
  return 1;
}
