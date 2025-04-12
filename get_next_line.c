/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohtake <skohtake@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:34:22 by skohtake          #+#    #+#             */
/*   Updated: 2025/04/12 15:15:40 by skohtake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q a.out");
// }

char	*get_next_line(int fd)
{
	char	*result;
	char	c;

	while (1)
	{
		c = ft_getc(fd);
		if (c == EOF)
			break ;
		ft_putc(&result, c);
		if (c == '\n')
			break ;
	}
	ft_putc(&result, c);
	return (result);
}

char	ft_get(int fd)
{
	static char	buff[BUFFER_SIZE];
	static char	*buffptr;
	static int	read_byte;
	char		c;

	if (read_byte == 0)
	{
		read_byte = read(fd, buff, BUFFER_SIZE);
		buffptr = buff;
	}
	read_byte--;
	if (read_byte >= 0)
	{
		c = *buffptr;
		buffptr++;
	}
	if (read_byte < 0)
	{
		c = EOF;
	}
	return (c);
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
	printf("gnl returns	:%s\n", get_next_line(fd));
	printf("gnl returns	:%s\n", get_next_line(fd));
	close(fd);
	return (0);
}
