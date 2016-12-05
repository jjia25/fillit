/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:00:51 by jjia              #+#    #+#             */
/*   Updated: 2016/11/13 22:27:24 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int i;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (len && *big)
	{
		if (*big == little[i])
			i++;
		if (little[i] == '\0')
			return ((char *)(big - i + 1));
		big++;
		len--;
	}
	return (NULL);
}
