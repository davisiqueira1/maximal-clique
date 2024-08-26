input = "testes/entrada.txt"

CC = g++

all: forca heuristica gerador

forca: forca.o forca_lib.o
	$(CC) forca.o forca_lib.o -o forca

heuristica: heuristica.o heuristica_lib.o
	$(CC) heuristica.o heuristica_lib.o -o heuristica

gerador: gerador.o
	$(CC) gerador.o -o gerador

forca.o: src/forca/forca.cpp src/forca/forca_lib.h
	$(CC) -c -I src/ src/forca/forca.cpp -o forca.o

heuristica.o: src/heuristica/heuristica.cpp src/heuristica/heuristica_lib.h
	$(CC) -c -I src/ src/heuristica/heuristica.cpp -o heuristica.o

forca_lib.o: src/forca/forca_lib.cpp src/forca/forca_lib.h
	$(CC) -c -I src/ src/forca/forca_lib.cpp -o forca_lib.o

heuristica_lib.o: src/heuristica/heuristica_lib.cpp src/heuristica/heuristica_lib.h
	$(CC) -c -I src/ src/heuristica/heuristica_lib.cpp -o heuristica_lib.o

gerador.o: src/gerador.cpp
	$(CC) -c -I src/ src/gerador.cpp -o gerador.o

run: runforca runheuristica

runforca: forca
	./forca < $(input)

runheuristica: heuristica
	./heuristica < $(input)

generate: gerador
	./gerador

clean:
	rm -f *.o forca heuristica gerador
