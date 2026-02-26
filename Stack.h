#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include "ErrorCode.h"

typedef struct Stack Stack;

// constructor
ErrorCode new_stack(size_t maxSize, Stack *returnValue);
// add new element to top of stack
ErrorCode push(Stack *self, int value);
// remove highest element from stack and return
ErrorCode pop(Stack *self, int *returnValue);
// check if the stack is empty
ErrorCode isEmpty(Stack *self);
// check if the stack is full
ErrorCode isFull(Stack *self);
// return a copy of the highest element
ErrorCode peek(Stack *self, int *returnValue);

#endif