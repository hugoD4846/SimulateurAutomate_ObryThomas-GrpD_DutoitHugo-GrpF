#ifndef READAUTO_H_INCLUDED
#define READAUTO_H_INCLUDED
void getAlphabet(FILE *file,struct automate *autom);
void setInitial(FILE *file,struct automate *autom);
void setFinal(FILE *file,struct automate *autom);
void setTransition(FILE *file,struct automate *autom);
#endif
