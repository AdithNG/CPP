#include "Navigator.h"
#include "Port.cpp"
#include "Route.cpp"
/**********
* File: Navigator.cpp
* Intended for Project 3: Container Ship Management
**********/

//Overloaded Constructor
Navigator::Navigator(string filename) {
  m_fileName = filename;
}

//Destructor
Navigator::~Navigator() {

  cout << "Deleting Ports" << endl;
  for (unsigned int i = 0; i < m_ports.size(); i++){
    delete m_ports[i];
    m_ports[i] = nullptr;
  }

  cout << "Deleting Routes" << endl;
  for (unsigned int i = 0; i < m_routes.size(); i++){
    delete m_routes[i];
    m_routes[i] = nullptr;
  }

}

//Starts the Program
void Navigator::Start() {
  ReadFile();
  MainMenu();
}

//Displays all Routes created
void Navigator::DisplayPorts() {
  for (unsigned int i = 0; i < m_ports.size(); i++){
    cout << i+1 << ". " << *m_ports[i] << endl;
  }
  cout << endl;
}

//Loads all Ports from file
void Navigator::ReadFile() {

  fstream inputStream;
  inputStream.open(m_fileName);

  string name, location, strNorth, strWest;
  double north, west;
  int counter;

  if (inputStream.is_open()) { //Checks to see if the file exists and was opened

    const int total = 36;

    cout << "Opened File" << endl;

    for (unsigned int i = 0; i < total; i++){

      getline(inputStream, name, ',');
      getline(inputStream, location, ',');
      getline(inputStream, strNorth, ',');
      getline(inputStream, strWest);

      north = stod(strNorth);//Convert to double
      west  = stod(strWest);//Convert to double

      m_ports.push_back(new Port(name, location, north, west)); //Creates Port and stores in vector
      counter++;
    }
    cout << "Ports loaded: " << counter << endl;
  }else{
    cout << "Unable to open file"; //If the input file does not exist, notifies user
  }
  inputStream.close(); //Closes the file
}

//Populates dynamically created route with user selected ports
void Navigator::InsertNewRoute() {
  int choice;

  Route *route = new Route();

  while (choice != -1){
    cout << "Enter the number of the port to add to your Route: (-1 to end)" << endl;
    cin >> choice;

    while ((choice < 1 or choice > (int)m_ports.size()) and choice != -1){
      cout << "Unable to find port" << endl;
      cout << "Enter again!" << endl;
      cin >> choice;
    }
    if (choice != -1){
      route->InsertEnd(m_ports[choice-1]->GetName(), m_ports[choice-1]->GetLocation(), m_ports[choice-1]->GetNorth(), m_ports[choice-1]->GetWest()); // Insert port at end of route
    }
  }
  route->UpdateName(); // Updates name of route
  m_routes.push_back(route); // Stores route in vector

  cout << "Done building a new route named " << route->GetName() << endl;
}

// Main menu manager
void Navigator::MainMenu() {

  int choice;

  do{
    cout << "What would you like to do?:" << endl;
    cout << "1. Create New Route" << endl;
    cout << "2. Display Route" << endl;
    cout << "3. Remove Port From Route" << endl;
    cout << "4. Reverse Route" << endl;
    cout << "5. Exit" << endl;
    cin >> choice;

    while (choice < 1 || choice > 5 ){
      cout << "Enter a number from (1-5): ";
      cin >> choice;
    }

    switch(choice){

    case 1:
      DisplayPorts();
      InsertNewRoute();
      break;

    case 2:
      DisplayRoute();
      break;

    case 3:
      RemovePortFromRoute();
      break;

    case 4:
      ReverseRoute();
      break;

    case 5:
      cout << "Routes removed from memory" << endl;

    }
  }while(choice != 5);
}

//Returns User selected index for route
int Navigator::ChooseRoute() {
  int choice;
  cin >> choice;

  while (choice < 1 or choice > (int)m_routes.size()){
    cout << "Unable to find route! Try again!" << endl;
    cin >> choice;
  }

  return choice;
}

//Displays Route details
void Navigator::DisplayRoute() {
  int index;

  if (m_routes.size() > 0){
    cout << "Which Route would you like to use?" << endl;

    for (unsigned int i = 0; i < m_routes.size(); i++){
      cout << i+1 << ". " << m_routes[i]->GetName() << endl;
    }

    index = ChooseRoute() - 1;
    Route *route = m_routes[index];

    cout << route->GetName() << endl;
    m_routes[index]->DisplayRoute();

    cout << "The total miles of this route is " << RouteDistance(route) << " miles" << endl;

  }else{
    cout << "There are no routes to display!" << endl;
  }
}

//Removes Port from route base on user input
void Navigator::RemovePortFromRoute() {
  int index1, index2;

  if (m_routes.size() > 0){
    cout << "Which Route would you like to use?" << endl;

    for (unsigned int i = 0; i < m_routes.size(); i++){
      cout << i+1 << ". " << m_routes[i]->GetName() << endl;
    }

    index1 = ChooseRoute() - 1;
    Route *route = m_routes[index1];

    if (route->GetSize() > 2){
      cout << route->GetName() << endl;
      m_routes[index1]->DisplayRoute();


      cout << "Which port would you like to remove?" << endl;
      cin >> index2;

      route->RemovePort(index2-1);
      m_routes[index1]->DisplayRoute();

      route->UpdateName();
      cout << "Route named " << route->GetName() << " updated" << endl;
    }else{
      cout << "Access Denied: Port Size must be greater than 2 " << endl;
    }

  }else{
    cout << "You have no routes!" << endl;
  }
}

//Calculates Total distance of route
double Navigator::RouteDistance(Route *route) {
  double total = 0;

  for (int i = 0; i < route->GetSize() - 1; i++) {

    total += CalcDistance(route->GetData(i)->GetNorth(), route->GetData(i)->GetWest(), route->GetData(i+1)->GetNorth(), route->GetData(i+1)->GetWest());
  }

  return total;
}

//Reverses direction of route
void Navigator::ReverseRoute() {
  int index;

  if (m_routes.size() > 0){

    cout << "Which Route would you like to use?" << endl;

    for (unsigned int i = 0; i < m_routes.size(); i++){
      cout << i+1 << ". " << m_routes[i]->GetName() << endl;
    }

    index = ChooseRoute() - 1;
    Route *route = m_routes[index];

    route->ReverseRoute(); // Reverses Ports in given route
    route->UpdateName(); // Updates name of route

    cout << "Done reversing Route " << index + 1 << endl;

  }else{
    cout << "You don't have any routes to reverse!" << endl;
  }
}
