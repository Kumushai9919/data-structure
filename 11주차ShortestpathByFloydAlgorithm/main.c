//
//  main.c
//  11주차ShortestpathByFloydAlgorithm
//
//  Created by Kumushai Nazhimidin kyzy on 2021/11/15.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_VTXS 256

void error(char str[]){
    printf("%s\n", str);
    exit(1);
}

typedef char VtxData;
int adj[MAX_VTXS][MAX_VTXS];
int vsize;
VtxData vdata[MAX_VTXS];

int is_empty_grapth(){ return (vsize==0);}
int is_full_graph(){return (vsize>=MAX_VTXS);}
void init_graph(){
    int i,j;
    vsize = 0;
    for(i=0;i<MAX_VTXS;i++){
        for(j=0;j<MAX_VTXS;j++){
            adj[i][j] = 0;
        }
    }
}
void insert_vertex(VtxData name){
    if(is_full_graph())
        error("Error: 그래프 정점의 개수 초과\n");
    else
        vdata[vsize++] = name;
}
void insert_edge(int u, int v, int val){
    adj[u][v] = val;
}
void insert_edge2(int u, int v, int val){
    adj[u][v] = adj[v][u] = val;
}

void print_graph(char* msg){
    int i, j;
    printf("%s", msg);
    printf("%d\n", vsize);
    for(i=0; i<vsize; i++){
        printf("%c ", vdata[i]);
        for(j=0;j<vsize;j++)
            printf(" %3d", adj[i][j]);
        printf("\n");
    }
}

#define INF 9999

void load_wgraph(char *filename){
    int i,j,val,n;
    char str[80];
    FILE *fp= fopen(filename, "r");
    if(fp!=NULL){
        init_graph();
        fscanf(fp, "%d", &n);
        for(i=0;i<n;i++){
            fscanf(fp, "%s", str);
            insert_vertex(str[0]);
            for(j=0; j<n; j++){
                fscanf(fp, "%d", &val);
                if(i!=j && val==0)
                    adj[i][j] = INF;
                else adj[i][j] = val;
            }
        }
        fclose(fp);
    }
}

void print_wgraph(char* msg){
    int i,j,val;
    printf("%s%d\n",msg,vsize);
    for(i=0;i<vsize;i++){
        printf("%c  ", vdata[i]);
        for(j=0;j<vsize;j++){
            val = adj[i][j];
            if(i==j) printf("  0 ");
            else if (val >= INF) printf("  - ");
            else printf("%3d ", val);
        }
        printf("\n");
    }
}

//Floyd의 최단경로
int A[MAX_VTXS][MAX_VTXS];  //최단경로 거리
void printA(){
    int i,j;
    printf("=================================\n");
    for(i=0;i<vsize;i++){
        for(j=0;j<vsize;j++){
            if (A[i][j] == INF) printf(" INF ");
            else printf("%4d ", A[i][j]);
        }
        printf("\n");
    }
}
void shortest_path_floyd(){
    int i,j,k;
    for(i=0;i<vsize;i++){ //초기화
        for(j=0;j<vsize;j++)
            A[i][j] = adj[i][j];
    }
    
    for (k=0; k<vsize;k++){ //경로설정
        for(i=0;i<vsize;i++)
            for(j=0;j<vsize;j++){
                if(A[i][k] + A[k][j] < A[i][j])
                    A[i][j] = A[i][k] + A[k][j];
            }
        printA();  //진행상황 출력용
    }
}

int main(){
    load_wgraph("/Users/kumushainazhimidinkyzy/Documents/Data Structure/DS자료구조실습2학기/11주차ShortestpathByFloydAlgorithm/11주차ShortestpathByFloydAlgorithm/wgraph_sp.text");
    print_wgraph("Shortest distance (wgraph_sp.txt)\n");
    printf("Shortest path By Floyd Algorithm\n");
    shortest_path_floyd();
}
