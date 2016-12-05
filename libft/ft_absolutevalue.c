/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 13:47:13 by jjia              #+#    #+#             */
/*   Updated: 2016/11/13 23:42:14 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_abs(int n)
{
	unsigned long ul;

	ul = 0;
	if (n < 0)
	{
		ul = (unsigned long)n;
		ul *= -1;
		return (ul);
	}
	return ((unsigned long)n);
}
