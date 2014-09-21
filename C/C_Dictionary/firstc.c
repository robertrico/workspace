#include<stdio.h>

const char *bank[4] = {"Cat","Dog","Elephant","Pig"};

main()
{
	printf("Hello, World!\n");
    world(*bank[2]);
	return 0;
}

world(x)
{
    printf("%c",x);
    printf("\n");
}
