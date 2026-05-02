#include "string.h"

int kstrlen(char* str){
  int count = 0;
  while(str[count] != '\0') {
    count++;
  }
  return count;
}

int katoi(char* str) {
  //skip all whitespaces 
  //upon finding a sign then start counting numbers
  // if no sign then its ok as long as its not a non numeric character
  // keep counting until numbers until hitting either null or non-numeric character
  // each iteration multiply by 10
  int len = kstrlen(str);
  
  int return_number = 0;
  //bool
  int is_reached_numbers = 0;
  int is_negative = 0;
  for(int i = 0; i < len; i++) {
    if(str[i] == ' ' && !is_reached_numbers) {
      //do nothing
    }
    else if(str[i] == '-' && !is_reached_numbers){
      is_negative = 1;
      is_reached_numbers = 1;
    }
    else if(str[i] == '+' && !is_reached_numbers){
      is_reached_numbers = 1;
    }
    else if(str[i] >= 48 && str[i] <= 57) {
      is_reached_numbers = 1;
      return_number *= 10;
      return_number += (int) str[i] - 48; 
    }
    else{
      //invalid string
      break;
    }
  }
  if(is_negative) {
    return_number *= -1;
  }
  return return_number;
}



