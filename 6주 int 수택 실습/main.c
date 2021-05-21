//
//  main.c
//  6주 int 수택 실습
//
//  Created by Kumushai Nazhimidin kyzy on 2021/04/12.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int Element;
Element data[MAX_STACK_SIZE];
int top;

void init_stack() {top = -1;}

int size(){return top+1;}

int is_empty(){return (top == -1);}

int is_full(){return (top == MAX_STACK_SIZE-1);}


void error(char str[]){
    printf("%s\n", str);
    exit(1);
}

void push(Element e){
    if( is_full()){
        error("스택 포화 에러");
    }
    data[++top] = e;
}

void print_stack(){
    int i;

    for(i=0;i<size();i++){
        printf("%2d ", data[i]);
    }
    printf("\n");
}


Element pop(){
    if(is_empty()){
        error("스택 공백 에러");
    }
    return data[top--];
}

Element peek(){
    if(is_empty()){
        error("스택 공백 에러");
    }
    return data[top];
}

int main(){
    int i;
    init_stack();

    for(i=1; i<10; i++){
        push(i);
    }
    printf("학번: 202068060 이름: 쿠무샤이\n");
    printf("스택 push 9휘 = ");
    print_stack();
    printf("\tpop() --> %d\n", pop());
    printf("\tpop() --> %d\n", pop());
    printf("\tpop() --> %d\n", pop());
    printf("스택 pop 3휘 = ");
    print_stack();
    return 0;

}
 
