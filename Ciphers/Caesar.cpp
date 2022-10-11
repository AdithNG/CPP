#include "Caesar.h"
/**********
* File: Caesar.cpp
* Intended for Project 4: Cipher
**********/

//Default Constructor
Caesar::Caesar():Cipher(){
  m_shift = 3;
}

//Overloaded Constructor
Caesar::Caesar(string message, bool isEncrypted, int shift):Cipher(message, isEncrypted){
  m_shift = shift;
}

//Destructor
Caesar::~Caesar(){}

//Encrypts the data
void Caesar::Encrypt(){
  string str = "";

  for (int i = 0; i < int(GetMessage().length()); i++){
    char letter = GetMessage()[i];

    if (letter >= 'a' and letter <= 'z'){ //Lowercase
      letter += m_shift;

      if (letter > 'z'){
	letter = (letter % 'z' - 1) + 'a'; // Similar to setting limits of rand()
      }

    }else if (letter >= 'A' and letter <= 'Z'){ //UppercCase
      letter += m_shift;

      if (letter > 'Z'){
	letter = (letter % 'Z' - 1) + 'A';//prevent letter bigger than maximum('Z')
      }
    }
    str += letter;
  }
  SetMessage(str);
  ToggleEncrypted();
}

//Decrypts the data
void Caesar::Decrypt(){
  string str = "";

  for (int i = 0; i < int(GetMessage().length()); i++){
    char letter = GetMessage()[i];

    if (letter >= 'a' and letter <= 'z'){ //Lowercase
      letter -= m_shift;

      if (letter < 'a'){
	letter = 'z' - ('a' % letter - 1);
      }

    }else if (letter >= 'A' and letter <= 'Z'){ //Uppercase
      letter -= m_shift;

      if (letter < 'A'){
	letter = 'Z' - ('A' % letter - 1);
      }
    }
    str += letter;
  }
  SetMessage(str);
  ToggleEncrypted();
}

//Returns object type
string Caesar::ToString(){
  return "(Caesar)";
}

//Formats output for exporting
string Caesar::FormatOutput(){
  stringstream ss;
  ss << "c" << DELIMITER << int(GetIsEncrypted()) << DELIMITER << GetMessage() << DELIMITER << m_shift << endl;
  return ss.str();
}
