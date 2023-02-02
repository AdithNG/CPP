#include "Game.h"
/**********
* File: Game.cpp
* Intended for Project 4: Starcraft
**********/

//Deafault Constructor
Game::Game(){
  m_curArea = START_AREA;
  m_numRests = NUM_RESTS;
  m_numSpecial = NUM_SPECIAL;
  m_filename = FILE_NAME;
  m_wins = START_WINS;
  m_myTerran = nullptr;
  m_curZerg = nullptr;
}

//Overloaded Constructor
Game::Game(string filename){
  m_curArea = START_AREA;
  m_numRests = NUM_RESTS;
  m_numSpecial = NUM_SPECIAL;
  m_filename = filename;
  m_wins = START_WINS;
  m_myTerran = nullptr;
  m_curZerg = nullptr;
}

//Destructor
Game::~Game(){
  for (unsigned int i = 0; i < m_myMap.size(); i++){
    delete m_myMap[i];
    m_myMap[i] = nullptr;
  }

  delete m_myTerran;
  m_myTerran = nullptr;

  delete m_curZerg;
  m_curZerg = nullptr;
}


void Game::LoadMap(){
  string strID, name, desc, strNorth, strEast, strSouth, strWest, garbage;
  int id, north, east, south, west = 0;

  fstream inputStream;
  inputStream.open(m_filename);//Opens the file

  if (inputStream.is_open()){//Checks if file is open

    while(getline(inputStream, strID, DELIMITER) &&
          getline(inputStream, name, DELIMITER) &&
          getline(inputStream, desc, DELIMITER) &&
          getline(inputStream, strNorth, DELIMITER) &&
          getline(inputStream, strEast, DELIMITER) &&
          getline(inputStream, strSouth, DELIMITER) &&
          getline(inputStream, strWest, DELIMITER) &&
          getline(inputStream, garbage)
          ){

          id = stoi(strID);
          north = stoi(strNorth);
          east = stoi(strEast);
          south = stoi(strSouth);
          west = stoi(strWest);

          //Creates new area object and adds to vector
          Area *area = new Area(id, name, desc, north, east, south, west);
          m_myMap.push_back(area);
    }
    inputStream.close();//Closes the file

  }else{
    cout << "File Could Not Be Found!" << endl;
  }
}

//Creates player
void Game::TerranCreation(){
  string name;
  int type = 0;

  cout << "Terran Name: ";
  cin >> name;

  do{
    cout <<  "Select a class" << endl;
    cout <<  "1. Marine" << endl;
    cout <<  "2. Ghost" << endl;
    cout <<  "3. Battlecruiser" << endl;
    cout <<  "4. No Class" << endl;
    cin >> type;

    if (type < 1 || type > 4){
        cout << "Invalid Input! Try Again!" << endl;
    }

  }while(type < 1 || type > 4);

  if (type == 1){
    m_myTerran = new Marine(name, MARINE_HEALTH);

  }else if (type == 2){
    m_myTerran = new Ghost(name, GHOST_HEALTH);

  }else if (type == 3){
    m_myTerran = new Battlecruiser(name, BATTLECRUISER_HEALTH);

  }else{
    m_myTerran = new Terran(name, TERRAN_HEALTH);
  }
}

//Starts the game
void Game::StartGame(){
  cout << "Welcome to UMBC Starcraft!" << endl;
  LoadMap();
  TerranCreation();

  m_myMap[m_curArea]->PrintArea();

  Action();
}

//Menu manager
void Game::Action(){
  m_curZerg = RandomZerg(); //Creates zerg for stage

  if (m_curZerg != nullptr){
    cout << *m_curZerg;
  }else{
    cout << "It is peaceful here" << endl;
  }

  int choice = 0;
  do{
    cout << "What would you like to do?" << endl;
    cout << "1. Look" << endl;
    cout << "2. Move" << endl;
    cout << "3. Attack Zerg" << endl;
    cout << "4. Rest" << endl;
    cout << "5. Check Stats" << endl;
    cout << "6. Quit" << endl;
    cin >> choice;

    while (choice > 6 || choice < 1){
      cout << "Invalid Input! Try Again!" << endl;
      cin >> choice;
    }

    if (choice == 1){
      m_myMap[m_curArea]->PrintArea();

    }else if (choice == 2){
      Move();

    }else if (choice == 3){
      Attack();

    }else if (choice == 4){
      Rest();

    }else if (choice == 5){
      Stats();

    }

  }while(choice != 6 and m_myTerran->GetHealth() > 0);

  if (choice == 6){
    cout << "Good Bye!" << endl;
  }else{
    cout << "Game Over" << endl;
  }


}

