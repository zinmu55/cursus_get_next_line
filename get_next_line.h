/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohtake <skohtake@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:39:30 by skohtake          #+#    #+#             */
/*   Updated: 2025/04/12 15:30:58 by skohtake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_string
{
	char	*str;
	size_t	len;
	size_t	capa;
}			t_string;

//	get_next_line.c

char		*get_next_line(int fd);
char		my_getc(int fd);
int			my_putc(t_string *str, char c);
void		*my_memcpy(void *dst, const void *src, size_t n);

// get_next_line_utils.c

// must comment out below

# define BUFFER_SIZE 42

// must comment out upon

#endif

/////////////////////////////////////////////////////////////////////

// #ifndef GET_NEXT_LINE_H
// # define GET_NEXT_LINE_H

// # include <fcntl.h>
// # include <stdlib.h>
// # include <unistd.h>
// # include <stdio.h>

// //	get_next_line.c
// char	*get_next_line(int fd);
// char    ft_get(int fd);

// // get_next_line_utils.c

// #endif