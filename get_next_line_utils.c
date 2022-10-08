/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhabri <zhabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:47:55 by zhabri            #+#    #+#             */
/*   Updated: 2022/10/08 09:38:11 by zhabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	nl_in_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++] == '\n')
			return (i);
	return (-42);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
