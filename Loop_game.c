#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

#define TRL 5
#define MIN 1
#define MAX 1024


void menu(); // Prints Menu
int make_a_guess (int trial, int min, int max , int* ,int*); 
void show_scores(int* score_human, int* score_program);
void draw_hourglass (int height);
void draw_mountain_road (int length, int max_radius);



int main(){
    
    srand(time(NULL));
    menu();
    
}

void menu(){
    
    int operator , min , max , trial , height, length ,max_radius;

    int com_score =0;
    int my_score=0;
    

    while(operator != 4){ // Check the valid value.
        printf("***** MENU *****\n");
        printf("Enter the operation\n");
        printf("1. Play Lucky Number \n2. Draw Hourglass \n3. Draw Mountain Road \n4. Exit \n Choice:");
        scanf("%d",&operator); // User picks the operation.
        switch (operator)
        {
            case 1:
                make_a_guess(trial , min , max ,&my_score , &com_score);
                break;
            case 2:
                draw_hourglass(height);
                break;
            case 3:
                draw_mountain_road (length,max_radius);
                break;
            case 4:
                operator = 4 ;
                break;
            default:
                printf("This is an invalid choice. Try again!\n");
                break;
        }
    }
    
}

int make_a_guess (int trial, int min, int max , int* my_score , int* com_score ){
    int  guess_number , distance  ;
    int lucky_number = 1 + rand()%1024; //Luck number must be between 1-1024.
    printf("%d\n",lucky_number);
    trial = TRL; // The trial number.
    min = MIN;
    max = MAX;
    while(trial != 0 && lucky_number != guess_number ){ //Checking trial and guess number each round.
        
        printf("Make a guess between %d and %d:\n",min,max);
        scanf("%d",&guess_number); // User enters your guess

        //Calculating the distance based on user guess
        if(guess_number > lucky_number){
            distance = guess_number - lucky_number;
            max = guess_number; 
        }
        else{
            distance = lucky_number - guess_number;
            min = guess_number;
        }

        //Printing distance.
        if(distance >= 512 && distance <= 1024 ){
            printf("Distance is 10 \n");
        }
        else if(distance >= 256 && distance <= 512 ){
            printf("Distance is 9 \n");
        }
        else if(distance >= 128 && distance <=255 ){
            printf("Distance is 8 \n");
        }
        else if(distance >= 64 && distance <= 127 ){
            printf("Distance is 7 \n");
        }
        else if(distance >= 32 && distance <= 63 ){
            printf("Distance is 6 \n");
        }
        else if(distance >= 16 && distance <= 31 ){
            printf("Distance is 5 \n");
        }
        else if(distance >= 8 && distance <= 15 ){
            printf("Distance is 4 \n");
        }
        else if(distance >= 4 && distance <= 7 ){
            printf("Distance is 3 \n");
        }
        else if(distance >= 2 && distance <= 3 ){
            printf("Distance is 2 \n");
        }
        else if(distance == 1 ){
            printf("Distance is 1 \n");
        }
        else if(distance == 0 ){
            printf("Distance is %d. You won the game \n",0);
            guess_number = lucky_number;
        }    
        trial--; //trial reduces after each round.
    }

    //Checking winner and stores number of win for each side.
    if(trial>0 || guess_number==lucky_number ){
        *my_score=*my_score+1; 
    }
    else
    {
        *com_score=*com_score+1;
    }

    //Prints score after each round.
    show_scores(my_score , com_score);
    
    
    
    return guess_number;
}

void show_scores(int* score_human, int* score_program){
    
    printf("Your score : %d  Program score : %d\n",*score_human,*score_program);
    
}

void draw_hourglass (int height){
    
    int i, j;
    
    printf("Enter Odd value for height : ");
    scanf("%d", &height); //User enters height of HourGlass

    //Checking height is even or odd.If height is even , user is warned and ask again the height.
    while(height%2 == 0){ 
        printf("You entered even number . Please enter odd number\n"); 
        scanf("%d",&height);
    }


    printf("\n");

    //Prints HourGlass.
    if(height%2 == 1){
    
        for(i=height/2+1; i>1; i--)
        {      
            for(j=i; j<height; j++)
            {
                printf(" ");
            }
            for(j=1; j<=(2*i-1); j++)
            {
                printf("*");
            }
            printf("\n");
        }

        for(i=1; i<=height/2+1; i++)
        {
            for(j=i; j<height; j++)
            {
                printf(" ");
            }
            for(j=1;j<=(2*i-1); j++)
            {
                printf("*");
            }
            printf("\n");
        }
        printf("\n");
    }
}

void draw_mountain_road (int length, int max_radius){
    
    int i,j,k;
    //Gets Lenght and maximim radius from user.
    printf("Please Enter the lenght of mountain road\n");
    scanf("%d",&length);
    printf("Please Enter the maximum radius of half circle\n");
    scanf("%d",&max_radius);

    int r , flag = 0 , space = max_radius;

    //Prints the Mountain Road.
    for(k=0 ; k<length ; k++){
        
        r = rand()%max_radius;
        
        if(r==0){
            if(r%2==1){
                for(i=0 ; i<max_radius+1 ;i++){
                    printf(" ");
                }
                printf("|\n");
            }
            else{
                for(i=0 ; i<=max_radius+1 ;i++){
                    printf(" ");
                }
                printf("|\n");
            }
        }
        else{

            if(k%2==0){
                for(i=0; i<r ; i++){
                    for(j=0 ; j<space + 1-i ; j++){
                        printf(" ");    
                    }
                printf("/");
                printf("\n");
                }
                for(i=0 ; i<space-r+1 ; i++){
                    printf(" ");
                }
                
                printf("|\n");
                
                for(i=0 ; i<r ; i++){
                    for(j=space+1 ; j>r-i-1 ; j--){
                        printf(" ");
                    }
                    printf("\\");
                    printf("\n");
                }
            }
            else{
                for(i=0 ; i<r ; i++){
                    for(j=0 ; j<=space+1+i ; j++){
                        printf(" ");
                    }
                    printf("\\");
                    printf("\n");
                }
                for(i=0 ; i<=r+space+1 ; i++){
                    printf(" ");
                }
                
                printf("|\n");

                for(i=0 ; i<r ; i++){
                    for(j=0 ; j<=r+space-i ; j++){
                        printf(" ");
                    }
                printf("/\n");
                }
            }
        }
    }
}