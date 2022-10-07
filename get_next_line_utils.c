/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhabri <zhabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:47:55 by zhabri            #+#    #+#             */
/*   Updated: 2022/10/07 08:10:23 by zhabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	nl_in_str(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++] == '\n')
			return (i);
	return (-1);
}

int	ft_strlen(const char *str)
{
	int	i;

	while (str[i])
		i++;
	return (i);
}

char	*init_stash(const char *buf)
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
