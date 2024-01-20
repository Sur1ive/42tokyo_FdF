/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:28:14 by yxu               #+#    #+#             */
/*   Updated: 2024/01/19 18:59:47 by yxu              ###   ########.fr       */
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

	fineness = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)) + 1;
	i = 0;
	while (i <= fineness)
	{
		my_mlx_pixel_put(data, round(p1.x + (p2.x - p1.x) / fineness * i),
			round(p1.y + (p2.y - p1.y) / fineness * i),
			round(p1.color + (p2.color - p1.color) / fineness * i));
		i++;
	}
}

t_point	isometric(int x, int y, int z)
{
	t_point	p;

	p.x = (x - y) * sqrt(3) / 2;
	p.y = (x + y) * 0.5 - z;
	p.color = 0x00FFFFFF;
	if (z > 0)
		p.color = create_trgb(0, 255, 255 / z, 255 / z);
	if (z < 0)
		p.color = create_trgb(0, 255 / z, 255 / z, 255);
	return (p);
}

t_offset	get_offset(int x_min, int x_max, int y_min, int y_max)
{
	t_offset	offset;

	offset.scaling = 0.8 * min(WIN_WIDTH / (x_max - x_min), WIN_HEIGHT / (y_max - y_min));
	offset.xoffset =
	offset.yoffset =
	return (offset);
}

int	screenctl(t_data *data)
{
	t_offset	offset;
	t_point	p1;
	t_point	p2;
	int		i;
	int		j;

	offset.xoffset = 500;
	offset.yoffset = 500;
	offset.scaling = 30;
	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			p1 = isometric(offset, j, i, ft_atoi(data->map[i][j]));
			if (i + 1 != data->rows)
			{
				p2 = isometric(offset, j, i + 1, ft_atoi(data->map[i + 1][j]));
				drawline(data, p1, p2);
			}
			if (j + 1 != data->cols)
			{
				p2 = isometric(offset, j + 1, i, ft_atoi(data->map[i][j + 1]));
				drawline(data, p1, p2);
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_string_put(data->mlx, data->win, 10, 10, 0x00FFFFFF, "Guide:");
	return (0);
}
