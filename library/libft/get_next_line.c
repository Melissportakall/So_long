/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mportaka <mportaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:13:23 by mportaka          #+#    #+#             */
/*   Updated: 2024/02/24 14:13:25 by mportaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static char	*ft_copy_to_stash(char *stash, char *buffer)
{
	char	*res;

	res = 0;
	if (!stash && buffer)
	{
		res = ft_strdup(buffer);
		if (!res)
			return (NULL);
		return (res);
	}
	res = ft_strjoin(stash, buffer);
	ft_free_stash(&stash, 0);
	return (res);
}

static int	ft_have_nl(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i] != '\0')
		if (s[i] == '\n')
			return (1);
	return (0);
}

static char	*ft_extract_line(char *stash)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	j = 0;
	while (j <= i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*ft_recreate_stash(char *stash)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] != '\n')
		i++;
	if (stash[i + 1] == '\0')
		return (ft_free_stash(&stash, 0));
	res = ft_substr(stash, i + 1, ft_strlen(stash));
	if (!res)
	{
		ft_free_stash(&stash, 0);
		return (NULL);
	}
	ft_free_stash(&stash, 0);
	return (res);
}

char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE + 1];
	long			rd_bytes;
	static char		*stash = NULL;
	char			*line;

	line = 0;
	rd_bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free_stash(&stash, 0));
	while (rd_bytes > 0)
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if ((rd_bytes <= 0 && !stash) || rd_bytes == -1)
			return (ft_free_stash(&stash, 0));
		buffer[rd_bytes] = '\0';
		stash = ft_copy_to_stash(stash, buffer);
		if (ft_have_nl(stash))
		{
			line = ft_extract_line(stash);
			if (!line)
				ft_free_stash(&stash, 0);
			return (stash = ft_recreate_stash(stash), line);
		}
	}
	return (ft_free_stash(&stash, 1));
}
