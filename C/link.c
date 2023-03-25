#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void PrintList(struct Node *ptr) {
    while(ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void InsertAtEnd(struct Node* ptr) {
    struct Node* add = NULL;
    add = (struct Node*)malloc(sizeof(struct Node));
    add->data = 4;
    add->next = NULL;
    ptr->next = add;
}

void InsertInBetween(struct Node *first, struct Node *second, int data) {
    struct Node* add = NULL;
    add = (struct Node*)malloc(sizeof(struct Node));
    add->data = data;
    first->next = add;
    add->next = second;
}

void Delete(struct Node *ptr, int data) {
    struct Node* temp = ptr, *prev;

    while(ptr->data != data && ptr != NULL) {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = ptr->next->next;
}

void hi(int *bye) {
    ++*bye;
}

int main()e
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    InsertAtEnd(third);
    InsertInBetween(head, second, 6);
    // Delete(head, 3);

    int x = 200;
    hi(&x);

    printf("%d\n", x);

    PrintList(head);
}
