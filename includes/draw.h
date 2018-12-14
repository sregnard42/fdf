/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 09:23:45 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/14 13:37:55 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "libft.h"
# include "mlx.h"
# include "params.h"

void	draw_line(t_params *params, t_point *p1, t_point *p2);
void	draw_v_line(t_output *params, t_point *p1, t_point *p2);
void	draw_h_line(t_output *params, t_point *p1, t_point *p2);

#endif
