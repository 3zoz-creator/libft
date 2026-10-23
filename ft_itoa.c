/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-br <abait-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 13:42:46 by abait-br          #+#    #+#             */
/*   Updated: 2026/10/20 21:01:49 by abait-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_sign(long *nb, size_t *len)
{
	long	n;

	if ((*nb) < 0)
	{
		(*nb) *= -1;
		(*len) = 1;
	}
	n = *nb;
	if (n == 0)
	{
		(*len) = 1;
		return ;
	}
	while (n > 0)
	{
		n /= 10;
		(*len)++;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	size_t	len;

	nb = n;
	len = 0;
	check_sign(&nb, &len);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > (n < 0))
	{
		len--;
		str[len] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
