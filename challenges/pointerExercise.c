#include <stdio.h>

int main(){

  int myNumbers[5] = {10, 20, 30, 40, 50};

  int *pMyNumbers1 = & myNumbers[1];
  int *pMyNumbers2 = & myNumbers[4];

  printf("pMyNumbers1 = %d\n", *pMyNumbers1);
  printf("pMyNumbers1 = %d\n", *pMyNumbers2);
  printf("Adresse von pMyNumber1: %p\n", pMyNumbers1);
  printf("Adresse von pMyNumber1: %p\n", pMyNumbers2);
  printf("Adresse von myNumbers[1]: %p\n", myNumbers);
  printf("Differenz der Adressen (Pointer): %lld", pMyNumbers2-pMyNumbers1);
  
  return 0;
}