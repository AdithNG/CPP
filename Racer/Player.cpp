#include "Player.h"
/**********
* File: Player.cpp
* Intended for Project 2: Racer
**********/

//Default Constructor
Player::Player() {
  m_name = "Beannie";
  m_races = 0;
  m_wins = 0;
  m_falls = 0;
  for(int i = 0; i < NUM_STATS; i++){
    m_stat[i] = START_STAT;
  }
}

//Overloaded Constructor
Player::Player(string name){
  m_name = name;
  m_races = 0;
  m_wins = 0;
  m_falls = 0;
  for(int i = 0; i < NUM_STATS; i++){
    m_stat[i] = START_STAT;
  }
}

//Getter
string Player::GetName(){
  return m_name;
}

//setter
void Player::SetName(string name){
  m_name = name;
}

//Getter
int Player::GetSpeed(){
  return m_stat[0];
}

//Getter
int Player::GetAgility(){
  return m_stat[1];
}

//Getter
int Player::GetJump(){
  return m_stat[2];
}

//Getter
int Player::GetRaces(){
  return m_races;
}

//Getter
int Player::GetFalls(){
  return m_falls;
}

//Setter
void Player::SetRaces(int races){
  m_races = races;
}

//Setter
void Player::SetFalls(int falls){
  m_falls = falls;
}

//Displays User Information
void Player::DisplayStatus(){
  cout << "*****The Mighty Racer " << m_name << "**********" << endl;
  cout << "Races: " << m_races << endl;
  cout << "Wins: " << m_wins << endl;
  cout << "Falls: " << m_falls << endl;
  cout << endl;
  cout << "Stats" << endl;
  cout << "Speed: " << m_stat[0] << endl;
  cout << "Agility: " << m_stat[1] << endl;
  cout << "Jump: " << m_stat[2] << endl;
}

//Increases value of stat by 1
void Player::IncreaseStat(){
  int index = 0;
  do{
    cout << "Which stat would you like to increase?" << endl;
    cout << "1. Speed" << endl;
    cout << "2. Agility" << endl;
    cout << "3. Jump" << endl;
    cin >> index;
  }while(index < 1 || index > 3);

  if(m_stat[index-1] < MAX_STAT){
    m_stat[index-1]++;
  }
}

//Getter
int Player::GetStat(int stat){
  return m_stat[stat];
}

//Increases wins by 1
void Player::IncreaseWins(){
  m_wins++;
}
