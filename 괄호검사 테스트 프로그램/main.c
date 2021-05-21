//
//  main.c
//  괄호검사 테스트 프로그램
//
//  Created by Kumushai Nazhimidin kyzy on 2021/04/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef int  Element;
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
    
int check_matching(char expr[]){
    int i=0, prev;
    char ch, open_ch;
    init_stack();
    while(expr[i] != '\0') {
        ch=expr[i++];
        switch(ch) {
            case'(': case'[':  case'{':
                push(ch);
                break;
            case')': case ']': case '}':
                if( is_empty() ) return 0;
                else
                {
                    open_ch=pop();
                    if((open_ch == '(' && ch != ')') || (open_ch == '{' && ch!='}') || (open_ch =='[' && ch != ']') )
                        return 0;
                }
                
            }
    }
    if(is_empty()==0) return 1;
    return 0;
}

int main(int argc, const char * argv[]) {
    char expr[4][80] = { "{A[(i+1)]=0;}", "if((i==0) && (j==0)",
                             "A[(i+1])=0;", "A[i] =f)(;" };
       int err, i;
    printf("학번: 202068060 이름: 쿠무샤이 \n");
    for( i=0; i<4; i++) {
           err = check_matching(expr[i]);
        if( err == 0 ) {
               printf(" 괄호정상: %s\n", expr[i]);
        }
           else
               printf(" 괄호오류: %s (조건%d 위반)\n", expr[i], err);
          }
    return 0;
}
