#include<stdio.h>
//Finds even numbers
int main(){
    int border1,border2,i,sum=0;
    printf("Alt ve ust sinirlari giriniz\n");
    scanf("%d%d",&border1,&border2);

    for(i=border1;i<=border2;i++){
        if((i%2)==0){
            sum += i;
        }
    }

    printf("Aralikta kalan cift sayilarin toplami %d\n",sum);

}
