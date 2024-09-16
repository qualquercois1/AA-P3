#include "funcionalidades.h"

void infoMochila(FILE *arq, int *qtd, int *pesoMax){
    fscanf(arq, "%d %d\n", qtd, pesoMax);
}

void leituraPesoValor(FILE *arq, elemento* elementos, int qtd){
    for(int i=0; i<qtd; i++){
        fscanf(arq, "%d %d\n", &elementos[i].valor, &elementos[i].peso);
        elementos[i].posicao = i;
        elementos[i].entrou = 0;
        elementos[i].relacao = elementos[i].valor / elementos[i].peso;
    }
}

void output(elemento* elementos, int qtd){
    FILE *saida = fopen("output.txt", "a");

    for(int i=0; i<qtd; i++){
        fprintf(saida, "%d ", elementos[i].entrou);
    }

    fclose(saida);
}

int particionarPeso(elemento* elementos, int inicio, int fim){
    int pivo = elementos[fim].peso;
    int i = inicio - 1;
    for(int j = inicio; j < fim; j++){
        if(elementos[j].peso <= pivo){
            i++;
            elemento aux = elementos[i];
            elementos[i] = elementos[j];
            elementos[j] = aux;
        }
    }
    elemento aux = elementos[i+1];
    elementos[i+1] = elementos[fim];
    elementos[fim] = aux;

    return i+1;
}

void ordenaPeso(elemento* elementos, int inicio, int fim){
    if(inicio<fim){
        int pivo = particionarPeso(elementos, inicio, fim);
        ordenaPeso(elementos, inicio, pivo-1);
        ordenaPeso(elementos, pivo+1, fim);
    }
}

int particionarPosicao(elemento* elementos, int inicio, int fim){
    int pivo = elementos[fim].posicao;
    int i = inicio - 1;
    for(int j = inicio; j < fim; j++){
        if(elementos[j].posicao <= pivo){
            i++;
            elemento aux = elementos[i];
            elementos[i] = elementos[j];
            elementos[j] = aux;
        }
    }
    elemento aux = elementos[i+1];
    elementos[i+1] = elementos[fim];
    elementos[fim] = aux;

    return i+1;
}

void ordenaPosicao(elemento* elementos, int inicio, int fim){
    if(inicio<fim){
        int pivo = particionarPosicao(elementos, inicio, fim);
        ordenaPosicao(elementos, inicio, pivo-1);
        ordenaPosicao(elementos, pivo+1, fim);
    }
}

int particionarRelacao(elemento* elementos, int inicio, int fim){
    int pivo = elementos[fim].relacao;
    int i = inicio - 1;
    for(int j=inicio; j<fim; j++){
        if(elementos[j].relacao > pivo){
            i++;
            elemento aux = elementos[i];
            elementos[i] = elementos[j];
            elementos[j] = aux;
        }
    }
    elemento aux = elementos[i+1];
    elementos[i+1] = elementos[fim];
    elementos[fim] = aux;

    return i+1;
}

void ordenaRelacao(elemento* elementos, int inicio, int fim){
    if(inicio<fim){
        int pivo = particionarRelacao(elementos, inicio, fim);
        ordenaRelacao(elementos, inicio, pivo-1);
        ordenaRelacao(elementos, pivo+1, fim);
    }
}

int max(int a, int b){
    return (a > b) ? a : b;
}