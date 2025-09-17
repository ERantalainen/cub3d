/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_arena_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 21:26:37 by jpelline          #+#    #+#             */
/*   Updated: 2025/09/17 14:45:07 by dimendon         ###   ########.fr       */
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
