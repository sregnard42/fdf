/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:37:06 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/26 14:44:28 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMS_H
# define PARAMS_H

# include "libft.h"
# include "mlx.h"
# include "xpm.h"

# define KEY_ESCAPE 53
# define WIN_WIDTH  1280
# define WIN_HEIGHT 720

typedef struct	s_params
{
	void		*mlx;
	void		*win;
	void		*img;
}				t_params;

t_params		*params_new(void);
void			params_init(t_params *params);
int			get_input(int keycode, t_params *params);
void			params_free(t_params *params);

#endif
