input = "testes/entrada.txt"

CC = g++

all: forca heuristica

forca: forca.o forca_lib.o
	$(CC) forca.o forca_lib.o -o forca

heuristica: heuristica.o heuristica_lib.o
	$(CC) heuristica.o heuristica_lib.o -o heuristica

forca.o: src/forca/forca.cpp src/forca/forca_lib.h
	$(CC) -c -I src/ src/forca/forca.cpp -o forca.o

heuristica.o: src/heuristica/heuristica.cpp src/heuristica/heuristica_lib.h
	$(CC) -c -I src/ src/heuristica/heuristica.cpp -o heuristica.o

forca_lib.o: src/forca/forca_lib.cpp src/forca/forca_lib.h
	$(CC) -c -I src/ src/forca/forca_lib.cpp -o forca_lib.o

heuristica_lib.o: src/heuristica/heuristica_lib.cpp src/heuristica/heuristica_lib.h
	$(CC) -c -I src/ src/heuristica/heuristica_lib.cpp -o heuristica_lib.o

# rodar os dois algoritmos
run: runforca runheuristica

runforca: forca
	./forca < $(input)

runheuristica: heuristica
	./heuristica < $(input)

clean:
	rm -f *.o forca heuristica