prog3:prog3.o circuit.o deeqn.o point.o
	g++ -o prog3 prog3.o circuit.o deeqn.o point.o -g

prog3.o:prog3.cc circuit.h deeqn.h
	g++ -c prog3.cc -g

circuit.o: circuit.cc circuit.h array2.h component.h point.h
	g++ -c circuit.cc -g

point.o: point.cc point.h
	g++ -c point.cc -g

deeqn.o: deeqn.h deeqn.cc
	g++ -c deeqn.cc -g
