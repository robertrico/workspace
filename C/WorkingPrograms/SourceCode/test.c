#include <stdio.h>
#include <string.h>
#include "test.h"
void main(){
    struct test f;
    f.x = 150;
    printf("%d\n",f.x);
    int x = 0;
    printf("%d",test_get_question(f));
}
void test_free(struct test *t)
{
    /*free the test struct*/
}

struct test *test_new(int fd)
{
    /*malloc a new test*/
    /*return the new test struct*/
}
int test_get_question(struct test t)
{
    return t.x;
    //return t->wordbank[question];
}

/*char *test_get_answer(struct test *t, int question)
{
    return t->answerbank[question];
}*/
void hello(){
    printf("%s","Hello");
}
