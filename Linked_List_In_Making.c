#include <stdio.h>
#include <stdlib.h>


int blah() {
    int * a;
    int i, n, val;

    n = 3;
    a = malloc(n * sizeof(int));

    // enter data
    i = 0;
    scanf("%d", &val);
    while(val>0){
        a[i] = val;
        i = i+1;
        if(i>=n) {
            n = n*2;
            a = realloc(a, n * sizeof(int));
        }
        scanf("%d", &val);
    }
    n = i;
    a = realloc(a, n * sizeof(int));

    // print data
    for(i=0; i<n; i++) {
        printf("%d ", a[i]);
    }

    printf("\n\nDone!\n");
    
    return 0;
}

struct nodeType {
    int value;
    struct nodeType * next;
};

typedef struct nodeType Node;

int main(int argc, char **argv) {
    int i, val;
    Node * head = NULL;
    Node * temp = NULL;

    i = 0;
    scanf("%d", &val);
    while(val>0){
        temp = malloc(sizeof(Node));
        temp->value = val;
        temp->next = NULL;

        // if this is the first time
        // or else

        i = i+1;
        scanf("%d", &val);
    }
    return 0;
}
