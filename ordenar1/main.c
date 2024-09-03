#include <stdlib.h>
#include <stdio.h>
#define Tam 3
    int main()
{
    int x[Tam];
    int i, j, temp, pesq;
    
        for (i = 0; i<Tam; i++)
        {
        printf("Digite o %dº elemento:\n", i+1);
        scanf("%d",&x[i]);
        }
  
    for (i=0;i<Tam; i++)
        for(j=i+1;j<Tam;j++)
        {
            if (x[i]>x[j])
            {
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;
            }
        }

    printf("\nVetor ordenado:\n");
        for(i=0;i<Tam;i++)
            printf(" %d",x[i]);

  printf("\nQual valor deseja pesquisar:\n");
  scanf("%d",&pesq);

  return 0;
}