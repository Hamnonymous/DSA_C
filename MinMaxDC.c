
#include <stdio.h>

typedef struct{
    int min;
    int max;
}MaxMin;

MaxMin findMaxMin(int arr[],int l,int h){
    MaxMin result;
    if(l==h){
        result.max=arr[l];
        result.min=arr[l];
        return result;
    }else if((l+1)==h){
        if(arr[l]<arr[h]){
            result.max=arr[h];
            result.min=arr[l];
            return result;
        }else{
            result.max=arr[l];
            result.min=arr[h];
            return result;
        }
    }
    int mid=(l+h)/2;
    MaxMin leftres=findMaxMin(arr,l,mid);
    MaxMin rightres=findMaxMin(arr,mid+1,h);
    result.max=(leftres.max<rightres.max)?rightres.max:leftres.max;
    result.min=(leftres.min>rightres.min)?rightres.min:leftres.min;
    
    return result;
    
}


int main()
{
    int n;
    printf("Enter Size of Array: ");
    scanf("%d",&n);
    int arr[100];
    printf("Enter Values: ");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    MaxMin result= findMaxMin(arr,0,n-1);
    printf("Max=%d",result.max);
    printf("Min=%d",result.min);
    return 0;
}
