/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 08:11:11 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/29 13:31:19 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xpm.h"
#include "defines.h"

static void	add_color(t_map *xpm, char c, char *color, int i)
{
	xpm->data[1 + i] = ft_strdup(&c);
	xpm->data[1 + i] = ft_stradd(xpm->data[1 + i], " c ");
	xpm->data[1 + i] = ft_stradd(xpm->data[1 + i], color);
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
	char	*tmp;

	xpm->data[0] = ft_itoa(xpm->width);
	xpm->data[0] = ft_stradd(xpm->data[0], " ");
	tmp = ft_itoa(xpm->height);
	xpm->data[0] = ft_stradd(xpm->data[0], tmp);
	free(tmp);
	xpm->data[0] = ft_stradd(xpm->data[0], " ");
	xpm->data[0] = ft_stradd(xpm->data[0], XPM_COLORS);
	xpm->data[0] = ft_stradd(xpm->data[0], " ");
	xpm->data[0] = ft_stradd(xpm->data[0], XPM_CHARS_PER_PIXEL);
    add_all_colors(xpm);
	xpm->data[size] = 0;
}

void	xpm_conversion(t_params *p)
{
	int		size;
	int		i;
	int		j;

	if (!(p->xpm = (t_map *)malloc(sizeof(t_map))))
		trigger_error("Error malloc xpm xpm_conversion", p);
	p->xpm->width = p->output->width;
	p->xpm->height = p->output->height;
	size = p->xpm->height + ft_atoi(XPM_COLORS) + 1;
	if (!(p->xpm->data = (char **)malloc(sizeof(char *) * (size + 1))))
		trigger_error("Erroc malloc xpm->data xpm_conversion", p);
	header_and_footer(p->xpm, size);
	i = 1 + ft_atoi(XPM_COLORS);
	j = 0;
	while (i < size && p->output->data && p->output->data[j])
		p->xpm->data[i++] = ft_strdup(p->output->data[j++]);
}

t_map		*xpm_new(t_params *params)
{
	t_map	*xpm;

	xpm = (t_map *)malloc(sizeof(t_map));
	if (xpm)
		xpm_conversion(params);
	return (xpm);
}
