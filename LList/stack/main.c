#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


int main(void){
    
    return 0;
}

/*int main(void){
    stack_t* operators = createStack();
    stack_t* numbers  = createStack();
    char *expr = (char*)malloc(100);
    printf("Enter expression: ");
    fgets(expr, 100, stdin);
    expr[strlen(expr) - 1] = '\0';
    while (*expr){
        if (*expr == '+' || *expr == '*'){
            push(operators, *expr);
        } else if (*expr >= '0' && *expr <= '9'){
            push(numbers, *expr - '0');
        } else if (*expr == '('){
            push(numbers, '(');
        } else if (*expr == ')'){
            int op;
            pop(operators, &op);
            if (op == '+'){
                int result = 0;
                for(;;){
                    int num;
                    pop(numbers, &num);
                    if (num == '('){
                        break;
                    }
                    result += num;
                }
                push(numbers, result);
            } else if (op == '*'){
                int result = 1;
                for(;;){
                    int num;
                    pop(numbers, &num);
                    if (num == '('){
                        break;
                    }
                    result *= num;
                }
                push(numbers, result);
            }
        }
        expr++;
    }
    int result;
    pop(numbers, &result);
    printf("Result = %d\n", result);
    return 0;
}*/