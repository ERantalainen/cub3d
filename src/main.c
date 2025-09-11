/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:36:13 by erantala          #+#    #+#             */
/*   Updated: 2025/09/10 17:17:00 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int main(int argc, char **argv)
{
    t_data  *data;
    int     i;

    if (argc != 2)
        ft_exit("Usage: ./cub3D <map.cub>", 1);
    data = load_data(argv[1]);
    if (!data)
        ft_exit("Failed to load game data", 1);
    i = 0;
    while (data->map && data->map[i])
    {
        puts(data->map[i]);
        i++;
    }
    start_game(data);
    return (0);
}
