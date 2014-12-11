#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
//prototypes
char** array(char * pnt, int size, int indexSize);
struct Arr;
void addTo(struct Arr *which,char *word);
void printArr(struct Arr *which,int position);
struct Arr *Arr_Create(int size,int wordSize);
bool isinarray(long val, long *arr, long size);
char * pop(struct Arr *array);
void push(struct Arr *array,char * word);

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

struct Arr {
    char **array;
    int size;
    int position;
};

//TODO remove this and make studyguide say push
void addTo(struct Arr *which, char *word){
    int i = which->position;
    which->array[i] = word;
    which->position += 1;
}
void addAt(struct Arr *array,int position, char *word){
    int i = array->position;
    while(i != position){
        array->array[i] = array->array[i-1];
        i--;
    }
    array->array[position] = word;
    array->position++;
}

void printArr(struct Arr *which, int position){
    printf("%s",which->array[position]);
}

struct Arr *Arr_Create(int size,int wordSize){
    struct Arr *make = malloc(sizeof(struct Arr));
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
char * pop(struct Arr *array){
    char * pop = array->array[array->position-1];
    array->array[array->position-1] = NULL;
    array->position -= 1;
    return pop;

}
void push(struct Arr *array,char * word){
    int i = array->position;
    array->array[i] = word;
    array->position += 1;
}

