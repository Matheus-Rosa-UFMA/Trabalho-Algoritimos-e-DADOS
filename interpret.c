// interpret.c
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "interpret.h"
#include "stack.h"
#include "list.h"

static Stack* pilha = NULL;
static List* lista = NULL;

void set_list(List* l) {
    lista = l;
}
void set_stack(Stack* s) {
    pilha = s;
}

void interpret(const char *source,List*lista) {
    char op[10], arg[50];
    int n = sscanf(source, "%s %s", op, arg);

    if (strcmp(op, "exit") == 0) {
        exit(0);
    } 
    else if (strcmp(op, "push") == 0 && n == 2) {
        // verifica se é número
        int is_number = 1;
        for (int i = 0; i < strlen(arg); i++) {
            if (!isdigit(arg[i]) && !(i == 0 && arg[i] == '-')) {
                is_number = 0;
                break;
            }
        }

        if (is_number) {
            int value = atoi(arg);
            stack_push(pilha, value);
        } else {
            if (list_exist(lista, arg)) {
                int value = list_get(lista, arg);
                stack_push(pilha, value);
            } else {
                printf("Variavel '%s' nao encontrada.\n", arg);
            }
        }
    } 
    else if (strcmp(op, "pop") == 0 && n == 2) {
        int value = stack_pop(pilha);
        list_set(lista, arg, value);
    }
    else if (strcmp(op, "add") == 0) {
        int b = stack_pop(pilha);
        int a = stack_pop(pilha);
        stack_push(pilha, a + b);
    } 
    else if (strcmp(op, "sub") == 0) {
        int b = stack_pop(pilha);
        int a = stack_pop(pilha);
        stack_push(pilha, b - a);
    } 
    else if (strcmp(op, "mul") == 0) {
        int b = stack_pop(pilha);
        int a = stack_pop(pilha);
        stack_push(pilha, a * b);
    } 
    else if (strcmp(op, "div") == 0) {
        int b = stack_pop(pilha);
        int a = stack_pop(pilha);
        if (b == 0) {
            printf("Erro: divisao por zero.\n");
        } else {
            stack_push(pilha, a / b);
        }
    } 
    else if (strcmp(op, "print") == 0) {
        int value = stack_pop(pilha);
        printf("%d\n", value);
    }
    else {
        printf("Comando inválido: %s\n", op);
    }
}
