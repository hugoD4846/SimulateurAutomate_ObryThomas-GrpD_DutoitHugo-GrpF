#include <string.h>
#include <stdio.h>
#include "automate.h"
#include "solveAuto.h"

bool solveAuto(struct automate autom,char mot []){
	//All letter in  Alphabet ?
	return IsInAlphabet(autom.A,mot)
	&&
	//in the automate
	IsInAutomate(autom,mot);
}

bool IsInAlphabet(alphabet alpha,char mot[]){
	for(int lm = 0;lm<strlen(mot);lm++){
		if(!LetterInAlphabet(alpha,mot[lm])){
			return false;
		}
	}
	return true;
}
bool LetterInAlphabet(alphabet alpha,char letter){
	for(int la=0;la< strlen(alpha);la++){
		if(alpha[la]==letter){
			return true;
		}
	}
	return false;
}
bool IsInAutomate(struct automate autom,char mot[]){
	return _IsInAutomate(autom,*(autom.Initial),mot,0);
}
bool _IsInAutomate(struct automate autom,struct etat current,char mot[],int cpt){
	if(current.index ==-1){
		return false;
	}
	if(cpt==strlen(mot)){
		return current.final;
	}
	printf("%d:\n%d->%c",cpt,current.index,mot[cpt]);
	return _IsInAutomate(autom,getNextState(autom,current,mot[cpt]),mot,cpt+1);
}
struct etat getNextState(struct automate autom,struct etat state,char letter){
	trans letterMasque = LetterToBinaryVector(autom.A,letter);
	for(int t = 0;t<5;t++){
		printf("%d&%d",state.transi[t],letterMasque);
		if(state.transi[t]&letterMasque != 0){
			return autom.Q[t];
		}
	}
	struct etat null;
	null.index=-1;
	return null;
}
trans LetterToBinaryVector(alphabet alpha,char letter){
	trans tmptrans=0;
	for(int al =0;al<8;al++){
		if(alpha[al]==letter){
			tmptrans++;
		}
		tmptrans <<1;
	}
	printf(">%d<",tmptrans);
	return tmptrans;
}
