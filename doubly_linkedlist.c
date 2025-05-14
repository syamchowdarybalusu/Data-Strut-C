#include <stdio.h>
#include <stdlib.h>

struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
};

struct DNode* headD = NULL;

// Insert at beginning
void insertAtBeginD(int value) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = headD;
    if (headD != NULL)
        headD->prev = newNode;
    headD = newNode;
}

// Insert at end
void insertAtEndD(int value) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = value;
    newNode->next = NULL;

    if (headD == NULL) {
        newNode->prev = NULL;
        headD = newNode;
        return;
    }

    struct DNode* temp = headD;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Delete at beginning
void deleteAtBeginD() {
    if (headD == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct DNode* temp = headD;
    headD = headD->next;
    if (headD != NULL)
        headD->prev = NULL;
    free(temp);
}

// Delete at end
void deleteAtEndD() {
    if (headD == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct DNode* temp = headD;
    if (temp->next == NULL) {
        free(headD);
        headD = NULL;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

// Search for a value
void searchD(int value) {
    struct DNode* temp = headD;
    int pos = 0;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value %d found at position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Value not found.\n");
}

// Display the list
void displayD() {
    struct DNode* temp = headD;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
