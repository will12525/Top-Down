CC=g++
CFLAGS=-std=gnu++11 -c -g -Wall -Dmain=SDL_main
# Mac OS X Users: Remove -lmingw32 and remove  -w -Wl,-subsystem,windows
LDFLAGS=-I/usr/local/include/SDL2 -L/usr/local/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf # -w -Wl,-subsystem,windows
SOURCES=model.cpp view.cpp controller.cpp main.cpp Menu.cpp Tile.cpp Library.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=final.exe

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE):
	$(CC) -g -std=c++11 -fpermissive $(SOURCES) $(LDFLAGS) -o $@

clean:
	rm $(EXECUTABLE)
