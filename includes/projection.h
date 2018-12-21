/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:51:33 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/21 10:38:12 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
# define PROJECTION_H

# include "libft.h"

t_map	*projection_3d(char **map, t_point *size_window);

t_point	*proj_isometric(t_point *p);

int		normalize(t_point ***pts, t_point *max);
void	scale_to_window(t_point ***pts, t_point *size_win, t_point *max);
void	draw_all_lines(t_map *map, t_point ***Pts, t_point size_tab, t_point pos);

#endif
