/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:05:50 by sregnard          #+#    #+#             */
/*   Updated: 2019/01/07 11:52:36 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "defines.h"
#include "params.h"
#include "projection.h"
#include "xpm.h"
#include "errors.h"

static void	update_view(t_params *p)
{
	params_free_view(p);
	ft_putstr("Calculcating projection...");
	projection_3d(p);
	ft_putendl("Done.");
	ft_putstr("Converting to XPM format...");
	xpm_conversion(p);
	ft_putendl("Done.");
	ft_putstr("Creating image from XPM...");
	if (!(p->img = mlx_xpm_to_image(p->mlx, p->xpm->data,
					&(p->xpm->width), &(p->xpm->height))))
		trigger_error("Error while loading XPM into an image.", p);
	ft_putendl("Done.");
	ft_putstr("Displaying image...");
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	ft_putendl("Done.");
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
		params->height -= 0.1;
	if (keycode == KEY_UP)
		params->height += 0.1;
}

static void	zoom_and_move(int keycode, t_params *params)
{
	if (keycode == KEY_Q)
		if (params->zoom < 3)
			params->zoom += 0.1;
	if (keycode == KEY_E)
		if (params->zoom > 0.1)
			params->zoom -= 0.1;
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
		ft_putstr("Exiting program...");
		params_free(params);
		ft_putendl("Done.");
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_DOT)
	{
		params->height = 1;
		params->zoom = 1;
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

int			main(int ac, char **av)
{
	t_params	p;

	if (ac != 2)
		trigger_error(ERR_USAGE, NULL);
	ft_putstr("Initializing params...");
	params_init(&p);
	mlx_key_hook(p.win, &get_input, &p);
	ft_putendl("Done.");
	ft_putstr("Parsing file...");
	if (!(p.input = ft_mapfrom(read_file(av[1]))))
		trigger_error(ERR_FILE, NULL);
	ft_putendl("Done.");
	update_view(&p);
	mlx_loop(p.mlx);
	return (0);
}
