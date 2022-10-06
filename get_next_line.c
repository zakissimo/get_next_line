/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhabri <zhabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:47:44 by zhabri            #+#    #+#             */
/*   Updated: 2022/10/06 22:16:31 by zhabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	nl_in_str(const char *str)
{
	while (*str)
		if (*str++ == '\n')
			return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	while (str[i])
		i++;
	return (i);
}

char	*ft_rejoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*out;

	out = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	while (s1[i])
	{
		out[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		out[i++] = s2[j++];
	out[i] = '\0';
	free(s1);
	return (out);
}

char	*init_stash(char *buf)
{
	int		i;
	char	*out;

	i = -1;
	out = malloc(ft_strlen(buf) + 1);
	while (buf[++i])
		out[i] = buf[i];
	out[i] = '\0';
	return (out);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*out;
	char		buf[BUFFER_SIZE];

	while (read(1, buf, BUFFER_SIZE))
	{
		if (!stash)
			stash = init_stash(buf);
		else
			stash = ft_rejoin(stash, buf);
		while (nl_in_str(stash))
			//Find index of nl / split to out = substr to return / stash the rest of the string
	}
	return (out);
}
