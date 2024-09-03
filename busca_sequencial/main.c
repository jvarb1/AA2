#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fPesquisa_Sequencial(int *pVetor, int pChave , int pQuantidade);

int main()
{
    int TAM = 500;
    int vVetor[TAM];
    int vAux;
    int vChave;

    srand(time(NULL));

    for (vAux=0; vAux<TAM; vAux++)
    {
        vVetor[vAux] = rand() % 100; 
    }

    printf("\n Digite qual valor voce deseja procurar:");
    scanf("%d",&vChave);

    if ( fPesquisa_Sequencial(vVetor, vChave , TAM) != -1 )
        printf("\n Valor encontrado!\n\n ");
    else 
        printf("\n Valor nao encontrado!\n\n ");

    system("pause");
}

int fPesquisa_Sequencial(int *pVetor, int pChave , int pQuantidade)
{
     int vAux;

     for ( vAux=0; vAux < pQuantidade; vAux++ ) 
     {
         if ( pChave == pVetor[vAux] ) 
             return vAux; 
     }

     return -1; 
}