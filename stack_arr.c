#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX], top = -1;

// Push function
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = value;
    printf("%d pushed to stack.\n", value);
}

// Pop function
void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return;
    }
    printf("%d popped from stack.\n", stack[top--]);
}

// Display function
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int choice, value;
    
    while (1) {
        printf("\nEnter 1 to Push, 2 to Pop, 3 to Display, 4 to Exit: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
        } else if (choice == 2) {
            pop();
        } else if (choice == 3) {
            display();
        } else if (choice == 4) {
            exit(0);
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
