/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:37:06 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/29 13:37:23 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMS_H
# define PARAMS_H

# include "libft.h"
# include "mlx.h"

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
	float		height_modifier;
}			t_params;

void			params_init(t_params *params);
void			params_free_view(t_params *params);
void			params_free(t_params *params);

#endif
