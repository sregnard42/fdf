/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:36:45 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/26 22:18:11 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "projection.h"
#include "draw.h"

static t_point	*get_point(t_point *pos)
{
	return (proj_parallel(pos));
}

static int		process_line(t_point ***pts, char **line, t_point pos)
{
	t_point	*pt;

	while (line[pos.x])
	{
		pos.z = ft_atoi(line[pos.x]);
		if (!(pt = get_point(&pos)))
			return (0);
		pts[pos.y][pos.x] = pt;
		pos.x += 1;
	}
	pts[pos.y][pos.x] = NULL;
	return (1);
}

/*
 **	Create a list of points representing the projection
 */

#include "errors.h"

static t_point	***get_points(char **map, t_point *size)
{
	t_point	***pts;
	t_point pos;
	char	**line;

	ft_ptset(size, -1, ft_nb_str_tab(map), 0);
	pts = (t_point ***)malloc(sizeof(t_point **) * (size->y + 1));
	pts[size->y] = NULL;
	ft_ptset(&pos, 0, 0, 0);
	while (pos.y < size->y)
	{
		line = ft_strsplit(map[pos.y], ' ');
		if (size->x == -1)
			size->x = ft_nb_str_tab(line);
		else if (size->x != ft_nb_str_tab(line))
			trigger_error("Line wrong length.");
		pts[pos.y] = (t_point **)malloc(sizeof(t_point *) * (size->x + 1));
		pts[pos.y][size->x] = NULL;
		process_line(pts, line, pos);
		pos.y += 1;
	}
	return (pts);
}

static int		place_points(t_map *map, t_point ***pts, t_point size_tab)
{
	t_point *pt;
	t_point	pos;

	ft_ptset(&pos, 0, 0, 0);
	while (pts[pos.y])
	{
		while (pts[pos.y][pos.x])
		{
			pt = pts[pos.y][pos.x];
			if (pt->y < 0 || pt->y >= map->height
					|| pt->x < 0 || pt->x >= map->width)
				return (0);
			(map->map)[pt->y][pt->x] = '*';
			draw_all_lines(map, pts, size_tab, pos);
			free(pt);
			pos.x += 1;
		}
		free (pts[pos.y]);
		ft_ptset(&pos, 0, pos.y + 1, 0);
	}
	return (1);
}

t_map			*projection_3d(t_params *params)
{
	t_point	size_tab;

	params->pts = get_points(map, &size_tab);
	find_min_max(pts, &min, &max);
	normalize(pts, &min, &max);
	scale_to_window(pts, &max);
	if (!(map_projection = ft_mapnew(max.x + 1, max.y + 1, '.')))
		return (NULL);
	if (!(place_points(map_projection, pts, size_tab)))
		ft_putendl("Problem filling map");
	free(pts);
	return (map_projection);
}
