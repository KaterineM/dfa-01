/*
*   Author: Katerine Muñoz Tello & Alfonso Cabargas Madrid
*   Description: emulate the transition function of an deterministic finite automata (DFA) 
*/

#include <stdlib.h>
#include <stdio.h>


int main(){
  int i, l, aux1, aux2, M[1000][2];         
  scanf("%d", &l);                              //Ask user how many states the automata has 

  for(i=0;i<l;i=i+1){  
    scanf("%d %d", &aux1, &aux2);               //Ask the transition function 
    M[i][0] = aux1;
    M[i][1] = aux2;
  }

  int r, aux3, rn[1000];                        //Ask the quantity of final states
  scanf("%d", &r);

  for(i=0;i<r;i=i+1){                           //Ask the finals states
    scanf("%d", &aux3);
    rn[i] = aux3;           
  }

  int w;                                        
  scanf("%d", &w);                              //Ask the string (in this case the chain of 0s and 1s) 

  

  
  return 0;
}