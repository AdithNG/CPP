#include "Navigator.cpp"
#include <iostream>
using namespace std;

int main (int argc, char* argv[]) {
  if (argc < 2)
    {
     // cout << "You are missing a data file." << endl;
     // cout << "Expected usage ./proj3 proj3_data.txt" << endl;
     // cout << "File 1 should be a file with ports" << endl;
     cout << endl << "***Navigator***" << endl << endl;
      Navigator S = Navigator("proj3_data.txt");
      S.Start();
    }
  else
    {
      cout << endl << "***Navigator***" << endl << endl;
      Navigator S = Navigator("proj3_data.txt");
      S.Start();
    }
  return 0;
}
