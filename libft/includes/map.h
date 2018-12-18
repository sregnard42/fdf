/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:26:07 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/18 09:06:01 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "libft.h"

typedef struct	s_map
{
	char		**map;
	int			width;
	int			height;
}				t_map;

t_map			*ft_mapnew(int width, int height, char c);
void			ft_mapfree(t_map **map);

#endif
