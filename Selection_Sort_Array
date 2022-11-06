#include <stdio.h> 
int main(){
    int i; // we take i as the index of the array 
    int j;  // we take j as the index of the array
    int temp; //  let temp be a temporary variable 
    int a[9];  // we take an array of size 9 = a[9]  
    for (i=0;i<9;i++){ // for loop to take input from the user     
        printf("Enter the number: "); //Here we enter the numbers to be sorted 
        scanf("%d",&a[i]); //this is for storing the numbers that we entered in the array
    }
    for (i=0;i<8;i++) // This is outer loop where we will compare the numbers 
    {
        for (j=i+1;j<9;j++) // This is inner loop where we will compare the numbers 
        {
            if (a[i]>a[j]) // This is the condition where we will compare the numbers 
            temp=a[i]; // Here we will store the value of a[i] in temp 
            a[i]=a[j]; // Here we will store the value of a[j] in a[i] 
            a[j]=temp; // Here we will store the value of temp in a[j] 
            
        }
    }
    printf("The sorted array is: "); 
    for (i=0;i<9;i++) {  // for loop to print the sorted array      
        printf("%d ",a[i]); // this is to print the sorted array
    }
    return 0;
}
