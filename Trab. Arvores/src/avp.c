#include <string.h>

#include "treeVP.h"
#include "arq.h"

TreeVP *temp, *nill;

void iniciaTreeVP(TreeVP **raiz){
    (*raiz) = NULL;
    nill        =(TreeVP *) malloc(sizeof(TreeVP));
    nill->color = black;
    nill->Fe    = NULL;
    nill->Fd    = NULL;
    nill->P     = NULL;
    nill->reg.key   = 0;
    (*raiz)     = nill;
}

void insertItemRB(TreeVP **raiz, Record r, int *contadorRP, int *cont) {
    int chk = 0;

    if ((temp = (TreeVP *) malloc(sizeof(TreeVP))) != NULL){
        temp->P     = nill;
        temp->Fe    = nill;
        temp->Fd    = nill;
        temp->reg   = r;
        temp->color = black;
        chk         = check(*raiz,r.key,0);

        if(chk == 0){
            rb_insert(raiz, *raiz, nill, temp);
            (*cont)++;
        }
        else{
            printf("Node already registered: %lf\n", r.key);
            (*contadorRP)++;
            free(temp);
        }
    }
}

void rotacaoEsquerda(TreeVP **raiz, TreeVP *x){
    TreeVP *y;
    y = x->Fd;
    x->Fd = y->Fe;
    if (y->Fe != nill)
        y->Fe->P = x;
    y->P = x->P;
    if (x->P == nill)
        (*raiz) = y;
    else if (x == x->P->Fe)
        x->P->Fe = y;
    else if (x == x->P->Fd)
        x->P->Fd = y;
    y->Fe = x;
    x->P  = y;
}

void rotacaoDireita(TreeVP **raiz, TreeVP *y){
    TreeVP *x;
    x = y->Fe;
    y->Fe = x->Fd;
    if (x->Fd != nill)
        x->Fd->P = y;
    x->P = y->P;
    if (y->P == nill)
        (*raiz) = x;
    else if (y == y->P->Fd)
        y->P->Fd = x;
    else if (y == y->P->Fe)
        y->P->Fe = x;
    x->Fd = y;
    y->P  = x;
}



void pesquisaVP(TreeVP *tVP, Record z, double *quant){
    while (tVP != nill && z.key != tVP->reg.key){
        (*quant)++;
        if (z.key < tVP->reg.key)
            tVP = tVP->Fe;
        else 
            tVP = tVP->Fd;
    }
}

void pesquisaDelete(TreeVP *tVP, Record z){
    while (tVP != nill && z.key != tVP->reg.key){
        if (z.key < tVP->reg.key)
            tVP = tVP->Fe;
        else 
            tVP = tVP->Fd;
    }
    if (tVP->reg.key == z.key) {
        printf("Noh (%lf) encontrado\n", z.key);
    }
    else 
        printf("Noh (%lf) nao existe\n", z.key);    fflush(stdout);
}

void preordemRB(TreeVP *tVP) {
    if(tVP != NULL && tVP->reg.key != 0) {
        printf("%lf ", tVP->reg.key);
        preordemRB(tVP->Fe);
        preordemRB(tVP->Fd);
    }
}

void centralRB(TreeVP *tVP) {
    if(tVP != NULL && tVP->reg.key != 0) {
        centralRB(tVP->Fe);
        printf("%lf ", tVP->reg.key);
        centralRB(tVP->Fd);
    }
}

void posordemRB(TreeVP *tVP) {
    if(tVP != NULL && aux->reg.key != 0) {
        posordemRB(tVP->Fe);
        posordemRB(tVP->Fd);
        printf("%lf ", tVP->reg.key);
    }
}


int check(TreeVP *tVP, double z, int chk){
    while (tVP != nill && z != tVP->reg.key){
        if (z < tVP->reg.key)
            tVP = tVP->Fe;
        else 
            tVP = tVP->Fd;
    }
    if (tVP->reg.key == z)
        chk = 1;
    return chk;
}
