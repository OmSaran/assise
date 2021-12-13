#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

#include <mlfs/mlfs_interface.h>

// #define FILE_NAME "/home/om/test_file.txt"
#define FILE_NAME "/mlfs/test_file.txt"

int main() {
    int ret;
    char buf[] = "YOLO world!\n";
    int child;
    int wstatus;

    child = fork();
    if(child != 0) {
        // Parent
        int fd;
        wait(&wstatus);
        if(wstatus != 0) {
            printf("Child process failed with status %d\n", wstatus);
            return wstatus;
        }
        printf("Trying to open some random file\n");
        fd = open("./random_file", O_CREAT | O_RDWR, 0644);
        assert(fd >=0);
        printf("Successfully opened random file\n");
        close(fd);
    }
    else {
        int fd;
        init_fs();
        // Child
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
        shutdown_fs();
    }
}
