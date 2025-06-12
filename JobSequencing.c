
#include <stdio.h>

typedef struct{
    char id[2];
    int profit;
    int deadline;
}job;

int minValue(int x,int y){
    return (x<y)?x:y;
}

void JobSequencing(job arr[],int n){
    int i,j,k,maxprofit;
    int dmax=0;
    int timeslot[n];
    int filledts=0;
    
    for(i=0;i<n;i++){
        if(dmax<arr[i].deadline){
            dmax=arr[i].deadline;
        }
    }
    
    for(i=1;i<=dmax;i++){
        timeslot[i]=-1;
    }
    
    printf("dmax=%d\n",dmax);
    
    for(i=1;i<=n;i++){
        k = minValue(dmax,arr[i-1].deadline);
        while(k>=1){
            if(timeslot[k]==-1){
                timeslot[k]=i-1;
                filledts++;
                break;
            }
        k--;
        }
        if(dmax==filledts){
            break;
        }
    }
    
    printf("Required Jobs: ");
    for(i=1;i<=dmax;i++){
        printf("%s",arr[timeslot[i]].id);
        if(i<dmax){
            printf(" --> ");
        }
    }
    
    maxprofit=0;
    for(i=1;i<=dmax;i++){
        maxprofit+=arr[timeslot[i]].profit;
    }
    printf("\nMaxprofit=%d",maxprofit);
    
    
}

int main()
{   
    int i,j;
    
    job arr[6]={
        {"j1",200,3},
        {"j2",300,3},
        {"j3",100,5},
        {"j4",150,4},
        {"j5",500,4},
        {"j6",150,1},
    };

    job temp;
    
    int n=6;
    
    for(i=1;i<n;i++){
        for(j=0;j<n-1;j++){
            if(arr[j+1].profit>arr[j].profit){
                temp = arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    
    printf("%10s %10s %10s\n", "Job", "Deadline", "Profit");
    for(i = 0; i < n; i++) {
        printf("%10s %10i %10i\n", arr[i].id, arr[i].deadline, arr[i].profit);
    }
    
    JobSequencing(arr,n);

    return 0;
}

