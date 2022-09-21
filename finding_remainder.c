// Code to find the remainder of from division of two numbers 

#include <stdio.h> // standard input output library

//****************************************************************************

int main(){    // main function
int number_1,number_2,negative_number,remainder_1,remiander_2;
number_1 = -3;
number_2 = 2;
negative_number = -2;

remainder_1= number_1%number_2; //Calculate the remainder of the division of number_1 and number_2
remiander_2 = number_1%negative_number; //Calculate the remainder of the division of number_1 and negative_number

//****************************************************************************

printf(remainder_1); // print the remainder of the division of number_1 and number_2
printf(remiander_2);  //    print the remainder of the division of number_1 and negative_number
}