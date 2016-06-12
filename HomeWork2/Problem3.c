#include <stdio.h>


int* hop(int *elem){

    return *elem + elem;
}
int is_in_bound(int *arr, int size, int *ptr){
    for(int i = 0; i < size; i++){
        if(ptr == &arr[i])
            return 1;
    }
    return 0;
}

int main(){

    int arr[50], counter, haspath = 0;

    for(counter = 0; scanf("%d", &arr[counter]) != EOF; counter++);

    int size = counter;
    counter = 0;

    int *ptr = &arr[counter];

    for(; (is_in_bound(arr, size, ptr) == 1) && counter < 50; counter++){
      if(*ptr == 0){
          haspath = 1;
          break;
      }
      ptr = hop(ptr);
    }

    printf("%d \n%d\n", haspath, counter);
    return 0;
}
