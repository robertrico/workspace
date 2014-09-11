#include <stdio.h>

main(void){
	int count = 0;
	do{
		go();
		count++;
	}while (count < 10);
	
}

go(){
	printf("Hello World\n");
}