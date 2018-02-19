/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <jecombe@student.le-101.f>         +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:21:35 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/01 21:54:50 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list		*temp;

	if (!lst)
		return (NULL);
	else
	{
		temp = (t_list*)malloc(sizeof(lst));
		if (temp == NULL)
			return (NULL);
		temp = f(lst);
		temp->next = ft_lstmap(lst->next, f);
		return (temp);
	}
}
