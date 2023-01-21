/*****************************************************************************
 ** File: Trivia.cpp
 ** Project: CMSC 202 Project 5, Spring 2022
 ** Author:  Kush Shah and CMSC202
 ** Date:    04/05/2022
 ** Email:   k216@umbc.edu
 **
 Description: CPP file for Trivia class. Includes both class definition and
 class function definitions. Loads a file of trivia questions
*****************************************************************************/

#ifndef TRIVIA_CPP
#define TRIVIA_CPP
#include "Lqueue.cpp"
#include "Question.cpp"
#include <fstream>
#include <vector>
using namespace std;

const string DEFAULT_FILE = "proj5_string.txt";
const char DELIMITER = '|';

template <class T>
class Trivia {
public:
  // Name: Default Constructor
  // Desc: Displays the title, Loads Questions and calls menu
  // Indicates if the file was not loaded.
  // Precondition: None
  // Postcondition: User is prompted with assignment menus
  Trivia(string filename);
  // Name: Destructor
  // Desc: Deallocates memory allocated for the Questions and
  // resets all variables.
  // Precondition: A Trivia exists.
  // Postcondition: All dynamically allocated memory in Trivia is deleted.
  ~Trivia();
  // Name: LoadQuestions
  // Desc: Each input file will be for a specific type of question (int, double, string)
  //       Reads in Questions from a file and stores them in anLqueue.
  //       An input file will be for exactly one type of question (int, double, string)
  // Precondition: None.
  // Postcondition: Returns true if file was read. Otherwise, it returns false.
  bool LoadQuestions(string filename);
  // Name: MainMenu
  // Desc: Presents user with menu options for showing subjects and allowing
  // user to work on a subject.
  // Precondition: None.
  // Postcondition: The main menu is presented.
  void MainMenu();
  // Name: DisplaySubjects
  // Desc: Presents all Subjects with corresponding numerical identifiers.
  // Precondition: Subjects have been added.
  // Postcondition: All assignments are printed to the screen.
  void DisplaySubjects();
  // Name: StartSubject
  // Desc: Starts working on a selected Subject.
  // Displays the number of questions in subject.
  // Starts at beginning and goes through each question.
  // After all questions have been answered:
  //       displays total correct, incorrect, and percentage correct
  // Precondition: m_questions has been populated
  // Postcondition: Returns to main menu
  void StartSubject();
  // Name: AddSubject
  // Desc: Checks to see if a subject exists in m_subjects.
  //       If not, inserts subject into m_subjects.
  // Precondition: A Subject exists.
  // Postcondition: Add subject to m_subjects if new subject.
  void AddSubject(string subject);
  // Name: ChooseSubject
  // Desc: Allows a user to choose one of the subjects to work on. Lists all subjects
  // in m_subjects and allows use to choose one. Returns value - 1 (location in vector)
  // Precondition: A Subject exists.
  // Postcondition: Returns value entered minus one
  int ChooseSubject();
  // Name: QuestionsPerSubject
  // Desc: Iterates over m_questions and counts how many questions match the subject
  // passed into function
  // Precondition: A Subject exists.
  // Postcondition: Returns number of questions of a particular subject
  int QuestionsPerSubject(string subject);
  // Name: DisplayTitle
  // Desc: Displays opening Welcome message
  // Precondition: None.
  // Postcondition: Title is displayed.
  void DisplayTitle();
private:
  Lqueue<Question<T>* >* m_questions; // Holds questions using a specific data type
  vector<string> m_subjects; //Populated as file is loaded
};

//**********Implement Trivia Class Here***********

//Overloaded constructor
template <class T>
Trivia<T>::Trivia(string filename){
  m_questions = new Lqueue<Question<T>* >; //Constructs new lqueue

  DisplayTitle();
  LoadQuestions(filename);
  MainMenu();
}

//Destructor
template <class T>
Trivia<T>::~Trivia(){
  delete m_questions;
}

