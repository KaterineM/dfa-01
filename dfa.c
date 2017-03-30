/*
*   Author: Katerine Muñoz Tello & Alfonso Cabargas Madrid
*   Description: emulate the transition function of a deterministic finite automata (DFA) 
*   Output: instant description of the automata and if the string belongs to the language
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 20
#define STRING_LENGHT_MAX 42

void latexprint(int wo[MAX], int ri, int piv, int w);     //Prints the instant description by state
int isin(int r, int rn[MAX], int ri);                     //Verifies if the last state corresponds to a final state
int random_number(int min_num, int max_num);
int check_for_existance(int rn[MAX], int value, int max, int states);

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

int random_number(int min_num, int max_num){
  int result = 0, low_num = 0, hi_num = 0;

  if (min_num < max_num){
    low_num = min_num;
    hi_num = max_num + 1; // include max_num in output
  } else {
    low_num = max_num + 1; // include max_num in output
    hi_num = min_num;
  }

  result = (rand() % (hi_num - low_num)) + low_num;
  return result;
}

int check_for_existance(int rn[MAX], int value, int max, int states){
  for(int i=0;i<max;i++){
    if(rn[i] == value){
      value = random_number(0, states);
      check_for_existance(rn, value, max, states);
    }
  }
  
  return value;
}

int main(){
  srand(time(NULL));   // should only be called once
  int i, l, aux1, aux2, M[MAX][2];         
  l = random_number(1, 10);                                     //Ask user how many states the automata has 
  printf("Number of States: %d\n", l);

  printf("The transition function: \n");
  for(i=0;i<l;i=i+1){  
    aux1 = random_number(1, l);
    aux2 = random_number(1, l);    //Ask the transition function 
    M[i][0] = aux1;
    M[i][1] = aux2;
   
    printf("M %d 0 = %d\n", i, M[i][0]);
    printf("M %d 1 = %d\n", i, M[i][1]);
  }

  

  int r, aux3, rn[MAX];                                   //Ask the quantity of final states
  r = random_number(1, l);
  printf("Number of final states: %d\n", r);

  printf("Final states:\n");
  for(i=0;i<r;i++){                                     //Ask the finals states
    aux3 = random_number(1, l);
    aux3 = check_for_existance(rn, aux3, i, l);
    rn[i] = aux3;

    printf("%d ", rn[i]);
  }

  printf("\n");
  int w, aux4, wo[MAX];                                   //Ask the lenght of the string
  w = random_number(1, 20);

  for(i=0;i<w;i++){                              //Ask the string 
    aux4 = rand() % 2;
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
    printf("The string does not belong to the language of the automata.\n");
  }

  return 0;
}
