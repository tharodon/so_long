/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharodon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:55:31 by tharodon          #+#    #+#             */
/*   Updated: 2021/08/03 16:55:46 by tharodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	go_up(t_data *vars)
{
	if (vars->argv[vars->one - 1][vars->two] == 'V')
	{
		vars->steps++;
		printf("You lose!\n");
		exit(0);
	}
	if (vars->argv[vars->one - 1][vars->two] == 'E' && \
	vars->collect_score != vars->numb_items)
		return ;
	if (vars->argv[vars->one - 1][vars->two] == 'E' && \
	vars->collect_score == vars->numb_items)
	{
		vars->steps++;
		printf("You win!\n");
		exit(0);
	}
	if (vars->argv[vars->one - 1][vars->two] == 'C')
		vars->collect_score++;
	vars->argv[vars->one][vars->two] = '0';
	vars->argv[vars->one - 1][vars->two] = 'P';
	vars->steps++;
}

static void	go_left(t_data *vars)
{
	vars->personage_r = vars->personage_l;
	if (vars->argv[vars->one][vars->two - 1] == 'V')
	{
		vars->steps++;
		printf("You lose!\n");
		exit(0);
	}
	if (vars->argv[vars->one][vars->two - 1] == 'E' && \
	vars->collect_score != vars->numb_items)
		return ;
	if (vars->argv[vars->one][vars->two - 1] == 'E' && \
	vars->collect_score == vars->numb_items)
	{
		vars->steps++;
		printf("You win!\n");
		exit(0);
	}
	if (vars->argv[vars->one][vars->two - 1] == 'C')
		vars->collect_score++;
	vars->argv[vars->one][vars->two] = '0';
	vars->argv[vars->one][vars->two - 1] = 'P';
	vars->steps++;
}

static void	go_down(t_data *vars)
{
	if (vars->argv[vars->one + 1][vars->two] == 'V')
	{
		vars->steps++;
		printf("You lose!\n");
		exit(0);
	}
	if (vars->argv[vars->one + 1][vars->two] == 'E' && \
	vars->collect_score != vars->numb_items)
		return ;
	if (vars->argv[vars->one + 1][vars->two] == 'E' && \
	vars->collect_score == vars->numb_items)
	{
		vars->steps++;
		printf("You win!\n");
		exit(0);
	}
	if (vars->argv[vars->one + 1][vars->two] == 'C')
		vars->collect_score++;
	vars->argv[vars->one][vars->two] = '0';
	vars->argv[vars->one + 1][vars->two] = 'P';
	vars->steps++;
}

static void	go_right(t_data *vars)
{
	vars->personage_r = vars->personage;
	if (vars->argv[vars->one][vars->two + 1] == 'V')
	{
		vars->steps++;
		printf("You lose!\n");
		exit(0);
	}
	if (vars->argv[vars->one][vars->two + 1] == 'E' && \
	vars->collect_score != vars->numb_items)
		return ;
	if (vars->argv[vars->one][vars->two + 1] == 'E' && \
	vars->collect_score == vars->numb_items)
	{
		vars->steps++;
		printf("You win!\n");
		exit(0);
	}
	if (vars->argv[vars->one][vars->two + 1] == 'C')
		vars->collect_score++;
	vars->argv[vars->one][vars->two] = '0';
	vars->argv[vars->one][vars->two + 1] = 'P';
	vars->steps++;
}

int	key_hook(int key, t_data *vars)
{
	if (key == 53)
		exit(0);
	else if (key == 1 && vars->argv[vars->one + 1][vars->two] != '1')
		go_down(vars);
	else if (key == 2 && vars->argv[vars->one][vars->two + 1] != '1')
		go_right(vars);
	else if (key == 0 && vars->argv[vars->one][vars->two - 1] != '1')
		go_left(vars);
	else if (key == 13 && vars->argv[vars->one - 1][vars->two] != '1')
		go_up(vars);
	map_drawing(vars);
	return (key);
}
