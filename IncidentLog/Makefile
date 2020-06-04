#
# Makefile for P1
# COSC 052
# Fall 2019
#

a.out: main.o IncidentLog.o PHMSA7000.o Resources.o
	g++ -std=c++11 main.o IncidentLog.o PHMSA7000.o Resources.o

main.o: main.cpp main.h IncidentLog.h PHMSA7000.h Resources.h
	g++ -std=c++11 -c main.cpp

IncidentLog.o: IncidentLog.cpp IncidentLog.h PHMSA7000.h
	g++ -std=c++11 -c IncidentLog.cpp

PHMSA7000.o: PHMSA7000.cpp PHMSA7000.h Resources.h
	g++ -std=c++11 -c PHMSA7000.cpp

Resources.o: Resources.cpp Resources.h
	g++ -std=c++11 -c Resources.cpp

.PHONY: submit clean

submit:
	rm -f submit.zip
	zip submit.zip main.cpp main.h IncidentLog.cpp IncidentLog.h PHMSA7000.cpp PHMSA7000.h Resources.cpp Resources.h Makefile

clean:
	rm -f *.o core a.out
