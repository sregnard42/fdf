/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:25:13 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/29 16:26:11 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "params.h"
#include "defines.h"

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
	params->height_modifier = 1;
}

void	params_free_view(t_params *p)
{
	t_point	pos;

	if (p->win)
		mlx_clear_window(p->mlx, p->win);
	if (p->img)
		mlx_destroy_image(p->mlx, p->img);
	if (p->output)
		ft_mapfree(&p->output);
	if (p->xpm)
		ft_mapfree(&p->xpm);
	ft_ptset(&pos, 0, 0, 0);
	while (p->pts && p->pts[pos.y])
	{
		while (p->pts[pos.y][pos.x])
			free(p->pts[pos.y][pos.x++]);
		free(p->pts[pos.y]);
		ft_ptset(&pos, 0, pos.y + 1, 0);
	}
	free(p->pts);
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
