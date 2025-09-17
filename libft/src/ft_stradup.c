/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erantala <erantala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:39:02 by erantala          #+#    #+#             */
/*   Updated: 2025/09/12 15:39:09 by erantala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_stradup(char **src)
{
	int		line;
	char	**dup;

	line = 0;
	if (src == NULL)
		return (NULL);
	while (src[line])
		line++;
	dup = (char **)malloc(sizeof(char *) * (line + 1));
	if (!dup)
		return (NULL);
	line = 0;
	while (src[line])
	{
		dup[line] = ft_strdup(src[line]);
		if (dup[line] == NULL)
		{
			ft_frearr((void **)dup, line);
			return (NULL);
		}
		line++;
	}
	dup[line] = NULL;
	return (dup);
}