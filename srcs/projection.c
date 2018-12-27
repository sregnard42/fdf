/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:36:45 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/27 11:30:50 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "projection.h"
#include "draw.h"
#include "errors.h"

static t_point	*get_point(t_point *pos)
{
	return (proj_isometric(pos));
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

static t_point	***get_points(t_map *input, t_params *p)
{
	t_point	***pts;
	t_point pos;
	char	**line;

	if (!(pts = (t_point ***)malloc(sizeof(t_point **)
					* (input->height + 1))))
		trigger_error("Error malloc pts get_points", p);
	pts[input->height] = NULL;
	ft_ptset(&pos, 0, 0, -1);
	while (pos.y < input->height)
	{
		line = ft_strsplit(input->data[pos.y], ' ');
		if (pos.z == -1)
		{
			pos.z += 1;
			input->width = ft_nb_str_tab(line);
		}
		else if (input->width != ft_nb_str_tab(line))
			trigger_error("Wrong width get_points.", p);
		if (!(pts[pos.y] = (t_point **)malloc(sizeof(t_point *)
						* (input->width + 1))))
			trigger_error("Error malloc pts[y] get_points", p);
		pts[pos.y][input->width] = NULL;
		process_line(pts, line, pos);
		pos.y += 1;
	}
	return (pts);
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
	p->pts = get_points(p->input, p);
	find_min_max(p->pts, &(p->min), &(p->max));
	normalize(p->pts, &(p->min), &(p->max));
	scale_to_window(p->pts, &(p->max));
	if (!(p->output = ft_mapnew(p->max.x + 1, p->max.y + 1, '.')))
		trigger_error("Error malloc projection_3d", p);
	place_points(p);
	free(p->pts);
	p->pts = NULL;
}
