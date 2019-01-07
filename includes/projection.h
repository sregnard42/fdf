/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:51:33 by sregnard          #+#    #+#             */
/*   Updated: 2019/01/07 09:25:26 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
# define PROJECTION_H

/*
**	projection.c
*/

void	projection_3d(t_params *params);

/*
**	projection_maths.c
*/

t_point	*proj_isometric(t_point *pt);
t_point	*proj_parallel(t_point *pt);
t_point	*proj_cavaliere(t_point *pt);
t_point	*proj_top(t_point *pt);

/*
**	projection_utils.c
*/

void	find_min_max(t_point ***pts, t_point *min, t_point *max);
void	normalize(t_point ***pts, t_point *min, t_point *max);
void	scale_to_window(t_params *p, t_point ***pts, t_point *max);
void	draw_all_lines(t_params *p, t_point pos);

/*
**	projection_utils2.c
*/

void	pts_iter(t_point ***pts, void *f(t_point *pt, int val), int val);
#endif
