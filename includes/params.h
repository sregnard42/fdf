/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:37:06 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/20 15:19:03 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMS_H
# define PARAMS_H

# include "libft.h"
# include "mlx.h"
# include "fdf_xpm.h"

# define KEY_ESCAPE 53

typedef struct	s_params
{
	void		*mlx;
	void		*win;
	void		*img;
	t_point		*size;
}				t_params;

t_params		*params_new(void);
int				get_input(int keycode, void *params);
void			params_free(t_params **params);

#endif
