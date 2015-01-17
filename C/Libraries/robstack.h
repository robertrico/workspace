#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
//prototypes
char** elements(char * pnt, int size, int indexSize);

typedef void(*stackPush)();
typedef char*(*stackPop)();
typedef char*(*stackPeek)();
typedef bool(*stackIsEmpty)();

typedef struct Stack {
    //function pointers
    stackPush push;
    stackPop pop;
    stackPeek peek;
    stackIsEmpty isEmpty;
    //properties
    char **elements;
    int size;
    int position;
} Stack;

char * pop(Stack *stack);
void push(Stack *stack,char * word);
char * peek(Stack *stack);
bool  isEmpty(Stack *stack);
Stack *Stack_Init(int size,int wordSize);

char** elements(char * pnt, int size,int indexSize){
    int i;
    char **a = malloc(sizeof *pnt * size);
    if (a){
        for (i = 0; i < size; i++){
            a[i] = malloc(sizeof *a[i] * indexSize);
        }
    }
    return a;
}


Stack *Stack_Init(int size,int wordSize){

    Stack *make = malloc(sizeof(Stack));
    assert(make != NULL);
    char **a = elements(*a,size,wordSize);
    //properties
    make->elements = a;
    make->elements[0] = '\0';
    make->position = 0;
    make->size = size;
    //function pointers
    make->push = push;
    make->pop = pop; 
    make->peek = peek;
    make->isEmpty = isEmpty;
    return make;
}
char * pop(Stack *stack){
    char * pop = stack->elements[stack->position-1];
    stack->elements[stack->position-1] = NULL;
    stack->position -= 1;
    return pop;

}
void push(Stack *stack,char * word){
    int i = stack->position;
    stack->elements[i] = word;
    stack->position += 1;
}
char * peek(Stack *stack){
    if(stack->position-1 < 0) 
        return '\0';
    return  stack->elements[stack->position-1];
}
bool isEmpty(Stack *stack){
    return stack->position == 0;
}
