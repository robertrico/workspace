#ifndef _studyguide_h
#define _studyguide_h
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <robarr.h>
#include <robstring.h>

//Prototypes
void wordbank(struct Arr *a,struct Arr *b);
void answerbank(struct Arr *b,int num);
void ask(struct Arr *a, struct Arr *b);
//Constant Definitions
static const SIZEOFBANK=64;
static const SIZEOFWORDS=64;
static const int key[4] = {2,3,1,4};

#endif
