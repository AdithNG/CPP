/*
Title: Hashtag Analyzer
Author: Adith Nishanth Gunaseelan
Date: 9/28/2022
E-Mail : mi12370@umbc.edu
Description: Program to analyze hashtags.
*/
#include <iostream>
#include <iomanip>//Required to format array values
#include <fstream> //Required to open/close and read a file
#include <string> //Required to use a string
using namespace std;

const int NUMBER_OF_HASHES = 20;

void loadfiles(string a[], string b[], int size);
// PRECONDITION: Array and size passed as parameters.
// POSTCONDITION: Opens file and populates arrays with hashes and messages.

bool processMessage(string a[], string b[], int index);
// PRECONDITION: Arrays and index passed as parameters.
// POSTCONDITION: Compares element against given list.

void counter(string a[], string b[], int c[]);
// PRECONDITION: Arrays passed as parameters.
// POSTCONDITION: Counts recurrence of hash element.

void displayCount(string a[], int c[]);
// PRECONDITION: Arrays passed as parameters.
// POSTCONDITION: Displays formatted elements.

void reset(int c[]);
// PRECONDITION: Array passed as parameter.
// POSTCONDITION: Resets the array.

int main () {

    string starterList[NUMBER_OF_HASHES];
    string messageList[NUMBER_OF_HASHES];
    int countList[NUMBER_OF_HASHES] = {0};

    string restart;

    cout << "Welcome to the Hashtag Analyzer" << endl;
    do{
        loadfiles(starterList, messageList, NUMBER_OF_HASHES);

        cout << "Messages with matching hashtags" << endl << endl;

        int index = 1;
        for (int i = 0; i < NUMBER_OF_HASHES; i = i+2){
            if (processMessage(starterList, messageList, i)){
                cout << index << ". " << messageList[i] << " " << messageList[i+1] << endl;
                index++;
            }
        }

        counter(starterList, messageList, countList);
        displayCount(starterList, countList);

        cout << "Would you like to analyze another file?" << endl;
        cin >> restart;

        if (restart == "y"){
            reset(countList);
        }

    }while (restart != "n");

    cout << "Thank you for using the hashtag analyzer!" << endl;

  return 0;
}


void loadfiles(string starterList[], string messageList[], int size){

    // Loading files into arrays
    string file1;
    string file2;
    fstream inputStream1;
    fstream inputStream2;

    cout << "You will choose a file of hashtags to search for" << endl;
    cout << "Then you will choose a file to search for the hashtags" << endl;

    do{
        cout << "Please enter the file with the hashtags you would like to use:" << endl;
        cin >> file1;
        inputStream1.open(file1);

        if (!inputStream1.is_open()){
            cout << "Unable to open file! Try Again!" << endl;
        }
    }while (!inputStream1.is_open());

    do{
        cout << "Please enter the file with the messages you would like to parse:" << endl;
        cin >> file2;
        inputStream2.open(file2);

        if (!inputStream2.is_open()){
            cout << "Unable to open file! Try Again!" << endl;
        }
    }while (!inputStream2.is_open());

    if(inputStream1.is_open()){
        cout << "Your file was imported!" << endl;
    }

    if (inputStream2.is_open()){
        cout << "Your file was imported!" << endl;
    }

    //////////////////////////////////////////////
    // Populating the array

    int hashCount = 0;
    int messageCount = 0;
    int index1 = 0;
    int index2 = 0;

    while(index1 < NUMBER_OF_HASHES){
        getline(inputStream1, starterList[index1]);
        hashCount++;
        index1++;
    }

    while(index2 < NUMBER_OF_HASHES){
        getline(inputStream2, messageList[index2]);
        messageCount++;
        index2++;
    }


    cout << messageCount/2 << " messages loaded." << endl;
    cout << hashCount << " Hashtags loaded." << endl;

    inputStream1.close();
    inputStream2.close();
}

bool processMessage(string starterList[], string messageList[], int i){
    for (int j = 0; j < NUMBER_OF_HASHES ; j++){
        if (messageList[i] == starterList[j]){
                if (messageList[i] != ""){
                    return true;
                }
        }
    }
    return false;
}

void counter(string starterList[], string messageList[], int countList[]){
    for (int i = 0; i < NUMBER_OF_HASHES; i++){
        for (int j = 0; j < NUMBER_OF_HASHES; j++){
            if (starterList[i] == messageList[j]){
                countList[i]++;
            }
        }
    }
}

void displayCount(string starterList[], int countList[]){
    cout.fill(' ');
    for (int i = 0; i < NUMBER_OF_HASHES; i++){
        cout << setw(6) << i+1 << setw(25) << starterList[i] << setw(5) << countList[i] << endl;
    }
}

void reset(int countList[]){
    countList = {0};
}
