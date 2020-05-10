#include "automate.c"
#include <stdlib.h>
#include <stdio.h>

#include "readAuto.h"

struct automate * readAuto(char filename[])
{
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
	for(int i = 0; i< 5; i++){
		for (int t = 0; t < 5;t++){
			char readBuff= fgetc(file);
			trans tmptrans = 0;
			int alphacount = 0;
			while(readBuff!=';' && readBuff!='\n'){
				while(readBuff != autom->A[alphacount]){
					tmptrans<<1;
					alphacount++;
				}
				tmptrans++;
				readBuff = fgetc(file);
			}
			while(alphacount < 8){
				tmptrans<<1;
				alphacount ++;
			}
			autom->Q[i].transi[t]=tmptrans;
		}
	}
}


