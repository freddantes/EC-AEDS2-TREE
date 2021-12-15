#ifndef ARQ_H
#define ARQ_H

#include "avl.h"
#include "avp.h"

#define PATH_INSERCAO 'src/files/E'
#define PATH_PESQUISA 'src/files/P'

#include <string.h>
#include <time.h>


void writeArq(char *nome, int max);
void readArqEnt(Tree **raiz, TreeAVL **raizAVL, TreeVP **raizVP, int tam, double *t, double *tAVL, double *tVP);
void readArqPes(Tree **raiz, TreeAVL **raizAVL, TreeVP **raizVP, int tam, double *t, double *tAVL, double *tVP);
void valorRandom();

double getRandom();

#endif