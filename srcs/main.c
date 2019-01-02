/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:05:50 by sregnard          #+#    #+#             */
/*   Updated: 2019/01/02 15:17:19 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "defines.h"

static void	update_view(t_params *p)
{
	params_free_view(p);
	projection_3d(p);
	xpm_conversion(p);
	if (!(p->img = mlx_xpm_to_image(p->mlx, p->xpm->data,
					&(p->xpm->width), &(p->xpm->height))))
		trigger_error("Error while loading XPM into an image.", p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}

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
		params->height_modifier -= 0.1;
	if (keycode == KEY_UP)
		params->height_modifier += 0.1;
}

static void	zoom_and_move (int keycode, t_params *params)
{
	if (keycode == KEY_Q)
		if (params->scale_modifier < 3)
			params->scale_modifier += 0.1;
	if (keycode == KEY_E)
		if (params->scale_modifier > 0.1)
			params->scale_modifier -= 0.1;
	if (keycode == KEY_W)
		params->offset.y += 10;
	if (keycode == KEY_S)
		params->offset.y -= 10;
	if (keycode == KEY_A)
		params->offset.x += 10;
	if (keycode == KEY_D)
		params->offset.x -= 10;
}

static int	get_input(int keycode, t_params *params)
{
	if (keycode == KEY_ESCAPE)
	{
		params_free(params);
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_DOT)
	{
		params->height_modifier = 1;
		params->scale_modifier = 1;
		params->offset.x = 0;
		params->offset.y = 0;
	}
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT
			|| keycode == KEY_UP || keycode == KEY_DOWN)
		view_and_height(keycode, params);
	if (keycode == KEY_W || keycode == KEY_A
			|| keycode == KEY_S || keycode == KEY_D
			|| keycode == KEY_Q || keycode == KEY_E)
		zoom_and_move(keycode, params);
	update_view(params);
	return (1);
}

int	main(int ac, char **av)
{
	t_params	p;

	if (ac != 2)
		trigger_error(ERR_USAGE, NULL);
	params_init(&p);
	mlx_key_hook(p.win, &get_input, &p);
	if (!(p.input = ft_mapfrom(read_file(av[1]))))
		trigger_error(ERR_FILE, NULL);
	update_view(&p);
	mlx_loop(p.mlx);
	return (0);
}
