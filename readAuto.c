#include <stdlib.h>
#include <stdbool.h>

#include "automate.h"
#include "formatChecker.h"
#include "readAuto.h"
#include "printAuto.h"
#include "solveAuto.h"

struct automate * readAuto(FILE *file){
	fseek(file,0,SEEK_SET);
	struct automate *res;
	res = malloc(sizeof(struct automate));

	getAlphabet(file,res);
	initAuto(res);
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
	fseek(file,decaleLine(file,1),SEEK_SET);
	fgets(buffer,1,file);
	autom->Initial=&autom->Q[atoi(&buffer[0])];
}
void setFinal(FILE *file, struct automate *autom){
	char buffer[5];
	fseek(file,decaleLine(file,2),SEEK_SET);
	fgets(buffer,5,file);
	for(int i=0;i<5;i++){
		if(buffer[i]!= '\n' && buffer[i] != '\0'){
			autom->Q[(int)(buffer[i]-'0')].final=true;
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

