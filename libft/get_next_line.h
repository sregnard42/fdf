/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:08:48 by sregnard          #+#    #+#             */
/*   Updated: 2018/11/24 09:25:19 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1000
# define FD_MAX 4864
# define EOL '\n'
# define EOS '\0'

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int	get_next_line(int fd, char **line);

#endif
