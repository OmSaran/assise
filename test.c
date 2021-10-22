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
    char buf[] = "Hello world!\n";

    if(remove(FILE_NAME) == 0) {
        printf("Deleted file successfully!\n");
    } else {
        printf("Deletion of file unsuccessful, probably does not exist!\b");
    }

    fd = open(FILE_NAME, O_CREAT | O_RDWR, 0644);
    ret = write(fd, buf, strlen(buf));
    assert(ret == strlen(buf));

    close(fd);
}
