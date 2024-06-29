/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohtake <skohtake@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:05:33 by skohtake          #+#    #+#             */
/*   Updated: 2024/06/29 13:11:34 by skohtake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TMP_H
# define TMP_H

# include "../get_next_line.h"
# include <stdio.h>

# define BUFFER_SIZE 42

typedef struct s_string
{
	char	*str;
	size_t	len;
	size_t	capa;
}			t_string;

int			my_getc(int fd);
int			my_putc(t_string *str, char c);
char		*get_next_line(int fd);

#endif