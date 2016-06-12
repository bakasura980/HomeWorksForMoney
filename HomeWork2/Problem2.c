#include <stdio.h>
#include <string.h>

char* find(char *haystack, char needle){
  int i = 0;
  for(; i < strlen(haystack); i++){
    if (haystack[i] == needle) {
      break;
    }
  }
  if (i == strlen(haystack)) {
    return NULL;
  }else{
    return &haystack[i];
  }
}

int main(){

  char haystack[400];
  int i = 0;
  while(i < 400){
    scanf("%c", &haystack[i]);
    if (haystack[i] == '\n') {
      break;
    }
    i++;
  }

  char needle;
  scanf("%c", &needle);
  char *found = find(haystack, needle);
  found == NULL ? printf("%d\n", -1) : printf("%lu\n", found - haystack);
  return 0;
}
