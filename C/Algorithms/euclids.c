#include<stdio.h>
#include<math.h>

int main()
{
    int h = gcd(256,28);
    printf("%d",h);
}
int gcd(int p, int q)
{
    if(q == 0) return p;
    int r = p % q;
    return gcd(q,r);
}
