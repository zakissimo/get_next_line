/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhabri <zhabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:47:44 by zhabri            #+#    #+#             */
/*   Updated: 2022/10/08 09:12:02 by zhabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_rejoin(char *stash, char *buf)
{
	int		i;
	int		j;
	char	*out;

	if (!stash)
		return (buf);
	out = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buf) + 1));
	i = -1;
	while (stash[++i])
		out[i] = stash[i];
	j = 0;
	while (buf[j])
		out[i++] = buf[j++];
	out[i] = '\0';
	free(stash);
	free(buf);
	return (out);
}

char	**split_to_tab(int nl_idx, char *stash)
{
	int		i;
	int		j;
	char	*out;
	char	**tab;
	char	*new_stash;

	i = 0;
	tab = malloc(sizeof(char *) * 3);
	out = malloc((nl_idx + 2) * sizeof(char *));
	if (ft_strlen(stash) - nl_idx)
		new_stash = malloc(ft_strlen(stash) - nl_idx + 1);
	while (i < nl_idx)
	{
		out[i] = stash[i];
		i++;
	}
	out[i] = '\0';
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	if (j)
		new_stash[j] = '\0';
	else
		new_stash = NULL;
	free(stash);
	tab[0] = new_stash;
	tab[1] = out;
	tab[2] = NULL;
	return (tab);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*arr;

	i = 0;
	arr = (unsigned char *)s;
	while (i < n)
		arr[i++] = '\0';
}

char	*get_next_line(int fd)
{
	int			ret;
	char		**tab;
	char		*buf;
	static char	*stash = NULL;

	ret = read(fd, (void *)0, 0);
	if (fd < 0 || ret < 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	ft_bzero(buf, (BUFFER_SIZE + 1));
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret)
	{
		stash = ft_rejoin(stash, buf);
		if (nl_in_str(stash) >= 0)
		{
			tab = split_to_tab(nl_in_str(stash), stash);
			stash = tab[0];
			buf = tab[1];
			free(tab);
			return (buf);
		}
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		ft_bzero(buf, (BUFFER_SIZE + 1));
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < BUFFER_SIZE)
		{
			free(buf);
			return (stash);
		}
	}
	free(buf);
	return (NULL);
}
