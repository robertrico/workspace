#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
//prototypes
char** array(char * pnt, int size, int indexSize);

typedef struct Arr {
    char **array;
    int size;
    int position;
} Arr;

void tokenize(Arr *array,char *equation);
void addTo(Arr *which,char *word);
void printArr(Arr *which,int position);
Arr *Arr_Create(int size,int wordSize);
bool isinarray(long val, long *arr, long size);
//char * pop(Arr *array);
//void push(Arr *array,char * word);

char** array(char * pnt, int size,int indexSize){
    int i;
    char **a = malloc(sizeof *pnt * size);
    if (a){
        for (i = 0; i < size; i++){
            a[i] = malloc(sizeof *a[i] * indexSize);
        }
    }
    return a;
}



//TODO remove this and make studyguide say push
void addTo(Arr *which, char *word){
    int i = which->position;
    which->array[i] = word;
    which->position += 1;
}
void addAt(Arr *array,int position, char *word){
    int i = array->position;
    while(i != position){
        array->array[i] = array->array[i-1];
        i--;
    }
    array->array[position] = word;
    array->position++;
}

void printArr(Arr *which, int position){
    printf("%s",which->array[position]);
}

Arr *Arr_Create(int size,int wordSize){
    Arr *make = malloc(sizeof(Arr));
    assert(make != NULL);

    char **a = array(*a,size,wordSize);

    make->position = 0;
    make->array = a;
    make->size = size;


    return make;
}
bool isinarray(long val, long *arr, long size){
    int i;
    for (i=0; i < size; i++) {
        if (arr[i] == val)
            return true;
    }
    return false;
}
/*
char * pop(Arr *array){
    char * pop = array->array[array->position-1];
    array->array[array->position-1] = NULL;
    array->position -= 1;
    return pop;

}
void push(Arr *array,char * word){
    int i = array->position;
    array->array[i] = word;
    array->position += 1;
}
char * peek(Arr *array){
    return  array->array[array->position-1];
}*/
bool contains(Arr *array,char *compareTo){
    int x;
    x = 0;
    while(array->array[x] != NULL){
        if(*compareTo == *array->array[x]){
            return true;
        }
        x++;
    }
    return false;

}
void tokenize(struct Arr *array,char *equation){
    char *token;
    token = strtok(equation,"\n ");
    while (token != NULL){
        addTo(array,token);
        //printf ("%s\n",token);
        token = strtok(NULL,"\n ");
    }
}
