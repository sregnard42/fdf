/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 08:36:46 by sregnard          #+#    #+#             */
/*   Updated: 2019/01/08 08:47:20 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	draw_straight_line(t_map *map, t_point p1, t_point p2, char c)
{
	t_point	pos;
	t_point	end;

	pos = p1.y < p2.y ? p1 : p2;
	end = p1.y > p2.y ? p1 : p2;
	while (pos.y < end.y)
	{
		if (pos.y >= 0 && pos.x >= 0)
			map->data[pos.y][pos.x] = c;
		pos.y += 1;
	}
	pos = p1.x < p2.x ? p1 : p2;
	end = p1.x > p2.x ? p1 : p2;
	while (pos.x < end.x)
	{
		if (pos.y >= 0 && pos.x >= 0)
			map->data[pos.y][pos.x] = c;
		pos.x += 1;
	}
}

static void	init_values(t_point *p1, t_point *p2, t_point *d, t_point *s)
{
	d->x = (p1->x < p2->x) ? p2->x - p1->x : p1->x - p2->x;
	s->x = (p1->x < p2->x) ? 1 : -1;
	d->y = (p1->y < p2->y) ? p2->y - p1->y : p1->y - p2->y;
	s->y = (p1->y < p2->y) ? 1 : -1;
}

static int	end_reached(t_point s, t_point p1, t_point p2)
{
	return ((p1.x == p2.x && p1.y == p2.y)
			|| (s.x == 1 && p1.x > p2.x)
			|| (s.y == 1 && p1.y > p2.y)
			|| (s.x == -1 && p2.x > p1.x)
			|| (s.y == -1 && p2.y > p1.y)
			|| (p1.x < 0 || p1.y < 0));
}

void		draw_line(t_map *map, t_point p1, t_point p2, char c)
{
	t_point	d;
	t_point	s;
	int		err;
	int		err2;

	init_values(&p1, &p2, &d, &s);
	err = (d.x > d.y) ? d.x / 2 : d.y / 2;
	if (p1.y == p2.y || p1.x == p2.x)
		draw_straight_line(map, p1, p2, c);
	else
		while (!(end_reached(s, p1, p2)))
		{
			map->data[p1.y][p1.x] = c;
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
