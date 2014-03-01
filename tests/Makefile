CXX=g++ -std=c++11 -Wall
INCDIR=../include
CFLAGS= -I$(INCDIR)
OBJDIR=../obj
LDFLAGS=
SFMLFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
	#collisions
all: vectors sfml

vectors: vectors.o $(OBJDIR)/CandyMath.o
	$(CXX) -o $@ $^ $(CFLAGS) $(LDFLAGS)

vectors.o: vectors.cpp
		$(CXX) -c -o $@ $< $(CFLAGS) 

sfml: sfml.cpp
	$(CXX) -o $@ $^ $(CFLAGS) $(SFMLFLAGS)

collision : collision.o
	$(CXX) $^ ../obj/* -o $@
collision.o: collisions.cpp
	$(CXX) -c $< -o $@

	
