//
//  main.c
//  13주차Insertion-Sort
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


void insertion_sort(int list[], int n){
    int i, j, key;
    for(i=1; i<n; i++){
        key = list[i];
        for(j=i-1; j>=0 && list[j]>key; j--)
            list[j+1] = list[j];
        list[j+1] = key;
        printStep(list, n, i);
    }
}

int ascend(int x, int y) { return y-x;} //오름차순 비교함수
int descend(int x, int y) { return x-y;} //내립차순 비교함수

void insertion_sort_fn(int list[], int n, int(*f)(int, int)){
    int i, j, key;
    for(i=1; i<n; i++){
        key = list[i];
        for(j=i-1;j>=0 && f(list[j], key)<0; j--)
                {
                    list[j+1] = list[j];
                }
        list[j+1] = key;
        printStep(list, n, i);
    }
}


int main(int argc, const char * argv[]) {
    printf("학번: 202068060 이름: 쿠무샤이\n");
    int list[9] = {5,3,8,4,9,1,6,2,7};
    printArray(list, 9, "Original");
    insertion_sort_fn(list, 9, descend);
    printArray(list, 9, "Descend-insert");
    printf("\n\n");
    
    int list2[9] = {5,3,8,4,9,1,6,2,7};
    printArray(list2, 9, "Original");
    insertion_sort_fn(list2, 9, ascend);
    printArray(list2, 9, "Ascend-insert");
 
    return 0;
}
