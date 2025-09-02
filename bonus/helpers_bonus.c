/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:04:28 by erantala          #+#    #+#             */
/*   Updated: 2025/09/01 23:37:19 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

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
	(void)write(2, s, ft_strlen(s));
	(void)write(2, "\n", 1);
	exit (code);
}

unsigned int make_color(unsigned int r, unsigned int g, unsigned int b, unsigned int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

char	*ft_stradd(char *s1, char *s2)
{
	int		pos;
	int		i;
	char	*res;

	i = 0;
	pos = 0;
	res = arena_malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	while(s1[pos])
	{
		res[pos] = s1[pos];
		pos++;
	}
	while (s2[i])
	{
		res[pos] = s2[i];
		pos++;
		i++;
	}
	res[pos] = 0;
	return (res);
}

void	place_pixel(mlx_image_t *img, unsigned int pixel, int x, int y)
{
	mlx_put_pixel(img, x, y, pixel);
}

#include <time.h>
#include <sys/time.h>

time_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_usec / 1000) + (tv.tv_sec * 1000));
}