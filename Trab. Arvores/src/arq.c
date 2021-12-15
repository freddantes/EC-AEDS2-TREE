#include "arq.h"


double getRandom() { return (1 + (double)rand() / (double)RAND_MAX *100000); }


void valorRandom() {
	char nome[100];

	srand(time(NULL));
	
	printf("Inicializando arquivos de entrada:\nE1 = 1.000 entradas.\nE2 = 10.000 entradas.\nE3 = 1.000.000 entradas.\n");
	strcpy(nome, "src/files/E1.txt");
	writeArq(nome, 1000);
	strcpy(nome, "src/files/E2.txt");
	writeArq(nome, 10000);
	strcpy(nome, "src/files/E3.txt");
	writeArq(nome, 1000000);

	srand(time(NULL));
    
    printf("Inicializando arquivos de pesquisa:\nP1 = 5.000 entradas.\nP2 = 10.000 entradas.\nP3 = 100.000 entradas.\n");
    strcpy(nome, "src/files/P1.txt");
	writeArq(nome, 5000);
	strcpy(nome, "src/files/P2.txt");
	writeArq(nome, 10000);
	strcpy(nome, "src/files/P3.txt");
	writeArq(nome, 100000);

}


void writeArq(char *nome, int max) {
	FILE *arq;
	char array[100];
	char *res;

	double n = 0;

	arq = fopen(nome, "w");

    for(int i=0; i < max; i++) {
        n = getRandom();
		sprintf(array, "%.5lf", n);
		strcat(array, "\n");
		fputs(array, arq);
    }
	fclose(arq);
}


void readArqEnt(Tree **raiz, TreeAVL **raizAVL, TreeVP **raizVP, int tam, double *t, double *tAVL, double *tVP) {
	FILE *file, *fileAVL, *fileVP;

	clock_t time;

	char linha[100];
	char texto[20];
	char *res;
    
	int inseridos = 0;

	sprintf(texto, "%d", tam);
	strcpy(linha, PATH_INSERCAO);
	strcat(linha, strcat(texto, ".txt"));

	file = fopen(linha, "r");
	fileAVL = fopen(linha, "r");
	fileVP = fopen(linha, "r");

	int repetidos = 0;

	if(file == NULL) {
		printf("Erro ao abrir arquivo de entrada!\n");
		return;
	} else {
		Record r;
		
		time = clock();

		while(!feof(file)) {
			res = fgets(linha, 100, file);

			if(res) {
				r.key = atof(linha);
				insertItemS(raiz, r);
				inseridos++;
			}
		}
		*t = ((clock() - time) / (double)CLOCKS_PER_SEC); // 1

		time = clock();

		while(!feof(fileAVL)) {
			res = fgets(linha, 100, fileAVL);

			if(res) {
				r.key = atof(linha);
				insertItemAVL(raizAVL, r);
				inseridos++;
			}
		}
		*tAVL = ((clock() - time) / (double)CLOCKS_PER_SEC); // 2

		time = clock();

		while(!feof(fileVP)) {
			res = fgets(linha, 100, fileVP);

			if(res) {
				r.key = atof(linha);
				insertItemRB(raizVP, r, &repetidos, &inseridos);
			}
		}
		*tVP = ((clock() - time) / (double)CLOCKS_PER_SEC); // 3
	}
	printf("\n%d valores inseridos no total\n", inseridos);
	printf("\n%d valores repetidos\n", repetidos);
	
	fclose(file);
	fclose(fileAVL);
	fclose(fileVP);
}


void readFileSearch(Tree **raiz, TreeAVL **raizAVL, TreeVP **raizVP, int tam, double *t, double *tAVL, double *tVP) {
	FILE *file, *fileAVL, *fileVP;
	Tree *aux;
	TreeAVL *auxAVL;

	clock_t time;

	char linha[100];
	char texto[20];
	char *res;

	int pesquisas;
	double qtdpes, qtdpesAVL, atdpesVP;

	pesquisas = qtdpes = qtdpesAVL = atdpesVP = 0;
	
	sprintf(texto, "%d", tam);
	strcpy(linha, PATH_SEARCH);
	strcat(linha, strcat(texto, ".txt"));

	file = fopen(linha, "r");
	fileAVL = fopen(linha, "r");
	fileVP = fopen(linha, "r");

	if(file == NULL) {
		printf("Erro ao abrir arquivo de pesquisa!\n");
		return;
	} else {
		Record r;
		
		time = clock();

		while(!feof(file)) {
			res = fgets(linha, 100, file);

			if(res) {
				r.key = atof(linha);
				pesquisaS(raiz, &aux, r, &qtdpes);
				pesquisas++;
			}
		}
		*t = ((clock() - time) / (double)CLOCKS_PER_SEC); // 1

		time = clock();

		while(!feof(fileAVL)) {
			res = fgets(linha, 100, fileAVL);

			if(res) {
				r.key = atof(linha);
				pesquisaAVL(raizAVL, &auxAVL, r, &qtdpesAVL);
				pesquisas++;
			}
		}
		*tAVL = ((clock() - time) / (double)CLOCKS_PER_SEC); // 2

		time = clock();

		while(!feof(fileVP)) {
			res = fgets(linha, 100, fileVP);

			if(res) {
				r.key = atof(linha);
				searchRB(*raizVP, r, &atdpesVP);
				pesquisas++;
			}
		}
		*tVP = ((clock() - time) / (double)CLOCKS_PER_SEC); // 3
	}
	fclose(file);
	fclose(fileAVL);
	fclose(fileVP);
	
	printf("(%.0lf) / %i pesquisas realizadas arvore Simples / pesquisas TOTAIS\n", qtdpes,pesquisas);
	printf("(%.0lf) / %i pesquisas realizadas arvore AVL / pesquisas TOTAIS\n", qtdpesAVL,pesquisas);
	printf("(%.0lf) / %i pesquisas realizadas arvore RB / pesquisas TOTAIS\n", atdpesVP,pesquisas);
}
