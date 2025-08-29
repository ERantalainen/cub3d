/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:36:13 by erantala          #+#    #+#             */
/*   Updated: 2025/08/29 16:35:01 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int main (int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_data	*data;

	data = load_default();
	load_game(data);
	return (1);
}