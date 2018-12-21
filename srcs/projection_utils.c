/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:06:52 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/21 11:36:26 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "draw.h"

/*
 ** Find both minimum x and y and both maximum x and y
 */

static void	find_min_max(t_point ***pts, t_point *min, t_point *max)
{
	t_point *pt;
	t_point	pos;

	ft_ptset(&pos, 0, 0, 0);
	ft_ptset(min, 0, 0, -1);
	ft_ptset(max, 0, 0, 0);
	while (pts && pts[pos.y])
	{
		while (pts[pos.y][pos.x])
		{
			pt = pts[pos.y][pos.x];
			if (min->z == -1)
				ft_ptset(min, pt->x, pt->y, 0);
			if (min->x > pt->x)
				min->x = pt->x;
			if (min->y > pt->y)
				min->y = pt->y;
			if (max->x < pt->x)
				max->x = pt->x;
			if (max->y < pt->y)
				max->y = pt->y;
			pos.x += 1;
		}
		ft_ptset(&pos, 0, pos.y + 1, 0);
	}
}

/*
 ** Normalize points so that there is no negative coordinates
 ** Max will store both the maximum x and y AFTER normalization
 */

void		normalize(t_point ***pts, t_point *max)
{
	t_point *pt;
	t_point	min;
	t_point	pos;

	find_min_max(pts, &min, max);
	ft_ptset(&pos, 0, 0, 0);
	while (pts && pts[pos.y])
	{
		while (pts[pos.y][pos.x])
		{
			pt = pts[pos.y][pos.x];
			pt->x = pt->x - min.x;
			pt->y = pt->y - min.y;
			pos.x += 1;
		}
		ft_ptset(&pos, 0, pos.y + 1, 0);
	}
	max->x = max->x - min.x;
	max->y = max->y - min.y;
}

void		scale_to_window(t_point ***pts, t_point *size_win, t_point *max)
{
	t_point	pos;
	t_point	*pt;
	float	ratio_width;
	float	ratio_height;
	float	ratio;

	ratio_width = (float)size_win->x / max->x;
	ratio_height = (float)size_win->y / max->y;
	ratio = ratio_width < ratio_height ? ratio_width : ratio_height;
	max->x = max->x * ratio;
	max->y = max->y * ratio;
	ft_ptset(&pos, 0, 0, 0);
	while (pts && pts[pos.y])
	{
		while (pts[pos.y][pos.x])
		{
			pt = pts[pos.y][pos.x];
			pt->x = pt->x * ratio;
			pt->y = pt->y * ratio;
			pos.x += 1;
		}
		ft_ptset(&pos, 0, pos.y + 1, 0);
	}
}

/*
 **	Link points by drawing lines between then
 */

void		draw_all_lines(t_map *map, t_point ***pts, t_point size_tab,
		t_point pos)
{
	t_point *pt;
	t_point *pt2;

	pt = pts[pos.y][pos.x];
	if (pos.x + 1 < size_tab.x)
	{
		pt2 = pts[pos.y][pos.x + 1];
		draw_line(map, *pt, *pt2);
	}
	if (pos.y + 1 < size_tab.y)
	{
		pt2 = pts[pos.y + 1][pos.x];
		draw_line(map, *pt, *pt2);
	}
}
