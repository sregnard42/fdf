/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_xpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 08:11:11 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/23 11:38:11 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_xpm.h"

static void	add_color(t_map *xpm, char c, char *color, int i)
{
	xpm->map[1 + i] = ft_strdup(&c);
	xpm->map[1 + i] = ft_stradd(xpm->map[1 + i], " c ");
	xpm->map[1 + i] = ft_stradd(xpm->map[1 + i], color);
}

static void add_all_colors(t_map *xpm)
{
    int     i;

    i = 0;
    add_color(xpm, COLOR_BLACK, HEXA_BLACK, i++);
    add_color(xpm, COLOR_WHITE, HEXA_WHITE, i++);
    add_color(xpm, COLOR_BLUE, HEXA_BLUE, i++);
    add_color(xpm, COLOR_CYAN, HEXA_CYAN, i++);
    add_color(xpm, COLOR_GREEN, HEXA_GREEN, i++);
    add_color(xpm, COLOR_YELLOW, HEXA_YELLOW, i++);
    add_color(xpm, COLOR_ORANGE, HEXA_ORANGE, i++);
    add_color(xpm, COLOR_RED, HEXA_RED, i++);
}

static void	header_and_footer(t_map *xpm, int size)
{
	xpm->map[0] = ft_strdup(ft_itoa(xpm->width));
	xpm->map[0] = ft_stradd(xpm->map[0], " ");
	xpm->map[0] = ft_stradd(xpm->map[0], ft_itoa(xpm->height));
	xpm->map[0] = ft_stradd(xpm->map[0], " ");
	xpm->map[0] = ft_stradd(xpm->map[0], XPM_COLORS);
	xpm->map[0] = ft_stradd(xpm->map[0], " ");
	xpm->map[0] = ft_stradd(xpm->map[0], XPM_CHARS_PER_PIXEL);
    add_all_colors(xpm);
	xpm->map[size] = 0;
}

static void	fdf_to_xpm(t_map *xpm, char **fdf)
{
	int		size;
	int		i;

	xpm->width = ft_strlen(*fdf);
	xpm->height = ft_nb_str_tab(fdf);
	size = xpm->height + ft_atoi(XPM_COLORS) + 1;
	if (!(xpm->map = (char **)malloc(sizeof(char *) * (size + 1))))
		return ;
	header_and_footer(xpm, size);
	i = 1 + ft_atoi(XPM_COLORS);
	while (i < size && fdf && *fdf)
		xpm->map[i++] = ft_strdup(*fdf++);
}

t_map		*xpm_new(char **fdf)
{
	t_map	*xpm;

	xpm = (t_map *)malloc(sizeof(t_map));
	if (xpm)
		fdf_to_xpm(xpm, fdf);
	return (xpm);
}
