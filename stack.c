// stack.c - Implementação da pilha
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack {
    int *data;
    int top;
    int size;
};

Stack* new_stack(int size) {
    Stack *s = malloc(sizeof(Stack));
    s->data = malloc(sizeof(int) * size);
    s->top = -1;
    s->size = size;
    return s;
}

void stack_push(Stack* s, int value) {
    if (s->top >= s->size - 1) {
        printf("Erro: pilha cheia.\n");
        return;
    }
    s->data[++(s->top)] = value;
}

int stack_pop(Stack* s) {
    if (s->top < 0) {
        printf("Erro: pilha vazia.\n");
        return 0;
    }
    return s->data[(s->top)--];
}

void stack_print(Stack* s) {
    if (s->top < 0) {
        printf("Pilha vazia.\n");
        return;
    }
    printf("Pilha: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}
