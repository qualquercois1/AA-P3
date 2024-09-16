#ifndef FUNCIONALIDADES_H
#define FUNCIONALIDADES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct elemento{
    int valor;
    int peso;
    int entrou;
    int posicao;
    int relacao;
} elemento;

void infoMochila(FILE *arq, int *qtd, int *pesoMax);
void leituraPesoValor(FILE *arq, elemento* elementos, int qtd);
void output(elemento* elementos, int qtd);
int particionarPeso(elemento* elementos, int inicio, int fim);
void ordenaPeso(elemento* elementos, int inicio, int fim);
int particionarPosicao(elemento* elementos, int inicio, int fim);
void ordenaPosicao(elemento* elementos, int inicio, int fim);
int particionarRelacao(elemento* elementos, int inicio, int fim);
void ordenaRelacao(elemento* elementos, int inicio, int fim);
int max(int a, int b);

#endif