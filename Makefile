FLAGS = -g -fPIC -c --std=c++17

all:
	mkdir -p obj
	mkdir -p bin
	g++ $(FLAGS) src/product.cpp -o obj/product.o
	g++ $(FLAGS) src/store.cpp -o obj/store.o
	 
	g++ -shared -o bin/libstore.so obj/store.o 
	mkdir -p bin/include
	cp src/product.h ./bin/include
	cp src/store.h ./bin/include

test:
	    mkdir -p obj
		g++ $(FLAGS) src/product.cpp -o obj/product.o
		g++ $(FLAGS) src/store.cpp -o obj/store.o
		g++ $(FLAGS) tests/tests_product.cpp -o obj/tests_product.o
		g++ $(FLAGS) tests/tests_store.cpp -o obj/tests_store.o
		g++ -g -o obj/tests obj/product.o obj/store.o obj/tests_product.o obj/tests_store.o -lgtest -lgtest_main -lpthread 
clean:
	rm -Rf bin
	rm -Rf obj