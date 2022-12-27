#include <stdio.h>
#include <math.h>

int * sortEveryThirdElement(int *a, int n) // Function is taking in array and n value 
{
    int size = floor(n/3); // Setting the size of the array to the floor of n/3
    int indexvalue=0; // Setting the index to 0
    int swap=0; // Setting the swap to 0
    
    int sort[size]; // Setting the size of the array to the size of the array
    
    for(int i=2;i<n;i=i+3) // Looping through the array and incrementing by 3 for all cases where i is less than n
    {
        sort[indexvalue]=a[i]; // Setting the value of the array at the index to the value of the array at i
        indexvalue++; // Incrementing the index
    }
    
    for(int k=0;k<size;k++) // Looping through the array and incrementing by 1 for all cases where k is less than the size of the array
    {
        for(int j=k+1;j<size;j++) // Looping through the array and incrementing by 1 for all cases where j is less than the size of the array
        {
            if(sort[k]>sort[j]) // If the value of the array at k is greater than the value of the array at j
            {
                swap=sort[k]; // Set the swap to the value of the array at k
                sort[k]=sort[j]; // Set the value of the array at k to the value of the array at j
                sort[j]=swap; // Set the value of the array at j to the swap
            }
        }
    }
    
    indexvalue = 0; // Setting the index to 0
    for(int i=2;i<n;i=i+3) // Looping through the array and incrementing by 3 for all cases where i is less than n
    {
        a[i]=sort[indexvalue]; // Setting the value of the array at i to the value of the array at the index
        indexvalue++; // Incrementing the index
    }
    return a;
}
void kSmallestAmongUntouched(int * a, int k, int n) //The function is taking array, and value of integer k and n 
{
    int size = n - floor(n/3); // Setting the size of the array to the value of n minus the floor of n/3
    int newSort[size]; // Setting the size of the array to the size of the array
    
    int indexvalue=0; // Setting the index to 0
    int swap=0; // Setting the swap to 0
    
    for(int i=0;i<n;i++) // Looping through the array and incrementing by 1 for all cases where i is less than n
    {
        if((i+1)%3!=0) // If the value of i mod 3 is not equal to 0
        {
            newSort[indexvalue]=a[i]; // Setting the value of the array at the index to the value of the array at i
            indexvalue++; // Incrementing the index
        }
    }
    
    for(int j=0;j<size;j++) //
    {
        for(int l=0;l<size;l++) // Looping through the array and incrementing by 1 for all cases where l is less than the size of the array
        {
            if(newSort[j]<newSort[l]) // If the value of the array at j is less than the value of the array at l
            {
                swap=newSort[j]; // Set the swap to the value of the array at j
                newSort[j]=newSort[l]; // Set the value of the array at j to the value of the array at l
                newSort[l]=swap; // Set the value of the array at l to the swap
            }
        }
    
    }
    
    for(int i=0;i<k;i++) // Looping through the array and incrementing by 1 for all cases where i is less than k
    {
        printf("%d ",newSort[i]); // Printing the value of the array at i
    }
   
}


int main() {
    
    int a[] = {17,47,68,28,13,8,19,38,31,51,27,48,43,567}; // Setting the array to the values given
    int n = sizeof(a)/sizeof(a[0]); // Setting the value of n to the size of the array divided by the size of the array at 0
    
    sortEveryThirdElement(a, n); // Calling the function sortEveryThirdElement
    
    for(int j=0;j<n;j++) // Looping through the array and incrementing by 1 for all cases where j is less than n
    {
        printf("%d ",a[j]); // Printing the value of the array at j
    }

    
    printf("\n");// Printing a new line
    
    kSmallestAmongUntouched(a, 3, n); // Calling the function kSmallestAmongUntouched
    
    return 0;
}