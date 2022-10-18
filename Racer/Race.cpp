#include "Race.h"
#include "Player.cpp"
#include "Track.cpp"
/**********
* File: Race.cpp
* Intended for Project 2: Racer
**********/

//Default Constructor
Race::Race(){}

//Starts the race
void Race::StartRace(){
  int length = 0;
  int option = 0;
  int winner = 0;

  m_track.ResetLocation(); //Resets Location for new race
  m_myPlayer.SetRaces(m_myPlayer.GetRaces()+1); // Increments no. of races

  do{
    cout << "How long would you like the race?" << endl;
    cin >> length;
    if (length < 1){
      cout << "Invalid Input!" << endl;
    }
  }while (length < 1 || length > MAX_LENGTH);

  m_track.SetLength(length); //Sets length of race
  m_track.PopulateObstacles(); // Creates obstacles

  do{
    option = RaceOptions();

    if (option == 1){
      m_track.GetStatus();

    }else{
      ProgressRace(option);

    }
  }while(m_track.CheckWin() == -1);

  winner = m_track.CheckWin();

  if (winner == 0){
    cout << "You won the race" << endl;
    m_myPlayer.IncreaseStat();
    m_myPlayer.IncreaseWins();

  }else{
    cout << "Player " << winner << " won the race!" << endl;
  }

}

//Inputs name of racer
void Race::GetRacerInfo(){
  string name;
  cout << "What is your racer's name?" << endl;
  cin >> name;

  m_myPlayer.SetName(name);

}

//Checks progression of game
void Race::ProgressRace(int choice){
  int difficulty = 0;
  difficulty = (rand() % (BASE_DIFFICULTY)) + 1; //Sets difficulty of obstacle

  int stat = 0;
  stat = m_myPlayer.GetStat(choice - 2); // Gets stat of user choice

  //Gets location of player
  int location = 0;
  if (m_track.ConvertObstacle(0) == "speed"){
    location = 0;

  }else if (m_track.ConvertObstacle(0) == "agility"){
    location = 1;

  }else{
    location = 2;
  }

  cout << "You are trying to progress the race!" << endl;
  if (choice - 2 == location){

    if (difficulty <= BASE_SKILL + (5 * stat)){
      cout << "You made it through the " << m_track.ConvertObstacle(0) << " obstacle!" << endl;
      m_track.IncrementLocation(0);

    }else{
      cout << "You fell!" << endl;
      m_myPlayer.SetFalls((m_myPlayer.GetFalls())+1);
    }

  }else{
    cout << "You fell!" << endl;
    m_myPlayer.SetFalls((m_myPlayer.GetFalls())+1);

  }

  //For AI Players
  ProgressComputer(difficulty);

}

//Manages Main Menu
bool Race::MainMenu(){
  int option;

    do{
      cout << "What would you like to do? " << endl;
      cout << "1. Start New Race" << endl;
      cout << "2. View Racer History" << endl;
      cout << "3. Quit" << endl;
      cin >> option;

      if (option < 1 || option > 3){
        cout << "Invalid Input!" << endl;
      }
    }while(option < 1 || option > 3);

    if (option == 1){
      StartRace();
      return true;

    }else if (option ==  2){
      m_myPlayer.DisplayStatus();
      return true;

    }else if (option == 3){
      return false;
    }
}

//Manages Race Menu
int Race::RaceOptions(){
  int option = 0;
  do{
    cout << "What would you like to do?" << endl;
    cout << "1. Get Race Status" << endl;
    cout << "2. Try to Sprint (Speed)" << endl;
    cout << "3. Try to Dodge (Agility)" << endl;
    cout << "4. Try to Jump (Jump)" << endl;
    cin >> option;

    if (option < 1 || option > 4){
        cout << "Invalid Input!" << endl;
    }
  }while(option < 1 || option > 4);

  return option;
}

//Starts off game
void Race::ManageGame(){
  bool again = true;

  RaceTitle();
  GetRacerInfo();
  again = MainMenu();

  while(again){
    again = MainMenu();
  }

  cout << "Thanks for Playing UMBC Racer!" << endl;
}

//Manages AI participation
void Race::ProgressComputer(int obstacleDifficulty){
  int luck = 0;
  for (int i = 1; i < NUM_RACERS; i++){

    luck = (rand() % (COMP_MAX + 1 - COMP_MIN)) + COMP_MIN;

    if (luck > obstacleDifficulty){
      cout << "Player " << i << " made it through the " << m_track.ConvertObstacle(i) << " obstacle!" << endl;
      m_track.IncrementLocation(i);
    }else{
      cout << "Player " << i << " fell!" << endl;
    }
  }
}
