#include "string.h"

int kstrlen(char* string){
  int count = 0;
  while(string[count] != '\0') {
    count++;
  }
  return count;
}

int katoi(char* string) {
  //skip all whitespaces 
  //upon finding a sign then start counting numbers
  // if no sign then its ok as long as its not a non numeric character
  // keep counting until numbers until hitting either null or non-numeric character
  // each iteration multiply by 10
  int len = kstrlen(string);
  
  int return_number = 0;
  //bool
  int is_reached_numbers = 0;
  int is_negative = 0;
  for(int i = 0; i < len; i++) {
    if(string[i] == ' ' && !is_reached_numbers) {
      //do nothing
    }
    else if(string[i] == '-' && !is_reached_numbers){
      is_negative = 1;
      is_reached_numbers = 1;
    }
    else if(string[i] == '+' && !is_reached_numbers){
      is_reached_numbers = 1;
    }
    else if(string[i] >= 48 && string[i] <= 57) {
      is_reached_numbers = 1;
      return_number *= 10;
      return_number += (int) string[i] - 48; 
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


int kstrlcat(char* destination, char* source, int maxlen) {
  int n = kstrlen(destination);
  int m = kstrlen(source);
  int new_string_length = n + m;
  
  if (new_string_length > maxlen) {
    return -1;
  }
  //copy the destination string to the first n bytes of the new string buffer
  for(int i = n ; i < n + m; i++) {
    destination[i] = source[i - n];
  }
  //copy the soruce string to the n - n + mth bytes of the new string buffer
  return 0;
}

void kstrflip(char* string) {
  int len = kstrlen(string);

  for(int i = 0; i < len / 2; i++){
    //standard swap algo
    char temp = string[i];
    int mirrored_position =  len - 1 - i;
    string[i] = string[mirrored_position];
    string[mirrored_position] = temp;
  }
}

void kitoa(int number, char* destination, int maxlen) {
  //convert number to ascii
  // while number is > 0
  
  if(number == 0) {
    destination[0] = '0';
    destination[1] = '\0';
    return;
  }

  int negative = 0;

  if(number < 0) {
    negative = 1;
    number *= -1;
  }

  while(number > 0) {
    //  read digit by digit by % 10 
    int digit = number % 10;
    //  take digit and + 48 then type cast to char
    char digit_char[2];
    digit_char[0] =  (char) (digit + 48);
    digit_char[1] = '\0';
    //  add the digit character to return string
    kstrlcat(destination, digit_char, maxlen);
    //divide by 10;
    number /= 10;
  }
  if(negative) {
    kstrlcat(destination, "-", maxlen);
  }

  kstrflip(destination);

}