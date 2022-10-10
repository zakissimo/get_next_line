/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhabri <zhabri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:27:00 by zhabri            #+#    #+#             */
/*   Updated: 2022/10/10 14:40:14 by zhabri           ###   ########.fr       */
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
int			nl_in_str(char *str);
int			ft_strlen(char *str);
char		*ft_strdup(char *buf);
char		*ft_rejoin(char *stash, char *buf);
char		**split_to_tab(char **tab, int nl_idx, char *stash);
char		*ft_rejoin(char *stash, char *buf);

#endif
