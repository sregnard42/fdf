/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:05:50 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/21 13:25:55 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main(int ac, char **av)
{
	t_params	*params;
	char		**file_content;
	t_map		*xpm;

	if (ac != 2)
		trigger_error(ERR_USAGE);
	ft_putendl("Parsing file...");
	if (!(file_content = read_file(av[1])))
		trigger_error(ERR_FILE);
	ft_putendl("Initialization of parameters...");
	if (!(params = params_new()))
		trigger_error("Error while creating mlx window.");
	ft_putendl("Calculating 3D projection...");
	if (!(xpm = xpm_new((projection_3d(file_content, params->size)->map))))
		trigger_error("Error while converting map to XPM format.");
	ft_free_tab(&file_content);
	ft_putendl("Creating image...");
	params->img = mlx_xpm_to_image(params->mlx, xpm->map,
			&(xpm->width), &(xpm->height));
	ft_putendl("Display image in window...");
	mlx_put_image_to_window(params->mlx, params->win, params->img, 0, 0);
	mlx_loop(params->mlx);
	return (0);
}
