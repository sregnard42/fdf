/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:25:13 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/21 13:25:30 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "params.h"

t_params		*params_new(void)
{
	t_params	*params;

	params = (t_params *)malloc(sizeof(t_params));
	params->mlx = mlx_init();
	params->size = ft_ptnew(2560, 1440, 0);
	params->win = mlx_new_window(params->mlx, params->size->x, params->size->y,
			"FdF");
	mlx_key_hook(params->win, &get_input, params);
	params->img = NULL;
	return (params);
}

int				get_input(int keycode, void *params)
{
	if (keycode == KEY_ESCAPE)
	{
		params_free((t_params **)&params);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void			params_free(t_params **ptr_params)
{
	t_params *params;

	params = *ptr_params;
}
