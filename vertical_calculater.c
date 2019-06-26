#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define SIZE 10
#define EXAMS 2
#define MAX_OP_SIZE 50

void menu();
void part1(int*);
void part2();
void part3();
//Function definitions.
int add(int number1 , int number2);
int sub(int number1 , int number2);
int multp(int number1 , int number2);
int division(int number1 , int number2);
int power(int number1 , int number2);
int mod(int number1 , int number2);
int doit(int f(int , int),int first_number , int second_number);

int take_grades(int []);
int take_exam_grades(int[]);
double calculate_homework(int[]); 
double calculate_lab(int[]);
double calculate_all(int ,int[],int);

//int x=0;//Global variable to hold previous result.

int main(){

    menu();

}


//Menu for all parts.
void menu(){
    int part_of_menu;
    int x;//It holds previous result.
    
    while(part_of_menu != -1){
        //Menu information.
        printf("\nPlease Enter the Part of Program\n");
        printf("Enter ""1"" for Part 1\nEnter ""2"" for Part 2\nEnter ""3"" for Part 3\n");
        printf("Enter -1 to Exit Program\n");
        scanf("%d",&part_of_menu);//User selection

        switch(part_of_menu){
            case 1:
                part1(&x);
                break;
            case 2:
                part2();
                break;
            case 3:
                part3();
                break;
            case -1:
                part_of_menu = -1;//Exit case.
                break;
            default:
                printf("This is an invalid choice. Try again!\n");//Error message.
                break;
                
        }
    }

}

//Part 1.
void part1(int* x){
    int num1,num2,flag=0,i,space;
    
    //Part 1 Menu.
    printf("Please Enter the Operation\n");
    printf("operators: addition (+), substraction (-), multiplication (*), division (/), power (**) and modulo (%%):\n");

    scanf("\n");
    char c[MAX_OP_SIZE];
    fgets(c,MAX_OP_SIZE,stdin);

    //The string parses according by the space icon.
    char* op = strtok(c," ");
    char* number1 = strtok(NULL," ");
    char* number2 = strtok(NULL," ");
    
    if(number2==NULL){
        number2="\0";
    }
    
    //String converts to integer numbers.
    num1=atoi(number1);
    num2=atoi(number2);
    
    //Determine operation and process.
    if(*op=='+'){
        if(num2==0){
        *x=doit(add,num1,*x);
        printf("%d\n",*x);
        }
        else{
        *x=doit(add,num1,num2);
        printf("%d\n",*x);
        }
    }
    else if(strcmp(op,"**")==0){
        if(num2==0){
        *x=doit(power,*x,num1);
        printf("%d\n",*x);
        }
        else{
        *x=doit(power,num1,num2);
        printf("%d\n",*x);
        }
    }
    else if(*op=='-'){
        if(num2==0){
        *x=doit(sub,*x,num1);
        printf("%d\n",*x);
        }
        else{
        *x=doit(sub,num1,num2);
        printf("%d\n",*x);
        }
    }
    else if(*op=='*'){
        if(num2==0){
        *x=doit(multp,num1,*x);
        printf("%d\n",*x);
        }
        else{
        *x=doit(multp,num1,num2);
        printf("%d\n",*x);
        }
    }
    else if(*op=='%'){
        if(num2==0){
        *x=doit(mod,*x,num1);
        printf("%d\n",*x);
        }
        else{
        *x=doit(mod,num1,num2);
        printf("%d\n",*x);
        }
    }
    else if(*op=='/'){
        if(num2==0){
        *x=doit(division,*x,num1);
        printf("%d\n",*x);
        }
        else{
        *x=doit(division,num1,num2);
        printf("%d\n",*x);
        }
    }
}
//Part 2.
void part2(){
    int homeworks[SIZE],lab[SIZE],exam[EXAMS],average_homework,average_lab; 

    //Calculates homeworks,labs and all average.
    average_homework =  calculate_homework(homeworks);
    average_lab = calculate_lab(lab);
    calculate_all(average_homework , exam , average_lab);
}
//Part 3.
void part3(){
    int index , i , j;
    //Gets information about shape from user. 
    printf("Enter the number\n");
    scanf("%d",&index);

    //Printing the shape according to index.
    for(i=0; i<index ; i++){
        if(i==0){
            for(j=0; j<index-1 ; j++){
                printf(" ");
            }
            printf("/\\\n");
        }
        else{
            for(j=0 ; j<index-i-1 ; j++){
                printf(" ");
            }
            printf("/");
            for(j=0 ; j<2*i ; j++){
                printf("*");
            }
            printf("\\\n");
        }
    }
    for(i=0 ; i<index ; i++){
        if(i==index-1){
            for(j=0 ; j<index-1 ; j++){
                printf(" ");
            }
            printf("\\/\n");
        }
        else{
            for(j=0 ; j<i ; j++){
                printf(" ");
            }
            printf("\\");
            for(j=0 ; j<(index-1)*2-(2*i) ; j++){
                printf("*");
            }
            printf("/\n");
        }
    }
}

//Operation functions in part1.
int doit(int f(),int first_number , int second_number){
    return f(first_number,second_number);
}

int add(int number1 , int number2){
        return number1 + number2;
}

int sub(int number1 , int number2){
    return number1 - number2;
}

int multp(int number1 , int number2){
    return number1 * number2;
}

int division(int number1 , int number2){
    return number1 / number2;
}

int power(int number1 , int number2){
    int i , res=1;
    for(i=0 ; i<number2 ; i++){
        res = res * number1;
    }
    return res;
}

int mod(int number1 , int number2){
    return number1%number2;
}

//This function runs for homeworks and labs grades.
int take_grades(int array[]){
    
    int i,grade;

    for(i=0 ; i<SIZE ; i++){
        scanf("%d",&grade);
        array[i] =grade;
    }
    return 0;
}
//gets exams from user.
int take_exam_grades(int exams[]){
    int i,grade;

    printf("Enter the midterm\n");
    scanf("%d",&exams[0]);
    printf("Enter the final\n");
    scanf("%d",&exams[1]);
    
    return 0;
}
//Calculates average of the homework grade.
double calculate_homework(int homeworks[]){
    int sum=0 , i;
    double average;

    printf("Enter the HomeWork grades\n");
    take_grades(homeworks);


    for(i=0 ; i<SIZE ; i++){
        sum = sum + homeworks[i];
    }

    average = (double)sum / (double)SIZE;

    printf("Average of homeworks: %.2lf\n",average);
    
    return average;
}
//Calculates average of the lab grade.
double calculate_lab(int labs[]){
    int i , sum = 0;
    double average ;

    printf("Enter the lab notes\n");
    take_grades(labs);

    for(i=0 ; i<SIZE ; i++){
        sum = sum + labs[i]; 
    }

    average = (double)sum / (double)SIZE;

    printf("Average of labs:%.2lf\n",average);

    return average;
}
//Calculates all average.
double calculate_all(int average_homework ,int exams[],int average_lab){
    int i;
    double average;

    take_exam_grades(exams);

    average = (average_homework * 0.1) + (average_lab * 0.2) + (exams[0] * 0.3) + (exams[1] * 0.4);

    printf("Average of all grades : %.2lf\n",average);

    return average;
}