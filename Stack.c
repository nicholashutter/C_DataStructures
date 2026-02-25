/*
return codes:
0 = success
1 = failure
*/

#include <stdlib.h>
#include "Stack.h"
#include "ErrorCode.h"
#include "Optional.h"

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

    stack_ptr->top = -1;

    if (stack_ptr == NULL)
    {
        return NULL;
    }

    return stack_ptr;
}

ErrorCode push(Stack *stack_ptr, int value)
{
    stack_ptr->stack[stack_ptr->top] = value;

    ErrorCode returnCode = SUCCESS;

    if (stack_ptr == NULL)
    {
        returnCode = FAILURE;
    }
    else if (stack_ptr->top <= stack_ptr->maxSize)
    {
        stack_ptr->top++;
    }
    else
    {
        returnCode = FAILURE;
    }

    return returnCode;
}

Optional pop(Stack *stack_ptr)
{
    ErrorCode returnCode = SUCCESS;

    int popped = 0;

    if (stack_ptr == NULL)
    {
        returnCode = FAILURE;
    }

    else if (stack_ptr->top < 0)
    {
        returnCode = FAILURE;
    }
    else
    {
        popped = stack_ptr->stack[stack_ptr->top];

        stack_ptr->top--;
    }

    return new_optional(popped, returnCode);
}

ErrorCode isEmpty(Stack *stack_ptr)
{
    ErrorCode returnCode = FALSE;

    if (stack_ptr == NULL)
    {
        returnCode = FAILURE;
    }
    else if (stack_ptr->top == -1)
    {
        returnCode = TRUE;
    }

    return returnCode;
}

ErrorCode isFull(Stack *stack_ptr)
{
    ErrorCode returnCode = TRUE;

    if (stack_ptr == NULL)
    {
        returnCode = TRUE;
    }

    else if (stack_ptr->top == stack_ptr->maxSize)
    {
        returnCode = FALSE;
    }

    return returnCode;
}

Optional peek(Stack *stack_ptr)
{
    ErrorCode returnCode = SUCCESS;
    int returnValue = 0;

    if (stack_ptr == NULL)
    {
        returnCode = FAILURE;
    }
    else
    {
        returnValue = stack_ptr->stack[stack_ptr->top];
    }

    return new_optional(returnValue, returnCode);
}
