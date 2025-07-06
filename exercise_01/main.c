#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "./strutils/strutils.h"

void main(void)
{
    char str[100];
    int out_num;

    printf("Input the string: ");
    scanf("%s", str);

    /* Removes leading and trailing whitespace from a string. */
    str_trim(str);

    /* Reverses a string in-place. */
    str_reverse(str);

    /* Safely converts a string to an integer. */
    if (str_to_int(str, &out_num)) {
        printf("Output integer: %d\n", out_num);
    } else {
        printf("Conversion to integer failed.\n");
    }
}