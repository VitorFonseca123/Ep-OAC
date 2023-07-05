#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define grau 5
#define n 5 // Número máximo de iterações

void derivada(double fx[], double fdx[]);
void newton(double fx[], double fdx[], double x0);
double y(double x, double fx[]);

int main()
{
    double fx[grau] = {0, 0, 0, 4, 7};
    double fdx[grau];
    double x0 = 15;

    derivada(fx, fdx);
    newton(fx, fdx, x0);
}
void derivada(double fx[], double fdx[])
{
    for (int i = 1; i < grau; i++)
    {
        fdx[i - 1] = fx[i] * i;
        fdx[i] = 0;
    }
}
double y(double x, double fx[])
{
    double resultado = 0;
    for (int i = 0; i < grau; i++)
    {
        resultado += fx[i] * pow(x, i);
    }
    return resultado;
}
void newton(double fx[], double fdx[], double x0)
{
    double der = y(x0, fdx);
    if (der == 0)
    {
        printf("Escolha outro ponto de inicio");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            double x1 = x0 - y(x0, fx) / der;
            der = y(x1, fdx);
            if (der == 0)
            {
                printf("%f\n, parou na iteração: %f", x1, i);
                return;
            }
            printf("%f\n", x1);
            x0 = x1;
        }
    }
}
