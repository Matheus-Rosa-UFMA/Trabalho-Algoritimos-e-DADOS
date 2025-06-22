#ifndef INTERPRET_H
#define INTERPRET_H

#include "stack.h"   // <-- inclua o stack.h aqui para conhecer Stack
#include "list.h"

// Modifique a assinatura da função interpret para aceitar List*
void interpret(const char *source, List* lista); //
void set_stack(Stack* s);
void set_list(List* l);

#endif
