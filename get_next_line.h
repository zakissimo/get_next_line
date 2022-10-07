/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhabri <zhabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:27:00 by zhabri            #+#    #+#             */
/*   Updated: 2022/10/07 19:15:55 by zhabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_node
{
	char	*stash;
	char	*out;
}			t_node;

char		*get_next_line(int fd);
int			nl_in_str(const char *str);
int			ft_strlen(const char *str);
char		*init_stash(char *buf);
char		*ft_rejoin(char *stash,char *buf);
char		**split_to_tab(char **tab, int nl_idx, char *stash);
void		free_tab(char **tab);

#endif
