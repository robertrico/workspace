#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <stdbool.h>

/* Constants*/
#define GRAV 9.8
#define BALL_LIM 5 


/*Struct Definitions*/

struct ball{
    double mass;
    double radius;
};
struct parameters{
    double height;
    double velocity;
};

/* Prototypes */
double noAccel(struct parameters instance);
double quad(struct parameters instance,bool plus);
