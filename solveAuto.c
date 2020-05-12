#include <string.h>
#include <stdio.h>

#include "automate.h"
#include "formatChecker.h"
#include "readAuto.h"
#include "printAuto.h"
#include "solveAuto.h"

//fonction principal de resolution de automate avec un mot donne
bool solveAuto(struct automate autom,char mot []){
	//All letter in  Alphabet ?
	return IsInAlphabet(autom.A,mot)
	&&
	//in the automate
	IsInAutomate(autom,mot);
}

//function qui verifie que toutes les lettres du mot sont dans l'alphabet
bool IsInAlphabet(alphabet alpha,char mot[]){
	for(int lm = 0;lm<strlen(mot);lm++){
		if(!LetterInAlphabet(alpha,mot[lm])){
			return false;
		}
	}
	return true;
}

//fonction qui verifi si un lettre appartient a un alphabet
bool LetterInAlphabet(alphabet alpha,char letter){
	for(int la=0;la< strlen(alpha);la++){
		if(alpha[la]==letter){
			return true;
		}
	}
	return false;
}

//base de la function recursive qui verifie si le mot est dans l automate
bool IsInAutomate(struct automate autom,char mot[]){
	return _IsInAutomate(autom,*(autom.Initial),mot,0);
}

// fonction recursive de verification de mot dans l automate
bool _IsInAutomate(struct automate autom,struct etat current,char mot[],int cpt){
	if(current.index ==-1){
		return false;
	}
	if(cpt==strlen(mot)){
		return current.final;
	}
	return _IsInAutomate(autom,getNextState(autom,current,mot[cpt]),mot,cpt+1);
}

// fonction retournant l etat suivant en fonction d'une lettre et un etat donne
struct etat getNextState(struct automate autom,struct etat state,char letter){
	trans letterMasque = LetterToBinaryVector(autom.A,letter);
	for(int t = 0;t<5;t++){
		if((state.transi[t]&letterMasque) != (trans)0){
			return autom.Q[t];
		}
	}
	struct etat null;
	null.index=-1;
	return null;
}
