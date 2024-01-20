/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:49:56 by yxu               #+#    #+#             */
/*   Updated: 2024/01/19 18:59:55 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_cols(char ***map)
{
	int	lenth;

	if (map == NULL)
		return (0);
	lenth = 0;
	while (map[0][lenth])
		lenth++;
	return (lenth);
}

void	init(char ***map, t_data *data)
{
	data->cols = count_cols(map);
	data->map = map;
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}
