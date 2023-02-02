#include "Game.cpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

int main(int argc, char *argv[]) {
  /*
  if( argc != 2) {
    cout << "This requires a map file to be loaded." << endl;
    cout << "Usage: ./proj4 proj4_map1.txt" << endl;
  }
  */

  cout << "Loading file: " << "proj4_map2.txt" << endl << endl;

  string mapName = "proj4_map2.txt";
  srand (time(NULL));
  Game g(mapName);
  g.StartGame();
  return 0;
}
