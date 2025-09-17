/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:36:13 by erantala          #+#    #+#             */
/*   Updated: 2025/09/10 14:48:47 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

<<<<<<< Updated upstream
int main (int argc, char **argv)
=======
int	main(int argc, char **argv)
>>>>>>> Stashed changes
{
	(void)argc;
	(void)argv;
	t_data	*data;

	data = load_default();
	for (int i = 0; data->map[i]; i++)
		puts(data->map[i]);
	load_game(data);
	return (1);
}