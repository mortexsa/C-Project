CFLAGS = -Wall -g `pkg-config --cflags gtk+-2.0`
LDFLAGS = `pkg-config --libs gtk+-2.0`



all: clean compil
	./main

compil:
	g++ fractal.cxx  $(CFLAGS) $(LDFLAGS) -o main

clean:
	rm -fr main 
