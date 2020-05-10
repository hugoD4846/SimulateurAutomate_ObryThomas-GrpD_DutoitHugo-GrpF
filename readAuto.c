#include "automate.c"
#include <stdlib.h>
#include <stdio.h>

#include "readAuto.h"
int decaleLine(FILE * file,int VOffset){
	fseek(file,0,SEEK_SET);
	int res = 0;
	for (int i = 0; i < VOffset; i++)
	{
		char tmpchar;
		do{
			res++;
			tmpchar = fgetc(file);
		}while ( tmpchar !='\n');
	};
	return res;
	
}
struct automate * readAuto(char filename[]){
	struct automate *res;
	res = malloc(sizeof(struct automate));
	FILE *file = fopen(filename,"a+");

	getAlphabet(file,res);
	setEtat(res);
	setInitial(file,res);
	setFinal(file,res);
	setTransition(file,res);
	return res;
}
void getAlphabet(FILE *file,struct automate *autom){
	fgets(autom->A,8,file);
	bool checker = false;
	for(int i=0;i<8;i++){
		if(autom->A[i] == '\n'){
			checker = true;
		}
		if(checker){
			autom->A[i]=0;
		}
	}
}
void setInitial(FILE *file,struct automate *autom){
	char buffer[1];
	fgets(buffer,1,file);
	autom->Initial=&autom->Q[atoi(&buffer[0])];
}
void setFinal(FILE *file, struct automate *autom){
	char buffer[5];
        fgets(buffer,1,file);
	for(int i=0;i<5;i++){
		if(&buffer[i]!=NULL){
        		autom->Q[atoi(&buffer[i])].final=true;
		}
	}
}
void setTransition(FILE *file, struct automate *autom){
	char buffer[50];
	fseek(file,decaleLine(file,3),SEEK_SET);
	for(int i = 0; i< 5; i++){
		for (int t = 0; t < 5;t++){
			autom->Q[i].transi[t]=0;
			char buffer =fgetc(file);
			while(buffer != '\n' && buffer != ';'){
				autom->Q[i].transi[t]= autom->Q[i].transi[t]|LetterToBinaryVector(autom->A,buffer);
				buffer =fgetc(file);
				
		}
			}
			
	}
}


