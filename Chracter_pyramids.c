#include<stdio.h>


int main(){
    int row=10,i,j;
    char c;

    printf("Enter the character\n");
    scanf("%c",&c);

    for(i=0 ; i<row ; i++){
        for(j=1 ; j<row-i ;j++){
            printf("Enter the number ");
        }
        for(j=0 ; j<=i ; j++){
            printf("%c ",c);
        }
    printf("Enter the value of j\n");
    }


}
