CXX=g++ -std=c++11 -Wall
INCDIR=../include
CFLAGS= -I$(INCDIR)
OBJDIR=../obj
	#collisions
all: vectors 

vectors: vectors.o $(OBJDIR)/CandyMath.o
	$(CXX) -o $@ $^ $(CFLAGS) $(LDFLAGS)

vectors.o: vectors.cpp
		$(CXX) -c -o $@ $< $(CFLAGS) 

collision : collision.o
	$(CXX) $^ ../obj/* -o $@
collision.o: collisions.cpp
	$(CXX) -c $< -o $@

	
