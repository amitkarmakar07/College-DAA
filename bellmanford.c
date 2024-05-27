#include<stdio.h>
#include<limits.h>

void print(int dist[], int v){
    for(int i = 0; i < v; i++)
        printf("%d ", dist[i]);
}

void bellmanford(int graph[][3], int src, int vertex){

    int dist[vertex];
    for(int i = 0; i < vertex; i++){
        dist[i] = INT_MAX;
    }
    dist[src] = 0;  

    int e = 8;
    for(int i = 0; i < vertex - 1; i++){
        for(int j = 0; j < e; j++){
            int u = graph[j][0];
            int v = graph[j][1];
            int wt = graph[j][2];

            if(dist[u] != INT_MAX && (dist[u] + wt) < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }
    print(dist, vertex); 
}

int main(){
   int graph[8][3] = {
    {0, 1, -1},
    {0, 2, 4},
    {1, 2, 3},
    {1, 3, 2},
    {1, 4, 2},
    {3, 2, 5},
    {3, 1, 1},
    {4, 3, -3}
};
    int v = 5;
    int src = 0;

    
    bellmanford(graph, src, v);
    return 0;
}
