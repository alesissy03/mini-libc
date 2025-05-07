#include <stdio.h>
#include <time.h>

int sleep(int seconds) {
    struct timespec req = {seconds, 0};
    struct timespec rem = {0, 0};
    while (nanosleep(&req, &rem) == -1) {
        req = rem;
    }
    return rem.tv_sec;
}
