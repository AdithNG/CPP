#include "Song.h"
/**********
 * File: Song.cpp
 * Intended for Project 3: Music Player
 **********/

//Default Constructor
Song::Song(){
  m_title = "New Title";
  m_artist = "New Artist";
  m_year = 0;
  m_rank = 0;
  m_next = nullptr;
}

//Overloaded Constructor
Song::Song(string title, string artist, int year, int ranking){
  m_title = title;
  m_artist = artist;
  m_year = year;
  m_rank = ranking;
  m_next = nullptr;
}

//Getters
string Song::GetTitle(){
  return m_title;
}

string Song::GetArtist(){
  return m_artist;
}

int Song::GetYear(){
  return m_year;
}

int Song::GetRank(){
  return m_rank;
}

//Setters
void Song::SetTitle(string title){
  m_title = title;
}

void Song::SetArtist(string artist){
  m_artist = artist;
}

void Song::SetYear(int year){
  m_year = year;
}

void Song::SetRank(int ranking){
  m_rank = ranking;
}

//Getter
Song* Song::GetNext() {
  return m_next;
}

//Setter
void Song::SetNext(Song* song){
  m_next = song;
}


