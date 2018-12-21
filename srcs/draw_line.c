/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 08:36:46 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/21 12:57:46 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_line(t_map *xpm, t_point p1, t_point p2, char c)
{
	t_point	d;
	t_point	s;
	int		err;
	int		e2;

	d.x = (p1.x < p2.x) ? p2.x - p1.x : p1.x - p2.x;
	s.x = (p1.x < p2.x) ? 1 : -1;
	d.y = (p1.y < p2.y) ? p2.y - p1.y : p1.y - p2.y;
	s.y = (p1.y < p2.y) ? 1 : -1;
	err = (d.x > d.y) ? d.x / 2 : d.y / 2;
	while (p1.y != p2.y && p1.x != p2.x)
	{
		xpm->map[p1.y][p1.x] = c;
		e2 = err;
		if (e2 > -d.x)
		{
			err -= d.y;
			p1.x += s.x;
		}
		if (e2 < d.y)
		{
			err += d.x;
			p1.y += s.y;
		}
	}
}
