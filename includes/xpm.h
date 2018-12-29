/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 08:08:27 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/29 13:23:51 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_XPM_H
# define FDF_XPM_H

# include "libft.h"
# include "params.h"
# include "errors.h"

t_map			*xpm_new(t_params *params);
void			xpm_conversion(t_params *params);

#endif
