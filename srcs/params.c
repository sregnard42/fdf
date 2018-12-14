/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 09:01:42 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/14 14:23:38 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		set_win_size(t_params *params)
{
	float	ratio;

	params->map_size = (t_point *)malloc(sizeof(t_point));
	params->map_size->x = ft_max_strlen_tab(params->map);
	params->map_size->y = ft_nb_str_tab(params->map);
	ratio = params->map_size->x / params->map_size->y;
	params->win_size = (t_point *)malloc(sizeof(t_point));
	params->win_size->x = params->map_size->x * 100;
	params->win_size->y = params->map_size->y * 100;
	if (params->win_size->x > 1280 || params->win_size->y > 720)
	{
		if (ratio > 1)
		{
			params->win_size->x = 1280;
			params->win_size->y = 1280 / ratio;
		}
		else
		{
			params->win_size->y = 720;
			params->win_size->x = 720 / ratio;
		}
	}
}

t_params		*params_new(char **map)
{
	t_params	*params;

	params = (t_params *)malloc(sizeof(t_params));
	params->mlx = mlx_init();
	params->map = map;
	set_win_size(params);
	params->win = mlx_new_window(params->mlx,
			params->win_size->x, params->win_size->y, "FdF");
	return (params);
}

void			params_free(t_params **ptr_params)
{
	t_params *params;

	params = *ptr_params;
	ft_memdel((void **)&(params->win));
	ft_memdel((void **)&(params->mlx));
	ft_free_tab(&(params->map));
	ft_memdel((void **)ptr_params);
}
