/*
return codes:
0 = success
1 = failure
*/

#include <stdlib.h>
#include "Stack.h"
#include "ErrorCode.h"

struct Stack
{

    int top;
    int maxSize;
    int *stack;
};

ErrorCode new_stack(size_t maxSize, Stack *returnValue)
{

    Stack *stack_ptr = malloc(sizeof(Stack));

    stack_ptr->stack = malloc(maxSize * sizeof(int));

    stack_ptr->maxSize = maxSize;

    stack_ptr->top = -1;

    returnValue = stack_ptr;
}

ErrorCode push(Stack *self, int value)
{
    self->stack[self->top] = value;

    ErrorCode returnCode = SUCCESS;

    if (self == NULL)
    {
        returnCode = FAILURE;
    }
    else if (self->top <= self->maxSize)
    {
        self->top++;
    }
    else
    {
        returnCode = FAILURE;
    }

    return returnCode;
}

ErrorCode pop(Stack *self, int *returnValue)
{
    ErrorCode returnCode = SUCCESS;

    if (self == NULL)
    {
        returnCode = FAILURE;
    }

    else if (self->top < 0)
    {
        returnCode = FAILURE;
    }
    else
    {
        *returnValue = self->stack[self->top];

        self->top--;
    }

    return returnCode;
}

ErrorCode isEmpty(Stack *self)
{
    ErrorCode returnCode = FALSE;

    if (self == NULL)
    {
        returnCode = FAILURE;
    }
    else if (self->top == -1)
    {
        returnCode = TRUE;
    }

    return returnCode;
}

ErrorCode isFull(Stack *self)
{
    ErrorCode returnCode = TRUE;

    if (self == NULL)
    {
        returnCode = TRUE;
    }

    else if (self->top == self->maxSize)
    {
        returnCode = FALSE;
    }

    return returnCode;
}

ErrorCode peek(Stack *self, int *returnValue)
{
    ErrorCode returnCode = SUCCESS;

    if (self == NULL)
    {
        returnCode = FAILURE;
    }
    else
    {
        *returnValue = self->stack[self->top];
    }

    return returnCode;
}
