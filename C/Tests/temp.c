struct test
{
    char **wordbank;
    char **answerbank;
    size_t test_len;
};

struct test *test_new(int fd)
{
    /*malloc a new test*/
    /*return the new test struct*/
}

void test_free(struct test *t)
{
    /*free the test struct*/
}

char *test_get_question(struct test *t, int question)
{
    return t->wordbank[question];
}

char *test_get_answer(struct test *t, int question)
{
    return t->answerbank[question];
}
