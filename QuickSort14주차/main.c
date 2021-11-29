//
//  main.c
//  QuickSort
//
//  Created by Kumushai Nazhimidin kyzy on 2021/11/29.
//

#include <stdio.h>
typedef int element;
int size, i = 0;

int partition(element a[], int begin, int end)
{
    int pivot, L, R, t;
    element temp;
    L = begin;
    R = end;
    
    pivot = (int)((begin + end)/2.0); // 중간에 위치한 원소를 피봇 원소로 선택
    
    printf("\n [ %d단계  :  pivot=%d ] \n", ++i, a[pivot]);
    while(L<R){
        while((a[L]<a[pivot]) && (L<R)) L++;
        while((a[R] >= a[pivot]) && (L<R)) R--;
        if(L<R)  {                   //선택된 두 레코드 교환
            temp = a[L];
            a[L] = a[R];
            a[R] = temp;
        
            if(L == pivot)   //L이 피봇인 경우
                pivot = R;   //변경된 피봇의 위치 R를 저장
       }
 }
    temp = a[pivot];  // L=R이면 R원소와 피봇 원소 교환
    a[pivot] = a[R];
    a[R] = temp;
    for( t=0; t<size; t++) printf(" %d", a[t]);
    printf("\n");
    return R;
}
void quick_sort(element a[], int begin, int end)
{
    int q;
    if(begin<end){
        q = partition(a, begin, end);
        quick_sort(a, begin, q-1);
        quick_sort(a, q+1, end);
    }
}
 
int main(int argc, const char * argv[]) {
    printf("학번: 202068060 이름: 쿠무샤이\n");
    int i;
    element a[8] = { 69, 10, 30, 2, 16, 8, 31, 22};
    size = 8;
    printf("\n [ 초기 상태 ]\n");
    for(i=0; i <= size-1; i++)
        printf(" %d", a[i]);
    printf("\n");
    quick_sort(a, 0, size-1);
}
