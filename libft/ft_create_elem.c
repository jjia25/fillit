/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 01:35:18 by jjia              #+#    #+#             */
/*   Updated: 2016/12/05 01:35:20 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_create_elem(char *data)
{
	t_list	*tmp;

	if (!(tmp = (t_list*)malloc(sizeof(t_list))))
		return (0);
	tmp->data = data;
	tmp->next = NULL;
	return (tmp);
}
