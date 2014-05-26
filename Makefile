CXX = g++ 
TARGET=CandySaga
OBJDIR=obj
SRCDIR=src
INCDIR=include
CFLAGS= -I$(INCDIR) -I./SFML-2.1/include -std=c++0x -Wall -g -ggdb
LDFLAGS= -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-network -lm
DEPS=
OBJFILES=CandyGame.o CandyMainMenu.o CandyBody.o CandyMath.o main.o CandyGameState.o CandyWorld.o CandyActor.o CandySettingsMenu.o CandyShip.o CandyPlay.o CandyPause.o CandyTextureManager.o CandyBullet.o CandyBonus.o CandyTeam.o CandyWeapon.o CandyBasicWeapon.o CandySettings.o CandyMeasureBar.o CandyAsteroid.o
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
