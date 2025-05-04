#include <stdio.h>
int main(void){
    printf("Enter Yes/No :");
    char c = scanf("%c");
    if (c == 'Y'){
        printf("aggreed \n");

}
    else if(c == 'n')
    {
        printf("Not\n");
    }
    else{
        printf("wrong input");
    }

}
