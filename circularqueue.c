#include <stdio.h>
#include <stdlib.h>

#define CAP 5

int arr[CAP];
int front = 0;
int rear = -1;
int size = 0;

int isFull() { return size == CAP; }
int isEmpty() { return size == 0; }

int enqueue(int v) {
    if (isFull()) return 0;
    rear = (rear + 1) % CAP;
    arr[rear] = v;
    size++;
    return 1;
}

int dequeue(int *out) {
    if (isEmpty()) return 0;
    *out = arr[front];
    front = (front + 1) % CAP;
    size--;
    if (size == 0) { front = 0; rear = -1; }
    return 1;
}

void display() {
    if (isEmpty()) { printf("[empty]\n"); return; }
    for (int i = 0; i < size; ++i) {
        int idx = (front + i) % CAP;
        printf("%d ", arr[idx]);
    }
    printf("\n");
}

int main(void) {
    int choice, x, val;
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nChoose: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = 0;
        }
        switch (choice) {
            case 1:
                printf("Value to enqueue: ");
                if (scanf("%d", &val) != 1) { while (getchar() != '\n'); break; }
                if (!enqueue(val)) printf("enqueue failed: full\n");
                else printf("enqueued %d\n", val);
                break;
            case 2:
                if (dequeue(&x)) printf("dequeued %d\n", x);
                else printf("dequeue failed: empty\n");
                break;
            case 3:
                display();
                break;
            case 4:
                printf("exiting\n");
                break;
            default:
                printf("invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}
