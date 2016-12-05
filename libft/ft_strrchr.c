/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:38:28 by jjia              #+#    #+#             */
/*   Updated: 2016/11/13 21:47:24 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	int save;

	save = (int)ft_strlen((char *)s);
	while (save != 0 && s[save] != (char)c)
		save--;
	if (s[save] == c)
		return ((char *)s + save);
	return (0);
}
