OBJ = gcc -c -o
MAIN = gcc -o

simulateurAutomate: simulateurAutomate.o readAuto.o printAuto.o solveAuto.o
		$(MAIN) simulateurAutomate simulateurAutomate.o

simulateurAutomate.o: simulateurAutomate.c  automate.c printAuto.c readAuto.c solveAuto.c
		$(OBJ) simulateurAutomate.o  simulateurAutomate.c

automate.o: automate.c
		$(OBJ) automate.o automate.c

printAuto.o: printAuto.c automate.h
		$(OBJ) printAuto.o printAuto.c

readAuto.o: readAuto.c automate.c
		$(OBJ) readAuto.o readAuto.c

solveAuto.o: solveAuto.c automate.c
		$(OBJ) solveAuto.o solveAuto.c
