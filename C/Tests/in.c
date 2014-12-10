#include<stdio.h>
#include<roblib.h>
int main(int argc, char *argv[]){
    char **a = array(*a,2,10);
    add(a,"Does this pass?",0);
    add(a,"Does this work",1);
    add(a,"Doth thy work",2);
    add(a,"Doth thy work",3);
    add(a,"Doth thy work",4);
    add(a,"Doth thy work",5);
    add(a,"Doth thy work",6);
    printf("%s\n",a[0]);
    printf("%s\n",a[1]);
    printf("%s\n",a[2]);
    printf("%s\n",a[3]);
    printf("%s\n",a[4]);
    printf("%s\n",a[5]);
    printf("%s\n",a[6]);
    int i;
    return 0;
}
