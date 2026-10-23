/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-br <abait-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 22:32:36 by abait-br          #+#    #+#             */
/*   Updated: 2026/10/23 15:56:45 by abait-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s_len;
	size_t	i;
	char	*s2;

	if (!s1 || !set)
		return (NULL);
	s_len = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i++;
	while (s_len > i && ft_strchr(set, s1[s_len - 1]) != NULL)
		s_len--;
	s2 = malloc((s_len - i) + 1);
	if (!s2)
		return (NULL);
	ft_memcpy(s2, s1 + i, s_len - i);
	s2[s_len - i] = '\0';
	return (s2);
}
