#include<stdio.h>
//Calculates the power
int main(){
    int base,power,i,j,result=1;

    printf("Enter base and power\n");
    scanf("%d%d",&base,&power);

    for(i=0 ; i<power ; i++){
        result= result *base;
    }

    printf("%d power %d = %d\n",base,power,result);


}
