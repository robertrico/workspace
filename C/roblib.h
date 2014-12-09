#include <stdlib.h>
//prototypes
char** array(char * pnt, int size, int indexSize);
void add(char ** array, char * word, int position);

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
void add(char ** array,char * word,int position){
    array[position] = word;
}
int size(){
    return sizeof a;
}

