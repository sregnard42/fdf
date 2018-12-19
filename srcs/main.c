/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:05:50 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/19 14:16:46 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				get_input(int keycode, void *params)
{
	if (keycode == KEY_ESCAPE)
	{
		params_free((t_params **)&params);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int				main(int ac, char **av)
{
	t_params	*params;
	void		*img;
	char		**file_content;

	if (ac != 2)
		trigger_error(ERR_USAGE);
	if (!(file_content = read_file(av[1])))
		trigger_error(ERR_FILE);
	if (!(params = params_new(xpm_new((proj_mapping(file_content)->map)))))
		trigger_error("Error while converting map to XPM format.");
	ft_print_tab(file_content);
	ft_free_tab(&file_content);
	ft_print_tab((params->xpm)->map);
	params->win = mlx_new_window(params->mlx, params->win_size->x,
			params->win_size->y, "FdF");
	mlx_key_hook(params->win, &get_input, params);
	img = mlx_xpm_to_image(params->mlx, params->xpm->map,
			&(params->xpm->width), &(params->xpm->height));
	mlx_put_image_to_window(params->mlx, params->win, img, 0, 0);
	mlx_loop(params->mlx);
	return (0);
}
