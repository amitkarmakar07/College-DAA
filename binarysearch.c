#include<stdio.h>
int binary(int arr[],int s,int e,int key){
      if(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==key) return mid;
         else if(arr[mid]>key) 
         return binary(arr,s,mid-1,key);
        else return binary(arr,mid+1,e,key);
      }
      return -1;
}
int main(){
    int arr[6]={3,5,6,7,8,10};
    int key=8;
    int f=binary(arr,0,5,key);
    printf("%d ",f);
    return 0;
}
