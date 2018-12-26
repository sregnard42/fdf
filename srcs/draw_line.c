/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 08:36:46 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/23 19:07:02 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	init_values(t_point *p1, t_point *p2, t_point *d, t_point *s, float *err)
{
	d->x = (p1->x < p2->x) ? p2->x - p1->x : p1->x - p2->x;
	s->x = (p1->x < p2->x) ? 1 : -1;
	d->y = (p1->y < p2->y) ? p2->y - p1->y : p1->y - p2->y;
	s->y = (p1->y < p2->y) ? 1 : -1;
	*err = (d->x > d->y) ? d->x / 2 : d->y / 2;
}

int		end_reached(t_point s, t_point p1, t_point p2)
{
	return ((p1.x == p2.x && p1.y == p2.y)
			|| (s.x == 1 && p1.x > p2.x)
			|| (s.y == 1 && p1.y > p2.y)
			|| (s.x == -1 && p2.x > p1.x)
			|| (s.y == -1 && p2.y > p1.y));
}

void		draw_line(t_map *xpm, t_point p1, t_point p2, char c)
{
	t_point	d;
	t_point	s;
	float	err;
	float	err2;

	init_values(&p1, &p2, &d, &s, &err);
	while (!end_reached(s, p1, p2))
	{
		xpm->map[p1.y][p1.x] = c;
		err2 = err;
		if (err2 > -d.x)
		{
			err -= d.y;
			p1.x += s.x;
		}
		if (err2 < d.y)
		{
			err += d.x;
			p1.y += s.y;
		}
	}
}
