#include <iostream>

#include "List.h"


List::List(){
  head = nullptr;

}

void List::insert(std::string data){
  Node *new_node = new Node(data);
  new_node->setNext(head);
  head=new_node;
  }

std::string List::toString(){
  Node *walker = head;
  std::string s = "";
  while (walker != nullptr){
    s = s + walker->getData() + "-->";
    walker = walker->getNext();

  }
  s=s+"nullptr";
  return s;
}

void List::insert(int loc, std::string data){
  if(loc == 0){
    insert(data);
    return;
  }
  if(loc < 0){
    return;
  }
  Node *new_node = new Node(data);
  Node *walker = head;
  for(int i = 0; walker != nullptr; i++){
    if(i == loc - 1){
      new_node -> setNext(walker -> getNext());
      walker -> setNext(new_node);
    }
    else{
      walker = walker -> getNext();
    }
  }
}

void List::remove(int loc){
  if (loc < 0){
    return;
  }
  if (loc == 0){
    head = head->getNext();
    return;
  }
  Node *walker = head;
  for (int i = 0; i < loc - 1; i++){
    if (walker -> getNext() -> getNext() == nullptr){
      return;
    }
     walker = walker -> getNext();
  }
  walker -> setNext(walker -> getNext() -> getNext());
}

std::string List::get(int loc){
  if(loc < 0){
    return "Out of Bounds, Number cannot be negative";
  }
  if(head == nullptr){
    return "Empty List";
  }
  Node *walker = head;
  for(int i = 0; i < loc; i++){
    if(walker -> getNext() == nullptr){
      return "Out of Bounds, Number is too high";
    }
    walker = walker -> getNext();
  }
  return walker -> getData();
}

List::~List(){
  Node *walker = head;
  while(walker != nullptr){
    Node *deleteme = walker;
    walker = walker -> getNext();
    delete deleteme;
  }
}
