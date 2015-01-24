#include "phys.h"

int main()
{
    double radius = 0.00;
    double mass = 0.00;
    double height = 0.00;
    double velocity = 0.00;
    char *buff;

    /*printf("%s","What is the radius of the ball?\n");
    fgets(buff,sizeof(buff),stdin);
    radius = strtod(buff,NULL);

    printf("%s","What is the mass of the ball?\n");
    fgets(buff,sizeof(buff),stdin);
    mass = strtod(buff,NULL);

    struct ball newb = {mass,radius};*/

    buff = malloc(128);

    printf("%s","At what height is the ball dropped?\n");
    fgets(buff,sizeof(buff),stdin);
    height = strtod(buff,NULL);

    /*double result = noAccel(newb,instance);
    printf("It took the ball %f seconds to fall %f meters.\n",result,instance.height);*/

    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    //fflush(stdin);

    printf("%s","At what velocity is the ball thrown down?\n");
    fgets(buff,sizeof(buff),stdin);
    velocity = strtod(buff,NULL);

    struct parameters instance = {height,velocity};

    double pos = quad(instance,true);
    double neg = quad(instance,false);

    double result = (neg > pos) ? neg:pos;
    printf("It took the ball %f seconds to fall %f meters.\n",result,instance.height);
    
    return 0;
}
double quad(struct parameters instance,bool plus)
{
    double sqRoot = sqrt(pow(instance.velocity,2)+(2*GRAV*instance.height));
    double result;
    if(plus){
        result = (-instance.velocity) + sqRoot;
    }else{
        result = (-instance.velocity) - sqRoot;
    }
    return result/GRAV;
}
double noAccel(struct parameters instance)
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

