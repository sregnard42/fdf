/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:25:13 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/26 14:52:54 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "params.h"

t_params		*params_new(void)
{
	t_params	*params;

	params = (t_params *)malloc(sizeof(t_params));
	params_init(params);
	return (params);
}

void				params_init(t_params *params)
{
	params->mlx = mlx_init();
	params->win = mlx_new_window(params->mlx, WIN_WIDTH, WIN_HEIGHT,
			"FdF");
	mlx_key_hook(params->win, &get_input, params);
	params->img = NULL;
}

int				get_input(int keycode, t_params *params)
{
	if (keycode == KEY_ESCAPE)
	{
		params_free(params);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void			params_free(t_params *params)
{
	mlx_destroy_image(params->mlx, params->img);
	mlx_destroy_window(params->mlx, params->win);
	free(params->mlx);
}
