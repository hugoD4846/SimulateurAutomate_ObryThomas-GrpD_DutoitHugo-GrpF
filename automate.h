#include <stdbool.h>
#ifndef AUTOMATE_H_INCLUDED
#define AUTOMATE_H_INCLUDED
typedef char alphabet[8];
typedef unsigned int trans;

typedef struct etat{
	int index;
	trans transi[5];
	bool final;
}etat;

typedef struct automate{
	struct etat *Initial;
	struct etat Q[5];
	alphabet A;
}automate;

void setEtat(struct automate * autom);
int AlphaLength(alphabet alpha);
void initAuto(automate *autom);
#endif
