#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertBeg(int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val;
    n->next = head;
    head = n;
}

void insertEnd(int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val;
    n->next = NULL;
    if (!head) head = n;
    else {
        struct Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }
}

void insertMid(int pos, int val) {
    if (pos <= 1 || !head) {
        insertBeg(val);
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next; i++)
        temp = temp->next;

    struct Node* n = malloc(sizeof(struct Node));
    n->data = val;
    n->next = temp->next;
    temp->next = n;
}

void deleteBeg() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteEnd() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    if (!head->next) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void deleteMid(int pos) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    if (pos <= 1 || !head->next) {
        deleteBeg();
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next && temp->next->next; i++)
        temp = temp->next;

    struct Node* del = temp->next;
    if (del) {
        temp->next = del->next;
        free(del);
    } else {
        printf("Invalid position.\n");
    }
}

void display() {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void search(int val) {
    struct Node* temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == val) {
            printf("Found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Not found.\n");
}

int main() {
    int ch, val, pos;
    while (1) {
        printf("\n1.InsertBeg  2.InsertEnd  3.InsertMid\n");
        printf("4.DeleteBeg  5.DeleteEnd  6.DeleteMid\n");
        printf("7.Display    8.Search     9.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Value: ");
            scanf("%d", &val);
            insertBeg(val);
        }
        else if (ch == 2) {
            printf("Value: ");
            scanf("%d", &val);
            insertEnd(val);
        }
        else if (ch == 3) {
            printf("Position & Value: ");
            scanf("%d%d", &pos, &val);
            insertMid(pos, val);
        }
        else if (ch == 4) deleteBeg();
        else if (ch == 5) deleteEnd();
        else if (ch == 6) {
            printf("Position to delete: ");
            scanf("%d", &pos);
            deleteMid(pos);
        }
        else if (ch == 7) display();
        else if (ch == 8) {
            printf("Value to search: ");
            scanf("%d", &val);
            search(val);
        }
        else if (ch == 9) break;
        else printf("Invalid choice.\n");
    }
    return 0;
