#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* newNode(int val) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = val;
    n->prev = n->next = NULL;
    return n;
}

// insert after a given node
void insertAfter(struct Node *prev_node, int val) {
    if (prev_node == NULL) return;
    struct Node *nn = newNode(val);
    nn->next = prev_node->next;
    nn->prev = prev_node;
    if (prev_node->next) prev_node->next->prev = nn;
    prev_node->next = nn;
}

void deleteNode(struct Node **head, struct Node *del) {
    if (*head == NULL || del == NULL) return;
    if (*head == del) *head = del->next;
    if (del->next) del->next->prev = del->prev;
    if (del->prev) del->prev->next = del->next;
    free(del);
}

void printForward(struct Node *head) {
    printf("Forward: ");
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void printBackward(struct Node *head) {
    if (!head) return;
    while (head->next) head = head->next;
    printf("Backward: ");
    while (head) {
        printf("%d ", head->data);
        head = head->prev;
    }
    printf("\n");
}

int main() {
    struct Node *head = newNode(10);
    head->next = newNode(20);
    head->next->prev = head;
    head->next->next = newNode(30);
    head->next->next->prev = head->next;

    printf("Initial list:\n");
    printForward(head);
    printBackward(head);

    // insert 15 after first node
    insertAfter(head, 15);
    printf("\nAfter inserting 15 after 10:\n");
    printForward(head);

    // delete node with value 20
    struct Node *tmp = head;
    while (tmp && tmp->data != 20) tmp = tmp->next;
    deleteNode(&head, tmp);
    printf("\nAfter deleting 20:\n");
    printForward(head);
    printBackward(head);

    return 0;
}
