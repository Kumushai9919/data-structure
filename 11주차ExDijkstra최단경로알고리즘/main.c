//
//  main.c
//  11주차ExDijkstra최단경로알고리즘
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
        printf(" %c", vdata[i]);
        for(j=0;j<vsize;j++){
            printf(" %3d", adj[i][j]);
        }
    }
    printf("\n");
}

//가중치 그래프 파일 입력/화면 출력
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
                if(i != j && val == 0){
                    adj[i][j] = INF;
                }
                else adj[i][j]=val;
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
//Dijkstra의 최단 경로
int path[MAX_VTXS];  //경로
int dist[MAX_VTXS];  //시작정점으로부터 최단경로 거리
int found[MAX_VTXS];  //방문한 정점

void print_step(int step){  //진행 단계별 상황출력
    int i;
    printf(" Step%2d:", step);
    for(i=0; i<vsize; i++)
        if(dist[i] == INF){
            printf("  INF");
        }else{
            printf("%5d", dist[i]);
        }
        printf("\n");
    
}

void print_shortest_path(int start, int end){ //최종 경로 출력
    printf("[최단경로: %c---%c] %c", vdata[end], vdata[start], vdata[end]);
    while (path[end] != start){
        printf("-%c", vdata[path[end]]);
        end = path[end];
    }
    printf("-%c\n", vdata[path[end]]);
}

//최단 경로를 갖는 다음 정점을 찾는 연산
int choose_vertex(){
    int i, min = INF, minpos = -1;
    
    for(i=0;i<vsize;i++){
        if(dist[i]<min && !found[i]){
            min = dist[i];
            minpos = i;
        }
    }
    return minpos;
}

//Dijkstra의 최단경로
void shortest_path_dijkstra(int start){
    int i,u,w;
    for(i=0; i<vsize; i++){ //초기화
        dist[i] = adj[start][i];
        path[i] = start;
        found[i] = 0;
    }
    found[start] = 1;  //시작 정점을 추가
    dist[start] = 0;  //시작 정점의 최단경로를 0으로 설정
    
    for (i=0;i<vsize;i++){
        print_step(i+1);  //진행상황 출력용
        u = choose_vertex();  //최단 경로를 위한 다음 정점 착기 
        found[u] = 1;
        
        for(w=0;w<vsize;w++){
            if(found[w] == 0){
                if(dist[u] + adj[u][w]<dist[w]){
                    dist[w] = dist[u] + adj[u][w];
                    path[w] = u;
                }
            }
        }
    }
}

int main(){
    int i;
    load_wgraph("/Users/kumushainazhimidinkyzy/Documents/Data Structure/DS자료구조실습2학기/11주차ExDijkstra최단경로알고리즘/11주차ExDijkstra최단경로알고리즘/wgraph_sp.text");
    printf("Shortest path By Dijkstra Algorithm\n");
    shortest_path_dijkstra(0);
    for (i=1; i<vsize; i++){
        print_shortest_path(0,i);
    }
}
