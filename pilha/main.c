# include <stdio.h>
# include <stdlib.h>
# include "pilha.h"

int main()
{
    Pilha *pPos = NULL;
    Pilha *pTemp = NULL;

    printf( "Insira sua função em notação usual: " );
    leOperacao( &pPos, &pTemp );
    printf( "Função equivalente em notação pós-fixa: " );
    imprime( pPos );
    printf( "\n" );

    return 0;
}