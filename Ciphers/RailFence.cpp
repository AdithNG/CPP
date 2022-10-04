#include "RailFence.h"
/**********
* File: RailFence.cpp
* Intended for Project 4: Cipher
**********/

//Default constructor
RailFence::RailFence():Cipher(){
  m_rails = 3;
}

//Overloaded constructor
RailFence::RailFence(string message, bool isEncrypted, int rails):Cipher(message, isEncrypted){
  m_rails = rails;
}

//Destructor
RailFence::~RailFence(){}

//Encrypts the data
void RailFence::Encrypt(){
  char my_array[m_rails][(GetMessage().size())];
  string direction;
  int rail = 0;

  //Sets all elements of 2D-array to '_'
  for (int i = 0; i < m_rails; i++){
    for (unsigned int j = 0; j < GetMessage().size(); j++){
      my_array[i][j] = '_' ;
    }
  }

  //Fills in letters at right spot
  for (unsigned int i = 0; i < GetMessage().size(); i++){

      if (rail == 0){
        direction = "down";
      }else if (rail == m_rails - 1){
        direction = "up";
      }

      my_array[rail][i] = GetMessage()[i];

      if (direction == "down"){
        rail++;
      }else{
        rail--;
      }
    }

  //Puts all leeters together in encrypted order
  string garbled = "";

  for (int i = 0; i < m_rails; i++){
    for (unsigned int j = 0; j < GetMessage().size(); j++){

      if (my_array[i][j] != '_'){
        garbled += my_array[i][j];
      }
    }
  }
  SetMessage(garbled);
  ToggleEncrypted();
}

void RailFence::Decrypt(){
  char my_array[m_rails][(GetMessage().size())];
  string direction;
  int rail = 0;

  //Sets all elements of 2D-Array to '_'
  for (int i = 0; i < m_rails; i++){
    for (unsigned int j = 0; j < GetMessage().size(); j++){
      my_array[i][j] = '_' ;
    }
  }

  //Fills in all the right spots with a common character ('*')
  for (unsigned int i = 0; i < GetMessage().size(); i++){

    if (rail == 0){
      direction = "down";
    }else if (rail == m_rails - 1){
      direction = "up";
    }

    my_array[rail][i] = '*';

    if (direction == "down"){
      rail++;
    }else{
      rail--;
    }
  }

  //Fills in common character with correct character in regular order
  unsigned int counter = 0;

  for(int i = 0; i < m_rails; i++){
    for(unsigned int j = 0; j < GetMessage().size(); j++){

      if (my_array[i][j] == '*' and counter < GetMessage().size()){
	my_array[i][j] = GetMessage()[counter];
	counter++;
      }
    }
  }

  //Puts all letters together in correct order by traversing in encrypted order
  string straight = "";
  rail = 0;

  for (unsigned int i = 0; i < GetMessage().size(); i++){

    if (rail == 0){
      direction = "down";
    }else if (rail == m_rails - 1){
      direction = "up";
    }

    if (my_array[rail][i] != '_'){
      straight += my_array[rail][i];
    }

    if (direction == "down"){
      rail++;
    }else{
      rail--;
    }
  }
  SetMessage(straight);
  ToggleEncrypted();
}

//Returns object type
string RailFence::ToString(){
  return "(RailFence)";
}

//Formats output for exporting
string RailFence::FormatOutput(){
  stringstream ss;
  ss << "r" << DELIMITER << int(GetIsEncrypted()) << DELIMITER << GetMessage() << DELIMITER << m_rails << endl;
  return ss.str();
}
