/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_xpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 08:11:11 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/18 09:24:35 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_xpm.h"

static void	add_color(t_map *xpm, char *c, char *color, int i)
{
	xpm->map[3 + i] = ft_strdup("\"");
	xpm->map[3 + i] = ft_stradd(xpm->map[3 + i], c);
	xpm->map[3 + i] = ft_stradd(xpm->map[3 + i], " c ");
	xpm->map[3 + i] = ft_stradd(xpm->map[3 + i], color);
	xpm->map[3 + i] = ft_stradd(xpm->map[3 + i], "\",");
}

static void	header_and_footer(t_map *xpm, int size)
{
	xpm->map[0] = ft_strdup(XPM_LINE_0);
	xpm->map[1] = ft_strdup(XPM_LINE_1);
	xpm->map[2] = ft_strdup("\"");
	xpm->map[2] = ft_stradd(xpm->map[2], ft_itoa(xpm->width));
	xpm->map[2] = ft_stradd(xpm->map[2], " ");
	xpm->map[2] = ft_stradd(xpm->map[2], ft_itoa(xpm->height));
	xpm->map[2] = ft_stradd(xpm->map[2], " ");
	xpm->map[2] = ft_stradd(xpm->map[2], XPM_COLORS);
	xpm->map[2] = ft_stradd(xpm->map[2], " ");
	xpm->map[2] = ft_stradd(xpm->map[2], XPM_CHARS_PER_PIXEL);
	xpm->map[2] = ft_stradd(xpm->map[2], "\",");
	add_color(xpm, "*", COLOR_WHITE, 0);
	add_color(xpm, ".", COLOR_BLACK, 1);
	xpm->map[size - 1] = ft_strdup("};");
	xpm->map[size] = 0;
}

static void		fdf_to_xpm(t_map *xpm, char **fdf)
{
	int		size;
	int		i;

	xpm->width = ft_max_strlen_tab(fdf);
	xpm->height = ft_nb_str_tab(fdf);
	size = xpm->height + ft_atoi(XPM_COLORS) + 4;
	if (!(xpm->map = (char **)malloc(sizeof(char *) * (size + 1))))
		return ;
	header_and_footer(xpm, size);
	i = 3 + ft_atoi(XPM_COLORS);
	while (i < (size - 1) && fdf && *fdf)
	{
		xpm->map[i] = ft_strdup("\"");
		xpm->map[i] = ft_stradd(xpm->map[i], *fdf++);
		xpm->map[i] = ft_stradd(xpm->map[i], "\"");
		if (i < (size - 2))
			xpm->map[i] = ft_stradd(xpm->map[i], ",");
		i++;
	}
}

t_map		*xpm_new(char **fdf)
{
	t_map	*xpm;

	xpm = (t_map *)malloc(sizeof(t_map));
	if (xpm)
		fdf_to_xpm(xpm, fdf);
	return (xpm);
}
