//
//  main.c
//  5주실습hanoitower
//
//  Created by Kumushai Nazhimidin kyzy on 2021/03/29.
//

#include <stdio.h>
void hanoiTower(int n, char from, char tmp, char to) {
    if (n == 1)
        printf("원판 %d를 %c애서 %c으로 옮긴다.\n", n, from, to);
    else {
        hanoiTower(n-1, from, to, tmp);
        printf("원판 %d를 %c애서 %c으로 옮긴다.\n", n, from, to);
        hanoiTower(n-1, tmp, from, to);
    }
    
}
int main(int argc, const char * argv[]) {
    printf("학번: 202068060 이름: 쿠무샤이\n");
    hanoiTower(4, 'A', 'B', 'C');
    getchar();
   
    return 0;
}



