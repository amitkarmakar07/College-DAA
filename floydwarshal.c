#include<stdio.h>
#define INF 999

void floydMarshal(int n, int graph[][n]){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(graph[i][j] > graph[i][k] + graph[k][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}
int main(){
    int v=3;
    int graph[3][3]={
        {0,4,6},
        {6,0,2},
        {3,INF,0}}; 

    floydMarshal (v,graph);

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }

return 0;
}
