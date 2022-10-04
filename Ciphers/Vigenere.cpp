#include "Vigenere.h"
/**********
* File: Vigenere.cpp
* Intended for Project 4: Cipher
**********/

//Default Constructor
Vigenere::Vigenere():Cipher(){
  m_key = "";
}

//Overloaded Constructor
Vigenere::Vigenere(string message, bool isEncrypted, string key):Cipher(message, isEncrypted){
  m_key = key;
}

//Destructor
Vigenere::~Vigenere(){}

//Encrypts the data
void Vigenere::Encrypt(){
  string newKey = "";
  int index = 0;

  for (int i = 0; newKey.size() < GetMessage().size() ; i++){

    if (i == int(m_key.size())){
      i = 0;
    }

    if((GetMessage()[index] >= 'a' and GetMessage()[index] <= 'z') or (GetMessage()[index] >= 'A' and GetMessage()[index] <= 'Z')){
      newKey += m_key[i]; //binds key and letter
    }else{
      newKey += ' ';//Does not bind non-letter characters
      i--;
    }

    index++;
  }

  string garbled = "";
  char letter;
  int r = 0;

  for(unsigned int i = 0; i < newKey.size(); i++){
    if (GetMessage()[i] >= 'a' and GetMessage()[i] <= 'z'){//Uppercase
      letter = ((GetMessage()[i] + newKey[r] - 2 * 'a') % 26) + 'a';

    }else if (GetMessage()[i] >= 'A' and GetMessage()[index] <= 'Z'){//lowercase
      letter = ((GetMessage()[i] + toupper(newKey[r]) - 2 * 'A') % 26) + 'A';

    }else {
      letter = GetMessage()[i];

    }
    r = (r+1) % newKey.size();
    garbled += letter;
  }
  SetMessage(garbled);
  ToggleEncrypted();
}

//Decrypts the data
void Vigenere::Decrypt(){
  string newKey = "";
  int index = 0;

  for (int i = 0; newKey.size() < GetMessage().size() ; i++){

    if (i == int(m_key.size())){
      i = 0;
    }

    if((GetMessage()[index] >= 'a' and GetMessage()[index] <= 'z') or (GetMessage()[index] >= 'A' and GetMessage()[index] <= 'Z')){
      newKey += m_key[i];//Binds key and letter
    }else{
      newKey += ' ';//Does not bind non-letter characters
      i--;
    }

    index++;
  }

  string straight = "";
  char letter;
  int r = 0;

  for(unsigned int i = 0; i < newKey.size(); i++){
    if (GetMessage()[i] >= 'a' and GetMessage()[i] <= 'z'){ //Lowercase
      letter = ((GetMessage()[i] - newKey[r] + 26) % 26) + 'a';

    }else if (GetMessage()[i] >= 'A' and GetMessage()[index] <= 'Z'){ //Uppercase
      letter = ((GetMessage()[i] - toupper(newKey[r]) + 26) % 26) + 'A';

    }else {
      letter = GetMessage()[i];

    }
    r = (r+1) % newKey.size();
    straight += letter;
  }

  SetMessage(straight);
  ToggleEncrypted();
}

//Returns object type
string Vigenere::ToString(){
  return "(Vigenere)";
}

//Formats output for exporting
string Vigenere::FormatOutput(){
  stringstream ss;
  ss << "v" << DELIMITER << int(GetIsEncrypted()) << DELIMITER << GetMessage() << DELIMITER << m_key << endl;
  return ss.str();
}
