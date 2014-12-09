#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


//Constant Defintions
static const SIZEOFBANK=64;
static const SIZEOFWORDS=64;
static const int key[4] = {2,3,1,4};

//Prototypes
void wordbank(char **a,char **b);
void answerbank(char **b,int num);
void ask();
bool isinarray(long val, long *arr, long size);
char toLowerCase(char *buf);

//Main function


char toLowerCase(char *buf){
    int i;
    for(i = 0; buf[i]; i++){
        buf[i] = tolower(buf[i]);
    }
}

void ask(char **a,char **b){
    int x;
    bool trigger = false;
    char buf[SIZEOFWORDS];
    char ans[SIZEOFWORDS];
    long inarr[32] = {1,2,3,4,5,6,7,8,9};
    char *p;
    long int i;



    while ((x = getchar()) != '\n' && x != EOF); //clear stdin buffer

    x = 0; //Recycle x to iterate through the array in file

    while(!trigger){
        if (strcmp(a[x],"") == 0){
            trigger = true;
            break;
        }
        printf("\n%s",a[x]);
        //printf("\n%s",b[x]);
        printf("\n%s","Your Answer: ");
        fgets(buf, sizeof(buf), stdin);
        toLowerCase(buf);
        if ( buf != NULL){
            buf[strlen(buf)-1] = '\0';
            if (strcmp(b[x],buf) == 0){
                printf("\n%s\n","Correct!");
                x++;
                continue;
            }else{
                //printf ("ANS: %s\n", ans);
                //printf ("BUF: %s\n", buf);
                if(strcmp(buf,"quit") == 0){
                    printf ("Program Closing...\n");
                    trigger = true;
                    break;
                }
                printf("\n%s","Incorrect, please try again.");

            }
        }  
    }

}

bool isinarray(long val, long *arr, long size){
    int i;
    for (i=0; i < size; i++) {
        if (arr[i] == val)
            return true;
    }
    return false;
}

//build array from file
void wordbank(char **a,char **b){
    int i;
    long filearr[32] = {0};
    char *files[] = {"test.txt"};
    for (i = 0;i < sizeof(files)/sizeof(files[0]); i++){
        printf("%d %s\n", i, files[i]);
    }

    printf("\n");
    int title;
    bool trigger = false;
    while(!trigger){
        printf("%s\n","Choose File");
        scanf("%d", &title);
        if (isinarray(title,filearr,sizeof(filearr))){
            printf("Question bank: %s\n",files[title]);

            FILE *f = fopen(files[title], "rt");

            char stuff[SIZEOFBANK];
            char line[SIZEOFWORDS];
            int x;
            x = 0;
            while(fgets(line,SIZEOFBANK,f)){
                sscanf (line, "%[^\n]", stuff);
                strcpy(a[x],stuff);
                x++;
            }

            fclose(f);
            answerbank(b,title);
            trigger = true;
        } else {
            printf("Not a valid file. Please select a valid file.\n");
            trigger=false;
        }
    }

}
void answerbank(char **b,int num){
    int i;
    char file[16];
    sprintf(file,"answers%d.txt",num);
    FILE *f = fopen(file, "rt");
    char stuff[SIZEOFBANK];
    char line[SIZEOFWORDS];
    int x;

    x = 0;
    while(fgets(line,SIZEOFBANK,f)){
        sscanf (line, "%[^\n]", stuff);
        strcpy(b[x],stuff);
        x++;
    }

    fclose(f);

}
