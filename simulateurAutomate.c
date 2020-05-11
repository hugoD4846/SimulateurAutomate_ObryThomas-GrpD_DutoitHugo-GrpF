#include <stdlib.h>
#include <stdio.h>
#include "automate.h"
#include "printAuto.h"
#include "readAuto.h"
#include "solveAuto.h"
#include "formatChecker.h"
int main(int argc, char **argv){
	FILE *file=fopen(argv[1],"a+");
	if(!goodFormat(file)){
		printf("FORMAT DE FICHIER INCORRECT");
		exit(EXIT_FAILURE);
	};
	if(argc != 3){
		printf("ARGUMENTS PASSES INCORRECTS");
		exit(EXIT_FAILURE);
	}
	
	struct automate *autom;
	autom = readAuto(file);
	fclose(file);
	printAuto(*autom);
	if(solveAuto(*autom,argv[2])){
		printf("Le mot %s passe bien dans l'automate precedent",argv[2]);
	}else{
		printf("Le mot %s ne passe pas dans l'automate precedent",argv[2]);
	}
	printf("\n");
	free(autom);
}
