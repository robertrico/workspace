#include "studyguide.h"

//Main function
int main(int argc, char *argv[]){

    int i;
    struct Arr *a = Arr_Create(10,20);
    struct Arr *b = Arr_Create(10,20);

    wordbank(a,b);

    /*for (i = 0; i < SIZEOFBANK; i++){
      printf("%s\n",a[i]);
      }*/
    ask(a,b);
    return 0;
}



void ask(struct Arr *a,struct Arr *b){
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
        if (strcmp(a->array[x],"") == 0){
            trigger = true;
            break;
        }
        printf("\n%s",a->array[x]);
        //printf("\n%s",b[x]);
        printf("\n%s","Your Answer: ");
        fgets(buf, sizeof(buf), stdin);
        toLowerCase(buf);
        if ( buf != NULL){
            buf[strlen(buf)-1] = '\0';
            if (strcmp(b->array[x],buf) == 0){
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

//build array from file
void wordbank(struct Arr *a,struct Arr *b){
    int i;
    long filearr[32] = {0};
    char *files[] = {"assembly.txt"};
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

            while(fgets(line,64,f)){
                sscanf (line, "%[^\n]", stuff);
                addTo(a,strdup(stuff));
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
void answerbank(struct Arr *b,int num){
    int i;
    char file[16];
    sprintf(file,"answers%d.txt",num);
    FILE *f = fopen(file, "rt");
    char stuff[SIZEOFBANK];
    char line[SIZEOFWORDS];

    while(fgets(line,SIZEOFBANK,f)){
        sscanf (line, "%[^\n]", stuff);
        addTo(b,strdup(stuff));
    }

    fclose(f);

}
