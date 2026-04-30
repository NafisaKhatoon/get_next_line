/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakhatoo <nakhatoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/14 19:09:32 by nakhatoo      #+#    #+#                 */
/*   Updated: 2026/04/15 17:52:53 by nakhatoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <fcntl.h>
// #include <unistd.h>

// char	*get_next_line(int fd);

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("file2.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf("Error opening file\n");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("NEWLINE: %s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <fcntl.h>

// char	*get_next_line(int fd);

// int main(void)
// {

// int		fd;
// char	*line;

// fd = open("file1.txt", O_RDONLY);
// if (fd < 0)
// {
// 	printf("Error");
// 	return (1);
// }
// while ((line = get_next_line(fd)) != NULL)
// {
// 	printf("NEWLINE: %s", line);
// 	free(line);
// }
// close(fd);
// return (0);
// }





#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd);

int main(void)
{
	int		fd;
	char	*line;

	fd = open ("file1.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Newline: %s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}