/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 11:07:28 by jjia              #+#    #+#             */
/*   Updated: 2016/11/14 17:43:37 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_print_exception_fd(int exc, int fd)
{
	if (exc == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (exc < 0)
		ft_putchar_fd('-', fd);
	return (exc *= -1);
}

static	int		ft_set_divider(int nb)
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

void			ft_putnbr_fd(int nb, int fd)
{
	int divider;

	if (nb < 0)
		nb = ft_print_exception_fd(nb, fd);
	divider = ft_set_divider(nb);
	while (divider > 0)
	{
		if (nb / divider >= 0)
		{
			ft_putchar_fd((nb / divider + 48), fd);
			nb = nb % divider;
		}
		divider /= 10;
	}
}
