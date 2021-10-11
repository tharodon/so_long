/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharodon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:24:07 by tharodon          #+#    #+#             */
/*   Updated: 2021/08/03 18:24:09 by tharodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_drawing_enemies(void *amg)
{
	t_data	*img;
	int		h;
	int		i;

	img = (t_data *)amg;
	img->del++;
	h = -1;
	while (img->argv[++h])
	{
		i = -1;
		while (img->argv[h][++i])
		{
			img->del++;
			move_enemies(img, h, i);
		}
	}
	return (0);
}
