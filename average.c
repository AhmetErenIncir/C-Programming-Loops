#include<stdio.h>
//Finds average the numbers/
int main(){
    int n,i,num;
    double sum=0;
    printf("Enter the number\n");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&num);
        sum += num;
    }

    sum=sum/(double)n;

    printf("Girilen sayilarin ortlamasi : %.2lf\n",sum);

}
