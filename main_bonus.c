#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *get_next_line(int fd);

int main(void)
{
    int fd1;
    int fd2;
    char *line1;
    char *line2;

    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_RDONLY);

    if (fd1 < 0 || fd2 < 0)
        return (1);

    // Alternate reading between the two files
    line1 = get_next_line(fd1);
    printf("fd1: %s\n", line1);
    free(line1);

    line2 = get_next_line(fd2);
    printf("fd2: %s\n", line2);
    free(line2);

    line1 = get_next_line(fd1);
    printf("fd1: %s\n", line1);
    free(line1);

    line2 = get_next_line(fd2);
    printf("fd2: %s\n", line2);
    free(line2);

    line1 = get_next_line(fd1);
    printf("fd1: %s\n", line1);
    free(line1);

    line2 = get_next_line(fd2);
    printf("fd2: %s\n", line2);
    free(line2);

    close(fd1);
    close(fd2);
    return (0);
}