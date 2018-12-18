/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:16:40 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/18 09:43:02 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_point	*get_point(char **map, t_point pos)
{
	t_point *pt;

	pt = (t_point *)malloc(sizeof(t_point));
	pt->x = pos.x - pos.y ;
	pt->y = map[pos.y][pos.x] + pos.x / 2 + pos.y / 2;
	return (pt);
}

static t_list	*lst_points(char **map)
{
	t_list	*lst;
	t_list	*elem;
	t_point pos;

	lst = NULL;
	ft_ptset(&pos, 0, 0, 0);
	while (map && map[pos.y])
	{
		while (map && map[pos.y][pos.x])
		{
			if (!(elem = ft_lstnew(get_point(map, pos), sizeof(t_point))))
			{
				ft_lstdel(&lst, &ft_ptfree);
				return (NULL);
			}
			if (!lst)
				lst = elem;
			else
				ft_lstadd(&lst, elem);
			pos.x += 1;
		}
		ft_ptset(&pos, 0, pos.y + 1, 0);
	}
	return (lst);
}

static void		find_edges(t_list *lst, t_point *min, t_point *max)
{
	t_point *pt;

	ft_ptset(min, 0, 0, 0);
	ft_ptset(max, 0, 0, 0);
	while (lst)
	{
		pt = (t_point *)lst->content;
		if (min->x > pt->x)
			min->x = pt->x;
		if (min->y > pt->y)
			min->y = pt->y;
		if (max->x < pt->x)
			max->x = pt->x;
		if (max->y < pt->y)
			max->y = pt->y;
		lst = lst->next;
	}
}

static int		normalize(t_list *lst, t_point *max)
{
	t_point *pt;
	t_point	*min;

	if (!(min = ft_ptnew(0, 0, 0)))
		return (0);
	find_edges(lst, min, max);
	while (lst)
	{
		pt = (t_point *)lst->content;
		pt->x -= min->x;
		pt->y -= min->y;
		lst = lst->next;
	}
	max->x -= min->x;
	max->y -= min->y;
	ft_putnbr(max->y);
	ft_putstr(", ");
	ft_putnbr(max->x);
	ft_putln();
	return (1);
}

static int		fill_map(t_map *map, t_list *lst)
{
	t_point *pt;

	ft_putendl("Fill map");
	while (lst)
	{
		pt = (t_point *)lst->content;
		if (pt->y < 0 || pt->y >= map->height
				|| pt->x < 0 || pt->x >= map->width)
		{
			ft_putnbr(pt->y);
			ft_putstr(", ");
			ft_putnbr(pt->x);
			ft_putln();
			return (0);
		}
		(map->map)[pt->y][pt->x] = '*';
		lst = lst->next;
	}
	return (1);
}

t_map			*isometric_mapping(char **map)
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