//Creates Zerg for stage
Entity* Game::RandomZerg(){
  int rank = 0;
  int numEntities = 4;
  rank = rand() % numEntities;

  Entity* curZerg;

  switch(rank){
    case 0:
      curZerg = nullptr;
      break;
    case 1:
      curZerg = new Zergling("Zergling",ZERGLING_HEALTH);
      break;

    case 2:
      curZerg = new Hydralisk("Hydralisk",HYDRALISK_HEALTH);
      break;

    case 3:
      curZerg = new Mutalisk("Mutalisk",MUTALISK_HEALTH);
      break;
  }
  return curZerg;
}

//Allows character to heal
void Game::Rest(){
  if (m_curZerg != nullptr){
    cout << "You cannot rest with a zerg in the area." << endl;

  }else if (m_numRests == 0){
    cout << "You are out of rests" << endl;

  }else{
   cout << "You rest and wake up refreshed" << endl;
   m_myTerran->SetHealth(m_myTerran->GetHealth() + REST_HEAL);
   m_numRests--;
  }
}

//Allows character to move between stages
void Game::Move(){
  string direction;
  int newID = 0;

  do{
    cout << "Which direction? (N E S W)" << endl;
    cin >> direction;

    if (direction == "N" || direction == "n"){
      newID = m_myMap[m_curArea]->CheckDirection(N);
    }else if (direction == "E" || direction == "e"){
      newID = m_myMap[m_curArea]->CheckDirection(E);
    }else if (direction == "S" || direction == "s"){
      newID = m_myMap[m_curArea]->CheckDirection(S);
    }else if (direction == "W" || direction == "w"){
      newID = m_myMap[m_curArea]->CheckDirection(W);
    }

    if(newID == -1){
      cout << "You bonked your head against an invisible wall! Owie! -.-" << endl;
    }

  }while(newID == -1);

  m_curArea = newID;

  //Create Zerg for new stage
  delete m_curZerg;
  m_curZerg = nullptr;
  m_curZerg = RandomZerg();

  m_myMap[m_curArea]->PrintArea();

  if (m_curZerg != nullptr){
    cout << *m_curZerg;
  }else{
    cout << "It is peaceful here" << endl;
  }

}

//Facilitates Engagement with Enemy
void Game::Attack(){
  int choice = 0;
  int dmg = 0;

  if(m_curZerg == nullptr){
    cout << "There is no enemy nearby!" << endl;
  }else{


    do{
      cout << "1. Normal Attack" << endl;
      cout << "2. Special Attack" << endl;
      cin >> choice;

      while(choice < 1 || choice > 2){
        cout << "Invalid Input! Try Again!" << endl;
        cin >> choice;
      }

      if (choice == 1){
        dmg = m_myTerran->Attack(); //Normal Attack
      }else{
        if (m_numSpecial > 0){
          dmg = m_myTerran->SpecialAttack(); //Special Attack
        }else{
        cout << "Out of Special Energy!" << endl;
        }
        m_numSpecial--;
      }
      m_curZerg->SetHealth(m_curZerg->GetHealth() - dmg);


      //AI decisions in fight
      int quarter = 4;
      if (rand() % quarter == 0){ //25% chance for normal/special attack
        dmg = m_curZerg->Attack();
      }else{
        dmg = m_curZerg->SpecialAttack();
      }
      m_myTerran->SetHealth(m_myTerran->GetHealth() - dmg);

      ProcessBattle(m_curZerg->GetHealth() > 0, m_myTerran->GetHealth() > 0); //Checks for winner of battle

    }while (m_myTerran->GetHealth() > 0 && m_curZerg->GetHealth() > 0);


    delete m_curZerg;
    m_curZerg = nullptr;
  }
}

//Displays player stats
void Game::Stats(){
  cout << "Name: " << m_myTerran->GetName() << endl;
  cout << "HP: " << m_myTerran->GetHealth() << endl;
  cout << "Rests: " << m_numRests << endl;
  cout << "Special: " << m_numSpecial << endl;
  cout << "Wins: " << m_wins << endl;
}

//Displays battle outcome
void Game::ProcessBattle(bool zergAlive, bool alive){
  if (not zergAlive){
    if(alive){
      cout << "You have defeated the " << m_curZerg->GetName() << endl;
      if (rand()%10 == 0){
        cout << "You have earned another rest action!" << endl;
        m_numRests++;
      }
      m_wins++;
    }else{
      cout << "You've killed each other! Great Job!" << endl;
    }
  }else if (not alive){
    cout << "You have been slain by " << m_curZerg->GetName() << endl;
  }else{
    cout << m_myTerran->GetName() << "'s Health:" << m_myTerran->GetHealth() << endl;
    cout << m_curZerg->GetName() << "'s Health:" << m_curZerg->GetHealth() << endl;
  }
}
