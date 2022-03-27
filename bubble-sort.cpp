#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void BubbleSort(int vet[]);
#define TAMANHO_VETOR 10

int main()
{
    int vetor[TAMANHO_VETOR] = {0}; // iniciando um vetor com 0
    srand(time(NULL));              // gera semente aleatoria

    for (int i = 0; i < TAMANHO_VETOR; i++)
        vetor[i] = rand() % 100; // numeros aleatorios entre 0 e 99

    BubbleSort(vetor);
    for (int i = 0; i < TAMANHO_VETOR; i++)
        printf("%d\n", vetor[i]);

    system("pause");
    return 0;
}
void BubbleSort(int vet[])
{
    int aux;
    for (int n = 1; n <= TAMANHO_VETOR; n++) // Laço para o tamanho do vetor
    {
        for (int i = 0; i < (TAMANHO_VETOR - 1); i++) // Laço da 1ª até a penultima posição
        {
            if (vet[i] > vet[i + 1])
            {
                aux = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = aux;
            }
        }
    }
}