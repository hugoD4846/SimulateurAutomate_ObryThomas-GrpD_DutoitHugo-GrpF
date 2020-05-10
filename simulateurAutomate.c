#include "printAuto.c"
#include "readAuto.c"
#include "solveAuto.c"
#include <stdio.h>
int main(int argc, char **argv){
	if(argc != 3){
		exit(0);
	};
	struct automate *autom;
 	autom = readAuto(argv[1]);
	printAuto(*autom);
	if(solveAuto(*autom,argv[2])){
		printf("Le mot %s passe bien dans l'automate precedent",argv[2]);
	}else{
		printf("Le mot %s ne passe pas dans l'automate precedent",argv[2]);
	}
	printf("\n");
}
