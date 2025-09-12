/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:36:13 by erantala          #+#    #+#             */
/*   Updated: 2025/09/12 16:15:27 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int main(int argc, char **argv)
{
	t_data	*data;
	int		i;

	if (argc != 2)
		ft_exit("Usage: ./cub3D <map.cub>", 1);
	data = load_data(argv[1]);
	if (!data)
		ft_exit("Failed to load game data", 1);
	i = 0;
	start_game(data);
	return (0);
}
