#include<stdio.h>
#define INF 999
#define v 4
void prims(int graph[][v]){
    int edge=1;
    int visited[v+1];
    for(int i=1;i<v+1;i++) visited[i]=0;
    visited[1]=1;
    int start,dest,sum=0; 
    while(edge<=v-1){
        int mini=INF;
        for(int i=1;i<=v;i++){
            if(visited[i]==1){
                for(int j=1;j<=v;j++){
                     if(visited[j]==0 && graph[i-1][j-1] < mini){
                        mini= graph[i-1][j-1];
                        start=i;
                        dest=j;
                     }
                }
            }
        }
        printf("From %d --> %d cost=%d\n",start,dest ,mini);
        sum+=mini;
        edge++;
        visited[dest]=1;
    }
    printf("\ncost : %d ",sum);
}
int main(){
    int graph[][v]={
    {0, 10, 6, 5},
    {10, 0, 15, 3},
    {6, 15, 0, 4},
    {5, 3, 4, 0}
};
prims(graph);
return 0;
}
