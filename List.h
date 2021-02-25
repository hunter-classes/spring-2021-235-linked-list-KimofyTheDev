#pragma once
#include "Node.h"

class List{
 private:
  Node *head;

 public:
  List();
  void insert(std::string data);
  std::string toString();
  void insert(int loc, std::string data);
  void remove(int loc);
  std::string get(int loc);
  ~List();

};
