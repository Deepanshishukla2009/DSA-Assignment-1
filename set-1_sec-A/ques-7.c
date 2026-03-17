/*Find length of Loop*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int findLoopLength(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {  
            int count = 1;
            struct Node* temp = slow;

            while (temp->next != slow) {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }

    return 0;
}

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int n, i, value, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node* nodes[n];

    for(i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data for node %d: ", i+1);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;
        nodes[i] = newNode;

        if(head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Enter position to create loop (0 for no loop): ");
    scanf("%d", &pos);

    if(pos > 0 && pos <= n)
        temp->next = nodes[pos-1];

    int length = findLoopLength(head);

    if(length > 0)
        printf("Length of Loop = %d\n", length);
    else
        printf("No Loop in Linked List\n");

    return 0;
}