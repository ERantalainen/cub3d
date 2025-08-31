/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 02:05:31 by erantala          #+#    #+#             */
/*   Updated: 2025/08/31 02:05:36 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

int main (int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_data	*data;

	data = load_default();
	load_game(data);
	return (1);
}