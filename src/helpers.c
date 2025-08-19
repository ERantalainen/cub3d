/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:04:28 by erantala          #+#    #+#             */
/*   Updated: 2025/08/19 13:41:31 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_close(void *s)
{
	(void)s;
	ft_exit("", 0);
}

void	ft_exit(char *s, int code)
{
	t_data	*data;

	data = get_data();
	free(data);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	exit (code);
}