#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int transformabinario(int n, int *binario, int indice);

int main()
{
    int num;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);
    int binario[32];
    for (int i = 0; i < 32; i++)
    {
        binario[i] = 0;
    }
    transformabinario(num, binario, 0);
    for (int i = 0; i < 32; i++)
    {
        // printf("%d", binario[i]);
    }
    // printf("\n");

    return 0;
}

int transformabinario(int n, int *binario, int i)
{
    int bit = 0;
    if (n > 0)
    {
       printf("%d", n/2);
       bit = transformabinario(n/2, binario, i);
    }
    
    return bit;
}
