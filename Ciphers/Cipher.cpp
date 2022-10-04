#include "Cipher.h"
/**********
* File: Cipher.cpp
* Intended for Project 4: Cipher
**********/

//Default Constructor
Cipher::Cipher(){
  m_message = "New message";
  m_isEncrypted = false;
}

//Overloaded Constructor
Cipher::Cipher(string message, bool isEncrypted){
  m_message = message;
  m_isEncrypted = isEncrypted;
}

//Destructor
Cipher::~Cipher(){}

//Getter
string Cipher::GetMessage(){
  return m_message;
}

//Getter
bool Cipher::GetIsEncrypted(){
  return m_isEncrypted;
}

//Setter
void Cipher::SetMessage(string message){
  m_message = message;
}

//Setter
void Cipher::ToggleEncrypted(){
  m_isEncrypted = not m_isEncrypted;
}

//Overloaded operator (<<)
ostream &operator<<( ostream &output, Cipher &C){
  output << C.m_message;
  return output;
}
