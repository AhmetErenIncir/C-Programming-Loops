#include<stdio.h>
//Factorial Calculater.
int main(){
    int number,i,sum=1;
    printf("Enter the number to calculate Factorial\n");
    scanf("%d",&number);

    for(i=2;i<=number;i++){
        sum*=i;
    }
    if(number==0){
        printf("%d",1);
    }
    else{
        printf("%d",sum);
    }
}
