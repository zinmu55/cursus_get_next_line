/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohtake <skohtake@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:34:22 by skohtake          #+#    #+#             */
/*   Updated: 2024/06/13 13:07:05 by skohtake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

__attribute__((destructor)) static void destructor()
{
	system("leaks -q a.out");
}

char	*get_next_line(int fd)
{
	if (0)
	{
		return (NULL);
	}
}
