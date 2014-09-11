#include <stdio.h>

const char* DIGITS[] = {"0","1","2","3","4","5","6","7","A","B","C","D","E","F"};
main()
{
	int i;
	for (i = 0; i<14; i++){
		printf("%s",DIGITS[i]);
		printf("\n");
	}
	printf("\n");
	return 0;
}


