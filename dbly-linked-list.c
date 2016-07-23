#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

typedef struct node {
    char* name;
    char* sport;
    struct node* prev;
    struct node* next;
}node;

node* head = NULL;

node* getNewNode(char* name_a, char* sport_a) {
    node* new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        printf("malloc failed");
        return new_node;
    }
    
    new_node->name = name_a;
    new_node->sport = sport_a;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void addNode(char* name_a, char* sport_a) {
    node* new_node = getNewNode(name_a, sport_a);
    if (head == NULL) {
        head = new_node;
        return;
    }
    head->prev = new_node;
    new_node->next = head;
    head = new_node;
}

void printList() {
    node* curr = head;
    printf("%s,%s\n", curr->name, curr->sport);
    while (curr->next != NULL) {
        curr = curr->next;
        printf("%s,%s\n", curr->name, curr->sport);
    }
}

void printReverse() {
    node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    
    printf ("%s,%s\n", curr->name, curr->sport);
    while (curr->prev != NULL) {
        curr = curr->prev;
        printf("%s,%s\n", curr->name, curr->sport);
    }
}

int main(void) {
    addNode("Jackson Lenhart", "Basketball");
    addNode("Jimmy Butler", "Basketball");
    addNode("Joe Flacco", "American Football");
    addNode("Lionel Messi", "Football");
    
    printList();
    printf("\n");
    printReverse();
    return 0;
}
