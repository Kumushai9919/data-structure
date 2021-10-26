//
//  main.c
//  9주차 그래프 인접행렬1
//
//  Created by Kumushai Nazhimidin kyzy on 2021/10/26.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_VTXS 10
//인접행렬,Матрица смежности(Способы представления графа)

typedef char VtxData;        // 그래프 정점에 저장할 데이터의 자료형
int adj[MAX_VTXS][MAX_VTXS]; // 각 정점의 인접 행렬
int vsize;                   // 정점의 개수
VtxData vdata[MAX_VTXS];    // 정점에 저장할 데이터 배열

void init_graph(){
    int i, j;
    vsize=0;
    for(i=0; i<MAX_VTXS; i++) for(j=0; j<MAX_VTXS; j++)
    adj[i][j] = 0;
}
int is_empty_graph(){
    return(vsize==0);
}
int is_full_graph(){
    return(vsize>=MAX_VTXS);
}
void error(char str[]){
    printf("%c\n", str);
    exit(1);
}
void insert_vertex(char name){
    if(is_full_graph())
        error("Error: 정점 개수 초과\n");
    else
        vdata[vsize++]=name;
}
void insert_edge(int u, int v, int val){
    adj[u][v]=val;
}
void insert_edge2(int u, int v, int val){
    adj[u][v]=adj[u][v]=val;
}
void printf_graph(FILE *fp, char* msg){
    int i, j;
    fprintf(fp, "%s", msg);
    fprintf(fp, "%d\n", vsize);
    for(i=0; i<vsize; i++){
        fprintf(fp, "%c", vdata[i]);
        for(j=0; j<vsize; j++){
            fprintf(fp, "%3d", adj[i][j]);
        }
        fprintf(fp, "\n");
    }
}
void store_graph(char *filename){
    FILE *fp = fopen(filename, "w");
    if(fp!=NULL){
        printf_graph(fp, "");
        fclose(fp);
    }
}
void load_graph(char *filename){
    int i, j, val, n;
    char str[80];
    FILE *fp = fopen(filename, "r");
    if(fp!=NULL){
        init_graph();
        fscanf(fp, "%d", &n);
        for(i=0; i<n; i++){
            fscanf(fp, "%s", str);
            insert_vertex(str[0]);
            for(j=0; j<n; j++){
                fscanf(fp, "%d", &val);
                if(val!=0)
                    insert_edge(i, j, val);
            }
        }
        fclose(fp);
    }
}

int main(int argc, const char * argv[]) {
    int i;
    init_graph();
    for(int i=0; i<4; i++)
        insert_vertex('A' + i);
    insert_edge2(0, 1, 1);
    insert_edge2(0, 3, 1);
    insert_edge2(1, 2, 1);
    insert_edge2(1, 3, 1);
    insert_edge2(2, 3, 1);
    
    store_graph("graph.txt");
    printf("학번: 202068060 이름: 쿠무샤이\n");
    printf_graph(stdout, "그래프 (인접행렬)\n");
     
    return 0;
}
