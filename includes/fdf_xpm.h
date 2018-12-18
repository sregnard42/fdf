/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_xpm.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 08:08:27 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/18 09:20:24 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_XPM_H
# define FDF_XPM_H

# include "libft.h"

# define XPM_LINE_0				"/* XPM */"
# define XPM_LINE_1				"static char * blarg_xpm[] = {"
# define XPM_COLORS				"2"
# define XPM_CHARS_PER_PIXEL	"1"

# define COLOR_WHITE			"#ffffff"
# define COLOR_BLACK			"#000000"
# define COLOR_RED				"#ff0000"
# define COLOR_GREEN			"#00ff00"
# define COLOR_BLUE				"#0000ff"

t_map			*xpm_new(char **map);

#endif
