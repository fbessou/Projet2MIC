CXX = g++ 
TARGET=CandySaga
OBJDIR=obj
SRCDIR=src
INCDIR=include
CFLAGS= -I$(INCDIR) -I./SFML-2.1/include -std=c++0x -Wall -g -ggdb
LDFLAGS= -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-network
DEPS=
OBJFILES=CandyGame.o CandyMainMenu.o CandyBody.o CandyMath.o main.o CandyGameState.o
OBJ=$(patsubst %,$(OBJDIR)/%,$(OBJFILES))

all: $(TARGET)
test:
	make -C tests
$(TARGET): $(OBJ)
		$(CXX) -o $@ $^ $(CFLAGS) $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
		$(CXX) -c -o $@ $< $(CFLAGS) 


.PHONY: clean

clean:
		rm -f $(OBJDIR)/*.o *~ 
