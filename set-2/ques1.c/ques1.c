#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

struct Node* reverse(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void reverseAlternate(struct Node* head) {
    if (!head || !head->next) return;

    struct Node *odd = head;
    struct Node *even = head->next;
    struct Node *evenHead = even;
    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    odd->next = NULL;
    evenHead = reverse(evenHead);
    struct Node *curr1 = head;
    struct Node *curr2 = evenHead;

    while (curr2) {
        struct Node *temp1 = curr1->next;
        struct Node *temp2 = curr2->next;

        curr1->next = curr2;
        curr2->next = temp1;

        curr1 = temp1;
        curr2 = temp2;
    }
}

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int n, i, value;

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

    printf("Original Linked List: ");
    printList(head);

    reverseAlternate(head);

    printf("\nAfter Reversing Alternate Nodes: ");
    printList(head);

    return 0;
}