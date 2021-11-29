//
//  main.c
//  MergeSort14주차
//
//  Created by Kumushai Nazhimidin kyzy on 2021/11/29.
//

#include <stdio.h>
#define MAX_SIZE 8

static void merge(int list[], int left, int mid, int right)
{
    int i, j, t, k = left, l;
    static int sorted[MAX_SIZE];
    
    for(i=left, j=mid+1; i<=mid && j<=right ; )
    sorted[k++] = (list[i]<=list[j] ? list[i++] : list[j++]); //작은 숫자를 찾아 임시 배열애 넣는다. 어느 쪽 덩어리든 Index의 끝에 닿으면 빠져나온다.
    if(i > mid){
        for( l=j; l<=right ; l++, k++)
        sorted[k] = list[l];
    }else {
        for(l=i ; l<=mid ; l++, k++)
        sorted[k] = list[l];
    }
    for(l=left; l<=right; l++)
        list[l] = sorted[l];
    
    printf("Merging: %d ~ %d & %d ~ %d\n", left, mid, mid+1, right);
    for(t=0; t<MAX_SIZE;t++){
        printf("  %d", list[t]);
    }
    printf("\n\n");
}

void merge_sort(int list[], int left, int right){
    if(left<right){
        int mid = (left+right)/2;
        merge_sort(list, left, mid);
        merge_sort(list, mid+1, right);
        merge(list, left, mid, right);
    }
}
int main(int argc, const char * argv[]) {
    printf("학번: 202068060 이름: 쿠무샤이\n");int i;
    int list[] = {27, 10, 12, 20, 25, 13, 15, 22};
    printf("초기 상태  : ");
    for(i = 0; i <= 7; i++)
        printf(" %d", list[i]);
    printf("\n\n");
    
    merge_sort(list, 0, 7);
}
