#include<stdio.h>
void nqueen(int n,char board[n][n],int col,int leftrow[],int upperd[],int lowerd[]){
    if(col==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%c",board[i][j]);
            }
            printf("\n");
        }
         printf("\n");
          return ;
        }

        for(int row=0;row<n;row++){
            if(leftrow[row]==0 &&  upperd[n-1+col-row]==0 && lowerd[row+col]==0){
                board[row][col]='Q';
                leftrow[row]=1;
                upperd[n-1+col-row]=1;
                lowerd[row+col]=1;
                nqueen(n,board,col+1,leftrow,upperd,lowerd);
                board[row][col]='.';
                leftrow[row]=0;
                upperd[n-1+col-row]=0;
                lowerd[row+col]=0;
            }
        }
    
}
int main(){
    int n;
    printf("Enter the size of biard : ");
    scanf("%d",&n);
    char board[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]='.';
        }
    }
    int leftrow[n],lowerd[2*n-1],upperd[2*n-1];
    for(int i=0;i<n;i++) leftrow[i]=0;
    for(int i=0;i<2*n-1;i++){
        upperd[i]=0;
        lowerd[i]=0;
    }
    nqueen(n,board,0,leftrow,upperd,lowerd);
    return 0;
}
