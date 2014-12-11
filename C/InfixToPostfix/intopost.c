#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "robstring.h"
void convert(struct Arr *tokens);
void convert(struct Arr *tokens){
    char *converted;
    struct Arr *stack = Arr_Create(32,32);

    int i;
    i = 0;
    while(tokens->array[i] != NULL){
        if(*tokens->array[i] == '('){
            push(stack,tokens->array[i]);
        }else if(*tokens->array[i] == ')'){
            while(*tokens->array[i] != '('){

            }
        }
        printArr(tokens,i);
        fflush(stdout);
        i++;
    }
    int x;
    for(x = 0; x < stack->position; x++){
        printArr(stack,x);
        fflush(stdout);
    }
    printf("\n");
}



int main(){
    struct Arr *tokens = Arr_Create(32,32);
    char *equation;
    equation = malloc(128);

    fgets(equation,128,stdin);

    tokenize(tokens,equation);
    int i;
    for(i = 0; i < tokens->position; i++){
        printArr(tokens,i);
    }

    convert(tokens);
    free(tokens);
    return 0;
}
