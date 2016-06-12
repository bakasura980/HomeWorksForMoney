#include <stdio.h>
#include <string.h>

int printcombination(char* numbers, int expectedvalue){
	int sum = 0;

  for(int i = 0; i < strlen(numbers); i++){
    sum += numbers[i] - '0';
  }

  if(sum == expectedvalue){
    for (int i = 0; i < strlen(numbers); i++){
      if(i != strlen(numbers) - 1)
      printf("%c+", numbers[i]);
      else
      printf("%c=%d\n", numbers[i], expectedvalue);
    }
    return 0;
  }else{
    sum = 0;

    for(int i = 0; i < strlen(numbers); i++){
      sum -= numbers[i] - '0';
    }

    if(sum == expectedvalue){
      for (int i = 0; i < strlen(numbers); i++){
        if(i != strlen(numbers) - 1)
        printf("%c-", numbers[i]);
        else
        printf("%c=%d\n", numbers[i], expectedvalue);
      }
      return 0;
    }

  }

	return 1;
}
int main(){
	char numbers[10];
	int expectedvalue;

	scanf("%s", numbers);
	scanf("%d", &expectedvalue);

	if(printcombination(numbers, expectedvalue))
		printf("-1\n");

	return 0;
}

