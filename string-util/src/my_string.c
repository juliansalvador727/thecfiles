#include "../include/my_string.h"
#include <stdio.h>

size_t str_len(const String *str) {
    return str->length;
}
int str_compare(const String *str1, const String *str2) {
    if (str1 == NULL || str2 == NULL) {
        return 0;
    }
    size_t min_len = (str1->length < str2->length) ? str1->length : str2->length;

    for (size_t i = 0; i < min_len; ++i) {
        if (str1->data[i] != str2->data[i]) {
            return (unsigned char)str1->data[i] - (unsigned char)str2->data[i];
        }
    }
    if (str1->length == str2->length) {
        return 0;
    }
    return (str1->length > str2->length ? 1 : -1);
}
bool str_find_char(const String *str, char ch, size_t* index_out) {
    if (str->length == 0) {
        return false;
    }
    for (size_t i = 0; i < str->length; ++i) {
        if (str->data[i] == ch) {
            *index_out = i;
            return true;
        }
    }
    return false;
}
size_t str_count_char(const String *str, char ch) {
    if (str->length == 0) {
        return 0;
    }
    size_t k = 0;
    for (size_t i = 0; i < str->length; ++i) {
        if (str->data[i] == ch) {
            k++;
        }
    }
    return k;
}

int main(void) {
      String s1 = { "abc", 3 };
    String s2 = { "abd", 3 };
    String s3 = { "abc", 3 };
    String s4 = { "ab", 2 };
    String s5 = { "banana", 6 };
    String s6 = { "", 0 };

    printf("=== str_len ===\n");
    printf("len(\"%.*s\") = %zu\n", (int)s1.length, s1.data, str_len(&s1));
    printf("len(\"%.*s\") = %zu\n", (int)s5.length, s5.data, str_len(&s5));
    printf("len(\"%.*s\") = %zu\n", (int)s6.length, s6.data, str_len(&s6));

    printf("\n=== str_compare ===\n");
    printf("\"%.*s\" vs \"%.*s\" -> %d\n",
           (int)s1.length, s1.data,
           (int)s2.length, s2.data,
           str_compare(&s1, &s2));

    printf("\"%.*s\" vs \"%.*s\" -> %d\n",
           (int)s1.length, s1.data,
           (int)s3.length, s3.data,
           str_compare(&s1, &s3));

    printf("\"%.*s\" vs \"%.*s\" -> %d\n",
           (int)s1.length, s1.data,
           (int)s4.length, s4.data,
           str_compare(&s1, &s4));

    printf("\"%.*s\" vs \"%.*s\" -> %d\n",
           (int)s4.length, s4.data,
           (int)s1.length, s1.data,
           str_compare(&s4, &s1));

    printf("\n=== str_find_char ===\n");
    size_t index = 0;
    bool found = str_find_char(&s1, 'b', &index);
    if (found) {
        printf("'b' found in \"%.*s\" at index %zu\n",
               (int)s1.length, s1.data, index);
    } else {
        printf("'b' not found in \"%.*s\"\n", (int)s1.length, s1.data);
    }

    found = str_find_char(&s1, 'z', &index);
    if (found) {
        printf("'z' found in \"%.*s\" at index %zu\n",
               (int)s1.length, s1.data, index);
    } else {
        printf("'z' not found in \"%.*s\"\n", (int)s1.length, s1.data);
    }

    found = str_find_char(&s5, 'a', &index);
    if (found) {
        printf("'a' found in \"%.*s\" at index %zu\n",
               (int)s5.length, s5.data, index);
    } else {
        printf("'a' not found in \"%.*s\"\n", (int)s5.length, s5.data);
    }

    printf("\n=== str_count_char ===\n");
    printf("count('a' in \"%.*s\") = %zu\n",
           (int)s5.length, s5.data, str_count_char(&s5, 'a'));

    printf("count('n' in \"%.*s\") = %zu\n",
           (int)s5.length, s5.data, str_count_char(&s5, 'n'));

    printf("count('z' in \"%.*s\") = %zu\n",
           (int)s5.length, s5.data, str_count_char(&s5, 'z'));

    printf("count('x' in \"%.*s\") = %zu\n",
           (int)s6.length, s6.data, str_count_char(&s6, 'x'));

    return 0;
}