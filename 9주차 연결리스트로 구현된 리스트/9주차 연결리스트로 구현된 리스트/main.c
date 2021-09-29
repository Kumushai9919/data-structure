//
//  main.c
//  9주차 연결리스트로 구현된 리스트
//
//  Created by Kumushai Nazhimidin kyzy on 2021/05/03.
//

#include <stdio.h>
#include <stdlib.h>
typedef int Element;
typedef struct LinkedNode
{
    Element data;
    struct LinkedNode *link;
}Node;

Node *head;

void init_list()
{
    head=NULL;
}
int is_empty()
{
    return head==NULL;
}
int size()
{
    Node* p;
    int count=0;
    for(p = head; p!=NULL; p=p->link)
        count++;
    return count;
}
Node* get_entry(int pos)
{
    Node *p = head;
    int i;
    for(i=0; i<pos; i++, p = p->link)
    if(p == NULL) return NULL;
    return p;
}

void replace(int pos, Element e)
{
    Node *node = get_entry(pos);
    if(node != NULL)
        node->data = e;
}
Node* find(Element e)
{
    Node *p;
    for(p=head; p != NULL; p=p->link)
    if(p->data == e) return p;
    return NULL;
}
void insert_next(Node *prev, Node *node)
{
    if (node != NULL){
        node->link = prev->link;
        prev->link = node;
    }
}
void insert(int pos, Element e)
{
    Node *new_n, *prev;
    new_n = (Node*)malloc(sizeof(Node));
    new_n->data = e;
    new_n->link = NULL;
    
    if(pos==0) {
        new_n->link = head;
        head = new_n;
    }
    else {
        prev = get_entry(pos-1);
        if(prev != NULL)
            insert_next(prev, new_n);
        else
            free(new_n);
    }
}


Node* remove_next(Node *prev)
{
    Node *removed = prev->link;
    if(removed!=NULL)
        prev->link = removed->link;
    return removed;
}
void delete(int pos)
{
    Node *prev, *removed;
    if(pos == 0 && is_empty() == 0) {
        removed = head;
        head = head->link;
        free(removed);
    }
    else {
        prev = get_entry(pos - 1);
        if(prev!=NULL) {
            removed = remove_next(prev);
            free(removed);
        }
    }
}
void clear_list()
{
    while (is_empty() == 0)
        delete(0);
}

void print_list(char* msg)
{
    Node* p;
    printf("%s[%2d]: ", msg, size());
    for (p = head; p != NULL; p = p->link)
    printf("%2d ", p->data);
    printf("\n");
}

int main(int argc, const char * argv[])
{
    init_list();
    insert(0, 30);
    insert(0, 20);
    insert(1, 30);
    insert(size(), 40);
    insert(2, 50);
    printf("학번: 202068060 이름: 쿠무샤이\n");
    
    print_list("단순연결리스트로 구현한 List(삽입x5)");
    
    replace(2, 90);
    print_list("단순연결리스트로 구현한 List(교체x1)");
    
    delete(2);
    delete(size() - 1);
    delete(0);
    print_list("단순연결리스트로 구현한 List(삽입x3)");
    
    clear_list();
    print_list("단순연결리스트로 구현한 List(정리후)");
    return 0;
}

