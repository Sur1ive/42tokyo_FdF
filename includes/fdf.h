/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:21:34 by yxu               #+#    #+#             */
/*   Updated: 2024/01/19 18:59:05 by yxu              ###   ########.fr       */
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

# define ESC_KEY 53
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

typedef struct s_point {
double	x;
double	y;
double	z;
int		color;
}	t_point;

typedef struct s_offset {
int	xoffset;
int	yoffset;
int	scaling;
}	t_offset;

typedef struct s_data {
void	*win;
void	*mlx;
void	*img;
char	*addr;
int		bits_per_pixel;
int		line_length;
int		endian;
char	***map;
int		rows;
int		cols;
}	t_data;

int		screenctl(t_data *data);
int		key(int keycode, t_data *data);
int		count_line(char *path);
char	***read_map(char *path, t_data *data);
void	init(char ***map, t_data *data);
int		print_map(char ***map);
int		free_map(char ***map);
void	quit(int exitflag, char *msg, t_data *data);
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

#endif
