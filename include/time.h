#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <errno.h>

struct timespec {
    long tv_sec;
    long tv_nsec;
};

int nanosleep(const struct timespec *req, struct timespec *rem);
int sleep(int seconds);
