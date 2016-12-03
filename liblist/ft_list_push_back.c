/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 22:34:05 by srodrigu          #+#    #+#             */
/*   Updated: 2016/07/26 22:34:07 by srodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *temp_list;
	t_list *new_node;

	if (!(new_node = ft_create_elem(data)))
		return ;
	temp_list = *begin_list;
	if (temp_list)
	{
		while (temp_list->next != NULL)
		{
			temp_list = temp_list->next;
		}
		temp_list->next = new_node;
	}
	else
	{
		*begin_list = new_node;
	}
}
