#include "Processor.h"
/**********
* File: Processor.cpp
* Intended for Project 5: Process Manager
**********/

//Overloaded Constructor
Processor::Processor(string filename){
  m_fileName = filename;
}

//Destructor
Processor::~Processor(){
  for (int i = 0; i < int(m_processes.size()); i++){
    delete m_processes[i];
  }
  for (int i = 0; i < int(m_threads.size()); i++){
    delete m_threads[i];
  }
}

//Process Manager, Starts the processing application
void Processor::InitializeProcessor(){
  DisplayTitle();
  LoadProcesses(m_fileName);
  PopulateThreads();
  MainMenu();
}

//Loads processes into vectors and creates base threads
bool Processor::LoadProcesses(string filename){

  fstream inputStream;
  inputStream.open(filename); // Opens the file

  string name, strID, strCallID, strDuration, garbage;
  int ID = 0, CallID = 0, Duration = 0, counter = 0;

  if (inputStream.is_open()){ // Checks if file is open
    while(getline(inputStream, name, DELIMITER) &&
	  getline(inputStream, strID, DELIMITER) &&
	  getline(inputStream, strCallID, DELIMITER)
	  ){

      inputStream >> strDuration;
      getline(inputStream, garbage); // Absorbs newLine character

      // Converts string to integer
      ID = stoi(strID);
      CallID = stoi(strCallID);
      Duration = stoi(strDuration);

      Process* newProcess = new Process(name, ID, CallID, Duration); // Creates new Process
      m_processes.push_back(newProcess); // Adds new process to vector

      //Creating threads
      if (counter < NUM_THREADS){
        AddThread(newProcess);
        counter++;
      }
    }
    return true;

  }else{
    cout << "Unable to open " << filename << endl; //If file not found
    return false;
  }
}

//Creates threads with base processes
void Processor::AddThread(Process* process){
  Lstack<Process*>* lstack = new Lstack<Process*>();
  lstack->Push(process);
  m_threads.push_back(lstack);
}

// Returns index of process with ID to be found
int Processor::GetProcessCalled(int id){
  for (int i = 0; i < int(m_processes.size()); i++){
    if (id == m_processes[i]->m_id){
      return i;
    }
  }
  return -1;
}

//Conmpletes creation of Threads
void Processor::PopulateThreads(){
  for (unsigned int i = 0; i < m_threads.size(); i++){
    int toID = m_threads[i]->At(0)->m_call; // Gets m_call to start

    while (toID != -1){
      Process* process = m_processes[GetProcessCalled(toID)]; // Gets m_call continuously untill -1
      m_threads[i]->Push(process); // Adds process to Thread
      toID = process->m_call; // Switches target process
    }

  }
}

// Manages main menu for user
void Processor::MainMenu(){
  int choice = 0;
  do{
    cout << "1. Display Threads" << endl;
    cout << "2. Start Thread" << endl;
    cout << "3. Quit" << endl;
    cin >> choice;

    while (choice < 1 || choice > 3){
      cout << "Invalid Input! Try Again!" << endl;
      cin >> choice;
    }

    if(choice == 1){
      DisplayThread(); //Displays vector to user to choose and view

    }else if (choice == 2){
      StartThreads(); // Starts off threads and counts time taken to complete
    }

  }while(choice != 3);

  cout << "Thank You for trying UMBC Processor!" << endl;
}

//Prints out all processes
void Processor::DisplayProcesses(){
  for (unsigned int i = 0; i < m_processes.size(); i++){
    cout << m_processes[i] << endl;
  }
}

//Displays all the threads
void Processor::ListThreads(){
  cout << "What thread would you like to view?" << endl;
  for (unsigned int i = 0; i < m_threads.size(); i++){
    cout << i+1 << ". Thread " << i+1 << " (" << m_threads[i]->GetSize() << " processes)" << endl;
  }
}

//Asks user Input for Thread to view
int Processor::ChooseThread(){
  ListThreads();

  int choice = 0;
  cin >> choice;

  while (choice < 1 || choice > int(m_threads.size())){
    cout << "Invalid Input! Try Again!" << endl;
    cin >> choice;
  }
  return choice - 1;

}

//Displays thread based on user input
void Processor::DisplayThread(){
  int index = ChooseThread();

  cout << "Thread " << index + 1 << endl;

  for (int i = 0; i < m_threads[index]->GetSize(); i++){
    cout << *m_threads[index]->At(i) << endl; // Prints out nodes in Lstack
  }
}

//Counts time taken to complete processes
void Processor::StartThreads(){
  for (int i = 0; i < int(m_threads.size()); i++){
    int time = 0;
    while (!m_threads[i]->IsEmpty()){
      time = time + m_threads[i]->Top()-> m_duration; //Adds time duration of each process
      m_threads[i]->Pop(); // Removes top process
    }
    cout << "Thread " << i+1 << " took " << time << " milliseconds to complete" << endl;
  }
}

//Displays Starting Title
void Processor::DisplayTitle(){
  cout << "Welcome to UMBC Processor!" << endl;
}


