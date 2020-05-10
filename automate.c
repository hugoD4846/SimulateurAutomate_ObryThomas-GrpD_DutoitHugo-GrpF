#include"automate.h"
#include<stdio.h>

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
