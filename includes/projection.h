/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:51:33 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/26 22:17:13 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
# define PROJECTION_H

# include "libft.h"

typedef struct	s_projection
{
}		t_projection;

/*
**	projection.c
*/

t_map	*projection_3d(t_params *params);

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
void	draw_all_lines(t_map *map, t_point ***pts, t_point size_tab, t_point pos);

#endif
