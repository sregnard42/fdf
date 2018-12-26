/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:05:50 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/26 22:21:55 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main(int ac, char **av)
{
	t_params	params;

	if (ac != 2)
		trigger_error(ERR_USAGE);
	if (!(params.input = ft_mapfrom(read_file(av[1]))))
		trigger_error(ERR_FILE);
	params_mlx_init(&params);
	projection_3d(&params);
	xpm_conversion(&params);
	if (!(params.img = mlx_xpm_to_image(params.mlx, xpm.map,
			&(xpm.width), &(xpm.height))))
		trigger_error("Error while loading XPM into an image.");
	mlx_put_image_to_window(params.mlx, params.win, params.img, 0, 0);
	mlx_loop(params.mlx);
	return (0);
}
