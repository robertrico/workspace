struct test
{
    int x;
    //char **wordbank[8];
    //char **answerbank;
    //size_t test_len;
};

struct test *test_new(int fd);
int test_get_question(struct test t);
char *test_get_answer(struct test *t, int question);

void hello();
