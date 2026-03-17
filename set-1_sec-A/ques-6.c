/*check if circular linkedlist*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int isCircular(struct Node* head) {
    if (!head) 
        return 1;

    struct Node* temp = head->next;

    while (temp != NULL && temp != head)
        temp = temp->next;

    return (temp == head);
}

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int n, i, value, choice;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Make it circular? (1 = Yes, 0 = No): ");
    scanf("%d", &choice);

    if(choice == 1)
        temp->next = head;   

    if (isCircular(head))
        printf("Circular Linked List\n");
    else
        printf("Not Circular Linked List\n");

    return 0;
}