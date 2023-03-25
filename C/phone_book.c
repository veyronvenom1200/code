#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node {
    char *name;
    char *number;
    struct Node *next;
};

void insert(struct Node **head, char *name, char *number) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *current;
    struct Node * previous;

    new_node->name = name;
    new_node->number = number;
    new_node->next = NULL;

    if (*head == NULL || (strcmp(new_node->name, (*head)->name) < 0)) {
        new_node->next = *head;
        *head = new_node;
    } else {
        current = *head;
        previous = *head;
        while(strcmp(current->name,name) != 0 && current->next != NULL) {
            previous = current;
            current = current->next;
        }
        if (strcmp(current->name,name) > 0) {
            previous->next = new_node;
            new_node->next = current;
        } else {
            new_node->next = current->next;
            current->next = new_node;
        }
    }
}

bool searchNode(struct Node **head_ref, char* name) {
    struct Node* temp = *head_ref;

    while (temp != NULL && strcmp(temp->name, name)!= 0) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Not Found\n");
        return false;
    } else {
        printf("Found: %*s (%.*s)%.*s-%.*s\n", 3, temp->name, 3, temp->number, 3, temp->number+3, 4, temp->number+6);
        return true;
    }
}

void printList(struct Node *ptr) {
    printf("\n");
    // start from beginning
    while(ptr != NULL) {
        printf("%*s (%.*s)%.*s-%.*s\n", 6, ptr->name, 3, ptr->number, 3, ptr->number+3, 4, ptr->number+6);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    insert(&head, "Jane", "2316206404");
    insert(&head, "Tammy", "2319382577");
    insert(&head, "Sam", "1234567890");
    insert(&head, "Angela", "0987654321");

    printList(head);

    char *nameSearch = "Jane";
    searchNode(&head, nameSearch);
}
