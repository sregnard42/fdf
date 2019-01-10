/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:34:50 by sregnard          #+#    #+#             */
/*   Updated: 2019/01/10 14:39:24 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "defines.h"
#include "params.h"
#include "errors.h"

static void	view_and_height(int keycode, t_params *params)
{
	if (keycode == KEY_LEFT)
	{
		if (params->view == 0)
			params->view = 3;
		else
			params->view -= 1;
	}
	if (keycode == KEY_RIGHT)
	{
		if (params->view == 3)
			params->view = 0;
		else
			params->view += 1;
	}
	if (keycode == KEY_DOWN)
		params->height -= 0.1;
	if (keycode == KEY_UP)
		params->height += 0.1;
}

static void	zoom_and_move(int keycode, t_params *p)
{
	if (keycode == KEY_Q)
		if (p->zoom < 10)
			p->zoom += 0.1;
	if (keycode == KEY_E)
		if (p->zoom > 0.1)
			p->zoom -= 0.1;
	if (keycode == KEY_W && p->offset.y < WIN_HEIGHT)
		p->offset.y += OFFSET_STEP;
	if (keycode == KEY_S && p->max.y - OFFSET_STEP > 0)
		p->offset.y -= OFFSET_STEP;
	if (keycode == KEY_A && p->offset.x < WIN_WIDTH)
		p->offset.x += OFFSET_STEP;
	if (keycode == KEY_D && p->max.x - OFFSET_STEP > 0)
		p->offset.x -= OFFSET_STEP;
}

int			get_input(int keycode, t_params *params)
{
	if (keycode == KEY_ESCAPE)
	{
		ft_putstr("Exiting program...");
		params_free(params);
		ft_putendl("Done.");
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_DOT)
		params_reset_view(params);
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT
			|| keycode == KEY_UP || keycode == KEY_DOWN)
		view_and_height(keycode, params);
	if (keycode == KEY_W || keycode == KEY_A
			|| keycode == KEY_S || keycode == KEY_D
			|| keycode == KEY_Q || keycode == KEY_E)
		zoom_and_move(keycode, params);
	params_update_view(params);
	return (1);
}
