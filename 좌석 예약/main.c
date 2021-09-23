//
//  main.c
//  자료수조실습6
//
//  Created by Kumushai Nazhimidin kyzy on 2021/03/15.
//
#define SIZE 10
#include <stdio.h>

int main (){
    
    printf("202068060학번 쿠무샤이\n");

    int seatChoice;
    char choice;
    int s[SIZE] = {0};
    int i;
    printf("******좌석 예약 시스템******\n");
    printf("\n좌석을 예약하시겠습니까?<y 또는 n>/n> ");

    scanf("%c", &choice);
    while (choice == 'y'){
        printf("———————————\n");

        for (i = 1; i <= 10; i++)

        printf(" %d", i);

        printf("\n———————————\n");

        for (i = 0; i < 10; i++)

        printf(" %d", s[i]);
        printf("\n몇번째 좌석을 예약하시겠습니까? ");
        scanf("%d", &seatChoice);
        if ( s[seatChoice - 1] == 0) {
            printf("예약되었습니다.\n");
            s[seatChoice - 1] = 1;
        } else
            printf("이미 예약된 자리입니다\n");

        printf("\n좌석을 예약하시겠습니까?(y/n) ");
        fflush(stdin);
        scanf("%c", &choice);
    }
}
