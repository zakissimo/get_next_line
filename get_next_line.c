/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhabri <zhabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:47:44 by zhabri            #+#    #+#             */
/*   Updated: 2022/10/15 12:34:23 by zhabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_out(char **stash, int ret)
{
	char		*out;
	char		**tab;

	if ((!ret && nl_in_str(*stash) == -1)
		|| (nl_in_str(*stash) == ft_strlen(*stash)))
	{
		out = ft_strdup(*stash);
		return (out);
	}
	if (nl_in_str(*stash) != -1)
	{
		tab = malloc(sizeof(char *) * 2);
		if (!tab)
			return (NULL);
		tab = split_to_tab(tab, nl_in_str(*stash), *stash);
		*stash = tab[0];
		out = tab[1];
		free(tab);
		return (out);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	int			ret;
	char		*buf;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	ret = 1;
	while (ret && nl_in_str(stash) == -1)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		ret = read(fd, buf, BUFFER_SIZE);
		if ((!ret && !stash) || ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		stash = ft_rejoin(stash, buf);
	}
	return (get_out(&stash, ret));
}
