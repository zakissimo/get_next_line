/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhabri <zhabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:47:44 by zhabri            #+#    #+#             */
/*   Updated: 2022/10/10 19:54:18 by zhabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_out(char **stash, int ret)
{
	char		*out;
	char		**tab;

	if ((!ret && nl_in_str(*stash) == -1)
		|| (nl_in_str(*stash) == ft_strlen(*stash)))
	{
		out = ft_strdup(*stash);
		*stash = NULL;
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
	static char	*stash[1024] = {NULL};
	int			ret;
	char		*buf;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, (void *)0, 0) == -1)
		return (NULL);
	ret = 1;
	while (ret && nl_in_str(stash[fd]) == -1)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		ret = read(fd, buf, BUFFER_SIZE);
		if ((!ret && !stash[fd]) || ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		stash[fd] = ft_rejoin(stash[fd], buf);
	}
	return (get_out(&stash[fd], ret));
}