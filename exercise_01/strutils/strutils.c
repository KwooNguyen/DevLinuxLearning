#include "strutils.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>

void str_reverse (char *str)
{
    /* Check if String is NULL */
    if (NULL == str || '\0' == *str)
    {
        printf("String is NULL\n");
        return;
    }

    size_t left = 0;
    size_t right = strlen(str) - 1;

    while (left < right)
    {
        char temp = str[left];
        str[left++] = str[right];
        str[right--] = temp;
    }
}

void str_trim (char *str)
{
    /* Check if String is NULL */
    if (NULL == str || '\0' == *str)
    {
        printf("String is NULL\n");
        return;
    }

    // Trim leading spaces
    char *start = str;
    while (isspace((unsigned char)*start)) {
        start++;
    }

    // Trim trailing spaces
    char *end = start + strlen(start) - 1;
    while (end > start && isspace((unsigned char)*end)) {
        *end = '\0';
        end--;
    }

    // Move trimmed string to the original buffer
    if (start != str) {
        memmove(str, start, strlen(start) + 1); // include null-terminator
    }
}

int str_to_int (const char *str, int *out_num)
{
    /* Check if String is NULL */
    if (NULL == str || '\0' == *str)
    {
        printf("String is NULL\n");
        return 0;
    }

    char *endptr;
    long val = strtol(str, &endptr, 10);

    /* Check if invalid character */
    if (*endptr != '\0') return 0;

    /* Check if value is out of range */
    if (val < INT_MIN || val > INT_MAX) return 0;

    *out_num = (int)val;

    return 1;
}
