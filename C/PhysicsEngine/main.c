#include "phys.h"

int main()
{
    double radius = 0.00;
    double mass = 0.00;
    double height = 0.00;
    char *buff;

    printf("%s","What is the radius of the ball?\n");
    buff = malloc(16);
    fgets(buff,sizeof(buff),stdin);
    radius = strtod(buff,NULL);

    printf("%s","What is the mass of the ball?\n");
    fgets(buff,sizeof(buff),stdin);
    mass = strtod(buff,NULL);

    struct ball newb = {mass,radius};

    printf("%s","At what height is the ball dropped?\n");
    fgets(buff,sizeof(buff),stdin);
    height = strtod(buff,NULL);

    struct parameters instance = {height};

    double result = calculate(newb,instance);
    printf("It took the ball with radius %f, and mass %f, %f seconds to fall %f meters.\n",newb.radius,newb.mass,result,instance.height);
    
    return 0;
}
double calculate(struct ball object,struct parameters instance)
{ 
    /* The distance that an object travels under constant acceleration is given by the formula:
        distance = 1/2 × acceleration × time2 + intial speed × time

    The initial speed is zero because the balls are dropped and not thrown. Therefore, we can solve for time:
        time2 = (2 × distance) / acceleration

    Substituting distance = 54 meters and acceleration = 9.8 meters/second2, we get
        time2 = (2 × 54 meters) / (9.8 meters/second2) = 11.0 seconds2

    The square root gives:
        time = 3.3 seconds*/
    double result = (2 * instance.height) / GRAV;

    return sqrt(result);
}

