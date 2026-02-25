#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include "ErrorCode.h"
#include "Optional.h"

typedef struct Stack Stack;

//constructor
Stack *new_stack(size_t maxSize);
//add new element to top of stack
ErrorCode push(Stack *stack_ptr, int value);
//remove highest element from stack and return
Optional pop(Stack *stack_ptr);
//check if the stack is empty
ErrorCode isEmpty(Stack *stack_ptr);
//check if the stack is full
ErrorCode isFull(Stack *stack_ptr); 
//return a copy of the highest element
Optional peek(Stack *stack_ptr);

#endif