//Loads questions into a queue
template <class T>
bool Trivia<T>::LoadQuestions(string filename){

  fstream inputStream;
  inputStream.open(filename); // Opens the file

  string subject, question, datatype, strDifficulty, garbage;
  int difficulty;
  T answer;

  if (inputStream.is_open()){ // Checks if file is open
    while(getline(inputStream, subject, DELIMITER) &&
	  getline(inputStream, question, DELIMITER) &&
	  getline(inputStream, datatype, DELIMITER) &&
	  getline(inputStream, strDifficulty, DELIMITER)
	  ){

      inputStream >> answer;
      getline(inputStream, garbage); // Absorbs newLine character
      difficulty = stoi(strDifficulty); // Converts string to integer

      Question<T>* newQuestion = new Question<T>(subject, question, datatype, difficulty, answer); // Creats new Question
      m_questions->Push(newQuestion); // Adds new question to queue
      //delete newQuestion;

      AddSubject(subject); //Adds subject to vector
    }
    return true;

  }else{
    cout << "Unable to open " << filename << endl;
    return false;
  }
}

//Runs the Main Menu
template <class T>
void Trivia<T>::MainMenu(){
  int choice = 0;
  do{

    cout << "Choose an option." << endl;
    cout << "1. Display Subjects" << endl;
    cout << "2. Start Subject" << endl;
    cout << "3. Quit" << endl;
    cin >> choice;

    //Input Validation
    while (choice < 1 || choice > 3){
      cout << "Please enter a valid option." << endl;
      cin >> choice;
    }

    if(choice == 1){
      DisplaySubjects();

    }else if(choice == 2){
      StartSubject();

    }

  }while(choice != 3);

  cout << "Thank you trying UMBC Trivia!" << endl;
}

//Displays all subjects in file
template <class T>
void Trivia<T>::DisplaySubjects(){
  for (unsigned int i = 0; i < m_subjects.size(); i++){
    cout << i+1 << ". " << m_subjects[i] << endl;
  }
}

//Starts the trivia
template <class T>
void Trivia<T>::StartSubject(){
  string subject;
  T submission;
  int numQuestions = 0;
  int counter = 0;
  int correct = 0;

  int index = ChooseSubject();
  subject = m_subjects[index];

  numQuestions = QuestionsPerSubject(subject);
  cout << "There are " << numQuestions << " questions in this subject" << endl;

  for (int i = 0; i < m_questions->GetSize(); i++){

    //Checks to ask questions from same subject
    if (m_questions->At(i)->m_subject == subject){
      counter++;

      cout << counter << ". Question: " << *(m_questions->At(i)) << endl;
      cout << "Please answer with a(n) string." << endl << endl;
      cin >> submission;

      m_questions->At(i)->m_isAnswered = true;

      if (m_questions->At(i)->CheckAnswer(submission)){
	cout << "Correct" << endl;
	correct++;

      }else{
	cout << "Incorrect" << endl;

      }
    }
  }

  //Score calculator
  cout << "You got " << correct << " answers correct." << endl;
  cout << "You got " << counter - correct << " answers incorrect." << endl;
  cout << "Which is a " << double(correct*100)/counter << "%." << endl;
}

//Adds unique subject to vector
template <class T>
void Trivia<T>::AddSubject(string subject){
  bool flag = false;

  for (unsigned int i = 0; i < m_subjects.size(); i++){
    if (m_subjects[i] == subject){
      flag = true;
    }
  }

  if(not flag){
    m_subjects.push_back(subject);
  }
}

//Asks user for subject to start trivia
template <class T>
int Trivia<T>::ChooseSubject(){
  int choice = 0;

  cout << "What subject would you like to attempt?" << endl;
  cout << "Possible Subjects:" << endl;
  DisplaySubjects();

  do{
    cin >> choice;
    if (choice < 1 or choice > int(m_subjects.size())){
      cout << "Please enter a valid option." << endl;
    }
  }while(choice < 1 || choice > (int)m_subjects.size());

  return choice - 1;
}

//Calculates no of questions in specified subject
template <class T>
int Trivia<T>::QuestionsPerSubject(string subject){
  int counter = 0;

  for (int i = 0; i < m_questions->GetSize(); i++){
    if (m_questions->At(i)->m_subject == subject){
      counter++;
    }
  }
  return counter;
}

//Displays the Title
template <class T>
void Trivia<T>::DisplayTitle(){
  cout << "Welcome to UMBC Trivia!" << endl;
}


#endif
