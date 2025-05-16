/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohtake <skohtake@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:34:22 by skohtake          #+#    #+#             */
/*   Updated: 2025/05/11 15:48:19 by skohtake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*my_save(char *save)
{
	int		i;
	int		j;
	char	*new_save;

	if (!save || !*save)
		return (NULL);
	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if ((!save[i]))
		// return (free(save), NULL);
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	new_save = (char *)malloc(sizeof(char) * (my_strlen(save) - i + 1));
	if (!new_save)
		// return (free(save), NULL);
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	i++;
	while (save[i])
		new_save[j++] = save[i++];
	new_save[j] = '\0';
	free(save);
	return (new_save);
}

char	*my_get_line(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] != '\n' && save[i])
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if(!line)
		return(NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*my_read(int fd, char *save)
{
	char	*tmp;
	char	*new_save;
	int		readbyte;

	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (tmp == NULL)
		return (NULL);
	readbyte = 1;
	while (!my_strchr(save, '\n') && readbyte != 0)
	{
		readbyte = read(fd, tmp, BUFFER_SIZE);
		if (readbyte == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[readbyte] = '\0';
		new_save = my_strjoin(save, tmp);
		save = new_save;
	}
	free(tmp);
	return (save);
}

char	*get_next_line(int fd) //ラインをリターンする
{
	char *line;
	static char *save;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	save = my_read(fd, save);
	if (save == NULL)
		return (NULL);
	if (*save == 0)
	{
		free(save);
		save = NULL;
		line = NULL;
		return (NULL);
	}
	line = my_get_line(save);
	save = my_save(save);
	if (save != NULL && *save == 0)
	{
		free(save);
		save = NULL;
	}
	return (line);
}

////////////
////main////
////////////

// Mandatory
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("./example.txt", O_RDONLY);
	line = "";
	if (fd == -1)
	{
		fprintf(stdout, "file open error.");
		return (1);
	}
	while (line)
	{
		line = get_next_line(fd);
		printf(">%s", line);
		free(line);
	}
	return (0);
}
