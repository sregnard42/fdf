/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:51:33 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/19 14:05:45 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
# define PROJECTION_H

# include "libft.h"

t_map	*proj_mapping(char **map);

t_point	*proj_isometric(t_point *p);

void	find_edges(t_list *lst, t_point *min, t_point *max);
int		normalize(t_list *lst, t_point *max);

#endif
