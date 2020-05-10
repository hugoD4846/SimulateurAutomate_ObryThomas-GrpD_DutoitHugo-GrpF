#include"automate.h"
#include<stdio.h>
#ifndef AUTOMATE_C_INCLUDED
#define AUTOMATE_C_INCLUDED
void setEtat(struct automate *autom){
        for(int i = 0; i < 5;i ++){
                autom->Q[i].index = i;
        }
}
int AlphaLength(alphabet alpha){
	int len = 0;
	while(len < 8 && alpha[len]!=0){
		len++;
	}
	return len;
}

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
#endif
