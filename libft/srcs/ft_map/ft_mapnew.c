/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:33:59 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/19 14:20:44 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_map			*ft_mapnew(int width, int height, char c)
{
	t_map	*map;
	t_point pos;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	if (!(map->map = (char **)malloc(sizeof(char *) * (height + 1))))
		return (NULL);
	map->map[height] = NULL;
	ft_ptset(&pos, 0, 0, 0);
	while (pos.y < height)
	{
		if (!(map->map[pos.y] = (char *)malloc(sizeof(char) * (width + 1))))
			return (NULL);
		map->map[pos.y][width] = '\0';
		while (pos.x < width)
		{
			map->map[pos.y][pos.x] = c;
			pos.x += 1;
		}
		ft_ptset(&pos, 0, pos.y + 1, 0);
	}
	map->height = height;
	map->width = width;
	return (map);
}
