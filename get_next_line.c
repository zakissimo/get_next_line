/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhabri <zhabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:47:44 by zhabri            #+#    #+#             */
/*   Updated: 2022/10/06 10:22:25 by zhabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	nl_in_str(const char *str)
{
	while (*str)
		if (*str++ == '\n')
			return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*out;
	char		buf[BUFFER_SIZE];

	while (read(1, buf, BUFFER_SIZE))
	{
	}
	return (out);
}
