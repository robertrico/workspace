#include <string.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "roblibs.h"
#include "macros.h"

//YAY, now you can call shit, without being redundant

void convert(Arr *tokens,Arr *operators);
void buildOp(Arr *ops);
bool isLeftAssociative(char *numOp);
bool hasPrecedence(char *topOfStack,char *numOp);


bool isLeftAssociative(char *numOp)
{
    return !(numOp == "^");
}
//TODO Probably don't need all these bools
bool hasPrecedence(char *topOfStack,char *numOp)
{
    bool stackIsHigher = topOfStack == "*" || topOfStack == "/"; 
    bool currentOpIsLower = numOp == "+" || numOp == "-"; 
    if(stackIsHigher && currentOpIsLower){
        return false;
    }else{ 
        return true;
    }
}

//TODO needs to returne the converted
void convert(Arr *tokens,Arr *operators)
{
    //Create and allocate memory for final converted string
    char *converted;
    converted = malloc(128);


    //create Arr structure to be used as stack
    Stack *stack = Stack_Init(32,32);

    //iterative counter
    int i;
    i = 0;

    while(*tokens->array[i] != '\000'){
        if(*tokens->array[i] == '('){
            push(tokens->array[i]);
            //stack->push(stack,tokens->array[i]);
        }else if(*tokens->array[i] == ')'){
            while(*stack->peek(stack) != '('){
                //contatenate 
                converted = strcat(converted,pop(stack));
            }
            stack->pop(stack);
        }else if(contains(operators,tokens->array[i])){
            //when there is an operator inside the paren,failes
            //figure out how to compare it.
            if(stack->peek(stack) != '\0' && (hasPrecedence(stack->peek(stack),tokens->array[i])))
                converted = strcat(converted,pop(stack));
            push(tokens->array[i]);
            //stack->push(stack,tokens->array[i]);
        }else{
                //contatenate 
            converted = strcat(converted,tokens->array[i]);
        }
        i++;
    }

    //concatenate the rest of the stack onto string
    int x = stack->position-1;
    while(!stack->isEmpty(stack)){
        strcat(converted,stack->pop(stack));
        x--;
    }

    printf("\n%s",converted);
    printf("\n");
}

/**
 * Create Arr structure of operators to 
 * test against
 */
void buildOp(Arr *ops)
{
    addTo(ops,"+");
    addTo(ops,"-");
    addTo(ops,"/");
    addTo(ops,"*");
    addTo(ops,"^");
    addTo(ops,'\0');
}

int main()
{
    Arr *tokens = Arr_Create(32,32);

    //build operators structure
    Arr *operators = Arr_Create(32,32);
    buildOp(operators);

    char *equation;
    equation = malloc(128);

    fgets(equation,128,stdin);

    //@source robstring.h
    tokenize(tokens,equation);

    int i;
    for(i = 0; i < tokens->position; i++){
        //@source robarr.h
        printArr(tokens,i);
    }

    convert(tokens,operators);
    free(tokens);
    return 0;
}
