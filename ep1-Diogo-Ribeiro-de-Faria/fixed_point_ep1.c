#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define true 1
#define false 0

#define TOL exp(-20)    /* tolerancia do erro na iteracao do ponto fixo */
#define MAXK 1000       /* maximo de iteracoes das funcoes do ponto fixo */

double evalf(double x){ return exp(x)-2.0*pow(x,2);   } /* f(x) = e^x-2x^2     */
double evalg1(double x){return log(2*pow(x,2));       } /* g(x) = ln(2x^2)     */
double evalg2(double x){return sqrt(exp(x)/2.0);      } /* g(x) = sqrt(e^x/2)  */
double evalg3(double x){return -1.0*sqrt(exp(x)/2.0); } /* g(x) = -sqrt(e^x/2) */
double iteracaoPontoFixoG1(double x_0, char* converge);
double iteracaoPontoFixoG2(double x_0, char* converge);
double iteracaoPontoFixoG3(double x_0, char* converge);

int main(int argc, char** argv){
  char converge;
  double x_s, x_0 = atof(argv[1]);

  x_s = iteracaoPontoFixoG1(x_0, &converge);
  if(converge && isfinite(x_s)) printf("x*_1 = %.3f\n", x_s);
  else printf("x_0 = %.2f nao converge para g1(x)\n", x_0);
  
  x_s = iteracaoPontoFixoG2(x_0, &converge);
  if(converge && isfinite(x_s)) printf("x*_2 = %.3f\n", x_s);
  else printf("x_0 = %.2f nao converge para g2(x)\n", x_0);

  x_s = iteracaoPontoFixoG3(x_0, &converge);
  if(converge && isfinite(x_s)) printf("x*_3 = %.3f\n", x_s);
  else printf("x_0 = %.2f nao converge para g3(x)\n", x_0);
  return 0;
}

double iteracaoPontoFixoG1(double x_0, char* converge){
  int k = 0;
  double x_k, x_kp1 = evalg1(x_0);
  *converge = true;
  for(x_k = x_0; fabs(x_kp1-x_k) > TOL && isfinite(x_kp1) && k < MAXK; x_kp1 = evalg1(x_k)){
    x_k = x_kp1;
    k++;
  } /* realiza a iteracao do ponto fixo ate a distancia entre x atual e o anterior ser suficientemente pequena, k atinja o maximo de iteracoes ou x atual nao seja finito */
  if(fabs(x_kp1-x_k) > TOL) *converge = false;
  return x_kp1;
}

double iteracaoPontoFixoG2(double x_0, char* converge){
  int k = 0;
  double x_k, x_kp1 = evalg2(x_0);
  *converge = true;
  for(x_k = x_0; fabs(x_kp1-x_k) > TOL && k < MAXK; x_kp1 = evalg2(x_k)){
    x_k = x_kp1;
    k++;
  } /* realiza a iteracao do ponto fixo ate a distancia entre x atual e o anterior ser suficientemente pequena ou k atinja o maximo de iteracoes */
  if(fabs(x_kp1-x_k) > TOL) *converge = false;
  return x_kp1;
}

double iteracaoPontoFixoG3(double x_0, char* converge){
  int k = 0;
  double x_k, x_kp1 = evalg3(x_0);
  *converge = true;
  for(x_k = x_0; fabs(x_kp1-x_k) > TOL && k < MAXK; x_kp1 = evalg3(x_k)){
    x_k = x_kp1;
    k++;
  } /* realiza a iteracao do ponto fixo ate a distancia entre x atual e o anterior ser suficientemente pequena ou k atinja o maximo de iteracoes */
  if(fabs(x_kp1-x_k) > TOL) *converge = false;
  return x_kp1;
}
