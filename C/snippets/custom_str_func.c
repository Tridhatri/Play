#include <stdio.h>
#include <stdbool.h>

// Custom strcpy, strlen, strcmp

// Probably very bad code.
// Will change this. But need this commit.

int _strlen(char* src){

  int count = 0;
  while(*src != '\0'){
    src++;
    count++;
  }
if(count) 
  {
    return count;
  }
  else{
  return -1;
  };


};

bool _strcmp(char* src, char* dst){
 // First use strlen to compare if they are both the same len 
  if(_strlen(src) == _strlen(dst)){
    // both are equal.
    // Now,
    while(*src == '\0' || *dst == '\0'){
      if(*src == *dst) {
        src++;
        dst++;
      }
      else{
        return false;
      }
    }
  }

return true;

}


int main() {
char* input = "str";
int count = _strlen(input);
printf("%d\n",count);

char *input2 = "str";

int status = _strcmp(input, input2);
if(status) {printf("They are equeal\n");}
else{
printf("They are unequal\n");}




}

