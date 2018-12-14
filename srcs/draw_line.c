/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 08:36:46 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/14 09:24:43 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_line(t_output *output, t_point *p1, t_point *p2)
{
	t_point p;
	t_point d;

	d.y = p2->y - p1->y;
	d.x = p2->x - p1->x;

	ft_ptcpy(&p, p1);
	while (p.y <= p2->y && p.x <= p2->x)
	{
		mlx_pixel_put(output->mlx, output->win, p.y, p.x, 0xFFFFFF);
	}
}

void	draw_v_line(t_output *output, t_point *p1, t_point *p2)
{
	t_point p;

	ft_ptcpy(&p, p1);
	while (p.y != p2->y)
	{
		mlx_pixel_put(output->mlx, output->win, p.y, p.x, 0xFFFFFF);
		(p.y < p2->y) ? (p.y += 1) : (p.y -= 1);
	}
}

void	draw_h_line(t_output *output, t_point *p1, t_point *p2)
{
	t_point p;

	ft_ptcpy(&p, p1);
	while (p.x != p2->x)
	{
		mlx_pixel_put(output->mlx, output->win, p.y, p.x, 0xFFFFFF);
		(p.y < p2->y) ? (p.y += 1) : (p.y -= 1);
	}
}
