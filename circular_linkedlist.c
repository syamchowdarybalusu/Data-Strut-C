#include <stdio.h>
#include <stdlib.h>

struct CNode {
    int data;
    struct CNode* next;
};

struct CNode* headC = NULL;

// Insert at beginning
void insertAtBeginC(int value) {
    struct CNode* newNode = (struct CNode*)malloc(sizeof(struct CNode));
    newNode->data = value;

    if (headC == NULL) {
        newNode->next = newNode;
        headC = newNode;
        return;
    }

    struct CNode* temp = headC;
    while (temp->next != headC)
        temp = temp->next;

    newNode->next = headC;
    temp->next = newNode;
    headC = newNode;
}

// Insert at end
void insertAtEndC(int value) {
    struct CNode* newNode = (struct CNode*)malloc(sizeof(struct CNode));
    newNode->data = value;

    if (headC == NULL) {
        newNode->next = newNode;
        headC = newNode;
        return;
    }

    struct CNode* temp = headC;
    while (temp->next != headC)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = headC;
}

// Delete at beginning
void deleteAtBeginC() {
    if (headC == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (headC->next == headC) {
        free(headC);
        headC = NULL;
        return;
    }

    struct CNode* temp = headC;
    while (temp->next != headC)
        temp = temp->next;

    struct CNode* delNode = headC;
    headC = headC->next;
    temp->next = headC;
    free(delNode);
}

// Delete at end
void deleteAtEndC() {
    if (headC == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (headC->next == headC) {
        free(headC);
        headC = NULL;
        return;
    }

    struct CNode* temp = headC;
    while (temp->next->next != headC)
        temp = temp->next;

    free(temp->next);
    temp->next = headC;
}

// Search for a value
void searchC(int value) {
    if (headC == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct CNode* temp = headC;
    int pos = 0;
    do {
        if (temp->data == value) {
            printf("Value %d found at position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != headC);

    printf("Value not found.\n");
}

// Display the list
void displayC() {
    if (headC == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct CNode* temp = headC;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != headC);
    printf("(Back to head)\n");
}
