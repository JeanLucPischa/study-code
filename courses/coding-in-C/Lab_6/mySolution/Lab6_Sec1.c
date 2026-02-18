#include <stdio.h>

int main(){

  FILE* data = NULL;

  if(data = fopen("sensor.txt", "r")){
    return 1;
  }

  return 0;
}