#include "automate.h"
#include "formatChecker.h"
#include "readAuto.h"
#include "printAuto.h"
#include "solveAuto.h"

#include<stdio.h>
// permet d'initialiser les etat d'un automate
void setEtat(struct automate *autom){
        for(int i = 0; i < 5;i ++){
                autom->Q[i].index = i;
				for(int t=0; t < 5;t++){
					autom->Q[i].final=false;
					autom->Q[i].transi[t]=0;
				}
        }
}
//return la longueur de l'alphabet passer en parametre
int AlphaLength(alphabet alpha){
	int len = 0;
	while(len < 8 && alpha[len]!=0){
		len++;
	}
	return len;
}


//transforme une lettre en vecteur binaire pour faciliter la resolution de l'automate
trans LetterToBinaryVector(alphabet alpha,char letter){

	trans tmptrans = 0;

	for (int i = AlphaLength(alpha)-1; i >= 0 ; i--)
	{
		
		if(letter==alpha[i]){
			tmptrans++;
		}
		tmptrans = tmptrans<<1;
	}
	return tmptrans>>1;
	
}
// fonction principale d'initialistation d'automate
void initAuto(automate *autom){
	setEtat(autom);

}
