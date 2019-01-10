/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:58:29 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/17 14:01:48 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content, size_t content_size)
{
	t_list	*elem;

	if ((elem = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	ft_bzero(elem, sizeof(t_list));
	if (content)
	{
		elem->content = content;
		elem->content_size = content_size;
	}
	elem->prev = NULL;
	elem->next = NULL;
	return (elem);
}
