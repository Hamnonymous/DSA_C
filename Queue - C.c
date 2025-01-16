#include<stdio.h>
#include<stdlib.h>

int main(){
    int n=3;
    int arr[3];
    int rear=-1;
    int front=0;
    int choice,value;
    while (1)
    {
        printf("\n1. Enqueue 2. Dequeue 3. Display 4. Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter Value: ");
            scanf("%d",&value);
            if(rear != n-1){
                rear++;
                arr[rear]=value;
            }else{
                printf("Queue Full!");
            }
            break;
        case 2:
            if(front <= rear){
                printf("Dequeued %d",arr[front]);
                front++;
                if(front>rear){
                    rear=-1;
                    front=0;
                }
            }else{
                printf("Queue Empty!");
            }
            break;
        
        case 3:
        for(int i=front;i<=rear;i++){
            printf("%d ",arr[i]);
        }
            break;
        case 4:
        exit(0);
        break;
        
        default:
            break;
        }
    }
    
}