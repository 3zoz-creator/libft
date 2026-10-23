/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-br <abait-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:55:00 by abait-br          #+#    #+#             */
/*   Updated: 2026/10/23 15:27:49 by abait-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*dst;
	size_t			i;

	s = (unsigned char *)src;
	dst = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		dst[i] = s[i];
		i++;
	}
	return (dest);
}