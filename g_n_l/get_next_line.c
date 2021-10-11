/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharodon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:06:37 by tharodon          #+#    #+#             */
/*   Updated: 2021/08/03 17:06:38 by tharodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	dest_in_line(char **dest, char ***line)
{
	char	*temp;
	char	*dest_twin;

	dest_twin = *dest;
	temp = ft_strchr(*dest, '\n');
	if (temp)
	{
		*temp = '\0';
		**line = ft_strdup(*dest);
		*dest = ft_strdup(temp + 1);
		free(dest_twin);
		return (1);
	}
	else
	{
		**line = ft_strdup(*dest);
		free(*dest);
		*dest = NULL;
		return (0);
	}
}

int	buff_in_line(char **buff, char **dest, char ***line)
{
	char	*line_twin2;
	char	*temp;

	line_twin2 = **line;
	temp = ft_strchr(*buff, '\n');
	if (temp == NULL)
	{
		**line = ft_strjoin(**line, *buff);
		free(line_twin2);
		return (0);
	}
	else
	{
		*temp = '\0';
		**line = ft_strjoin(**line, *buff);
		free(line_twin2);
		*dest = ft_strdup(++temp);
		free(*buff);
		return (1);
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*dest;
	char		*buff;
	int			reader;

	if (!line || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (-1);
	reader = 1;
	if (dest != NULL)
	{
		if (dest_in_line(&dest, &line))
			return (1);
	}
	else
		*line = ft_strdup("");
	buff = (char *)malloc(BUFFER_SIZE + 1);
	while (reader != 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		buff[reader] = '\0';
		if (buff_in_line(&buff, &dest, &line))
			return (1);
	}
	free(buff);
	return (0);
}
