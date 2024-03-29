#ifndef LQUEUE_CPP
#define LQUEUE_CPP
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Templated node class used in templated linked list
template <class T>
class Node {
   public:
  Node( const T& data ); //Constructor
  T& GetData(); //Gets data from node
  void SetData( const T& data ); //Sets data in node
  Node<T>* GetNext(); //Gets next pointer
  void SetNext( Node<T>* next ); //Sets next pointer
private:
  T m_data;
  Node<T>* m_next;
};

//Overloaded constructor for Node
template <class T>
Node<T>::Node( const T& data ) {
   m_data = data;
   m_next = NULL;
}

//Returns the data from a Node
template <class T>
T& Node<T>::GetData() {
   return m_data;
}

//Sets the data in a Node
template <class T>
void Node<T>::SetData( const T& data ) {
   m_data = data;
}

//Gets the pointer to the next Node
template <class T>
Node<T>* Node<T>::GetNext() {
   return m_next;
}

//Sets the next Node
template <class T>
void Node<T>::SetNext( Node<T>* next ) {
   m_next = next;
}

template <class T>
class Lqueue {
 public:
  // Name: Lqueue() (Linked List Queue) - Default Constructor
  // Desc: Used to build a new linked queue (as a linked list)
  // Preconditions: None
  // Postconditions: Creates a new lqueue where m_head and m_tail point to nullptr
  // Required
  Lqueue();
  // Name: ~Lqueue() - Destructor
  // Desc: Used to destruct a Lqueue
  // Preconditions: There is an existing lqueue with at least one node
  // Postconditions: An lqueue is deallocated (including dynamically allocated nodes)
  //                 to have no memory leaks!
  // Required
 ~Lqueue();
  // Name: Lqueue (Copy Constructor)
  // Preconditions: Creates a copy of existing LQueue
  //                Requires a Lqueue
  // Postconditions: Copy of existing Lqueue
  // Required
  Lqueue(const Lqueue&);
  // Name: operator= (Overloaded Assignment Operator)
  // Preconditions: Copies an Lqueue into an existing Lqueue
  //                Requires a Lqueue
  // Postconditions: Copy of existing Lqueue
  // Required
  Lqueue<T>& operator= (Lqueue&);
  // Name: Push
  // Preconditions: Takes in data. Creates new node.
  //                Requires a Lqueue
  // Postconditions: Adds a new node to the end of the lqueue.
  // Required
  void Push(const T&);
  // Name: Pop
  // Preconditions: Lqueue with at least one node.
  // Postconditions: Removes first node in the lqueue, returns data from first node.
  // Required
  T Pop();
  // Name: Display
  // Preconditions: Outputs the lqueue.
  // Postconditions: Displays the data in each node of lqueue
  // Required (used only for testing)
  void Display();
  // Name: Front
  // Preconditions: Requires a populated lqueue
  // Postconditions: Returns whatever data is in front
  // Required
  T Front();
  // Name: IsEmpty
  // Preconditions: Requires a lqueue
  // Postconditions: Returns if the lqueue is empty.
  // Required
  bool IsEmpty();
  // Name: GetSize
  // Preconditions: Requires a lqueue
  // Postconditions: Returns m_size
  // Required
  int GetSize();
  // Name: Find()
  // Preconditions: Requires a lqueue
  // Postconditions: Iterates and if it finds the thing, returns index, else -1
  // Required
  int Find(T&);
  // Name: Swap(int)
  // Preconditions: Requires a lqueue
  // Postconditions: Swaps the nodes at the index with the node prior to it.
  // Required
  void Swap(int);
  // Name: Clear
  // Preconditions: Requires a lqueue
  // Postconditions: Removes all nodes in a lqueue
  // Required
  void Clear();
  // Name: At
  // Precondition: Existing Lqueue
  // Postcondition: Returns object from Lqueue at a specific location
  // Desc: Iterates to node x and returns data from Lqueue
  // Required
  T At (int x);
private:
  Node <T> *m_head; //Node pointer for the head
  Node <T> *m_tail; //Node pointer for the tail
  int m_size; //Number of nodes in queue
};

//**********Implement Lqueue Class Here***********
//**********All Functions Are Required Even If Not Used for Trivia**************

//Default Constructor
template <class T>
Lqueue<T>::Lqueue(){
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
}

