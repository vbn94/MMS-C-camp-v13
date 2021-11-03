#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN(arr) (sizeof(arr)/sizeof(*arr))

int compareInt1(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int compareDouble(const void* a, const void* b){
    double num1 = *(double*)a;
    double num2 = *(double*)b;
    if (num1 < num2){
        return 1;
    } else if (num1 > num2){
        return -1;
    }
    return 0;
}


void printArray(double* arr, size_t n){
    for (int i = 0; i < n; i++){
        printf("%lf ", *(arr+i));
    }
    putchar('\n');
}


void swap(int* a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapUni(void* a, void *b, size_t size){
    char temp[size];
    memmove(temp, a, size);
    memmove(a, b, size);
    memmove(b, temp, size);
}

int compareInt2(int a, int b){
    return b - a;
}

void bubbleSort(void* arr, size_t nmemb, size_t size, int (*cmp)(const void*,const void*)){
    for (int j = 0; j < nmemb; j++){
        int swapped = 0;
        for (int i = 0; i < (nmemb - j - 1) * size; i += size){
            if (cmp(arr + i, arr + i + size) > 0){
                swapUni(arr + i, arr + i + size, size);
                swapped = 1;
            }
        }
        if (!swapped){
            return; // sorted break
        }
    }
} // broi 1 ->>>>>   0b1000000, 0b0000011, 0x0f, 0xaf, 0xffff.......



void* linearSearch(const void* key, void* arr, size_t nitems, size_t size, int (*cmp)(const void* a, const void* b)){
    for (int i = 0; i < nitems * size; i += size){
        if (cmp(arr + i, key) == 0){
            return arr + i;
        }
    }
    return NULL;
}

int main(void){
    int arr[] = { 10, 20, 3, 3, 3, -5, 3, 6, 7, 8, 22, -3 };
   // qsort(arr, LEN(arr), sizeof(int), compareInt1);
    int key = 3000;

    int* element = (int*)linearSearch(&key, arr, LEN(arr), sizeof(int), compareInt1);
   
    if (element == NULL){
        printf("Not found!\n");
    } else {
        printf("Found: %d\n", *(element));
    }


    //double reals[] = { 23.34, 43.45, 4, -44.5, 3.1415, 45 };

   // bubbleSort(reals, LEN(reals), sizeof(double), compareDouble);
    //printArray(reals, LEN(reals));
 
    return 0;
}