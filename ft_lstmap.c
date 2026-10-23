/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-br <abait-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 00:54:31 by abait-br          #+#    #+#             */
/*   Updated: 2026/10/23 20:17:22 by abait-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*n_lst;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	n_lst = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		tmp = ft_lstnew(content);
		if (!tmp)
		{
			del(content);
			ft_lstclear(&n_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&n_lst, tmp);
		lst = lst->next;
	}
	return (n_lst);
}
