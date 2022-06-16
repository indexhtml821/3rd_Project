FLAGS = -g -c --std=c++17

all:
	mkdir -p bin
	g++ $(FLAGS) src/empleado.cpp -o bin/empleado.o
	g++ $(FLAGS) src/empleadoNomina.cpp -o bin/empleadoNomina.o
	g++ $(FLAGS) src/empleadoHoras.cpp -o bin/empleadoHoras.o
	g++ $(FLAGS) src/procesador.cpp -o bin/procesador.o
	g++ $(FLAGS) src/planilla.cpp -o bin/planilla.o
	g++ $(FLAGS) src/nodo.cpp -o bin/nodo.o
	g++ $(FLAGS) src/main.cpp -o bin/main.o
	g++ -g -o bin/organizador bin/planilla.o bin/procesador.o bin/empleadoHoras.o  bin/empleadoNomina.o  bin/main.o bin/empleado.o bin/nodo.o

test:
	    mkdir -p bin
		g++ $(FLAGS) src/empleado.cpp -o bin/empleado.o
		g++ $(FLAGS) tests/tests_empleado_nomina.cpp -o bin/tests_empleado_nomina.o
		g++ $(FLAGS) src/empleadoNomina.cpp -o bin/empleadoNomina.o
		g++ $(FLAGS) tests/tests_empleado_horas.cpp -o bin/tests_empleado_horas.o
		g++ $(FLAGS) src/empleadoHoras.cpp -o bin/empleadoHoras.o
		g++ $(FLAGS) src/procesador.cpp -o bin/procesador.o
		g++ $(FLAGS) tests/tests_procesador.cpp -o bin/tests_procesador.o
		g++ $(FLAGS) src/planilla.cpp -o bin/planilla.o
		g++ $(FLAGS) tests/tests_planilla.cpp -o bin/tests_planilla.o
		g++ $(FLAGS) src/nodo.cpp -o bin/nodo.o
		g++ -g -o bin/tests bin/empleado.o bin/tests_empleado_nomina.o bin/empleadoNomina.o bin/tests_empleado_horas.o bin/empleadoHoras.o bin/procesador.o bin/tests_procesador.o bin/planilla.o bin/tests_planilla.o bin/nodo.o -lgtest -lgtest_main -lpthread
clean:
	rm -Rf bin