/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:51:33 by sregnard          #+#    #+#             */
/*   Updated: 2019/01/10 11:31:45 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
# define PROJECTION_H

/*
**	projection.c
*/

void	projection_3d(t_params *p);

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

void	find_min_max(t_params *p);
void	normalize(t_params *p);
void	scale_to_window(t_params *p);
void	draw_all_lines(t_params *p, t_point pos);

#endif
