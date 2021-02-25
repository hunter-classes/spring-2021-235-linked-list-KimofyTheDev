#include <iostream>
#include "List.h"

List::List()
{
  head = nullptr;
}

void List::insert(std::string data)
{
  Node *new_node = new Node(data);
  new_node->setNext(head);
  head=new_node;
  }

std::string List::toString()
{
  Node *walker = head;
  std::string s = "";
  while (walker != nullptr)
  {
    s = s + walker->getData() + "-->";
    walker = walker->getNext();

  }
  s=s+"nullptr";
  return s;
}

void List::insert(int loc, std::string data)
{
  Node *new_node = new Node(data);
  Node *walker = head;
  if (loc != 0)
  {
    for (int i = 1; i < loc; i++)
    {
      walker = walker->getNext();
    }
    Node *insert_node = new Node(data);
    insert_node->setNext(walker->getNext());
    walker->setNext(insert_node);
  }
  else
  {
    new_node->setNext(head);
    head=new_node;
  }
}

void List::remove(int loc)
{
  Node *new_node = new Node();
  Node *walker = head;
  if (loc != 0)
  {
    for (int i = 1; i < loc; i++)
    {
      walker = walker->getNext();
    }
    walker->setNext(walker->getNext()->getNext());
  }
  else
  {
    new_node->setNext(head);
    head=new_node;
  }
}

std::string List::get(int loc){
  Node *walker = head;
  int count = 0;
  for (int i = 1; i < loc; i++)
  {
    walker = walker->getNext();
  }
  return walker->getData();
}

List::~List()
{
  Node *walker = head;
  Node *tempNode = new Node();
  while(walker != NULL)
  {
    tempNode = walker->getNext();
    delete walker;
    walker = tempNode;
  }
}
