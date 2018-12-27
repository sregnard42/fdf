/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:51:33 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/27 09:50:38 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
# define PROJECTION_H

# include "libft.h"
# include "params.h"

typedef struct	s_projection
{
}		t_projection;

/*
**	projection.c
*/

void	projection_3d(t_params *params);

/*
**	projection_maths.c
*/

t_point	*proj_isometric(t_point *p);
t_point	*proj_parallel(t_point *p);

/*
**	projection_utils.c
*/

void	find_min_max(t_point ***pts, t_point *min, t_point *max);
int	normalize(t_point ***pts, t_point *min, t_point *max);
void	scale_to_window(t_point ***pts, t_point *max);
void	draw_all_lines(t_params *p, t_point pos);

#endif
