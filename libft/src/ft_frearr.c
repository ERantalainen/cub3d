/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frearr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:13:08 by erantala          #+#    #+#             */
/*   Updated: 2025/10/14 11:25:06 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_frearr(void **s, int lines)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] && i < lines)
	{
		free(s[i]);
		i++;
	}
	free(s);
}
