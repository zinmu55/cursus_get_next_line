/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohtake <skohtake@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:34:22 by skohtake          #+#    #+#             */
/*   Updated: 2025/01/19 13:21:43 by skohtake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

__attribute__((destructor)) static void destructor()
{
	system("leaks -q a.out");
}

char	*get_next_line(int fd)
{
	char *result;
	char c;


	while(1)
	{
		char c = ft_getc(fd);
		if (c == EOF)
			break;
		ft_putc(&result, c);
		if (c == '\n')
			break;
	}
	ft_putc(&result, c);
	return(result);
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

