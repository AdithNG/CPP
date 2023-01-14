#include "Playlist.h"
/**********
* File: Playlist.h
* Intended for Project 3: Music Player
**********/

//Default Constructor
Playlist::Playlist(){
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
}

//Overloaded Constructor
Playlist::~Playlist(){
  Song* curr = m_head;
  while (m_head != nullptr){
    curr = m_head->GetNext();
    delete m_head;
    m_head = curr;
    m_size--;
  }
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
}

//Inserts dynamically allocated Song at end of Playlist
void Playlist::AddSong(string title, string artist, int year, int ranking){
  Song *temp, *curr;
  temp = new Song(title, artist, year, ranking);
  curr = m_head;

  if (m_head == nullptr){
    m_head = temp;
  }else{
    while (curr->GetNext() != nullptr){
      curr = curr->GetNext();
    }
    curr->SetNext(temp);
  }
  m_tail = temp;
  m_size++;
}

//Returns Song at index
Song* Playlist::GetPlaylistDetails(int location){
  int counter = 0;
  Song *curr = m_head;

  while(curr != nullptr){
    if (counter == location){
      return curr;
    }
    curr = curr->GetNext();
    counter++;
  }
  return curr;
}

//Getter
int Playlist::Size(){
  return m_size;
}

//Plays song by removing it??
void Playlist::PlayAt(int location){
  Song *curr = m_head;
  Song *prev = m_head;
  int counter = 0;

  while(curr != nullptr){

    if(counter == location){

      if(counter == 0){
        m_head = curr->GetNext();
        cout << "Played: " << *curr << endl;
        delete curr;
        curr = nullptr;
        m_size--;
        return;

      }else{
        prev->SetNext(curr->GetNext());
        cout << "Played: " << *curr << endl;
        delete curr;
        curr = nullptr;
        m_size--;
        if (counter == m_size){
          m_tail = prev;
        }
        return;
      }
    }
    prev = curr;
    curr = curr->GetNext();
    counter++;
  }
}

//Getter
string Playlist::GetName() {
  return m_name;
}

//Updates name
string Playlist::UpdateName(){
  m_name = m_head->GetTitle() + " to " + m_tail->GetTitle();
  return m_name;
}


