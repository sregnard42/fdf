/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:25:13 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/27 11:36:00 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "params.h"

void				params_init(t_params *params)
{
	params->mlx = mlx_init();
	params->win = mlx_new_window(params->mlx, WIN_WIDTH, WIN_HEIGHT,
			"FdF");
	mlx_key_hook(params->win, &get_input, params);
	params->img = NULL;
	params->output = NULL;
	params->xpm = NULL;
	params->pts = NULL;
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

void			params_free(t_params *p)
{
	mlx_destroy_image(p->mlx, p->img);
	mlx_destroy_window(p->mlx, p->win);
	free(p->mlx);
	ft_mapfree(&p->input);
	ft_mapfree(&p->output);
	ft_mapfree(&p->xpm);
	while (p->pts && *p->pts)
	{
		while (**p->pts)
			free(**p->pts++);
		free(*p->pts++);
	}
}
