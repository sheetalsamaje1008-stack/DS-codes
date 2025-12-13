#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void create() {
    int item;
    printf("enter value (enter -999 for exit):");
    scanf("%d",&item);
    while(item != -999){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = item;
    newnode->prev = NULL;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
    }
    else{
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
    }
    printf("enter value:");
    scanf("%d",&item);
    }




}

void insert_left(int key, int value) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = value;

    struct Node *temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node not found\n");
        free(newnode);
        return;
    }

    newnode->next = temp;
    newnode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newnode;
    else
        head = newnode;

    temp->prev = newnode;
}

void delete_value(int key) {
    struct Node *temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

void display() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, key;

    do {
        printf("\n1.Create\n2.Insert Left\n3.Delete\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:

                create();
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Insert left of: ");
                scanf("%d", &key);
                insert_left(key, value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                delete_value(key);
                break;

            case 4:
                display();
                break;

            case 5:
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
