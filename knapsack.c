#include<stdio.h>
void swap(float *a,float *b){
        float temp=*a;
        *a=*b;
        *b=temp;
}
float knapsack(float weight[],float ratio[],float profit[],int n,int m){
    float total=0;
    for(int i=0;i<n;i++){
        if(weight[i]<=m){
           total+=profit[i];
           m-=weight[i]; 
        }
        else if(m<weight[i]){  
            float rem=m/weight[i];
            total+=(profit[i] * rem);
            break;
        }
    }
return total;
}
int main(){
    int n;
    int m;
    printf("Enter the number of goods : ");
    scanf("%d",&n);
    float profit[n];
    float weight[n];
    printf("Enter the total capacity : ");
    scanf("%d",&m);
    printf("Enter the profits : ");
    for(int i=0;i<n;i++){
        scanf("%f",&profit[i]);
    }
    printf("Enter the weights : ");
    for(int i=0;i<n;i++){
        scanf("%f",&weight[i]);
    }
    float ratio[n];
    for(int i=0;i<n;i++){
        ratio[i]=profit[i]/weight[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(ratio[i]<ratio[j]){
                 swap(&ratio[i],&ratio[j]);
                 swap(&profit[i],&profit[j]);
                 swap(&weight[i],&weight[j]);
            }
        }
    }
    
    float total=knapsack(weight,ratio,profit,n,m);
    printf("%f",total);
    return 0;
}
