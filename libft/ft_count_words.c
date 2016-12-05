/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:06:45 by jjia              #+#    #+#             */
/*   Updated: 2016/11/13 22:02:49 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	int wordcount;
	int i;
	int flag;

	i = 0;
	wordcount = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			flag = 0;
		else if (flag == 0 && s[i] != c)
		{
			flag = 1;
			wordcount++;
		}
		i++;
	}
	return (wordcount);
}
