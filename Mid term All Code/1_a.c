#include<stdio.h>
#include <stdbool.h>

void basicFizzBuzz(int x) {   // Making the function to check condition for divisibility
    if (x % 3 == 0 || x % 5 == 0 || x % 11 == 0 || x % 13 == 0 || x % 33 == 0 || x % 39 == 0 || x % 55 == 0 || x % 65 == 0) { // Checking for divisibility of all the number we are interested in
        if (x % 3 == 0 || x % 5 == 0) { // checking of the first condition of divisibility by 3 and 5
            printf("fizz\n");     // if the conditon is matched then print fizz
        }
        if (x % 11 == 0 || x % 13 == 0) { // checking of the second condition of divisibility by 11 and 13
            printf("buzz\n");    // if the conditon is matched then print buzz
        }
        if (x % 33 == 0 || x % 39 == 0 || x % 55 == 0 || x % 65 == 0) { // checking of the third condition of divisibility by 33, 39, 55 and 65
            printf("fizzbuzz\n"); // if the conditon is matched then print fizzbuzz
        }
    }
    else { // if the number is not divisible by any of the number we are interested in then print the number itself
        printf("%d\n", x); // printing the number
    }
}

int main() {
    //declare x
    int x=0;


    printf("Enter a number: "); // asking for input that needs to be checked 
    scanf("%d", &x);  // taking input from the user


    basicFizzBuzz(x); // calling the function to check the condition

    return 0;
}