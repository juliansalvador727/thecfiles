#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 8

typedef struct Rb {
    size_t size[CAPACITY];
    size_t top;
} Rb;

void rb_init(Rb* rb, size_t* top);
void rb_push(Rb* rb, size_t val);
bool rb_is_empty(Rb* rb);
bool rb_is_full(Rb* rb);

