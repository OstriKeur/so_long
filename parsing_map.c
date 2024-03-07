/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorin <smorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:28:54 by smorin42          #+#    #+#             */
/*   Updated: 2024/03/07 15:13:32 by smorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_alloc(char *s1, char *s2, int nb_alloc)
{
	if (nb_alloc == 2)
	{
		free(s1);
		free(s2);
	}
	else if (nb_alloc == -1)
		free(s1);
	else if (nb_alloc == 1)
		free(s2);
}

char	*ft_freejoin(char *s1, char *s2, int nb_alloc)
{
	size_t	i;
	size_t	len_s1;
	char	*join;

	if (!s1 || !s2)
		return (free_alloc(s1, s2, nb_alloc), NULL);
	len_s1 = ft_strlen(s1);
	join = ft_calloc(len_s1 + ft_strlen(s2) + 1, sizeof(char));
	if (!join)
		return (free_alloc(s1, s2, nb_alloc), NULL);
	i = -1;
	while (s1[++i])
		join[i] = s1[i];
	i = -1;
	while (s2[++i])
		join[i + len_s1] = s2[i];
	return (free_alloc(s1, s2, nb_alloc), join);
}

static void	parsing(t_map *games)
{
	int	height;

	games->lines = ft_get_next_line(games->fd);
	height = 0;
	games->buff = ft_get_next_line(games->fd);
	while (games->buff)
	{
		games->lines = ft_freejoin(games->lines, games->buff, 2);
		games->buff = ft_get_next_line(games->fd);
	}
	games->maps = ft_split(games->lines, '\n');
	free(games->buff);
	free(games->lines);
	close(games->fd);
	if (!games->maps)
		free_all_and_error(games, "MALLOC ERROR");
	if (!games->maps[0])
		free_all_and_error(games, "TOO MUCH LINES");
	while (games->maps[height] != NULL)
		height++;
	games->height = height;
	games->lenght = ft_strlen(games->maps[0]);
	if (games->height == 0)
		free_all_and_error(games, "EMPTY MAP FILE");
}

void	parsing_map(t_map *games)
{
	games->fd = open(games->files_name, O_RDONLY);
	if (games->fd < 0)
		map_error("NO MAP SO SORRY BRO");
	parsing(games);
}

int	exit_map(t_map *games)
{
	if (games)
	{
		if (games->imgs->collect != NULL)
			mlx_destroy_image(games->mlx_ptr, games->imgs->collect);
		if (games->imgs->player != NULL)
			mlx_destroy_image(games->mlx_ptr, games->imgs->player);
		if (games->imgs->exitt != NULL)
			mlx_destroy_image(games->mlx_ptr, games->imgs->exitt);
		if (games->imgs->walls != NULL)
			mlx_destroy_image(games->mlx_ptr, games->imgs->walls);
		if (games->imgs->floorr != NULL)
			mlx_destroy_image(games->mlx_ptr, games->imgs->floorr);
	}
	return (0);
}
