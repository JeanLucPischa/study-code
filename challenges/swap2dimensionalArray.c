#include <stdio.h>

int main(){

  int arr1[2][2] = {{1, 2}, {3, 4}};
  int arr2[2][2] = {{5, 6}, {7, 8}};

  printf("Current content of arr1 and arr2:\n");

  //print out arr1
  printf("arr1:\n");
  for (int i = 0; i < 2; i++){        //rows
    for(int j = 0; j < 2; j++){       //columns
      printf("%d ", arr1[i][j]);
    }
    printf("\n");
  }

  //print out arr2
  printf("arr2:\n");
  for (int i = 0; i < 2; i++){        //rows
    for(int j = 0; j < 2; j++){       //columns
      printf("%d ", arr2[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < 2; i++){        //rows
    for(int j = 0; j < 2; j++){       //columns
      int temporary = arr1[i][j];
      arr1[i][j] = arr2[i][j];
      arr2[i][j] = temporary;
    }
  }

  printf("\nSwapped content of arr1 and arr2:\n");

  //print out arr1
  printf("arr1:\n");
  for (int i = 0; i < 2; i++){        //rows
    for(int j = 0; j < 2; j++){       //columns
      printf("%d ", arr1[i][j]);
    }
    printf("\n");
  }

  //print out arr2
  printf("arr2:\n");
  for (int i = 0; i < 2; i++){        //rows
    for(int j = 0; j < 2; j++){       //columns
      printf("%d ", arr2[i][j]);
    }
    printf("\n");
  }

return 0;
}