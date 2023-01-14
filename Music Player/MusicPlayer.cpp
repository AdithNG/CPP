#include "MusicPlayer.h"
/**********
* File: MusicPlayer.cpp
* Intended for Project 3: Music Player
**********/

//Overloaded Constructor
MusicPlayer::MusicPlayer(){
  m_curr = 0;
}

//Destructor
MusicPlayer::~MusicPlayer(){
  for (unsigned int i = 0; i < m_songCatalog.size(); i++){
    delete m_songCatalog[i];
    m_songCatalog[i] = nullptr;
  }
  for (unsigned int i = 0; i < m_playList.size(); i++){
    delete m_playList[i];
    m_playList[i] = nullptr;
  }

}

void MusicPlayer::LoadCatalog(string filename){
  fstream inputStream;
  inputStream.open(filename);

  string title, artist, strYear, strRanking;
  int year, ranking;
  int counter = 0;

  if (inputStream.is_open()) { //Checks to see if the file exists and was opened

    while(getline(inputStream, title, DELIMITER) &&
	  getline(inputStream, artist, DELIMITER) &&
	  getline(inputStream, strYear, DELIMITER) &&
	  getline(inputStream, strRanking)
	  ){

      year = stoi(strYear);//Convert to int
      ranking  = stoi(strRanking);//Convert to int

      m_songCatalog.push_back(new Song(title, artist, year, ranking)); //Creates Song and stores in vector
      counter++;
    }
    cout << "Songs loaded: " << counter << endl;
  }else{
    cout << "Unable to open file"; //If the input file does not exist, notifies user
  }
  inputStream.close(); //Closes the file
}

//Main Menu Manager
void MusicPlayer::MainMenu(){

  int choice = 0;

  do{
    cout << "What would you like to do?:" << endl;
    cout << "1. Create New Playlist" << endl;
    cout << "2. Choose Playlist to Edit" << endl;
    cout << "3. Display Songs by Year" << endl;
    cout << "4. Add Song to Current Playlist" << endl;
    cout << "5. Display Current Playlist" << endl;
    cout << "6. Play Song" << endl;
    cout << "7. Quit" << endl;
    cin >> choice;

    while (choice < 1 || choice > 7 ){
      cout << "Enter a number from (1-7): ";
      cin >> choice;
    }

    switch(choice){

    case 1:
      InsertNewPlaylist();
      break;

    case 2:
      ChoosePlaylist();
      break;

    case 3:
      DisplaySongs();
      break;

    case 4:
      AddSong();
      break;

    case 5:
      DisplayPlaylist();
      break;

    case 6:
        PlaySong();
        break;
    }

  }while(choice != 7);

  cout << "Thank you for using the UMBC music player" << endl;
}

//Displays the songs for a particular year
void MusicPlayer::DisplaySongs(){

  int year = 0;

  cout << "Which year would you like to display? (2010-2021)" << endl;
  cin >> year;

  while (year < LOW_YEAR || year > HIGH_YEAR){
    cout << "Invalid input" << endl;
    cout << "Which year would you like to display? (2010-2021)" << endl;
    cin >> year;
  }

  cout << "******" << year << "*****" << endl;

  for (unsigned int i = 0; i < m_songCatalog.size(); i++){
    if (m_songCatalog[i]->GetYear() == year){
      cout << i+1 << ". " << *m_songCatalog[i] << endl;
    }
  }
}

//Adds song to playlist
void MusicPlayer::AddSong(){

  int num = 0;

  if (int(m_playList.size()) == 0){
    cout << "You have no playlists" << endl;
  }else{
    if (not m_playList[m_curr]->Size()){
      cout << "***Current Playlist is Empty***" << endl;
    }

    cout << "Choose the songs you would like to add to the playlist." << endl;
    DisplaySongs();

    cout << "Enter the number of the song you would like to add:" << endl;
    cin >> num;

    while (num < 1 || num > int(m_songCatalog.size())){
      cout << "Invalid input" << endl;
      cout << "Enter the number of the song you would like to add:" << endl;
      cin >> num;
    }

    Song* song = m_songCatalog[num-1];
    m_playList[m_curr]->AddSong(song->GetTitle(), song->GetArtist(), song->GetYear(), song->GetRank());
    m_playList[m_curr]->UpdateName();
  }
}

//Displays songs in playlist
void MusicPlayer::DisplayPlaylist(){
  cout << "Your Playlist" << endl;
  if (int(m_playList.size()) == 0){
    cout << "You have no playlists" << endl;
  }else{
    if (m_playList[m_curr]->Size() == 0){
      cout << "The playlist is currently empty" << endl;
    }
    for (int i = 0; i < m_playList[m_curr]->Size(); i++){
      cout << i+1 << ". " << *(m_playList[m_curr]->GetPlaylistDetails(i)) << endl;
    }
  }
}

//Plays song and deletes it??
void MusicPlayer::PlaySong(){
  int choice = 0;

  if (int(m_playList.size()) == 0){
    cout << "You have no playlists" << endl;
  }else{
    DisplayPlaylist();

    if (m_playList[m_curr]->Size() != 0){
      cout << "Which song would you like to play?" << endl;
      cin >> choice;

      while (choice < 1 || choice > m_playList[m_curr]->Size()){
        cout << "Invalid Input" << endl;
        cout << "Which song would you like to play?" << endl;
        cin >> choice;
      }
      m_playList[m_curr]->PlayAt(choice-1);
      if (m_playList[m_curr]->Size() > 0){
        m_playList[m_curr]->UpdateName();
      }
    }
  }
}

void MusicPlayer::InsertNewPlaylist(){
  string choice;
  int temp = 0;
  Playlist* playlist = new Playlist();
  m_playList.push_back(playlist);

  temp = m_curr;
  m_curr = m_playList.size()-1;

  do{
    AddSong();
    cout << "Add More? (y/n)" << endl;
    cin >> choice;
  }while(choice == "y");

  m_playList[m_playList.size()-1]->UpdateName();
  m_curr = temp;
}

void MusicPlayer::ChoosePlaylist(){
  int choice;

  cout << "Your Playlists" << endl;
  for (int i = 0; i < int(m_playList.size()); i++){
    cout << i+1 << ". " << m_playList[i]->GetName() << endl;
  }
  if (int(m_playList.size()) == 0){
    cout << "You dont have any playlists" << endl;
  }else{
    do{
      cout << "Which playlist do you want to edit?" << endl;
      cin >> choice;
    }while(choice < 1 || choice > m_playList.size());

    m_curr = choice-1;
  }
}
