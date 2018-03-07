/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <jecombe@student.le-101.f>         +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 15:58:44 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 15:58:45 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*ptr;

	ptr = (void*)malloc(sizeof(*ptr) * (size + 1));
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size + 1);
	return (ptr);
}
