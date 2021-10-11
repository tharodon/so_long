/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharodon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 22:10:11 by tharodon          #+#    #+#             */
/*   Updated: 2021/08/03 22:10:13 by tharodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static	int	max_score(char **argv)
{
	int	str;
	int	i;
	int	score;

	str = -1;
	score = 0;
	while (argv[++str])
	{
		i = -1;
		while (argv[str][++i])
			if (argv[str][i] == 'C')
				score++;
	}
	return (score);
}

static void	read_and_recording_map(char **ar, t_data *img, int *strings, int i)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(ar[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		(*strings)++;
		free(line);
	}
	free(line);
	close(fd);
	fd = open(ar[1], O_RDONLY);
	img->argv = (char **)malloc((*strings) * sizeof(char *) + 1);
	img->argv[(*strings)] = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		img->argv[i++] = ft_strdup(line);
		free(line);
	}
	img->argv[i] = ft_strdup(line);
	free(line);
}

static int	check_args(char **argv)
{
	int	i;

	i = 0;
	if (argv[1][i] == '.' && argv[1][i + 1] == '/')
		while (argv[1][i] && argv[1][i] != '.')
			i++;
	while (argv[1][i] && argv[1][i] != '.')
		i++;
	if (argv[1][i] == '.' && argv[1][i + 1] == 'b' && \
	argv[1][i + 2] == 'e' && argv[1][i + 3] == 'r')
		return (1);
	return (0);
}

int	main(int argc, char **ar)
{
	int		i;
	int		strings;
	t_data	img;

	i = 0;
	strings = 1;
	if (argc < 2 || !check_args(ar))
	{
		printf("Error\n");
		return (0);
	}
	img.collect_score = 0;
	img.steps = 0;
	img.argv = NULL;
	read_and_recording_map(ar, &img, &strings, i);
	img.numb_items = max_score(img.argv);
	if (!valid_map(&img))
	{
		printf("Error\n");
		return (0);
	}
	struct_init(&img, strings);
	draw(&img);
	mlx_loop(img.mlx);
	return (0);
}
