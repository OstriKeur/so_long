/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorin <smorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:30:25 by smorin            #+#    #+#             */
/*   Updated: 2024/03/04 18:10:37 by smorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	right_move(t_map *games, int i, int j)
{
	if (games->maps[j][i] == 'E')
	{
		if (games->accessible_collectibles == 0)
			return (0);
		ft_printf("\nYou Have Won, Congrats!\n");
		exit_point(games);
	}
	if (games->maps[j][i] == '0')
	{
		games->maps[j][i] = 'P';
		games->px_x = i;
		games->py_y = j;
		games->moves++;
	}
	if (games->maps[j][i] == 'C')
	{
		games->maps[j][i] = 'P';
		games->px_x = i;
		games->py_y = j;
		games->accessible_collectibles--;
		games->moves++;
	}
	return (1);
}

static int	keyboard_w_s(t_map *games, int movement)
{
	int	i;
	int	j;
	int	k;

	i = games->px_x;
	j = games->py_y;
	if (movement == XK_w)
		j--;
	else if (movement == XK_s)
		j++;
	if (games->maps[j][i] == '1')
		return (0);
	k = right_move(games, i, j);
	if (!k)
		return (0);
	if (movement == XK_w)
		games->maps[j + 1][i] = '0';
	else if (movement == XK_s)
		games->maps[j - 1][i] = '0';
	return (1);
}

static int	keyboard_a_d(t_map *games, int movement)
{
	int	i;
	int	j;
	int	k;

	i = games->px_x;
	j = games->py_y;
	if (movement == XK_a)
		i--;
	else if (movement == XK_d)
		i++;
	if (games->maps[j][i] == '1')
		return (0);
	k = right_move(games, i, j);
	if (!k)
		return (0);
	if (movement == XK_a)
		games->maps[j][i + 1] = '0';
	else if (movement == XK_d)
		games->maps[j][i - 1] = '0';
	return (1);
}

int	controls_working(int command, t_map *games)
{
	int	works;

	if (command == XK_Escape)
		exit_point(games);
	if (command == XK_w)
		works = keyboard_w_s(games, command);
	if (command == XK_s)
		works = keyboard_w_s(games, command);
	if (command == XK_a)
		works = keyboard_a_d(games, command);
	if (command == XK_d)
		works = keyboard_a_d(games, command);
	printf("Steps Taken: %i\n", games->moves);
	printf("Collectables Remaining: %i\n", games->accessible_collectibles);
	if (works)
		init_image(games);
	return (1);
}

int	exit_point(t_map *games)
{
	int	line;

	line = 0;
	if (games->win_ptr)
		mlx_destroy_window(games->mlx_ptr, games->win_ptr);
	free(games->mlx_ptr);
	while (line < games->height - 1)
		free(games->maps[line++]);
	free(games->maps);
	exit(0);
}
