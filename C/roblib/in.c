#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include<robarr.h>
int main(int argc, char *argv[]){

    struct Arr *arr1 = Arr_Create(10);


    add(arr1,"Ned");
    add(arr1,"Sam");
    add(arr1,"James");
    add(arr1,"Peach");
    add(arr1,"Mushroom");

    int i;
    for (i = 0; i < arr1->position; i++){
        printArr(arr1,i);
    }

    return 0;
}
