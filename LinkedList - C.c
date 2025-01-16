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
void appendNode(struct Node* head,struct Node* newnode){
    struct Node* ptr=head;
    int choice,key;
    printf("1.Insert in Middle\n2.Insert at end: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("Enter Key:");
        scanf("%d",&key);
        while (ptr->next->data!=key&&ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        if(ptr->next->data==key){
            newnode->next=ptr->next;
            ptr->next=newnode;
        }else{
            printf("Key Not Found!");
        }
        break;
    case 2:
        while (ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
        break;
    
    default:
        break;
    }
    return;
}

void DisplayNode(struct Node *head){
    if(head == NULL){
        printf("The List is empty\n");
        return;
    }
    struct Node *ptr=head;
    while(ptr!=NULL){
        printf("%d ->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n ");
}

int main(){
    int n;
    struct Node *head=NULL;
    struct Node *nde;
    int item,key;
    while (1)
    {
        printf("Choice:\n1.Insert\n2.Display\n3.Exit");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            printf("Enter The Data: ");
            scanf("%d",&item);
            nde=createNode(item);
            if(head==NULL){
                head=nde;
                break;
            }
            appendNode(head,nde);
            break;
        case 2:
            DisplayNode(head);
            break;
        case 3:
            exit(0);
            break;
        
        default:
        printf("Try again!");
            break;
        }
        
        
    }
    
}