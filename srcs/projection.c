/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:36:45 by sregnard          #+#    #+#             */
/*   Updated: 2019/01/06 15:50:53 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "defines.h"
#include "params.h"
#include "errors.h"
#include "projection.h"

static t_point	*get_point(t_params *p, t_point *pos)
{
	if (p->view == VIEW_ISOMETRIC)
		return (proj_isometric(pos));
	if (p->view == VIEW_PARALLEL)
		return (proj_parallel(pos));
	if (p->view == VIEW_CAVALIERE)
		return (proj_cavaliere(pos));
	if (p->view == VIEW_TOP)
		return (proj_top(pos));
	return (NULL);
}

static int		process_line(t_params *p, char **line, t_point pos)
{
	t_point	*pt;

	while (line[pos.x])
	{
		pos.z = ft_atoi(line[pos.x]) * p->height_modifier;
		if (!(pt = get_point(p, &pos)))
			return (0);
		p->pts[pos.y][pos.x] = pt;
		pos.x += 1;
	}
	p->pts[pos.y][pos.x] = NULL;
	return (1);
}

/*
 **	Create a list of points representing the projection
 */

static void	get_points(t_params *p)
{
	t_point pos;
	char	**line;

	if (!(p->pts = (t_point ***)malloc(sizeof(t_point **)
					* (p->input->height + 1))))
		trigger_error("Error malloc pts get_points", p);
	p->pts[p->input->height] = NULL;
	ft_ptset(&pos, 0, 0, 0);
	while (pos.y < p->input->height)
	{
		p->pts[pos.y] = NULL;
		line = ft_strsplit(p->input->data[pos.y], ' ');
		if (pos.y == 0)
			p->input->width = ft_nb_str_tab(line);
		else if (p->input->width != ft_nb_str_tab(line))
		{
			ft_free_tab(&line);
			trigger_error("Line length changed.", p);
		}
		if (!(p->pts[pos.y] = (t_point **)malloc(sizeof(t_point *)
						* (p->input->width + 1))))
			trigger_error("Error malloc pts[y] get_points", p);
		p->pts[pos.y][p->input->width] = NULL;
		process_line(p, line, pos);
		ft_free_tab(&line);
		pos.y += 1;
	}
}

static void		place_points(t_params *p)
{
	t_point *pt;
	t_point	pos;

	ft_ptset(&pos, 0, 0, 0);
	while (p->pts[pos.y])
	{
		while (p->pts[pos.y][pos.x])
		{
			pt = p->pts[pos.y][pos.x];
			if (!(pt->y < 0 || pt->x < 0
					|| pt->y >= p->output->height
					|| pt->x >= p->output->width))
			{
				(p->output->data)[pt->y][pt->x] = '*';
				draw_all_lines(p, pos);
			}
			ft_memdel((void **)&pt);
			pos.x += 1;
		}
		free (p->pts[pos.y]);
		p->pts[pos.y] = NULL;
		ft_ptset(&pos, 0, pos.y + 1, 0);
	}
}

void			projection_3d(t_params *p)
{
	get_points(p);
	find_min_max(p->pts, &(p->min), &(p->max));
	normalize(p->pts, &(p->min), &(p->max));
	scale_to_window(p, p->pts, &(p->max));
	if (!(p->output = ft_mapnew(p->max.x + 1, p->max.y + 1, '.')))
		trigger_error("Error malloc projection_3d", p);
	place_points(p);
	free(p->pts);
	p->pts = NULL;
}
