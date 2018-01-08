#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int value;
    struct node *next;
};

void push(struct node *head_node, int value) {
    if (head_node->next == NULL) {
        // First node with data
        head_node->next = malloc(sizeof(struct node));
        head_node->next->value = value;
        head_node->next->next = NULL;
    }

    // Second or later node with data
    struct node *current = head_node->next;
    while (current->next != NULL)
        current = current->next;

    current->next = malloc(sizeof(struct node));
    current->next->value = value;
    current->next->next = NULL;
}

int pop(struct node *head_node) {
    struct node *current = head_node->next;
    struct node *headnn = head_node->next->next;
    int value = current->value;
    free(head_node->next);
    head_node->next=headnn;
    return value;
}

void clean(struct node *head_node) {
    for(int i=0; i<(sizeof(head_node)/sizeof(int));i++)
        pop(head_node);
}

int main() {
    // head_node is not the 1st node in the list
    struct node *head_node = NULL;
    head_node = malloc(sizeof(struct node));

    // malloc test
    if (head_node == NULL)
        return 1;

    head_node->next = NULL;

    // Randomize
    srand(time(NULL));
    int max = 25;
    int n;
    printf("Enter nodes number: ");
    scanf("%d", &n);

    // Create nodes with random values
    for(int i=0; i<n;i++)
        push(head_node, (rand() % max+1));

    printf("\nList:\n");
    struct node *current = head_node->next->next;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    // Clean
    clean(head_node);

    return 0;
}