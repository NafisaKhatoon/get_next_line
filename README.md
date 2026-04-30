*This project has been created as part of the 42 curriculum by nakhatoo.*

# Get Next Line
## Description

The goal of this project is to implement a function **get_next_line** that reads and returns a line from a file descriptor, one at a time. This function allows sequential reading of a file or input stream without loading the entire content into memory.

Each call to **get_next_line(int fd)** returns the next line from the given file descriptor, including the terminating newline character **(\n)** if present. When the end of the file is reached or an error occurs, the function returns **NULL**.

This project introduces static variables, buffer management, and efficient memory handling, which are essential concepts in low-level programming.

## Instructions
### Compilation

You can compile the project using:

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c

or for bonus part:

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils.c


**Usage Example**

## For mandatory part:-

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *get_next_line(int fd);

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        printf("Error opening file\n");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("LINE: %s", line);
        free(line);
    }
	close(fd);
    return (0);
}

## For bonus part:-

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
    printf("fd1: %s", line1);
    free(line1);

    line2 = get_next_line(fd2);
    printf("fd2: %s", line2);
    free(line2);

    close(fd1);
    close(fd2);
    return (0);
}


## Algorithm Explanation

The implementation is based on reading chunks of data from a file descriptor and storing them until a full line can be extracted.

### Key Concepts

- **Static variable**

A static buffer is used to retain leftover data between function calls. This allows the function to continue reading from where it previously stopped.

- **Buffered reading**

The **read()** function is used repeatedly to append data into a temporary buffer until a newline **(\n)** is found or **EOF** is reached.

- **Line extraction**

Once a newline is detected, the function:
 - Extracts the line to return
 - Stores the remaining data for the next call

### Step-by-step logic

1. Read from file descriptor into a buffer of size **BUFFER_SIZE**
2. Append read content to a static storage string
3. Check if a newline exists in the storage
4. If yes:
  - Extract the line (including \n)
  - Save the remaining part for the next call
5. If no newline but EOF reached:
  - Return remaining content
6. If nothing left:
  - Return NULL

### Why this approach?

- Minimizes unnecessary reads
- Handles arbitrary line lengths
- Works efficiently with small or large buffer sizes
- Ensures continuity across multiple function calls

## Resources

- Manual pages: man read, man open, man free
- https://www.geeksforgeeks.org/c/c-programming-language/
- https://www.w3schools.com/c/
- https://youtu.be/8E9siq7apUU?si=0jgSCK1MeztoIO7t/
- 42 subject PDF and intra materials

### AI Usage

AI tools were used for:

- Understanding buffer management strategies
- Clarifying edge cases (EOF, no newline, multiple file descriptors)

All code implementation and logic decisions were written and validated manually.

