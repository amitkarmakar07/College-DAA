#include<stdio.h>
#define INF 999
#define n  6
void djikstra(int graph[n][n],int src){
    int dist[n]={INF,INF,INF,INF,INF,INF};
    dist[src]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((graph[i][j]!=INF) && (dist[i]+graph[i][j]) < dist[j]){
                dist[j]=dist[i]+graph[i][j];
            }
        }
        }
        printf("All the vertex distance form 0 is  : \n");
        for(int i=0;i<n;i++){
            printf("%d--%d \n",i,dist[i]);
        }
}
int main(){
     int graph[n][n] = {
    {0, 1, 4, INF, INF, INF},
    {1, 0, 4, 2, 7, INF},
    {4, 4, 0, 3, 5, INF},
    {INF, 2, 3, 0, 4, 6},
    {INF, 7, 5, 4, 0, 7},
    {INF, INF, INF, 6, 7, 0}
};
     djikstra(graph,0);
     return 0;
}
 
