OBJ = gcc -c -o
MAIN = gcc -o

simulateurAutomate: simulateurAutomate.o automate.o readAuto.o printAuto.o solveAuto.o formatChecker.o
		$(MAIN) simulateurAutomate simulateurAutomate.o automate.o readAuto.o printAuto.o solveAuto.o formatChecker.o

simulateurAutomate.o: simulateurAutomate.c  automate.c printAuto.c readAuto.c solveAuto.c formatChecker.c
		$(OBJ) simulateurAutomate.o  simulateurAutomate.c

automate.o: automate.c printAuto.h readAuto.h solveAuto.h formatChecker.h
		$(OBJ) automate.o automate.c

printAuto.o: printAuto.c automate.h readAuto.h solveAuto.h formatChecker.h
		$(OBJ) printAuto.o printAuto.c

readAuto.o: readAuto.c automate.h printAuto.h solveAuto.h formatChecker.h
		$(OBJ) readAuto.o readAuto.c

solveAuto.o: solveAuto.c automate.h printAuto.h readAuto.h formatChecker.h
		$(OBJ) solveAuto.o solveAuto.c

formatChecker.o: formatChecker.c automate.h printAuto.h readAuto.h solveAuto.h 
		$(OBJ) formatChecker.o formatChecker.c
