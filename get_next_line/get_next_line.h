/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:50:28 by pcordero          #+#    #+#             */
/*   Updated: 2025/12/03 14:04:35 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 1

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_gnl_buffer
{
	char		*buffer;
	ssize_t		r_bytes;
	ssize_t		idx;
	ssize_t		start;
}	t_gnl;

// GNL
char	*get_next_line(int fd);

// UTILS
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
void	*ft_memset(void *dest, int ch, size_t count);
void	*ft_calloc(size_t num_mem_blocks, size_t size_mem_blocks);

#endif