//Destructor
template <class T>
Lqueue<T>::~Lqueue(){
  Node<T>* curr = m_head;
  while (m_head != nullptr){
    curr = m_head->GetNext();
    delete m_head;
    m_head = curr;
    m_size--;
  }
  m_head = nullptr;
  m_tail = nullptr;
}

//Copy constructor
template <class T>
Lqueue<T>::Lqueue(const Lqueue& lqueue){

  m_size = 0;
  Node<T>* lqcurr = lqueue.m_head;

  Node<T>* mycurr = new Node<T>(lqcurr->GetData());
  m_size++;

  m_head = mycurr;
  m_tail = mycurr;
  Node<T>* temp;

  //Copies node by node
  while (lqcurr->GetNext() != nullptr){
    lqcurr = lqcurr->GetNext();
    temp = new Node<T>(lqcurr->GetData());
    mycurr->SetNext(temp);
    mycurr = temp;
    m_tail = temp;
    m_size++;
  }

}

//Overloaded Assignment Operator
template <class T>
Lqueue<T>& Lqueue<T>::operator= (Lqueue& other){

  if (this != &other){
    Clear();

    this->Push((other.m_head)->GetData());
    Node<T>* curr = other.m_head;
    curr = curr->GetNext();

    while (m_size != other.m_size){

      this->Push(curr->GetData());
      curr = curr->GetNext();
    }
  }
  return *this;
}

//Adds node to queue
template <class T>
void Lqueue<T>::Push(const T& data){
  Node<T>* newNode = new Node<T>(data);
  if (m_tail != nullptr){
    m_tail->SetNext(newNode);
    m_tail = newNode;
  }else{
    m_head = newNode;
    m_tail = newNode;
  }
  m_size++;
}

//Removes first node from queue
template <class T>
T Lqueue<T>::Pop(){
  Node<T>* curr = m_head;
  T data = m_head->GetData();
  m_head = m_head->GetNext();
  delete curr;
  m_size--;

  return data;
}

//Displays all Nodes
template <class T>
void Lqueue<T>::Display(){
  Node<T>* curr = m_head;
  while (curr != nullptr){
    cout << curr->GetData() << "->";
    curr = curr->GetNext();
  }
  cout << "END" << endl;
}

//Returns data from first node
template <class T>
T Lqueue<T>::Front(){
  return m_head->GetData();
}

//Checks if queue is empty
template <class T>
bool Lqueue<T>::IsEmpty(){
  if (m_head == nullptr){
    return true;
  }
  return false;
}

//Returns size of queue
template <class T>
int Lqueue<T>::GetSize(){
  return m_size;
}

//Finds node with data and returns index
template <class T>
int Lqueue<T>::Find(T& data){
  int counter = 0;
  Node<T>* curr = m_head;

  while (curr != nullptr){
    if (curr->GetData() == data){
      return counter;
    }
    curr = curr->GetNext();
    counter++;
  }
  return -1;
}

//Swaps positions of 2 adjacent nodes in queue
template <class T>
void Lqueue<T>::Swap(int index){
  int counter = 0;
  Node<T>* prev2 = m_head;
  Node<T>* prev = m_head;
  Node<T>* curr = m_head;
  if (m_size > 1){
    if (index == 1){
      curr = curr->Getnext();
      prev->SetNext(curr->GetNext());
      curr->SetNext(prev);
      m_head = curr;

      if (m_size == 2)
	     m_tail = prev;

    }else{
      while (counter != index){
	prev2 = prev;
	prev = curr;
	curr = curr->GetNext();
	counter++;
      }
      prev2->SetNext(curr);
      prev->SetNext(curr->GetNext());
      curr->SetNext(prev);

      if (index == m_size)
	m_tail = prev;
    }
  }else{
    cout << "Denied: Not enough nodes to continue swap." << endl;
  }
}

//Emptys queue
template <class T>
void Lqueue<T>::Clear(){
  Node<T>* curr = m_head;
  while (m_head != nullptr){
    curr = m_head->GetNext();
    delete m_head;
    m_size--;
    m_head = curr;
  }
  m_head = nullptr;
  m_tail = nullptr;
}

//Returns data at index
template <class T>
T Lqueue<T>::At (int x){
  int counter = 0;
  Node<T>* curr = m_head;

  while(counter != x){
    curr = curr->GetNext();
    counter++;
  }
  return curr->GetData();
}

#endif
