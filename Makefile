FLAGS = -g -c --std=c++17

all:
	mkdir -p bin
	g++ $(FLAGS) src/product.cpp -o bin/product.o
	g++ $(FLAGS) src/store.cpp -o bin/store.o
	g++ -g -o bin/storeLibrary bin/product.o bin/store.o

test:
	    mkdir -p bin
		g++ $(FLAGS) src/product.cpp -o bin/product.o
		g++ $(FLAGS) src/store.cpp -o bin/store.o
		g++ $(FLAGS) tests/tests_product.cpp -o bin/tests_product.o
		g++ $(FLAGS) tests/tests_store.cpp -o bin/tests_store.o
		g++ -g -o bin/tests bin/product.o bin/store.o bin/tests_product.o bin/tests_store.o -lgtest -lgtest_main -lpthread 
clean:
	rm -Rf bin