/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:25:13 by sregnard          #+#    #+#             */
/*   Updated: 2019/01/10 11:37:23 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "defines.h"
#include "params.h"
#include "errors.h"
#include "projection.h"
#include "xpm.h"

void	params_init(t_params *params)
{
	if (!(params->mlx = mlx_init()))
		trigger_error("mlx_init returned NULL.", params);
	params->win = mlx_new_window(params->mlx, WIN_WIDTH, WIN_HEIGHT,
			"FdF");
	params->img = NULL;
	params->view = 0;
	params->input = NULL;
	params->output = NULL;
	params->xpm = NULL;
	params->pts = NULL;
	params->height = 1;
	params->zoom = 1;
	params->offset.x = 0;
	params->offset.y = 0;
}

void	params_update_view(t_params *p)
{
	params_free_view(p);
	projection_3d(p);
	xpm_conversion(p);
	if (!(p->img = mlx_xpm_to_image(p->mlx, p->xpm->data,
					&(p->xpm->width), &(p->xpm->height))))
		trigger_error("Error while loading XPM into an image.", p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}

void	params_reset_view(t_params *params)
{
	params->height = 1;
	params->zoom = 1;
	params->offset.x = 0;
	params->offset.y = 0;
}

void	params_free_view(t_params *p)
{
	t_point	pos;

	if (p->win)
		mlx_clear_window(p->mlx, p->win);
	if (p->img)
		mlx_destroy_image(p->mlx, p->img);
	p->img = NULL;
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
	if (p->pts)
		free(p->pts);
	p->pts = NULL;
}

void	params_free(t_params *p)
{
	params_free_view(p);
	if (p->win)
		mlx_destroy_window(p->mlx, p->win);
	if (p->input)
		ft_mapfree(&p->input);
}
