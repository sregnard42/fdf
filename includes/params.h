/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:37:06 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/14 14:23:20 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PARAMS_H
# define PARAMS_H

# include "libft.h"
# include "mlx.h"

typedef struct	s_params
{
	void		*mlx;
	void		*win;
	char		**map;
	t_point		*win_size;
	t_point		*map_size;
}				t_params;

t_params	*params_new(char **map);
void		params_free(t_params **params);

#endif
