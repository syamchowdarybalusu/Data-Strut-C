#include <stdio.h>
#include <stdlib.h>

struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
};

struct DNode* headD = NULL;

// Insert at any position (0-based)
void insertAtPositionD(int value, int position) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = value;
    newNode->prev = newNode->next = NULL;

    if (position == 0 || headD == NULL) {
        newNode->next = headD;
        if (headD != NULL)
            headD->prev = newNode;
        headD = newNode;
        return;
    }

    struct DNode* temp = headD;
    for (int i = 0; i < position - 1 && temp->next != NULL; i++)
        temp = temp->next;

    newNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
    newNode->prev = temp;
}

// Delete at any position (0-based)
void deleteAtPositionD(int position) {
    if (headD == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct DNode* temp = headD;

    if (position == 0) {
        headD = headD->next;
        if (headD != NULL)
            headD->prev = NULL;
        free(temp);
        return;
    }

    for (int i = 0; i < position && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    if (temp->prev)
        temp->prev->next = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;

    free(temp);
}

// Search
void searchD(int value) {
    struct DNode* temp = headD;
    int pos = 0;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Found %d at position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Value not found.\n");
}

// Display
void displayD() {
    struct DNode* temp = headD;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
