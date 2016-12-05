/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:20:07 by jjia              #+#    #+#             */
/*   Updated: 2016/11/20 19:37:02 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*store;
	int		i;
	long	ln;

	ln = (long)n;
	i = ft_digit_length(ln);
	store = (char *)malloc(sizeof(char) * i + 1);
	if (!store)
		return (NULL);
	store[i--] = '\0';
	if (ln < 0)
	{
		store[0] = '-';
		ln *= -1;
	}
	if (ln == 0)
		store[0] = '0';
	while (ln != 0)
	{
		store[i--] = (ln % 10) + '0';
		ln /= 10;
	}
	return (store);
}
