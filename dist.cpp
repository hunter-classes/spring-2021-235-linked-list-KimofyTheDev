#include "dlist.h"

Dlist::Dlist(){
	head = nullptr;
	tail = nullptr;
	cur = nullptr;
	index = 0;
	size = 0;
}

Dlist::~Dlist(){
	Dnode *temp;
	while(head != nullptr){
		temp = head;
		head = head->getNext();
		size = 0;
		index = 0;
		delete temp;
	}
}

std::string Dlist::toString(){
	if(size == 0){
		return "head--><--tail";
	}
	std::string ans = "";
	Dnode *walker = head;
	while(walker->getNext() != nullptr){
		ans += walker->getData() + "<-->";
		walker = walker->getNext();
	}
	return "head-->" + ans + walker->getData() +"<--tail";
}
void Dlist::insert(std::string data){
	Dnode *node = new Dnode(data);
	if(size == 0){
		head->setData(data);
		cur = head;
	}
	else{
		cur->setNext(node);
		cur->getNext()->setPrev(cur);
		cur = node;
		tail = node;
	}
	size++;
}

void Dlist::insert(int loc, std::string data){
    if(loc > size || loc < 0){
        return;
    }
    if(loc == 0){
        Dnode *node = new Dnode (data);
        if(size == 0){
            tail = node;
        }
        else{
            node->setNext(head);
            head->setPrev(node);
        }
        head = node;
        index = 0;
        size++;
        return;
    }
    Dnode *walker = getNode(loc-1);
    Dnode *node = new Dnode(data);
    if(walker->getNext() != nullptr){
        walker->getNext()->setPrev(node);
        node->setNext(walker->getNext());
    }
    else{
        tail = node;
    }
    walker->setNext(node);
    node->setPrev(walker);
    cur = node;
    index = loc+2;
    size++;
}
void Dlist::remove(int loc){
    if(loc < 0 || loc > size){
        return;
    }
    Dnode *walker = getNode(loc);
    if(loc == 0){
        head = head->getNext();
    }
    else if(loc == size-1){
        tail = walker->getPrev();
        tail->setNext(nullptr);
        cur = tail;
        index = size - 1;
    }
    else{
        walker->getPrev()->setNext(walker->getNext());
        walker->getNext()->setPrev(walker->getPrev());
        cur = walker->getNext();
        index = loc;
    	delete walker;
    }
    size--;
}
std::string Dlist::get(int loc){
    if(loc < 0 || loc > size - 1){
    	return "Out of Bounds";
    }
    return getNode(loc)->getData();
}

Dnode *Dlist::getNode(int loc){
	if(loc == 0){
		cur = head;
    }
	else if(loc <= size/2){
		cur = head;
		for(int i = 0; i != loc; i++){
			cur = cur->getNext();
		}
	}
	else if(loc > size/2){
		cur = tail;
		for(int i = size-1; i != loc; i--){
			cur = cur->getPrev();
		}
	}
	return cur;
}
