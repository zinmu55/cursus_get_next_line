/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_getc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohtake <skohtake@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 09:22:25 by skohtake          #+#    #+#             */
/*   Updated: 2024/06/14 12:00:46 by skohtake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tmp.h"

int	main(void)
{
	int		fd;
	char	c1;
	char	c2;

	fd = 0;
	c1 = my_getchar(fd);
	c2 = my_getchar(fd);
	printf("my_getchar returns\n");
	printf("c1: >>> int:%d, char:%c\n", c1, c1);
	printf("c2: >>> int:%d, char:%c\n", c2, c2);
	return (0);
}

int	my_getchar(int fd)
{
	static char	buf[BUFSIZ];
	static char	*bufp;
	static int	n = 0;

	if (n == 0)
	{
		n = read(fd, buf, sizeof buf);
		bufp = buf;
	}
	return ((--n >= 0) ? (unsigned char)*bufp++ : EOF);
}

int	my_putc(t_string *str, char c)
{
	if (str->len + 1 > str->capa)
	{
	}
	str->str[str->len] = c;
	str->len++;
	return (0);
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
		c = my_getchar(fd);
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
