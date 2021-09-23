//
//  main.c
//  4주1부터n까지의합
//
//  Created by Kumushai Nazhimidin kyzy on 2021/03/23.
//
#include<stdio.h>
#include<time.h>


int sumAlgorithmA(int num)
{
    return num*(num + 1) / 2; // O(1)
}

int sumAlgorithmB(int num)
{
    int sum = 0; // O(n)
    for (int i = 1; i <= num; i++) {
        sum = sum + i;
    }
    return sum;
}

int sumAlgorithmC(int num)
{
    int sum = 0;
    int    i, j;
    for (i = 0; i <= num; i++) {  // O(n^2)
        for (j = 1; j <= i; j++) {
            sum = sum + 1;
        }
    }
    return sum;
}


void AlgorithmA(int n, int times) {
    int i;
    for (i = 0; i < times; i++)
        sumAlgorithmA(n);
}
void AlgorithmB(int n, int times) {
    int i;
    for (i = 0; i < times; i++)
        sumAlgorithmB(n);
}
void AlgorithmC(int n, int times) {
    int i;
    for (i = 0; i < times; i++)
        sumAlgorithmC(n);
}

void main()
{ 
    clock_t time0, time1, time2, time3;
    double dataA, dataB, dataC;
    int i;

    printf("(1) 알고리즘 정확도 테스트\n");
    printf("AlgorithmA (7) = %d\n", sumAlgorithmA(7));
    printf("AlgorithmB (7) = %d\n", sumAlgorithmB(7));
    printf("AlgorithmC (7) = %d\n", sumAlgorithmC(7));

    printf("AlgorithmA (9) = %d\n", sumAlgorithmA(9));
    printf("AlgorithmB (9) = %d\n", sumAlgorithmB(9));
    printf("AlgorithmC (9) = %d\n", sumAlgorithmC(9));

    printf("\n(2) 알고리즘 실행 시간 비교: A - B - C\n");
    for (i = 1000; ; i += 100) {
        time0 = clock(); // catch current time
        AlgorithmA(i, 100);
        time1 = clock(); //point
        AlgorithmB(i, 100);
        time2 = clock();
        AlgorithmC(i, 100);
        time3 = clock();
        dataA = (double)(time1 - time0) / CLOCKS_PER_SEC;
        dataB = (double)(time2 - time1) / CLOCKS_PER_SEC;
        dataC = (double)(time3 - time2) / CLOCKS_PER_SEC;

        printf("%5d: \t", i);
        printf("AlgorithmA : %lf\t", dataA);
        printf("AlgorithmB : %lf\t", dataB);
        printf("AlgorithmC : %lf\n", dataC);

        if (dataC > 1.0) break;
    }

    printf("\n(3) 알고리즘 실행 시간 비교: A - B\n");
    for (i = 10000; ; i += 100000) {
        time0 = clock();
        AlgorithmA(i, 100);
        time1 = clock();
        AlgorithmB(i, 100);
        time2 = clock();
        dataA = (double)(time1 - time0) / CLOCKS_PER_SEC;
        dataB = (double)(time2 - time1) / CLOCKS_PER_SEC;
        printf("%5dk: \t", i / 1000);
        printf("AlgorithmA : %lf\t", dataA);
        printf("AlgorithmB : %lf\n", dataB);
        if (dataB > 1.0) break;
    }
}
