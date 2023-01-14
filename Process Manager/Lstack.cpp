#ifndef LSTACK_CPP
#define LSTACK_CPP
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
  T m_data; //Templated data for node
  Node<T>* m_next; //Templated node pointer to next node
};

//Overloaded constructor for Node
template <class T>
Node<T>::Node( const T& data ) {
   m_data = data;
   m_next = nullptr;
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
class Lstack {
 public:
  // Name: Lstack() (Linked List Stack) - Default Constructor
  // Desc: Used to build a new templated stack (as a linked list) m_head = top
  // Preconditions: None
  // Postconditions: Creates a new lstack where m_head points to nullptr and m_size = 0
  // Required
  Lstack();
  // Name: ~Lstack() - Destructor
  // Desc: Used to destruct a Lstack
  // Preconditions: There is an existing lstack with at least one node
  // Postconditions: An lstack is deallocated (including dynamically allocated nodes)
  //                 to have no memory leaks. (Allowed to use Clear in this function)
  // Required
 ~Lstack();
  // Name: Lstack (Copy Constructor)
  // Preconditions: Creates a copy of existing LStack
  //                Requires an existing Lstack
  // Hint: Make sure that the copy is not inverted
  // Postconditions: Copy of existing Lstack
  // Required
  Lstack(const Lstack&);
  // Name: operator= (Overloaded Assignment Operator)
  // Preconditions: Requires two Lstacks holding the same type of data
  //                After running, both stacks are identical with no memory loss
  //                Requires an existing Lstack
  // Postconditions: Two identical Lstack
  // Hint: Make sure that the destination Lstack has the same data in the same order as source
  // Required
  Lstack<T>& operator= (Lstack&);
  // Name: Push
  // Preconditions: Takes in data. Creates new node.
  //                Requires an existing Lstack
  // Postconditions: Adds a new node to the top of the lstack.
  // Required
  void Push(const T&);
  // Name: Pop
  // Preconditions: Requires an existing Lstack with at least one node
  // Postconditions: Removes top node in the lstack.
  // Assume that the Lstack has at least one node (Will check prior to call)
  // Required
  void Pop();
  // Name: Display
  // Preconditions: Outputs the lstack.
  // Postconditions: Displays the data in each node of lstack
  // Required (used only for testing lstack_test)
  void Display();
  // Name: Top
  // Preconditions: Requires an existing Lstack
  // Postconditions: Returns whatever data is on top
  // Required
  T Top();
  // Name: IsEmpty
  // Preconditions: Requires an existing Lstack
  // Postconditions: Returns true if the Lstack is empty else false.
  // Required
  bool IsEmpty();
  // Name: GetSize
  // Preconditions: Requires an existing Lstack
  // Postconditions: Returns m_size
  // Required
  int GetSize();
  // Name: Find()
  // Preconditions:  Requires an existing Lstack
  // Postconditions: Iterates and if it finds the thing, returns index, else -1
  // Required
  int Find(T&);
  // Name: Clear
  // Preconditions:  Requires an existing Lstack
  // Postconditions: Removes all nodes in Lstack
  // Required
  void Clear();
  // Name: At(int)
  // Preconditions:  Requires an existing Lstack
  // Postconditions: Returns the data at a specific index;
  //                 Index will be checked prior to call (assume int is valid)
  // Required
  T At (int x);
private:
  Node <T> *m_head; //Node pointer for the head
  int m_size; //Number of nodes in stack
};

//**********Implement Lstack Class Here***********
//**********All Functions Are Required Even If Not Used for Processor**************

//Default Constructor
template <class T>
Lstack<T>::Lstack(){
  m_head = nullptr;
  m_size = 0;
}

//Destructor
template <class T>
Lstack<T>::~Lstack(){
  Node<T>* curr = m_head;
  while (m_head != nullptr){
    curr = m_head->GetNext();
    delete m_head;
    m_head = curr;
    m_size--;
  }
  m_head = nullptr;
}

//Copy constructor
template <class T>
Lstack<T>::Lstack(const Lstack& lstack){

  m_size = 0;
  Node<T>* lscurr = lstack.m_head;

  Node<T>* mycurr = new Node<T>(lscurr->GetData());
  m_size++;

  m_head = mycurr;
  Node<T>* temp;

  //Copies node by node
  while (lscurr->GetNext() != nullptr){
    lscurr = lscurr->GetNext();
    temp = new Node<T>(lscurr->GetData());
    mycurr->SetNext(temp);
    mycurr = temp;
    m_size++;
  }

}

//Overloaded Assignment Operator
template <class T>
Lstack<T>& Lstack<T>::operator= (Lstack& other){

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

//Adds node to stack
template <class T>
void Lstack<T>::Push(const T& data){
  Node<T>* newNode = new Node<T>(data);
  if (m_head != nullptr){
    newNode->SetNext(m_head);
    m_head = newNode;
  }else{
    m_head = newNode;
  }
  m_size++;
}

//Removes first node from stack
template <class T>
void Lstack<T>::Pop(){
  Node<T>* curr = m_head;
  m_head = m_head->GetNext();
  delete curr;
  m_size--;
}

//Displays all Nodes
template <class T>
void Lstack<T>::Display(){
  Node<T>* curr = m_head;
  while (curr != nullptr){
    cout << curr->GetData() << "->";
    curr = curr->GetNext();
  }
  cout << "END" << endl;
}

//Returns data from first node
template <class T>
T Lstack<T>::Top(){
  return m_head->GetData();
}

//Checks if stack is empty
template <class T>
bool Lstack<T>::IsEmpty(){
  if (m_head == nullptr){
    return true;
  }
  return false;
}

//Returns size of stack
template <class T>
int Lstack<T>::GetSize(){
  return m_size;
}

//Finds node with data and returns index
template <class T>
int Lstack<T>::Find(T& data){
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

//Emptys stack
template <class T>
void Lstack<T>::Clear(){
  Node<T>* curr = m_head;
  while (m_head != nullptr){
    curr = m_head->GetNext();
    delete m_head;
    m_size--;
    m_head = curr;
  }
  m_head = nullptr;
}

//Returns data at index
template <class T>
T Lstack<T>::At (int x){
  int counter = 0;
  Node<T>* curr = m_head;

  while(counter != x){
    curr = curr->GetNext();
    counter++;
  }
  return curr->GetData();
}

#endif
