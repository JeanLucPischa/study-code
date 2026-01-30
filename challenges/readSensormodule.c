#include <stdio.h>

int main(){

  unsigned char status = 0xA7;

  if(status & 0x80){
    printf("Fehler\n");
  }
  if(status & 0x40){
    printf("Uebertemperatur\n");
  }
  if(status & 0x20){
    printf("Unterspannung\n");
  }
  printf("%d", (status & 0x07));

  return 0;
}