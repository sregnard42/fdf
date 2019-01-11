/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:36:45 by sregnard          #+#    #+#             */
/*   Updated: 2019/01/11 12:54:15 by sregnard         ###   ########.fr       */
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

static void		process_line(t_params *p, char **line, t_point pos)
{
	t_point	*pt;

	while (line[pos.x])
	{
		pos.z = ft_atoi(line[pos.x]) * p->height;
		if (!(pt = get_point(p, &pos)))
			trigger_error("Error malloc (t_point *) in process_line", p);
		p->pts[pos.y][pos.x] = pt;
		pos.x += 1;
	}
	ft_free_tab(&line);
	p->pts[pos.y][pos.x] = NULL;
}

static void		get_points(t_params *p)
{
	t_point pos;
	char	**line;

	if (!(p->pts = (t_point ***)malloc(sizeof(t_point **)
					* (p->input->height + 1))))
		trigger_error("Error malloc (t_point ***) in get_points", p);
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
			trigger_error("Different line length.", p);
		}
		if (!(p->pts[pos.y] = (t_point **)malloc(sizeof(t_point *)
						* (p->input->width + 1))))
			trigger_error("Error malloc (t_point **) in get_points", p);
		process_line(p, line, pos);
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
			draw_all_lines(p, pos);
			pt = p->pts[pos.y][pos.x];
			ft_memdel((void **)&pt);
			pos.x += 1;
		}
		free(p->pts[pos.y]);
		p->pts[pos.y] = NULL;
		ft_ptset(&pos, 0, pos.y + 1, 0);
	}
}

void			projection_3d(t_params *p)
{
	get_points(p);
	find_min_max(p);
	normalize(p);
	scale_to_window(p);
	if (p->max.x < 0 || p->max.y < 0)
		trigger_error("Error p->max", p);
	if (!(p->output = ft_mapnew(p->max.x + 1, p->max.y + 1, '.')))
		trigger_error("Error malloc projection_3d", p);
	place_points(p);
	free(p->pts);
	p->pts = NULL;
}
