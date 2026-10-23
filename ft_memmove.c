/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-br <abait-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:16:30 by abait-br          #+#    #+#             */
/*   Updated: 2026/10/16 23:52:55 by abait-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*s;
	size_t				i;

	dst = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (n == 0 || dest == src)
		return (dest);
	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			i--;
			dst[i] = s[i];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dst);
}
