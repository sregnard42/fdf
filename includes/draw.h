/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 09:23:45 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/21 12:58:26 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "libft.h"
# include "mlx.h"
# include "params.h"

void	draw_line(t_map *xpm, t_point p1, t_point p2, char c);

#endif
