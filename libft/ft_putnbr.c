/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 11:07:28 by jjia              #+#    #+#             */
/*   Updated: 2016/11/13 22:02:31 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_print_exception(int exc)
{
	if (exc == -2147483648)
		ft_putstr("-2147483648");
	else if (exc < 0)
	{
		ft_putchar('-');
	}
	return (exc *= -1);
}

static int		ft_set_divider(int nb)
{
	int divider;

	divider = 1;
	while (nb >= 10)
	{
		nb /= 10;
		divider *= 10;
	}
	return (divider);
}

void			ft_putnbr(int nb)
{
	int divider;

	if (nb < 0)
	{
		nb = ft_print_exception(nb);
	}
	divider = ft_set_divider(nb);
	while (divider > 0)
	{
		if (nb / divider >= 0)
		{
			ft_putchar(nb / divider + 48);
			nb = nb % divider;
		}
		divider /= 10;
	}
}
