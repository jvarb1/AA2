typedef struct _Pilha
{
    char op;
    struct _Pilha *p;
}Pilha;


void PosicaoTemporaria( Pilha **pPos, Pilha **pTemp, Pilha *aux )
{
    aux = ( *pTemp ) -> p;
    ( *pTemp ) -> p = *pPos;
    *pPos = *pTemp;
    *pTemp = aux;
}

void AlocaNaPilha( Pilha **pilha, Pilha *aux, char op )
{
    aux = ( Pilha *) malloc( sizeof( Pilha ) );
    aux -> op = op;  
    aux -> p = *pilha;
    *pilha = aux;
}

void leOperacao( Pilha **pPos, Pilha **pTemp )
{
    char op;
    Pilha *aux;
    
    scanf( "%c", &op );
    while( op != '\n' )
    {      

        switch( op )
        {
            case '+':
            case '-':

                while( ( *pTemp ) && ( (*pTemp) -> op != '(' ) )
                {
                    PosicaoTemporaria( &( *pPos ), &( *pTemp ), aux );
                }

                AlocaNaPilha( &( *pTemp ), aux, op );
                
                break;

            case '*':
            case '/':

                while( ( *pTemp ) && ( (*pTemp) -> op != '+' && (*pTemp) -> op != '-'
                        && (*pTemp) -> op != '(' ) )
                {        
                    PosicaoTemporaria( &( *pPos ), &( *pTemp ), aux );
                }

                AlocaNaPilha( &( *pTemp ), aux, op );
                
                break;

            case ')':
                while( ( *pTemp ) && ( (*pTemp) -> op != '(' ) )
                {
                    PosicaoTemporaria( &( *pPos ), &( *pTemp ), aux );
                }

                if( (*pTemp) && (*pTemp) -> op == '(' )
                {
                    aux = *pTemp;
                    *pTemp = (*pTemp) -> p;
                    free( aux );
                }
                
                break;

            case '(':
                AlocaNaPilha( &( *pTemp ), aux, op );
                
                break;

            default:
                AlocaNaPilha( &( *pPos ), aux, op );
                
                break;
        }

        scanf( "%c", &op );
    }

    while( *pTemp )
    {
        AlocaNaPilha( &( *pTemp ), aux, op );
    }
    
}

void imprime( Pilha *topo )
{
    if( topo )
    {
        imprime( topo -> p );
        printf( "%c", topo -> op );
    }   
}