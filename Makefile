all: clean compil
	./main

compil:
	g++ main.cpp Dessin.cpp Point.cpp -o main

clean:
	rm -fr main 