/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohtake <skohtake@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:39:30 by skohtake          #+#    #+#             */
/*   Updated: 2025/05/18 13:40:34 by skohtake         ###   ########.fr       */
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
	// size_t	capa;
}			t_string;

//	get_next_line.c

char		*my_save(char *save);
char		*my_get_line(char *save);
char		*my_read(int fd, char *save);
char		*get_next_line(int fd);

// get_next_line_utils.c

size_t		my_strlen(const char *s);
char		*my_strchr(const char *s, int c);
char		*my_initialize(char *s1);
char		*my_strjoin(char *s1, char *s2);

// // you must comment out below

// # define BUFFER_SIZE 2

// // you must comment out upon

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