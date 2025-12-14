#include <stdio.h>

void push(int arr[], int n, int *top) {
    if (*top == n - 1) {
        printf("Stack is full\n");
        return;
    } else {
        int value;
        (*top)++;
        printf("Enter a value to push: ");
        scanf("%d", &value);
        arr[*top] = value;
    }
}

void pop(int arr[], int *top) {
    if (*top == -1) {
        printf("Stack is empty\n");
        return;
    } else {
        printf("Popped element: %d\n", arr[*top]);
        (*top)--;
    }
}

void display(int arr[], int top) {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", arr[i]);
    }
}

int main() {
    int n, top = -1;
    printf("Enter size of stack: ");
    scanf("%d", &n);

    int arr[n];
    int choice;

    do {
        printf("\nWhat do you want to do?\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(arr, n, &top);
                break;
            case 2:
                pop(arr, &top);
                break;
            case 3:
                display(arr, top);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}




