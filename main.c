//
//  main.c
//  13주차Selection-Sort
//
//  Created by Kumushai Nazhimidin kyzy on 2021/11/22.
//

#include <stdio.h>
#include <string.h>
#include <stdio.h>
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

void printArray(int arr[], int n, char *str){
    int i;
    printf("%s = ", str);
    for(i=0; i<n; i++){
        printf("%3d", arr[i]);
    }
    printf("\n");
}
void printStep(int arr[], int n, int val){
    int i;
    printf("   Step %2d = ", val);
    for(i=0; i<n; i++)
        printf("%3d", arr[i]);
    printf("\n");
}
//선택정렬
void selection_sort(int list[], int n){
    int i, j, least, tmp;
    for(i=0; i<n-1; i++){
        least = i;
        for(j=i+1; j<n; j++)
            if(list[j]<list[least])
                least = j;
        SWAP(list[i], list[least], tmp);
        printStep(list, n, i+1);
    }
}
//버블정렬
void bubble_sort(int list[], int n){
    int i, j, bChanged, tmp;
    for(i=n-1; i>0; i--){
        bChanged = 0;
        for(j=0; j<i; j++)
        if(list[j]>list[j+1]){
            SWAP(list[j], list[j+1], tmp);
            bChanged = 1;
    }
        if(!bChanged)break;
        printStep(list, n, n-1);
    }
}

int main(int argc, const char * argv[]) {
    printf("학번: 202068060 이름: 쿠무샤이\n");
    int list[9] = {5,3,8,4,9,1,6,2,7};
    printArray(list, 9, "Original");
    selection_sort(list, 9);
    printArray(list, 9, "Selection");
    printf("\n\n");
    
    int list2[9] = {5,3,8,4,9,1,6,2,7};
    printArray(list2, 9, "Original");
    bubble_sort(list2, 9);
    printArray(list2, 9, "Bubble-Sort");
    return 0;
}










