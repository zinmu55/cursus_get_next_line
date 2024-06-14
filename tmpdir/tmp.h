/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohtake <skohtake@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:05:33 by skohtake          #+#    #+#             */
/*   Updated: 2024/06/14 11:26:33 by skohtake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TMP_H
# define TMP_H

# include "../get_next_line.h"
# include <stdio.h>

typedef struct s_string
{
	char	*str;
	size_t	len;
	size_t	capa;
}			t_string;

int			my_getchar(int fd);
int			ft_putc(t_string *str, char c);
char		*get_next_line(int fd);

#endif