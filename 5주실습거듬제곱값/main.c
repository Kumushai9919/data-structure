//
//  main.c
//  5주실습거듬제곱값
//
//  Created by Kumushai Nazhimidin kyzy on 2021/03/29.
//

#include <stdio.h>
#include <time.h>

double power(double x, int n) {
    if (n == 0) return 1;
    else if (n % 2 == 0)
        return power(x*x, n/2);
    else
        return (x*power(x*x, (n-1)/2));
}

double slow_power(double x, int n) {
    int i;
    double r=1.0;
    for(i=0; i<n; i++)
    r=r*x;
       return r;
    }

int main(int argc, const char * argv[]) {
    clock_t t0, t1, t2;
    double dA, dB;
    
    t0=clock();
    slow_power(2.0, 100000);
    t1=clock();
    power(2.0, 100000);
    t2=clock();
    
    dA=(double)(t1-t0)/CLOCKS_PER_SEC;
    dB=(double)(t2-t1)/CLOCKS_PER_SEC;
    
    printf("학번: 202068060 이름: 쿠무샤이\n");
    printf("SLOW...%1f\n", dA);
    printf("FAST...%1f\n", dB);
 
    return 0;
}



















