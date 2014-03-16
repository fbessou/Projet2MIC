CXX = g++ 
TARGET=CandySaga
OBJDIR=obj
SRCDIR=src
INCDIR=include
CFLAGS= -I$(INCDIR) -I./SFML-2.1/include -std=c++0x -Wall -g -ggdb
LDFLAGS= -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-network
DEPS=
OBJFILES=CandyGame.o CandyMainMenu.o CandyBody.o CandyMath.o main.o CandyGameState.o CandyWorld.o CandyActor.o
OBJ=$(patsubst %,$(OBJDIR)/%,$(OBJFILES))

all: $(TARGET)
test:
	make -C tests
$(TARGET): $(OBJ)
		@tput setaf 3
		@echo "[ Linking $^ ]"
		@tput sgr 0
		@$(CXX) -o $@ $^ $(CFLAGS) $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
		@tput setaf 2
		@echo "[ Compiling $^ ]"
		@tput sgr 0
		@tput setaf 1
		@$(CXX) -c -o $@ $< $(CFLAGS)  || tput sgr 0


.PHONY: clean

clean:
		rm -f $(OBJDIR)/*.o *~
