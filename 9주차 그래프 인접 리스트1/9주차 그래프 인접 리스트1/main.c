//
//  main.c
//  9주차 그래프 인접 리스트1
//
//  Created by Kumushai Nazhimidin kyzy on 2021/10/26.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_VTXS 100
typedef struct GraphNode{
    int id;
    struct GraphNode* link;
}GNode;

typedef char VtxData;
int vsize;
VtxData vdata[MAX_VTXS];

GNode* adj[MAX_VTXS];

void init_graph() {
    int i;
    vsize=0;
    for(i=0 ; i<MAX_VTXS; i++){
        adj[i]= NULL;
    }
}
int is_empty_graph(){return(vsize==0);}
int is_full_graph(){return(vsize>=MAX_VTXS);}

void reset_graph(){
    int i;
    GNode* n;
    for(i=0; i<vsize; i++){
        while(adj[i]!=NULL){
            n=adj[i];
            adj[i] = n->link;
            free(n);
        }
    }
    vsize=0;
}
void error(char str[]){
    printf("%s\n", str);
    exit(1);
}
void insert_vertex( char val) {
    vdata[vsize++]=val;
}
void insert_edge(int u, int v) {
    GNode* n=(GNode*)malloc(sizeof(GNode));
    n->link=adj[u];
    n->id=v;
    adj[u]=n;
}

void print_graph(char* msg)
{
    int i;
    GNode* v;
    printf("%s", msg);
    printf("%d\n", vsize);
    for(i=0;i<vsize; i++){
        printf("%c \t", vdata[i]);
        for(v=adj[i]; v!=NULL; v=v->link){
            printf("%c \t", vdata[v->id]);
            }
        printf("\n");
    }
}
int main() {
    int i;
    init_graph();
    for(i=0; i<4; i++)
        insert_vertex('A'+i);
    
    insert_edge(0,1);
    insert_edge(0,3);
    insert_edge(1,0);
    insert_edge(1,2);
    insert_edge(1,3);
    insert_edge(2,1);
    insert_edge(2,3);
    insert_edge(3,0);
    insert_edge(3,1);
    insert_edge(3,2);
    
    
    printf("학번: 202068060 이름: 쿠무샤이");
    print_graph("그래프(인접리스트)\n");
    return 0;
    }
