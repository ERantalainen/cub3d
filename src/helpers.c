/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:04:28 by erantala          #+#    #+#             */
/*   Updated: 2025/08/21 22:00:36 by erantala         ###   ########.fr       */
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
	(void)data;
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	exit (code);
}

unsigned int make_color(unsigned int r, unsigned int g, unsigned int b, unsigned int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}