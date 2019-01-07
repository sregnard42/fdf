/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:06:52 by sregnard          #+#    #+#             */
/*   Updated: 2019/01/07 11:54:19 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "defines.h"
#include "params.h"
#include "projection.h"
#include "draw.h"

void	find_min_max(t_point ***pts, t_point *min, t_point *max)
{
	t_point	pos;

	ft_ptset(&pos, -1, 0, 0);
	ft_ptcpy(min, pts[pos.y][pos.x + 1]);
	ft_ptcpy(max, pts[pos.y][pos.x + 1]);
	while (pts && pts[pos.y])
	{
		while (pts[pos.y][++pos.x])
		{
			if (min->x > pts[pos.y][pos.x]->x)
				min->x = pts[pos.y][pos.x]->x;
			if (min->y > pts[pos.y][pos.x]->y)
				min->y = pts[pos.y][pos.x]->y;
			if (min->z > pts[pos.y][pos.x]->z)
				min->z = pts[pos.y][pos.x]->z;
			if (max->x < pts[pos.y][pos.x]->x)
				max->x = pts[pos.y][pos.x]->x;
			if (max->y < pts[pos.y][pos.x]->y)
				max->y = pts[pos.y][pos.x]->y;
			if (max->z < pts[pos.y][pos.x]->z)
				max->z = pts[pos.y][pos.x]->z;
		}
		ft_ptset(&pos, -1, pos.y + 1, 0);
	}
}

void	normalize(t_point ***pts, t_point *min, t_point *max)
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

void	scale_to_window(t_params *p, t_point ***pts, t_point *max)
{
	t_point	pos;
	t_point	*pt;
	float	ratio_width;
	float	ratio_height;
	float	ratio;

	ratio_width = (float)(WIN_WIDTH * p->zoom - 1) / max->x;
	ratio_height = (float)(WIN_HEIGHT * p->zoom - 1) / max->y;
	ratio = ratio_width < ratio_height ? ratio_width : ratio_height;
	max->x = max->x * ratio + p->offset.x + (WIN_WIDTH * (1 - p->zoom)) / 2;
	max->y = max->y * ratio + p->offset.y + (WIN_HEIGHT * (1 - p->zoom)) / 2;
	ft_ptset(&pos, 0, 0, 0);
	while (pts && pts[pos.y])
	{
		while (pts[pos.y][pos.x])
		{
			pt = pts[pos.y][pos.x++];
			pt->x = pt->x * ratio + p->offset.x
				+ (WIN_WIDTH * (1 - p->zoom)) / 2;
			pt->y = pt->y * ratio + p->offset.y
				+ (WIN_HEIGHT * (1 - p->zoom)) / 2;
		}
		ft_ptset(&pos, 0, pos.y + 1, 0);
	}
}

char	find_color(t_params *p, t_point *pt1, t_point *pt2)
{
	float	val;

	val = (pt1->z + pt2->z) / 2;
	val = (val - p->min.z) / (p->max.z - p->min.z) * 100;
	if (val <= 0)
		return (COLOR_BLUE);
	if (val <= 20)
		return (COLOR_CYAN);
	if (val <= 40)
		return (COLOR_GREEN);
	if (val <= 60)
		return (COLOR_YELLOW);
	if (val <= 80)
		return (COLOR_ORANGE);
	if (val <= 100)
		return (COLOR_RED);
	return (COLOR_WHITE);
}

void	draw_all_lines(t_params *p, t_point pos)
{
	t_point *pt1;
	t_point *pt2;

	pt1 = p->pts[pos.y][pos.x];
	if (pos.x + 1 < p->input->width)
	{
		pt2 = p->pts[pos.y][pos.x + 1];
		draw_line(p->output, *pt1, *pt2, find_color(p, pt1, pt2));
	}
	if (pos.y + 1 < p->input->height)
	{
		pt2 = p->pts[pos.y + 1][pos.x];
		draw_line(p->output, *pt1, *pt2, find_color(p, pt1, pt2));
	}
	if (pos.x + 1 < p->input->width && pos.y + 1 < p->input->height)
	{
		pt2 = p->pts[pos.y + 1][pos.x + 1];
		draw_line(p->output, *pt1, *pt2, find_color(p, pt1, pt2));
	}
	if (pos.x - 1 >= 0 && pos.y + 1 < p->input->height)
	{
		pt2 = p->pts[pos.y + 1][pos.x - 1];
		draw_line(p->output, *pt1, *pt2, find_color(p, pt1, pt2));
	}
}
