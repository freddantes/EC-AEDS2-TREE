#ifndef AVP_H
#define AVP_H

#include "abs.h"

#include<stdio.h>
#include<stdlib.h>

typedef struct  TreeVP TreeVP;

enum type {black, red};

struct TreeVP {
	enum type color;
	Record reg;

	TreeVP *Fe;
	TreeVP *Fd;
	TreeVP *P;
};

void iniciaTreeVP(TreeVP **raiz);


void rotacaoEsquerda(TreeVP **raiz, TreeVP *x);
void rotacaoDireita(TreeVP **raiz, TreeVP *y);
void insertVP(TreeVP **raiz, TreeVP *x,TreeVP *y,TreeVP *temp);
void transportaVP(TreeVP *tVP,TreeVP *auxfilho);


void pesquisaVP(TreeVP *tVP, Record z, double *qtd);
void pesquisaDelete(TreeVP *tVP, Record z);

void preordemRB(TreeVP *tVP);
void centralRB(TreeVP *tVP);
void posordemRB(TreeVP *tVP);

int check(TreeVP *tVP,double z,int chq);



#endif