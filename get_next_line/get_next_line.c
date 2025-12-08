/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcordero <pcordero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:50:32 by pcordero          #+#    #+#             */
/*   Updated: 2025/12/08 11:47:02 by pcordero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_gnl_init(t_gnl *gnl)
{
	if (gnl->buffer == NULL && BUFFER_SIZE > 0)
	{
		gnl->buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		gnl->r_bytes = 0;
		gnl->idx = 0;
		gnl->start = 0;
	}
}

static void	ft_gnl_read(t_gnl *gnl, int fd)
{
	if (gnl->idx == gnl->r_bytes)
	{
		ft_memset(gnl->buffer, '\0', BUFFER_SIZE);
		gnl->r_bytes = read(fd, gnl->buffer, BUFFER_SIZE);
		gnl->idx = 0;
	}
}

static char	*ft_gnl_append(t_gnl *gnl, char **output)
{
	const ssize_t	gnl_s = (gnl->idx - gnl->start);
	char			*fullstr;

	if ((*output) == NULL)
		fullstr = ft_calloc(gnl_s + 1, sizeof(char));
	else
		fullstr = ft_calloc(ft_strlen(*output) + gnl_s + 1, sizeof(char));
	if (fullstr == NULL)
	{
		free((*output));
		(*output) = NULL;
		free((gnl->buffer));
		(*output) = NULL;
	}
	if ((*output) != NULL)
		ft_strlcat(fullstr, *output, ft_strlen(*output) + 1);
	if (gnl->buffer != NULL)
	{
		while (gnl->start < gnl->idx)
			fullstr[ft_strlen(fullstr)] = gnl->buffer[gnl->start++];
	}
	free(*output);
	*output = fullstr;
	return (*output);
}

static char	*ft_gnl_output(t_gnl *gnl, char **output, int *eol)
{
	if (gnl->r_bytes > 0)
	{
		gnl->start = gnl->idx;
		while (gnl->idx < gnl->r_bytes && gnl->buffer[gnl->idx] != '\n')
			gnl->idx++;
		if (gnl->buffer[gnl->idx] == '\n')
		{
			gnl->idx++;
			(*eol) = 1;
		}
		(*output) = ft_gnl_append(gnl, output);
	}
	return (*output);
}

char	*get_next_line(int fd)
{
	static t_gnl	gnl;
	char			*output;
	int				eol_found;

	if (fd > -1)
		ft_gnl_init(&gnl);
	output = NULL;
	eol_found = 0;
	while (eol_found == 0 && gnl.buffer != NULL)
	{
		ft_gnl_read(&gnl, fd);
		if (gnl.r_bytes < 1)
		{
			free(gnl.buffer);
			gnl.buffer = NULL;
		}
		if (gnl.r_bytes < 0 && output != NULL)
		{
			free(output);
			return (NULL);
		}
		output = ft_gnl_output(&gnl, &output, &eol_found);
	}
	return (output);
}
