#include<stdio.h>
#include<limits.h>
int matrixChain(int arr[],int n){
    int dp[n][n];
    for(int i=0;i<n;i++){
        dp[i][i]=0;
    }
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<n;j++){
            int mini=INT_MAX;
            for(int k=i;k<j;k++){
                int steps=(arr[i-1]*arr[k]*arr[j])+dp[i][k]+dp[k+1][j];
                if(steps<mini) mini=steps;
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][n-1];
}
int main(){  
    int n;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the size of matrix : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int ans=matrixChain(arr,n);
    printf("The multiplication needed : %d",ans);
    return 0;
}
