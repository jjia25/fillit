/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 12:17:21 by jjia              #+#    #+#             */
/*   Updated: 2016/11/14 20:39:00 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *area;

	area = malloc((size));
	if (area == NULL || size > (size_t)area)
		return (NULL);
	ft_memset(area, 0, size);
	return (area);
}
