all: bin/autocompletar

bin/autocompletar: build/main.o build/Autocompletar.o build/ListaOrdenada.o build/Termo.o build/Lista.o
	mkdir -p bin
	g++ build/main.o build/Autocompletar.o build/ListaOrdenada.o build/Termo.o build/Lista.o -o bin/autocompletar

build/main.o: main.cpp include/Autocompletar.hpp include/ListaOrdenada.hpp include/Termo.hpp include/Lista.hpp
	mkdir -p build
	g++ -c main.cpp -o build/main.o

build/Autocompletar.o: src/Autocompletar.cpp include/Autocompletar.hpp include/Termo.hpp
	g++ -c src/Autocompletar.cpp -o build/Autocompletar.o

build/ListaOrdenada.o: src/ListaOrdenada.cpp include/ListaOrdenada.hpp include/Lista.hpp
	g++ -c src/ListaOrdenada.cpp -o build/ListaOrdenada.o

build/Termo.o: src/Termo.cpp include/Termo.hpp
	g++ -c src/Termo.cpp -o build/Termo.o

build/Lista.o: src/Lista.cpp include/Lista.hpp
	g++ -c src/Lista.cpp -o build/Lista.o

test: bin/autocompletar
	./bin/autocompletar datasets/actors.txt 10

clean:
	rm -f build/*.o

cleanall: clean
	rm -f bin/autocompletar

.PHONY: all test clean cleanall
