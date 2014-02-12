CXX = g++
CFLAGS= -I./include -I./SFML-2.1/include 
LDFLAGS= -L./SFML-2.1/lib -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-network
TARGET=C.A.N.D.Y.S.A.G.A.
OBJS=./src/

all: ${OBJS}
	${CXX} $^ -o ${TARGET} 

%.o,%.cpp:
	${CXX} -c ${CFLAGS} -o $@

clean:
	rm src/*.o
	rm bin/${TARGET}
