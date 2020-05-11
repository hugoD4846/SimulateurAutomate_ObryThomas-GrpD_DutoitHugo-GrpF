#include <stdio.h>
#ifndef READAUTO_H_INCLUDED
#define READAUTO_H_INCLUDED
struct automate * readAuto(FILE *file);
void getAlphabet(FILE *file,struct automate *autom);
void setInitial(FILE *file,struct automate *autom);
void setFinal(FILE *file,struct automate *autom);
void setTransition(FILE *file,struct automate *autom);
int decaleLine(FILE * file,int VOffset);
#endif
