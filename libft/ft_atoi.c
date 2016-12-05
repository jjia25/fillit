/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 09:17:17 by jjia              #+#    #+#             */
/*   Updated: 2016/11/13 23:20:25 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int				is_blank(char c)
{
	if (c == '\t' || c == '\v' || c == '\n' || c == '\f' || c == '\r')
		return (1);
	return (c == ' ');
}

int						ft_atoi(const char *str)
{
	unsigned long long	x;
	int					i;
	int					sign;

	i = 0;
	x = 0;
	sign = 1;
	while (is_blank(str[i]) == 1)
		str++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = str[i] == '-' ? -1 : 1;
		str++;
	}
	while (*str == '0')
		str++;
	while (str[i] != '\0')
	{
		if (str[i] > 57 || str[i] < 48)
			return (sign * x);
		x = x * 10 + str[i++] - '0';
	}
	if (i > 19 || x > 9223372036854775807ULL)
		return (sign == 1 ? -1 : 0);
	return (sign * x);
}
