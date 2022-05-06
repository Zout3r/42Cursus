/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:49:37 by jperez-p          #+#    #+#             */
/*   Updated: 2022/05/03 13:49:38 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_get_cnt(const char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			cnt++;
			while (*s != '\0' && *s != c)
				s++;
		}
	}
	return (cnt);
}

char	**ft_free_machine(char **s, size_t count)
{
	while (s[count] != NULL && count >= 0)
	{
		free(s[count]);
		s[count] = NULL;
		count--;
	}
	free(s);
	s = NULL;
	return (NULL);
}

char	**ft_paco(const char *s, char c, char **words, size_t word_cnt)
{
	size_t	count;
	size_t	len;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len = 0;
			while (*(s + len) && *(s + len) != c)
				len++;
			words[count++] = ft_substr(s, 0, len);
			if (count < word_cnt && !(words))
				return (ft_free_machine(words, count));
			s += len;
		}
	}
	words[count] = 0;
	return (words);
}

char	**ft_split(const char *s, char c)
{
	size_t	word_cnt;
	char	**words;

	word_cnt = ft_get_cnt(s, c);
	words = (char **)malloc(sizeof(char *) * (ft_get_cnt(s, c) + 1));
	if (s == 0 || words == 0)
		return (NULL);
	ft_paco(s, c, words, word_cnt);
	return (words);
}
