#include <stdio.h>
#define MAX 100  

int queue[MAX], front = -1, rear = -1;

void enqueue(int data) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;  
    queue[++rear] = data;  
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

int peek() {
    return (front != -1 && front <= rear) ? queue[front] : -1;
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("Front Element: %d\n", peek());
    display();
    printf("Dequeued: %d\n", dequeue());
    display();
    return 0;
}
