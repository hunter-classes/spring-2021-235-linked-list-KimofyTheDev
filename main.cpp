#include <iostream>

#include "List.h"
int main(int argc, char *argv[])
{

  List *l1 = new List();
  std::cout << l1->toString() << "\n";

  l1->insert("a");
  l1->insert("b");
  l1->insert("c");
  l1->insert("x");
  l1->insert("y");
  l1->insert("z");
  l1->insert(2,"I");
  std::cout << l1->toString() << "\n";
  l1->remove(2);
  std::cout << l1->toString() << "\n";
  std::cout << l1->get(3) << "\n";

  return 0;

}
