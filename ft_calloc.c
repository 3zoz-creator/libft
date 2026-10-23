/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-br <abait-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 22:45:26 by abait-br          #+#    #+#             */
/*   Updated: 2026/10/23 15:40:45 by abait-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*arr;
	unsigned char	*bytes;
	size_t			i;

	if (size != 0 && nmemb > (size_t)-1 / size)
		return (NULL);
	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	bytes = (unsigned char *)arr;
	i = 0;
	while (i < (nmemb * size))
	{
		bytes[i] = 0;
		i++;
	}
	return (arr);
}
