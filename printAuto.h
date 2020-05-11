#ifndef PRINTAUTO_H_INCLUDED
#define PRINTAUTO_H_INCLUDED
void printAuto(struct automate autom);
void printAlphabet(struct automate autom);
void printEtats(struct automate autom);
void printTransition(struct automate autom,struct etat *state);
void printBinary(int num,alphabet alpha);
#endif
