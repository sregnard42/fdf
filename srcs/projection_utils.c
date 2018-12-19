/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:04:06 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/19 14:08:15 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Find both minimum x and y and both maximum x and y in given list of points
*/

void	find_edges(t_list *lst, t_point *min, t_point *max)
{
	t_point *pt;

	ft_ptset(min, 0, 0, -1);
	ft_ptset(max, 0, 0, 0);
	while (lst)
	{
		pt = (t_point *)lst->content;
		if (min->z == -1)
		{
			ft_ptset(min, pt->x, pt->y, 0);
		}
		if (min->x > pt->x)
			min->x = pt->x;
		if (min->y > pt->y)
			min->y = pt->y;
		if (max->x < pt->x)
			max->x = pt->x;
		if (max->y < pt->y)
			max->y = pt->y;
		lst = lst->next;
	}
}

/*
** Normalize points so that the top left point is as close as possible to
** (0, 0), max will store both the maximum x and y AFTER normalization
*/

int		normalize(t_list *lst, t_point *max)
{
	t_point *pt;
	t_point	*min;

	if (!(min = ft_ptnew(0, 0, 0)))
		return (0);
	find_edges(lst, min, max);
	while (lst)
	{
		pt = (t_point *)lst->content;
		pt->x = pt->x - min->x;
		pt->y = pt->y - min->y;
		lst = lst->next;
	}
	max->x = max->x - min->x;
	max->y = max->y - min->y;
	return (1);
}
