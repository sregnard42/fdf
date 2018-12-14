/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 09:14:37 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/14 09:27:50 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "libft.h"

# define DEBUG				1
# define DEBUG_ON			"DEBUG : "
# define MSG_ERR			"error"

# define ERR_USAGE			"usage: ./fdf file"
# define ERR_FILE			"FIle error."

void	trigger_error(char *err_code);

#endif
