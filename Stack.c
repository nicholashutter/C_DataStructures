/*
return codes:
0 = success
1 = failure
*/

#include <stdlib.h>
#include "Stack.h"

struct Stack
{

    int top;
    int maxSize;
    int *stack;
};

Stack *new_stack(size_t maxSize)
{

    Stack *stack_ptr = malloc(sizeof(Stack));

    stack_ptr->stack = malloc(maxSize * sizeof(int));

    stack_ptr->maxSize = maxSize;

    stack_ptr->top = 0;

    if (stack_ptr == NULL)
    {
        return NULL;
    }

    return stack_ptr;
}

void push(Stack *stack_ptr, int value)
{
}

int pop(Stack *stack_ptr)
{
    return 0;
}

int isEmpty(Stack *stack_ptr)
{
    return 0;
}

int isFull(Stack *stack_ptr)
{
    return 0;
}

int peek(Stack *stack_ptr)
{
    return 0;
}
