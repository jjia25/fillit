/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 11:02:29 by jjia              #+#    #+#             */
/*   Updated: 2016/11/13 23:41:27 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *str, char const *to_find)
{
	char *begin;
	char *pattern;
	char *cstr;

	cstr = (char *)str;
	if (ft_strcmp((char *)to_find, "") == 0)
		return ((char *)str);
	while (*cstr && str != NULL && to_find != NULL)
	{
		begin = cstr;
		pattern = (char *)to_find;
		while (*cstr && *pattern && *cstr == *pattern)
		{
			cstr++;
			pattern++;
		}
		if (!*pattern)
			return (begin);
		cstr = begin + 1;
	}
	return (NULL);
}
