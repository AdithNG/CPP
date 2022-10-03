#include "Route.h"
//#include "Port.cpp"
/**********
* File: Route.cpp
* Intended for Project 3: Container Ship Management
**********/

//Default Constructor
Route::Route() {
  m_name = "Test";
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
}

//Setter
void Route::SetName(string name){
  m_name = name;
}

//Destructor
Route::~Route(){
  Port *curr = m_head;
  while(m_head != nullptr){
    curr = m_head->GetNext();
    delete m_head;
    m_head = curr;
  }
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
}

//Inserts dynamically allocated Port at end of route
void Route::InsertEnd(string name, string location, double north, double west){
  Port *temp, *curr;
  temp = new Port(name, location, north, west);
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

//Removes Port at given index
void Route::RemovePort(int port){
  Port *curr = m_head;
  Port *prev = m_head;
  int counter = 0;

  while(curr != nullptr){

    if(counter == port){

      if(counter == 0){
        m_head = curr->GetNext();
        delete curr;
        curr = nullptr;
	m_size--;
        return;

      }else{
        prev->SetNext(curr->GetNext());
        delete curr;
        curr = nullptr;
        if (counter == m_size -1){
          m_tail = prev;
        }
	m_size--;
        return;
      }

    }
    prev = curr;
    curr = curr->GetNext();
    counter++;
  }
}

//Getter
string Route::GetName() {
  return m_name;
}

//Updates name
string Route::UpdateName(){
  m_name = m_head->GetName() + " to " + m_tail->GetName();
  return m_name;
}

//Getter
int Route::GetSize(){
  return m_size;
}

//Reverses direction of route
void Route::ReverseRoute(){
  Port *prev, *curr, *next;
  prev = m_head;
  curr = prev->GetNext();
  next = curr->GetNext();
  prev->SetNext(nullptr);
  curr->SetNext(prev);
  m_tail = prev;
  while (next != nullptr)
    {
      prev = curr;
      curr = next;
      next = next->GetNext();
      curr->SetNext(prev);
    }
    m_head = curr;
}


//Returns port at index
Port* Route::GetData(int index){
  int counter = 0;
  Port *curr = m_head;

  while(curr != nullptr){
    if (counter == index){
      return curr;
    }
    curr = curr->GetNext();
    counter++;
  }
  return curr;
}


//Displays all Ports in route
void Route::DisplayRoute(){
  int counter = 0;
  Port *curr = m_head;
  while(curr != nullptr){
    cout << counter + 1 << ". " << *curr << " (N" << curr->GetNorth() << " W" << curr->GetWest() << ")" << endl;
    curr = curr->GetNext();
    counter++;
  }
}
