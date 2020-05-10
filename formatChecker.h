#ifndef FORMAT_H_INCLUDED
#define FORMAT_H_INCLUDED
bool contains(char letter, char *alphabet);
bool alphabetCheck(char *line);
bool initialStateCheck(char *line);
bool acceptingStatesCheck(char *line);
bool transitionsCheck(char *line);
bool goodFormat(FILE *file);
#endif