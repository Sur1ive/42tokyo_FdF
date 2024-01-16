/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:49:56 by yxu               #+#    #+#             */
/*   Updated: 2024/01/16 17:51:07 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	arrlen(char **arr)
{
	int	lenth;

	if (arr == NULL)
		return (0);
	lenth = 0;
	while (*arr++)
		lenth++;
	return (lenth);
}

void	init(char ***map, t_data *data)
{
	// data->cols = arrlen(map[0]);
	data->map = map;
	data->win = mlx_new_window(data->mlx, 1920, 1080, "FdF");
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}
