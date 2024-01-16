/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:04:34 by yxu               #+#    #+#             */
/*   Updated: 2024/01/16 16:58:58 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_line(char *path)
{
	int		fd;
	int		nb;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	nb = 0;
	line = get_next_line(fd);
	while (line)
	{
		nb++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (nb);
}

void	check_map_load(char ***map, t_data *data)
{
	int	i;
	int	rows;

	i = 0;
	rows = data->rows;
	if (rows == 0)
	{
		free_map(map);
		quit(2, "Map loading error\n", NULL);
	}
	while (rows-- > 0)
	{
		if (map[i++] == NULL)
		{
			free_map(map);
			quit(2, "Map loading error\n", NULL);
		}
	}
}

char	***read_map(char *path, t_data *data)
{
	int		fd;
	char	***map;
	char	*tmp;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		quit(2, "Map loading error\n", NULL);
	map = (char ***)malloc(sizeof(char *) * (data->rows + 1));
	if (map == NULL)
	{
		close(fd);
		quit(2, "Map loading error\n", NULL);
	}
	map[data->rows] = NULL;
	i = 0;
	while (i < data->rows)
	{
		tmp = get_next_line(fd);
		map[i++] = ft_split(tmp, ' ');
		free(tmp);
	}
	close(fd);
	check_map_load(map, data);
	return (map);
}

int	print_map(char ***map)
{
	int	i;
	int	j;

	if (map == NULL)
		return (0);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			ft_printf("%s ", map[i][j++]);
		i++;
	}
	ft_printf("\n");
	return (0);
}

int	free_map(char ***map)
{
	int	i;
	int	j;

	if (map == NULL)
		return (0);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			free(map[i][j++]);
		free(map[i++]);
	}
	free(map);
	return (0);
}
