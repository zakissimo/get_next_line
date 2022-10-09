/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhabri <zhabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:47:55 by zhabri            #+#    #+#             */
/*   Updated: 2022/10/09 21:35:37 by zhabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*init_stash(char *buf)
{
	int		i;
	char	*out;

	i = 0;
	out = malloc(ft_strlen(buf) + 1);
	while (buf[i])
	{
		out[i] = buf[i];
		i++;
	}
	out[i] = '\0';
	free(buf);
	return (out);
}

char	*ft_rejoin(char *stash, char *buf)
{
	int		i;
	int		j;
	char	*out;

	if (!stash)
		return (init_stash(buf));
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
	j = 0;
	tab = malloc(sizeof(char *) * 2);
	out = malloc((nl_idx + 2) * sizeof(char *));
	new_stash = malloc(ft_strlen(stash) - nl_idx + 1);
	while (i < nl_idx)
	{
		out[i] = stash[i];
		i++;
	}
	out[i] = '\0';
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	tab[0] = new_stash;
	tab[1] = out;
	return (tab);
}

int	nl_in_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
		if (str[i++] == '\n')
			return (i);
	return (-1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
