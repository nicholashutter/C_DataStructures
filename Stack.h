#ifndef STACK_H
#define STACK_H

#include <stddef.h>

typedef struct Stack Stack;

//constructor
Stack *new_stack(size_t maxSize);
//add new element to top of stack
void push(Stack *stack_ptr, int value);
//remove highest element from stack and return
int pop(Stack *stack_ptr);
//check if the stack is empty
int isEmpty(Stack *stack_ptr);
//check if the stack is full
int isFull(Stack *stack_ptr); 
//return a copy of the highest element
int peek(Stack *stack_ptr);

#endif