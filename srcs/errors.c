/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 09:15:29 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/27 12:37:42 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

/*
** Show error and exit program
** SET DEBUG AT 1 in errors.h to show more errors
*/

void	trigger_error(char *err_msg, t_params *p)
{
	if (ft_strequ(err_msg, ERR_USAGE))
		ft_putendl(ERR_USAGE);
	else if (DEBUG && !ft_strequ(err_msg, MSG_ERR))
	{
		ft_putstr(DEBUG_ON);
		ft_putendl(err_msg);
	}
	else
		ft_putendl(MSG_ERR);
	if (p)
		params_free(p);
	exit(EXIT_FAILURE);
}
