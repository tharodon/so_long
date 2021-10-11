/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharodon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:44:37 by tharodon          #+#    #+#             */
/*   Updated: 2021/08/03 21:44:38 by tharodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	go_up_enemy(t_data *img, int h, int i)
{
	if (img->argv[h - 1][i] == 'P')
	{
		printf("You lose!\n");
		exit(0);
	}
	if (img->argv[h - 2][i] == '1')
		img->otskok++;
	if (!(img->argv[h - 2][i] != '0' && img->argv[h - 1][i - 1] != '0' && \
	img->argv[h - 1][i + 1] != '0'))
	{
		img->argv[h][i] = '0';
		img->argv[h - 1][i] = 'V';
	}
}

static void	go_left_enemy(t_data *img, int h, int i)
{
	img->enemy_l = img->enemy;
	if (img->argv[h][i - 1] == 'P')
	{
		printf("You lose!\n");
		exit(0);
	}
	if (img->argv[h][i - 2] == '1')
		img->otskok++;
	img->argv[h][i] = '0';
	img->argv[h][i - 1] = 'V';
}

static void	go_down_enemy(t_data *img, int h, int i)
{
	if (img->argv[h + 1][i] == 'P')
	{
		printf("You lose!\n");
		exit(0);
	}
	if (img->argv[h + 2][i] == '1')
		img->otskok++;
	if (!(img->argv[h + 2][i] != '0' && img->argv[h + 1][i - 1] != '0' && \
	img->argv[h + 1][i + 1] != '0'))
	{
		img->argv[h][i] = '0';
		img->argv[h + 1][i] = 'V';
	}
}

static void	go_right_enemy(t_data *img, int h, int i)
{
	img->enemy_l = img->enemy_r;
	if (img->argv[h][i + 1] == 'P')
	{
		printf("You lose!\n");
		exit(0);
	}
	if (img->argv[h][i + 2] == '1')
		img->otskok++;
	img->argv[h][i] = '0';
	img->argv[h][i + 1] = 'V';
}

void	move_enemies(t_data *img, int h, int i)
{
	if (img->argv[h][i] == 'V' && img->argv[h][i - 1] != '1' && \
	(img->argv[h][i - 1] == '0' || img->argv[h][i - 1] == 'P') && \
	img->del % 51 == 13 && img->otskok % 2 == 0)
		go_left_enemy(img, h, i);
	if (img->argv[h][i] == 'V' && img->argv[h][i + 1] != '1' && \
	(img->argv[h][i + 1] == '0' || img->argv[h][i + 1] == 'P') && \
	img->del % 51 == 13 && img->otskok % 2 == 1)
		go_right_enemy(img, h, i);
	if (img->argv[h][i] == 'V' && img->argv[h - 1][i] != '1' && \
	(img->argv[h - 1][i] == '0' || \
	img->argv[h - 1][i] == 'P') && \
	img->del % 51 == 13 && img->otskok % 3 == 2)
		go_up_enemy(img, h, i);
	if (img->argv[h][i] == 'V' && img->argv[h + 1][i] != '1' && \
	(img->argv[h + 1][i] == '0' || \
	img->argv[h + 1][i] == 'P') && \
	img->del % 51 == 13 && img->otskok % 3 == 1)
		go_down_enemy(img, h, i);
}
