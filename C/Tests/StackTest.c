#include "robstack.h"
int main(){
    Stack *test;
    test = Stack_Init(32,32);
    test->push(test,"hi\n");
    printf("%s",test->peek());


    test->push(test,"hello corinne");
    printf("%s",test->pop(test));
    printf("\n");
    printf("%s",test->pop(test));
    printf("%d\n",test->position);
    printf("%d",test->isEmpty(test));

    free(test);
    return 0;

}
