/*Linked List Insertion*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* insertatbeginning(struct node *head,int element)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=element;
    newnode->next=head;

    head=newnode;
    return head;
}
 struct node* insertatlast(struct node *head,int element)
 {
    struct node *newnode, *temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=element;
    newnode->next=NULL;
    if(head == NULL){
        return newnode;
    }
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    return head;
 }
 struct node* insertatgivennode(struct node *head,int element,int pos)
 {
    struct node *newnode,*temp;
    int i;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=element;
    newnode->next=NULL;
    if(pos == 1)
    {
        newnode->next=head;
        return newnode;
    }
    temp=head;
    for(i=1;i<pos-1 && temp!=NULL;i++)
    {
        temp = temp->next;
    }
    if(temp==NULL)
    {
        printf("invalid position\n");
        return head;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
 }
 void display(struct node *head)
 {
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d->", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
 }

 int main()
 {
    struct node *head=NULL;
    int n,i,element,pos,choice;
    printf("enter no of nodes:");
    scanf("%d",&n);
    printf("enter elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&element);
        head=insertatlast(head,element);
    }
    while(1){
    display(head);
    printf("\n 1. insert at beginning");
    printf("\n 2. insert at last");
    printf("\n 3. insert at given node");
    printf("\n 4. exit");
    printf("\n enter choice:");
    scanf("%d",&choice);
    if(choice==4)
    {
        printf("exiting.....\n");
        break;
    }

    printf("enter element:");
    scanf("%d",&element);

    switch(choice){
        case 1:
        head= insertatbeginning(head,element);
        break;
        case 2:
        head=insertatlast(head,element);
        break;
        case 3:
        printf("enter position:");
        scanf("%d",&pos);
        head=insertatgivennode(head,element,pos);
        break;
        default:
        printf("invalid choice");
    }
}
    printf("\n updated linkedlist:\n");
    display(head);
    return 0;
 }