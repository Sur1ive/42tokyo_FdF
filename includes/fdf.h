/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:21:34 by yxu               #+#    #+#             */
/*   Updated: 2024/01/16 14:22:03 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include <errno.h>
# include <libc.h>

typedef struct s_obj{
	int	x_from;
	int	y_from;
	int	x;
	int	y;
	int	collectible;
	int	life;
}	t_obj;

typedef struct s_image{
	void	*image;
	int		width;
	int		height;
}	t_image;

typedef struct s_texture{
	t_image	player_s1;
	t_image	player_s2;
	t_image	water;
	t_image	wall;
	t_image	escape;
	t_image	collect;
	t_image	enemy;
}	t_texture;

typedef struct s_data {
	void		*win;
	void		*mlx;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		**map;
	int			rows;
	int			cols;
	int			move_nb;
	t_obj		player;
	t_obj		enemy;
	t_texture	texture;
}	t_data;


#endif
