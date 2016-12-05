/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjia <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:08:39 by jjia              #+#    #+#             */
/*   Updated: 2016/11/13 21:59:45 by jjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_index_string_length(char const *s, int index, char c)
{
	int		x;

	if (*s == 0)
		return (0);
	x = 0;
	while (s[index] != '\0' && s[index] != c)
	{
		index++;
		x++;
	}
	return (x);
}

char		**ft_strsplit(char const *s, char c)
{
	int		index;
	char	**words;
	char	*string;
	int		word_length;
	int		wordcount;

	wordcount = 0;
	index = -1;
	if (!s)
		return (NULL);
	words = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!words)
		return (NULL);
	while (s[++index])
		if (s[index] != c)
		{
			word_length = ft_index_string_length(s, index, c);
			string = (char *)malloc(sizeof(char) * (word_length + 1));
			ft_strncpy(string, s + index, word_length);
			string[word_length] = '\0';
			words[wordcount++] = string;
			index += word_length - 1;
		}
	words[wordcount] = NULL;
	return (words);
}
