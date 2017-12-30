CFLAGS = -Wall -g `pkg-config --cflags gtk+-2.0`
LDFLAGS = `pkg-config --libs gtk+-2.0`


all: clean compil
	./main

compil:
	g++ main.cpp Dessin.cpp Point.cpp cairo.cpp $(CFLAGS) $(LDFLAGS) -o main

clean:
	rm -fr main 
