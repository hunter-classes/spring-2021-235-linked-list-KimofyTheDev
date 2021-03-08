#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "List.h"
#include "dlist.h"

List *l = new List();

TEST_CASE("Insert"){
	CHECK(l->toString() == "nullptr"); //Confirms base senario
	l->insert("Two");
	CHECK(l->toString() == "Two-->nullptr");
	l->insert(0,"Zero");
	CHECK(l->toString() == "Zero-->Two-->nullptr");
	l->insert(1,"One");
	CHECK(l->toString() == "Zero-->One-->Two-->nullptr");
	l->insert(3,"Three");
	CHECK(l->toString() == "Zero-->One-->Two-->Three-->nullptr");
	l->insert(-4,"Neg");//should fail/do nothing
	CHECK(l->toString() == "Zero-->One-->Two-->Three-->nullptr");
	l->insert(10,"Neg");//should fail/do nothing
	CHECK(l->toString() == "Zero-->One-->Two-->Three-->nullptr");
}

TEST_CASE("Remove"){
	l->remove(-10);//removed out of bound
	CHECK(l->toString() == "Zero-->One-->Two-->Three-->nullptr");
	l->remove(2);//working remove
	CHECK(l->toString() == "Zero-->One-->Three-->nullptr");
	l->remove(3);//remove on index of nullptr
	CHECK(l->toString() == "Zero-->One-->Three-->nullptr");
	l->remove(5);//remove past nullprt(out of bound)
}

TEST_CASE("Get"){
	CHECK(l->get(-100) == "Out of Bounds, Number cannot be negative");
	CHECK(l->get(3) == "Out of Bounds, Number is too high");
	CHECK(l->get(0) == "Zero");
	CHECK(l->get(1) == "One");
}

Dlist *dlist = new Dlist();

TEST_CASE("Insert"){
	CHECK(dlist->toString() == "head--><--tail");
	dlist->insert(0,".");
	CHECK(dlist->toString() == "head-->.<--tail");
	dlist->insert(1,"a");
	CHECK(dlist->toString() == "head-->.<-->a<--tail");
	dlist->insert(2,"b");
	CHECK(dlist->toString() == "head-->.<-->a<-->b<--tail");
}

TEST_CASE("Basic Insert"){
	dlist->insert("c");
	CHECK(dlist->toString() == "head-->.<-->a<-->b<-->c<--tail");
	dlist->insert("d");
	CHECK(dlist->toString() == "head-->.<-->a<-->b<-->c<-->d<--tail");
}

TEST_CASE("Remove"){
	dlist->remove(0);
	CHECK(dlist->toString() == "head-->a<-->b<-->c<-->d<--tail");
	dlist->remove(2);
	CHECK(dlist->toString() == "head-->a<-->b<-->d<--tail");
	dlist->remove(1);
	CHECK(dlist->toString() == "head-->a<-->d<--tail");
}

TEST_CASE("Get"){
	dlist->insert("1");
	dlist->insert("2");
	dlist->insert("3");
	dlist->insert("4");
	CHECK(dlist->get(1) == "d");
	CHECK(dlist->get(2) == "1");
	CHECK(dlist->get(3) == "2");
	CHECK(dlist->get(4) == "3");
	dlist->remove(5);
	dlist->remove(4);
	dlist->remove(3);
	dlist->remove(2);
}

TEST_CASE("Out of Bounds"){
	dlist->insert(-10,"a");
	CHECK(dlist->toString() == "head-->a<-->d<--tail");
	dlist->insert(10,"a");
	CHECK(dlist->toString() == "head-->a<-->d<--tail");
	dlist->remove(-10);
	CHECK(dlist->toString() == "head-->a<-->d<--tail");
	dlist->remove(10);
	CHECK(dlist->toString() == "head-->a<-->d<--tail");
	CHECK(dlist->get(-10) == "Out of Bounds");
	CHECK(dlist->get(10) == "Out of Bounds");
}

TEST_CASE("Border Interactions"){
	dlist->insert(2,"e");
	CHECK(dlist->toString() == "head-->a<-->d<-->e<--tail");
	dlist->insert(0,".");
	CHECK(dlist->toString() == "head-->.<-->a<-->d<-->e<--tail");
	dlist->remove(0);
	CHECK(dlist->toString() == "head-->a<-->d<-->e<--tail");
	dlist->remove(2);
	CHECK(dlist->toString() == "head-->a<-->d<--tail");
	CHECK(dlist->get(0) == "a");
	CHECK(dlist->get(1) == "d");
}

TEST_CASE("Destructor"){
	dlist->~Dlist();
	CHECK(dlist->toString() == "head--><--tail");
}
