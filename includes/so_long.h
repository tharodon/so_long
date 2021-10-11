/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharodon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:53:01 by tharodon          #+#    #+#             */
/*   Updated: 2021/08/03 21:53:03 by tharodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# define BUFFER_SIZE 10

typedef struct s_data
{
	int		x;
	int		y;
	int		one;
	int		two;
	int		numb_items;
	int		collect_score;
	int		height;
	int		with;

	void	*stena;
	void	*personage_r;
	void	*personage_l;
	void	*personage;
	void	*item;
	void	*enemy_r;
	void	*enemy_l;
	void	*enemy;
	void	*pesok;
	void	*exit;
	void	*mlx;
	void	*mlx_win;

	char	**argv;
	char	*fon;
	char	*pes;
	char	*ext;
	char	*im;
	char	*emy_r;
	char	*emy_l;
	char	*pers_r;
	char	*pers_l;
	long	steps;
	long	otskok;
	long	del;
}				t_data;

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa_long(long n);
int		ft_strlen(const char *str);
int		get_next_line(int fd, char **line);
int		key_hook(int key, t_data *vars);
int		valid_map(t_data *img);
int		valid_map_bonus(t_data *img);
int		map_drawing(void *amg);
int		map_drawing_enemies(void *amg);
void	struct_init(t_data *img, int strings);
void	draw(t_data *img);
void	move_enemies(t_data *img, int h, int i);
#endif