/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhabri <zhabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:47:44 by zhabri            #+#    #+#             */
/*   Updated: 2022/10/07 17:26:09 by zhabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
	if (stash)
		free(stash);
	return (out);
}

char	**split_to_tab(char **tab, int nl_idx, char *stash)
{
	int		i;
	int		j;
	char	*out;
	char	*new_stash;

	i = 0;
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

char	*get_next_line(int fd)
{
	int			ret;
	static char	*stash;
	char		*out;
	char		**tab;
	char		buf[BUFFER_SIZE];

	if (fd <= 0 || fd >= 1000)
		return (NULL);
	out = NULL;
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret > 0)
	{
		if (!stash)
			stash = init_stash(buf);
		else
			stash = ft_rejoin(stash, buf);
		// printf("%s\n", stash);
		if (nl_in_str(stash) >= 0)
		{
			tab = malloc(sizeof(char *) * 3);
			tab = split_to_tab(tab, nl_in_str(stash), stash);
			stash = tab[0];
			out = tab[1];
			free(tab);
			return (out);
		}
		ret = read(fd, buf, BUFFER_SIZE);
		if (!ret)
			return (stash);
	}
	// free(stash);
	// free(out);
	return (NULL);
}
