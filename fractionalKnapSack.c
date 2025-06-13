
#include <stdio.h>

typedef struct{
    float weight;
    float profit;
    float ratio;
}knap;

void knapsack(int n,knap arr[],float capacity){
    float tp=0.0;
    int temp;
    float u=capacity;
    float x[10];
    for(int i=0;i<n;i++){
        if(arr[i].weight>u){
            temp = i;
            break;
        }else{
            x[i]=1.0;
            tp+=arr[i].profit;
            u=u-arr[i].weight;
        }
    }
    
    if(u > 0.0){
        x[temp] = u/arr[temp].weight;
        tp = tp + (x[temp]*arr[temp].profit);
    }
    
    printf("Total profit: %.2f",tp);
    printf("\nKnapsack: ");
    for(int i=0;i<n;i++){
        printf("%.2f\t",x[i]);
    }
    
    
}

int main()
{
    int n,i,j;
    float capacity;
    knap arr[10];
    printf("Enter Number of Items: ");
    scanf("%d",&n);
    printf("\nEnter Weights and Profits: ");
    for(i=0;i<n;i++){
        scanf("%f %f",&arr[i].weight,&arr[i].profit);
        arr[i].ratio = arr[i].profit/arr[i].weight;
    }
    printf("\nEnter Knapsack capacity: ");
    scanf("%f",&capacity);
    
    knap temp;
    for(i=1;i<n;i++){
        for(j=0;j<n-1;j++){
            if(arr[j+1].ratio>arr[j].ratio){
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    knapsack(n,arr,capacity);
    

    return 0;
}
