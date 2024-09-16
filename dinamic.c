#include "funcionalidades.h"

void resolucaoMochila(elemento *elementos, int qtd, int pesoMax) {

    int **dp = (int **)malloc((qtd + 1) * sizeof(int *));
    for (int i = 0; i <= qtd; i++) {
        dp[i] = (int *)malloc((pesoMax + 1) * sizeof(int));
    }

    for (int i = 0; i <= qtd; i++) {
        for (int w = 0; w <= pesoMax; w++) {
            dp[i][w] = 0;
        }
    }

    for (int i = 1; i <= qtd; i++) {
        for (int w = 0; w <= pesoMax; w++) {
            if (elementos[i-1].peso <= w) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - elementos[i-1].peso] + elementos[i-1].valor);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    int w = pesoMax;
    for (int i = qtd; i > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            elementos[i-1].entrou = 1;
            w -= elementos[i-1].peso;
        }
    }

    printf("Valor total obtido: %d\n", dp[qtd][pesoMax]);

    for (int i = 0; i <= qtd; i++) {
        free(dp[i]);
    }
    free(dp);
}

int main(){
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    
    printf("Iniciando o programa...\n");

    FILE *arq = fopen("instances_01_KP/large_scale/knapPI_1_10000_1000_1", "r");
    int qtd, pesoMax;
    infoMochila(arq, &qtd, &pesoMax);
    elemento *elementos = (elemento *)calloc(qtd, sizeof(elemento));
    leituraPesoValor(arq, elementos, qtd);

    fclose(arq);

    resolucaoMochila(elementos, qtd, pesoMax);

    output(elementos, qtd);

    free(elementos);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Tempo de execução: %f segundos\n", cpu_time_used);

    return 0;
}