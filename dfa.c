/*
*   Author: Katerine Muñoz Tello & Alfonso Cabargas Madrid
*   Description: emulate the transition function of a deterministic finite automata (DFA) 
*   Output: instant description of the automata and if the string belongs to the language
*/

#include <stdlib.h>
#include <stdio.h>
#define MAX 20

void latexprint(int wo[MAX], int ri, int piv, int w);     //Prints the instant description by state
int isin(int r, int rn[MAX], int ri);                     //Verifies if the last state corresponds to a final state
  
void latexprint(int wo[MAX], int ri, int piv, int w){
  for(int i=0;i<w;i=i+1){
    if(piv == i){
      printf("q_{%d}", ri);
    }
    printf("%d", wo[i]);
  }

  if(piv == w){
    printf("q_{%d} $\n", ri);
  }
}

int isin(int r, int rn[MAX], int ri){
  int in = 0, i;
  for(i=0;i<r;i=i+1){
    if(rn[i] == ri){
      in = 1;
    }
  }

  return in;
}

int main(){
  int i, l, aux1, aux2, M[MAX][2];         
  scanf("%d", &l);                                        //Ask user how many states the automata has 

  for(i=0;i<l;i=i+1){  
    scanf("%d %d", &aux1, &aux2);                         //Ask the transition function 
    M[i][0] = aux1;
    M[i][1] = aux2;
  }

  int r, aux3, rn[MAX];                                   //Ask the quantity of final states
  scanf("%d", &r);

  for(i=0;i<r;i=i+1){                                     //Ask the finals states
    scanf("%d", &aux3);
    rn[i] = aux3;           
  }

  int w, aux4, wo[MAX];                                   //Ask the lenght of the string
  scanf("%d", &w);

  for(i=0;i<w;i=i+1){                                     //Ask the string 
    scanf("%d ", &aux4);
    wo[i] = aux4;
  }

  int ri = 1, piv = 0, aux5 = 0;
  printf("$ ");
  latexprint(wo, ri, piv, w);

  for(i=0;i<w;i=i+1){                                     //Emulates the transition function
    printf(" \\vdash ");
    
    if(wo[i] == 0){
      ri = M[aux5][0];
      aux5 = ri - 1 ;
      
    }else{
      ri = M[aux5][1];
      aux5 = ri - 1;
      
    }
    piv = piv + 1;

    latexprint(wo, ri, piv, w);
  }

  if(isin(r, rn, ri)){
    printf("The string belongs to the language of the automata.\n");
  }else{
    printf("El string does not belongs to the language of the automata.\n");
  }

  return 0;
}