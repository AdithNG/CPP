//Title: proj3.cpp
//Author: Adith Nishanth Gunaseelan
//Date: 10/5/2022
//Description: This is part of the project 3
//This is the music player that holds a music catalog and allows the user to build a playlist

#include <iostream>
#include "MusicPlayer.cpp" //Loads the MusicPlayer
//#include "Playlist.h" //Loads the Playlist
//#include "Song.h" //Loads the Songs

//Takes in an argument when you call this program
//For example, if you type ./proj3 proj3_music.txt it will automatically pass proj3_music.txt in
//as argv[1]. So it is required.
int main (int argc, char* argv[]) {
  string musicFile;
  cout << "Welcome to UMBC Music Player"<< endl;
  /*
  if(argc > 1){
    musicFile = argv[1]; //stores the first argument as musicFile
  } else{
    cout << "One music files required - try again" << endl;
    cout << "./proj3 proj3_music.txt" << endl;
    return 0;
  }
  */
  musicFile = "proj3_music.txt";
  MusicPlayer* myMusic = new MusicPlayer(); //Dynamically allocates a new music player
  myMusic->LoadCatalog(musicFile); //Loads the catalog
  myMusic->MainMenu(); //Calls MainMenu
  delete myMusic; //Deallocates the music player
  return 0;
}
