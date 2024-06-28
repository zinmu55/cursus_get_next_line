/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_getc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohtake <skohtake@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 09:22:25 by skohtake          #+#    #+#             */
/*   Updated: 2024/06/28 13:52:14 by skohtake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tmp.h"

int	my_putc(t_string *str, char c)
{
	if (str->len + 1 > str->capa)
	{
	}
	str->str[str->len] = c;
	str->len++;
	return (0);
}

int	my_getc(int fd)
{
	static char	buf[BUFFER_SIZE]; // static char	buf[BUFSIZ];
	static char	*bufp;
	static int	i = 0;

	if (i == 0)
	{
		i = read(fd, buf, sizeof buf); // sizeof buf = 42byte
		//	read fd to memorize from buf for sizeof buf byte
		bufp = buf; //	bufp is the head of buf area
	}
	if (--i >= 0)
	{
		return ((unsigned char)*bufp++);
	}
	else
	{
		return (EOF);
	}
}

char	*gnl_practice(int fd)
{
	t_string	ret;
	char		c;

	ret.str = NULL;
	ret.len = 0;
	ret.capa = 0;
	while (1)
	{
		c = my_getc(fd);
		if (c == EOF)
		{
			break ;
		}
		my_putc(&ret, c);
		if (c == '\n')
		{
			break ;
		}
	}
	if (ret.len > 0)
	{
		my_putc(&ret, '\0');
	}
	return (ret.str);
}

////////////
////main////
////////////

int	main(void)
{
	int		fd;
	char	c1;
	char	c2;

	fd = open("./tmp.txt", O_RDONLY);
	c1 = my_getc(fd);
	c2 = my_getc(fd);
	close(fd);
	printf("my_getc returns\n");
	printf("c1: >>> int:%d, char:%c\n", c1, c1);
	printf("c2: >>> int:%d, char:%c\n", c2, c2);
	return (0);
}
