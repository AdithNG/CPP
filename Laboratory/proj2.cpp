//Title: Project 2 for Spring 2022
//Author: Adith Nishanth Gunaseelan
//Date: 2/25/2022
//Description: This is main for Laboratory

#include "Chemist.cpp"
#include "Lab.cpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

int main () {
  srand(time(NULL));
  Lab newLab;
  newLab.StartLab();
  return 0;
}
