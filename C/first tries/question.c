#include<stdio.h>
#include <string.h>


ask()
{

    char stuff[16];
    char title[16];
    char line[16];
    FILE *f = fopen("asdf.txt", "rt");
    char butt[8][16];
    while(fgets(line,16,f)){
        sscanf (line, "%[^\n]", stuff);
        printf("%s\n", stuff);
    }
    
    fclose(f);
	return 0;
}
