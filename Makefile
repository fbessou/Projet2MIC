CXX = g++
TARGET=CandySaga
OBJDIR=obj
SRCDIR=src
INCDIR=include
CFLAGS= -I$(INCDIR) -I./SFML-2.1/include 
LDFLAGS= -L./SFML-2.1/lib -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-network
DEPS=
OBJFILES=a.o
OBJ=$(patsubst %,$(OBJDIR)/%,$(OBJFILES))

all: $(TARGET)

$(TARGET): $(OBJ)
		$(CXX) -o $@ $^ $(CFLAGS) $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
		$(CXX) -c -o $@ $< $(CFLAGS) 


.PHONY: clean

clean:
		rm -f $(OBJDIR)/*.o *~ 
