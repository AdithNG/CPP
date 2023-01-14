//Title: MusicPlayer.h
//Author: Adith Gunaseelan
//Date: 10/5/2022
//Description: This is part of the project 3
//This is the music player that holds a music catalog and allows the user to build a playlist

#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
//#include "Song.cpp"
#include "Playlist.cpp"

using namespace std;

//Constants
const int LOW_YEAR = 2010; //First year of music catalog
const int HIGH_YEAR = 2021; //Last year of music catalog
const string FILE_NAME = "proj3_music.txt"; //Default input file
const char DELIMITER = '|'; //Default delimiter for the input file

class MusicPlayer{
 public:
  //Name: MusicPlayer - Default Constructor
  //Precondition: None
  //Postcondition: Dynamically creates a new MusicPlayer and populates m_filename FILE_NAME
  MusicPlayer();
  //Name: ~MusicPlayer - Destructor
  //Precondition: None
  //Postcondition: Destructs all songs in the catalog and all songs in the playlist
  ~MusicPlayer();
  //Name: LoadCatalog(string filename)
  //Precondition: Requires filename
  //Postcondition: Loads the file of songs into the m_songCatalog (as song objects) using the DELIMITER
  void LoadCatalog(string filename);
  //Name: MainMenu
  //Precondition: None
  //Postcondition: Manages the application and the menu. Calls until user chooses to quit.
  void MainMenu();
  //Name: DisplaySongs
  //Precondition: User enters year using constants above (2010-2021)
  //Postcondition: Lists all songs (numbered) for that year by ranking
  void DisplaySongs();
  //Name: AddSong
  //Precondition: m_songCatalog is populated and m_playList exists
  //Postcondition: Displays the songs for a specific year. Adds a song to the m_playList by dynamically allocating a new song based on the song in the catalog
  //               and inserting it in the end.
  //               May have duplicate songs on a playlist.
  //               If the user chooses 2010, the user does not have to choose something from 2010 but it does need to be valid (between 1 - 1200)
  void AddSong();
  //Name: DisplayPlaylist
  //Precondition: None (can be empty)
  //Postcondition: Displays the playlist or tells the user it is empty
  void DisplayPlaylist();
  //Name: PlaySong
  //Precondition: Playlist should be populated
  //Postcondition: Allows the user to choose a song from the playlist to play.
  //               Removes chosen song from playlist after "played"
  void PlaySong();
  // Name: InsertNewPlaylist
  // Desc: Dynamically allocates a new playlist with the user selecting each song in the playlist.
  //       Playlist named based on the first and last song automatically
  //       Once playlist is created, inserted into m_playlist.
  // Preconditions: Populated m_playlist
  // Postconditions: Inserts a new playlist into m_playlist
  void InsertNewPlaylist();
  // Name: ChoosePlaylist
  // Desc: Allows user to choose a specific Playlist to work with by displaying numbered list
  // Preconditions: Populated m_Playlist
  // Postconditions: Returns the index of the selected playlist
  void ChoosePlaylist();
 private:
  vector<Song*> m_songCatalog; //Holds all songs in input file as songs
  vector<Playlist*> m_playList; //Holds all songs in play list
  int m_curr; // index of current playlist
};


#endif
