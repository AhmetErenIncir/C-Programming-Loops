#include<stdio.h>
//Staff salary calculater
int main(){
    int n,i=0;
    double maas,toplam=0;
    printf("Enter the number of staffs\n");
    scanf("%d",&n);
    do{
        printf("Enter the salary of staffs : ");
        scanf("%lf",&maas);
        toplam+=maas;
        i++;
    }
    while(i<n);

    printf("personele odenen toplam maas: %.2lf\n",toplam);
    printf("personele odenen ortlama maas : %.2lf",(toplam/n));



}
