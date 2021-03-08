#include <string>
#include "dnode.h"

Dnode::Dnode(){
    next = nullptr;
    prev = nullptr;
}

Dnode::Dnode(std::string data){
    this->data = data;
    next = nullptr;
    prev = nullptr;
}

Dnode::Dnode(std::string data, Dnode *next, Dnode *prev){
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}

Dnode::~Dnode(){
    next = nullptr;
    delete next;
    prev = nullptr;
    delete prev;
    data = "";
}

void Dnode::setNext(Dnode *next){
    this->next = next;
}

void Dnode::setPrev(Dnode *prev){
    this->prev = prev;
}

void Dnode::setData(std::string data){
    this->data = data;
}

Dnode *Dnode::getNext(){
    return next;
}

Dnode *Dnode::getPrev(){
    return prev;
}

std::string Dnode::getData(){
    return data;
}
