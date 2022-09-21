//Code to find the midValue value of a given array

#include<stdio.h> 
#include<stdlib.h>
#include<string.h> // standard library for string functions



// ==============================================================================================

int midterm(int l, int r, int target, int a[]) { // function to find the midValue value of a given array
   int midValue = (l + r) / 2;
   if(a[midValue] == target) {
       return midValue;
   }
   else if(a[midValue] < target) {
       return midterm(midValue + 1, r, target, a);
   }
   else {
       return midterm(0, midValue - 1, target, a);
   }

// ==============================================================================================
}
void solve() {
   int array[]= {1 , 2, 3, 4, 5};
  printf("%d", midterm(0, 5, 3, array));
}

int main() {
   solve();
   return 0;
}

// ==============================================================================================

// Code of also done with ICP and FCP course - Concept taken from there and modified for c 