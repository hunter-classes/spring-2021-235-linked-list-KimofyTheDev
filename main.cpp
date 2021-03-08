#include <iostream>

#include "List.h"
#include "dlist.h"

int main(int argc, char *argv[]){
	List *l1 = new List();
	std::cout << l1->toString() << "\n";

	l1->insert("c");
	l1->insert("b");
	l1->insert("a");
	std::cout << l1->toString() << "\n";
	l1->~List();

	Dlist *dlist = new Dlist();

	std::cout << dlist->toString() << "\n";
	dlist->insert(0,".");
	dlist->insert(1,"1");
	dlist->insert(2,"2");
	std::cout << dlist->toString() <<  " and Element 3 is: " << dlist->get(3) << "\n";
	dlist->insert(3,"3");
	std::cout << dlist->toString() <<  " and Element 3 is now: " << dlist->get(3) << "\n";
	dlist->remove(2);
	std::cout << dlist->toString() <<  " Element 2 was removed, now its : " << dlist->get(2) << "\n";
	dl->~Dlist();

	return 0;
}
