CC = g++
Flags = -std=c++14 - Wall - g
OBJS = 

all: hw07

hw07: hw07.cpp ManageInventory.o
	$(CC)$(FLAGS)hw07.cpp -o hw07 $(OBJS)
	
ManageInventory.o: ManageInventory.cpp ManageInventory.h
	$(CC)$(FLAGS) -c ManageInventory.cpp -o ManageInventory.o

clean:
	rm*.o hw07 hw07.tar

tar:
	tar cf hw07.tar hw07.scr makefile hw07.cpp
