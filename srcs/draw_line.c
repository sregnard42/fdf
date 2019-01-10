/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 08:36:46 by sregnard          #+#    #+#             */
/*   Updated: 2019/01/10 14:53:48 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	put_pixel(t_map *map, t_point p1, t_point p2, char c)
{
	if (!(p1.x < 0 || p1.y < 0 || p1.x >= map->width || p1.y >= map->height))
		map->data[p1.y][p1.x] = c;
	if (p1.x == p2.x && p1.y == p2.y)
		return (0);
	return (1);
}

static void	draw_straight_line(t_map *map, t_point p1, t_point p2, char c)
{
	t_point	pos;
	t_point	end;

	pos = p1.y < p2.y ? p1 : p2;
	end = p1.y > p2.y ? p1 : p2;
	while (pos.y < end.y)
	{
		put_pixel(map, pos, end, c);
		pos.y += 1;
	}
	pos = p1.x < p2.x ? p1 : p2;
	end = p1.x > p2.x ? p1 : p2;
	while (pos.x < end.x)
	{
		put_pixel(map, pos, end, c);
		pos.x += 1;
	}
}

static void	init_values(t_point *p1, t_point *p2, t_point *d, t_point *s)
{
	d->x = (p1->x < p2->x) ? p2->x - p1->x : p1->x - p2->x;
	d->y = (p1->y < p2->y) ? p2->y - p1->y : p1->y - p2->y;
	d->z = 0;
	s->x = (p1->x < p2->x) ? 1 : -1;
	s->y = (p1->y < p2->y) ? 1 : -1;
	s->z = 0;
}

void		draw_line(t_map *map, t_point p1, t_point p2, char c)
{
	t_point	d;
	t_point	d2;
	t_point	s;
	float	err;
	float	err2;

	if (p1.y == p2.y || p1.x == p2.x)
		return (draw_straight_line(map, p1, p2, c));
	init_values(&p1, &p2, &d, &s);
	ft_ptcpy(&d2, &d);
	err = (d.x > d.y) ? d.x / 2 : d.y / 2;
	while (put_pixel(map, p1, p2, c) && (d2.x >= 0 || d2.y >= 0))
	{
		err2 = err;
		if (err2 > -d.x)
		{
			err -= d.y;
			p1.x += s.x + 0 * --d2.x;
		}
		if (err2 < d.y)
		{
			err += d.x;
			p1.y += s.y + 0 * --d2.y;
		}
	}
}
