/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 09:14:37 by sregnard          #+#    #+#             */
/*   Updated: 2019/01/06 15:41:13 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define DEBUG				1
# define DEBUG_ON			"DEBUG : "
# define MSG_ERR			"error"

# define ERR_USAGE			"usage: ./fdf file"
# define ERR_FILE			"FIle error."

void	trigger_error(char *err_code, t_params *p);

#endif
