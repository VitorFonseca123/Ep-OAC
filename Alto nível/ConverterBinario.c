#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int transformabinario(int n, int *binario, int *i);

int main()
{
    int num;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);
    int binario[32];
    int bin[32];
    for (int i = 0; i < 32; i++)
    {
        binario[i] = 0;
        bin[i] = 0;
    }
    int i=0;
    
    
    transformabinario(num, bin, &i);
    int j=0;
    for(int indice = 32-i;indice<32;indice++){
        //printf("%d\n", indice);
        
        binario[indice] = bin[j];
        j++;
    }
    
   
    //printf("%d",i);
    for (int i = 0; i < 32; i++)
    {
        printf("%d", binario[i]);
    }
     printf("\n");

    return 0;
}

int transformabinario(int n, int *binario, int *i)
{
    int bit = 0;
    if (n > 0)
    {
        bit = transformabinario(n / 2, binario, i);
        binario[*i] = n % 2;
        (*i)++;
        //printf("%d", n%2);
    }

    return bit;
}

