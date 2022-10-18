#include "Track.h"
/**********
* File: Track.cpp
* Intended for Project 2: Racer
**********/

//Default Constructor
Track::Track(){
  m_length = DEFAULT_LENGTH;

  for (int i = 0; i < NUM_RACERS; i++){
    m_track[i] = 0;
  }
}

//Setter
void Track::SetLength(int length){
  m_length = length;
}

//Creates Obstacles
void Track::PopulateObstacles(){
  for (int i =0; i < MAX_LENGTH; i++){
    m_obstacle[i] = rand() % 3;
  }
}

//Getter
void Track::GetStatus(){
  for (int i = 0; i < NUM_RACERS; i++){
    if(i == 0){
      cout << "You are on a " << ConvertObstacle(i) << " obstacle (obstacle " << m_track[i]+1 << " of " << m_length << ")" << endl;
    }else{
      cout << "Player " << i << " is on a " << ConvertObstacle(i) << " obstacle (obstacle " << m_track[i]+1 << " of " << m_length << ")" << endl;
    }
  }
}

//Finds Winner
int Track::CheckWin(){
  for (int i = 0; i < NUM_RACERS; i++){
    if (m_track[i] == m_length){
      return i;
    }
  }
  return -1;
}

//Getter
int Track::GetObstacle(int location){
  return m_obstacle[location];
}

//increases location by 1
void Track::IncrementLocation(int player){
  m_track[player]++;
}

//Resests location to 0
void Track::ResetLocation(){
  for (int i = 0; i < NUM_RACERS; i++){
    m_track[i] = 0;
  }
}

//Conversts obstacle from int to string
string Track::ConvertObstacle(int player){
  return OBSTACLE_TYPE[m_obstacle[m_track[player]]];
}

