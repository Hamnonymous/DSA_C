#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int item){
    struct Node *newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=item;
    newnode->next=NULL;
    return newnode;
}
void PUSH(struct Node** top,int item){
    struct Node* newnode=createNode(item);
    newnode->next=*top;
    *top=newnode;
    printf("\n%d Pushed In Stack\n",newnode->data);
    return;
}
void POP(struct Node** top){
    if(*top == NULL){
        printf("Underflow");
        return ;
    }
    printf("\n%d Popped\n",(*top)->data);
    *top=(*top)->next;
    return;
}

void DisplayNode(struct Node *top){
    if(top == NULL){
        printf("The List is empty\n");
        return;
    }
    struct Node *ptr=top;
    printf("Stack: \n");
    while(ptr!=NULL){
        printf("|_%d_|\n",ptr->data);
        ptr=ptr->next;
    }
}

int main(){
    int n;
    struct Node *top=NULL;
    int item;
    while (1)
    {
        printf("Choice:\n1.PUSH\n2.POP\n3.Display\n4.Exit");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            printf("Enter The Data: ");
            scanf("%d",&item);
            PUSH(&top,item);
            break;
        case 2:
            POP(&top);
            break;
        case 3:
            DisplayNode(top);
            break;
        case 4:
            exit(0);
            break;
        
        default:
        printf("Try again!");
            break;
        }
        
        
    }
    
}