/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:25:13 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/27 16:46:44 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "params.h"

void	params_init(t_params *params)
{
	params->mlx = mlx_init();
	params->win = mlx_new_window(params->mlx, WIN_WIDTH, WIN_HEIGHT,
			"FdF");
	params->img = NULL;
	params->view = 0;
	params->input = NULL;
	params->output = NULL;
	params->xpm = NULL;
	params->pts = NULL;
	params->cte1 = 1;
	params->cte2 = 1;
	params->a = 45;
}

void	params_free_view(t_params *p)
{
	if (p->win)
		mlx_clear_window(p->mlx, p->win);
	if (p->img)
		mlx_destroy_image(p->mlx, p->img);
	if (p->output)
		ft_mapfree(&p->output);
	if (p->xpm)
		ft_mapfree(&p->xpm);
	while (p->pts && *p->pts)
	{
		while (**p->pts)
			free(**p->pts++);
		free(*p->pts++);
	}
}

void	params_free(t_params *p)
{
	params_free_view(p);
	if (p->win)
		mlx_destroy_window(p->mlx, p->win);
	if (p->mlx)
		free(p->mlx);
	if (p->input)
		ft_mapfree(&p->input);
}
