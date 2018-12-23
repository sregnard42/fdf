/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_maths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:47:15 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/23 11:57:43 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

t_point	*proj_isometric(t_point *p)
{
    t_point *pt;

	if (!(pt = ft_ptnew(0, 0, 0)))
		return (NULL);
	pt->x = 2 * (p->x - p->y);
	pt->y = p->x + p->y - 2 * p->z;
	pt->z = p->z;
	return (pt);
}

t_point *proj_parallel(t_point *p)
{
    t_point *pt;

	if (!(pt = ft_ptnew(0, 0, 0)))
		return (NULL);
	pt->x = 2 * (p->x + p->z);
	pt->y = 2 * p->y - p->z;
	pt->z = p->z;
	return (pt);
}
