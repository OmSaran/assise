#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

// #define FILE_NAME "/home/om/test_file.txt"
#define FILE_NAME "/mlfs/test_file.txt"

void main() {
    int fd;
    int ret;
    char buf[100];

    fd = open(FILE_NAME, O_RDONLY, 0644);
    ret = read(fd, buf, 5);
    assert(ret == 5);
    buf[ret] = '\0';

    printf("Read the following: %s\n", buf);

    close(fd);
}
