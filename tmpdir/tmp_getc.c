/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_getc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohtake <skohtake@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 09:22:25 by skohtake          #+#    #+#             */
/*   Updated: 2024/06/14 09:22:26 by skohtake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

int	getchar(void)
{
	static char	buf[BUFSIZ];
	static char	*bufp;
	static int	n = 0;

	if (n == 0)
	{
		n == read(0, buf, sizeof buf);
		bufp = buf;
	}
	return ((--n >= 0) ? (unsigned char)*bufp++ : EOF);
}
