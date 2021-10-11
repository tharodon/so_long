/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharodon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:56:25 by tharodon          #+#    #+#             */
/*   Updated: 2021/08/03 16:56:27 by tharodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	struct_init(t_data *img, int strings)
{
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, \
	ft_strlen(img->argv[0]) * 64, (strings * 64) + 24, "so_looooooong");
	img->height = 64;
	img->with = 64;
	img->fon = "./xpm/fon.xpm";
	img->pes = "./xpm/pesok.xpm";
	img->pers_r = "./xpm/personage_right.xpm";
	img->pers_l = "./xpm/personage_left.xpm";
	img->ext = "./xpm/exit.xpm";
	img->im = "./xpm/item.xpm";
	img->emy_r = "./xpm/enemy_right.xpm";
	img->emy_l = "./xpm/enemy_left.xpm";
}

void	draw_positions(t_data *img, int h, int i)
{
	if (img->argv[h][i] == 'P')
	{
		img->one = h;
		img->two = i;
		mlx_put_image_to_window(img->mlx, img->mlx_win, \
		img->personage_r, img->x, img->y);
	}
	else if (img->argv[h][i] == '1')
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, \
		img->pesok, img->x, img->y);
		mlx_put_image_to_window(img->mlx, img->mlx_win, \
		img->stena, img->x, img->y);
	}
	else if (img->argv[h][i] == '0')
		mlx_put_image_to_window(img->mlx, img->mlx_win, \
		img->pesok, img->x, img->y);
	else if (img->argv[h][i] == 'C')
		mlx_put_image_to_window(img->mlx, img->mlx_win, \
		img->item, img->x, img->y);
	else if (img->argv[h][i] == 'V')
		mlx_put_image_to_window(img->mlx, img->mlx_win, \
		img->enemy_l, img->x, img->y);
	img->x += 64;
}

void	steps_count(t_data *img)
{
	char	*r;

	if (img->steps > 0)
	{
		r = ft_itoa_long(img->steps - 1);
		mlx_string_put(img->mlx, img->mlx_win, \
		img->x + 480, img->y, 0x00000000, r);
		free(r);
	}
	r = ft_itoa_long(img->steps);
	mlx_string_put(img->mlx, img->mlx_win, \
	img->x + 480, img->y, 0x00FF0000, r);
	free(r);
	img->y += 24;
}

int	map_drawing(void *amg)
{
	t_data	*img;
	int		h;
	int		i;

	img = (t_data *)amg;
	h = -1;
	img->x = 0;
	img->y = 0;
	steps_count(img);
	while (img->argv[++h])
	{
		i = -1;
		while (img->argv[h][++i])
		{
			if (img->argv[h][i] == 'E')
				mlx_put_image_to_window(img->mlx, img->mlx_win, \
				img->exit, img->x, img->y);
			draw_positions(img, h, i);
		}
		img->x = 0;
		img->y += 64;
	}
	map_drawing_enemies(img);
	return (0);
}

void	draw(t_data *img)
{
	img->stena = mlx_xpm_file_to_image(img->mlx, img->fon, \
	&img->with, &img->height);
	img->pesok = mlx_xpm_file_to_image(img->mlx, img->pes, \
	&img->with, &img->height);
	img->exit = mlx_xpm_file_to_image(img->mlx, img->ext, \
	&img->with, &img->height);
	img->personage_r = mlx_xpm_file_to_image(img->mlx, img->pers_r, \
	&img->with, &img->height);
	img->personage_l = mlx_xpm_file_to_image(img->mlx, img->pers_l, \
	&img->with, &img->height);
	img->item = mlx_xpm_file_to_image(img->mlx, img->im, \
	&img->with, &img->height);
	img->enemy_r = mlx_xpm_file_to_image(img->mlx, img->emy_r, \
	&img->with, &img->height);
	img->enemy_l = mlx_xpm_file_to_image(img->mlx, img->emy_l, \
	&img->with, &img->height);
	img->personage = img->personage_r;
	img->enemy = img->enemy_l;
	img->otskok = 0;
	mlx_hook(img->mlx_win, 2, 1L, key_hook, img);
	mlx_loop_hook(img->mlx, map_drawing, img);
}
