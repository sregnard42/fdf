/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:06:52 by sregnard          #+#    #+#             */
/*   Updated: 2019/01/10 14:59:29 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "defines.h"
#include "params.h"
#include "projection.h"
#include "draw.h"

void	find_min_max(t_params *p)
{
	t_point	pos;

	ft_ptset(&pos, -1, 0, 0);
	ft_ptcpy(&p->min, p->pts[pos.y][pos.x + 1]);
	ft_ptcpy(&p->max, p->pts[pos.y][pos.x + 1]);
	while (p->pts && p->pts[pos.y])
	{
		while (p->pts[pos.y][++pos.x])
		{
			if (p->min.x > p->pts[pos.y][pos.x]->x)
				p->min.x = p->pts[pos.y][pos.x]->x;
			if (p->min.y > p->pts[pos.y][pos.x]->y)
				p->min.y = p->pts[pos.y][pos.x]->y;
			if (p->min.z > p->pts[pos.y][pos.x]->z)
				p->min.z = p->pts[pos.y][pos.x]->z;
			if (p->max.x < p->pts[pos.y][pos.x]->x)
				p->max.x = p->pts[pos.y][pos.x]->x;
			if (p->max.y < p->pts[pos.y][pos.x]->y)
				p->max.y = p->pts[pos.y][pos.x]->y;
			if (p->max.z < p->pts[pos.y][pos.x]->z)
				p->max.z = p->pts[pos.y][pos.x]->z;
		}
		ft_ptset(&pos, -1, pos.y + 1, 0);
	}
}

void	normalize(t_params *p)
{
	t_point *pt;
	t_point	pos;

	ft_ptset(&pos, 0, 0, 0);
	while (p->pts && p->pts[pos.y])
	{
		while (p->pts[pos.y][pos.x])
		{
			pt = p->pts[pos.y][pos.x];
			pt->x = pt->x - p->min.x;
			pt->y = pt->y - p->min.y;
			pos.x += 1;
		}
		ft_ptset(&pos, 0, pos.y + 1, 0);
	}
	p->max.x = p->max.x - p->min.x;
	p->max.y = p->max.y - p->min.y;
	p->min.x = 0;
	p->min.y = 0;
}

void	scale_to_window(t_params *p)
{
	t_point	pos;
	t_point	*pt;
	float	ratio_width;
	float	ratio_height;
	float	r;

	ratio_width = (float)(WIN_WIDTH * p->zoom - 1) / p->max.x;
	ratio_height = (float)(WIN_HEIGHT * p->zoom - 1) / p->max.y;
	r = ratio_width < ratio_height ? ratio_width : ratio_height;
	p->min.x = p->min.x * r + p->offset.x + (WIN_WIDTH * (1 - p->zoom)) / 2;
	p->min.y = p->min.y * r + p->offset.y + (WIN_HEIGHT * (1 - p->zoom)) / 2;
	p->max.x = p->max.x * r + p->offset.x + (WIN_WIDTH * (1 - p->zoom)) / 2;
	p->max.y = p->max.y * r + p->offset.y + (WIN_HEIGHT * (1 - p->zoom)) / 2;
	ft_ptset(&pos, 0, 0, 0);
	while (p->pts && p->pts[pos.y])
	{
		while (p->pts[pos.y][pos.x])
		{
			pt = p->pts[pos.y][pos.x++];
			pt->x = pt->x * r + p->offset.x + (WIN_WIDTH * (1 - p->zoom)) / 2;
			pt->y = pt->y * r + p->offset.y + (WIN_HEIGHT * (1 - p->zoom)) / 2;
		}
		ft_ptset(&pos, 0, pos.y + 1, 0);
	}
}

char	find_color(t_params *p, t_point *p1, t_point *p2)
{
	float val;

	if (p->max.z == p->min.z)
		return (COLOR_BLUE);
	val = (p1->z + p2->z) / 2;
	val = (val - p->min.z) / (p->max.z - p->min.z) * 100;
	if (val <= 1)
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
	if (pt1->y == p->max.y)
		p->output->data[pt1->y][pt1->x] = find_color(p, pt1, pt1);
}
