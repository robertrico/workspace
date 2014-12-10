#include <stdlib.h>
char toLowerCase(char *buf);

char toLowerCase(char *buf){
    int i;
    for(i = 0; buf[i]; i++){
        buf[i] = tolower(buf[i]);
    }
}
