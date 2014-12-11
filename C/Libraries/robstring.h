#include <string.h>
#include <stdlib.h>
#include "robarr.h"

char toLowerCase(char *buf);
void tokenize(struct Arr *array,char *equation);

char toLowerCase(char *buf){
    int i;
    for(i = 0; buf[i]; i++){
        buf[i] = tolower(buf[i]);
    }
}

void tokenize(struct Arr *array,char *equation){
    char *token;
    token = strtok(equation," ");
    while (token != NULL){
        addTo(array,token);
        //printf ("%s\n",token);
        token = strtok(NULL," ");
    }
}
