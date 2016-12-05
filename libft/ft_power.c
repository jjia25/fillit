/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 01:07:43 by jjia              #+#    #+#             */
/*   Updated: 2016/11/13 22:44:32 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_power(int n, int pow)
{
	double answer;

	if (pow == 0)
		return (1);
	answer = 1;
	if (pow < 0)
	{
		pow *= -1;
		while (pow > 0)
		{
			answer *= n;
			pow--;
		}
		answer = (1 / answer);
	}
	else
		while (pow > 0)
		{
			answer *= n;
			pow--;
		}
	return (answer);
}
