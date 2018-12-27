/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:37:06 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/27 09:31:50 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMS_H
# define PARAMS_H

# include "libft.h"
# include "mlx.h"

# define KEY_ESCAPE 53
# define WIN_WIDTH  1280
# define WIN_HEIGHT 720

typedef struct		s_params
{
	void		*mlx;
	void		*win;
	void		*img;
	t_map		*input;
	t_map		*output;
	t_map		*xpm;
	t_point		***pts;
	t_point		min;
	t_point		max;
}			t_params;

void			params_init(t_params *params);
int			get_input(int keycode, t_params *params);
void			params_free(t_params *params);

#endif
