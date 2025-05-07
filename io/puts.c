#include <stdio.h>
#include <unistd.h>
#include <string.h>

void puts(char *str) {
    size_t i;
    for (i = 0; i < strlen(str); i++) {
        write(1, (str + i), 1);
    }
    write(1, "\n", 1);
}
