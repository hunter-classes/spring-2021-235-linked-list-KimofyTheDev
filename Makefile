OBJECTS= List.o Node.o dnode.o dlist.o
CXX=g++

main: main.o $(OBJECTS)
	$(CXX) -o main main.o $(OBJECTS)

test: test.o $(OBJECTS)
	$(CXX) -o test test.o $(OBJECTS)

test.o: test.cpp List.h

main.o: main.cpp List.h

List.o: List.cpp List.h Node.h

Node.o: Node.cpp Node.h

dnode.o: dnode.cpp dnode.h

dlist.o: dlist.cpp dlist.h

clean:
	rm -f $(OBJECTS) main.o test.o
