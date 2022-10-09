/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhabri <zhabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 08:55:19 by zhabri            #+#    #+#             */
/*   Updated: 2022/10/09 18:32:23 by zhabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*kek;
	int		fd;
	int		i;

	i = 3;
	fd = open("gnlTester/files/nl", O_RDWR);
	while (i)
	{
		kek = get_next_line(fd);
		printf("%s", kek);
		free(kek);
		i--;
	}
	close(fd);
	return (0);
}
