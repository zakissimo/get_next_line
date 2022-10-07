/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhabri <zhabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:47:44 by zhabri            #+#    #+#             */
/*   Updated: 2022/10/07 08:10:43 by zhabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_rejoin(char *stash, const char *buf)
{
	int		i;
	int		j;
	char	*out;

	out = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buf) + 1));
	i = -1;
	while (stash[++i])
		out[i] = stash[i];
	j = 0;
	while (buf[j])
		out[i++] = buf[j++];
	out[i] = '\0';
	free(stash);
	return (out);
}

t_node	*split_to_node(int nl_idx, char *stash)
{
	int		i;
	int		j;
	char	*out;
	t_node	*node;
	char	*new_stash;

	i = 0;
	node = malloc(sizeof(t_node));
	out = malloc((nl_idx + 2) * sizeof(char *));
	new_stash = malloc(ft_strlen(stash) - nl_idx);
	while (i < nl_idx + 1)
	{
		out[i] = stash[i];
		i++;
	}
	out[i] = '\0';
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	node->stash = new_stash;
	node->out = out;
	return (node);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	t_node		*node;
	char		*out;
	char		buf[BUFFER_SIZE];

	while (read(fd, buf, BUFFER_SIZE))
	{
		if (!stash)
			stash = init_stash(buf);
		else
			stash = ft_rejoin(stash, buf);
		while (nl_in_str(stash) > 0)
		{
			node = split_to_node(nl_in_str(stash), stash);
			out = node->out;
			stash = node->stash;
			return (out);
		}
	}
	while (nl_in_str(stash) > 0)
	{
		node = split_to_node(nl_in_str(stash), stash);
		out = node->out;
		stash = node->stash;
		return (out);
	}
	return (stash);
}
