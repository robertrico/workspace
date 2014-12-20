#include<stdio.h>
#include "roblibs.h"
#include "robstack.h"
typedef bool(*Endor)();

typedef struct Test {
    char *hoth;
    Endor moon;
} Test;

bool tre(){
    return true;
}
bool flse(){
    return false;
}
int main(int argc, char *argv[]){
    Test test;
    test.moon = tre;
    if(test.moon()){
        printf("%s","It's a moon!");
    }   
    test.moon = flse;
    if(!test.moon()){
        printf("%s","This is negated");
    }   


    return 0;
}
