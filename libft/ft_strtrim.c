/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:59:25 by jjia              #+#    #+#             */
/*   Updated: 2016/11/13 22:34:39 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		length;

	i = -1;
	if (!s)
		return (NULL);
	length = (int)ft_strlen(s);
	while (ft_isspace(s[length - 1]) == 1)
		length--;
	while (ft_isspace(s[++i]) == 1)
		length--;
	if (length <= 0)
		length = 0;
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	s += i;
	i = -1;
	while (++i < length && s)
	{
		str[i] = *s++;
	}
	str[i] = '\0';
	return (str);
}
