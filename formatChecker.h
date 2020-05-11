#include <stdio.h>
#ifndef FORMATCHECKER_H_INCLUDED
#define FORMATCHECKER_H_INCLUDED
bool contains(char letter, char *alphabet);
bool alphabetCheck(char *line);
bool initialStateCheck(char *line);
bool acceptingStatesCheck(char *line);
bool transitionsCheck(char *line, char *alphabet);
bool goodFormat(FILE *file);
#endif