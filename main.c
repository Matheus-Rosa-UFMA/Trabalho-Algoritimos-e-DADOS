#include <stdio.h>
#include "interpret.h"
#include "stack.h"
#include "list.h"

// Modifique repl para aceitar um argumento List*
static void repl(List* lista) { //
    char line[1024];
    for (;;) {
        printf("> ");
        if (!fgets(line, sizeof(line), stdin)) {
            printf("\n");
            break;
        }
        interpret(line, lista); //
    }
}

int main () {
    Stack* pilha = new_stack(100);
    List* lista = new_list();
    
    set_stack(pilha);
    set_list(lista);
    
    repl(lista); //
    return 0;
}
