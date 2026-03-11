#include "../include/stack.h"
#include <stdio.h>

void print_values(Stack* s) {
    for (int i = 0; i < s->top; ++i)
    {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}
void push_value(Stack* s, int value) {
    if (s->top >= STACK_CAPACITY) {
        return; // we have exceeded stack capacity
    }
    s->data[s->top] = value;
    s->top++;
}
void pop_value(Stack* s) {
    if (s->top == 0) {
        return;
    }
    s->top--;
    s->data[s->top] = 0;
}
int peek_value(Stack* s, int index) {
    if (index < 0 || index >= s->top) {
        return 0;
    }
    return s->data[index];
}

bool peek_top(Stack* s, int* out) {
    if (s->top==0) {
        return false;
    }
    *out = s->data[s->top-1];
    return true;
}

bool is_empty(Stack* s) {
    return (s->top == 0);
}
bool is_full(Stack* s) {
    return (s->top == STACK_CAPACITY);
}


int main(void) {
    Stack s = {0};
    int top_value;

    printf("Initial stack: ");
    print_values(&s);
    printf("Empty? %s\n", is_empty(&s) ? "yes" : "no");

    push_value(&s, 10);
    push_value(&s, 20);
    push_value(&s, 30);

    printf("\nAfter pushing 10, 20, 30:\n");
    print_values(&s);

    if (peek_top(&s, &top_value)) {
        printf("Top value: %d\n", top_value);
    }

    printf("Value at index 0: %d\n", peek_value(&s, 0));
    printf("Value at index 1: %d\n", peek_value(&s, 1));
    printf("Value at index 2: %d\n", peek_value(&s, 2));

    pop_value(&s);
    printf("\nAfter one pop:\n");
    print_values(&s);

    if (peek_top(&s, &top_value)) {
        printf("Top value: %d\n", top_value);
    }

    printf("\nFilling stack with 99s:\n");
    while (!is_full(&s)) {
        push_value(&s, 99);
        print_values(&s);
    }

    printf("Full? %s\n", is_full(&s) ? "yes" : "no");

    printf("\nPopping everything:\n");
    while (!is_empty(&s)) {
        if (peek_top(&s, &top_value)) {
            printf("Top before pop: %d\n", top_value);
        }
        pop_value(&s);
        print_values(&s);
    }

    printf("Empty? %s\n", is_empty(&s) ? "yes" : "no");

    return 0;
}