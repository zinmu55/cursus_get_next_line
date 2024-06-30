/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohtake <skohtake@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 09:22:25 by skohtake          #+#    #+#             */
/*   Updated: 2024/06/30 13:26:44 by skohtake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tmp.h"

void	*my_memcpy(void *dst, const void *src, size_t n)
{
	char	*res;
	char	*input;

	res = (char *)dst;
	input = (char *)src;
	if (src == NULL && dst == NULL)
		return (NULL);
	while (n--)
	{
		*res++ = *input++;
	}
	return (dst);
}

int	my_putc(t_string *res, char c)
{
	char	*new_str;

	new_str = (char *)malloc(sizeof(char) * (res->len + 1));
	if (new_str == NULL)
	{
		return (-1);
	}
	my_memcpy(new_str, res->str, res->len);
	new_str[res->len] = c;
	free(res->str);
	res->len++;
	res->str = new_str;
	return (0);
}

// int	my_putc(t_string *str, char c)
// {
// 	if (str->len + 1 > str->capa)
// 	{
// 	}
// 	str->str[str->len] = c;
// 	str->len++;
// 	return (0);
// }

int	my_getc(int fd)
{
	static char	buf[BUFFER_SIZE];
	static char	*buf_ptr;
	static int	pending_bytes = 0;
	char		res;

	if (pending_bytes == 0) // get string from txtfile.
	{
		pending_bytes = read(fd, buf, sizeof buf);
		//	sizeof buf = 42byte.
		//	read fd to memorize from buf for sizeof buf byte.
		buf_ptr = buf;
		//	buf_ptr is the head of buf area.
	}
	if (pending_bytes <= 0)
	{
		return (EOF);
	}
	else //	if (pending_bytes > 0)
	//	(IOW)	pending_bytes >= 1 >>> holding pending words
	{
		res = *buf_ptr;
		buf_ptr++;
		pending_bytes--;
		return (res);
	}
}

// int	my_getc(int fd)
// {
// 	static char	buf[BUFFER_SIZE]; // static char	buf[BUFSIZ];
// 	static char	*bufp;
// 	static int	i = 0;

// 	if (i == 0)
// 	{
// 		i = read(fd, buf, sizeof buf); // sizeof buf = 42byte
// 		//	read fd to memorize from buf for sizeof buf byte
// 		bufp = buf; //	bufp is the head of buf area
// 	}
// 	if (--i >= 0)
// 	{
// 		return ((unsigned char)*bufp++);
// 	}
// 	else
// 	{
// 		return (EOF);
// 	}
// }

char	*gnl_practice(int fd)
{
	t_string	res;
	char		c;

	res.str = NULL;
	res.len = 0;
	res.capa = 0;
	while (1)
	{
		c = my_getc(fd);
		if (c == EOF)
		{
			break ;
		}
		my_putc(&res, c);
		if (c == '\n')
		{
			break ;
		}
	}
	if (res.len > 0)
	{
		my_putc(&res, '\0');
	}
	return (res.str);
}

////////////
////main////
////////////

int	main(void)
{
	int	fd;

	// char	c1;
	// char	c2;
	// fd = open("./tmp.txt", O_RDONLY);
	// c1 = my_getc(fd);
	// c2 = my_getc(fd);
	// close(fd);
	// printf("my_getc returns\n");
	// printf("c1: >>> int:%d, char:%c\n", c1, c1);
	// printf("c2: >>> int:%d, char:%c\n", c2, c2);
	fd = open("./tmp.txt", O_RDONLY);
	printf("gnl returns	:%s\n", gnl_practice(fd));
	close(fd);
	return (0);
}

// #include "tmp.h"

// void	static_test(void)
// {
// 	static int	si = 10; //	static int	si;

// 	printf("si = %d\n", ++si);
// 	return ;
// }

// int	main(void)
// {
// 	static_test();
// 	static_test();
// 	static_test();
// }
