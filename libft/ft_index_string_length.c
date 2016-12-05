/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_string_length.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 18:34:21 by jjia              #+#    #+#             */
/*   Updated: 2016/11/13 22:29:25 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_index_string_length(char const *s, int index, char c)
{
	int x;

	x = 0;
	while (s[index] != '\0')
	{
		while (s[index] != c)
		{
			index++;
			x++;
		}
	}
	return (x);
}
