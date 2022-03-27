#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO_VETOR 10 
void quicksort(int vet[], int p, int u);
int particao(int vet[], int p, int u);
void troca(int vet[], int i, int j);

int main()
{
	int vet[TAMANHO_VETOR] = { 0 };     
	srand(time(NULL));

	for (int i = 0; i < TAMANHO_VETOR; i++)
		vet[i] = rand() % 100;

	printf("VETOR NAO ORDENADO:\n");
	for (int i = 0; i < TAMANHO_VETOR; i++) //IMPRIME NÃO ORDENADO
		printf("%d\n", vet[i]);

	quicksort(vet, 0, TAMANHO_VETOR - 1);

	printf("VETOR ORDENADO:\n");
	for (int i = 0; i < TAMANHO_VETOR; i++) //IMPRIME ORDENADO
		printf("%d\n", vet[i]);

	system("pause");
	return 0;
}

void quicksort(int vet[], int p, int u) //funcao recursiva
{
	int m;
	if (p < u)
	{
		m = particao(vet, p, u);
		quicksort(vet, p, m); 
		quicksort(vet, m + 1, u);
	}
}

int particao(int vet[], int p, int u) //encontra o pivo, faz varreduras e trocas
{
	int pivo, pivo_pos, i, j;

	pivo_pos = (p + u) / 2;
	pivo = vet[pivo_pos];

	i = p - 1;
	j = u + 1;
	while (i < j)
	{
		do //testa os valores à direita
		{
			j--;
		} while (vet[j] > pivo);

		do //testa os valores à esquerda
		{
			i++;
		} while (vet[i] < pivo);

		if (i < j)
			troca(vet, i, j);
	}
	return j;
}

void troca(int vet[], int i, int j)
{
	int aux;
	aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;
}