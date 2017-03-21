/*
*   Author: Katerine Muñoz Tello & Alfonso Cabargas Madrid
*   Description: emulate the transition function of a deterministic finite automata (DFA) 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void latexprint(int wo[1000], int ri, int piv, int w);

void latexprint(int wo[1000], int ri, int piv, int w){
  printf("$ ");
  for(int i=0;i<w;i=i+1){
    if(piv == i){
      printf("q_%d", ri);
    }
    printf("%d", wo[i]);
  }

  if(piv == w){
    printf("q_%d $\n", ri);
  }
}

int main(){
  int i, l, aux1, aux2, M[1000][2];         
  scanf("%d", &l);                              //Ask user how many states the automata has 

  for(i=0;i<l;i=i+1){  
    scanf("%d %d", &aux1, &aux2);               //Ask the transition function 
    M[i][0] = aux1;
    M[i][1] = aux2;
  }

  int r, aux3, rn[l];                          //Ask the quantity of final states
  scanf("%d", &r);

  for(i=0;i<r;i=i+1){                           //Ask the finals states
    scanf("%d", &aux3);
    rn[i] = aux3;           
  }

  int w, aux4, wo[1000];                        //Ask the lenght of the string
  scanf("%d", &w);

  for(i=0;i<w;i=i+1){                           //Ask the string 
    scanf("%d ", &aux4);
    wo[i] = aux4;
  }

  int ri = 1, piv = 0;
  latexprint(wo, ri, piv, w);

  for(i=0;i<w;i=i+1){
    printf(" \\vdash $\n");
    if(wo[i] == 0){
      ri = M[i][0];
    }else{
      ri = M[i][1];
    }
    piv = piv + 1;

    latexprint(wo, ri, piv, w);
  }

  return 0;
}