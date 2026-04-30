/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakhatoo <nakhatoo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/07 18:52:18 by nakhatoo      #+#    #+#                 */
/*   Updated: 2026/04/10 14:04:12 by nakhatoo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

char	*gnl_strchr(const char *s, int c);
size_t	gnl_strlen(const char *s);
char	*gnl_strjoin(const char	*s1, const char	*s2);
char	*gnl_substr(const char *s, unsigned int start, size_t len);

#endif