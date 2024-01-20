/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:01:27 by yxu               #+#    #+#             */
/*   Updated: 2024/01/19 17:56:49 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		quit(0, "Manual exit\n", data);
	// if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	// {
	// 	move(keycode, data);
	// 	enemy_move(data);
	// 	remap(data);
	// 	enemy_atk(data);
	// }
	// if (keycode == 3)
	// 	player_atk(data);
	return (0);
}
