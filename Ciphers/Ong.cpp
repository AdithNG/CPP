#include "Ong.h"
/**********
* File: Ong.cpp
* Intended for Project 4: Cipher
**********/

//Default Constructor
Ong::Ong():Cipher(){}

//Overloaded constructor
Ong::Ong(string message, bool isEncrypted):Cipher(message, isEncrypted){}

//Destructor
Ong::~Ong(){}

//Checks if character is vowel (Only letters are consonants)
bool Ong::IsVowel(char letter){
  if ((letter >= 'a' and letter <= 'z') || (letter >= 'A' and letter <= 'Z')){

    if (tolower(letter) == 'a' or tolower(letter) == 'e' or tolower(letter) == 'i' or tolower(letter) == 'o' or tolower(letter) == 'u'){
      return true;
    }else{
      return false;
    }

  }
  return true;
}

//Encrypts the Data
void Ong::Encrypt(){
  string message = "";

  for (unsigned int i = 0; i < GetMessage().size(); i++){

    if(IsVowel(GetMessage()[i])){
      message += GetMessage()[i]; // Ignores vowels

    }else{
      message = message + GetMessage()[i] + "ong"; // Ong cipher
    }
    if (GetMessage()[i+1] != ' ' and GetMessage()[i] != ' ' and i != GetMessage().size() - 1){
      message += '-';
    }
  }
  SetMessage(message);
  ToggleEncrypted();
}

//Decrypts the data
void Ong::Decrypt(){
  string message = "";

  for (unsigned int i = 0; i < GetMessage().size(); i++){

    if (GetMessage()[i] != '-'){

      if (GetMessage()[i+1] == 'o' and GetMessage()[i+2] == 'n' and GetMessage()[i+3] == 'g'){
	message += GetMessage()[i]; // Grabs Consonants
	i = i+3; //Skips Ong

      }else if (IsVowel(GetMessage()[i])){
	message += GetMessage()[i]; //Grabs Vowels
      }
    }
  }

  SetMessage(message);
  ToggleEncrypted();
}

//Returns object type
string Ong::ToString(){
  return "(Ong)";
}

//Formats output for Exporting
string Ong::FormatOutput(){
  stringstream ss;
  ss << "o" << DELIMITER << int(GetIsEncrypted()) << DELIMITER << GetMessage() << DELIMITER << endl;
  return ss.str();
}
