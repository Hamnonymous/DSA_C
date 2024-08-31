#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* head;
// struct node* newnode;
int InsertData(){
    struct node* newnode;
    struct node* p;
    int i,key;
    printf("1.Beginning\n2.Desired Location\n3.End\nEnter Your Choice( Any other key to exit ): ");
    scanf("%d",&i);
    switch (i)
    {
    case 1:
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL){
            printf("Overflow...");
            return 1;
        }
        printf("Enter Data: ");
        scanf("%d",&(newnode->data));
        if(head==NULL){
            head=newnode;
            newnode->next=head;
        }else{
            p=head;
            while(p->next!=head){
                p=p->next;
            }
            p->next=newnode;
            newnode->next=head;
            head=newnode;
        }
        break;
    case 2:
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL){
            printf("Overflow...");
            return 1;
        }
        l:
        printf("Enter Desired location Value: ");
        scanf("%d",&key);
        p=head;
        while(p->data!=key&&p->next!=head){
            p=p->next;
        }
        if(p->data==key){
            printf("Enter Data: ");
            scanf("%d",&(newnode->data));
            newnode->next=p->next;
            p->next=newnode;
        }else{
            printf("Value not found in Linked List...Try Again\n");
            goto l;
        }
        break;
    case 3:
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL){
            printf("Overflow...");
            return 1;
        }
        if(head==NULL){
            printf("Enter Data: ");
            scanf("%d",&(newnode->data));
            newnode->next=newnode;
            head=newnode;
        }else{
        p=head;
        while(p->next!=head){
            p=p->next;
        }
        printf("Enter Data: ");
        scanf("%d",&(newnode->data));
        newnode->next=head;
        p->next=newnode;
        }
        break;
    
    default:
        printf("Exiting insertion...");
        return 1;
        break;
    }
}

int DeleteData(){
    struct node* p;
    int i,key;
    printf("1.Beginning\n2.Desired Location\n3.End\nEnter Your Choice( Any other key to exit ): ");
    scanf("%d",&i);
    switch (i)
    {
    case 1:
        if(head==NULL){
            printf("Underflow...");
            return 1;
        }
        p=head;
        while(p->next!=head){
            p=p->next;
        }
        p->next=head->next;
        head=head->next;
        break;
    case 2:
        if(head==NULL){
            printf("Underflow...");
            return 1;
        }
        l:
        printf("Enter Desired location Value to Delete: ");
        scanf("%d",&key);
        struct node* q;
        p=head;
        if(head->data==key&&head->next==head){
            head=NULL;
            return 1;
        }
        while(p->data!=key&&p->next!=head){
            q=p;
            p=p->next;
        }
        if(p->data==key){
            q->next=p->next;
        }else{
            printf("Value not found in Linked List...Try Again\n");
            goto l;
        }
        break;
    case 3:
        if(head==NULL){
            printf("Underflow...");
            return 1;
        }
        p=head;
        if(head->next==head){
            head=NULL;
            return 1;
        }
        while(p->next->next!=head){
            p=p->next;
        }
        p->next=head;
        break;
    
    default:
        printf("Exiting deletion...");
        return 1;
        break;
    }
}

int DisplayData(){
    struct node* p;
    if(head==NULL){
        printf("Linked list is empty!\n");
        return 1;
    }
    p=head;
    while (p->next != head)
{
    printf("Data = %d, Present-Address = %u, Next-Address = %u\n",p->data,p,p->next);
    p=p->next;
    if (p->next == head)
    {
    printf("Data = %d, Present-Address = %u, Next-Address = %u\n",p->data,p,p->next);
    }
}
return 1;
}
int main(){
head =NULL;
int i=1,n;
do{
    printf("Menu\n1. Insert\n2. Display LL\n3. Delete\n0. Exit\nEnter Your Choice: ");
    scanf("%d",&n);
    switch (n)
    {
    case 1:
        InsertData();
        break;
    case 2:
        DisplayData();
        break;
    case 3:
        DeleteData();
        break;
    
    default:
        printf("Exiting...");
        exit(0);
        break;
    }
}while(1);

return 0;
}
