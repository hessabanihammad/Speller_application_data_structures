
dictionary: finalone.o myfunction.o
	g++ finalone.o myfunction.o -o dictionary
finalone.o: finalone.cpp
	g++ -c finalone.cpp
myfunction.o: myfunction.cpp myfunction.h
	g++ -c myfunction.cpp

clean:
	rm *.o

