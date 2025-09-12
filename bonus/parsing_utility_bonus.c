/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:34:53 by erantala          #+#    #+#             */
/*   Updated: 2025/09/12 16:20:42 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

int	flood_fill(char **map, int row, int col)
{
	if (!map[row])
	{
		ft_exit("Invalid Map", 1);
	}
	if (!map[row][col])
	{
		ft_exit("Invalid Map", 1);
	}
	if (map[row][col] == '1' || map[row][col] == 'V')
		return (0);
	map[row][col] = 'V';
	flood_fill(map, row + 1, col);
	flood_fill(map, row - 1, col);
	flood_fill(map, row, col + 1);
	flood_fill(map, row, col - 1);
	return (1);
}
