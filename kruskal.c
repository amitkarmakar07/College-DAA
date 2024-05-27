#include<stdio.h>
#define n 5
#define INF 99
int find(int arr[],int i){
    if(arr[i]==i) return i;
    return find(arr,arr[i]);
}
void uni0n(int arr[],int i,int j){
    if(find(arr,i)==find(arr,j)) return;
    arr[j]=i;
}
void kruskal(int graph[][n]){
    int parent[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
   int start,end,sum=0,edge=0;
   while(edge<n-1){
    int mini=INF;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
              if(find(parent,i)!=find(parent , j) && graph[i][j]< mini){
                mini=graph[i][j];
                start=i;
                end=j;
              }
        } 
    }
    edge++;
    printf("%d --> %d cost %d\n" ,start,end,mini);
    uni0n(parent,start,end);
    sum+=mini;
   }
 printf("%d ",sum);
}
int main(){
    int graph[n][n] = {
        {0,1,7,10,5},
        {1,0,3,99,99},
        {7,3,0,4,99},
        {10,99,4,0,2},
        {5,99,99,2,0}
    };         
    kruskal(graph);
    return 0;
}
