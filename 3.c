#include <stdio.h>

struct resul_t{
  int sum;
  int avr;
};

int main(){

  int n,i;
  struct resul_t *result;
  result->sum = 0;
  scanf("%d", &n);
  for(i = 1; i <= n; i++){
    result->sum += i;
  }
  result->avr = result->sum / n;
  printf("Sum : %d\n", result->sum);
  printf("Avr : %d\n", result->avr);
  return 0;
}
