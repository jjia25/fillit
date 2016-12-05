/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:00:11 by jjia              #+#    #+#             */
/*   Updated: 2016/11/13 23:42:25 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *suc;

	while (*alst)
	{
		suc = (*alst)->next;
		del((*alst)->data, (*alst)->data_size);
		free(*alst);
		*alst = suc;
	}
	*alst = NULL;
}
