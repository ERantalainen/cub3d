/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_arena_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 21:26:37 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/18 18:20:01 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_arena	**get_arenas(t_arena **new);
void	free_arenas(void)
{
	t_arena	**arenas;
	int		i;

	i = 0;
	arenas = get_arenas(NULL);
	while (arenas[i])
	{
		free(arenas[i]);
		i++;
	}
	free(arenas);
}
