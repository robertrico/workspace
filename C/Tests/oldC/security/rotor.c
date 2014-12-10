#include <stdio.h>
#include <stdlib.h>

int *rotatefirst(int arr[],int shift); /* Rotate first */

	
const char calpha[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int *rotatefirst(int arr[], int shift){
	/*int rotorone[10];*/
	int i,j;

/* Shift Array */
	for (i = 0; i < 26; i++){
		arr[i] = i;
	}
	for (j = 0; j < 26; j++){
		arr[j] = arr[j] + shift;
		if(arr[j] >= 26){
			arr[j] = (arr[j]-26);
		}
		//printf("%d ",arr[j]);
		//printf("%c ",calpha[j]);
	}
	return arr;
	//printf("\n");


}

main()
{
	int arr[26];
	int *arr2[26];
	int k,p;
	char *n;
	char **n = &n;
	for (k = 0; k < 26; k++){
		rotatefirst(arr,k);
	}
	//printf("\n");
	//printf("%c", calpha[2]);
	//printf("\n");
	while (p != -1){
		printf("Enter your number: ");
		scanf("%d", &p);
		//printf("%c", calpha[p]);
		printf("\n");
		arr2[26] = rotatefirst(arr,3);
		n = &arr2[1];
		printf("%c", *arr2[1]);
	}


	
	return 0;
}


