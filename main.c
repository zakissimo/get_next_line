/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhabri <zhabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 08:55:19 by zhabri            #+#    #+#             */
/*   Updated: 2022/10/07 09:42:27 by zhabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char buf[] = "1234";
	char buf1[] = "";
	char *stash;
	t_node *node;

	stash = init_stash(buf);
	stash = ft_rejoin(stash, buf1);
	node = split_to_node(nl_in_str(stash), stash);
	printf("%s", node->out);
	printf("%s", node->stash);
	free_node(node);
	// free(stash);
	return (0);
}
