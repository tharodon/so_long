/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharodon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:55:52 by tharodon          #+#    #+#             */
/*   Updated: 2021/08/03 16:55:55 by tharodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static long	schet(long c)
{
	unsigned long	tmp;

	tmp = 0;
	if (c == 0)
	{
		tmp++;
	}
	if (c < 0)
	{
		c = c * -1;
		tmp++;
	}
	while (c)
	{
		c = c / 10;
		tmp++;
	}
	return (tmp);
}

char	*ft_itoa_long(long n)
{
	unsigned long	tmp;
	long			sign;
	char			*r;

	sign = 1;
	tmp = schet(n);
	r = (char *)malloc(tmp + 1);
	if (r == NULL)
		return (NULL);
	r[tmp] = '\0';
	while (tmp-- > 0)
	{
		r[tmp] = n % 10 * sign + 48;
		n = n / 10;
	}
	return (r);
}
