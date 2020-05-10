#ifndef AUTOMATE_H_INCLUDED
#define AUTOMATE_H_INCLUDED
typedef char alphabet[8];
typedef unsigned int trans;
typedef int bool;
#define true 1
#define false 0
typedef struct etat{
	int index;
	trans transi[5];
	bool final;
};

/*
typedef struct trans {
	char letter;
	struct etat *vers;
	bool acceptant;
};
*/

typedef struct automate{
	struct etat *Initial;
	struct etat Q[5];
	alphabet A;
};

void setEtat(struct automate * autom);
int AlphaLength(alphabet alpha);
#endif
