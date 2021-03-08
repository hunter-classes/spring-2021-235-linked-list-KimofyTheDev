#pragma once
#include "dnode.h"
#include <string>

class Dlist{
private:
	Dnode *head;
	Dnode *tail;
	Dnode *cur;
	int size;
	int index;

public:
	Dlist();
	~Dlist();
	std::string toString();
	void insert(std::string data);
	void insert(int loc, std::string data);
	void remove(int loc);
	std::string get(int loc);
	Dnode *getNode(int l);
};
