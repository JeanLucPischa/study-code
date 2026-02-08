#include <time.h>

int main(){
  const int arr_size = 10;
  int arr1[arr_size] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  arr1[2] = 1;
  arr1[4] = 1;
  arr1[6] = 1;

  int *pArr = arr1;

  //temporary array and pointer
  int tempArr[arr_size];
  int *pTempArr = tempArr;

  return 0;
}