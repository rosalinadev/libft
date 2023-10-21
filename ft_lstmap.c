/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 01:02:23 by rvandepu          #+#    #+#             */
/*   Updated: 2023/10/21 14:53:34 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*r;
	t_list	*n;
	void	*t;

	r = NULL;
	while (lst)
	{
		t = f(lst->content);
		n = ft_lstnew(t);
		if (n == NULL)
		{
			ft_lstclear(&r, del);
			del(t);
		}
		ft_lstadd_back(&r, n);
		lst = lst->next;
	}
	return (r);
}
