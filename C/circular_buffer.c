/*
 * Author: Nathan Dohm
 * Date: March 31, 2018
 *
 * circular_buffer.c is a simple circular buffer that uses a linked list as its data structure
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    int key;
    struct node *next;
};

void print_list(struct node *ptr);
void add(struct node** head_ref, int new_data, int* size);
void delete_node(struct node **head_ref, int* size);

// Display list
void print_list(struct node *ptr) {
    printf("[ ");

    // start from beginning
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("]\n");
}

void add(struct node** head_ref, int new_data, int* size)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node *current;

    new_node->data  = new_data;

    // if list has more than the set number of nodes
    if (*size > 9) {
        delete_node(*&head_ref, *&size);
    }

    /*
     * creates the head node or attaches  the new  head node if
     * the head node already exists and is being replaced
     */
    if (*head_ref == NULL || ((*size)%10 == 0)) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        current = *head_ref;
        int i = 1;
        while (current->next != NULL && (i < (*size)%10)) { // determines where to insert the new node
            current = current->next;
            ++i;
    }

    new_node->next = current->next;
    current->next = new_node;
    }

    ++(*size);
}

void delete_node(struct node **head_ref, int* size)
{
    // Store head node
    struct node* temp = *head_ref, *prev;
    int i = 0;

    // If head node itself needs to be deleted
    if (temp != NULL && ((*size)%10 == 0))
    {
        *head_ref = temp->next;   // Changed head
        free(temp);               // free old head
        return;
    }

    /*
     * Search for the key to be deleted, keep track of the
     * previous struct node as it needs to change 'prev->next'
     */
    while (temp != NULL && (i < (*size)%10))
    {
        prev = temp;
        temp = temp->next;
        ++i;
    }

    // Unlink the struct node from linked list
    prev->next = temp->next;

    free(temp);  // Free memory
}

int main() {
    int size = 0;
    struct node *head = NULL;

    for(int a = 1; a != 17; ++a) {
        add(&head, a, &size);
    }

    print_list(head);
}
