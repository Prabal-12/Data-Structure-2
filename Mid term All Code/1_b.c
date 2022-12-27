#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
/*Assume you have an array f of length nf, and an array b of length nb, each con-
taining the integers you need to check for to print fizz and buzz.
So, for each integer in your input array a of length m, you need to check if it’s divisible by
something in f. If so, you should print “fizz”; if it’s divisible by something in b, you should
print “buzz”; and if it is divisible by something in f and b, you should print “fizzbuzz”.*/
void advancedFizzBuzz (int *a , int m, int *b , int nb , int * f , int nf ) {
    int i = 0, j = 0, k = 0;
    bool divisible = false;
    for (i = 0; i < m; i++) {
        for (j = 0; j < nf; j++) {
            for (k = 0; k < nb; k++) {
                if (a[i] % f[j] == 0 && a[i] % b[k] == 0) { // checking if the number is divisible by both the numbers in the array
                    divisible = true;
                    printf("fizzbuzz ");
                    break;
                }
            }
            if (a[i] % f[j] == 0 && !divisible) { // checking if the number is divisible by the number in the array
                divisible = true;
                printf("fizz ");
            }
        }
        for (j = 0; j < nb; j++) {    // checking if the number is divisible by the number in the array
            if (a[i] % b[j] == 0 && !divisible) {
                divisible = true;
                printf("buzz ");
            }
        }
        if (!divisible) {
            printf("%d ", a[i]); // printing the number if it is not divisible by any of the numbers in the array
        }
        divisible = false;
    }
}

int main(void) {

    //random array for fizzbuzz
    int f[] = {3, 5};
    int b[] = {11, 13};
    int a[] = {1, 9, 12, 33, 22, 45, 23, 45, 13, 15, 17};


    int nf = 2;
    int nb = 2;
    int m = 11;

    advancedFizzBuzz(a, m, b, nb, f, nf);
    
}