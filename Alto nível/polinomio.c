#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define grau 4
#define n 5 // Número máximo de iterações

void derivada(int fx[], int fdx[]);
void newton(int fx[], int fdx[], int x0);
int y(int x, int fx[]);

int main()
{
    int fx[grau] = {1, 1, 2, 4};
    int fdx[grau];
    int x0 = 10;

    derivada(fx, fdx);
    newton(fx, fdx, x0);
}
void derivada(int fx[], int fdx[])
{
    for (int i = 1; i < grau; i++)
    {
        fdx[i - 1] = fx[i] * i;
        fdx[i] = 0;
    }
}
int y(int x, int fx[])
{
    int resultado = 0;
    for (int i = 0; i < grau; i++)
    {
        resultado += fx[i] * pow(x, i);
    }
    return resultado;
}
void newton(int fx[], int fdx[], int x0)
{
    int der = y(x0, fdx);
    if (der == 0)
    {
        printf("Escolha outro ponto de inicio");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            int x1 = x0 - y(x0, fx) / der;
            der = y(x1, fdx);
            if (der == 0)
            {
                printf("%d\n, parou na iteração: ", x1, i);
                return;
            }
            printf("%d\n", x1);
            x0 = x1;
        }
    }
}
