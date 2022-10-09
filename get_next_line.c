/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhabri <zhabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:47:44 by zhabri            #+#    #+#             */
/*   Updated: 2022/10/09 22:18:52 by zhabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	int			ret;
	char		*buf;
	char		**tab;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, (void *)0, 0) == -1)
		return (NULL);
	ret = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (ret && nl_in_str(stash) == -1)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		if ((!ret && !stash) || ret == -1)
		{
			free(buf);
			return (NULL);
		}
		stash = ft_rejoin(stash, buf);
	}
	if (nl_in_str(stash) == ft_strlen(stash))
		return (stash);
	else
	{
		tab = malloc(sizeof(char *) * 2);
		if (!tab)
			return (NULL);
		tab = split_to_tab(tab, nl_in_str(stash), stash);
		tab[0] = stash;
		return (tab[1]);
	}
	return (NULL);
}
