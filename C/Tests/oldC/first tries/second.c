#include <stdio.h>

main(){
	int count;
	int add;
	int divs;
	puts("Please Enter a number");
	scanf("%d", &count);
	puts("Enter a multiplier");
	scanf("%d", &add);
	puts("Divided by");
	scanf("%d", &divs);
	printf("The number is %d \n", (count*add)/divs);
}