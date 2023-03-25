#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    int key;
    struct node *next;
};

typedef struct node node;

void print_list(node *ptr);
void add(node** head_ref, int new_data, int* size);
void delete_node(node **head_ref, int key);
bool search_node(node **head_ref, int key);

// Display list
void print_list(node *ptr) {
    printf("[ ");

    // start from beginning
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("]\n");
}

void add(node** head_ref, int new_data, int* size)
{
    node *new_node = (node*)malloc(sizeof(node));
    node *current;

    new_node->data  = new_data;

    if (*head_ref == NULL) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        current = *head_ref;
        while (current->next != NULL) {
            current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
    }

    ++(*size);
}

void delete_node(node **head_ref, int key)
{
    // Store head node
    node* temp = *head_ref, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;   // Changed head
        free(temp);               // free old head
        return;
    }

    /*
     * Search for the key to be deleted, keep track of the
     * previous node as we need to change 'prev->next'
     */
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return;

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp);  // Free memory
}

bool search_node(node **head_ref, int key) {
    node* temp = *head_ref;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return false;
    } else {
        return true;
    }
}

int main() {
    int size = 0;
    node *head = NULL;

    for(int a = 0; a != 10; ++a) {
        add(&head, a, &size);
        printf("%d", size);
    }
    add(&head, 1, &size);

    while (search_node(&head, 7)) {
        delete_node(&head, 7);
    }

    print_list(head);
}
