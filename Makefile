all: clean compil
	./main

compil:
	g++ main.cpp -lGL -lGLU -lglut -o main

clean:
	rm -fr main 