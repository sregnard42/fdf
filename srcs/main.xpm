/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:34:12 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/17 08:06:46 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_input(int keycode, void *params_)
{
	if (params_)
		params_ = NULL;
	if (keycode == KEY_ESCAPE)
	{
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int		main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*width;
	int		*height;

	if (ac != 2)
		return (0);
	height = (int *)malloc(sizeof(int));
	width = (int *)malloc(sizeof(int));
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "test");
	img = mlx_xpm_file_to_image(mlx, av[1], width, height);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_key_hook(win, &get_input, NULL);
	mlx_loop(mlx);
}
