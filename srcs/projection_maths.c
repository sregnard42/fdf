/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_maths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:47:15 by sregnard          #+#    #+#             */
/*   Updated: 2019/01/07 08:22:34 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_point	*proj_isometric(t_point *pt)
{
	t_point *pt_new;

	if (!(pt_new = ft_ptnew(0, 0, 0)))
		return (NULL);
	pt_new->x = (pt->x - pt->y) * 2;
	pt_new->y = (pt->x + pt->y) - 2 * pt->z;
	pt_new->z = pt->z;
	return (pt_new);
}

t_point	*proj_parallel(t_point *pt)
{
	t_point *pt_new;

	if (!(pt_new = ft_ptnew(0, 0, 0)))
		return (NULL);
	pt_new->x = 2 * (pt->x + pt->z);
	pt_new->y = 2 * pt->y - pt->z;
	pt_new->z = pt->z;
	return (pt_new);
}

t_point	*proj_cavaliere(t_point *pt)
{
	t_point *pt_new;

	if (!(pt_new = ft_ptnew(0, 0, 0)))
		return (NULL);
	pt_new->x = 7 * pt->y + 20 * pt->x;
	pt_new->y = 7 * pt->y - 20 * pt->z;
	pt_new->z = pt->z;
	return (pt_new);
}

t_point	*proj_top(t_point *pt)
{
	t_point *pt_new;

	if (!(pt_new = ft_ptnew(0, 0, 0)))
		return (NULL);
	pt_new->x = pt->x;
	pt_new->y = pt->y;
	pt_new->z = pt->z;
	return (pt_new);
}
