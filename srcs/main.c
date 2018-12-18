/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:05:50 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/18 09:26:34 by sregnard         ###   ########.fr       */
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
	char		**file_content;

	if (ac != 2)
		trigger_error(ERR_USAGE);
	if (!(file_content = read_file(av[1])))
		trigger_error(ERR_FILE);
	ft_putendl("Checkpoint A");
	ft_print_tab(file_content);
	if (!(params = params_new(xpm_new((isometric_mapping(file_content)->map)))))
		trigger_error("Error while converting map to XPM format.");
	ft_print_tab((params->xpm)->map);
	ft_putendl("Checkpoint B");
//	mlx_key_hook(params->win, &get_input, params);
//	mlx_loop(params->mlx);
	return (0);
}
