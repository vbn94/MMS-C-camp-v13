#include <stdio.h>
#include <stdlib.h>
#include "llist.h"
#include <time.h>

#define N 10

int compare(int a, int b){
    return b - a;
}

int main(void){
    srand(time(NULL));
    node_t* list = NULL;
    for (int i = 0; i < N; i++){
        push(&list, rand() % 101);
    }
    print_list(list);
    mergeSort(&list, compare);
    printf("Sorted: ");
    print_list(list);
    listFree(&list);
    return 0;
}
