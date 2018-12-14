/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:12:09 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/14 11:23:09 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ishexa(char *s)
{
	ft_putstr("Hexa ? ");
	ft_putstr(s);
	ft_putstr("         ");
	if (ft_strlen(s) != 8)
		return (0);
	if (*s != '0')
		return (0);
	if (*++s != 'x')
		return (0);
	while (*++s)
		if (!(ft_isdigit(*s)) && !(*s >= 'A' && *s <= 'F')
				&& !(*s >= 'a' && *s <= 'f'))
				return (0);
	ft_putstr("hexa");
	return (1);
}
