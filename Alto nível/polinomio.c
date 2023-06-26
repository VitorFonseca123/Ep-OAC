#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

void derivada(int grau, int fx[]);

int main()
{
    int grau = 4;
    int fx[4] = {0,1,2,4}; 
    derivada(grau, fx);
    for(int i = 0;i<grau;i++){
        printf("%dx^%d+", fx[i], i);
    }
}
void derivada(int grau,int fx[]){
    for(int i = 0;i<grau;i++){
        if(fx[i]!=0){
            fx[i-1] = fx[i]*i;
            fx[i]=0;
        }
        
    }
}