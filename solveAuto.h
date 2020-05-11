#ifndef SOLVEAUTO_H_INCLUDED
#define SOLVEAUTO_H_INCLUDED
bool solveAuto(struct automate autom, char mot[]);
bool IsInAlphabet(alphabet alpha,char mot[]);
bool LetterInAlphabet(alphabet alpha, char letter);
bool IsInAutomate(struct automate autom,char mot[]);
bool _IsInAutomate(struct automate autom,struct etat current,char mot[],int cpt);
struct etat getNextState(struct automate autom,struct etat state,char letter);
trans LetterToBinaryVector(alphabet alpha,char letter);
#endif
