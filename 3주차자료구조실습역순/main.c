//
//  main.c
//  3주차자료구조실습역순
//
//  Created by Kumushai Nazhimidin kyzy on 2021/09/13.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 25

typedef char Element;
Element data[MAX_STACK_SIZE];
int top;

void init_stack(){top = -1; }
int size() { return top+1; }
int is_empty() { return (top == -1); }
int is_full() { return (top == MAX_STACK_SIZE-1); }

void error(char str[])
{
    printf("%s\n", str);
    exit(1);
}

void push( Element e)
{
    if( is_full())
        error("스택 포화 에러 ");
    data[++top] = e;
}
Element pop()
{
    if( is_empty() ) error("스택 공백 에러");
        return data[top--];
}
Element peek(){
    if(is_empty()){
        error("스택 공백 에러");
    }
    return data[top];
}

void print_stack(){
    int i;

    for(i=0;i<size();i++){
        printf("%2d ", data[i]);
    }
    printf("\n");
}


int main(int argc, const char * argv[]) {
    int i;
    char c[MAX_STACK_SIZE];
    printf("학번: 202068060 이름: 쿠무샤이 \n");
    init_stack();
    printf("문자열을 입력하세요 ");
    scanf("%s",c);
    for(i=0; i < sizeof(c)/sizeof(c[0]); i++){
        push(c[i]);
    }
    printf("역순 문자열 ");
    while(is_empty()==0){
        printf("%c", pop());
    }
    printf("\n");
    return 0;
}
