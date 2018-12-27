/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:05:50 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/27 17:12:31 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update_view(t_params *p)
{
	params_free_view(p);
	projection_3d(p);
	xpm_conversion(p);
	if (!(p->img = mlx_xpm_to_image(p->mlx, p->xpm->data,
					&(p->xpm->width), &(p->xpm->height))))
		trigger_error("Error while loading XPM into an image.", p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}

int	get_input(int keycode, t_params *params)
{
	if (keycode == KEY_ESCAPE)
	{
		params_free(params);
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_LEFT) 
	{
		if (params->view == 0)
			params->view = 1;
		else
			params->view -= 1;
	}
	if (keycode == KEY_RIGHT)
	{
		if (params->view == 1)
			params->view = 0;
		else
			params->view += 1;
	}
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT
			|| keycode == KEY_UP || keycode == KEY_DOWN)
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
