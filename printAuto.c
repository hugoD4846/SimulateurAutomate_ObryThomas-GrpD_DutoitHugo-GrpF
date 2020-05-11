#include <stdio.h>
#include <stdbool.h>

#include "automate.h"
#include "formatChecker.h"
#include "readAuto.h"
#include "printAuto.h"
#include "solveAuto.h"


void printAuto(struct automate autom){
	//print alphabet
	printf("ALPHABET :\n");
	printAlphabet(autom);
	//print etat (+-)/transition
	printEtats(autom);
}


void printAlphabet(struct automate autom){
	int a=0;
	printf("|");
	for(a;a<sizeof(autom.A)/sizeof(char);a++){
		if(autom.A[a] != 0){
			printf("%c|",autom.A[a]);
		}
	}
	printf("\n");
}
void printEtats(struct automate autom){
	int e=0;
	printf("ETATS :\n");
	for(e;e<5;e++){
		if(autom.Q[e].index == autom.Initial->index){
			printf("-");
		}else{
			printf(" ");
		}
		printf("%d",autom.Q[e].index);
		if(autom.Q[e].final)printf("+");else printf(" ");
		printf(" :\n");
		//print transition
		printTransition(autom,&autom.Q[e]);
	}
}
void printTransition(struct automate autom,struct etat * state){
	printf(" ");
	printAlphabet(autom);
	for(int t=0;t<5;t++){
		printf("%d|",t);
		printBinary(state->transi[t],autom.A);
	}
	printf("\n");
}
void printBinary(int num,alphabet alpha){
	for(int b=0;b<AlphaLength(alpha);b++){
		if (num & 1){
        		printf("X");
		}else{
        		printf(" ");
		}
		num>>=1;
		printf("|");
	};
	printf("\n");
};
