/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:28:14 by yxu               #+#    #+#             */
/*   Updated: 2024/01/16 18:04:48 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(int *)dst = color;
}

t_point	round_point(t_point p)
{
	p.x = round(p.x);
	p.y = round(p.y);
	p.z = round(p.z);
	return (p);
}

void	drawline(t_data *data, t_point p1, t_point p2)
{
	int	fineness;
	int	i;

	fineness = 1000;
	i = 0;
	while (i < fineness)
	{
		my_mlx_pixel_put(data, round(p1.x + (p1.x - p2.x) / fineness * i),
			round(p1.y + (p1.y - p2.y) / fineness * i),
			round(p1.color + (p1.color - p2.color) / fineness * i));
		i++;
	}
}

int	screenctl(t_data *data)
{
	t_point	p1;
	t_point	p2;

	p1.x = 0;
	p1.y = 0;
	p1.color = 0x00FF0000;

	p2.x = 1000;
	p2.y = 1000;
	p2.color = 0xFFFFFFFF;
	drawline(data, p1, p2);
	mlx_string_put(data->mlx, data->win, 10, 10, 0x00FFFFFF, "Guide:");
	return (0);
}
