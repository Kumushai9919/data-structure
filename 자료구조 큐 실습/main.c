//
//  main.c
//  7주차1
//
//  Created by Kumushai Nazhimidin kyzy on 2021/04/26.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 4

typedef char Element;
typedef struct {
    Element queue[MAX_QUEUE_SIZE];
    int front, rear;
    
} Queuetype;

Queuetype *createQueue(){
    Queuetype *Q;
    Q=(Queuetype*)malloc(sizeof(Queuetype));
    Q->front=-1;
    Q->rear=-1;
    return Q;
}

int isEmpty(Queuetype *Q){
    if(Q->front==Q->rear){
        printf("The Queue is empty!");
        return 1;
    }
    else return 0;
}

int isFull(Queuetype *Q){
    if(Q->rear==MAX_QUEUE_SIZE-1){
        printf("The Queue is full! ");
        return 1;
    }
    else{
        return 0;
    }
}

void enQueue(Queuetype *Q, Element item){
    if(isFull(Q)) return;
    else {
        Q->rear++;
        Q->queue[Q->rear]=item;
    }
}

int deQueue(Queuetype *Q){
    if(isEmpty(Q)) return 0;
    else {
        Q->front++;
        return Q->queue[Q->front];
    }
}

int peek(Queuetype *Q){
    if(isEmpty(Q)) exit(1);
    else return Q->queue[Q->front+1];
}

void printQueue(Queuetype *Q){
    int i;
    printf("Queue : [ ");
    for(i=Q->front+1; i<=Q->rear; i++){
        printf("%3c", Q->queue[i]);
    }
    printf(" ]");
}


int main(int argc, const char * argv[]) {
    Queuetype *Q1= createQueue();
    Element data;
    printf(" 학번: 202068060 이름 쿠무샤이");
    printf("\n ***** 순차 큐 연산 ***** \n");
    printf("\n 삽입 A >>"); enQueue(Q1,'A'); printQueue(Q1);
    printf("\n 삽입 B >>"); enQueue(Q1,'B'); printQueue(Q1);
    printf("\n 삽입 C >>"); enQueue(Q1,'C'); printQueue(Q1);
    data=peek(Q1);
    printf(" peek item: %c\n", data);
    printf("\n 삭제 >>"); data=deQueue(Q1); printQueue(Q1);
    printf("\t 삭제된 데이터: %c", data);
    printf("\n 삭제 >>"); data=deQueue(Q1); printQueue(Q1);
    printf("\t 삭제된 데이터: %c", data);
    printf("\n 삭제 >>"); data=deQueue(Q1); printQueue(Q1);
    printf("\t\t 삭제된 데이터: %c", data);
    
    
    printf("\n 삽입 D >>"); enQueue(Q1, 'D'); printQueue(Q1);
    printf("\n 삽입 E >>"); enQueue(Q1, 'E'); printQueue(Q1);
    
    return 0;
}
