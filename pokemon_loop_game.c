#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define SQUARE 1
#define RECTANGULAR 2
#define CIRCULAR 3
#define RED 0
#define YELLOW 1
#define BLUE 2
#define BLACK 3
#define WHITE 4
#define PI 3



double CreateBody (int shape); // This function calculates shape's area and return it.
int SetColor (int color);   // This function takes integer value and return the modulo 5 of value
double LoadMoves(int shape, double body_size); // This function takes shape and shape's area and return the shape's perimeter.
int SetAtackPower(int lower_bound, int upper_bound); // This function generates a random integer attack power between the bounds and returns the power.
void ShowPokemon(int shape, double size_of_body, int color, double move_length, int attack_power); // This function prints created Pokémon.


int main(){
    int shape , color , attack_power;
    double size_of_body , move_lenght;
    shape = RECTANGULAR; //Shape could be SQUARE , RECTANGULAR or CIRCULAR.
    size_of_body = CreateBody(shape); //Calculates shape of area.
    color = 798;
    color = SetColor(color); // 
    move_lenght = LoadMoves(shape,size_of_body); // Set color.
    attack_power = SetAtackPower(0 , 150); // generates a random attack power between bounds.
    ShowPokemon(shape , size_of_body , color , move_lenght , attack_power); //Prints created Pokémon.
}

double CreateBody(int shape){
    int lenght1 , lenght2 ,radius;
    double area ;

    //Calculates area of Square.
    if(shape == 1){
        printf("Please Enter the Side of Square : \n");
        scanf("%d", &lenght1); //Takes side of square from user.
        area = lenght1*lenght1;       
    }
    //Calculates area of Rectangle.
    else if(shape == 2){
        printf("Please Enter the Sides of Rectangular : \n");
        scanf("%d%d", &lenght1 , &lenght2); //Takes sides of rectangle from user.
        area = lenght1 * lenght2;       
    }
    //Calculates area of Circle.
    else if(shape == 3){
        printf("Please Enter the Radius of Circle : \n");
        scanf("%d", &radius); //Takes radius of circle from user.
        area = PI * radius * radius;
        
    }
    return area; 
}

int SetColor (int color){
    if(color >= 0 && color <= 1000){ 
        return (color % 5); //If number between 0-1000 , function returns the modulo 5 of number . Otherwise return 1.
    }
    else
    {
        return 1; 
    }
}

double LoadMoves(int shape, double body_size){
    double move_lenght , edge1 , edge2;
    
    //Calculates perimeter of Square.
    if(shape == 1){
        edge1 = sqrt(body_size); //Finds edge of square
        move_lenght = 4 * edge1; //Finds perimeter of Square.
    }
    //Calculates perimeter of Rectangle.
    else if(shape == 2){
        edge1 = 5; //Assume that the shorter edge is 5.
        edge2 = (body_size / edge1); //Finds the other edge.
        move_lenght = 2 * (edge1 + edge2); //Calculates perimeter of rectangle.
    }
    //Calculates perimeter of circle.
    else if(shape == 3){
        body_size = body_size / PI; //Finds square of radius.
        move_lenght = 2 * PI * sqrt(body_size); //Calculates perimeter of circle.
    }
    return move_lenght;
}

int SetAtackPower(int lower_bound , int upper_bound){
    int power;
    srand(time(NULL));
    power = lower_bound + rand()%upper_bound;//Generates attack power between bounds.
    return power;
}

void ShowPokemon(int shape, double size_of_body, int color, double move_length, int attack_power){
    
    int i , j;

    //Prints shape of Square Pokémon.
    if(shape == 1){
        int side;
        
        side = sqrt(size_of_body);
        
        for(i=0 ; i<side ; i++){
            for(j=0 ; j<side ; j++){
                printf("X");
            }
        printf("\n");
        }
    }
    //Prints shape of Rectangle Pokémon.
    else if(shape == 2){
        int edge1 , edge2 ;
        edge1 = 5;
        edge2 = size_of_body / edge1;
        if(edge1<edge2){
            for(i=0 ; i<edge1 ; i++){
                for(j=0 ; j<edge2; j++){
                    printf("X");
                }
            printf("\n");
            }
        }
        if(edge2<edge1){
            for(i=0 ; i<edge2 ; i++){
                for(j=0 ; j<edge1; j++){
                    printf("X");
                }
            printf("\n");
            }
        }
    }
    //Prints shape of Circle Pokémon.
    else if(shape == 3){
        int radius;
        
        
        radius=sqrt(size_of_body/PI); //Finds radius of circle.
        
        //Prints shape of Circle Pokémon(if radius equals to odd number).
        if(radius%2==1){
        
        for(i=0 ; i<=(radius/2) ; i++){
            for(j=0 ; j<(radius/2)-i ; j++){
                printf("\t");
            }
        if(i==0){
            printf("X\n");
        }
        else{
            printf("X");
            for(j=0 ; j<i*2 ; j++){
                printf("\t");
            }
            printf("X\n");
        }
    }
    for(i=0 ; i<(radius/2) ; i++){
        for(j=0 ; j<i+1 ; j++){
            printf("\t");
        }
    if(i==(radius/2)-1){
        printf("X\n");
    }
    else{
        printf("X");
        for(j=0 ; j<(radius-((i+1)*3)+i);j++){
            printf("\t");      
        }
        printf("X\n");
        }
    }
    
    }

    //Prints shape of Circle Pokémon(if radius equals to even number).
    else{

        for(i=0 ; i<=(radius/2) ; i++){
            for(j=0 ; j<(radius/2)-i ; j++){
                printf("\t");
            }
        if(i==0){
            printf("X\n");
        }
        else{
            printf("X");
            for(j=0 ; j<i*2 ; j++){
                printf("\t");
            }
            printf("X\n");
        }   
        
        }

    for(i=0 ; i<(radius/2) ; i++){
        for(j=0 ; j<i+1 ; j++){
            printf("\t");
        }
        if(i==(radius/2)-1){
            printf("X\n");
        }
        else{
            if(i==(radius/2)-2){
            printf("X");
                for(j=0 ; j<15 ; j++){
                    printf(" ");
                }
                printf("X\n");
            }
            else{
                
                printf("X");
            for(j=0 ; j<=(radius-((i+1)*3)+i);j++){
                printf("\t");      
            }
            printf("X\n");
            }
        }
    }
    
    }
        

}
    //Prints name of (shape) Pokemon 
    if(shape == 1){
        printf("Square Pokemon\n"); 
    }
    else if(shape == 2){
        printf("Rectangular Pokemon\n");
    }
    else if(shape == 3){
        printf("Circular Pokemon\n");
    }
    
    printf("Size : %.2lf\n",size_of_body); // Prints area of shape.
    
    //Prints color of Pokemon
    if(color == 0){
        printf("Color : Red\n");
    }
    else if(color == 1){
        printf("Color : Yellow\n");
    }
    else if(color == 2){
        printf("Color : Blue\n");
    }
    else if(color == 3){
        printf("Color : Black\n");
    }
    else if(color == 4){
        printf("Color : White\n");
    }
    
    printf("Move : %.2lf\n",move_length); // Prints Move size of Pokemon(perimeter).

    printf("Attack Power : %d\n",attack_power); // Prints Attack power of Pokemon.
}


