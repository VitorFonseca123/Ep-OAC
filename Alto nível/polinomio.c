#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#define grau 4
void derivada(int fx[], int fdx[]);

int main()
{
    //int grau = 4;
    int fx[grau] = {0,1,2,4}; 
    int fdx[grau-1];
    derivada(fx, fdx);
    for(int i = 0;i<grau;i++){
        printf("%dx^%d+", fdx[i], i);
    }
}
void derivada(int fx[],  int fdx[]){
    for(int i = 0;i<grau;i++){
        if(fx[i]!=0){
            fdx[i-1] = fx[i]*i;
            fdx[i]=0;
        }
    }
}