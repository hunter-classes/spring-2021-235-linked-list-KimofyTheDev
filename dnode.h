#pragma once
#include <string>

class Dnode{
  private:
    std::string data;
    Dnode *next;
    Dnode *prev;
  public:
    Dnode();
    Dnode(std::string data);
    Dnode(std::string data, Dnode *next, Dnode *prev);
    ~Dnode();
    void setNext(Dnode *next);
    void setPrev(Dnode *prev);
    void setData(std::string data);
    Dnode *getNext();
    Dnode *getPrev();
    std::string getData();
};
