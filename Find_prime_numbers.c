#include<stdio.h>

int main(){
    int num1,num2,i,j,flag=0;
    printf("Enter 2 number to find prime numbers between two of them\n");
    scanf("%d%d",&num1,&num2);

    printf("\n\n");

    for(i=num1+1 ; i<num2 ; i++){
        for(j=2 ; j<i ;j++){
            if(i%j == 0 ){
                flag++;
            }
        }
        if(flag==0){
                printf("%d\n",i);
            }
        flag=0;
    }



}