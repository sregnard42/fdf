/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:16:40 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/19 14:15:51 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "projection.h"

static t_point	*get_point(t_point *pos)
{
	return (proj_isometric(pos));
}

static int		process_line(t_list **lst, char **map, t_point pos)
{
	t_list	*elem;
	int		i;

	i = 0;
	while (map && map[pos.y][pos.x + i])
	{
		pos.z = ft_atoi(&map[pos.y][pos.x + i]);
		if (!(elem = ft_lstnew(get_point(&pos), sizeof(t_point))))
		{
			ft_lstdel(lst, &ft_ptfree);
			return (0);
		}
		if (!(*lst))
			*lst = elem;
		else
			ft_lstadd(lst, elem);
		pos.x += 1;
		while (map[pos.y][pos.x + i] && map[pos.y][pos.x + i] != ' ')
			i += 1;
		while (map[pos.y][pos.x + i] && map[pos.y][pos.x + i] == ' ')
			i += 1;
	}
	return (1);
}

/*
**	Create a list of points representing the projection
*/

static t_list	*lst_points(char **map)
{
	t_list	*lst;
	t_point pos;

	lst = NULL;
	ft_ptset(&pos, 0, 0, 0);
	while (map && map[pos.y])
	{
		process_line(&lst, map, pos);
		pos.y += 1;
	}
	return (lst);
}

static int		fill_map(t_map *map, t_list *lst)
{
	t_point *pt;

	while (lst)
	{
		pt = (t_point *)lst->content;
		if (pt->y < 0 || pt->y >= map->height
				|| pt->x < 0 || pt->x >= map->width)
			return (0);
		(map->map)[pt->y][pt->x] = '*';
		lst = lst->next;
	}
	return (1);
}

t_map			*proj_mapping(char **map)
{
	t_list	*lst;
	t_map	*map_iso;
	t_point	*size;

	lst = lst_points(map);
	size = ft_ptnew(0, 0, 0);
	normalize(lst, size);
	map_iso = ft_mapnew(size->x + 1, size->y + 1, '.');
	if (!(fill_map(map_iso, lst)))
		ft_putendl("Problem iso");
	return (map_iso);
}
