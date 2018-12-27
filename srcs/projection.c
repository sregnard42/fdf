/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:36:45 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/27 17:07:43 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "projection.h"
#include "draw.h"
#include "errors.h"

static t_point	*get_point(t_params *p, t_point *pos)
{
	if (p->view == VIEW_ISOMETRIC)
		return (proj_isometric(pos));
	if (p->view == VIEW_PARALLEL)
		return (proj_parallel(pos));
	return (NULL);
}

static int		process_line(t_params *p, char **line, t_point pos)
{
	t_point	*pt;

	while (line[pos.x])
	{
		pos.z = ft_atoi(line[pos.x]);
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
	ft_ptset(&pos, 0, 0, -1);
	while (pos.y < p->input->height)
	{
		line = ft_strsplit(p->input->data[pos.y], ' ');
		if (pos.z == -1)
		{
			pos.z += 1;
			p->input->width = ft_nb_str_tab(line);
		}
		else if (p->input->width != ft_nb_str_tab(line))
			trigger_error("Wrong width get_points.", p);
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
			if (pt->y < 0 || pt->x < 0
					|| pt->y >= p->output->height
					|| pt->x >= p->output->width)
				trigger_error("Out of array, place_points", p);
			(p->output->data)[pt->y][pt->x] = '*';
			draw_all_lines(p, pos);
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
	scale_to_window(p->pts, &(p->max));
	if (!(p->output = ft_mapnew(p->max.x + 1, p->max.y + 1, '.')))
		trigger_error("Error malloc projection_3d", p);
	place_points(p);
	free(p->pts);
	p->pts = NULL;
}
