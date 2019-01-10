/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:37:06 by sregnard          #+#    #+#             */
/*   Updated: 2019/01/10 10:53:12 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMS_H
# define PARAMS_H

# include "libft.h"

typedef struct	s_params
{
	void		*mlx;
	void		*win;
	void		*img;
	int			view;
	t_map		*input;
	t_map		*output;
	t_map		*xpm;
	t_point		***pts;
	t_point		min;
	t_point		max;
	t_point		offset;
	float		height;
	float		zoom;
}				t_params;

void			params_init(t_params *params);
void			params_update_view(t_params *params);
void			params_reset_view(t_params *params);
void			params_free_view(t_params *params);
void			params_free(t_params *params);

#endif
