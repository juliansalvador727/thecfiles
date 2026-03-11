#pragma once

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    const char* data;
    size_t length;
} String;

size_t str_len(const String *str);
int str_compare(const String *str1, const String *str2);
bool str_find_char(const String *str, char ch, size_t* index_out);
size_t str_count_char(const String *str, char ch);