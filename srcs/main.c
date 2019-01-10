/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:05:50 by sregnard          #+#    #+#             */
/*   Updated: 2019/01/10 14:42:25 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "defines.h"
#include "params.h"
#include "errors.h"
#include "controller.h"

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
	ft_putstr("Loading image...");
	params_update_view(&p);
	ft_putendl("Done.");
	mlx_loop(p.mlx);
	return (0);
}
