#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data; // node data
    struct node* next; // pointer to next node
} Node;

Node defaultNode = {-1, NULL};

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error creating new node\n");
        exit(0);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);

    newNode->next = *head;
    *head = newNode;
}

void removeHead(Node** head) {
    
    if (head != NULL) {
        Node* oldHead = *head;
        *head = (*head)->next;
        free(oldHead);
    }
  

}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
    
Node* traverseAndGet(Node* head, int index) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    // Node* temp;
    int counter = 0;

    while (head != NULL) {
        if (counter == index) {
            return head;
        }
        head = head->next;
        counter++;
    }
    printf("Index %d out of bounds exception.\n", index);
    return &defaultNode;
}   

int main() {
    Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    removeHead(&head);

    printList(head);

    printf("Node data: %d\n", traverseAndGet(head, 1)->data);

    return 0;
}