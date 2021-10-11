/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharodon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 22:22:38 by tharodon          #+#    #+#             */
/*   Updated: 2021/08/03 22:22:40 by tharodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	null_end_str(char **argv)
{
	int	str;
	int	i;

	str = -1;
	i = ft_strlen(argv[0]) - 1;
	while (argv[++str])
		if (argv[str][i] != '1')
			return (0);
	return (1);
}

static	int	util_valid_size(char **argv)
{
	int	i;
	int	p;
	int	str;

	i = -1;
	while (argv[++i])
	{
		p = i + 1;
		str = ft_strlen(argv[i]);
		while (argv[p])
		{
			if (str != ft_strlen(argv[p]))
				return (0);
			p++;
		}
	}
	return (null_end_str(argv));
}

int	valid_size(char **argv)
{
	int	str;
	int	i;

	i = -1;
	str = 0;
	while (argv[0][++i])
		if (argv[0][i] != '1')
			return (0);
	i = -1;
	while (argv[++i])
		if (argv[i][0] != '1')
			return (0);
	while (argv[i - 1][str])
	{
		if (argv[i - 1][str] != '1')
			return (0);
		str++;
	}
	return (util_valid_size(argv));
}

static int	util_valid_map(t_data *img, int *start, int *exit)
{
	int	str;
	int	i;

	str = -1;
	while (img->argv[++str])
	{
		i = -1;
		while (img->argv[str][++i])
		{
			if (img->argv[str][i] == 'P')
				(*start)++;
			if (img->argv[str][i] == 'E')
				(*exit)++;
			if (img->argv[str][i] != '1' && img->argv[str][i] != '0' && \
			img->argv[str][i] != 'P' && img->argv[str][i] != 'C' && \
			img->argv[str][i] != 'V' && img->argv[str][i] != 'E')
				return (0);
		}
	}
	return (1);
}

int	valid_map_bonus(t_data *img)
{
	int	start;
	int	exit;

	start = 0;
	exit = 0;
	if (img->numb_items == 0)
		return (0);
	if (!util_valid_map(img, &start, &exit) || \
	start != 1 || exit != 1 || !valid_size(img->argv))
		return (0);
	return (1);
}
