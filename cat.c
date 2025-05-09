#include <stdio.h>

void meow(int i);
int main(void){
    printf("Enter the number(times) :");
    int i = scanf("%i");
    meow(i);
}
void meow(int i) {  
    for(i > 0 ;i--;){
        printf("meow\n");
      
    }
}
