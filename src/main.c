/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:36:13 by erantala          #+#    #+#             */
/*   Updated: 2025/10/14 14:58:52 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int		len;

	if (argc != 2)
		ft_exit("Usage: ./cub3D <map.cub>", 1);
	len = ft_strlen(argv[1]);
	if (len < 4 || ft_strncmp(argv[1] + len - 4, ".cub", 4) != 0)
		ft_exit("Error: invalid file extension (expected .cub)", 1);
	data = load_data(argv[1]);
	if (!data)
		ft_exit("Failed to load game data", 1);
	start_game(data);
	return (0);
}
