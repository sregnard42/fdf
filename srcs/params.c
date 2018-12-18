/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:25:13 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/18 09:26:15 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "params.h"

static void		set_win_size(t_params *params)
{
	float	ratio;

	ratio = (params->xpm)->width / (params->xpm)->height;
	params->win_size = (t_point *)malloc(sizeof(t_point));
	params->win_size->x = (params->xpm)->width * 100;
	params->win_size->y = (params->xpm)->height * 100;
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

t_params		*params_new(t_map *xpm)
{
	t_params	*params;

	params = (t_params *)malloc(sizeof(t_params));
	params->mlx = mlx_init();
	params->xpm = xpm;
	set_win_size(params);
	return (params);
}

void			params_free(t_params **ptr_params)
{
	t_params *params;

	params = *ptr_params;
	mlx_destroy_window(params->mlx, params->win);
	ft_memdel((void **)&(params->mlx));
//	ft_mapfree(&(params->xpm));
	ft_memdel((void **)ptr_params);
}
