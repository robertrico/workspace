#include<stdio.h>
#include <string.h>
#include <stdlib.h>

//Constant Defintions
static const SIZEOFBANK=16;
static const SIZEOFWORDS=16;
static const int key[4] = {2,3,1,4};

//Prototypes
void wordbank(char **a);
void ask();

//Main function
int main(int argc, char *argv[]){

    int i;
    char **a = malloc(sizeof *a * SIZEOFBANK);
    if (a){
        for (i = 0; i < SIZEOFBANK; i++){
            a[i] = malloc(sizeof *a[i] * SIZEOFWORDS);
        }
    }

    wordbank(a);

    /*for (i = 0; i < SIZEOFBANK; i++){
        printf("%s\n",a[i]);
    }*/
    ask(a);
	return 0;
}

void ask(char **a){
    int answer[1];
    printf("%s\n","Answer this:");
    while(*answer != -1){
        scanf("%d",answer);
        if (*answer == 1){
            printf("%s\n","Right.");
        } else {
            printf("%s\n",a[*answer]);
            printf("%s\n","Wrong.");
        }
    }


}

//build array from file
void wordbank(char **a){
    int i;
    char *files[] = {"asdf.txt","1.txt","corinne.txt","filename.txt","thistitle.txt"};
    for (i = 0;i < sizeof(files)/sizeof(files[0]); i++){
        printf("%d %s\n", i, files[i]);
    }
    printf("\n");
    char *ext = ".txt";
    int title;
    printf("%s\n","Choose File");
    scanf("%d", &title);
    printf("%s\n","Up till here works");
    printf("%s\n",files[title]);
    
    FILE *f = fopen(files[title], "rt");

    char stuff[16];
    char line[16];
    int x;
    x = 0;
    while(fgets(line,16,f)){
        sscanf (line, "%[^\n]", stuff);
        strcpy(a[x],stuff);
        x++;
    }
    
    fclose(f);
}
