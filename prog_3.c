#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* newNode(int val) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = val;
    n->next = NULL;
    return n;
}

void append(struct Node **head, int val) {
    struct Node *nn = newNode(val);
    if (*head == NULL) { *head = nn; return; }
    struct Node *tmp = *head;
    while (tmp->next) tmp = tmp->next;
    tmp->next = nn;
}

void printList(struct Node *head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// reverse traversal using recursion
void reverseTraversal(struct Node *head) {
    if (head == NULL) return;
    reverseTraversal(head->next);
    printf("%d ", head->data);
}

int main() {
    struct Node *head = NULL;

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);

    printf("Original list: ");
    printList(head);

    printf("Reverse traversal: ");
    reverseTraversal(head);
    printf("\n");

    return 0;
}
