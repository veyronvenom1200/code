#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev, *next;
    int data;
};

typedef struct node node;

int main(int argc, char const *argv[])
{
    node *head = NULL;
    head->data = 5;
    node *new_node = malloc(sizeof(node));
    new_node->data = 4;
    head->next = new_node;
    printf("%d\n", head->next->data);
    return 0;
}