#include "funcionalidades.h"

void resolucaoMochila(elemento* elementos, int qtd, int pesoMax){
    int soma=0, i=0, valor=0;

    while(soma<pesoMax && i<qtd){
        soma += elementos[i].peso;
        valor += elementos[i].valor;
        elementos[i].entrou = 1;
        i++;
    }

    if(soma>pesoMax){
        soma -= elementos[i-1].peso;
        valor -= elementos[i-1].valor;
        elementos[i-1].entrou = 0;
    }

    printf("Valor obtido: %d\n", valor);
}

int main(){
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    
    printf("Iniciando o programa...\n");

    FILE *arq = fopen("knapPI_1_100_1000_1", "r");
    int qtd, pesoMax;
    infoMochila(arq, &qtd, &pesoMax);
    elemento *elementos = (elemento *)calloc(qtd, sizeof(elemento));
    leituraPesoValor(arq, elementos, qtd);

    fclose(arq);

    ordenaPeso(elementos, 0, qtd-1);
    resolucaoMochila(elementos, qtd, pesoMax);
    ordenaPosicao(elementos, 0, qtd-1);

    output(elementos, qtd);

    free(elementos);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Tempo de execução: %f segundos\n", cpu_time_used);

    return 0;
}