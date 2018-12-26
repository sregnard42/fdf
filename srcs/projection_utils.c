/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:06:52 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/26 21:44:55 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "draw.h"

/*
 ** Find both minimum x and y and both maximum x and y
 */

void	find_min_max(t_point ***pts, t_point *min, t_point *max)
{
	t_point *pt;
	t_point	pos;

	ft_ptset(&pos, 0, 0, 0);
	ft_ptset(max, 0, 0, 0);
	while (pts && pts[pos.y])
	{
		while (pts[pos.y][pos.x])
		{
			pt = pts[pos.y][pos.x];
			if (pos.y == 0 && pos.x == 0)
				ft_ptset(min, pt->x, pt->y, pt->z);
			if (min->x > pt->x)
				min->x = pt->x;
			if (min->y > pt->y)
				min->y = pt->y;
			if (min->z > pt->z)
				min->z = pt->z;
			if (max->x < pt->x)
				max->x = pt->x;
			if (max->y < pt->y)
				max->y = pt->y;
			if (max->z < pt->z)
				max->z = pt->z;
			pos.x += 1;
		}
		ft_ptset(&pos, 0, pos.y + 1, 0);
	}
}

/*
 ** Normalize points so that there is no negative coordinates
 ** Max will store both the maximum x and y AFTER normalization
 */

void		normalize(t_point ***pts, t_point *min, t_point *max)
{
	t_point *pt;
	t_point	pos;

	ft_ptset(&pos, 0, 0, 0);
	while (pts && pts[pos.y])
	{
		while (pts[pos.y][pos.x])
		{
			pt = pts[pos.y][pos.x];
			pt->x = pt->x - min->x;
			pt->y = pt->y - min->y;
			pos.x += 1;
		}
		ft_ptset(&pos, 0, pos.y + 1, 0);
	}
	max->x = max->x - min->x;
	max->y = max->y - min->y;
}

/*
 **	Scale image to window
 */

void		scale_to_window(t_point ***pts, t_point *max)
{
	t_point	pos;
	t_point	*pt;
	float	ratio_width;
	float	ratio_height;
	float	ratio;

	ratio_width = (float)WIN_WIDTH / max->x;
	ratio_height = (float)WIN_HEIGHT / max->y;
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
 **	Find appropriate color depending on height and steep
 */

char        find_color(t_point *pt1, t_point *pt2)
{
	if (pt1->z == 0 && pt2->z == 0)
		return (COLOR_BLUE);
	if (pt1->z < 0)
		return (COLOR_GREEN);
	else
		return (COLOR_YELLOW);
	return (COLOR_WHITE);
}

/*
 **	Link points by drawing lines between then
 */

void		draw_all_lines(t_map *map, t_point ***pts, t_point size_tab,
		t_point pos)
{
	t_point *pt1;
	t_point *pt2;

	pt1 = pts[pos.y][pos.x];
	if (pos.x + 1 < size_tab.x)
	{
		pt2 = pts[pos.y][pos.x + 1];
		draw_line(map, *pt1, *pt2, find_color(pt1, pt2));
	}
	if (pos.y + 1 < size_tab.y)
	{
		pt2 = pts[pos.y + 1][pos.x];
		draw_line(map, *pt1, *pt2, find_color(pt1, pt2));
	}
}
