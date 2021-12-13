#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

// #define FILE_NAME "/home/om/test_file.txt"
#define FILE_NAME "/mlfs/test_file.txt"

int main() {
    int ret;
    char buf[] = "YOLO world!\n";
    int child;
    int wstatus;
    int fd;


    if(remove(FILE_NAME) == 0) {
        printf("Deleted file successfully!\n");
    } else {
        printf("Deletion of file unsuccessful, probably does not exist!\n");
    }

    printf("Tring to open\n");
    fd = open(FILE_NAME, O_CREAT | O_RDWR, 0644);
    printf("Open completed\n");
    ret = write(fd, buf, strlen(buf));
    assert(ret == strlen(buf));

    close(fd);
}
