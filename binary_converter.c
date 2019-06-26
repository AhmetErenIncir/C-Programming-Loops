#include<stdio.h>

int main(){
    int number,i=1,j,temp,binary=0;

    printf("enter the number\n");
    scanf("%d",&number);

    while(number!=0){
        temp=number%2;
        number= number /2;
        binary= binary + temp*i;
        i=i*10;
    }
    printf("%d",binary);

}