//
//  main.c
//  9주차 연결리스트 스택
//
//  Created by Kumushai Nazhimidin kyzy on 2021/05/03.
//

#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct LinkedNode
{
    Element data;
    struct LinkedNode* link;
}Node;

Node* top;

int init_stack()
{
    return top==NULL;
}
int size (){
    Node *p;
    int count=0;
    for(p=top; p!=NULL; p=p->link){
        count++;
    }
    return count;
}
int is_empty()
{
    return top==NULL;
}
void error(char *str)
{
    fprintf(stderr, "%s\n", str);
    exit(1);
}
void push(Element e)
{
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->link=top;
    top=p;
}
Element pop()
{
    Node *p;
    Element e;
    if(is_empty()) error("스택 공백 에러");
    
    p = top;
    top = p->link;
    
    e=p->data;
    free(p);
    return e;
}
Element peek()
{
    if(is_empty()) error("스택 공백 에러");
    return top->data;
}
void destroy_stack()
{
    while(is_empty()==0)
        pop();
    
}
void print_stack(char* msg)
{
    Node *p;
    printf("%s[%2d]= ", msg, size());
    for(p=top; p!=NULL; p=p->link){
        printf("%2d", p->data);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int i;
    init_stack();
    for(i=1; i<10; i++){
        push(i);
    }
    printf("학번: 202068060 이름: 쿠무샤이\n");
    print_stack("연결된스택 push 9회 ");
    printf("\tpop()-->%d\n", pop());
    printf("\tpop()-->%d\n", pop());
    printf("\tpop()-->%d\n", pop());
    print_stack("연결된스택 pop 3회 ");
    destroy_stack();
    print_stack("연결된스택 destroy ");
    return 0;
}
