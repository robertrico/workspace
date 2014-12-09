#include <stdio.h>
#include <stdlib.h>
//prototypes
char** array(char * pnt, int size, int indexSize);
struct Arr;
void add(struct Arr *which,char *word);
void printArr(struct Arr *which,int position);
struct Arr *Arr_Create(int size);

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

void add(struct Arr *which, char *word){
    int i = which->position;
    which->array[i] = word;
    which->position += 1;
}

void printArr(struct Arr *which, int position){
    printf("%s\n",which->array[position]);
}

struct Arr *Arr_Create(int size){
    struct Arr *make = malloc(sizeof(struct Arr));
    assert(make != NULL);

    char **a = array(*a,size,10);

    make->position = 0;
    make->array = a;
    make->size = size;


    return make;
}

