/*
Title: Wordle V2
Author: Adith Nishanth Gunaseelan
Date: 2/26/2022
Description: Program to recreate Wordle.
*/
#include <iostream>
#include <fstream> //Required to open/close and read a file
#include <string> //Required to use a string
#include <cstdlib> // Required for rand
#include <ctime> //Required to use time for randomizer
using namespace std;


const int NUMBER_OF_WORDS = 2315;
const string GREEN = "!";
const string YELLOW = "&";
const string GREY = "_";
const string EMPTY = "_____";


void loadWords(string a[], int size);
// PRECONDITION: Array and size passed as parameters.
// POSTCONDITION: Opens file and inputs words into array.
//                Calls guessWord()
void guessWord(string a[]);
// PRECONDITION: Array passed as parameter
// POSTCONDITION: Picks random word to guess.
//                Takes input from user and displays letter matches .
bool checkWord(string guess, string a[]);
// PRECONDITION: User guess and Wordlist passed as parametrs.
// POSTCONDITION: Checks if word exists in wordlist.
//                Returns True/False
int checkLetter(char guess, string chosenWord, int index);
// PRECONDITION: User Guess, Picked word, and current index passed as parameters.
// POSTCONDITION: It returns type of match of letter to print symbol.
//                Returns Integer
void displayCurrent(string a[], string arr[], int size);
// PRECONDITION: Array of symbols, array of guesses, and size of array passed as parameters.
// POSTCONDITION: prints out all guessed words.
//                Also prints empty spaces.
bool checkWin(string colours, string chosenWord);
// PRECONDITION: Current symbols passed as parameters.
// POSTCONDITION: Ckecks if win condition is satisfied.
//                Returns True/False


int main () {
    string wordList[NUMBER_OF_WORDS];

    cout << "Welcome to UMBC Wordle" << endl;

    loadWords(wordList, NUMBER_OF_WORDS);

  return 0;
}


void loadWords(string wordList[], int listSize){


    fstream inputStream;
    inputStream.open("proj1_data.txt");

    int wordCount = 0;
    int index = 0;

    if (inputStream.is_open()) { //Checks to see if the file exists and was opened

        while (getline(inputStream, wordList[index])){
            wordCount++;
            index++;

        }
    cout << "Your file was imported!" << endl;
    cout << wordCount << " words imported."<< endl;

    guessWord(wordList);

    }else {
      cout << "Unable to open file"; //If the input file does not exist, notifies user
    }

}

void guessWord(string wordList[]){

    int i = 0;
    int guessNum = 6;
    string guess;
    string answerColours[guessNum];
    string guesses[guessNum];

    for (int i = 0; i < guessNum; i++){
        answerColours[i] = EMPTY;
    }

    for (int i = 0; i < guessNum; i++){
        guesses[i] = EMPTY;
    }

    srand(time(NULL)); //Seeds random number generator (psuedo)
    int index = rand() % NUMBER_OF_WORDS;

    string chosenWord = wordList[index];
    cout << chosenWord << endl;

    cout << "Ok. I am thinking of a word with five letters." << endl;

    do{
        cout << "What word would you like to guess?" << endl;
	cout << "\033[;34m";
        cin >> guess;
	cout << "\033[0m";

        if (guess.length() != 5){
            cout << "That word is not five letters long!" << endl;
        }else if (not checkWord(guess, wordList)){
            cout << "That word is not in the word list" << endl;
        }else{
            string colours = "";
            guesses[i] = guess;
	     for (int j = 0; j < i; j++){
	       for (int k = 0; k < 5; k++){
                int type = checkLetter(guesses[j][k], chosenWord, k);
                switch (type)
                                {
                case 1:
                  cout <<  "\033[;32m";
                  cout << guesses[j][k];
                  cout << "\033[0m";
                    break;
                case 0:
                  cout << "\033[;31m";
                  cout << guesses[j][k];
                  cout << "\033[0m";
                    break;
                case -1:
                  cout << "\033[;33m";
                  cout << guesses[j][k];
                  cout <<  "\033[0m";
                    break;
                }
	       }
	       cout << "\n";
	     }

            for (int i = 0; i < 5; i++){
                int type = checkLetter(guess[i], chosenWord, i);
                switch (type)
                                {
                case 1:
		  cout <<  "\033[;32m";
		  cout << guess[i];
		  cout << "\033[0m";
                    break;
                case 0:
		  cout << "\033[;31m";
		  cout << guess[i];
		  cout << "\033[0m";
                    break;
                case -1:
		  cout << "\033[;33m";
		  cout << guess[i];
		  cout <<  "\033[0m";
                    break;
                }

            }

            cout << "\n";

            answerColours[i] = colours;
            int j = 6;
            while (j > i+1){
                cout << EMPTY << endl;
                j--;
            }



            if (checkWin(guess, chosenWord)){
                string newGame;
                cout << "Congrats you won!" << endl;
                cout << "The correct word was: " << chosenWord << endl;
                cout << "Another game? y/n" << endl;
                cin >> newGame;
                if (newGame == "y"){
                    guessWord(wordList);
                }else if(newGame == "n"){
                    cout << "Thank you!" << endl;
                    break;
                }

            }
            i++;
        }

    }while(i <= 5);

    if (i == 6){
        string newGame;
        cout << "Sorry, you lost!" << endl;
        cout << "The correct word was: " << chosenWord << endl;
        cout << "Another game? y/n" << endl;
        cin >> newGame;
        if (newGame == "y"){
            guessWord(wordList);
        }else if(newGame == "n"){
            cout << "Thank you!" << endl;
        }
    }
}

int checkLetter(char letter, string word, int index){

    bool flag = false;

        if (letter == word[index]){
            return 1;

        }else{
            for (int j = 0; j < 5; j++){
                if (letter == word[j]){
                    flag = true;}
            }

            if (flag == true){
                return -1;
            }else{
                return 0;
            }
        }

}



bool checkWin(string colours, string chosenWord){
    if (colours == chosenWord){
        return true;
    }
    return false;

}

bool checkWord(string word, string wordList[]){
    for (int i = 0; i < NUMBER_OF_WORDS; i++){
        if (word == wordList[i]){
            return true;
        }
    }
    return false;
}
