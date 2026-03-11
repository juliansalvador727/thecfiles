#pragma once

#include <stdint.h>
#include <stdbool.h>

#define STACK_CAPACITY 10

typedef struct {
    int data[STACK_CAPACITY];
    int top;
} Stack;


void push_value(Stack* s, int value);
void pop_value(Stack* s);
int peek_value(Stack* s, int index);
bool peek_top(Stack* s, int* out);

bool is_empty(Stack* s);
bool is_full(Stack* s);