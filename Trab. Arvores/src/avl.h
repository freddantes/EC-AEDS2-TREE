#ifndef AVL_H 
#define AVL_H

#include "abs.h"

#include<stdio.h>
#include<stdlib.h>

typedef struct TreeAVL TreeAVL;

struct TreeAVL{
	Record reg;
	TreeAVL *esq, *dir;
	int weight;
};

TreeAVL* CreateTree();
void insertTree(TreeAVL **t, Record r);
void pesquisa(TreeAVL **t, TreeAVL **aux, Record r);
int isInTree(TreeAVL *t, Record r);

void removeTree(TreeAVL **t, TreeAVL **f, Record r);
void antecessor(TreeAVL **t, TreeAVL *aux);
void rebalanceTree(TreeAVL **t);

void preordem(TreeAVL *t);
void central(TreeAVL *t);
void posordem(TreeAVL *t);


int getWeight(TreeAVL **t);
int getMaxWeight(int left, int right);


void rotacaoSimplesDireita(TreeAVL **t);
void rotacaoSimplesEsquerda(TreeAVL **t);
void rotacaoDuplaDireita(TreeAVL **t);
void rotacaoDuplaEsquerda(TreeAVL **t);


#endif