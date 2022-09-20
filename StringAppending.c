// Code to append two strings

#include<stdio.h> // standard input output library
#include<string.h> // standard library for string functions
#include<stdlib.h> // standard library for memory allocation    

//*********************************************************

int main(){ // main function
    char *string_1 = "abcdef"; // Address of String 1 
    char *string_2 = "xyzw";    // Address of String 2
    int len1 = strlen(string_1);  //calculate the length of string 1
    int len2 = strlen(string_2);  //calculate the length of string 2
    int len = len1>len2?len1:len2; // find the maximum length of the two strings
    char *string_3 = malloc((len1+len2+1)*sizeof(char)); // allocate memory for the new string to accomdate the two strings and the null character
    int i = 0; // index for string 1
    int j = 0;
    int k = 0;


    while(i<len1 && j<len2){ // append the two strings till the end of the shorter string
        string_3[k++] = string_1[i++]; // append the characters of the two strings to the new string
        string_3[k++] = string_2[j++];
    }
    while(i<len1){ // append the remaining characters of the longer string
        string_3[k++] = string_1[i++];
    }
    while(j<len2){ // append the remaining characters of the longer string
        string_3[k++] = string_2[j++];
    }

    string_3[k] = '\0'; // add the null character at the end of the new string
    printf("%s", string_3); // print the new string
    free(string_3); // free the memory allocated for the new string
    return 0;
}

//*********************************************************