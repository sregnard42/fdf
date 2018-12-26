/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 08:08:27 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/24 13:01:37 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_XPM_H
# define FDF_XPM_H

# include "libft.h"

# define XPM_LINE_0				"/* XPM */"
# define XPM_LINE_1				"static char * blarg_xpm[] = {"
# define XPM_COLORS				"8"
# define XPM_CHARS_PER_PIXEL	"1"

# define COLOR_BLACK             '.'
# define COLOR_WHITE             '*'
# define COLOR_BLUE              'B'
# define COLOR_CYAN              'C'
# define COLOR_GREEN             'G'
# define COLOR_YELLOW            'Y'
# define COLOR_ORANGE            'O'
# define COLOR_RED               'R'

# define HEXA_BLACK			    "#000000"
# define HEXA_WHITE			    "#ffffff"
# define HEXA_BLUE				"#0000ff"
# define HEXA_CYAN              "#00ffff"
# define HEXA_GREEN			    "#00ff00"
# define HEXA_YELLOW            "#ffff00"
# define HEXA_ORANGE            "#ff7f00"
# define HEXA_RED				"#ff0000"

t_map			*xpm_new(char **map);
void			xpm_conversion(t_map *xpm, char **map);

#endif
