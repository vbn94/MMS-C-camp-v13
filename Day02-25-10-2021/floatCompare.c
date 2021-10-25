#include <stdio.h>
#include <math.h>

// build-in compare operator
int floatCompare1(float a, float b){
    return a == b;
}

// fixed epsilon
int floatCompare2(float a, float b){
    return fabs(a - b) < 1.0e-5f;
}

// adaptive epsilon
int floatCompare3(float a, float b){
    return fabs(a - b) < 1.0e-5f * fmax(fabs(a), fabs(b));
}

int main(void){
    float a = 10.0f * 0.1f;
    float b = 0.0f;
    for (int i = 0; i < 10; i++, b += 0.1f);
    if (floatCompare3(a, b)){
        printf("Equals\n");
    } else {
        printf("Not equals\n");
    }
    return 0;
}
