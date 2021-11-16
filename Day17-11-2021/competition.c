#include <sys/mman.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


int main(void){
    int* num = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS , -1, 0);
    if (MAP_FAILED == num){
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid == 0){
        for (int i = 0; i < 100000; i++){
            (*num)++;
        }
    } else {
        wait(NULL);
        for (int i = 0; i < 100000; i++){
            (*num)++;
        }
        printf("Number = %d\n", *num);
    }

    return EXIT_SUCCESS;
}