CXX = g++ -std=c++0x -Wall
TARGET=CandySaga
OBJDIR=obj
SRCDIR=src
INCDIR=include
CFLAGS= -I$(INCDIR) -I./SFML-2.1/include 
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
