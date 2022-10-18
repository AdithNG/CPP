//Title: Project 2 for Fall 2022
//Author: Adith Gunaseelan
//Date: 9/25/2022
//Description: This is main for project 2

//#include "Race.h"
#include "Race.cpp"

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

int main () {
  srand(time(NULL)); //Seeds the random number generator (Do NOT seed again)
  Race newRace; //Creates a new instance of the game
  newRace.ManageGame(); //Starts the game
  return 0;
}
