/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:37:06 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/27 16:32:58 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMS_H
# define PARAMS_H

# include "libft.h"
# include "mlx.h"

# define KEY_ESCAPE		53
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_DOWN		125
# define KEY_UP			126

# define WIN_WIDTH		1280
# define WIN_HEIGHT		720

# define VIEW_ISOMETRIC		0
# define VIEW_PARALLEL		1

typedef struct		s_params
{
	void		*mlx;
	void		*win;
	void		*img;
	int		view;
	t_map		*input;
	t_map		*output;
	t_map		*xpm;
	t_point		***pts;
	t_point		min;
	t_point		max;
	float		cte1;
	float		cte2;
	int		a;
}			t_params;

void			params_init(t_params *params);
void			params_free_view(t_params *params);
void			params_free(t_params *params);

#endif
