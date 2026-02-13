#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 100

bool read_input(char *dest);
bool is_palindrome(const char *str);

int main(){

  char temp[MAX_SIZE];

  printf("Please type in string of characters: \n");

  if(!read_input(temp)){
    return 1;
  }

  printf("\"%s\" is %sa palindrome.\n", temp, is_palindrome(temp) ? "" : "not ");

  return 0;
}

bool is_palindrome(const char *str){

  const char *left = str;
  const char *right = str;

  while(*right) right++;

  if(right != str){
    right--;
  }

  while(left < right){
    char l = *left;
    char r = *right;

    if (tolower(l) != tolower(r)) return false;

    right--;
    left++;
  }

  return true;
}

bool read_input(char *dest) {
  if(fgets(dest, MAX_SIZE, stdin) == NULL){
    return false;
  }

  dest[strcspn(dest, "\n")] = '\0';

  return true;
}