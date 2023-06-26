#include <complex.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define true 1
#define false 0

#define TOL exp(-20)    /* tolerancia para o metodo de Newton */
#define MAXK 45         /* maximo de iteracoes do metodo de Newton */

#define FX cpow(x,6) - 1
#define dFX 6*cpow(x,5)
#define ROOTS 6

/* funcoes utilizadas nos testes do relatorio
 * 
 * #define FX cpow(x,4) + cpow(x,2) - 6
 * #define dFX 4*cpow(x,3) + 2*x
 * #define ROOTS 4
 *
 * #define FX cpow(x,6) + 2.0/cpow(x,2) - 11
 * #define dFX 6*cpow(x,5) - 4.0/cpow(x,3)
 * #define ROOTS 8
 */

double complex evalf(double complex z);
double complex evalDf(double complex z);
double complex newton(double complex z_0, char* converge);
void newton_basins(double l[], double u[], int p[]);

int main(int argc, char** argv){
  double l[2] = {atof(argv[1]),atof(argv[2])},
         u[2] = {atof(argv[3]),atof(argv[4])};
  int    p[2] = {atoi(argv[5]),atoi(argv[6])};
  newton_basins(l,u,p);
  return 0;
}

double complex evalf(double complex x){
  return FX;
}

double complex evalDf(double complex x){
  return dFX;
}

double complex newton(double complex z_0, char* converge){
  int k = 1;
  double complex z_k, z_kp1 = z_0 - evalf(z_0)/evalDf(z_0);
  *converge = true;
  for(z_k = z_0; cabs(z_kp1-z_k) > TOL && evalDf(z_kp1) != 0.0 && k < MAXK; z_kp1 = z_k - evalf(z_k)/evalDf(z_k)){
    z_k = z_kp1;
    k++;
  } /* realiza as iteracoes do ponto fixo ate que a distancia entre as iteracoes fique menor que a tolerancia, f'(x) seja 0 ou seja alcancado o maximo de iteracoes */
  if(cabs(z_kp1-z_k) > TOL) *converge = false;
  return z_kp1;
}

void newton_basins(double l[], double u[], int p[]){
  int i, r, color, found_roots = 0;
  FILE *output;
  char converge;
  double step_i, step_r; /* representam a distancia entre cada ponto dependendo do numero de pixels */
  double complex z, z_s, z_s_array[ROOTS];
  step_r = (double)abs(l[0]-u[0])/(p[0]-1);
  step_i = (double)abs(l[1]-u[1])/(p[1]-1);

  output = fopen("output.txt", "w");
  for(r = 0; r < p[0]; r++){
    for(i = 0; i < p[1]; i++){
      z = (l[0]+r*step_r) + (l[1]+i*step_i)*I;
      if(cabs(evalDf(z)) <= TOL) converge = false; /* caso a derivada de f <= TOL o metodo nao funciona */
      else z_s = newton(z, &converge);
      
      if(converge){
        for(color = 0; color < found_roots; color++)
          if(cabs(z_s-z_s_array[color]) <= (2*TOL)) break; /* verifica se a raiz esta no vetor de raizes */
        if(color == found_roots){
          z_s_array[color] = z_s; /* caso a raiz nao esteja no vetor, coloca a raiz no vetor */
          found_roots++;
        }
      }
      else color = -1; /* representa a cor preta no caso do ponto nao convergir ou o metodo nao ser conclusivo */

      fprintf(output,"%f %+f %d\n",creal(z),cimag(z),color+2); /* color+2 se deve ao fato de que os indices de cor devem comecar em 1 para que o gnuplot os entenda */
    }
    fprintf(output,"\n");
  }
  for(color = 0; color < found_roots; color++)
    printf("z* = %.2f%+.2fi\n", creal(z_s_array[color]), cimag(z_s_array[color]));
  fclose(output);
}
