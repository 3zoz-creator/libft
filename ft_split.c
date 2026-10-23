/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-br <abait-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 23:55:03 by abait-br          #+#    #+#             */
/*   Updated: 2026/10/22 14:48:12 by abait-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		count++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

static size_t	ft_strlen_w(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	skip_set(char const *s, size_t *i, char c)
{
	while (s[*i] && s[*i] == c)
		(*i)++;
	return (*i);
}

static char	**malloc_and_fill(char const *s, char c, char **strs)
{
	size_t i, (w_len), (k);
	i = 0;
	k = 0;
	while (s[i])
	{
		skip_set(s, &i, c);
		if (!s[i])
			break ;
		w_len = ft_strlen_w(s + i, c);
		strs[k] = malloc(w_len + 1);
		if (!strs[k])
		{
			while (k > 0)
				free(strs[--k]);
			free(strs);
			return (NULL);
		}
		ft_memcpy(strs[k], s + i, w_len);
		strs[k++][w_len] = '\0';
		i = w_len + i;
	}
	strs[k] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	size_t	cw;
	char	**strs;

	if (!s)
		return (NULL);
	cw = count_words(s, c);
	strs = malloc((cw + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	strs = malloc_and_fill(s, c, strs);
	if (!strs)
		return (NULL);
	return (strs);
}
