/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:30:23 by jjia              #+#    #+#             */
/*   Updated: 2016/11/13 21:51:02 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char *csrc;
	unsigned char *cdst;

	csrc = (unsigned char *)src;
	cdst = (unsigned char *)dst;
	if (csrc < cdst)
	{
		csrc = csrc + n - 1;
		cdst = cdst + n - 1;
		while (n--)
			*cdst-- = *csrc--;
	}
	else
	{
		while (n--)
			*cdst++ = *csrc++;
	}
	return (dst);
}
