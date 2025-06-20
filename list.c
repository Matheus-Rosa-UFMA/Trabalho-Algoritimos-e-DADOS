#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct Node {
    char key[50];
    int value;
    struct Node* next;
} Node;

struct list {
    Node* first;
};

List* new_list() {
    List* l = (List*)malloc(sizeof(List));
    l->first = NULL;
    return l;
}

void list_append(List* s, char* key, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->key, key);
    node->value = value;
    node->next = s->first;
    s->first = node;
}

int list_exist(List* s, char* key) {
    Node* current = s->first;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void list_set(List* s, char* key, int value) {
    Node* current = s->first;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            current->value = value;
            return;
        }
        current = current->next;
    }
    // se não existir, adiciona
    list_append(s, key, value);
}

int list_get(List* s, char* key) {
    Node* current = s->first;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return -1; // valor padrão caso não encontrado
}

void list_print(List* s) {
    Node* current = s->first;
    while (current != NULL) {
        printf("%s = %d\n", current->key, current->value);
        current = current->next;
    }
}
