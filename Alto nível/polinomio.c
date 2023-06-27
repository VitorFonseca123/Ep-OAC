#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define grau 4
#define n 5 //iterações

void derivada(int fx[], int fdx[]);
void newton(int fx[], int fdx[], double x0);
double y(double x, int fx[]);
int main()
{
    int fx[grau] = {0,1,2,4}; 
    int fdx[grau];
    double x0=2;
    derivada(fx, fdx);
    newton(fx,fdx, x0);
     
   
}
void derivada(int fx[],  int fdx[]){
    for(int i = 0;i<grau;i++){
        if(fx[i]!=0){
            fdx[i-1] = fx[i]*i;
            fdx[i]=0;
        }
    }
}
double y(double x, int fx[]){
    double resultado=0;
    for(int i=0;i<grau;i++){
        resultado += fx[i]*pow(x, i);
    }
    return resultado;
}
void newton(int fx[], int fdx[], double x0){
    double der = y(x0, fdx);
    if(der == 0){
        printf("Escolha outro ponto de inicio");
    }else{
        for(int i=0;i<n;i++){
            double x1 = x0 - y(x0, fx)/der;
            der = y(x1, fdx);
            if(der == 0){
                printf("%f", x1);
                return;
            } 
            if(i==n-1)printf("%f", x1);
            x0=x1;
        }
        
    }

}