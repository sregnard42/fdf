/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:05:50 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/27 11:19:33 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main(int ac, char **av)
{
	t_params	p;

	if (ac != 2)
		trigger_error(ERR_USAGE, NULL);
	ft_putendl("Parsing file...");
	if (!(p.input = ft_mapfrom(read_file(av[1]))))
		trigger_error(ERR_FILE, NULL);
	ft_putendl("Init mlx...");
	params_init(&p);
	ft_putendl("Calculating 3D projection...");
	projection_3d(&p);
	xpm_conversion(&p);
	if (!(p.img = mlx_xpm_to_image(p.mlx, p.xpm->data,
			&(p.xpm->width), &(p.xpm->height))))
		trigger_error("Error while loading XPM into an image.", &p);
	mlx_put_image_to_window(p.mlx, p.win, p.img, 0, 0);
	mlx_loop(p.mlx);
	return (0);
}
