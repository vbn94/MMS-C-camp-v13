#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct s {
    char a;
    char c;
    int b;
};

typedef union {
    uint8_t data;
    struct {
        uint8_t b0 : 1,
                b1 : 1,
                b2 : 1,
                b3 : 1,
                b4 : 1,
                b5 : 1,
                b6 : 1,
                b7 : 1;
    } bit;
} mask;

typedef struct {
    unsigned bf : 4;
} bitf;

typedef struct {
    double x[2];
} str;

struct stu_a {
    int i;
    char c;
};

struct stu_b {
    long l;
    char c;
};

struct stu_c {
    int i;
    long l;
    char c;
};

struct stu_d {
    long l;
    int i;
    char c;
};

struct stu_e {
    double d;
    int i;
    char c;
};

struct stu_f {
    int i;
    double d;
    char c;
};

int main(void){
    printf("Size: %ld\n", sizeof(struct stu_f));
    return 0;
}