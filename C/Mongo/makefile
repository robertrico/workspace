#gcc -o example4 example4.c $(pkg-config --cflags --libs libmongoc-1.0) 
OBJ=insert.o find.o
CC=gcc
LIBS=`pkg-config --cflags --libs libmongoc-1.0`
CFLAGS=-w -g -Wall
EXE=insert

all: $(EXE)
$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)
find.o: find.c
	$(CC) $(CFLAGS) -c find.c $(LIBS)
insert.o: insert.c
	$(CC) $(CFLAGS) -c insert.c $(LIBS)
clean:
	rm $(OBJ)
