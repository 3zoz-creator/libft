/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-br <abait-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 17:53:10 by abait-br          #+#    #+#             */
/*   Updated: 2026/10/20 22:30:15 by abait-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_alike(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && big[i] && little[i])
	{
		if (little[i] != big[i])
			return (1);
		i++;
	}
	if (little[i] == '\0')
		return (0);
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		if (is_alike(big + i, little, len - i) == 0)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
