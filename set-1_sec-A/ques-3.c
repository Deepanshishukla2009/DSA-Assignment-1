/*Delete a Node in Single Linked...*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* createlist(struct node *head, int val)
{
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL)
        return newNode;

    temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

/* -------- Display -------- */
void display(struct node *head)
{
    struct node *temp = head;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* -------- Delete at Beginning -------- */
struct node* deleteAtBeginning(struct node *head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    struct node *temp = head;
    head = head->next;
    free(temp);

    return head;
}

/* -------- Delete at Last -------- */
struct node* deleteAtLast(struct node *head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    if(head->next == NULL)
    {
        free(head);
        return NULL;
    }

    struct node *temp = head;

    while(temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;

    return head;
}

/* -------- Delete at Position -------- */
struct node* deleteAtPosition(struct node *head, int pos)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    if(pos == 1)
        return deleteAtBeginning(head);

    struct node *temp = head;
    int i;

    for(i = 1; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if(temp->next == NULL)
    {
        printf("Invalid position\n");
        return head;
    }

    struct node *del = temp->next;
    temp->next = del->next;
    free(del);

    return head;
}

/* -------- Main Function -------- */
int main()
{
    struct node *head = NULL;
    int n, i, element, pos, choice;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &element);
        head = createlist(head, element);
    }

    while(1)
    {
        printf("\nCurrent Linked List:\n");
        display(head);

        printf("\n1. Delete at beginning");
        printf("\n2. Delete at last");
        printf("\n3. Delete at position");
        printf("\n4. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                head = deleteAtBeginning(head);
                break;

            case 2:
                head = deleteAtLast(head);
                break;

            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                head = deleteAtPosition(head, pos);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
