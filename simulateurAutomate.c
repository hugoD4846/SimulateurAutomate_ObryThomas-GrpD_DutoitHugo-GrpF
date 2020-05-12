#include <stdlib.h>
#include <stdio.h>
#include "automate.h"
#include "printAuto.h"
#include "readAuto.h"
#include "solveAuto.h"
#include "formatChecker.h"
// Ficheir Principal qui lit affiche et regarde si le mot mit en parametres passe dans l automate precedement lu 
int main(int argc, char **argv){
	// Verification du format de la commande entrer
	if(argc != 3){
		printf("ARGUMENTS PASSES INCORRECTS");
		exit(EXIT_FAILURE);
	}
	// Ouverture du fichier  passé en parametre
	FILE *file=fopen(argv[1],"a+");
	//Verification du format du fichier passe en parametre
	if(!goodFormat(file)){
		printf("FORMAT DE FICHIER INCORRECT");
		exit(EXIT_FAILURE);
	};
	//definiton d'un automate pour stocker les donnee du fichier
	struct automate *autom;
	//Lecture du fichier afin de stocker les information dans la structure automate
	autom = readAuto(file);
	// fermetur du fichier (inutile ici)
	fclose(file);
	//affichage des caracteristiques de l'automate
	printAuto(*autom);
	//Verification que le mot passe en parametre passe dans l automate
	if(solveAuto(*autom,argv[2])){
		printf("Le mot %s passe bien dans l'automate precedent",argv[2]);
	}else{
		printf("Le mot %s ne passe pas dans l'automate precedent",argv[2]);
	}
	printf("\n");
	//liberation de la memoire d'automate
	free(autom);
}
