/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:54:34 by jjia              #+#    #+#             */
/*   Updated: 2016/11/13 22:03:10 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *us;

	us = (unsigned char *)s;
	while (n--)
	{
		if (*us == (unsigned char)c)
			return (us);
		us++;
	}
	return (NULL);
}
